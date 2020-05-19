#include "pch.h"
#include "int_item.h"
#include "menu_utils.h"

int_item::int_item(string name, int* setting, const int min, const int max, const int factor): name_(std::move(name)),
                                                                                               setting_(setting),
                                                                                               min_(min), max_(max),
                                                                                               factor_(factor) { }

string int_item::get_text() const {
	char buf[256];
	sprintf_s(buf, "%s: %d", this->name_.c_str(), *this->setting_);
	return buf;
}

bool int_item::input() const {

	if (menu_utils::get_keypress(VK_RIGHT) && *this->setting_ < this->max_) {
		*this->setting_ + this->factor_ > this->max_ ? *this->setting_ = this->max_ : *this->setting_ += this->factor_;
		return true;
	}

	if (menu_utils::get_keypress(VK_LEFT) && *this->setting_ > this->min_) {
		*this->setting_ - this->factor_ < this->min_ ? *this->setting_ = this->min_ : *this->setting_ -= this->factor_;
		return true;
	}
	return false;
}
