using UnityEngine;
using Vector3 = System.Numerics.Vector3;

[RequireComponent(typeof(Rigidbody2D))]
[RequireComponent(typeof(BoxCollider2D))]
public class playerScripts_ex01 : Player
{
	[SerializeField] private float moveForce;
	[SerializeField] private float jumpForce;
	[SerializeField] private GameObject target;

	private void Awake()
	{
		_rigidbody = GetComponent<Rigidbody2D>();
		_collider = GetComponent<BoxCollider2D>();
	}

	private void Update()
	{
		if (!HasFocus)
			return;

		ProcessInput();
		CheckTarget();
	}

	private Rigidbody2D _rigidbody;
	private BoxCollider2D _collider;

	private bool IsGrounded
	{
		get
		{
			var bounds = _collider.bounds;

			var minX = bounds.min.x;
			var maxX = bounds.max.x;

			var y = bounds.min.y - 0.01f;

			for (var i = 0; i <= 10; i++)
			{
				var origin = new Vector2(Mathf.Lerp(minX, maxX, i / 10f), y);
				if (CastRayToGroundOrPlayer(origin))
					return true;
			}

			return false;
		}
	}

	private bool CanJump => IsGrounded;

	private bool CastRayToGroundOrPlayer(Vector2 origin)
	{
		var direction = Vector2.down;

		var hit = Physics2D.Raycast(origin, direction);
		if (!hit)
			return false;

		var objectTag = hit.collider.gameObject.tag;
		if (objectTag != "ground" && objectTag != "player")
			return false;

		return hit.distance < 0.1f;
	}

	private void ProcessInput()
	{
		var xChange = Input.GetAxis("Horizontal");
		_rigidbody.velocity = _rigidbody.velocity.SetX(xChange * moveForce);

		if (Input.GetKeyDown(KeyCode.Space) && CanJump)
			_rigidbody.velocity = _rigidbody.velocity.SetY(jumpForce);
	}

	private void CheckTarget()
	{
		if (target == null)
			return;
		
		const float precisionX = 0.1f;
		const float precisionY = 0.1f;
		const float precisionZ = 0.1f;

		var delta = (target.transform.position - transform.position).Abs();
		IsAtTarget = delta.x < precisionX && delta.y < precisionY && delta.z < precisionZ;
	}
}