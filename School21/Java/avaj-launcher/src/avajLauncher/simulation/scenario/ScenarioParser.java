package avajLauncher.simulation.scenario;

import avajLauncher.simulation.aircrafts.AircraftFactory;
import avajLauncher.simulation.aircrafts.Flyable;
import avajLauncher.simulation.common.UsageException;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class						ScenarioParser
{
//	------------------------------>	Main method

	public static Scenario			parse(String pathToFile)
	{
		try
		{
			File					file = new File(pathToFile);
			Scanner					scanner = new Scanner(file);

			int						numberOfIteration;
			LinkedList<Flyable>		flyables = new LinkedList<>();

			if (!scanner.hasNextLine())
				throw new UsageException("Scenario file is empty");

			numberOfIteration = readNumberOfIterations(scanner.nextLine());

			while (scanner.hasNextLine())
				flyables.add(readAircraft(scanner.nextLine()));

			if (flyables.isEmpty())
				throw new UsageException("Aircraft are not present is scenario file");

			scanner.close();

			return new Scenario(numberOfIteration, flyables);
		}
		catch (FileNotFoundException exception)
		{
			throw new UsageException("Can't open scenario file");
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
		catch (Tokenizer.BadFormat | Tokenizer.BadInt | Tokenizer.TokensAreLeft exception)
		{
			throw new UsageException("Can't parse number of iterations in scenario file");
		}
	}

	private static Flyable			readAircraft(String line)
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

			return (Flyable)AircraftFactory.newAircraft(type, name, longitude, latitude, height);
		}
		catch (Tokenizer.BadFormat | Tokenizer.BadInt | Tokenizer.TokensAreLeft exception)
		{
			throw new UsageException("Can't parse aircraft in scenario file");
		}
	}

//	------------------------------>	Tokenizer

	private static class			Tokenizer
	{
		public static class			BadFormat extends UsageException {}
		public static class			BadInt extends UsageException {}
		public static class			TokensAreLeft extends UsageException {}

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
