#ifndef MURACH_CARD_H
#define MURACH_CARD_H

#include <string>

class Card
{
private:
	std::string suit;
	std::string rank;
	int value;

public:
	Card();

	void set_suit(int);
	void set_rank(int);
	void set_value(int);

	std::string get_suit()const;
	std::string get_rank()const;
	int get_value()const;

	friend std::ostream& operator<< (std::ostream&, const Card&);
};

#endif