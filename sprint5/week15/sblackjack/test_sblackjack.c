#include "sblackjack.h"

#if TESTING
#include "acutest.h"

void can_make_deck()
{
    // Function creates a 52 card deck using for loops.
    // The card order must match that specified on this
    // site: https://ambitiouswithcards.com/new-deck-order/
    // No joker cards are included.
    int my_deck[DECK_SIZE];
    int* my_deck_ptr = &my_deck[0];
    make_deck(my_deck_ptr);
    TEST_CHECK(my_deck[0]  == 0b10000001);  //ace of spades
    TEST_CHECK(my_deck[12] == 0b10001101);  //king of spades
    TEST_CHECK(my_deck[13] == 0b01000001);  //ace of diamonds
    TEST_CHECK(my_deck[25] == 0b01001101);  //kihg of diamonds
    TEST_CHECK(my_deck[26] == 0b00101101);  //king of clubs
    TEST_CHECK(my_deck[38] == 0b00100001);  //ace of clubs
    TEST_CHECK(my_deck[39] == 0b00011101);  //king of hearts
    TEST_CHECK(my_deck[51] == 0b00010001);  //ace of hearts
}

void can_swap_card_position()
{
    int my_deck[DECK_SIZE];
    int* my_deck_ptr = &my_deck[0];
    make_deck(my_deck_ptr);
    int* p_card1 = my_deck_ptr;             //first card is ace of spaces
    TEST_CHECK(*p_card1 == 0b10000001);     //ace of spades 
    int* p_card2 = my_deck_ptr+51;          //last card is ace of hearts
    TEST_CHECK(*p_card2 == 0b00010001);     //ace of hearts
    swap_card_position(p_card1, p_card2);
    //swapped?
    TEST_CHECK(*p_card1 == 0b00010001);     //ace of hearts?
    TEST_CHECK(*p_card2 == 0b10000001);     //ace of spaces?
}

void can_check_new_deck_is_not_shuffled()
{
    // Test by checking first three cards in each suit.
    // Cards should be sequential in new deck.
    // Clubs and hearts are in descending order. 
    int my_deck[DECK_SIZE];
    make_deck(my_deck);

    int suit_offset = 0*13;    //check spade sequence - ascending
    TEST_CHECK(my_deck[suit_offset]+1==my_deck[suit_offset+1]);
    TEST_CHECK(my_deck[suit_offset]+2==my_deck[suit_offset+2]);
    TEST_CHECK(my_deck[suit_offset]+3==my_deck[suit_offset+3]);
    suit_offset = 1*13;       //check diamond sequence - ascending
    TEST_CHECK(my_deck[suit_offset]+1==my_deck[suit_offset+1]);
    TEST_CHECK(my_deck[suit_offset]+2==my_deck[suit_offset+2]);
    TEST_CHECK(my_deck[suit_offset]+3==my_deck[suit_offset+3]);
    suit_offset = 2*13;       //check club sequence - decending
    TEST_CHECK(my_deck[suit_offset]-1==my_deck[suit_offset+1]);
    TEST_CHECK(my_deck[suit_offset]-2==my_deck[suit_offset+2]);
    TEST_CHECK(my_deck[suit_offset]-3==my_deck[suit_offset+3]);
    suit_offset = 3*13;       //check heart sequence - decending
    TEST_CHECK(my_deck[suit_offset]-1==my_deck[suit_offset+1]);
    TEST_CHECK(my_deck[suit_offset]-2==my_deck[suit_offset+2]);
    TEST_CHECK(my_deck[suit_offset]-3==my_deck[suit_offset+3]);
}

