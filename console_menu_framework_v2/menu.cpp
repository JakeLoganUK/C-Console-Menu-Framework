#include "pch.h"
#include "menu.h"
#include "menu_utils.h"
#include "termcolor.h"
#include <iomanip>

menu::menu(string title, const string&& description, const double version) : title_(std::move(title)),
                                                                             description_(description),
                                                                             version_(version) {
	std::cout << termcolor::cyan;
	menu_utils::show_cursor();
	this->render();
}

menu::~menu() = default;

void menu::render() const {
	system("cls");

	std::cout << this->title_ << std::endl; // Draw title

	if (!this->description_.empty()) // Draw Description unless 0
		std::cout << this->description_ << std::endl;

	if (this->version_ > 0) // Draw Version unless 0
		std::cout << "Version: " << std::setprecision(2) << std::fixed << this->version_ << std::endl << std::endl <<
			std::endl;

	for (auto it = this->items_.begin(); it != this->items_.end(); ++it) {
		// Render Menu Items
		const auto pos{std::distance(this->items_.begin(), it)};
		const auto selected{cur_pos_ == pos};

		if (selected)
			std::cout << termcolor::green << ">";

		std::cout << (*it)->get_text() << std::endl << termcolor::cyan;
	}
}

void menu::input() const {
	if (menu_utils::get_keypress(VK_UP) && this->cur_pos_ > 0) {
		this->cur_pos_--;
		this->render();
	}

	if (menu_utils::get_keypress(VK_DOWN) && this->items_.size() - 1 > this->cur_pos_) {
		this->cur_pos_++;
		this->render();
	}

	for (auto it = this->items_.begin(); it != this->items_.end(); ++it) {
		// Handle menu item input
		const auto pos{std::distance(this->items_.begin(), it)};
		const auto selected{cur_pos_ == pos};

		if (selected) {
			if ((*it)->input())
				this->render();
		}
	}

	Sleep(125);
}

void menu::add_item(menu_item_base* item) const {
	this->items_.push_back(item);
	this->render();
}
