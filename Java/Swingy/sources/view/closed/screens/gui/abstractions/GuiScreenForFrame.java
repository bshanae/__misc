package view.closed.screens.gui.abstractions;

import model.open.Requests;
import view.closed.mode.modeController.GuiModeController;

import javax.swing.*;
import java.awt.*;

public abstract class				GuiScreenForFrame extends GuiScreen
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
			GuiModeController.getInstance().setContentInFrame(getContent(request));
		}
	}

	@Override
	public void						buildUi(Requests.Ui request)
	{
		EventQueue.invokeLater(new GuiBuilder(request));
	}

	protected abstract JPanel		getContent(Requests.Ui request);
}
