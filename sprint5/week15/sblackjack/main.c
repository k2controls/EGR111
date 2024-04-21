// Simple Blackjack in C
// Two cards dealt. Player and dealer can take a single 'hit' 
// for a total hand card count of 3.
// Keith E Kelly
// 4/18/24
#include "sblackjack.h"

#if !TESTING

int main()
{
    int this_deck[DECK_SIZE];   //cards in deck are int values. See header file for value definitions.
    int player_hand[HAND_SIZE]; //hand has up to 3 cards. You get two with the deal and can 'hit' once.
    int dealer_hand[HAND_SIZE]; //hand has up to 3 cards. Dealer get two and must take a third if hand value is < 17.
    char hit;                   //
    int player_hand_value;      //sum of cards in hand. See header file for card values. Aces are 1 or 11.
    int dealer_hand_value;      //sum of cards in hand. See header file for card values. Aces are 1 or 11.

    printf("\nWelcome to Simple BlackJack in C!\n\n");
    printf("Get as close to 21 as you can without going over.\n");
    printf("But in this Simple BlackJack!\n");
    printf("You only get to hit once, so there is a max of three cards.\n");
    printf("Dealer hits once if under 17. Aces count as 1 or 11.\n\n");

    make_deck(this_deck);
    fan_deck(this_deck);
    shuffle(this_deck);
    fan_deck(this_deck);
    player_hand[0] = deal_card(this_deck);
    player_hand[1] = deal_card(this_deck);
    player_hand[2] = NO_CARD;
    dealer_hand[0] = deal_card(this_deck);
    dealer_hand[1] = deal_card(this_deck);
    dealer_hand[2] = NO_CARD;

    printf("Your hand...\n");
    show_card(&player_hand[0]);
    printf(" ");
    show_card(&player_hand[1]);
    printf("\n");
    player_hand_value = get_hand_value(player_hand);
    printf("Player has %d.\n", player_hand_value);
    printf(">>>Dealer has this card showing...\n>>>");
    show_card(&dealer_hand[0]);
    printf("\n");
    printf("Press space bar to hit. Enter to stay.");
    // #TODO - implement player hit on space bar entry
    //*****************************************************

    //*****************************************************
    if (player_hand_value == BUSTED)
        printf("Player busts! Game over!\n");
    else
    {
        printf("\n>>>Dealer's hand...\n>>>");
        show_card(&dealer_hand[0]);
        printf(" ");
        show_card(&dealer_hand[1]);
        printf("\n");
        dealer_hand_value = get_hand_value(dealer_hand);
        printf(">>>Dealer has %d.\n", dealer_hand_value);
        // #TODO - implement dealer hit if hand value is less than 17.
        //*************************************************
 
        //*************************************************
        if (dealer_hand_value == BUSTED)
            printf("Dealer busts! Player wins!\n");
        else if (player_hand_value > dealer_hand_value)
            printf("Player wins!\n\n");
        else if (player_hand_value < dealer_hand_value)
            printf("Dealer wins.\n\n");
        else
            printf("Push.\n\n");    
        
    }
    return 0;
}
#endif