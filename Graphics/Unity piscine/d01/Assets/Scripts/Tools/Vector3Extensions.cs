using UnityEngine;

public static class Vector3Extensions
{
	public static Vector3 AddX(this Vector3 vector, float delta)
	{
		return new Vector3(vector.x + delta, vector.y, vector.z);
	}

	public static Vector3 AddY(this Vector3 vector, float delta)
	{
		return new Vector3(vector.x, vector.y + delta, vector.z);
	}

	public static Vector3 AddZ(this Vector3 vector, float delta)
	{
		return new Vector3(vector.x, vector.y, vector.z + delta);
	}

	public static Vector3 SetX(this Vector3 vector, float x)
	{
		return new Vector3(x, vector.y, vector.z);
	}

	public static Vector3 SetY(this Vector3 vector, float y)
	{
		return new Vector3(vector.x, y, vector.z);
	}

	public static Vector3 SetZ(this Vector3 vector, float z)
	{
		return new Vector3(vector.x, vector.y, z);
	}

	public static Vector2 ToVector2(this Vector3 v)
	{
		return new Vector2(v.x, v.y);
	}
	
	public static Vector3 Abs(this Vector3 v)
	{
		return new Vector3(Mathf.Abs(v.x), Mathf.Abs(v.y), Mathf.Abs(v.z));
	}
}