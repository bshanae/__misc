package simulation.aircrafts;

import simulation.Coordinates;
import simulation.towers.WeatherTower;

public class				JetPlane extends Aircraft implements Flyable
{
	private WeatherTower	weatherTower;

	public					JetPlane(String name, Coordinates coordinates)
	{
		super(name, coordinates);
	}

	public void				updateConditions()
	{

	}

	public void				registerTower(WeatherTower weatherTower)
	{

	}
}
