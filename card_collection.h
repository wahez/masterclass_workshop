#include "cards.h"
#include <memory>
#include <list>
#include <algorithm>

namespace workshop {

class CardCollection
{
public:
	auto find_place_to_insert(const CardBase& card)
	{
		return std::find_if(
			cards.begin(),
			cards.end(),
			[&](const auto& other) { return card < *other; });
	}

	void insert(std::unique_ptr<CardBase> card)
	{
		auto it = find_place_to_insert(*card);
		cards.insert(it, std::move(card));
	}

	std::size_t size() const { return cards.size(); }

private:
	std::list<std::unique_ptr<CardBase>> cards;
};

}
