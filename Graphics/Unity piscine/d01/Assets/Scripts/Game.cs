using System.Linq;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Game: MonoBehaviour
{
	[SerializeField] private string nextLevel;

	private void Awake()
	{
		_players = FindObjectsOfType<Player>();
	}

	private void Update()
	{
		if (Input.GetKeyDown(KeyCode.R) || Input.GetKeyDown(KeyCode.Backspace))
			SceneManager.LoadScene(SceneManager.GetActiveScene().name);

		if (_players.All(player => player.IsAtTarget))
		{
			Debug.Log("Level completed!");
			if (!string.IsNullOrEmpty(nextLevel))
				SceneManager.LoadScene(nextLevel);
		}
	}

	private Player[] _players;
}