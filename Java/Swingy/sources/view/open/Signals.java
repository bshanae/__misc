package view.open;

public abstract class			Signals
{
	public interface			Abstract {}

	public static class			Console implements Abstract
	{
		private final String	input;
		private final Context	context;

		public String			getInput()
		{
			return input;
		}

		public Context			getContext()
		{
			return context;
		}

		public					Console(String input, Context context)
		{
			this.input = input;
			this.context = context;
		}
	}
}
