package view.closed.screens.console.implementations;

import model.open.Pockets;
import model.open.Requests;
import view.closed.screens.console.ConsoleScreen;
import view.closed.utils.common.ResourceManager;
import view.closed.utils.console.Template;

import java.util.List;

public class					ConsoleHeroSelectorScreen extends ConsoleScreen
{
	@Override
	public void					buildUi(Requests.Ui request)
	{
		Requests.HeroSelector	heroSelectorRequest;
		String					rawTemplate;
		Template				template;

		assert request instanceof Requests.HeroSelector;

		heroSelectorRequest = (Requests.HeroSelector)request;
		rawTemplate = ResourceManager.getText("/console/templates/HeroSelector.txt");
		template = new Template(rawTemplate);

		List<Pockets.Hero>		heroes = heroSelectorRequest.heroes;
		int						numberOfHeroes = heroes.size();

		for (int i = 0; i < 4; i++)
		{
			template.replace
			(
				"HERO" + i,
				i < numberOfHeroes ? heroes.get(i).name : "Empty"
			);
		}

		setContent(template.toString());
	}
}
