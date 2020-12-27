package view.open;

import application.utils.Debug;
import application.utils.SingletonMap;
import application.utils.uniqueNotifier.UniqueListener;
import application.utils.uniqueNotifier.UniqueNotifier;
import model.open.Requests;
import view.closed.builders.ScreenBuilder;
import view.closed.mode.Mode;
import view.closed.mode.modeController.ModeController;

public class					View
								extends UniqueNotifier<Signals.Abstract>
								implements UniqueListener<Requests.Abstract>
{
	private Requests.Abstract	currentRequest;

	public static View			getInstance()
	{
		return SingletonMap.getInstanceOf(View.class);
	}

	public Requests.Abstract	getCurrentRequest()
	{
		return currentRequest;
	}

	@Override
	public void					listen(Requests.Abstract request)
	{
		Debug.logFormat("[View/View] Received request of type '%s'", request.getClass());
		currentRequest = request;

		if (request instanceof Requests.System)
			reactOnSystemRequest((Requests.System)request);
		else if (request instanceof Requests.Ui)
			reactOnUiRequest((Requests.Ui)request);
	}

	public void 				sendSignal(Signals.Abstract signal)
	{
		Debug.logFormat("[View/View] Sending signal of type '%s'", signal.getClass());
		notifyListener(signal);
	}

	private void				reactOnSystemRequest(Requests.System request)
	{
		if (request instanceof Requests.SwitchToConsole)
			ModeController.switchMode(Mode.CONSOLE);
		else if (request instanceof Requests.SwitchToGui)
			ModeController.switchMode(Mode.GUI);

		notifyListener(new Signals.Null());
	}

	private void				reactOnUiRequest(Requests.Ui request)
	{
		ScreenBuilder.getScreen(request).buildUi(request);

		ModeController.getCurrentController().updateUi();
		ModeController.getCurrentController().requestInput();
	}
}
