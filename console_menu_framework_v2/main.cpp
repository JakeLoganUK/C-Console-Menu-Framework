#include "pch.h"
#include "menu.h"
#include "config.h"

int main() {

	/*		     [EXAMPLE MENU]
	 *	- Set description to "" for no description
	 *	- Set version to 0 for no version
	 *  - Owner Voltz
	 */

	menu my_menu(" Voltz' Console Menu Framework", "A framework used to make menus in CLI.", 2.00);
	my_menu.add_item(new bool_item("Test Bool", &config::get().test_bool));
	my_menu.add_item(new int_item("Test Int", &config::get().test_int, 0, 10, 2));
	my_menu.add_item(new float_item("Test Float", &config::get().test_float, 0, 10, 1.4));
	my_menu.add_item(new list_item("Test List", vector<string>{"Test", "Test2", "Test3", "Test4"},
	                               &config::get().test_list));

	while (true) { my_menu.input(); }
	return EXIT_SUCCESS;
}
