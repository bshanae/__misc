package avajLauncher.simulation;

public class			Coordinates
{
	private final int	longitude;
	private final int	latitude;
	private final int	height;

						Coordinates
						(
							int longitude,
							int latitude,
							int height
						)
	{
		this.longitude = limit(longitude, 0, null);
		this.latitude = limit(latitude, 0, null);
		this.height = limit(height, 0, 100);
	}

	private int			limit(int value, Integer min, Integer max)
	{
		if (min != null && value < min)
			return min;
		if (max != null && value > max)
			return max;

		return value;
	}

	public int			getLongitude()
	{
		return longitude;
	}

	public int			getLatitude()
	{
		return latitude;
	}

	public int			getHeight()
	{
		return height;
	}

	@Override
	public String		toString()
	{
		return String.format("[%d, %d, %d]", longitude, latitude, height);
	}
}
