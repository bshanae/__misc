package avajLauncher.simulation.scenario;

import avajLauncher.simulation.aircrafts.Aircraft;

import java.util.List;

public class				Scenario
{
	public static class		BadNumberOfIterations extends RuntimeException
	{
							BadNumberOfIterations()
		{
			super("Bad number of iterations");
		}
	}

	private int				numberOfIteration;
	private List<Aircraft>	aircrafts;

							Scenario(int numberOfIteration, List<Aircraft> aircrafts)
	{
		if (numberOfIteration < 1)
			throw new BadNumberOfIterations();

		this.numberOfIteration = numberOfIteration;
		this.aircrafts = aircrafts;
	}

	@Override
	public String			toString()
	{
		StringBuilder		stringBuilder = new StringBuilder();

		stringBuilder.append("[Scenario : ");
		stringBuilder.append("\n");

		stringBuilder.append("\t");
		stringBuilder.append("Number of iterations : ");
		stringBuilder.append(numberOfIteration);
		stringBuilder.append("\n");

		stringBuilder.append("\tAircrafts : {\n");

		for (Aircraft aircraft : aircrafts)
		{
			stringBuilder.append("\t\t");
			stringBuilder.append(aircraft);
			stringBuilder.append("\n");
		}

		stringBuilder.append("\t}\n");
		stringBuilder.append("]");

		return stringBuilder.toString();
	}
}
