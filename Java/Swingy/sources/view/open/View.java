package view.open;

import application.common.SingletonMap;
import application.common.uniqueNotifier.UniqueListener;
import application.common.uniqueNotifier.UniqueNotifier;
import model.open.Requests;
import view.closed.builders.ScreenBuilder;
import view.closed.mode.Mode;
import view.closed.mode.modeController.ModeController;

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
		if (request instanceof Requests.System)
			reactOnSystemRequest((Requests.System)request);
		else if (request instanceof Requests.Ui)
			reactOnUiRequest((Requests.Ui)request);
	}

	public void 			sendSignal(Signals.Abstract signal)
	{
		notifyListener(signal);
	}

	private void			reactOnSystemRequest(Requests.System request)
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
		try
		{
			ScreenBuilder.build(request).buildUi(request);
			ModeController.getCurrentController().updateUi();
			ModeController.getCurrentController().requestInput();
		}
		catch (NullPointerException exception)
		{
			// TODO Error
		}
	}
}
