using UnityEngine;

[RequireComponent(typeof(Collider2D))]
public class ScreenWrap : MonoBehaviour
{
	public void Update()
	{
		Vector2 min = GetComponent<Collider2D>().bounds.min;
		Vector2 max = GetComponent<Collider2D>().bounds.max;
		
		Vector2 position = transform.position;

		if (max.x < ScreenInfo.ScreenLeft)
			position.x = ScreenInfo.ScreenRight;
		else if (min.x > ScreenInfo.ScreenRight)
			position.x = ScreenInfo.ScreenLeft;
		
		if (max.y < ScreenInfo.ScreenBottom)
			position.y = ScreenInfo.ScreenTop;
		else if (min.y > ScreenInfo.ScreenTop)
			position.y = ScreenInfo.ScreenBottom;

		transform.position = position;
	}
}
