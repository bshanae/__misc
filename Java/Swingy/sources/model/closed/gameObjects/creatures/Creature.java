package model.closed.gameObjects.creatures;

import application.common.Point;

public class		Creature
{
	private Point	position;

	public Point	getPosition()
	{
		return position;
	}

	public void		setPosition(Point position)
	{
		assert position != null;
		this.position = position;
	}
}
