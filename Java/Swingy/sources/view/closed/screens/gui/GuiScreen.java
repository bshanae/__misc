package view.closed.screens.gui;

import model.open.Requests;
import view.closed.mode.modeController.GuiModeController;
import view.closed.mode.modeController.ModeController;
import view.closed.screens.Screen;
import view.open.Signals;
import view.open.View;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public abstract class				GuiScreen implements Screen
{
	private class					GuiBuilder implements Runnable
	{
		Requests.Ui					request;

		public 						GuiBuilder(Requests.Ui request)
		{
			this.request = request;
		}

		@Override
		public void					run()
		{
			GuiModeController.getInstance().setContent(getContent(request));
		}
	}

	public class					GuiSignalSender implements ActionListener
	{
		Signals.Gui.Abstract		signal;

		public 						GuiSignalSender(Signals.Gui.Abstract signal)
		{
			this.signal = signal;
		}

		@Override
		public void					actionPerformed(ActionEvent event)
		{
			View.getInstance().sendSignal(signal);
		}
	}

	@Override
	public void						buildUi(Requests.Ui request)
	{
		EventQueue.invokeLater(new GuiBuilder(request));
	}

	protected abstract JPanel		getContent(Requests.Ui request);

	protected static Font			buildFont(int style, int size)
	{
		return new Font(GuiModeController.FONT_NAME, style, size);
	}
}
