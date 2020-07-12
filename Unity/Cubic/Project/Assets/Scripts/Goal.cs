using UnityEngine;

public class Goal : MonoBehaviour
{
	public void OnTriggerEnter(Collider collider)
	{
		if (collider.transform.tag == "Player")
			Destroy(gameObject);
	}
}
