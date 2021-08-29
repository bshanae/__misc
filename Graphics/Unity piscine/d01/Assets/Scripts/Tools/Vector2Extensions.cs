using UnityEngine;

public static class Vector2Extensions
{
	public static Vector2 AddX(this Vector2 vector, float delta)
	{
		return new Vector2(vector.x + delta, vector.y);
	}

	public static Vector2 AddY(this Vector2 vector, float delta)
	{
		return new Vector2(vector.x, vector.y + delta);
	}

	public static Vector2 SetX(this Vector2 vector, float x)
	{
		return new Vector2(x, vector.y);
	}

	public static Vector2 SetY(this Vector2 vector, float y)
	{
		return new Vector2(vector.x, y);
	}
}