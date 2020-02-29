#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "calculator.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class main_window : public QMainWindow
{
	Q_OBJECT

public:
					main_window(QWidget *parent = nullptr);
					~main_window();

private slots:

	void			on_button_0_clicked();
	void			on_button_1_clicked();
	void			on_button_2_clicked();
	void			on_button_3_clicked();
	void			on_button_4_clicked();
	void			on_button_5_clicked();
	void			on_button_6_clicked();
	void			on_button_7_clicked();
	void			on_button_8_clicked();
	void			on_button_9_clicked();

private:

	Ui::main_window	*ui;
	calculator		calculator;

	void			update_text();
};

#endif
