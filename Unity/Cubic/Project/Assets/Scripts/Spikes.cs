using System.Collections;
using UnityEngine;

[RequireComponent(typeof(Animation))]
public class Spikes : MonoBehaviour
{
	[SerializeField] private float delay;

	private Animation animation;
	
    void Start()
	{
		animation = GetComponent<Animation>();
		StartCoroutine(Execute());
	}

    IEnumerator Execute()
	{
		while (true)
		{
			yield return new WaitForSeconds(delay);
			animation.Play();
		}
	}
}
