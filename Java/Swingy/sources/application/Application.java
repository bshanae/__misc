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

//class BoxLayoutButtons extends JFrame {
//
//	public BoxLayoutButtons() {
//
//		initUI();
//	}
//
//	private void initUI() {
//
//		JPanel basePanel = new JPanel();
//		basePanel.setLayout(new BoxLayout(basePanel, BoxLayout.Y_AXIS));
//		add(basePanel);
//
//		basePanel.add(Box.createVerticalGlue());
//
//		JPanel bottomPanel = new JPanel();
//		bottomPanel.setAlignmentX(1f);
//		bottomPanel.setLayout(new BoxLayout(bottomPanel, BoxLayout.X_AXIS));
//
//		JButton okBtn = new JButton("OK");
//		JButton closeBtn = new JButton("Close");
//
//		bottomPanel.add(okBtn);
//		bottomPanel.add(Box.createRigidArea(new Dimension(5, 0)));
//		bottomPanel.add(closeBtn);
//		bottomPanel.add(Box.createRigidArea(new Dimension(15, 0)));
//
//		basePanel.add(bottomPanel);
//		basePanel.add(Box.createRigidArea(new Dimension(0, 15)));
//
//		setTitle("Two Buttons");
//		setSize(300, 150);
//		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//		setLocationRelativeTo(null);
//	}
//
//	public static void main(String[] args) {
//
//
//	}
//}