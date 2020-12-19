package view.closed.screens.console.implementations;

import model.open.Requests;
import view.closed.screens.console.ConsoleScreen;
import view.closed.utils.common.ResourceManager;
import view.closed.utils.console.Template;

public class			ConsoleErrorScreen extends ConsoleScreen
{
	@Override
	public String		getContent(Requests.Ui request)
	{
		Requests.Error	errorRequest;
		String			rawTemplate;
		Template		template;

		assert request instanceof Requests.Error;

		errorRequest = (Requests.Error)request;
		rawTemplate = ResourceManager.getText("/console/templates/Error.txt");
		template = new Template(rawTemplate);

		template.replace("MESSAGE", errorRequest.message);
		return template.toString();
	}
}
