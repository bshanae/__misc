package avajLauncher;

import avajLauncher.simulation.Simulator;
import avajLauncher.simulation.UsageException;

public class			AvajLauncher
{
	public static void	main(String[] arguments)
	{
		try
		{
			if (arguments.length < 1)
				throw new UsageException("No arguments passed to program");

			Simulator.execute(arguments[0]);
		}
		catch (UsageException exception)
		{
			System.err.println("[avaj-launcher] Usage error : " + exception.getMessage());
		}
		catch (InternalError exception)
		{
			System.err.println("[avaj-launcher] Internal error : " + exception.getMessage());
		}
		catch (Exception exception)
		{
			System.err.println("[avaj-launcher] Unknown error : " + exception.getMessage());
			exception.printStackTrace();
		}
	}
}
