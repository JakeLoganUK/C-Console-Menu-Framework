#pragma once
#include "pch.h"
#include "menu_item_base.h"

class list_item final : public menu_item_base {
public:
	list_item(string name, vector<string> list, int* setting);
	string get_text() const override;
	bool input() const override;

private:
	string name_;
	vector<string> list_;
	mutable int* setting_;
};
