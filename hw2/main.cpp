#include <iostream>
#include <cstdlib>
#include <time.h>

#include "hand.h"
using namespace std;

int main(int argc, char **argv)
{

    List_linked_list ll;

    Card c('A','D');

    ll.insert_at_index(c,0);

    c.set_suit(HEART);
    c.set_rank(TEN);
    ll.insert_at_index(c,0);

    c.set_suit(SPADE);
    c.set_rank(FIVE);
    ll.insert_at_index(c,0);

    c.set_suit(CLUB);
    c.set_rank(TWO);
    ll.insert_at_index(c,0);

    c.set_rank(NINE);
    ll.insert_at_index(c,0);

    c.set_suit(HEART);
    c.set_rank(FOUR);
    ll.insert_at_index(c,0);
    ll.print_list();

    for (int i=0;i<6;i++) {
	cout << "Removed ";
	ll.remove_from_tail().print_card();
	cout << "\n";
	ll.print_list();
    }

    return 0;






/*	Hand deck, deck2, hand1, hand2;
	List_linked_list list;
//	deck.create_deck();
	//deck.read_deck();
//	deck.print_hand();

	Card c('3','H');

	//deck.remove_card(c);

//	deck.shuffle();
//	deck.print_hand_int();

	for (int i=0;i<5;i++) {
//		deck.deal_card_from_top(hand1);
//		deck.deal_card_from_top(hand2);
	}
//	hand1.order_hand_by_suit();
//	hand2.order_hand_by_suit();
//	deck.print_hand();

	Card d('5', 'S');
	Card f('7', 'D');
	Card g('8', 'C');
        c.set_suit(HEART);
        c.set_rank(TEN);
	list.insert_at_head(f);
//	list.insert_at_tail(g);
//      list.insert_at_tail(c);
	list.insert_at_head(c);
//	list.insert_at_tail(d);
	list.insert_at_index(f,1);
	list.insert_at_tail(c);
	list.print_list();
	list.replace_at_index(g, 1);
	list.print_list();
	list.remove_from_tail();
	//std::cout << "Cards in hand: " << list.cards_in_hand() << "\n";
	list.remove_from_head();
	list.print_list();
	list.remove_from_index(2);
//	list.make_empty();
	list.print_list();
//	std::cerr<<"after emptied";
//	hand1.print_hand();
//	hand2.print_hand();
return 0;*/

}
