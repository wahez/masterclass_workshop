#pragma once
#include "card.h"

namespace workshop {

class SpadesCard: public CardBase
{
public:
	explicit SpadesCard(std::string type);

    const std::string& color() const override;
    const std::string& type() const override;

private:
	std::string type_;
};

class HeartsCard: public CardBase
{
public:
	explicit HeartsCard(std::string type);

	const std::string& color() const override;
	const std::string& type() const override;

private:
	std::string type_;
};

class ClubsCard: public CardBase
{
public:
	explicit ClubsCard(std::string type);

	const std::string& color() const override;
	const std::string& type() const override;

private:
	std::string type_;
};

class DiamondsCard: public CardBase
{
public:
	explicit DiamondsCard(std::string type);

    const std::string& color() const override;
    const std::string& type() const override;

private:
	std::string type_;
};

}
