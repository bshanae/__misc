package view.closed.screens.gui.implementations;

import model.open.Requests;
import net.miginfocom.swing.MigLayout;
import view.closed.screens.console.ConsoleScreen;
import view.closed.screens.gui.GuiScreen;
import view.closed.utils.common.ResourceManager;

import javax.swing.*;
import javax.swing.border.LineBorder;
import java.awt.*;

public class					GuiNameEntryScreen extends GuiScreen
{
	private static final int	GAP_FROM_TOP_TO_TITLE = 60;
	private static final int	GAP_FROM_TITLE_TO_CONTENT = 75;

	@Override
	public void					buildGui(Requests.Ui request)
	{
		setContent(addHorizontalTabs(buildMainPanel()));
	}

	private JPanel				buildMainPanel()
	{
		String					layoutConfig;
		String					columnConfig;
		String					rowConfig;

		JPanel					panel;
		JLabel					title;

		layoutConfig = "fillx";
		columnConfig = "[center]";
		rowConfig = String.format("%d[]%d[]", GAP_FROM_TOP_TO_TITLE, GAP_FROM_TITLE_TO_CONTENT);

		panel = new JPanel();
		panel.setLayout(new MigLayout(layoutConfig, columnConfig, rowConfig));

		title = new JLabel("Enter hero name");
		title.setFont(buildFont(Font.BOLD, 25));

		panel.add(title, "wrap");
		panel.add(buildContent(), "width 400px!, height 200px!");

		return panel;
	}

	private JComponent			buildContent()
	{
		JPanel					panel;

		panel = new JPanel();
		panel.setLayout(new MigLayout("fill, insets 25 15 25 15", "", "[]rel:push[]"));
		panel.setBorder(LineBorder.createGrayLineBorder());

		panel.add(new JTextField(), "growx, height 45px!, wrap");
		panel.add(new JButton("Enter"), "al right");

		return panel;
	}
}
