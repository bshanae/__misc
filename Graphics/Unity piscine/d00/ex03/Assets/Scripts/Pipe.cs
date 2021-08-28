using UnityEngine;

[RequireComponent(typeof(SimpleCollider))]
public class Pipe : MonoBehaviour
{
	#region interface
	
	public Transform Transform { get; private set; }
	public SimpleCollider Collider { get; private set; }

	public bool WasPassed { get; private set; }
	public bool IsPassed { get; private set; }

	public void CheckIfPassed()
	{
		if (!isMain)
			return;

		if (WasPassed)
			return;

		if (IsPassed)
		{
			WasPassed = true;
			IsPassed = false;
			return;
		}

		if (bird.Transform.position.x > Transform.position.x)
			IsPassed = true;
	}

	#endregion

	#region engine fields

	[SerializeField] private float xMin;
	[SerializeField] private float xMax;
	[SerializeField] private bool isMain;
	[SerializeField] private Bird bird;

	#endregion

	#region engine events

	private void Awake()
	{
		Transform = GetComponent<Transform>();
		Collider = GetComponent<SimpleCollider>();
	}

	private void Update()
	{
		Move();
		ResetPositionIfNeeded();
	}

	#endregion

	#region main

	private float Speed
	{
		get
		{
			if (bird.IsGameOver)
				return 0;

			return bird.Score switch
			{
				var i when i <= 1 => 0.03f,
				var i when i <= 2 => 0.035f,
				var i when i <= 3 => 0.04f,
				var i when i <= 4 => 0.045f,
				var i when i <= 5 => 0.05f,
				var i when i <= 10 => 0.06f,
				var i when i <= 15 => 0.07f,
				var i when i >= 15 => 0.075f,
				_ => 0
			};
		}
	}

	private void Move()
	{
		Transform.Translate(new Vector3(-Speed, 0, 0));
	}

	private void ResetPositionIfNeeded()
	{
		if (Transform.position.x < xMin)
		{
			WasPassed = false;
			Transform.position = Transform.position.SetX(xMax);
		}
	}

	#endregion
}