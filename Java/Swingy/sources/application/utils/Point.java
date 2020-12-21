package application.utils;

public class			Point
{
	public int			x;
	public int			y;

	public 				Point()
	{
		this(0, 0);
	}

	public 				Point(int value)
	{
		this(value, value);
	}

	public 				Point(int x, int y)
	{
		this.x = x;
		this.y = y;
	}

	public boolean		equals(Point other)
	{
		return this.x == other.x && this.y == other.y;
	}

	public Point		add(Point other)
	{
		return new Point(this.x + other.x, this.y + other.y);
	}

	public Point		subtract(Point other)
	{
		return new Point(this.x - other.x, this.y - other.y);
	}

	public Point		multiply(int value)
	{
		return new Point(this.x * value, this.y * value);
	}

	public Point		divide(int value)
	{
		return new Point(this.x / value, this.y / value);
	}

	public Point		abs()
	{
		return new Point(Math.abs(this.x), Math.abs(this.y));
	}

	public boolean		isLess(Point other)
	{
		return this.x < other.x && this.y < other.y;
	}

	public boolean		isLessOrEquals(Point other)
	{
		return this.x <= other.x && this.y <= other.y;
	}

	public boolean		isGreater(Point other)
	{
		return this.x > other.x && this.y > other.y;
	}

	public boolean		isGreaterOrEquals(Point other)
	{
		return this.x >= other.x && this.y >= other.y;
	}
}
