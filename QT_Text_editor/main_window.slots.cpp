#include "main_window.h"
#include "ui_main_window.h"

void				main_window::on_combo_font_family_activated(const QString &string)
{
	set_font_family(string);
}

void				main_window::on_combo_font_type_activated(const QString &string)
{
	if (string == "Regular")
		set_font_style(false, QFont::Normal);
	else if (string == "Italic")
		set_font_style(true, QFont::Normal);
	else if (string == "Semibold")
		set_font_style(false, QFont::DemiBold);
	else if (string == "Semibold Italic")
		set_font_style(true, QFont::DemiBold);
	else if (string == "Bold")
		set_font_style(false, QFont::Bold);
	else if (string == "Bold Italic")
		set_font_style(true, QFont::Bold);
}

void				main_window::on_spin_font_valueChanged(int value)
{
	set_font_size(value);
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
	background-color : %1;					\
	border-radius : 4px;					\
}"

void				main_window::on_button_color_clicked()
{
	QColor			new_color = QColorDialog::getColor();

	ui->button_color->setStyleSheet(QString(TEMPLATE).arg(new_color.name()));
	set_text_color(new_color);
}

void				main_window::on_button_align_left_clicked()
{
	set_text_alignment(Qt::AlignLeft);
}

void				main_window::on_button_align_center_clicked()
{
	set_text_alignment(Qt::AlignCenter);
}

void				main_window::on_button_align_right_clicked()
{
	set_text_alignment(Qt::AlignRight);
}

void				main_window::on_button_align_justify_clicked()
{
	set_text_alignment(Qt::AlignJustify);
}

void				main_window::on_button_bold_clicked()
{
	set_text_css("font-weight : bold;");
}
