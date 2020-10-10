package avajLauncher.simulation.aircrafts;

import avajLauncher.simulation.other.Coordinates;
import avajLauncher.simulation.towers.WeatherTower;

public class				JetPlane extends Aircraft implements Flyable
{
	private WeatherTower weatherTower;

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

	@Override
	public String			toString()
	{
		return "[JetPlane : id = " + id + ", name = " + name + ", coordinates = " + coordinates + "]";
	}
}
