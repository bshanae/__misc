using UnityEngine;

[RequireComponent(typeof(Rigidbody2D))]
public class Asteroid : ScreenWrap
{
	private AsteroidSpawner spawner;
	private AudioManager audioManager;
	
	public void Awake()
	{
		spawner = GameObject.Find("AsteroidSpawner").GetComponent<AsteroidSpawner>();
		audioManager = GameObject.Find("AudioManager").GetComponent<AudioManager>(); 
	}
	
	private void OnCollisionEnter2D(Collision2D collision)
	{
		if (CompareTag("Asteroid1"))
			audioManager.Play(AudioClipName.Explosion1);
		else if (CompareTag("Asteroid2"))
			audioManager.Play(AudioClipName.Explosion2);
		else if (CompareTag("Asteroid3"))
			audioManager.Play(AudioClipName.Explosion3);
		
		if (collision.gameObject.CompareTag("Bullet"))
			spawner.ReduceAsteroid(gameObject);
	}
}
