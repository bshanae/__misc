using System;
using UnityEngine;

[RequireComponent(typeof(Rigidbody2D))]
public class Bullet : ScreenWrap
{
	private const float lifeDuration = 1.5f;
	
	private Timer lifeTimer;

	public void Start()
	{
		lifeTimer = gameObject.AddComponent<Timer>();
		lifeTimer.Duration = lifeDuration;
		lifeTimer.Run();
	}

	private new void Update()
	{
		base.Update();

		if (lifeTimer.Finished)
			Destroy(gameObject);
	}
	
	private void OnCollisionEnter2D(Collision2D collision)
	{
		string tag = collision.gameObject.tag;
		
		if (tag == "Asteroid1" || tag == "Asteroid2" || tag == "Asteroid3")
			Destroy(gameObject);
	}
}
