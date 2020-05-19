#include "pch.h"
#include "list_item.h"
#include "menu_utils.h"


list_item::list_item(string name, vector<string> list, int* setting): name_(std::move(name)), list_(std::move(list)),
                                                                      setting_(setting) {}

string list_item::get_text() const {
	return this->name_ + ": " + this->list_.at(*this->setting_);
}

bool list_item::input() const {
	if(menu_utils::get_keypress(VK_RIGHT) && this->list_.size() - 1 > *this->setting_) {
		*this->setting_ += 1;
		return true;
	}

	if(menu_utils::get_keypress(VK_LEFT) && *this->setting_ > 0) {
		*this->setting_ -= 1;
		return true;
	}

	return false;
}
