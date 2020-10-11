package avajLauncher.simulation.aircrafts;

import avajLauncher.simulation.common.Coordinates;
import avajLauncher.simulation.common.Logger;

public abstract class			Aircraft
{
	private static long			idCounter = 0;

	protected long				id;
	protected String			name;
	protected Coordinates		coordinates;

	protected					Aircraft(String name, Coordinates coordinates)
	{
		id = nextId();
		this.name = name;
		this.coordinates = coordinates;
	}

	private static long			nextId()
	{
		return idCounter++;
	}

	public abstract String		getDescription();

	protected void				moveWithShift(Coordinates shift)
	{
		int						newLongitude;
		int						newLatitude;
		int						newHeight;

		newLongitude = coordinates.getLongitude() + shift.getLongitude();
		newLatitude = coordinates.getLatitude() + shift.getLatitude();
		newHeight = coordinates.getHeight() + shift.getHeight();

		coordinates = new Coordinates(newLongitude, newLatitude, newHeight);
	}

	protected void 				logMessage(String message)
	{
		Logger.WriteLine(getDescription() + " : " + message);
	}

	protected void 				logLanding()
	{
		logMessage("Landing at " + coordinates);
	}
}