package view.closed.screens.console.implementations;

import application.common.Point;
import application.common.PointRange;
import model.open.Pockets;
import model.open.Requests;
import view.closed.screens.console.ConsoleScreen;
import view.closed.utils.console.ResourceManager;
import view.closed.utils.console.Template;

import java.util.List;

public class						ConsoleMapScreen extends ConsoleScreen
{
	private static final Point		CANVAS_SIZE = new Point(65, 7);

	private static final char		NULL_CHARACTER = ' ';
	private static final char		DEFAULT_CHARACTER = '·';
	private static final char		HERO_CHARACTER = 'H';
	private static final char		ENEMY_CHARACTER = 'E';

	private Point					mapSize;
	private List<Pockets.Creature>	mapCreatures;

	private Point					pivot;

	private Point					offset;
	private PointRange				bounds;

	private Template				mapTemplate;
	private String[]				mapLines;

	@Override
	public String					getContent(Requests.Ui request)
	{
		loadInfo(request);
		calculateOffset();
		calculateBounds();

		prepareTemplate();
		writeMapToLines();
		writeMapToTemplate();

		return mapTemplate.toString();
	}

	private void					loadInfo(Requests.Ui request)
	{
		Requests.Map				mapRequest;

		assert request instanceof Requests.Map;
		mapRequest = (Requests.Map)request;

		mapSize = mapRequest.map.size;
		mapCreatures = mapRequest.map.creatures;

		pivot = mapRequest.pivot;
	}

	private void					calculateOffset()
	{
		Point						mapOverCanvasOffset;
		Point						pivotOverMapOffset;

		mapOverCanvasOffset = CANVAS_SIZE.subtract(new Point(1)).divide(2);

		pivotOverMapOffset = new Point();
		pivotOverMapOffset.x = pivot.x * -1;
		pivotOverMapOffset.y = pivot.y * -1;

		offset = mapOverCanvasOffset.add(pivotOverMapOffset);
	}

	private void					calculateBounds()
	{
		bounds = new PointRange(new Point(), mapSize);
	}

	private void					prepareTemplate()
	{
		String						rawTemplate;

		rawTemplate = ResourceManager.getText("/console/templates/Map.txt");
		mapTemplate = new Template(rawTemplate);
	}

	private void					writeMapToLines()
	{
		int						invertedYForCanvas;


		mapLines = new String[CANVAS_SIZE.y];
		for (int y = 0; y < CANVAS_SIZE.y; y++)
		{
			invertedYForCanvas = CANVAS_SIZE.y - y - 1;

			mapLines[invertedYForCanvas] = "";
			for (int x = 0; x < CANVAS_SIZE.x; x++)
				mapLines[invertedYForCanvas] += getCharacterForCoordinate(new Point(x, y));
		}
	}

	private char					getCharacterForCoordinate(Point canvasCoordinate)
	{
		Point						mapCoordinate;
		Pockets.Creature			creature;

		mapCoordinate = canvasCoordinate.subtract(offset);

		if (!isCoordinateInMap(mapCoordinate))
			return NULL_CHARACTER;

		creature = getCreatureForCoordinate(mapCoordinate);

		if (creature instanceof Pockets.Hero)
			return HERO_CHARACTER;
		else if (creature instanceof Pockets.Enemy)
			return ENEMY_CHARACTER;

		// TODO
		return DEFAULT_CHARACTER;
	}

	private Pockets.Creature		getCreatureForCoordinate(Point coordinate)
	{
		for (Pockets.Creature creature : mapCreatures)
			if (creature.position.equals(coordinate))
				return creature;

		return null;
	}

	private boolean					isCoordinateInMap(Point coordinate)
	{
		return bounds.isInRange(coordinate);
	}

	private void					writeMapToTemplate()
	{
		for (int i = 0; i < mapLines.length; i++)
			mapTemplate.replace("LINE" + i, mapLines[i]);
	}
}
