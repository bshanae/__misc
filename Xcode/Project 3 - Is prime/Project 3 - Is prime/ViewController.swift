//
//  ViewController.swift
//  Project 3 - Is prime
//
//  Created by Vladimir Belchenko on 05.04.2020.
//  Copyright © 2020 Vladimir Belchenko. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

	@IBOutlet weak var value : UITextField!
	
	@IBOutlet weak var result: UILabel!
	
	func IsPrime(value : Int) -> Bool?
	{
		if value < 1
		{
			return nil
		}
		
		if value < 3
		{
			return true
		}
		
		for i in 2...value - 1
		{
			if value % i == 0
			{
				return false
			}
		}
		return true
	}
	
	@IBAction func ValueChecked(_ sender: Any)
	{
		var isError = true
		
		result.text = ""
		result.textColor = UIColor.black
		
		if let valueString = value.text
		{
			if let valueInt = Int(valueString)
			{
				let isPrime = IsPrime(value : valueInt)
				isError = isPrime == nil
				if isPrime == true
				{
					result.text = "It's prime!"
				}
				else if isPrime == false
				{
					result.text = "It's not prime..."
				}
				
			}
		}
		if isError
		{
			result.text = "Error"
			result.textColor = UIColor.red
		}
		
	}
	
	override func viewDidLoad() {
		super.viewDidLoad()
		// Do any additional setup after loading the view.
	}


}

