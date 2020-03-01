#include "main_window.h"
#include "ui_main_window.h"

void				main_window::on_combo_font_activated(const QString &selected)
{
	set_font(selected);
}
