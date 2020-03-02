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

#define TEMPLATE							\
"QPushButton								\
{											\
	padding : 2px 11px 1px 11px;			\
	border-top : 1px solid #c8c8c8;			\
	border-bottom : 1px solid #acacac;		\
	border-left : 1px solid #c2c2c2;		\
	border-right : 1px solid #c2c2c2;		\
	margin : 2px 0px 1px 0px;				\
	background-color : white;				\
	border-radius : 4px;					\
}"

void				main_window::on_button_color_clicked()
{
	QColor			new_color = QColorDialog::getColor();

	ui->button_color->setStyleSheet(TEMPLATE);
}

