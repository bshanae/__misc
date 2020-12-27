package view.closed.screens.gui.abstractions;

import model.open.Requests;
import view.closed.mode.modeController.GuiModeController;
import view.closed.screens.Screen;
import view.open.ButtonId;
import view.open.Signals;
import view.open.View;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public abstract class				GuiScreenForDialog extends GuiScreen
{
	private class					GuiBuilder implements Runnable
	{
		private final Requests.Ui	request;

		public						GuiBuilder(Requests.Ui request)
		{
			this.request = request;
		}

		@Override
		public void					run()
		{
			GuiModeController.getInstance().setContentInDialog(getContent(request), getDialogName());
		}
	}

	protected abstract String		getDialogName();

	@Override
	public void						buildUi(Requests.Ui request)
	{
		EventQueue.invokeLater(new GuiBuilder(request));
	}

	protected abstract JPanel		getContent(Requests.Ui request);
}
