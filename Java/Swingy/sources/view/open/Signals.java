package view.open;

public abstract class					Signals
{
	public interface					Abstract {}

// -----------------------------------> Console

	public static class					Console implements Abstract
	{
		public final Context			context;
		public final String				input;

		public							Console(String input)
		{
			this.context = Context.parseContext(View.getInstance().getCurrentRequest());
			this.input = input;
		}
	}

// -----------------------------------> GUI

	public static class					Gui implements Abstract
	{
		public final ButtonId			buttonId;
		public final Object				linkedData;

		public 							Gui(ButtonId buttonId)
		{
			this.buttonId = buttonId;
			this.linkedData = null;
		}

		public 							Gui(ButtonId buttonId, Object linkedData)
		{
			this.buttonId = buttonId;
			this.linkedData = linkedData;
		}
	}
}
