package avajLauncher.simulation.scenario;

import avajLauncher.simulation.aircrafts.Flyable;
import avajLauncher.simulation.common.UsageException;

import java.util.List;

public class				Scenario
{
	public static class		BadNumberOfIterations extends UsageException
	{
							BadNumberOfIterations()
		{
			super("Bad number of iterations");
		}
	}

	private int				numberOfIteration;
	private List<Flyable>	flyables;

							Scenario(int numberOfIteration, List<Flyable> flyables)
	{
		if (numberOfIteration < 1)
			throw new BadNumberOfIterations();

		this.numberOfIteration = numberOfIteration;
		this.flyables = flyables;
	}

	public int				getNumberOfIteration()
	{
		return numberOfIteration;
	}

	public List<Flyable>	getFlyables()
	{
		return flyables;
	}
}
