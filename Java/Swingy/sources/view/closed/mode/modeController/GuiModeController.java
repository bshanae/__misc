package view.closed.mode.modeController;

import application.common.SingletonMap;

import javax.swing.*;
import java.awt.*;

public class							GuiModeController extends ModeController
{
	private static final String			WINDOW_TITLE = "Swingy";
	public static final int				WINDOW_WIDTH = 1000;
	public static final int				WINDOW_HEIGHT = 600;

	public static final String			FONT_NAME = "Helvetica Neue";

	private JFrame						frame;
	private JPanel						panel;

	public static GuiModeController		getInstance()
	{
		return SingletonMap.getInstanceOf(GuiModeController.class);
	}

	public								GuiModeController()
	{
		EventQueue.invokeLater(new ConstructorImplementation());
	}

// -----------------------------------> Overrides

	@Override
	public void							show()
	{
		EventQueue.invokeLater(new ShowImplementation());
	}

	@Override
	public void							clean() {}

	@Override
	protected void						enable()
	{
		EventQueue.invokeLater(new EnableImplementation());
	}

	@Override
	protected void						disable()
	{
		EventQueue.invokeLater(new DisableImplementation());
	}

// -----------------------------------> Own methods

	public void 						setContent(JPanel panel)
	{
		this.panel = panel;
	}

// -----------------------------------> GUI queue

	private class						ConstructorImplementation implements Runnable
	{
		@Override
		public void						run()
		{
			frame = new JFrame();

			frame.setTitle(WINDOW_TITLE);
			frame.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
			frame.setResizable(false);

			frame.setLayout(null);

			frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			frame.setLocationRelativeTo(null);
		}
	}

	private class						ShowImplementation implements Runnable
	{
		@Override
		public void						run()
		{
			frame.setContentPane(panel);
			frame.repaint();
		}
	}

	private class						EnableImplementation implements Runnable
	{
		@Override
		public void						run()
		{
			frame.setVisible(true);
		}
	}

	private class						DisableImplementation implements Runnable
	{
		@Override
		public void						run()
		{
			frame.setVisible(false);
		}
	}
}
