package controller.closed;

import controller.open.Commands;
import view.open.Context;
import view.open.Signals;

import java.util.*;

public class							ConsoleSignalTranslator
{
	private enum						Keyword
	{
		CREATE,
		SELECT,
		DELETE,
		INFO,
		EXIT,
		NORTH,
		EAST,
		SOUTH,
		WEST,
		VALUE;

		private static final
		Map<String, Keyword>			stringToKeyword = new HashMap<String, Keyword>()
		{{
			put("create", CREATE);
			put("select", SELECT);
			put("delete", DELETE);
			put("info", INFO);
			put("north", NORTH);
			put("east", EAST);
			put("south", SOUTH);
			put("west", WEST);
			put("exit", EXIT);
		}};

		public boolean					checkToken(String token)
		{
			if (this == VALUE)
				return true;

			for (Map.Entry<String, Keyword> entry : stringToKeyword.entrySet())
			{
				if (token.equalsIgnoreCase(entry.getKey()))
					return this == entry.getValue();
			}

			return false;
		}
	}

	private static class				Pattern
	{
		private final Class<?>			class_;
		private final Keyword[]			keywords;

		public Class<?>					getClass_()
		{
			return class_;
		}

		public Keyword[]				getKeywords()
		{
			return keywords;
		}

		public boolean					isWildcard()
		{
			return keywords.length == 1 && keywords[0] == Keyword.VALUE;
		}

		public 							Pattern(Class<?> class_, Keyword... keywords)
		{
			this.class_ = class_;
			this.keywords = keywords;
		}

		public boolean					checkTokens(String[] tokens)
		{
			if (keywords.length != tokens.length)
				return false;

			for (int i = 0; i < keywords.length; i++)
			{
				if (!keywords[i].checkToken(tokens[i]))
					return false;
			}

			return true;
		}
	}

	private static class				CommandParser
	{
		private final String[]			tokens;
		private Pattern					pattern;

		public Pattern					getPattern()
		{
			return pattern;
		}

		public							CommandParser(String command)
		{
			tokens = command.split("\\s+");
		}

		public boolean					canApplyPattern(Pattern pattern)
		{
			return pattern.checkTokens(tokens);
		}

		public void						applyPattern(Pattern pattern)
		{
			assert pattern.checkTokens(tokens);
			this.pattern = pattern;
		}

		public boolean					hasValue()
		{
			Keyword[]					keywords = pattern.getKeywords();

			for (Keyword keyword : keywords)
			{
				if (keyword == Keyword.VALUE)
					return true;
			}

			return false;
		}

		public String					extractValue()
		{
			Keyword[]					keywords = pattern.getKeywords();

			for (int i = 0; i < keywords.length; i++)
			{
				if (keywords[i] == Keyword.VALUE)
					return tokens[i];
			}

			return null;
		}
	}

	private static class				CommandBuilder
	{
		public static Commands.Abstract	build(CommandParser commandParser)
		{
			Object						object;
			Class<?>					class_;

			assert commandParser.getPattern() != null;

			class_ = commandParser.getPattern().getClass_();
			object =
				commandParser.hasValue() ?
				buildWithValue(class_, commandParser.extractValue()) : buildWithoutValue(class_);

			assert object instanceof Commands.Abstract;
			return (Commands.Abstract)object;
		}

		public static Object			buildWithValue(Class<?> class_, String value)
		{
			try
			{
				return class_.getConstructor(String.class).newInstance(value);
			}
			catch (Exception exception)
			{
				exception.printStackTrace();
				return null;
			}
		}

		public static Object			buildWithoutValue(Class<?> class_)
		{
			try
			{
				return class_.newInstance();
			}
			catch (Exception exception)
			{
				exception.printStackTrace();
				return null;
			}
		}
	}

	private static final
	Map<Context, Pattern[]>				contextToPatterns = new HashMap<Context, Pattern[]>()
	{{
		put
		(
			Context.ERROR,
			new Pattern[]{ new Pattern(Commands.Empty.class) }
		);

		put
		(
			Context.HERO_SELECTOR,
			new Pattern[]
			{
				new Pattern(Commands.Select.class, Keyword.VALUE),

				new Pattern(Commands.Create.class, Keyword.CREATE),
				new Pattern(Commands.Select.class, Keyword.SELECT, Keyword.VALUE),
				new Pattern(Commands.Delete.class, Keyword.DELETE, Keyword.VALUE),
				new Pattern(Commands.Delete.class, Keyword.INFO, Keyword.VALUE)
			}
		);

		put
		(
			Context.NAME_ENTRY,
			new Pattern[]{ new Pattern(Commands.Enter.class, Keyword.VALUE) }
		);

		put
		(
			Context.CLASS_SELECTOR,
			new Pattern[]
			{
				new Pattern(Commands.Select.class, Keyword.VALUE),
				new Pattern(Commands.Select.class, Keyword.SELECT, Keyword.VALUE)
			}
		);

		put
		(
			Context.MAP,
			new Pattern[]
			{
				new Pattern(Commands.GoNorth.class, Keyword.NORTH),
				new Pattern(Commands.GoEast.class, Keyword.EAST),
				new Pattern(Commands.GoSouth.class, Keyword.SOUTH),
				new Pattern(Commands.GoWest.class, Keyword.WEST)
			}
		);

	}};

	private static final Pattern[]		commonPatterns = new Pattern[]
	{
		new Pattern(Commands.Exit.class, Keyword.EXIT)
	};

	public static Commands.Abstract		translate(Signals.Console signal)
	{
		List<Pattern>					possiblePatterns;
		CommandParser					commandParser;
		Pattern							resultPattern;

		assert contextToPatterns.containsKey(signal.getContext());

		possiblePatterns = new LinkedList<>();

		possiblePatterns.addAll(Arrays.asList(contextToPatterns.get(signal.getContext())));
		possiblePatterns.addAll(Arrays.asList(commonPatterns));

		commandParser = new CommandParser(signal.getInput());
		resultPattern = null;

		for (Pattern pattern : possiblePatterns)
		{
			if (commandParser.canApplyPattern(pattern))
			{
				if (!pattern.isWildcard())
					return buildCommand(commandParser, pattern);

				resultPattern = pattern;
			}
		}

		if (resultPattern != null)
			return buildCommand(commandParser, resultPattern);

		return null;
	}

	private static Commands.Abstract	buildCommand(CommandParser commandParser, Pattern pattern)
	{
		if (commandParser.canApplyPattern(pattern))
		{
			commandParser.applyPattern(pattern);
			return CommandBuilder.build(commandParser);
		}
		return null;
	}
}
