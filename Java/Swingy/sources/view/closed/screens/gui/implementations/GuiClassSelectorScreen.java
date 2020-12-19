package view.closed.screens.gui.implementations;

import model.open.Requests;
import net.miginfocom.swing.MigLayout;
import view.closed.screens.gui.GuiScreen;

import javax.swing.*;
import javax.swing.border.LineBorder;
import java.awt.*;

public class					GuiClassSelectorScreen extends GuiScreen
{
	private static final int	GAP_FROM_TOP_TO_TITLE = 60;
	private static final int	GAP_FROM_TITLE_TO_CONTENT = 75;

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

		layoutConfig = "fillx, wrap 1, gapy 100";
		columnConfig = "[center]";
		rowConfig = String.format
		(
			"%d[]%d[][][][]",
			GAP_FROM_TOP_TO_TITLE,
			GAP_FROM_TITLE_TO_CONTENT
		);

		panel = new JPanel();
		panel.setLayout(new MigLayout(layoutConfig, columnConfig, rowConfig));

		title = new JLabel("Select hero class");
		title.setFont(buildFont(Font.BOLD, 25));

		panel.add(title);
		panel.add(buildHeroClass(), "width 350px!");
		panel.add(buildHeroClass(), "width 350px!");
		panel.add(buildHeroClass(), "width 350px!");
		panel.add(buildHeroClass(), "width 350px!");

		return panel;
	}

	private JComponent			buildHeroClass()
	{
		JPanel					panel;

		panel = new JPanel();
		panel.setLayout(new MigLayout("fill, insets 5 10 2 10"));
		panel.setBorder(LineBorder.createGrayLineBorder());

		panel.add(new JLabel("test"), "wrap");
		panel.add(new JButton("Select"), "al right");

		return panel;
	}
}
