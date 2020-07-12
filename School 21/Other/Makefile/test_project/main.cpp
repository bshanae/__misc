#include "print_hi/print_hi.class.h"
#include "print_bye/print_bye.class.h"
#include "lib/lib.h"

int					main()
{
	print_hi		hi;
	print_bye		bye;
	lib				lib;

	hi.work();
	bye.work();
	lib.work();
	
	return (0);
}
