using UnityEngine;

public class CameraManipulator : MonoBehaviour
{
    private void Awake()
    {
        _players = FindObjectsOfType<Player>();
    }
    private void Start()
    {
        SelectPlayer(_players[0]);
    }
    
    private void Update()
    {
        for (var i = 0; i < _players.Length; i++)
        {
            if (Input.GetKeyDown((i + 1).ToString()))
            {
                SwitchToPlayer(_players[i]);
                return;
            }
        }

        if (_selectedPlayer != null)
            SynchronizePositionWithPlayer(_selectedPlayer);
    }

    private void SwitchToPlayer(Player player)
    {
        SelectPlayer(player);
        SynchronizePositionWithPlayer(player);
    }

    private void SynchronizePositionWithPlayer(Player player)
    {
        var cameraZ = transform.position.z;
        transform.position = player.transform.position.SetZ(cameraZ);
    }

    private Player[] _players;
    private Player _selectedPlayer;

    private void SelectPlayer(Player player)
    {
        if (_selectedPlayer != null)
            _selectedPlayer.HasFocus = false;

        _selectedPlayer = player;
        _selectedPlayer.HasFocus = true;
    }
}
