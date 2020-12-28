package view.closed.screens.console.implementations;

import model.open.Requests;
import view.closed.screens.console.ConsoleScreen;
import view.closed.others.console.ResourceManager;

public class		ConsoleClassSelectorScreen extends ConsoleScreen
{
	@Override
	public boolean	shouldRequestInput()
	{
		return true;
	}

	@Override
	public String	getContent(Requests.Ui request)
	{
		return ResourceManager.getText("/console/templates/ClassSelector.txt");
	}
}
