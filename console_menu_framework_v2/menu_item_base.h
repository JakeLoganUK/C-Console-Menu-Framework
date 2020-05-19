#pragma once
#include "pch.h"

class menu_item_base {
public:
	virtual ~menu_item_base() = default;
	virtual string get_text() const;
	virtual bool input() const;
};

