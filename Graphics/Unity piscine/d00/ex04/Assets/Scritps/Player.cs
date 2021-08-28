using System;
using UnityEngine;

public class Player : MonoBehaviour
{
	#region interface

	public int Score { get; set; }

	#endregion

	#region engine fields

	[SerializeField] private Side side;
	[SerializeField] private Vector2 size;
	[SerializeField] private float moveSpeed;
	[SerializeField] private float yMin;
	[SerializeField] private float yMax;
	[SerializeField] private PongBall ball;

	#endregion

	#region engine events

	private void Update()
	{
		if (ball.Min.IsBetweenOrEquals(Min, Max) || ball.Max.IsBetweenOrEquals(Min, Max))
			ResolveCollision();

		if (Input.GetKey(UpKey))
			transform.Translate(new Vector2(0, moveSpeed * Time.deltaTime));
		if (Input.GetKey(DownKey))
			transform.Translate(new Vector2(0, -moveSpeed * Time.deltaTime));

		if (transform.position.y < yMin)
			transform.position = transform.position.SetY(yMin);

		if (transform.position.y > yMax)
			transform.position = transform.position.SetY(yMax);
	}

	#endregion

	#region main

	private enum Side
	{
		Left,
		Right
	}

	private Vector2 Min => transform.position.ToVector2() - size / 2;
	private Vector2 Max => transform.position.ToVector2() + size / 2;

	private string UpKey
	{
		get
		{
			return side switch
			{
				Side.Left => "w",
				Side.Right => "up",
				_ => throw new ArgumentOutOfRangeException()
			};
		}
	}

	private string DownKey
	{
		get
		{
			return side switch
			{
				Side.Left => "s",
				Side.Right => "down",
				_ => throw new ArgumentOutOfRangeException()
			};
		}
	}

	private void ResolveCollision()
	{
		switch (side)
		{
			case Side.Left:
				ball.Reflect(Vector2.right);
				ball.Push(PongBall.PushDirection.FromLeft, Max.x);
				break;

			case Side.Right:
				ball.Reflect(Vector2.left);
				ball.Push(PongBall.PushDirection.FromRight, Min.x);
				break;

			default:
				throw new ArgumentOutOfRangeException();
		}
	}

	#endregion
}