void can_check_deck_is_shuffled()
{
    // Test by checking cards in deck.
    // No more than two cards can have a sequential card in next position. 
    int my_deck[DECK_SIZE];
    int cards_in_sequence = 0;
    make_deck(my_deck);
    shuffle(my_deck);    

    int suit_offset = 0*13;    //check first quarter
    (my_deck[suit_offset]+1==my_deck[suit_offset+1])? cards_in_sequence++: cards_in_sequence ;
    (my_deck[suit_offset]+2==my_deck[suit_offset+2])? cards_in_sequence++: cards_in_sequence ;
    (my_deck[suit_offset]+3==my_deck[suit_offset+3])? cards_in_sequence++: cards_in_sequence ;
    suit_offset = 1*13;       //check second quarter
    (my_deck[suit_offset]+1==my_deck[suit_offset+1])? cards_in_sequence++: cards_in_sequence ;
    (my_deck[suit_offset]+2==my_deck[suit_offset+2])? cards_in_sequence++: cards_in_sequence ;
    (my_deck[suit_offset]+3==my_deck[suit_offset+3])? cards_in_sequence++: cards_in_sequence ;
    suit_offset = 2*13;       //check third quarter
    (my_deck[suit_offset]-1==my_deck[suit_offset+1])? cards_in_sequence++: cards_in_sequence ;
    (my_deck[suit_offset]-2==my_deck[suit_offset+2])? cards_in_sequence++: cards_in_sequence ;
    (my_deck[suit_offset]-3==my_deck[suit_offset+3])? cards_in_sequence++: cards_in_sequence ;
    suit_offset = 3*13;       //check fourth quarter
    (my_deck[suit_offset]-1==my_deck[suit_offset+1])? cards_in_sequence++: cards_in_sequence ;
    (my_deck[suit_offset]-2==my_deck[suit_offset+2])? cards_in_sequence++: cards_in_sequence ;
    (my_deck[suit_offset]-3==my_deck[suit_offset+3])? cards_in_sequence++: cards_in_sequence ;

    TEST_CHECK(cards_in_sequence<3);
}    

void can_deal_card()
{
    // deal_card() returns the value of the next card
    // in the deck. Dealt card location in the deck is 
    // replaced with a NO_CARD (zero) value. So next card 
    // is always the first non-zero value.
    int my_deck[DECK_SIZE];
    make_deck(my_deck);
    shuffle(my_deck);
    int card0 = my_deck[0];
    int card1 = my_deck[1];
    int draw_card0 = deal_card(my_deck);
    int draw_card1 = deal_card(my_deck);
    TEST_CHECK(card0 == draw_card0);
    TEST_CHECK(card1 == draw_card1);
    TEST_CHECK(my_deck[0] == NO_CARD);    //dealt card position contains NO_CARD 0 value.
    TEST_CHECK(my_deck[1] == NO_CARD);    //dealt card position contains NO_CARD 0 value.
    //next card in deck
    TEST_CHECK(my_deck[2] != NO_CARD);    //next card position is not zero.
}

void can_show_card()
{
    // show_card is not testable.
    // Displays first two cards.
    // Displays NO_CARD spaces. 
    // Displays last card in deck.
    int my_deck[DECK_SIZE];
    make_deck(my_deck);
    deal_card(my_deck);                 // remove first card - NO_CARD
    show_card(&my_deck[0]);             // ptr to NO_CARD
    printf(",");
    show_card(&my_deck[1]);             // ptr to second card
    printf(",");
    show_card(&my_deck[DECK_SIZE-1]);    //ptr to last card
    printf("\n");
    TEST_CHECK(true);       //not testable. Always returns pass. Validate output in terminal.
}

void can_fan_new_deck()
{
    // fan_deck is not testable. Displays the new
    // deck in the test terminal.
    int my_deck[DECK_SIZE];
    make_deck(my_deck);
    fan_deck(my_deck);  // Check terminal window for display
    TEST_CHECK(true);   // Not testable. Always returns pass.
}

void can_fan_shuffled_deck()
{
    // fan_deck is not testable. Displays shuffled
    // deck in the test terminal.
    int my_deck[DECK_SIZE];
    make_deck(my_deck);
    shuffle(my_deck);   
    fan_deck(my_deck);  // Check terminal window for display
    TEST_CHECK(true);   // Not testable. Always returns pass.
}

