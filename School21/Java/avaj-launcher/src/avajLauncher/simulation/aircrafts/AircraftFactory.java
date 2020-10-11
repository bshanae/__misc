package avajLauncher.simulation.aircrafts;

import avajLauncher.simulation.common.Coordinates;
import avajLauncher.simulation.common.UsageException;

public class				AircraftFactory
{
	public static class		UnknownAircraftType extends UsageException
	{
							UnknownAircraftType()
		{
			super("Unknown aircraft type");
		}
	}

	public static Aircraft	newAircraft
							(
								String type,
								String name,
								int longitude,
								int latitude,
								int height
							)
	{
		switch (type)
		{
			case "Baloon" :
				return new Baloon(name, new Coordinates(longitude, latitude, height));

			case "Helicopter" :
				return new Helicopter(name, new Coordinates(longitude, latitude, height));

			case "JetPlane" :
				return new JetPlane(name, new Coordinates(longitude, latitude, height));

			default:
				throw new UnknownAircraftType();
		}
	}
}
