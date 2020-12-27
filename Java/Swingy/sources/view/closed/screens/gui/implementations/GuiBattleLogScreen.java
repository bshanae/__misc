package view.closed.screens.gui.implementations;

import model.open.Requests;
import view.closed.screens.gui.abstractions.GuiScreenForDialog;

import javax.swing.*;

public class				GuiBattleLogScreen extends GuiScreenForDialog
{
	@Override
	protected String		getDialogName()
	{
		return "Battle";
	}

	@Override
	protected JPanel		getContent(Requests.Ui request)
	{
		return buildMainPanel(request);
	}

	private JPanel			buildMainPanel(Requests.Ui request)
	{
		JPanel				panel;
		JScrollPane			scrollPane;
		JTextArea			textArea;

		textArea = new JTextArea();
		textArea.setEditable(false);

		scrollPane = new JScrollPane(textArea);
		scrollPane.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED);

		textArea.setText(getLog(request));

		panel = new JPanel();
		panel.add(scrollPane);

		return panel;
	}

	private String			getLog(Requests.Ui request)
	{
		Requests.BattleLog	log;
		StringBuilder		stringBuilder;

		log = (Requests.BattleLog)request;
		stringBuilder = new StringBuilder();

		for (String line : log.log.lines)
			stringBuilder.append(line).append("\n");

		return stringBuilder.toString();
	}
}
