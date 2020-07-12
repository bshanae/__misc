using System;
using UnityEngine;

[RequireComponent(typeof(Rigidbody2D))]
public class Spaceship : ScreenWrap
{
	#region Constants
	private const float ThrustPower = 100f;
	private const float RotationSpeed = 200f;
	
	private const float nextShotWait = 0.25f;
	private const float ShotPower =  1200f;

	#endregion

	#region Fields

	private GameObject bullet;
	private AudioManager audioManager;
	
	private Timer nextShotTimer;
	private Rigidbody2D rigidBody;

	#endregion

	#region UnityEvents
	
	public void Start()
	{
		bullet = Resources.Load("Prefabs/Bullet") as GameObject;
		audioManager = GameObject.Find("AudioManager").GetComponent<AudioManager>(); 
		
		rigidBody = GetComponent<Rigidbody2D>();

		nextShotTimer = gameObject.AddComponent<Timer>();
		nextShotTimer.Duration = nextShotWait;
		nextShotTimer.Run();
	}

	new public void Update()
	{
		float rotateInput = Input.GetAxis("Rotate");
		float thrustInput = Input.GetAxis("Thrust");

		if (rotateInput != 0)
			Rotate(rotateInput);

		if (thrustInput != 0)
			Thrust(thrustInput);

		base.Update();

		if (Input.GetKeyDown(KeyCode.LeftControl) || Input.GetKeyDown(KeyCode.LeftShift))
			TryShootBullet();
	}
	
	private void OnCollisionEnter2D(Collision2D collision)
	{
		audioManager.Play(AudioClipName.Death);
		Destroy(gameObject);
	}
	
	#endregion

	#region Methods

	private void Thrust(float value)
	{
		rigidBody.AddForce(value * transform.up * ThrustPower);
	}

	private void Rotate(float value)
	{
		transform.Rotate(Vector3.forward, value * Time.deltaTime * RotationSpeed);
	}

	private void TryShootBullet()
	{
		if (nextShotTimer.Finished)
		{
			nextShotTimer.Run();
			ShootBullet();
		}
	}

	private void ShootBullet()
	{
		Transform myTransform = transform; 
		GameObject newObject = Instantiate(bullet);

		newObject.transform.position = myTransform.position;
		newObject.transform.rotation = myTransform.rotation;

		newObject.GetComponent<Rigidbody2D>().AddForce(transform.up * ShotPower);
		
		audioManager.Play(AudioClipName.Laser);
	}
	
	#endregion
}
