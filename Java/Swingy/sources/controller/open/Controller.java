package controller.open;

import application.common.SingletonMap;
import application.common.uniqueNotifier.UniqueListener;
import application.common.uniqueNotifier.UniqueNotifier;
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
		notifyListener(SignalTranslator.translate(signal));
	}
}
