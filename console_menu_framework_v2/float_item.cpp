#include "pch.h"
#include "float_item.h"
#include "menu_utils.h"

float_item::float_item(string name, float* setting, const float min, const float max, const float factor):
	name_(std::move(name)),
	setting_(setting), min_(min),
	max_(max), factor_(factor) {}

string float_item::get_text() const {
	char buf[256];
	sprintf_s(buf, "%s: %.3f", this->name_.c_str(), *this->setting_);
	return buf;
}

bool float_item::input() const {
	if (menu_utils::get_keypress(VK_RIGHT) && *this->setting_ < this->max_) {
		*this->setting_ + this->factor_> this->max_ ? *this->setting_ = this->max_ : *this->setting_ += this->factor_;
		return true;
	}

	if (menu_utils::get_keypress(VK_LEFT) && *this->setting_ > this->min_) {
		*this->setting_ - this->factor_ < this->min_ ? *this->setting_ = this->min_ : *this->setting_ -= this->factor_;
		return true;
	}
	return false;
}
