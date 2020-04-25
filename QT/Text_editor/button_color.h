#ifndef BUTTON_COLOR_H
# define BUTTON_COLOR_H

# include <QtGui>
# include <QPushButton>
# include <QColorDialog>

class				button_color : public QPushButton
{
	Q_OBJECT
public:
	explicit		button_color(const QColor & color = Qt::black, QWidget *parent = nullptr);
	QColor			getColor();

signals:
	void			colorChanged(QColor);

public slots:
	void			changeColor(const QColor &);
	void			chooseColor();
	void			paintEvent(QPaintEvent *event);

private:

	QColor			currentColor;
};

#endif
