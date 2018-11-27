#pragma once
#include <string>
#include <ostream>
#include <tuple>

namespace workshop {

enum class Color : std::uint8_t
{
	spades,
	hearts,
	clubs,
	diamonds
};

enum class Type : std::uint8_t
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

class Card
{
public:
	Card(Color c, Type t) : type_(t), color_(c) {}

	Color color() const { return color_; }
	Type type() const { return type_; }

	friend bool operator<(const Card& lhs, const Card& rhs)
	{
		return
		        ((static_cast<std::uint8_t>(lhs.color()) << 8) | static_cast<std::uint8_t>(lhs.type())) <
		        ((static_cast<std::uint8_t>(rhs.color()) << 8) | static_cast<std::uint8_t>(rhs.type()));
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
