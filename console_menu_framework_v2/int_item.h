#pragma once
#include "pch.h"
#include "menu_item_base.h"

class int_item final : public menu_item_base {
public:
	int_item(string name, int* setting, int min, int max, int factor);
	string get_text() const override;
	bool input() const override;
private:
	string name_;
	mutable int* setting_;
	int min_;
	int max_;
	int factor_;
};

