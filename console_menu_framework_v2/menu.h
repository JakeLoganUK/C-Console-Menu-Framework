#pragma once
#include "pch.h"
#include "menu_items.h"

class menu final {
public:
	explicit menu(string title, const string&& description = "", double version = 0);
	~menu();

	void render() const;
	void input() const;
	void add_item(menu_item_base* item) const;
private:
	string title_;
	string description_;
	double version_;
	mutable int cur_pos_{0};
	mutable vector<menu_item_base*> items_;
};
