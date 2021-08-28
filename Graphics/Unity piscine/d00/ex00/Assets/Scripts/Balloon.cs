using UnityEngine;
using UnityEngine.UI;

public class Balloon : MonoBehaviour
{
	#region serialized fields
	
	[SerializeField] private Image image;
	[SerializeField] private Sprite normalSprite;
	[SerializeField] private Sprite[] popSprites;
	[SerializeField] private float initialSize;
	[SerializeField] private float maxSize;
	[SerializeField] private float inflatingSpeed;
	[SerializeField] private float deflatingSpeed;
	[SerializeField] private float deflatingTimeout;
	[SerializeField] private float breathReserve;
	[SerializeField] private float breathRegenerationTimeout;
	[SerializeField] private float breathRegenerationSpeed;

	#endregion

	#region engine events

	private void Awake()
	{
		_size = initialSize;
		_breathReserve = breathReserve;
		image.sprite = normalSprite;
	}

	private void Start()
	{
		_gameStartTime = Time.time;
		UpdateSpriteSize();
	}

	private void Update()
	{
		if (_isPopping || _size >= maxSize)
		{
			// Pop
			ShowNextPopFrame();
		}
		else
		{
			// Inflate or deflate
			if (Input.GetKeyDown(KeyCode.Space) && CanInflate)
			{
				ResetDeflating();
				ProcessInflating();
			}
			else
			{
				RegenerateBreath();
				ProcessDeflating();
			}
		}
	}

	#endregion
	
	#region common

	private float _gameStartTime;
	private float _size;

	private void UpdateSpriteSize()
	{
		image.transform.localScale = Vector3.one * _size;
	}

	private void FinishGame()
	{
		Destroy(this.gameObject);

		var gameDuration = Mathf.RoundToInt(Time.time - _gameStartTime);
		Debug.Log($"Balloon life time: {gameDuration}s");
	}

	#endregion

	#region inflating

	private float _breathReserve;
	private float? _breathRegenerationTimeout;

	private bool CanInflate => _breathReserve > 0f;

	private void ProcessInflating()
	{
		_size += inflatingSpeed;

		_breathReserve -= inflatingSpeed;
		_breathRegenerationTimeout = null;

		UpdateSpriteSize();
	}

	private void RegenerateBreath()
	{
		if (_breathRegenerationTimeout == null)
		{
			_breathRegenerationTimeout = breathRegenerationTimeout;
			return;
		}

		if (_breathRegenerationTimeout >= 0f)
		{
			_breathRegenerationTimeout -= Time.deltaTime;
			return;
		}
		
		_breathReserve += breathRegenerationSpeed;
		if (_breathReserve > breathReserve)
			_breathReserve = breathReserve;
	}
	
	#endregion

	#region deflating

	private bool _isDeflating;
	private float? _deflatingTimeout;

	private void ResetDeflating()
	{
		_isDeflating = false;
		_deflatingTimeout = null;
	}

	private void ProcessDeflating()
	{
		if (_size <= initialSize)
			return;

		if (_isDeflating)
		{
			_size -= deflatingSpeed;
			if (_size < initialSize)
				_size = initialSize;

			UpdateSpriteSize();
			return;
		}
		
		if (_deflatingTimeout == null)
		{
			_deflatingTimeout = deflatingTimeout;
		}
		else
		{
			_deflatingTimeout -= Time.deltaTime;
			if (_deflatingTimeout < 0f)
			{
				_isDeflating = true;
				_deflatingTimeout = null;
			}
		}
	}

	#endregion

	#region popping

	private bool _isPopping;
	private int? _currentPopFrame;

	private void ShowNextPopFrame()
	{
		// Start
		if (_currentPopFrame == null)
		{
			_isPopping = true;
			_currentPopFrame = 0;
		}
		
		// Update index
		_currentPopFrame++;

		// End
		if (_currentPopFrame == popSprites.Length)
		{
			_isPopping = false;
			FinishGame();
			return;
		}
		
		// Update sprite
		image.sprite = popSprites[_currentPopFrame.Value];
	}

	#endregion
}