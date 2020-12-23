package view.closed.screens.gui.implementations;

import application.utils.Point;
import model.open.Requests;
import net.miginfocom.swing.MigLayout;
import view.closed.screens.gui.GuiScreen;
import view.closed.utils.common.MapGenerator;
import view.open.ButtonId;

import javax.swing.*;
import javax.swing.border.LineBorder;

public class							GuiMapScreen extends GuiScreen
{
	private static final Point			CANVAS_SIZE = new Point(20, 15);

	private static final ImageIcon[]	iconsOfArrows;
	private static final MapGenerator	mapGenerator;

	static
	{
		mapGenerator = new MapGenerator(CANVAS_SIZE);

		iconsOfArrows = new ImageIcon[4];
		iconsOfArrows[0] = new ImageIcon("resources/gui/arrow-up.png");
		iconsOfArrows[1] = new ImageIcon("resources/gui/arrow-left.png");
		iconsOfArrows[2] = new ImageIcon("resources/gui/arrow-right.png");
		iconsOfArrows[3] = new ImageIcon("resources/gui/arrow-down.png");
	}

	@Override
	public JPanel						getContent(Requests.Ui request)
	{
		JPanel							panel;

		panel = new JPanel();
		panel.setLayout(new MigLayout("fill"));

		panel.add(buildMap(request), "grow, wrap, width 600!, height 400!, center");
		panel.add(buildButtons(), "center");

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
			panel.add(buildCell(map[y][x]), "center");

		return panel;
	}

	private JComponent					buildCell(char character)
	{
		return new JLabel("" + character);
	}

	private JComponent					buildButtons()
	{
		JPanel panel;
		JButton[] buttons;

		panel = new JPanel();
		panel.setLayout(new MigLayout());

		{
			buttons = new JButton[4];

			for (int i = 0; i < 4; i++)
			{
				buttons[i] = new JButton(iconsOfArrows[i]);
				buttons[i].setBorder(BorderFactory.createEmptyBorder());
			}

			buttons[0].addActionListener(new GuiSignalSender(ButtonId.MAP_ARROW_UP));
			buttons[1].addActionListener(new GuiSignalSender(ButtonId.MAP_ARROW_LEFT));
			buttons[2].addActionListener(new GuiSignalSender(ButtonId.MAP_ARROW_RIGHT));
			buttons[3].addActionListener(new GuiSignalSender(ButtonId.MAP_ARROW_DOWN));
		}

		panel.add(buttons[0], "cell 1 0");
		panel.add(buttons[1], "cell 0 1");
		panel.add(buttons[2], "cell 2 1");
		panel.add(buttons[3], "cell 1 2");

		return panel;
	}

}