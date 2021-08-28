using UnityEngine;

public class Cube : MonoBehaviour
{
	#region interface

	public float speed;
	public string catchKey;
	public float catchY;
	public float killY;

	#endregion

	#region engine events

	private void Update()
	{
		if (!_isCaught && Input.GetKeyDown(catchKey))
		{
			Catch();
			return;
		}

		if (transform.position.y < killY)
			Kill();

		transform.Translate(new Vector3(0, -speed * Time.deltaTime, 0));
	}

	#endregion

	#region common

	private bool _isCaught;

	private void Catch()
	{
		Debug.Log($"Precision: {Abs(transform.position.y - catchY)}");

		_isCaught = true;
		Destroy(gameObject);
	}

	private void Kill()
	{
		Destroy(gameObject);
	}

	private static float Abs(float value)
	{
		return value < 0 ? -value : value;
	}

	#endregion
}