package application;

import controller.open.Controller;
import model.open.Model;
import view.open.View;

public class			Application
{
	public static void	main(String[] args)
	{
		Model			model;
		View			view;
		Controller		controller;

		model = Model.getInstance();
		view = View.getInstance();
		controller = Controller.getInstance();

		model.setListener(view);
		view.setListener(controller);
		controller.setListener(model);

		model.run();

		while (!model.isTerminated())
			model.update();
	}
}