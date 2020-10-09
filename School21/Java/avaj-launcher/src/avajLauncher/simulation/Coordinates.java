package avajLauncher.simulation;

public class		Coordinates
{
	int				longitude;
	int				latitude;
	int				height;

					Coordinates
					(
						int longitude,
						int latitude,
						int height
					)
	{
		this.longitude = longitude;
		this.latitude = latitude;
		this.height = height;
	}

	int				getLongitude()
	{
		return longitude;
	}

	int				getLatitude()
	{
		return latitude;
	}

	int				getHeight()
	{
		return height;
	}
}
