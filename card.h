#pragma once
#include <string>
#include <ostream>
#include <tuple>

namespace workshop {

enum class Color
{
	spades,
	hearts,
	clubs,
	diamonds
};

enum class Type
{
	ace = 1,
	two = 2,
	three = 3,
	four = 4,
	five = 5,
	six = 6,
	seven = 7,
	eight = 8,
	nine = 9,
	ten = 10,
	jack,
	queen,
	king
};

class CardBase
{
public:
	virtual ~CardBase();

	virtual Color color() const = 0;
	virtual Type type() const = 0;
};

class Card : public CardBase
{
public:
	Card(Color color, Type type) : type_(type), color_(color) {}

	Color color() const override { return color_; }
	Type type() const override { return type_; }

	friend bool operator<(const Card& lhs, const Card& rhs)
	{
		return std::tie(lhs.type_, lhs.color_) < std::tie(rhs.type_, rhs.color_);
	}

private:
	Type type_;
	Color color_;
};

inline std::ostream& operator<<(std::ostream& os, const Card& card)
{
	os << '[';
	switch (card.type())
	{
	case Type::ace:
		os << "ace";
		break;
	case Type::two:
	case Type::three:
	case Type::four:
	case Type::five:
	case Type::six:
	case Type::seven:
	case Type::eight:
	case Type::nine:
	case Type::ten:
		os << static_cast<int>(card.type());
		break;
	case Type::jack:
		os << "jack";
		break;
	case Type::queen:
		os << "queen";
		break;
	case Type::king:
		os << "king";
		break;
	}
	os << " of ";
	switch (card.color())
	{
	case Color::spades:
		os << "spades";
		break;
	case Color::hearts:
		os << "hearts";
		break;
	case Color::clubs:
		os << "clubs";
		break;
	case Color::diamonds:
		os << "diamonds";
		break;
	}
	return os;
}

}
