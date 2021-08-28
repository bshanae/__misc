using UnityEngine;

[RequireComponent(typeof(Transform))]
public class SimpleCollider: MonoBehaviour
{
	#region interface

	public Vector2 Min { get; private set; }
	public Vector2 Max { get; private set; }

	public bool DoesCollideWith(SimpleCollider other)
	{
		return other.Min.IsBetweenOrEquals(Min, Max) ||
		       other.Max.IsBetweenOrEquals(Min, Max) ||
		       Min.IsBetweenOrEquals(other.Min, other.Max) ||
		       Max.IsBetweenOrEquals(other.Min, other.Max);
	}
	
	#endregion
	
	#region engine fields

	[SerializeField] private Vector2 size;

	#endregion

	#region engine events

	private void Awake()
	{
		_transform = GetComponent<Transform>();
	}

	private void Update()
	{
		UpdateMinAndMax();
	}

	#endregion

	#region main

	private Transform _transform;

	private Vector2 Scale => _transform.localScale.ToVector2();
	private Vector2 OffsetForMin => -size / 2 * Scale;
	private Vector2 OffsetForMax => size / 2 * Scale;

	private void UpdateMinAndMax()
	{
		var position = _transform.position.ToVector2();

		Min = position + OffsetForMin;
		Max = position + OffsetForMax;
	}
	
	#endregion
}