package avajLauncher.simulation.aircrafts;

import avajLauncher.simulation.common.Coordinates;
import avajLauncher.simulation.common.InternalException;
import avajLauncher.simulation.weather.WeatherTower;

public class				Helicopter extends Aircraft implements Flyable
{
	private WeatherTower	weatherTower;

	public					Helicopter(String name, Coordinates coordinates)
	{
		super(name, coordinates);
	}

	public String			getDescription()
	{
		return String.format("Helicopter#%s(%d)", name, id);
	}

	public void				updateConditions()
	{
		if (weatherTower == null)
			throw new InternalException("[Helicopter] Can't update conditions, weather tower is null");

		switch (weatherTower.getWeather(this.coordinates))
		{
			case "SUN" :
				changeCoordinates(10, 0, 2);
				logMessage("Wow, it's hot. My rotating motor is going to explode...");
				break ;

			case "RAIN" :
				changeCoordinates(5, 0, 0);
				logMessage("HELP IT'S RAINING BLBLBLBLBL");
				break ;

			case "FOG" :
				changeCoordinates(1, 0, 0);
				logMessage("I can't see shit.");
				break ;

			case "SNOW" :
				changeCoordinates(0, 0, -12);
				logMessage("Brrrrr.... It's freezing!");
				break ;

			default :
				throw new InternalException("[Helicopter] Unknown weather");
		}

		if (coordinates.getHeight() == 0)
		{
			logLanding();
			weatherTower.unregister(this);
		}
	}

	public void				registerTower(WeatherTower weatherTower)
	{
		this.weatherTower = weatherTower;
		weatherTower.register(this);
	}
}
