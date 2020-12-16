package view.closed.screens.gui;

import model.open.Requests;
import view.closed.mode.modeController.GuiModeController;
import view.closed.screens.Screen;

import javax.swing.*;
import java.awt.*;

public abstract class			GuiScreen implements Screen
{
	private static final int	VERTICAL_TAB = 20;
	private static final int	HORIZONTAL_TAB = 30;

	private class				BuildGuiCaller implements Runnable
	{
		Requests.Ui				request;

		public 					BuildGuiCaller(Requests.Ui request)
		{
			this.request = request;
		}

		@Override
		public void				run()
		{
			buildGui(request);
		}
	}

	@Override
	public void					buildUi(Requests.Ui request)
	{
		EventQueue.invokeLater(new BuildGuiCaller(request));
	}

	protected static void		setContent(JPanel panel)
	{
		GuiModeController.getInstance().setContent(panel);
	}

	protected abstract void		buildGui(Requests.Ui request);

	protected Font				buildFont(int style, int size)
	{
		return new Font(GuiModeController.FONT_NAME, style, size);
	}

	protected JPanel			addVerticalTabs(JPanel panel)
	{
		JPanel					resultPanel;

		resultPanel = new JPanel();

		resultPanel.setLayout(new BoxLayout(resultPanel, BoxLayout.Y_AXIS));

		resultPanel.add(Box.createVerticalStrut(HORIZONTAL_TAB));
		resultPanel.add(panel);
		resultPanel.add(Box.createVerticalStrut(HORIZONTAL_TAB));

		return resultPanel;
	}

	protected JPanel			addHorizontalTabs(JPanel panel)
	{
		JPanel					resultPanel;

		resultPanel = new JPanel();

		resultPanel.setLayout(new BoxLayout(resultPanel, BoxLayout.X_AXIS));

		resultPanel.add(Box.createHorizontalStrut(HORIZONTAL_TAB));
		resultPanel.add(panel);
		resultPanel.add(Box.createHorizontalStrut(HORIZONTAL_TAB));

		return resultPanel;
	}
}
