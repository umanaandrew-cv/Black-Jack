#ifndef MURACH_DECK_H
#define MURACH_DECK_H

#include "Card.h"

#include <string>

class Deck:public Card
{
private:
	std::string rank;
	std::string suit;

public:
	Deck();

};

#endif