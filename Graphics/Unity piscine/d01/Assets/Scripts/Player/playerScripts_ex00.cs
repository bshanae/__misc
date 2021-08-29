using UnityEngine;

[RequireComponent(typeof(Rigidbody2D))]
public class playerScripts_ex00 : Player
{
	[SerializeField] private float moveForce;
	[SerializeField] private float jumpForce;

	private void Awake()
	{
		_rigidbody = GetComponent<Rigidbody2D>();
	}

	private void Update()
	{
		if (!HasFocus)
			return;

		if (Input.GetKey(KeyCode.LeftArrow))
			_rigidbody.velocity = _rigidbody.velocity.SetX(-moveForce);
		if (Input.GetKey(KeyCode.RightArrow))
			_rigidbody.velocity = _rigidbody.velocity.SetX(moveForce);

		if (Input.GetKeyDown(KeyCode.Space))
			_rigidbody.velocity = _rigidbody.velocity.SetY(jumpForce);
	}

	private Rigidbody2D _rigidbody;
}