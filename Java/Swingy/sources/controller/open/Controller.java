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

		Debug.logFormat("[Controller/Controller] Received signal of type '%s'", signal.getClass());
		Debug.logFormat("[Controller/Controller] Sending command of type '%s'", command.getClass());

		notifyListener(command);
	}
}
