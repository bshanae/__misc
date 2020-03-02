#include "main_window.h"
#include "ui_main_window.h"

void				main_window::on_combo_font_family_activated(const QString &string)
{
	set_font(string);
}

void				main_window::on_combo_font_type_activated(const QString &string)
{
	set_font("", string);
}

void				main_window::on_spin_font_valueChanged(int value)
{
	set_font("", "", value);
}

void				main_window::on_button_color_clicked()
{
	QColor			new_color = QColorDialog::getColor();
}

