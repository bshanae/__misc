using System;
using System.Collections;
using UnityEngine;

[RequireComponent(typeof(Collider))]
[RequireComponent(typeof(Rigidbody))]
[RequireComponent(typeof(AudioSource))]
public class Player : MonoBehaviour
{
	#region SerializedFields

	[SerializeField] private GameObject deathParticles;
	[SerializeField] private HealthManager health;
	
	[SerializeField] AudioClip audioDeath;
	[SerializeField] AudioClip audioDefeat;
	[SerializeField] AudioClip audioVictory;
	
	[SerializeField] private float moveSpeed;
	[SerializeField] private float maxSpeed;
	[SerializeField] private float spawnWait;
	
	#endregion
	
	#region Fields
	
	private Collider collider;
	private Rigidbody rigidBody;
	private Renderer renderer;
	private AudioSource audio;
	
	private Vector3 spawnPoint;

	private bool isMovementActive = false;
	private bool isDead = false;
	private float spawnWaitCounter = 0f;
	private bool shouldRespawn = false;
	
	#endregion
	
	#region UnityEvents

	void Awake()
	{
		health = health.GetComponent<HealthManager>();

		spawnPoint = transform.position;
		
		collider = GetComponent<Collider>();
		rigidBody = GetComponent<Rigidbody>();
		renderer = GetComponent<Renderer>();
		audio = GetComponent<AudioSource>();
	}
	
	void Update()
	{
		if (isMovementActive)
			Move();
	}
	
	void FixedUpdate()
	{
		if (!isDead && transform.position.y < -3)
			Die();
		if (shouldRespawn)
			UpdateRespawn();
	}
	
	public void OnCollisionEnter(Collision collision)
	{
		string tag = collision.transform.tag;

		if (tag == "Enemy")
			Die();
		else if (tag == "Floor")
			isMovementActive = true;
	}

	public void OnTriggerEnter(Collider collider)
	{
		if (collider.tag == "Enemy")
			Die();
		else if (collider.tag == "Goal")
			Win();
	}

	#endregion

	#region Methods

	private void Move()
	{
		Vector3 input = new Vector3(Input.GetAxisRaw ("Horizontal"), 0, Input.GetAxisRaw ("Vertical"));

		if (rigidBody.velocity.magnitude < maxSpeed)
			rigidBody.AddForce(input * moveSpeed);
	}

	private void Win()
	{
		collider.enabled = false;
		rigidBody.Sleep();
		isMovementActive = false;
		StartCoroutine(WinCoroutine());
	}

	private IEnumerator WinCoroutine()
	{
		PlayAudio(audioVictory);
		yield return new WaitWhile(() => audio.isPlaying);
		GameManager.NextLevel();
	}

	private void Die()
	{
		StartCoroutine(DieCoroutine());
	}

	private IEnumerator DieCoroutine()
	{
		Hide();
		health.Decrease();
		if (health.Value > 0)
			PlayAudio(audioDeath);
		else
		{
			PlayAudio(audioDefeat);
			yield return new WaitWhile(() => audio.isPlaying);
		}
		StartRespawn();
		GameManager.SaveGame();
		if (health.Value == 0)
			GameManager.FirstLevel();
	}

	private void Hide()
	{
		isDead = true;
		
		Vector3 newPosition;

		newPosition = transform.position;
		newPosition.y += collider.bounds.size.y / 2;
		Instantiate(deathParticles).transform.position = newPosition;
		
		DisableModules();
	}

	private void StartRespawn()
	{
		shouldRespawn = true;
		spawnWaitCounter = spawnWait;
	}
	

	private void UpdateRespawn()
	{
		spawnWaitCounter -= Time.deltaTime;
		if (spawnWaitCounter <= 0f)
			Respawn();
	}

	private void Respawn()
	{
		isDead = false;
		
		transform.position = spawnPoint;
		isMovementActive = false;
		shouldRespawn = false;
		
		EnableModules();
	}

	private void EnableModules()
	{
		collider.enabled = true;
		renderer.enabled = true;
		rigidBody.WakeUp();
		rigidBody.velocity = new Vector3();
	}
	
	private void DisableModules()
	{
		collider.enabled = false;
		renderer.enabled = false;
		rigidBody.Sleep();
	}
	
	private void PlayAudio(AudioClip clip)
	{
		audio.clip = clip;
		audio.Play();
	}

	#endregion
}
