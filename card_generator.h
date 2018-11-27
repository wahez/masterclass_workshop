#pragma once
#include "card.h"
#include <random>

namespace workshop {

class CardGenerator
{
public:
    Card get_random_card();

private:
	std::minstd_rand engine{0};
};

}
