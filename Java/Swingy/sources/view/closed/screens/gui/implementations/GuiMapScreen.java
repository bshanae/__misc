package view.closed.screens.gui.implementations;

import application.utils.Point;
import model.open.Requests;
import net.miginfocom.swing.MigLayout;
import view.closed.screens.gui.GuiScreen;
import view.closed.utils.common.MapGenerator;

import javax.swing.*;
import javax.swing.border.LineBorder;

public class							GuiMapScreen extends GuiScreen
{
	private static final Point			CANVAS_SIZE = new Point(20, 15);
	private static final MapGenerator	mapGenerator;

	static
	{
		mapGenerator = new MapGenerator(CANVAS_SIZE);
	}

	@Override
	public JPanel						getContent(Requests.Ui request)
	{
		JPanel							panel;

		panel = new JPanel();
		panel.setLayout(new MigLayout("fill"));

		panel.add(buildMap(request), "grow, wrap, width 600!, height 400!, center");
		panel.add(new JButton("Hi"), "center");

		return panel;
	}

	private JComponent					buildMap(Requests.Ui request)
	{
		String							layoutConfig;
		JPanel							panel;
		char[][]						map;

		layoutConfig = String.format("insets 5, fill, wrap %d", CANVAS_SIZE.x);

		panel = new JPanel();
		panel.setLayout(new MigLayout(layoutConfig));
		panel.setBorder(LineBorder.createGrayLineBorder());

		map = mapGenerator.generate((Requests.Map)request);

		for (int y = 0; y < CANVAS_SIZE.y; y++)
		for (int x = 0; x < CANVAS_SIZE.x; x++)
				panel.add(buildCell(map[y][x]), "al center");

		return panel;
	}

	private JComponent					buildCell(char character)
	{
		JLabel							label;

		label = new JLabel("" + character);

		return label;
	}
}
