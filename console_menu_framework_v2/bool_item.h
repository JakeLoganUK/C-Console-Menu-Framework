#pragma once
#include "pch.h"
#include "menu_item_base.h"

class bool_item final : public menu_item_base {
public:
	bool_item(string name, bool* setting);
	string get_text() const override;
	bool input() const override;
private:
	string name_;
	mutable bool* setting_;
};

