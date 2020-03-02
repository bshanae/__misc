#include "main_window.h"
#include "ui_main_window.h"

					main_window::main_window(QWidget *parent) :
					QMainWindow(parent),
					ui(new Ui::main_window)
{
	QFont			font;
	font.setWeight(QFont::DemiBold);

	ui->setupUi(this);
	QMainWindow::centralWidget()->layout()->setContentsMargins(0, 0, 0, 0);

	ui->layout_edit->setAlignment(Qt::AlignTop);
	ui->layout_edit->setSpacing(2);

	ui->label_font->setFont(font);
	ui->label_alignment->setFont(font);

	set_font_family();
	set_font_style();
	set_font_size();
	set_text_color();
	set_text_alignment();
}

					main_window::~main_window()
{
	delete ui;
}

void				main_window::set_font_family(const QString &family)
{
	ui->text_edit->setFontFamily(family.isEmpty() ? ui->combo_font_family->currentText() : family);
}

void				main_window::set_font_style(const bool &italic, const QFont::Weight &weight)
{
	ui->text_edit->setFontItalic(italic);
	ui->text_edit->setFontWeight(weight);
}

void				main_window::set_font_size(const int &size)
{
	ui->text_edit->setFontPointSize(size == -1 ? ui->spin_font->value() : size);
}

void				main_window::set_text_color(const QColor &color)
{
	ui->text_edit->setTextColor(color);
}

void				main_window::set_text_alignment(const Qt::Alignment &alignment)
{
	ui->text_edit->setAlignment(alignment);
}

void				main_window::set_text_css(const QString &string)
{}
