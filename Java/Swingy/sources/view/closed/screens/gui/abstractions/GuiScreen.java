package view.closed.screens.gui.abstractions;

import view.closed.mode.modeController.GuiModeController;
import view.closed.screens.Screen;
import view.open.ButtonId;
import view.open.Signals;
import view.open.View;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public abstract class		GuiScreen implements Screen
{
	protected static class	GuiSignalSender implements ActionListener
	{
		Signals.Gui			signal;

		public 				GuiSignalSender(ButtonId buttonId)
		{
			signal = new Signals.Gui(buttonId);
		}

		public 				GuiSignalSender(ButtonId buttonId, Object data)
		{
			signal = new Signals.Gui(buttonId, data);
		}

		@Override
		public void			actionPerformed(ActionEvent event)
		{
			View.getInstance().sendSignal(signal);
		}
	}

	protected static Font	buildFont(int style, int size)
	{
		return new Font(GuiModeController.FONT_NAME, style, size);
	}
}