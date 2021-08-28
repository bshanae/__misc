using System.Text;
using UnityEngine;

[RequireComponent(typeof(SimpleCollider))]
public class Bird : MonoBehaviour
{
	#region interface

	public Transform Transform { get; private set; }
	public SimpleCollider Collider { get; private set; }

	public int Score { get; private set; }

	public bool IsGameOver { get; private set; }

	#endregion

	#region engine fields

	[SerializeField] private float flapForce;
	[SerializeField] private float fallingConstant;
	[SerializeField] private float verticalSpeedMax;
	[SerializeField] private float verticalSpeedMin;
	[SerializeField] private float yMax;
	[SerializeField] private float yMin;
	[SerializeField] private Pipe[] pipes;

	#endregion

	#region engine events

	private void Awake()
	{
		Transform = GetComponent<Transform>();
		Collider = GetComponent<SimpleCollider>();
	}

	private void Start()
	{
		_gameStartTime = Time.time;
	}

	private void Update()
	{
		if (IsGameOver)
			return;

		CheckFlap();

		UpdateSpeed();
		CheckSpeed();

		UpdatePosition();
		CheckPosition();

		ProcessPipes();
	}

	#endregion

	#region main

	private float _gameStartTime;
	private float _verticalSpeed;

	private void CheckFlap()
	{
		if (Input.GetKeyDown(KeyCode.Space))
			_verticalSpeed += flapForce;
	}

	private void UpdateSpeed()
	{
		_verticalSpeed += fallingConstant * Time.deltaTime;
	}

	private void CheckSpeed()
	{
		if (_verticalSpeed < verticalSpeedMin)
			_verticalSpeed = verticalSpeedMin;

		if (_verticalSpeed > verticalSpeedMax)
			_verticalSpeed = verticalSpeedMax;
	}

	private void UpdatePosition()
	{
		transform.Translate(new Vector3(0, _verticalSpeed * Time.deltaTime, 0));
	}

	private void CheckPosition()
	{
		if (Transform.position.y > yMax)
		{
			Transform.position = Transform.position.SetY(yMax);
			_verticalSpeed = 0;
		}

		if (Transform.position.y < yMin)
		{
			Transform.position = Transform.position.SetY(yMin);
			_verticalSpeed = 0;
		}
	}

	private void ProcessPipes()
	{
		foreach (var pipe in pipes)
		{
			if (pipe.Collider.DoesCollideWith(this.Collider))
			{
				FinishGame();
				return;
			}

			pipe.CheckIfPassed();

			if (pipe.IsPassed)
				Score++;
		}
	}

	private void FinishGame()
	{
		IsGameOver = true;

		Debug.Log($"Score: {Score * 5}");
		Debug.Log($"Time: {Mathf.RoundToInt(Time.time - _gameStartTime)}s");
	}

	#endregion
}