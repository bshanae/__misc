package view.closed.screens.gui.implementations;

import model.closed.gameObjects.creatures.hero.Hero;
import model.open.Pockets;
import model.open.Requests;
import view.closed.mode.modeController.GuiModeController;
import view.closed.screens.gui.GuiScreen;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;
import java.awt.*;
import java.util.List;

public class					GuiHeroSelectorScreen extends GuiScreen
{
	private static final int	GAP_FROM_TOP_TO_TITLE = 45;
	private static final int	GAP_FROM_TITLE_TO_HERO_PANELS = 60;
	private static final int	GAP_BETWEEN_HERO_PANELS = 15;

	private static final int	LEFT_TAB_IN_HERO_PANEL = 15;
	private static final int	RIGHT_TAB_IN_HERO_PANEL = 15;

	private List<Pockets.Hero> heroes;

// ---------------------------> UI

	@Override
	public void					buildGui(Requests.Ui request)
	{
		parseRequest(request);
		setContent(addHorizontalTabs(buildMainPanel()));
	}

	private JPanel				buildMainPanel()
	{
		JPanel					panel;

		panel = new JPanel();

		panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));

		{
			panel.add(Box.createRigidArea(new Dimension(0, GAP_FROM_TOP_TO_TITLE)));

			panel.add(buildTitle());
			panel.add(Box.createRigidArea(new Dimension(0, GAP_FROM_TITLE_TO_HERO_PANELS)));

			panel.add(buildHeroPanel(getHeroAt(0)));
			panel.add(Box.createRigidArea(new Dimension(0, GAP_BETWEEN_HERO_PANELS)));

			panel.add(buildHeroPanel(getHeroAt(1)));
			panel.add(Box.createRigidArea(new Dimension(0, GAP_BETWEEN_HERO_PANELS)));

			panel.add(buildHeroPanel(getHeroAt(2)));
			panel.add(Box.createRigidArea(new Dimension(0, GAP_BETWEEN_HERO_PANELS)));

			panel.add(buildHeroPanel(getHeroAt(3)));
			panel.add(Box.createVerticalGlue());
		}

		return panel;
	}

	private JComponent			buildTitle()
	{
		Font					font;
		JLabel					label;

		font = buildFont(Font.BOLD, 40);

		label = new JLabel("Select hero");
		label.setFont(font);
		label.setAlignmentX(JLabel.CENTER_ALIGNMENT);

		return label;
	}

	private JPanel				buildHeroPanel(Pockets.Hero hero)
	{
		JPanel					panel;

		panel = new JPanel();
		panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
		panel.setBorder(LineBorder.createGrayLineBorder());

		panel.add(Box.createVerticalStrut(5));
		panel.add(buildHeroName(hero != null ? hero.getName() : "Empty"));
		panel.add(buildHeroInfoAndActions());
		panel.add(Box.createVerticalStrut(5));

		return panel;
	}

	private JComponent			buildHeroName(String name)
	{
		JPanel					panel;
		JLabel					label;

		panel = new JPanel();
		panel.setLayout(new BoxLayout(panel, BoxLayout.X_AXIS));

		label = new JLabel(name);
		label.setFont(buildFont(Font.BOLD, 25));

		panel.add(Box.createHorizontalStrut(LEFT_TAB_IN_HERO_PANEL));
		panel.add(label);
		panel.add(Box.createHorizontalGlue());
		panel.add(Box.createHorizontalStrut(RIGHT_TAB_IN_HERO_PANEL));

		return panel;
	}

	private JComponent			buildHeroInfoAndActions()
	{
		JPanel					panel;

		panel = new JPanel();
		panel.setLayout(new BoxLayout(panel, BoxLayout.X_AXIS));

		panel.add(Box.createHorizontalStrut(LEFT_TAB_IN_HERO_PANEL));
		panel.add(buildHeroInfo());
		panel.add(Box.createHorizontalGlue());
		panel.add(buildHeroActions());
		panel.add(Box.createHorizontalStrut(RIGHT_TAB_IN_HERO_PANEL));

		return panel;
	}

	private JComponent			buildHeroInfo()
	{
		JPanel					panel;
		JLabel					label;

		panel = new JPanel();
		panel.setLayout(new BoxLayout(panel, BoxLayout.X_AXIS));

		label = new JLabel("Level 5");
		label.setFont(buildFont(Font.PLAIN, 15));

		panel.add(label);
		panel.add(Box.createHorizontalGlue());

		return panel;
	}

	private JComponent			buildHeroActions()
	{
		JPanel					panel;

		panel = new JPanel();
		panel.setLayout(new BoxLayout(panel, BoxLayout.X_AXIS));

		panel.add(new JButton("Delete"));
		panel.add(new JButton("Select"));

		return panel;
	}

// ---------------------------> Service

	private void				parseRequest(Requests.Ui request)
	{
		Requests.HeroSelector	heroSelectorRequest;

		assert request instanceof Requests.HeroSelector;
		heroSelectorRequest = (Requests.HeroSelector)request;

		heroes = heroSelectorRequest.getHeroes();
	}

	private Pockets.Hero		getHeroAt(int index)
	{
		if (index < heroes.size())
			return heroes.get(index);

		return null;
	}
}