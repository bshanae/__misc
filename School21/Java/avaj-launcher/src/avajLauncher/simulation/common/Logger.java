package avajLauncher.simulation.common;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class					Logger
{
	private static final String	file = "simulation.txt";

	private static PrintWriter	printWriter;

	public static void			Open()
	{
		try
		{
			printWriter = new PrintWriter(new FileWriter(file));
		}
		catch (IOException exception)
		{
			throw new InternalException("Can't create file for output");
		}
	}

	public static void			Close()
	{
		printWriter.close();
	}

	public static void			Write(String line)
	{
		if (printWriter == null)
			throw new InternalException("Can't write to output file");

		printWriter.print(line);
	}

	public static void			WriteLine(String line)
	{
		if (printWriter == null)
			throw new InternalException("Can't write to output file");

		printWriter.println(line);
	}
}
