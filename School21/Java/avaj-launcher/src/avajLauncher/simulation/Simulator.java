package avajLauncher.simulation;

import avajLauncher.simulation.aircrafts.Flyable;
import avajLauncher.simulation.common.Logger;
import avajLauncher.simulation.scenario.Scenario;
import avajLauncher.simulation.scenario.ScenarioParser;
import avajLauncher.simulation.weather.WeatherTower;

public class					Simulator
{
	public static void			execute(String scenarioFile)
	{
		final Scenario			scenario = ScenarioParser.parse(scenarioFile);
		final WeatherTower		weatherTower = new WeatherTower();

		Logger.Open();

		for (Flyable flyable : scenario.getFlyables())
			flyable.registerTower(weatherTower);

		for (int i = 0; i < scenario.getNumberOfIteration(); i++)
		{
			Logger.WriteLine("Simulation no. " + i);
			weatherTower.changeWeather();
			Logger.WriteLine("");
		}

		Logger.Close();
	}
}
