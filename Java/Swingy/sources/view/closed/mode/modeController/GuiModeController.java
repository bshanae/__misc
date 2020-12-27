package view.closed.mode.modeController;

import application.utils.SingletonMap;
import view.closed.utils.gui.GuiWayOfDisplayingScreen;

import javax.swing.*;
import java.awt.*;

public class							GuiModeController extends ModeController
{
// -----------------------------------> Constants

	private static final String			WINDOW_TITLE = "Swingy";
	public static final int				WINDOW_WIDTH = 1000;
	public static final int				WINDOW_HEIGHT = 600;
	public static final int				DIALOG_WIDTH = 650;
	public static final int				DIALOG_HEIGHT = 400;

	public static final String			FONT_NAME = "Helvetica Neue";

// -----------------------------------> Attributes

	private JFrame						frame;
	private JDialog						dialog;

	private GuiWayOfDisplayingScreen	wayOfDisplayingScreen;
	private JPanel						panel;
	private String						dialogName;

// -----------------------------------> Properties

	public static GuiModeController		getInstance()
	{
		return SingletonMap.getInstanceOf(GuiModeController.class);
	}

// -----------------------------------> Constructor

	public								GuiModeController()
	{
		EventQueue.invokeLater(new ConstructorImplementation());
	}

// -----------------------------------> Overrides

	@Override
	public void							updateUi()
	{
		EventQueue.invokeLater(new UpdateUiImplementation());
	}

	@Override
	public void							requestInput() { }

	@Override
	protected void						enableUi()
	{
		EventQueue.invokeLater(new EnableImplementation());
	}

	@Override
	protected void						disableUi()
	{
		EventQueue.invokeLater(new DisableImplementation());
	}

// -----------------------------------> Own methods

	public void 						setContentInFrame(JPanel panel)
	{
		this.wayOfDisplayingScreen = GuiWayOfDisplayingScreen.IN_FRAME;

		this.panel = panel;
	}

	public void 						setContentInDialog(JPanel panel, String dialogName)
	{
		this.wayOfDisplayingScreen = GuiWayOfDisplayingScreen.IN_DIALOG;

		this.panel = panel;
		this.dialogName = dialogName;
	}

// -----------------------------------> GUI queue

	private class						ConstructorImplementation implements Runnable
	{
		@Override
		public void						run()
		{
			buildFrame();
			buildDialog();
		}

		private void					buildFrame()
		{
			frame = new JFrame();

			frame.setTitle(WINDOW_TITLE);
			frame.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
			frame.setResizable(false);

			frame.setLayout(null);

			frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			frame.setLocationRelativeTo(null);
		}

		private void					buildDialog()
		{
			dialog = new JDialog(frame, dialogName, Dialog.ModalityType.DOCUMENT_MODAL);
			dialog.setLocation(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
			dialog.setSize(DIALOG_WIDTH, DIALOG_HEIGHT);
		}
	}

	private class						UpdateUiImplementation implements Runnable
	{
		@Override
		public void						run()
		{
			switch (wayOfDisplayingScreen)
			{
				case IN_FRAME:
					showPanelInFrame();
					break;

				case IN_DIALOG:
					showPanelInDialog();
					break;
			}

			repaint();
		}

		private void					showPanelInFrame()
		{
			frame.setContentPane(panel);
			dialog.setVisible(false);
		}

		private void					showPanelInDialog()
		{
			dialog.setContentPane(panel);
			dialog.setVisible(true);
		}

		private void					repaint()
		{
			frame.revalidate();
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
