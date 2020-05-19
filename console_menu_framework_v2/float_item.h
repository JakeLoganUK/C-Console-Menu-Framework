#pragma once
#include "pch.h"
#include "menu_item_base.h"

class float_item final : public menu_item_base {
public:
	float_item(string name, float* setting, float min, float max, float factor);
	string get_text() const override;
	bool input() const override;
private:
	string name_;
	mutable float* setting_;
	float min_;
	float max_;
	float factor_;
};

