package avajLauncher.simulation.aircrafts;

import avajLauncher.simulation.other.Coordinates;

public class				AircraftFactory
{
	public static class		UnknownAircraftType extends RuntimeException
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
		return switch (type)
		{
			case "Baloon" -> new Baloon(name, new Coordinates(longitude, latitude, height));
			case "Helicopter" -> new Helicopter(name, new Coordinates(longitude, latitude, height));
			case "JetPlane" -> new JetPlane(name, new Coordinates(longitude, latitude, height));
			default -> throw new UnknownAircraftType();
		};
	}
}