void can_get_card_rank()
{
    // Card rank returned for sample cards. 
    int card1 = DIAMONDS | ACE;     // Ace of diamonds
    int card2 = SPADES | KING;      // King of spades
    int card3 = HEARTS | QUEEN;     // Queen of hearts
    int card4 = CLUBS | TEN;        // Ten of clubs
    int card5 = HEARTS | SIX;       // 6 of hearts
    int card6 = NO_CARD;            // Empty or missing card from hand or deck
    int rank1 = get_card_rank(&card1);
    int rank2 = get_card_rank(&card2);
    int rank3 = get_card_rank(&card3);
    int rank4 = get_card_rank(&card4);
    int rank5 = get_card_rank(&card5);
    int rank6 = get_card_rank(&card6);
    TEST_CHECK(rank1==ACE);
    TEST_CHECK(rank2==KING);
    TEST_CHECK(rank3==QUEEN);
    TEST_CHECK(rank4==TEN);
    TEST_CHECK(rank5==SIX);
    TEST_CHECK(rank6==NO_CARD);
}

void can_get_card_rank_char()
{
    // Card rank character returned for sample ranks. 
    int rank1 = ACE;     
    int rank2 = KING;      
    int rank3 = QUEEN;
    int rank4 = JACK;         
    int rank5 = TEN;
    int rank6 = SIX;         
    char c1 = get_card_rank_char(rank1);
    char c2 = get_card_rank_char(rank2);
    char c3 = get_card_rank_char(rank3);
    char c4 = get_card_rank_char(rank4);
    char c5 = get_card_rank_char(rank5);
    char c6 = get_card_rank_char(rank6);
    TEST_CHECK(c1=='A');
    TEST_CHECK(c2=='K');
    TEST_CHECK(c3=='Q');
    TEST_CHECK(c4=='J');
    TEST_CHECK(c5=='T');
    TEST_CHECK(c6=='6');
}

void can_get_card_suit()
{
    // Card suit returned for sample cards.
    int card1 = DIAMONDS | ACE;     // Ace of diamonds
    int card2 = HEARTS | SIX;       // 6 of hearts
    int card3 = SPADES | KING;      // King of spades
    int card4 = CLUBS | TEN;        // Ten of clubs
    int card5 = NO_CARD;            // Empty or missing card from hand or deck
    int suit1 = get_card_suit(&card1);
    int suit2 = get_card_suit(&card2);
    int suit3 = get_card_suit(&card3);
    int suit4 = get_card_suit(&card4);
    int suit5 = get_card_suit(&card5);
    TEST_CHECK(suit1==DIAMONDS);
    TEST_CHECK(suit2==HEARTS);
    TEST_CHECK(suit3==SPADES);
    TEST_CHECK(suit4==CLUBS);
    TEST_CHECK(suit5==NO_CARD);
}

void can_get_card_suit_char()
{
    // Card suit character returned for suits.
    int suit1 = DIAMONDS;     
    int suit2 = HEARTS;      
    int suit3 = SPADES;
    int suit4 = CLUBS;         
    char c1 = get_card_suit_char(suit1);
    char c2 = get_card_suit_char(suit2);
    char c3 = get_card_suit_char(suit3);
    char c4 = get_card_suit_char(suit4);
    TEST_CHECK(c1=='D');
    TEST_CHECK(c2=='H');
    TEST_CHECK(c3=='S');
    TEST_CHECK(c4=='C');
}

void can_get_card_face_value()
{
    // Card "face value" returned for sample cards.
    // Aces are worth 11 but may be adjusted to 1 when hand value determined
    // Face cards (King, Queen, Jack) are worth 10.
    // Other cards worth numeric values (e.g 4 of clubs is worth 4)
    int card1 = DIAMONDS | ACE;     // Ace of diamonds
    int card2 = SPADES | KING;      // King of spades
    int card3 = HEARTS | QUEEN;     // Queen of hearts
    int card4 = CLUBS | TEN;        // Ten of clubs
    int card5 = HEARTS | SIX;       // 6 of hearts
    int card6 = NO_CARD;            // Empty or missing card from hand or deck
    int value1 = get_card_face_value(&card1);
    int value2 = get_card_face_value(&card2);
    int value3 = get_card_face_value(&card3);
    int value4 = get_card_face_value(&card4);
    int value5 = get_card_face_value(&card5);
    int value6 = get_card_face_value(&card6);
    TEST_CHECK(value1==11);
    TEST_CHECK(value2==10);
    TEST_CHECK(value3==10);
    TEST_CHECK(value4==10);
    TEST_CHECK(value5==6);
    TEST_CHECK(value6==0);      // Empty or missing card from hand or deck have zero value.
}

