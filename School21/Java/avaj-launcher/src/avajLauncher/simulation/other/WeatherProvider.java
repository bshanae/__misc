package avajLauncher.simulation.other;

public class								WeatherProvider
{
	private static final WeatherProvider	weatherProvider = new WeatherProvider();
	private static String[]					weather;

	private									WeatherProvider()
	{ }

	public static WeatherProvider			getWeatherProvider()
	{
		return weatherProvider;
	}

	public String							getCurrentWeather()
	{
		return null;
	}
}
