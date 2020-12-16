package view.closed.screens.gui.implementations;

import application.common.Point;
import model.open.Requests;
import net.miginfocom.swing.MigLayout;
import view.closed.screens.gui.GuiScreen;

import javax.swing.*;
import javax.swing.border.LineBorder;

public class					GuiMapScreen extends GuiScreen
{
	private static final Point	CANVAS_SIZE = new Point(20, 20);

	@Override
	protected void				buildGui(Requests.Ui request)
	{
		String					layoutConfig;
		JPanel					panel;

		layoutConfig = String.format("fill, wrap %d", CANVAS_SIZE.x);

		panel = new JPanel();
		panel.setLayout(new MigLayout(layoutConfig));
		panel.setBorder(LineBorder.createGrayLineBorder());

		for (int column = 0; column < CANVAS_SIZE.x; column++)
			for (int row = 0; row < CANVAS_SIZE.y; row++)
				panel.add(buildCell(), "al center");

		panel = addVerticalTabs(panel);
		panel = addHorizontalTabs(panel);

		setContent(panel);
	}

	private JComponent			buildCell()
	{
		JLabel					label;

		label = new JLabel("A");

		return label;
	}
}
