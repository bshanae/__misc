package avajLauncher.simulation.aircrafts;

import avajLauncher.simulation.other.Coordinates;
import avajLauncher.simulation.towers.WeatherTower;

public class				Helicopter extends Aircraft implements Flyable
{
	private WeatherTower	weatherTower;

	public					Helicopter(String name, Coordinates coordinates)
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
		return "[Helicopter : id = " + id + ", name = " + name + ", coordinates = " + coordinates + "]";
	}
}
