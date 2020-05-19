#pragma once
#include "pch.h"
#include "singleton.h"

class config final : public singleton<config> {
public:
	bool test_bool{true};
	int test_int{0};
	float test_float{0.f};
	int test_list{0};
};
