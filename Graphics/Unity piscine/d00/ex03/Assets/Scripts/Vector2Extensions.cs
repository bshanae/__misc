using UnityEngine;

public static class Vector2Extensions
{
	public static bool IsLess(this Vector2 a, Vector2 b)
	{
		return a.x < b.x && a.y < b.y;
	}

	public static bool IsLessOrEquals(this Vector2 a, Vector2 b)
	{
		return a.x <= b.x && a.y <= b.y;
	}

	public static bool IsMore(this Vector2 a, Vector2 b)
	{
		return a.x > b.x && a.y > b.y;
	}

	public static bool IsMoreOrEquals(this Vector2 a, Vector2 b)
	{
		return a.x >= b.x && a.y >= b.y;
	}

	public static bool IsBetween(this Vector2 a, Vector2 b, Vector2 c)
	{
		return a.IsMore(b) && a.IsLess(c);
	}

	public static bool IsBetweenOrEquals(this Vector2 a, Vector2 b, Vector2 c)
	{
		return a.IsMoreOrEquals(b) && a.IsLessOrEquals(c);
	}
}