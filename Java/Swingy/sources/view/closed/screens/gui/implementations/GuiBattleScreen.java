package view.closed.screens.gui.implementations;

import model.open.Requests;
import net.miginfocom.swing.MigLayout;
import view.closed.screens.gui.abstractions.GuiScreen;
import view.closed.screens.gui.abstractions.GuiScreenForDialog;
import view.open.ButtonId;

import javax.swing.*;
import java.awt.*;

public class				GuiBattleScreen extends GuiScreenForDialog
{
	private Requests.Battle	request;

	@Override
	protected String		getDialogName()
	{
		return "Battle";
	}

	@Override
	protected JPanel		getContent(Requests.Ui request)
	{
		parseRequest(request);
		return buildMainPanel();
	}

// ----------------------->	UI methods

	private JPanel			buildMainPanel()
	{
		JPanel				panel;

		panel = new JPanel();
		panel.setLayout(new MigLayout("fill"));

		panel.add(buildLog(), "center, center, width 550!, height 260!, wrap");
		panel.add(buildButton(), "center");

		return panel;
	}

	private JComponent		buildLog()
	{
		JTextArea			textArea;
		JScrollPane			scrollPane;

		textArea = new JTextArea();
		textArea.setEditable(false);
		textArea.setText(getLogText());
		textArea.setMargin(new Insets(0,10,0,10));

		scrollPane = new JScrollPane(textArea);
		scrollPane.setBorder(BorderFactory.createLineBorder(Color.GRAY));

		if (!request.isBattleFinished)
		{
			scrollPane.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
			scrollPane.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_NEVER);
		}
		else
		{
			scrollPane.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_AS_NEEDED);
			scrollPane.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED);
		}

		return scrollPane;
	}

	private JComponent		buildButton()
	{
		JButton				button;

		button = new JButton("Proceed");
		button.setEnabled(request.isBattleFinished);
		button.addActionListener(new GuiSignalSender(ButtonId.BATTLE_PROCEED));

		return button;
	}

// ----------------------->	Service methods

	private void			parseRequest(Requests.Ui request)
	{
		this.request = (Requests.Battle)request;
	}

	private String			getLogText()
	{
		StringBuilder		stringBuilder;

		stringBuilder = new StringBuilder();

		for (String line : request.log.lines)
			stringBuilder.append(line).append("\n");

		return stringBuilder.toString();
	}
}
