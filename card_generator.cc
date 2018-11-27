#include "card_generator.h"
#include "card.h"
#include <random>

namespace workshop {

Card CardGenerator::get_random_card()
{
    static std::uniform_int_distribution<int> color_dist{static_cast<int>(Color::spades), static_cast<int>(Color::diamonds)};
    static std::uniform_int_distribution<int> type_dist{static_cast<int>(Type::ace), static_cast<int>(Type::king)};
    const auto color = static_cast<Color>(color_dist(engine));
    const auto type = static_cast<Type>(type_dist(engine));
    return Card{color, type};
}

}
