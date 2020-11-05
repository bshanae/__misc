package avajLauncher.simulation;

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
			weatherTower.changeWeather();

		Logger.Close();
	}
}
