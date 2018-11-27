#pragma once
#include <string>
#include <ostream>
#include <tuple>

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

class Card : public CardBase
{
public:
	Card(std::string c, std::string t) : type_(std::move(t)), color_(std::move(c)) {}

	const std::string& color() const override { return color_; }
	const std::string& type() const override { return type_; }

	friend bool operator<(const Card& lhs, const Card& rhs)
	{
		return std::tie(lhs.type_, lhs.color_) < std::tie(rhs.type_, rhs.color_);
	}

private:
	std::string type_;
	std::string color_;
};

}
