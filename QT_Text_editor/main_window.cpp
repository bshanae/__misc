#include "main_window.h"
#include "ui_main_window.h"

					main_window::main_window(QWidget *parent) :
					QMainWindow(parent),
					ui(new Ui::main_window)
{
	ui->setupUi(this);
	QMainWindow::centralWidget()->layout()->setContentsMargins(0, 0, 0, 0);
	ui->layout_edit->setAlignment(Qt::AlignTop);
	ui->layout_edit->setSpacing(2);
	set_font_family();
	set_font_type();
	set_font_size();
	set_font_color();
}

					main_window::~main_window()
{
	delete ui;
}

void				main_window::set_font_family(const QString &family)
{
	ui->text_edit->setFontFamily(family.isEmpty() ? ui->combo_font_family->currentText() : family);
}

void				main_window::set_font_type(const bool &italic, const QFont::Weight &weight)
{
	ui->text_edit->setFontItalic(italic);
	ui->text_edit->setFontWeight(weight);
}

void				main_window::set_font_size(const int &size)
{
	ui->text_edit->setFontPointSize(size == -1 ? ui->spin_font->value() : size);
}

void				main_window::set_font_color(const QColor &color)
{
	ui->text_edit->setTextColor(color);
}
