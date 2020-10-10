package avajLauncher.simulation.other;

public class			Coordinates
{
	private final int	longitude;
	private final int	latitude;
	private final int	height;

	public				Coordinates
						(
							int longitude,
							int latitude,
							int height
						)
	{
		this.longitude = Integer.max(0, longitude);
		this.latitude = Integer.max(0, latitude);
		this.height = Integer.max(0, Integer.min(100, height));
	}

	int					getLongitude()
	{
		return longitude;
	}

	int					getLatitude()
	{
		return latitude;
	}

	int					getHeight()
	{
		return height;
	}

	@Override
	public String		toString()
	{
		return
			"[Coordinates : "
			+ "longitude = " + latitude
			+ ", latitude = " + latitude
			+ ", height = " + height + "]";
	}
}
