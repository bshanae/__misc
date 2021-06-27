package avajLauncher.simulation;

public class				JetPlane extends Aircraft implements Flyable
{
	private WeatherTower	weatherTower;

							JetPlane(String name, Coordinates coordinates)
	{
		super(name, coordinates);
	}

	public String			getDescription()
	{
		return String.format("JetPlane#%s(%d)", name, id);
	}

	public void				updateConditions()
	{
		if (weatherTower == null)
			throw new InternalException("[JetPlane] Can't update conditions, weather tower is null");

		switch (weatherTower.getWeather(this.coordinates))
		{
			case "SUN" :
				changeCoordinates(10, 0, 2);
				logMessage("IT'S SUNNY AND I AM GOING FAAAAST WOOOOOOOOOOW !!!!!!!!!!");
				break ;

			case "RAIN" :
				changeCoordinates(0, 5, 0);
				logMessage("Well I can't see anything because of the rain but I guess it's cool to fly in a jet plane anyway!");
				break ;

			case "FOG" :
				changeCoordinates(0, 1, 0);
				logMessage("Is there something in front of me? My radar isn't working! Do I have something to honk?! Oh yes this! Wow it was ejectable seat.");
				break ;

			case "SNOW" :
				changeCoordinates(0, 0, -7);
				logMessage("It's beautiful!!!!");
				break ;

			default :
				throw new InternalException("[JetPlane] Unknown weather");
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
