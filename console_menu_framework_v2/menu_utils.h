#pragma once
#include "pch.h"

namespace menu_utils {
	inline bool get_keypress(const int key) { return GetAsyncKeyState(key) && 0x100 != 0; } // Useless

	inline void show_cursor(const bool show = false) {
		const auto out = GetStdHandle(STD_OUTPUT_HANDLE);

		CONSOLE_CURSOR_INFO cursor_info;

		GetConsoleCursorInfo(out, &cursor_info);
		cursor_info.bVisible = show;
		SetConsoleCursorInfo(out, &cursor_info);
	}

}
