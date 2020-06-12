using System;
using UnityEngine;
using UnityEngine.UI;

public class HUD : MonoBehaviour
{
	private Text score;
	private GameObject spaceship;
	
	private int startTime;

	public void Start()
	{
		score = GameObject.Find("Score").GetComponent<Text>();
		spaceship = GameObject.Find("Spaceship");
		
		startTime = (int)Time.time;
	}

    public void FixedUpdate()
    {
		if (!spaceship)
		{
			enabled = false;
			score.color = Color.red;
		}
		
		int currentTime = (int)Time.time;
		int deltaTime = currentTime - startTime;

		int minutes = deltaTime / 60;
		int seconds = deltaTime % 60;

		score.text = minutes.ToString("00") + " : " + seconds.ToString("00");
	}
}
