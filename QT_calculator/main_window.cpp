#include "main_window.h"
#include "ui_main_window.h"

//					PUBLIC

					main_window::main_window(QWidget *parent) :
					QMainWindow(parent),
					ui(new Ui::main_window)
{
	ui->setupUi(this);
}

					main_window::~main_window()
{
	delete ui;
}

//					SLOTS

void				main_window::on_button_0_clicked()
{
	calculator.write_symbol('0');
	update_text();
}

void				main_window::on_button_1_clicked()
{
	calculator.write_symbol('1');
	update_text();
}

void				main_window::on_button_2_clicked()
{
	calculator.write_symbol('2');
	update_text();
}

void				main_window::on_button_3_clicked()
{
	calculator.write_symbol('3');
	update_text();
}

void				main_window::on_button_4_clicked()
{
	calculator.write_symbol('4');
	update_text();
}

void				main_window::on_button_5_clicked()
{
	calculator.write_symbol('5');
	update_text();
}

void				main_window::on_button_6_clicked()
{
	calculator.write_symbol('6');
	update_text();
}

void				main_window::on_button_7_clicked()
{
	calculator.write_symbol('7');
	update_text();
}

void				main_window::on_button_8_clicked()
{
	calculator.write_symbol('8');
	update_text();
}

void				main_window::on_button_9_clicked()
{
	calculator.write_symbol('9');
	update_text();
}

void				main_window::on_button_add_clicked()
{
	calculator.write_action('+');
}

void				main_window::on_button_substract_clicked()
{
	calculator.write_action('-');
}

void				main_window::on_button_multiply_clicked()
{
	calculator.write_action('*');
}

void				main_window::on_button_divide_clicked()
{
	calculator.write_action('/');
}

void				main_window::on_button_evaluate_clicked()
{
	calculator.write_action('=');
	update_text();
}

//					PRIVATE

void				main_window::update_text()
{
	ui->text_browser->setText(calculator.read_line());
}
