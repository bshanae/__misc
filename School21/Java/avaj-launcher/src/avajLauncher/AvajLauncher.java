package avajLauncher;

import avajLauncher.simulation.Simulator;
import avajLauncher.simulation.common.ParsingException;

public class			AvajLauncher
{
	public static void	main(String[] arguments)
	{
		try
		{
			Simulator.execute("resources/validScenarios/Example.txt");
		}
		catch (ParsingException exception)
		{
			System.err.println("[avaj-launcher] Parsing error : " + exception.getMessage());
		}
		catch (InternalError exception)
		{
			System.err.println("[avaj-launcher] Internal error : " + exception.getMessage());
		}
		catch (Exception exception)
		{
			System.err.println("[avaj-launcher] Unknown error : " + exception.getMessage());
		}
	}
}
