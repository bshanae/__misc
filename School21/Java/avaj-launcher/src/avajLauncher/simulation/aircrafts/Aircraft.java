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

	protected void				changeCoordinates(int longitudeChange, int latitudeChange, int heightChange)
	{
		int						newLongitude;
		int						newLatitude;
		int						newHeight;

		newLongitude = coordinates.getLongitude() + longitudeChange;
		newLatitude = coordinates.getLatitude() + latitudeChange;
		newHeight = coordinates.getHeight() + heightChange;

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

	protected void				logCoordinates()
	{
		logMessage("I'm on " + coordinates);
	}
}