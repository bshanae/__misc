#ifndef MAIN_WINDOW_H
# define MAIN_WINDOW_H

# include <QMainWindow>
# include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class				main_window : public QMainWindow
{
	Q_OBJECT

public:
					main_window(QWidget *parent = nullptr);
					~main_window();

private slots:

	void			on_combo_font_activated(const QString &arg1);

private:

	Ui::main_window *ui;

	void			set_font(const QString &font = "");
};

#endif
