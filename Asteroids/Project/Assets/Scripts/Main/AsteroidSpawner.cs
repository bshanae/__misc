using System;
using System.Collections.Generic;
using UnityEngine;
using Random = UnityEngine.Random;

public class AsteroidSpawner : MonoBehaviour
{
	#region Constants
	
	const float pushPowerStart = 300f;
	const float pushPowerFinish = 800f;
	const float pushPowerDelta = 0.01f;
	
	private const float explosionPower = 600f;
	
	private const float offsetX = 0;
	private const float offsetY = 0;

	private const float nextAsteroidStart = 4f;
	private const float nextAsteroidFinish = 2.5f;
	private const float Delta = 0.01f;
	
	#endregion
	
	#region Fields
	
	[SerializeField] private GameObject asteroid1;
	[SerializeField] private GameObject asteroid2;
	[SerializeField] private GameObject asteroid3;

	private Timer nextAsteroidTimer;
	private float nextAsteroidDuration = nextAsteroidStart;

	float pushPower = pushPowerStart;
	
	#endregion

	#region Properties

	private float PushPower
	{
		get
		{
			if (pushPower < pushPowerFinish)
				pushPower *= 1 + pushPowerDelta;
			return pushPower;
		}
	}

	private float NextAsteroidDuration
	{
		get
		{
			if (nextAsteroidDuration <= nextAsteroidFinish)
				nextAsteroidDuration = float.MaxValue;
			else
				nextAsteroidDuration *= 1f - Delta;
			return nextAsteroidDuration;
		}
	}

	#endregion

	#region UnityEvents
	
	public void Start()
	{
		asteroid1 = Resources.Load("Prefabs/Asteroid1") as GameObject;
		asteroid2 = Resources.Load("Prefabs/Asteroid2") as GameObject;
		asteroid3 = Resources.Load("Prefabs/Asteroid3") as GameObject;

		BuildAsteroidByDirection(Direction.Left);
		BuildAsteroidByDirection(Direction.Right);
		BuildAsteroidByDirection(Direction.Down);
		BuildAsteroidByDirection(Direction.Up);

		nextAsteroidTimer = gameObject.AddComponent<Timer>();
		StartTimerForAsteroid();
	}

	public void Update()
	{
		if (nextAsteroidTimer.Finished)
		{
			RandomAsteroid();
			StartTimerForAsteroid();
		}
	}

	#endregion
	
	#region GeneratingAsteroidByDirection

	private Vector2 RandomForce(float[] range, float power)
	{
		float angle = Random.Range(range[0], range[1]) * Mathf.Deg2Rad;
		Vector2 vector = new Vector2(Mathf.Cos(angle), Mathf.Sin(angle));
		
		return vector.normalized * pushPower;
	}

	private GameObject RandomAsteroidObject()
	{
		switch (Random.Range(1, 4))
		{
			case 1 :
				return Instantiate(asteroid1);
			
			case 2 :
				return Instantiate(asteroid2);
			
			case 3 :
				return Instantiate(asteroid3);
		}

		return null;
	}
	
	private enum Direction
	{
		Left,
		Right,
		Down,
		Up
	}

	private float[] AngleByDirection(Direction direction)
	{
		switch (direction)
		{
			case Direction.Left :
				return new float[] {-90, 90};
			
			case Direction.Right :
				return new float[] {90, 270};
			
			case Direction.Down :
				return new float[] {0, 180};
			
			case Direction.Up :
				return new float[] {180, 360};
		}

		return null;
	}

	private Vector2 PositionByDirection(Direction direction)
	{
		switch (direction)
		{
			case Direction.Left :
				return new Vector2(ScreenInfo.ScreenLeft + offsetX, 0);
			
			case Direction.Right :
				return new Vector2(ScreenInfo.ScreenRight - offsetX, 0);
			
			case Direction.Down :
				return new Vector2(0, ScreenInfo.ScreenBottom + offsetY);
			
			case Direction.Up :
				return new Vector2(0, ScreenInfo.ScreenTop - offsetY);
		}

		return new Vector2();
	}

	private void BuildAsteroidByDirection(Direction direction)
	{
		float[] angleRange = AngleByDirection(direction);
		Vector2 position = PositionByDirection(direction);

		GameObject newObject = RandomAsteroidObject();

		newObject.transform.position = position;
		newObject.GetComponent<Rigidbody2D>().AddForce(RandomForce(angleRange, PushPower), ForceMode2D.Impulse);
	}
	
	#endregion

	#region RandomAsteroid

	void RandomAsteroid()
	{
		Array array = Enum.GetValues(typeof(Direction));
		int random = Random.Range(0, array.Length);
	
		BuildAsteroidByDirection((Direction)random);
	}

	#endregion

	#region AsteroidReducing
	
	public void ReduceAsteroid(GameObject oldObject)
	{
		GameObject original = null;
		
		Vector2 oldPosition = oldObject.transform.position;
		string oldTag = oldObject.tag;
		
		GameObject[] newObjects = new GameObject[2];
		Vector2[] newForces = new Vector2[2];

		if (oldTag == "Asteroid2")
			original = asteroid1;
		else if (oldTag == "Asteroid3")
			original = asteroid2;

		if (original)
		{
			newObjects[0] = Instantiate(original);
			newObjects[1] = Instantiate(original);

			newObjects[0].transform.position = oldPosition;
			newObjects[1].transform.position = oldPosition;

			newForces[0] = RandomForce(new float[] {0, 360}, explosionPower);
			newForces[1] = RandomForce(new float[] {0, 360}, explosionPower);

			newObjects[0].GetComponent<Rigidbody2D>().AddForce(newForces[0], ForceMode2D.Impulse);
			newObjects[1].GetComponent<Rigidbody2D>().AddForce(newForces[1], ForceMode2D.Impulse);
		}

		Destroy(oldObject);
	}

	#endregion

	#region AsteroidTimerGenerating

	void StartTimerForAsteroid()
	{
		nextAsteroidTimer.Duration = NextAsteroidDuration;
		nextAsteroidTimer.Run();
	}

	#endregion
}
