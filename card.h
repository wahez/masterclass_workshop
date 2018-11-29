#pragma once
#include <string>
#include <ostream>

namespace workshop {

class CardBase
{
public:
    virtual ~CardBase();
    virtual const std::string& color() const = 0;
    virtual const std::string& type() const = 0;
};

inline std::ostream& operator<<(std::ostream& os, const CardBase& card)
{
	os << '[' << card.type() << " of " << card.color() << ']';
	return os;
}

inline bool operator<(const CardBase& lhs, const CardBase& rhs)
{
	if (lhs.color() != rhs.color())
		return lhs.color() < rhs.color();
	return lhs.type() < rhs.type();
}

}
