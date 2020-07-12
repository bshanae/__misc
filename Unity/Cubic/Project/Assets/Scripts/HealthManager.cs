using UnityEngine;
using UnityEngine.UI;

public class HealthManager : MonoBehaviour
{
	[SerializeField] private Canvas canvasA;
	[SerializeField] private Canvas canvasB;
	[SerializeField] private Canvas canvasC;
	
	public static int RequestValue
	{
		private get;
		set;
	}
	
	public int Value
	{
		get;
		private set;
	}
	
	public void Awake()
	{
		Value = RequestValue;
		ShowHealth();
	}

	public void Decrease()
	{
		if (Value > 0)
		{
			Value--;
			ShowHealth();
		}
	}

	private void ShowHealth()
	{
		HideAll();
		
		switch (Value)
		{
			case 1 :
				canvasA.enabled = true;
				break;
			
			case 2 :
				canvasB.enabled = true;
				break;
			
			case 3 :
				canvasC.enabled = true;
				break;
		}
	}
	
	private void HideAll()
	{
		canvasA.enabled = false;
		canvasB.enabled = false;
		canvasC.enabled = false;
	}
}
