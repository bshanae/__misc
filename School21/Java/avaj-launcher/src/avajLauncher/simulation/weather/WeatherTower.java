package avajLauncher.simulation.weather;

import avajLauncher.simulation.common.Coordinates;

public class		WeatherTower extends Tower
{
	public String	getWeather(Coordinates coordinates)
	{
		return WeatherProvider.getWeatherProvider().getCurrentWeather(coordinates);
	}

	public void		changeWeather()
	{
		conditionsChanged();
	}
}
