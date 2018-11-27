#include "cards.h"
#include <random>

namespace workshop {

SpadesCard::SpadesCard(std::string type)
	: type_(type)
{}

std::string SpadesCard::color() const
{
	static const std::string color_ = "spades";
	return color_;
}

std::string SpadesCard::type() const
{
	return type_;
}

HeartsCard::HeartsCard(std::string type)
	: type_(type)
{}

std::string HeartsCard::color() const
{
	static const std::string color_ = "hearts";
	return color_;
}

std::string HeartsCard::type() const
{
	return type_;
}

ClubsCard::ClubsCard(std::string type)
	: type_(type)
{}

std::string ClubsCard::color() const
{
	static const std::string color_ = "clubs";
	return color_;
}

std::string ClubsCard::type() const
{
	return type_;
}

DiamondsCard::DiamondsCard(std::string type)
	: type_(type)
{}

std::string DiamondsCard::color() const
{
	static const std::string color_ = "diamonds";
	return color_;
}

std::string DiamondsCard::type() const
{
	return type_;
}

}
