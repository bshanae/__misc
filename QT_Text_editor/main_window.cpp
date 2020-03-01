#include "main_window.h"
#include "ui_main_window.h"

					main_window::main_window(QWidget *parent) :
					QMainWindow(parent),
					ui(new Ui::main_window)
{
	ui->setupUi(this);
	QMainWindow::centralWidget()->layout()->setContentsMargins(0, 0, 0, 0);
	ui->layout_edit->setAlignment(Qt::AlignTop);
	set_font();
}

					main_window::~main_window()
{
	delete ui;
}					

void				main_window::set_font(const QString &font)
{

	ui->text_edit->setFontFamily(font.isEmpty() ? ui->combo_font->currentText() : font);
}
