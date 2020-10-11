package avajLauncher.simulation.weather;

import avajLauncher.simulation.aircrafts.Aircraft;
import avajLauncher.simulation.aircrafts.Flyable;
import avajLauncher.simulation.common.InternalException;
import avajLauncher.simulation.common.Logger;

import java.util.LinkedList;
import java.util.List;

public class					Tower
{
	private final List<Flyable>	observers = new LinkedList<>();

	public void					register(Flyable flyable)
	{
		observers.add(flyable);
		Logger.WriteLine
		(
			"Tower says : "
			+ getAircraftFromFlyable(flyable).getDescription()
			+ "registered to weather tower"
		);
	}

	public void					unregister(Flyable flyable)
	{
		observers.remove(flyable);
		Logger.WriteLine
		(
			"Tower says : "
			+ getAircraftFromFlyable(flyable).getDescription()
			+ "unregistered from weather tower"
		);
	}

	protected void				conditionsChanged()
	{
		for (Flyable observer : observers)
			observer.updateConditions();
	}

	private Aircraft			getAircraftFromFlyable(Flyable flyable)
	{
		if (flyable instanceof Aircraft)
			return (Aircraft)flyable;
		else
			throw new InternalException("[Tower] Can't cast flyable to aircraft");
	}
}
