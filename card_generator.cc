#include "card_generator.h"
#include "card.h"
#include <random>

namespace workshop {

std::string type_to_string(int type)
{
	switch (type)
	{
	case 1:
		return "ace";
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
		return std::to_string(type);
	case 11:
		return "jack";
	case 12:
		return "queen";
	case 13:
		return "king";
	}
	throw std::runtime_error("Unkown card type");
}

Card CardGenerator::get_random_card()
{
    static std::uniform_int_distribution<int> color_dist{1, 4};
    static std::uniform_int_distribution<int> type_dist{2, 13};
    const auto type = type_to_string(type_dist(engine));
    int color = color_dist(engine);
    switch (color)
    {
    case 1:
        return Card{"hearts", type};
    case 2:
        return Card{"clubs", type};
    case 3:
        return Card{"diamonds", type};
    case 4:
        return Card{"spades", type};
    }
    throw std::runtime_error("Unknown card color");
}

}
