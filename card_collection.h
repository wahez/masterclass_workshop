#include "card.h"
#include <memory>
#include <vector>
#include <algorithm>

namespace workshop {

class CardCollection
{
public:
	auto find_place_to_insert(const Card& card)
	{
		return std::lower_bound(
			cards.begin(),
			cards.end(),
			card);
	}

	void insert(Card card)
	{
		auto it = find_place_to_insert(card);
		cards.insert(it, card);
	}

	std::size_t size() const { return cards.size(); }

private:
	std::vector<Card> cards;
};

}
