using UnityEngine;

public class Club : MonoBehaviour
{
	#region engine fields

	[SerializeField] private Ball ball;
	[SerializeField] private float ballOffset;
	[SerializeField] private float swingTime;
	[SerializeField] private float swingLength;
	[SerializeField] private float swingPower;
	[SerializeField] private float strikeTime;

	#endregion

	#region engine events

	private void Update()
	{
		if (ball == null)
			return;

		if (_isWaitingForBallForStop && ball.IsStill)
		{
			transform.position = transform.position.SetZ(ball.transform.position.z + ballOffset);
			_isWaitingForBallForStop = false;
		}

		if (_isShowingStrikeAnimation)
			ProcessStrikeAnimation();
		else if (_didShowStrikeAnimation)
			Strike();
		else
			ProcessSwing();
	}

	#endregion

	#region ball observation

	private bool _isWaitingForBallForStop;

	#endregion

	#region swing

	private bool _isSwinging;
	private float _swingRatio;
	private float _zBeforeSwing;

	private float SwingRatioStep => 1f / swingTime * Time.deltaTime;

	private void ProcessSwing()
	{
		if (!ball.IsStill)
			return;

		if (Input.GetKey(KeyCode.Space))
		{
			if (!_isSwinging)
				StartSwing();
			else
				IncreaseSwing();
		}
		else if (_swingRatio > 0f)
		{
			StartStrikeAnimation();
		}
	}

	private void StartSwing()
	{
		_isSwinging = true;
		_zBeforeSwing = transform.position.z;
	}

	private void IncreaseSwing()
	{
		_swingRatio = Mathf.Clamp(_swingRatio + SwingRatioStep, 0, 1);
		transform.position = transform.position.SetZ(_zBeforeSwing - swingLength * _swingRatio);
	}

	#endregion

	#region strike

	private float _zBeforeStrike;

	private bool _isShowingStrikeAnimation;
	private bool _didShowStrikeAnimation;
	private float _strikeAnimationRatio;

	private void Strike()
	{
		ball.Strike(_swingRatio * swingPower);
		_swingRatio = 0f;
		_didShowStrikeAnimation = false;

		transform.position = transform.position.SetZ(_zBeforeSwing);
		_isWaitingForBallForStop = true;
	}

	private void StartStrikeAnimation()
	{
		_isSwinging = false;
		_zBeforeStrike = transform.position.z;

		_isShowingStrikeAnimation = true;
		_strikeAnimationRatio = 0f;
	}

	private float ZWhileStriking => _zBeforeStrike + (_zBeforeSwing - _zBeforeStrike) * _strikeAnimationRatio;

	private void ProcessStrikeAnimation()
	{
		_strikeAnimationRatio += Mathf.Clamp(1f / strikeTime * Time.deltaTime, 0, 1);
		transform.position = transform.position.SetZ(ZWhileStriking);

		if (_strikeAnimationRatio >= 1f)
		{
			_isShowingStrikeAnimation = false;
			_didShowStrikeAnimation = true;
		}
	}

	#endregion
}