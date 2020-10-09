package simulation;

public class						WeatherProvider
{
	private static WeatherProvider	weatherProvider;
	private static String[]			weather;

	private							WeatherProvider()
	{
		weatherProvider = new WeatherProvider();
	}

	public static WeatherProvider	getWeatherProvider()
	{
		return weatherProvider;
	}

	public String					getCurrentWeather()
	{
		return null;
	}
}
