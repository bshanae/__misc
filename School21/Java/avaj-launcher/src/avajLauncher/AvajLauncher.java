package avajLauncher;

import avajLauncher.simulation.scenario.Scenario;
import avajLauncher.simulation.scenario.ScenarioParser;

public class			AvajLauncher
{
	public static void	launchForDebug()
	{
		Scenario		scenario;

		scenario = ScenarioParser.parse("resources/validScenarios/Example.txt");
		System.out.println(scenario);
	}

	public static void	main(String[] arguments)
	{
		try
		{
			launchForDebug();
		}
		catch (RuntimeException exception)
		{
			System.out.println("[avaj-launcher] Critical error : " + exception.getMessage());
		}
	}
}
