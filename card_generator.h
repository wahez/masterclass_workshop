#pragma once
#include "card.h"
#include <memory>
#include <random>

namespace workshop {

class CardGenerator
{
public:
	std::unique_ptr<CardBase> get_random_card();

private:
	std::minstd_rand engine{0};
};

}
