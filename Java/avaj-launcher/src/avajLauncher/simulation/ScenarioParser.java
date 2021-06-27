package avajLauncher.simulation;

import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.text.ParseException;
import java.util.*;

public class							ScenarioParser
{
//	---------------------------------->	Main method

	public static Scenario				parse(String pathToFile)
	{
		try
		{
			File						file = new File(pathToFile);
			Scanner						scanner = new Scanner(file);

			int							numberOfIteration;
			LinkedList<Flyable>			flyables = new LinkedList<>();

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

//	---------------------------------->	Reading

	private static int					readNumberOfIterations(String line)
	{
		try
		{
			Tokenizer					tokenizer;
			int							result;

			tokenizer = new Tokenizer(line);
			result = tokenizer.pollNumberOfIterations();

			tokenizer.assertEmpty();

			return result;
		}
		catch (Tokenizer.BadFormat | Tokenizer.BadInt | Tokenizer.TokensAreLeft exception)
		{
			throw new UsageException("Can't parse number of iterations in scenario file");
		}
	}

	private static Flyable				readAircraft(String line)
	{
		try
		{
			Tokenizer					tokenizer;

			String						type;
			String						name;
			int							longitude;
			int							latitude;
			int							height;

			tokenizer = new Tokenizer(line);

			type = tokenizer.pollType();
			name = tokenizer.pollName();
			longitude = tokenizer.pollLongitude();
			latitude = tokenizer.pollLatitude();
			height = tokenizer.pollHeight();

			tokenizer.assertEmpty();

			return (Flyable)AircraftFactory.newAircraft(type, name, longitude, latitude, height);
		}
		catch (Tokenizer.BadFormat | Tokenizer.BadInt | Tokenizer.TokensAreLeft exception)
		{
			throw new UsageException("Can't parse aircraft in scenario file");
		}
	}

//	---------------------------------->	Tokenizer

	private static class				Tokenizer
	{

		public static class				BadFormat extends UsageException {}
		public static class				BadInt extends UsageException {}
		public static class				TokensAreLeft extends UsageException {}

		public static final int			numberOfIterationsMin = 1;
		public static final int			numberOfIterationsMax = 100000;
		public static final String[]	namePrefixes = {"B", "H", "J"};
		public static final int			nameNumberMin = 1;
		public static final int			nameNumberMax = 100000;
		public static final int			longitudeMin = 0;
		public static final int			longitudeMax = 100000;
		public static final int			latitudeMin = 0;
		public static final int			latitudeMax = 100000;
		public static final int			heightMin = 0;
		public static final int			heightMax = 100;

		Queue<String>					tokenQueue;

		public							Tokenizer(String line)
		{
			String[]					tokenArray;

			tokenArray = line.split("\\s+");
			tokenQueue = new LinkedList<>(Arrays.asList(tokenArray));
		}

		public int						pollNumberOfIterations()
		{
			return pollNumber(numberOfIterationsMin, numberOfIterationsMax);
		}

		public String					pollType()
		{
			String						string = pollToken();

			if (MD5.isHash(string))
			{
				if (MD5.tryDecode(string, "Baloon"))
					return "Baloon";
				else if (MD5.tryDecode(string, "Helicopter"))
					return "Helicopter";
				else if (MD5.tryDecode(string, "JetPlane"))
					return "JetPlane";
				else
					throw new UsageException("Can't decode type of aircraft");
			}
			else
				return string;
		}

		public String					pollName()
		{
			String						string = pollToken();

			if (MD5.isHash(string))
			{
				for (String prefix : namePrefixes)
					for (int i = nameNumberMin; i <= nameNumberMax; i++)
					{
						String			test = prefix + i;

						if (MD5.tryDecode(string, test))
							return test;
					}

				throw new UsageException("Can't decode name of aircraft");
			}
			else
				return string;
		}

		public int						pollLongitude()
		{
			final int					value = pollNumber(longitudeMin, longitudeMax);

			if (value < 1)
				throw new UsageException("Bad longitude value");
			else
				return value;
		}

		public int						pollLatitude()
		{
			final int					value = pollNumber(latitudeMin, latitudeMax);

			if (value < 1)
				throw new UsageException("Bad latitude value");
			else
				return value;
		}

		public int						pollHeight()
		{
			return pollNumber(heightMin, heightMax);
		}

		private int						pollNumber(int min, int max)
		{
			String						token = pollToken();

			if (MD5.isHash(token))
			{
				for (int i = min; i <= max; i++)
					if (MD5.tryDecode(token, String.valueOf(i)))
						return i;

				throw new UsageException("Can't decode name of aircraft");
			}
			else
			{
				try
				{
					return Integer.parseInt(token);
				}
				catch (NumberFormatException exception)
				{
					throw new BadInt();
				}
			}
		}

		private String					pollToken()
		{
			if (tokenQueue.isEmpty())
				throw new BadFormat();

			return tokenQueue.poll();
		}

		public void 					assertEmpty()
		{
			if (!tokenQueue.isEmpty())
				throw new TokensAreLeft();
		}
	}

//	---------------------------------->	MD5

	private static class				MD5
	{
		private static final MD5		instance = new MD5();

		private final MessageDigest		messageDigest;

		private							MD5()
		{
			try
			{
				messageDigest = MessageDigest.getInstance("MD5");
			}
			catch (NoSuchAlgorithmException exception)
			{
				throw new InternalException("[ScenarioParser, MD5] Can't initialize instance");
			}
		}

		public static boolean			isHash(String string)
		{
			return string.length() == 32 && string.matches("-?[0-9a-fA-F]+");
		}

		public static String			encode(String string)
		{
			byte[]						digest;
			BigInteger					bigInt;

			instance.messageDigest.reset();
			instance.messageDigest.update(string.getBytes());

			digest = instance.messageDigest.digest();
			bigInt = new BigInteger(1, digest);

			return bigInt.toString(16);
		}

		public static boolean			tryDecode(String hashed, String assumed)
		{
			return hashed.equals(encode(assumed));
		}
	}
}
