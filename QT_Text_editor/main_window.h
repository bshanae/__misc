#ifndef MAIN_WINDOW_H
# define MAIN_WINDOW_H

# include <QMainWindow>
# include <QDebug>
# include <QColorDialog>

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

	void			on_combo_font_family_activated(const QString &arg1);
	void			on_combo_font_type_activated(const QString &arg1);
	void			on_spin_font_valueChanged(int arg1);
	void			on_button_color_clicked();

private:

	Ui::main_window *ui;

	void			set_font(const QString &family = "", const QString &type = "Regular", const int &size = -1);
	void			set_font_type(const bool &italic, const QFont::Weight &weight);
};

#endif
