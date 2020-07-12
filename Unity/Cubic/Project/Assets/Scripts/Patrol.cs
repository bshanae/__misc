using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Patrol : MonoBehaviour
{
	public Transform[] points;
	public float moveSpeed;
	
	private int currentPoint;
	
    public void Start()
	{
		transform.position = points[0].position;
		currentPoint = 0;
	}

   public void Update()
	{
		if (transform.position == points[currentPoint].position)
			currentPoint = currentPoint == points.Length - 1 ? 0 : currentPoint + 1;
		
		transform.position = Vector3.MoveTowards(
			transform.position,
			points[currentPoint].position, 
			moveSpeed * Time.deltaTime);
	}
}
