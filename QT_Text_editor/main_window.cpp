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
	set_font();
}

					main_window::~main_window()
{
	delete ui;
}					

void				main_window::set_font(const QString &font, const QString &type, const int &size)
{

	ui->text_edit->setFontFamily(font.isEmpty() ? ui->combo_font_family->currentText() : font);

	if (type == "Regular")
		set_font_type(false, QFont::Normal);
	else if (type == "Italic")
		set_font_type(true, QFont::Normal);
	else if (type == "Semibold")
		set_font_type(false, QFont::DemiBold);
	else if (type == "Semibold Italic")
		set_font_type(true, QFont::DemiBold);
	else if (type == "Bold")
		set_font_type(false, QFont::Bold);
	else if (type == "Bold Italic")
		set_font_type(true, QFont::Bold);

	ui->text_edit->setFontPointSize(size == -1 ? ui->spin_font->value() : size);
}

void				main_window::set_font_type(const bool &italic, const QFont::Weight &weight)
{
	ui->text_edit->setFontItalic(italic);
	ui->text_edit->setFontWeight(weight);
}
