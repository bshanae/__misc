#include "button_color.h"

					button_color::button_color(const QColor & color, QWidget *parent) :
					QPushButton(parent)
{
	this->setMinimumWidth(50);
	currentColor = color;
	connect(this, SIGNAL(clicked()), this, SLOT(chooseColor()));
}

QColor				button_color::getColor()
{
	return (currentColor);
}

void				button_color::changeColor(const QColor & color)
{
	currentColor = color;
	colorChanged(currentColor);
}

void				button_color::chooseColor()
{
	QColor color = QColorDialog::getColor(currentColor, this);
	if (color.isValid())
		changeColor(color);
}

void				button_color::paintEvent(QPaintEvent *event)
{
	int				colorPadding = 5;

	QPushButton::paintEvent(event);

	QRect rect = event->rect();
	QPainter painter( this );
	painter.setBrush( QBrush( currentColor ) );
	painter.setPen("#CECECE");
	rect.adjust(colorPadding, colorPadding, -1-colorPadding, -1-colorPadding);
	painter.drawRect(rect);
}
