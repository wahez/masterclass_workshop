#include "cards.h"
#include <memory>
#include <vector>
#include <algorithm>

namespace workshop {

class CardCollection
{
public:
	auto find_place_to_insert(const CardBase& card)
	{
		return std::lower_bound(
			cards.begin(),
			cards.end(),
			card,
			[](const auto& lhs, const auto& rhs) { return *lhs < rhs; });
	}

	void insert(std::unique_ptr<CardBase> card)
	{
		auto it = find_place_to_insert(*card);
		cards.insert(it, std::move(card));
	}

	std::size_t size() const { return cards.size(); }

private:
	std::vector<std::unique_ptr<CardBase>> cards;
};

}
