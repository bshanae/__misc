package avajLauncher.simulation.weather;

import avajLauncher.simulation.common.Coordinates;

public class								WeatherProvider
{
	private static final WeatherProvider	weatherProvider = new WeatherProvider();
	private static final String[]			weather = {"RAIN", "FOG", "SUN", "SNOW"};

	private									WeatherProvider()
	{ }

	public static WeatherProvider			getWeatherProvider()
	{
		return weatherProvider;
	}

	public String							getCurrentWeather(Coordinates coordinates)
	{
		int									hash;
		int									index;

		hash = coordinates.getLongitude();
		hash += coordinates.getLatitude();
		hash += coordinates.getHeight();

		index = Math.abs(hash % 4);

		return weather[index];
	}
}
