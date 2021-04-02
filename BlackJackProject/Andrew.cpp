/*
Andrew Umana
This program is used to create black jack
*/


#include <iostream>
#include <string>
#include <ctime>
#include <numeric>
#include <algorithm>

#include "Card.h"
#include "Deck.h"
#include "Hand.h"

using namespace std;

Card::Card()
{
	string suit = "";
	string rank = "";
	int value = 0;
}

void Card::set_suit(int suit_param)
{
	switch(suit_param)
	{
	case 0:
		suit = "Clubs";
		break;

	case 1:
		suit = "Diamonds";
		break;

	case 2:
		suit = "Hearts";
		break;

	case 3:
		suit = "Spades";
		break;

	default:
		break;
	}
}

void Card::set_rank(int rank_param)
{
	switch (rank_param)
	{
	case 2:
		rank = "2";
		break;

	case 3:
		rank = "3";
		break;

	case 4:
		rank = "4";
		break;

	case 5:
		rank = "5";
		break;

	case 6:
		rank = "6";
		break;

	case 7:
		rank = "7";
		break;

	case 8:
		rank = "8";
		break;

	case 9:
		rank = "9";
		break;

	case 10:
		rank = "10";
		break;

	case 11:
		rank = "Jack";
		break;

	case 12:
		rank = "Queen";
		break;

	case 13:
		rank = "King";
		break;

	case 14:
		rank = "Ace";
		break;

	default:
		break;
	}
}

void Card::set_value(int value_param)
{
	value = value_param;
}

string Card::get_suit()const
{
	return suit;
}

string Card::get_rank()const
{
	return rank;
}

int Card::get_value()const
{
	return value;
}

ostream& operator<<(ostream& out, const Card& c)
{
	out << c.rank << " of " << c.suit << endl;
	return out;
}


Hand::Hand()
{
	vector<std::string> dealer;
	vector<std::string> player;

	vector<int>dealer_val;
	vector<int>player_val;
}

void Hand::set_dealer(int card_param)
{
	switch (card_param)
	{
	case 0:
		dealer.push_back("Clubs");
		break;

	case 1:
		dealer.push_back("Diamonds");
		break;

	case 2:
		dealer.push_back("Hearts");
		break;

	case 3:
		dealer.push_back("Spades");
		break;

	default:
		break;
	}

}

void Hand::set_player(int card_param)
{
	switch (card_param)
	{
	case 0:
		player.push_back("Clubs");
		break;

	case 1:
		player.push_back("Diamonds");
		break;

	case 2:
		player.push_back("Hearts");
		break;

	case 3:
		player.push_back("Spades");
		break;

	default:
		break;
	}
}

void Hand::set_dealer_val(int card_param)
{
	switch (card_param)
	{

	}
}

void Hand::set_player_val(int card_param)
{
	player_val.push_back(card_param);
}

/*
Hand& Hand::operator++()
{
	return *this;
}
*/

