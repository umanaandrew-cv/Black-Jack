#ifndef MURACH_HAND_H
#define MURACH_HAND_H

#include <string>
#include <vector>

class Hand: public Card
{
private:
	std::vector<std::string> dealer;
	std::vector<std::string> player;
	
	std::vector<int>dealer_val;
	std::vector<int>player_val;

public:
	Hand();

	void set_dealer(int);
	void set_player(int);

	void set_dealer_val(int);
	void set_player_val(int);

	std::string get_dealer_suit()const;
	std::string get_dealer_rank()const;
	int get_dealer_val()const;

	//std::string get_player_suit()const;
	//std::string get_player_suit()const;
	//int get_dealer_val()const;

	Hand& operator++ ();
};

#endif