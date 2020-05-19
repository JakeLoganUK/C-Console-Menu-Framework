#include "pch.h"
#include "bool_item.h"
#include "menu_utils.h"


bool_item::bool_item(string name, bool* setting): name_(std::move(name)), setting_(setting) {}

string bool_item::get_text() const { return this->name_ + ": " + (*this->setting_ ? "True" : "False"); }

bool bool_item::input() const {
	if (menu_utils::get_keypress(VK_RIGHT) || menu_utils::get_keypress(VK_LEFT)) {
		*this->setting_ = !(*this->setting_);
		return true;
	}
	return false;
}
