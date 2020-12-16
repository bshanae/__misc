package view.closed.screens.console.implementations;

import model.open.Requests;
import view.closed.screens.console.ConsoleScreen;
import view.closed.utils.common.ResourceManager;

public class		ConsoleClassSelectorScreen extends ConsoleScreen
{
	@Override
	public void		buildUi(Requests.Ui request)
	{
		setContent(ResourceManager.getText("/console/templates/ClassSelector.txt"));
	}
}
