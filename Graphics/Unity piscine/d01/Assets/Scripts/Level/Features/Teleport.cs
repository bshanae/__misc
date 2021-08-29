using System;
using System.Collections.Generic;
using UnityEngine;

public class Teleport : MonoBehaviour
{
	[SerializeField] private Teleport link;

	private void OnTriggerEnter2D(Collider2D otherCollider)
	{
		var player = otherCollider.gameObject;
		if (player.CompareTag("player"))
		{
			if (!_prohibitedPlayers.Contains(player))
				link.Receive(player);
		}
	}

	private void OnTriggerExit2D(Collider2D otherCollider)
	{
		var player = otherCollider.gameObject;
		if (player.CompareTag("player"))
			_prohibitedPlayers.Remove(player);
	}

	private readonly HashSet<GameObject> _prohibitedPlayers = new HashSet<GameObject>();

	private void Receive(GameObject player)
	{
		player.transform.position = transform.position;
		_prohibitedPlayers.Add(player);
	}
}