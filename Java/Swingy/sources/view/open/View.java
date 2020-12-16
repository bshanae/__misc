package view.open;

import application.common.SingletonMap;
import application.common.uniqueNotifier.UniqueListener;
import application.common.uniqueNotifier.UniqueNotifier;
import model.open.Requests;
import view.closed.builders.ScreenBuilder;
import view.closed.builders.SignalBuilder;
import view.closed.mode.Mode;
import view.closed.mode.modeController.ModeController;
import view.closed.screens.Screen;

public class				View
							extends UniqueNotifier<Signals.Abstract>
							implements UniqueListener<Requests.Abstract>
{
	public static View		getInstance()
	{
		return SingletonMap.getInstanceOf(View.class);
	}

	@Override
	public void				listen(Requests.Abstract request)
	{
		if (request instanceof Requests.NonUi)
			reactOnNonUiRequest((Requests.NonUi)request);
		else if (request instanceof Requests.Ui)
			reactOnUiRequest((Requests.Ui)request);
	}

	private void			reactOnNonUiRequest(Requests.NonUi request)
	{
		if (request instanceof Requests.SwitchToConsole)
			ModeController.switchMode(Mode.CONSOLE);
		else if (request instanceof Requests.SwitchToGui)
			ModeController.switchMode(Mode.GUI);

		notifyListener(null);

		// TODO Error
	}

	private void			reactOnUiRequest(Requests.Ui request)
	{
		Screen				screen;
		Signals.Abstract	signal;

		screen = ScreenBuilder.buildScreenUpon(request);
		assert screen != null;

		screen.buildUi(request);

		ModeController.getCurrentController().clean();
		ModeController.getCurrentController().show();

//		screen.waitForInput();

		try
		{
			signal = SignalBuilder.buildSignalUpon(request, screen);
		}
		catch (SignalBuilder.UnknownRequestException unknownRequest)
		{
			unknownRequest.printStackTrace();
			return ;
		}

		notifyListener(signal);
	}
}
