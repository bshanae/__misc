package view.closed.screens.gui.implementations;

import model.open.Requests;
import view.closed.screens.gui.GuiScreen;

import javax.swing.*;

public class			GuiBattleLogScreen extends GuiScreen
{
	private static int	i = 0;

	@Override
	protected JPanel	getContent(Requests.Ui request)
	{
		return buildMainPanel();
	}

	private JPanel		buildMainPanel()
	{
		JPanel			panel;
		JScrollPane		scrollPane;
		JTextArea		textArea;

		textArea = new JTextArea();
		textArea.setEditable(false);

		scrollPane = new JScrollPane(textArea);
		scrollPane.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED);

		textArea.setText("arc1\narc2 : " + i++);

		panel = new JPanel();
		panel.add(scrollPane);

		return panel;
	}
}
