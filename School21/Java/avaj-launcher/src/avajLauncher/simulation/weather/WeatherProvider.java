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

		hash = 1;
		hash *= coordinates.getLongitude() * 123;
		hash *= coordinates.getLatitude() * 23949;
		hash *= coordinates.getHeight() * 77;

		index = Math.abs(hash % 4);

		System.out.println("hash = " + hash);
		System.out.println("index = " + index);

		return weather[index];
	}
}
