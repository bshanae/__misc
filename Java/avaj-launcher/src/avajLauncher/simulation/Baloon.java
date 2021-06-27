package avajLauncher.simulation;

public class				Baloon extends Aircraft implements Flyable
{
	private WeatherTower	weatherTower;

							Baloon(String name, Coordinates coordinates)
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
				changeCoordinates(2, 0, 4);
				logMessage("I have the sun in my eyes, it's not cool");
				break ;

			case "RAIN" :
				changeCoordinates(0, 0, -5);
				logMessage("The experience is a bit ruined. You ever been in a hot air balloon under rain?!");
				break ;

			case "FOG" :
				changeCoordinates(0, 0, -3);
				logMessage("There is such a view up there... Too bad I can't see anything....");
				break ;

			case "SNOW" :
				changeCoordinates(+2, 0, -15);
				logMessage("It's snowing, we're gonna crash!");
				break ;

			default :
				throw new InternalException("[Balloon] Unknown weather");
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
