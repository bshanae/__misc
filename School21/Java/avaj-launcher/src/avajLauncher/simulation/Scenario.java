package avajLauncher.simulation;


import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class			Scenario
{
	public class		Instruction
	{

	}

	public static void	Read(String pathToFile)
	{
		try
		{
			File		file = new File(pathToFile);
			Scanner		scanner = new Scanner(file);

			while (scanner.hasNextLine())
				System.out.println(scanner.nextLine());

			scanner.close();
		}
		catch (FileNotFoundException exception)
		{
			exception.printStackTrace();
		}
	}
}
