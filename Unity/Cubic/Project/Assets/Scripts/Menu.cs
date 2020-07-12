using UnityEngine;
using UnityEngine.UI;

[RequireComponent(typeof(AudioSource))]
public class Menu : MonoBehaviour
{
	[SerializeField] private Canvas canvasA;
	[SerializeField] private Canvas canvasB;
	[SerializeField] private AudioClip audioClickA;
	[SerializeField] private AudioClip audioClickB;
	
	private AudioSource audio;
	
	public void Awake()
	{
		audio = GetComponent<AudioSource>();
		
		if (GameManager.DoesSaveExits)
			canvasB.enabled = false;
		else
			canvasA.enabled = false;
	}
	
	public void NewGame()
	{
		Play(audioClickA);
		GameManager.FirstLevel();
	}

	public void Continue()
	{
		Play(audioClickA);
		GameManager.LoadGame();
	}

	public void Quit()
	{
		Play(audioClickB);
		Application.Quit();
	}

	private void Play(AudioClip clip)
	{
		audio.clip = clip;
		audio.Play();
	}
}