int main()
{
	srand(time(0));

	char command;

	int dealer_suit, dealer_rank;
	int player_suit, player_rank;

	vector<string> dealer_s;
	vector<int> dealer_r;
	vector<int>rankk;
	
	vector<string> player_s;
	vector<int> player_r;
	vector<int> prank;

	char play = 'y';

	cout << "Blackjack" << endl << endl;

	Hand d, p;
	Card d2, p2;

	while (play == 'y')	
	{
		dealer_s.clear();
		dealer_r.clear();
		rankk.clear();

		player_s.clear();
		player_r.clear();
		prank.clear();

		cout << "DEALER'S SHOW CARD:\n";
		dealer_suit = rand() % 4;
		d2.set_suit(dealer_suit);
		string x = d2.get_suit();
		dealer_s.push_back(x);

		dealer_rank = (rand() % 13) + 2;
		d2.set_rank(dealer_rank);
		rankk.push_back(dealer_rank);

		if (dealer_rank == 11 || dealer_rank == 12 || dealer_rank == 13)
		{
			dealer_rank = 10;
		}
		if (dealer_rank == 14)
		{
			dealer_rank = 11;
		}

		dealer_r.push_back(dealer_rank);


		cout << d2.get_rank() << " of " << d2.get_suit() << endl;

		dealer_suit = rand() % 4;
		d2.set_suit(dealer_suit);
		x = d2.get_suit();
		dealer_s.push_back(x);

		dealer_rank = (rand() % 13) + 2;
		d2.set_rank(dealer_rank);
		rankk.push_back(dealer_rank);
		if (dealer_rank == 11 || dealer_rank == 12 || dealer_rank == 13)
		{
			dealer_rank = 10;
		}
		if (dealer_rank == 14)
		{
			dealer_rank = 11;
		}

		dealer_r.push_back(dealer_rank);

		cout << "\nYOUR CARDS:\n";

		for (int i = 0; i < 2; i++)
		{
			player_suit = rand() % 4;
			p2.set_suit(player_suit);
			string g = p2.get_suit();
			player_s.push_back(g);

			player_rank = (rand() % 13) + 2;
			p2.set_rank(player_rank);
			prank.push_back(player_rank);

			if (player_rank == 11 || player_rank == 12 || player_rank == 13)
			{
				player_rank = 10;
			}
			if (player_rank == 14)
			{
				player_rank = 11;
			}
			player_r.push_back(player_rank);

			cout << p2.get_rank() << " of " << p2.get_suit() << endl;

		}

		int n, j = 0;
		int k = 0;

		do
		{
			cout << "\nHit or stand? (h/s): ";
			cin >> command;

			if (command == 's')
			{
				n = dealer_r.size();

				cout << "\nDEALER'S CARDS:\n";
				for (int i = 0; i < n; i++)
				{
					k = rankk.at(i);
					d2.set_rank(k);
					cout << d2.get_rank() << " of " << dealer_s.at(i) << endl;
				}

				for (int i = 0; i < n; i++)
				{
					j += dealer_r.at(i);
				}

				if (j >= 21)
				{
					break;
				}
			}
			else
			{
				player_suit = rand() % 4;
				p2.set_suit(player_suit);
				string g = p2.get_suit();
				player_s.push_back(g);

				player_rank = (rand() % 13) + 2;
				p2.set_rank(player_rank);
				prank.push_back(player_rank);

				if (player_rank == 11 || player_rank == 12 || player_rank == 13)
				{
					player_rank = 10;
				}
				if (player_rank == 14)
				{
					player_rank = 11;
				}

				player_r.push_back(player_rank);

				n = player_r.size();

				cout << "\nYOUR CARDS: \n";
				for (int i = 0; i < n; i++)
				{
					j = prank.at(i);
					p2.set_rank(j);
					cout << p2.get_rank() << " of " << player_s.at(i) << endl;
				}

				dealer_suit = rand() % 4;
				d2.set_suit(dealer_suit);
				string x = d2.get_suit();
				dealer_s.push_back(x);

				dealer_rank = (rand() % 13) + 2;
				d2.set_rank(dealer_rank);
				if (dealer_rank == 11 || dealer_rank == 12 || dealer_rank == 13)
				{
					dealer_rank = 10;
				}

				if (dealer_rank == 14)
				{
					dealer_rank = 11;
				}

				dealer_r.push_back(dealer_rank);

				for (int i = 0; i < n; i++)
				{
					j += player_r.at(i);
					k += dealer_r.at(i);
				}

				if (j >= 21 || k >= 21)
				{
					break;
				}
			}

		} while (command == 'h');

		n = player_r.size();
		j = 0;
		k = 0;

		for (int i = 0; i < n; i++)
		{
			j += player_r.at(i);
		}

		n = dealer_r.size();
		
		for (int i = 0; i < n; i++)
		{
			k += dealer_r.at(i);
		}

		cout << "\n\nYOUR POINTS\t: " << j << endl;
		cout << "DEALER'S POINTS: " << k << endl;

		if (j > 21 && k <= 21)
		{
			cout << "\nThe dealer won. You lost"<<endl;
		}

		if (k > 21 && j <= 21)
		{
			cout << "Yay! The dealer busted. You win!" << endl << endl;
		}

		if (k > j && j < 21 && k <= 21)
		{
			cout << "\nThe dealer won. You lost"<<endl;
		}

		if (j > k && k < 21 && j <= 21)
		{
			cout << "Yay! The dealer busted. You win!" << endl << endl;
		}

		if (j == k)
		{
			cout << "Tied\n\n";
		}

		cout << "\nPlay again? (y/n): ";
		cin >> play;

		

	}

	cout << "\nCome back soon!";

}
