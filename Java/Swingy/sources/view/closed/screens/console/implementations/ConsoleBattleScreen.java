package view.closed.screens.console.implementations;

import model.open.Requests;
import view.closed.screens.console.ConsoleScreen;

public class			ConsoleBattleScreen extends ConsoleScreen
{
	@Override
	public boolean		shouldRequestInput()
	{
		return false;
	}

	@Override
	public String		getContent(Requests.Ui request)
	{
		Requests.Battle	battleRequest;
		StringBuilder	stringBuilder;

		assert request instanceof Requests.Battle;
		battleRequest = (Requests.Battle)request;

		stringBuilder = new StringBuilder();
		for (String line : battleRequest.log.lines)
			stringBuilder.append(line).append("\n");

		return stringBuilder.toString();
	}
}
