package view.closed.screens.gui.implementations;

import model.open.Requests;
import net.miginfocom.swing.MigLayout;
import view.closed.screens.gui.GuiScreen;

import javax.swing.*;
import javax.swing.border.LineBorder;
import java.awt.*;

public class					GuiClassSelectorScreen extends GuiScreen
{
	private static final int	GAP_FROM_TOP_TO_TITLE = 90;
	private static final int	GAP_FROM_TITLE_TO_CONTENT = 90;
	private static final int	GAP_BETWEEN_CLASSES = 10;
	private static final int	GAP_FROM_CONTENT_TO_BOTTOM = 100;

	@Override
	public JPanel				getContent(Requests.Ui request)
	{
		return buildMainPanel();
	}

	private JPanel				buildMainPanel()
	{
		String					layoutConfig;
		String					columnConfig;
		String					rowConfig;

		JPanel					panel;
		JLabel					title;

		layoutConfig = "fill, wrap 1";
		columnConfig = "[center]";
		rowConfig = String.format
		(
			"%d[]%d[]%d[]%d[]%d[]%d",
			GAP_FROM_TOP_TO_TITLE,
			GAP_FROM_TITLE_TO_CONTENT,
			GAP_BETWEEN_CLASSES,
			GAP_BETWEEN_CLASSES,
			GAP_BETWEEN_CLASSES,
			GAP_FROM_CONTENT_TO_BOTTOM
		);

		panel = new JPanel();
		panel.setLayout(new MigLayout(layoutConfig, columnConfig, rowConfig));

		title = new JLabel("Select hero class");
		title.setFont(buildFont(Font.BOLD, 40));

		panel.add(title);
		panel.add(buildHeroClass(), "grow, width ::450, height ::60");
		panel.add(buildHeroClass(), "grow, width ::450, height ::60");
		panel.add(buildHeroClass(), "grow, width ::450, height ::60");
		panel.add(buildHeroClass(), "grow, width ::450, height ::60");

		return panel;
	}

	private JComponent			buildHeroClass()
	{
		JPanel					panel;

		panel = new JPanel();
		panel.setLayout(new MigLayout("fill, insets 5 10 2 10"));
		panel.setBorder(LineBorder.createGrayLineBorder());

		panel.add(new JLabel("test"), "push");
		panel.add(new JButton("Select"));

		return panel;
	}
}
