package view.closed.screens.console.implementations;

import application.utils.Point;
import model.open.Requests;
import view.closed.screens.console.ConsoleScreen;
import view.closed.others.common.MapGenerator;
import view.closed.others.console.ResourceManager;
import view.closed.others.console.Template;

public class							ConsoleMapScreen extends ConsoleScreen
{
	private static final Point			CANVAS_SIZE = new Point(65, 7);
	private static final MapGenerator	mapGenerator;

	private Template					mapTemplate;

	static
	{
		mapGenerator = new MapGenerator(CANVAS_SIZE);
	}

	@Override
	public boolean						shouldRequestInput()
	{
		return true;
	}

	@Override
	public String						getContent(Requests.Ui request)
	{
		prepareTemplate();
		writeMapToTemplate(request);

		return mapTemplate.toString();
	}

	private void						prepareTemplate()
	{
		String							rawTemplate;

		rawTemplate = ResourceManager.getText("/console/templates/Map.txt");
		mapTemplate = new Template(rawTemplate);
	}

	private void						writeMapToTemplate(Requests.Ui request)
	{
		char[][]						map;

		map = mapGenerator.generate((Requests.Map)request);
		for (int y = 0; y < CANVAS_SIZE.y; y++)
			mapTemplate.replace("LINE" + y, new String(map[y]));
	}
}
