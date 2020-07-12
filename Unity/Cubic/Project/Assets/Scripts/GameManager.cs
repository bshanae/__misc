using UnityEngine;
using UnityEngine.SceneManagement;

[RequireComponent(typeof(AudioSource))]
public class GameManager : MonoBehaviour
{
	private static AudioSource audio;

	private static Menu menu;
	private static HealthManager health;

	private const int levelOffset = 1;
	private static int currentLevel;

	private static GameObject previousManager;
	
	#region UnityEvents
	
	public void Awake()
	{
		DontDestroyOnLoad(gameObject); 
		
		if (previousManager == null)
			previousManager = gameObject;
		else
		{
			Destroy(previousManager);
			previousManager = gameObject;
		} 
		
		audio = GetComponent<AudioSource>();
		
		if (SceneManager.GetActiveScene().name == "Menu")
			menu = GameObject.Find("Menu").GetComponent<Menu>();
		else
			health = GameObject.Find("HealthManager").GetComponent<HealthManager>();
	}

	public void Update()
	{
		if (Input.GetKeyDown("escape"))
		{
			if (SceneManager.GetActiveScene().name == "Menu")
				menu.Quit();
			else
			{
				audio.Play();
				SaveGame();
				Menu();
			}
		}
	}
	
	#endregion
	
	#region Scenes

	public static void Menu()
	{
		SceneManager.LoadScene(0);
	}

	public static void FirstLevel()
	{
		currentLevel = 0;
		HealthManager.RequestValue = 3;
		SceneManager.LoadScene(levelOffset + currentLevel);
	}
	
	public static void NextLevel()
	{
		currentLevel++;
		if (levelOffset + currentLevel == SceneManager.sceneCountInBuildSettings)
		{
			PlayerPrefs.DeleteAll();
			Menu();
		}
		else
		{
			HealthManager.RequestValue = 3;
			SceneManager.LoadScene(levelOffset + currentLevel);
		}
	}

	#endregion
	
	#region Saving

	public static void SaveGame()
	{
		PlayerPrefs.SetInt("Level", currentLevel);
		PlayerPrefs.SetInt("Health", health.Value);
	}

	public static void LoadGame()
	{
		currentLevel = PlayerPrefs.GetInt("Level");
		HealthManager.RequestValue = PlayerPrefs.GetInt("Health");
		
		SceneManager.LoadScene(levelOffset + currentLevel);
	}

	public static bool DoesSaveExits => PlayerPrefs.HasKey("Level") && PlayerPrefs.HasKey("Health");
	
	#endregion
}
