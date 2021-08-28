using UnityEngine;

public class CubeSpawner : MonoBehaviour
{
	#region serialized fields

	[SerializeField] private float generationPeriodMin;
	[SerializeField] private float generationPeriodMax;
	[SerializeField] private string catchKey;
	[SerializeField] private Cube prefab;
	[SerializeField] private float cubeSpeedMin;
	[SerializeField] private float cubeSpeedMax;
	[SerializeField] public float cubeCatchY;
	[SerializeField] public float cubeKillY;

	#endregion

	#region engine events

	private void Update()
	{
		if (CanGenerateCube)
		{
			ResetTimerForNextGeneration();
			GenerateCube();
		}

		UpdateTimerForNextGeneration();
	}

	#endregion

	#region common

	private bool CanGenerateCube => _timerForNextGeneration <= 0f && _currentCube == null;	

	#endregion

	#region timer

	private float? _timerForNextGeneration;

	private void ResetTimerForNextGeneration()
	{
		_timerForNextGeneration = null;
	}

	private void UpdateTimerForNextGeneration()
	{
		_timerForNextGeneration ??= GenerateNextPeriod();
		_timerForNextGeneration -= Time.deltaTime;
	}

	private float GenerateNextPeriod()
	{
		return Random.Range(generationPeriodMin, generationPeriodMax);
	}

	#endregion

	#region cube

	private Cube _currentCube;

	private void GenerateCube()
	{
		_currentCube = Instantiate(prefab);

		_currentCube.transform.position = transform.position;
		_currentCube.speed = GenerateCubeSpeed();
		_currentCube.catchKey = catchKey;
		_currentCube.catchY = cubeCatchY;
		_currentCube.killY = cubeKillY;
	}

	private float GenerateCubeSpeed()
	{
		return Random.Range(cubeSpeedMin, cubeSpeedMax);
	}

	#endregion
}