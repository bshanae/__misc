using UnityEngine;

public class AutoDestroy : MonoBehaviour
{
	[SerializeField] private float lifeTime;

	private float timer;

	void Start()
	{
		timer = lifeTime;
	}

	void Update()
	{
		timer -= Time.deltaTime;
		
		if (timer <= 0f)
			Destroy(gameObject);	
	}
}
