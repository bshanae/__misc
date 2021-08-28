using UnityEngine;

public class Ball : MonoBehaviour
{
	#region interface

	public bool IsStill => _velocity < 0.0001f;

	public void Strike(float acceleration)
	{
		_velocity += acceleration;
		_direction = 1f;
		_isWaitingForStrikeEnd = true;
	}

	#endregion

	#region engine fields

	[SerializeField] private float attenuation;
	[SerializeField] private float collisionAttenuation;
	[SerializeField] private float groundZMin;
	[SerializeField] private float groundZMax;
	[SerializeField] private float holeZMin;
	[SerializeField] private float holeZMax;
	[SerializeField] private float holeFallMinVelocity;

	#endregion

	#region engine events

	private void Update()
	{
		if (ShouldUpdatePositionAndVelocity)
			UpdatePositionAndVelocity();

		if (_isWaitingForStrikeEnd && IsStill)
		{
			_isWaitingForStrikeEnd = false;
			ProcessFailStrike();
		}
	}

	#endregion
	
	#region velecoty and position

	private float _velocity;
	private float _direction;

	private bool ShouldUpdatePositionAndVelocity => _velocity > 0f;

	private void UpdatePositionAndVelocity()
	{
		transform.Translate(new Vector3(0, 0, _direction * _velocity));
		_velocity -= attenuation * Time.deltaTime;

		// Check collision
		if (transform.position.z < groundZMin || transform.position.z > groundZMax)
		{
			_direction *= -1f;
			_velocity *= 1f - collisionAttenuation;
			return;
		}

		// Check fall
		if (transform.position.z > holeZMin && transform.position.z < holeZMax && _velocity < holeFallMinVelocity)
		{
			ProcessSuccessStrike();
			Destroy(gameObject);
		}
	}

	#endregion
	
	#region score

	private bool _isWaitingForStrikeEnd;
	private int _currentScore = -15;

	private void ProcessFailStrike()
	{
		_currentScore += 5;
		Debug.Log($"Score: {_currentScore}");

		if (_currentScore >= 0)
			Debug.Log("You lost...");
	}

	private void ProcessSuccessStrike()
	{
		if (_currentScore < 0)
			Debug.Log("You won!");
	}

	#endregion
}