package controller.open;

import application.utils.Debug;
import application.utils.SingletonMap;
import application.utils.uniqueNotifier.UniqueListener;
import application.utils.uniqueNotifier.UniqueNotifier;
import controller.closed.SignalTranslator;
import view.open.Signals;

public class					Controller
									extends UniqueNotifier<Commands.Abstract>
									implements UniqueListener<Signals.Abstract>
{
	public static Controller	getInstance()
	{
		return SingletonMap.getInstanceOf(Controller.class);
	}

	@Override
	public void					listen(Signals.Abstract signal)
	{
		Commands.Abstract		command = SignalTranslator.translate(signal);

		Debug.log("Controller/Controller : Received signal of type " + signal.getClass());
		Debug.log("Controller/Controller : Sending command of type " + command.getClass());

		notifyListener(command);
	}
}
