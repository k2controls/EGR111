#include "sblackjack.h"

//decks
void make_deck(int* deck_ptr)
{
    //DECK_SIZE = 52 (no jokers)
    //See this link for required cards and order
    //https://ambitiouswithcards.com/new-deck-order/
    //for loops required
    
    // #TODO

}

void swap_card_position(int* card_ptr1, int* card_ptr2)
{
    //swaps cards located at ptr1 and ptr2
   
    // #TODO
  
}

void shuffle(int* deck_ptr)
{
    //shuffles deck by swapping random cards 100 times
    int card_index1, card_index2;
    int* ptr_card1; 
    int* ptr_card2;

    srand(time(NULL));          // initialize random number. 
    
    for (int i=0; i<100; i++)
    {
        card_index1 = rand()%DECK_SIZE;
        card_index2 = rand()%DECK_SIZE;
        ptr_card1 = deck_ptr+card_index1;
        ptr_card2 = deck_ptr+card_index2;
        swap_card_position(ptr_card1, ptr_card2);
    }
}

int deal_card(int* deck_ptr)
{
    //searches deck for first non-NO_CARD
    // returns card value to caller and 
    // removes this card from deck by setting position to NO_CARD
   
    // #TODO
  
}

void fan_deck(int* deck_ptr)
{
    //uses show_card function to display all 52 cards
   
    // #TODO

}

int get_hand_value(int* hand_ptr)
{
    // return hand value based on card face value
    // corrects for aces if bust (uses alternate ace 
    // value of 1 rather than 11)
   
    // #TODO
  
}

bool hand_has_ace(int* hand_ptr)
{
    // returns true if hand contains an Ace.
   
    // #TODO
  
}

//cards
int get_card_suit(int* card_ptr)
{
    // returns card suit
       
    // #TODO
  
}

char get_card_suit_char(int suit)
{
    //return suit character
    char card_suit;

    switch(suit)
    {
        case NO_CARD:
            card_suit = ' ';
            break;
        case SPADES:
            card_suit = 'S';
            break;
        case DIAMONDS:
            card_suit = 'D';
            break;
        case CLUBS:
            card_suit = 'C';
            break;
        case HEARTS:
            card_suit = 'H';
            break;
    }
    return card_suit;
}

int get_card_rank(int* card_ptr)
{
    // returns card rank
       
    // #TODO
}

char get_card_rank_char(int rank)
{
    // returns rank character
    char card_char;

    switch(rank)
    {
        case KING:
            card_char = 'K';
            break;
        case QUEEN:
            card_char = 'Q';
            break;
        case JACK:
            card_char = 'J';
            break;
        case TEN:
            card_char = 'T';
            break;
        case NINE:
            card_char = '9';
            break;
        case EIGHT:
            card_char = '8';
            break;
        case SEVEN:
            card_char = '7';
            break;
        case SIX:
            card_char = '6';
            break;
        case FIVE:
            card_char = '5';
            break;
        case FOUR:
            card_char = '4';
            break;
        case THREE:
            card_char = '3';
            break;
        case TWO:
            card_char = '2';
            break;
        case ACE:
            card_char = 'A';
            break;
        case NO_CARD:
            card_char = ' ';
    }
    return card_char;
}
        
void show_card(int* card_ptr)
{
    int rank = get_card_rank(card_ptr);
    char rank_char = get_card_rank_char(rank);
    int suit = get_card_suit(card_ptr);
    char suit_char = get_card_suit_char(suit);
    printf("%c%c", rank_char, suit_char);
}

int get_card_face_value(int* card_ptr)
{
    // returns card value
    // Aces are 11, facecards (K,Q,J) are 10
    // others - value = rank (e.g. 9H = 9)

    // #TODO

}
