package application.utils;

public class			PointRange
{
	private final Point	min;
	private final Point	max;

	public				PointRange(Point min, Point max)
	{
		this.min = min;
		this.max = max;
	}

	public boolean		isInRange(Point point)
	{
		return point.isGreaterOrEquals(min) && point.isLess(max);
	}
}
