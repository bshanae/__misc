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
	void			on_button_align_left_clicked();
	void			on_button_align_center_clicked();
	void			on_button_align_right_clicked();
	void			on_button_align_justify_clicked();
	void			on_button_bold_clicked();

private:

	Ui::main_window	*ui;

	void			set_font_family(const QString &family = "");
	void			set_font_style(const bool &italic = false, const QFont::Weight &weight = QFont::Normal);
	void			set_font_size(const int &size = -1);

	void			set_text_color(const QColor &color = Qt::black);
	void			set_text_alignment(const Qt::Alignment &alignment = Qt::AlignLeft);
	void			set_text_css(const QString &string);
};

#endif
