using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MovingPlatform : MonoBehaviour
{
	[SerializeField] private Transform start;
	[SerializeField] private Transform end;
	[SerializeField] private float speed;
	[SerializeField] private float await;

	private void Awake()
	{
		_startPosition = start.position;
		_endPosition = end.position;

		_position = 0;
		_direction = 1;
	}

	private void FixedUpdate()
	{
		if (_isWaiting)
			return;

		if (_canInvertDirection)
		{
			if (_position <= 0f)
			{
				InvertDirectionAndWait();
				return;
			}
			else if (_position >= 1f)
			{
				InvertDirectionAndWait();
				return;
			}
		}

		var oldPosition = transform.position;
		
		_position += speed * _direction;
		transform.position = Vector3.Lerp(_startPosition, _endPosition, _position);

		var positionDelta = transform.position - oldPosition;
		foreach (var controlledObject in _controlledObjects)
			controlledObject.transform.Translate(positionDelta);
		
		_canInvertDirection = true;
	}

	private void OnCollisionEnter2D(Collision2D collision)
	{
		if (collision.gameObject.CompareTag("player"))
			_controlledObjects.Add(collision.gameObject);
	}

	private void OnCollisionExit2D(Collision2D collision)
	{
		if (collision.gameObject.CompareTag("player"))
			_controlledObjects.Remove(collision.gameObject);
	}

	private Vector3 _startPosition;
	private Vector3 _endPosition;

	private float _position;
	private float _direction;

	private bool _isWaiting;
	private bool _canInvertDirection;

	private readonly List<GameObject> _controlledObjects = new List<GameObject>();

	private void InvertDirectionAndWait()
	{
		_direction *= -1;
		StartCoroutine(Wait());
	}

	private IEnumerator Wait()
	{
		_isWaiting = true;
		yield return new WaitForSeconds(await);
		_isWaiting = false;
		_canInvertDirection = false;
	}
}