void can_get_hand_value()
{
    // Face cards are worth 10 and Aces are 11 unless
    // hand is over 21. Then Ace can be 1. Hands with a 
    // value over 21 must return BUSTED (-1).
    int ACE_OF_HEARTS = HEARTS | ACE;
    int KING_OF_DIAMONDS = DIAMONDS | KING;
    int TWO_OF_SPADES = SPADES | TWO;
    int SIX_OF_HEARTS = HEARTS | SIX;
    int JACK_OF_CLUBS = CLUBS | JACK;
    int my_hand[HAND_SIZE];
    int hand_value;

    // two card hand
    my_hand[0] = KING_OF_DIAMONDS;
    my_hand[1] = TWO_OF_SPADES;
    my_hand[2] = NO_CARD;
    hand_value = get_hand_value(my_hand);
    TEST_CHECK(hand_value == 12);

    // two card hand with Ace
    my_hand[0] = ACE_OF_HEARTS;
    my_hand[1] = TWO_OF_SPADES;
    my_hand[2] = NO_CARD;
    hand_value = get_hand_value(my_hand);
    TEST_CHECK(hand_value == 13);

    // three card hand with Ace
    my_hand[0] = ACE_OF_HEARTS;
    my_hand[1] = TWO_OF_SPADES;
    my_hand[2] = SIX_OF_HEARTS;
    hand_value = get_hand_value(my_hand);
    TEST_CHECK(hand_value == 19);

    // three card hand with Ace as 1 
    my_hand[0] = ACE_OF_HEARTS;
    my_hand[1] = JACK_OF_CLUBS;
    my_hand[2] = KING_OF_DIAMONDS;
    hand_value = get_hand_value(my_hand);
    TEST_CHECK(hand_value == 21);

    // three cards over 21 is busted.
    my_hand[0] = TWO_OF_SPADES;
    my_hand[1] = JACK_OF_CLUBS;
    my_hand[2] = KING_OF_DIAMONDS;
    hand_value = get_hand_value(my_hand);
    TEST_CHECK(hand_value == BUSTED);
    
    // Two Aces? Only one is adjusted to from 11 to 1
    my_hand[0] = ACE_OF_HEARTS;
    my_hand[1] = TWO_OF_SPADES;
    my_hand[2] = SPADES | ACE;
    hand_value = get_hand_value(my_hand);
    TEST_CHECK(hand_value == 14);
}

void can_check_hand_for_ace()
{
    int my_hand[HAND_SIZE];
        
    my_hand[0] = DIAMONDS | KING;
    my_hand[1] = HEARTS | TEN;
    my_hand[2] = NO_CARD;
    TEST_CHECK(!hand_has_ace(my_hand));
    my_hand[2] = SPADES | ACE;
    TEST_CHECK(hand_has_ace(my_hand));
}

// List of tests - key, value pairs with {NULL, NULL} termination.
TEST_LIST = {
    {"can make deck", can_make_deck},
    {"can swap card position in deck", can_swap_card_position},
    {"can check new deck is not shuffled", can_check_new_deck_is_not_shuffled},
    {"can check deck is shuffled", can_check_deck_is_shuffled},
    {"can deal card", can_deal_card},
    {"can show card", can_show_card},
    {"can fan new deck", can_fan_new_deck},
    {"can fan shuffled deck", can_fan_shuffled_deck},
    {"can get card rank", can_get_card_rank},
    {"can get card rank character", can_get_card_rank_char},
    {"can get card suit", can_get_card_suit},
    {"can get card suit character", can_get_card_suit_char},
    {"can get card face value", can_get_card_face_value},
    {"can get hand value", can_get_hand_value},
    {"can check hand for ace", can_check_hand_for_ace},

    { NULL, NULL }
};

#endif
