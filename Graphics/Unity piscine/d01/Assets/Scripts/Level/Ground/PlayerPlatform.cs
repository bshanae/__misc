using UnityEngine;

public class PlayerPlatform : MonoBehaviour
{
	[SerializeField] private Player player;

	private void Awake()
	{
		_renderer = GetComponent<Renderer>();
	}

	private void Update()
	{
		_renderer.enabled = player.HasFocus;
	}

	private Renderer _renderer;
}