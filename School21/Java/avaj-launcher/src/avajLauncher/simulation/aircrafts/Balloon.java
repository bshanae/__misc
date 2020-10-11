package avajLauncher.simulation.aircrafts;

import avajLauncher.simulation.common.Coordinates;
import avajLauncher.simulation.common.InternalException;
import avajLauncher.simulation.weather.WeatherTower;

public class				Balloon extends Aircraft implements Flyable
{
	private WeatherTower	weatherTower;

	public					Balloon(String name, Coordinates coordinates)
	{
		super(name, coordinates);
	}

	public String			getDescription()
	{
		return String.format("Baloon#%s(%d)", name, id);
	}

	public void				updateConditions()
	{
		if (weatherTower == null)
			throw new InternalException("[Balloon] Can't update conditions, weather tower is null");

		switch (weatherTower.getWeather(this.coordinates))
		{
			case "SUN" :
				moveWithShift(new Coordinates(2, 0, 4));
				logMessage("I have the sun in my eyes, it's not cool");
				break ;

			case "RAIN" :
				moveWithShift(new Coordinates(0, 0, -5));
				logMessage("The experience is a bit ruined. You ever been in a hot air balloon under rain?!");
				break ;

			case "FOG" :
				moveWithShift(new Coordinates(0, 0, -3));
				logMessage("There is such a view up there... Too bad I can't see anything....");
				break ;

			case "SNOW" :
				moveWithShift(new Coordinates(+2, 0, -15));
				logMessage("It's snowing, we're gonna crash!");
				break ;

			default :
				throw new InternalException("[Balloon] Unknown weather");
		}

		if (coordinates.getHeight() == 0)
		{
			weatherTower.unregister(this);
			logLanding();
		}
	}

	public void				registerTower(WeatherTower weatherTower)
	{
		this.weatherTower = weatherTower;
		weatherTower.register(this);
	}
}
