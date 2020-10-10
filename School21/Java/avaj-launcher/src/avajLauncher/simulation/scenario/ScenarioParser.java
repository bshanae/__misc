package avajLauncher.simulation.scenario;

import avajLauncher.simulation.aircrafts.Aircraft;
import avajLauncher.simulation.aircrafts.AircraftFactory;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class						ScenarioParser
{
//	------------------------------>	Exceptions

	public static class				CantOpenFile extends RuntimeException
	{
									CantOpenFile()
		{
			super("Can't open scenario file");
		}
	}

	public static class				FileIsEmpty extends RuntimeException
	{
									FileIsEmpty()
		{
			super("Scenario file is empty");
		}
	}

	public static class				AircraftsAreNotPresent extends RuntimeException
	{
									AircraftsAreNotPresent()
		{
			super("Aircraft are not present is scenario file");
		}
	}

	public static class				CantParseNumberOfIterations extends RuntimeException
	{
									CantParseNumberOfIterations()
		{
			super("Can't parse number of iterations in scenario file");
		}
	}

	public static class				CantParseAircraft extends RuntimeException
	{
									CantParseAircraft()
		{
			super("Can't parse aircraft in scenario file");
		}
	}

//	------------------------------>	Main method

	public static Scenario			parse(String pathToFile)
	{
		try
		{
			File					file = new File(pathToFile);
			Scanner					scanner = new Scanner(file);

			int						numberOfIteration;
			LinkedList<Aircraft>	aircrafts = new LinkedList<>();

			if (!scanner.hasNextLine())
				throw new FileIsEmpty();

			numberOfIteration = readNumberOfIterations(scanner.nextLine());

			while (scanner.hasNextLine())
				aircrafts.add(readAircraft(scanner.nextLine()));

			if (aircrafts.isEmpty())
				throw new AircraftsAreNotPresent();

			scanner.close();

			return new Scenario(numberOfIteration, aircrafts);
		}
		catch (FileNotFoundException exception)
		{
			throw new CantOpenFile();
		}
	}

//	------------------------------>	Reading

	private static int				readNumberOfIterations(String line)
	{
		try
		{
			Tokenizer				tokenizer;
			int						result;

			tokenizer = new Tokenizer(line);
			result = tokenizer.pollInt();

			tokenizer.assertEmpty();

			return result;
		}
		catch (RuntimeException exception)
		{
			throw new CantParseNumberOfIterations();
		}
	}

	private static Aircraft			readAircraft(String line)
	{
		try
		{
			Tokenizer				tokenizer;

			String					type;
			String					name;
			int						longitude;
			int						latitude;
			int						height;

			tokenizer = new Tokenizer(line);

			type = tokenizer.pollString();
			name = tokenizer.pollString();
			longitude = tokenizer.pollInt();
			latitude = tokenizer.pollInt();
			height = tokenizer.pollInt();

			tokenizer.assertEmpty();

			return AircraftFactory.newAircraft(type, name, longitude, latitude, height);
		}
		catch (Tokenizer.BadFormat | Tokenizer.BadInt | Tokenizer.TokensAreLeft exception)
		{
			throw new CantParseAircraft();
		}
	}

//	------------------------------>	Tokenizer

	private static class			Tokenizer
	{
		public static class			BadFormat extends RuntimeException {}
		public static class			BadInt extends RuntimeException {}
		public static class			TokensAreLeft extends RuntimeException {}

		Queue<String>				tokenQueue;

		public						Tokenizer(String line)
		{
			String[]				tokenArray;

			tokenArray = line.split("\\s+");
			tokenQueue = new LinkedList<>(Arrays.asList(tokenArray));
		}

		public String				pollString()
		{
			return pollToken();
		}

		public int					pollInt()
		{
			try
			{
				return Integer.parseInt(pollToken());
			}
			catch (NumberFormatException exception)
			{
				throw new BadInt();
			}
		}

		private String				pollToken()
		{
			if (tokenQueue.isEmpty())
				throw new BadFormat();

			return tokenQueue.poll();
		}

		public void 				assertEmpty()
		{
			if (!tokenQueue.isEmpty())
				throw new TokensAreLeft();
		}
	}
}
