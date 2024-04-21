#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define TESTING true

// Card suits
#define SPADES      0x80    // Spades are 1000 0001 through 1000 1101
#define DIAMONDS    0x40    // Diamonds are 0100 0001 through 0100 1101
#define CLUBS       0x20    // Clubs are 0010 0001 through 0010 1101
#define HEARTS      0x10    // Hearts are 0001 0001 through 0001 1101
#define CARD_SUITS  {SPADES,DIAMONDS,CLUBS,HEARTS}

// Card ranks
#define KING        0xD       // 1101 or 13
#define QUEEN       0xC       // 1100 or 12
#define JACK        0xB       // 1011 or 11
#define TEN         0xA       // 1010 or 10
#define NINE        0x9       // 1001 or 9
#define EIGHT       0x8       // 1000 or 8
#define SEVEN       0x7       // 0111 or 7
#define SIX         0x6       // 0110 or 6
#define FIVE        0x5       // 0101 or 5
#define FOUR        0x4       // 0100 or 4
#define THREE       0x3       // 0011 or 3
#define TWO         0x2       // 0010 or 2
#define ACE         0x1       // 0001 or 1
#define NO_CARD     0x0       // 0000 - Missing card from hand or deck 
#define CARD_RANKS  {ACE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING}

#define DECK_SIZE 52
#define HAND_SIZE 3                 // Two on deal plus one possible 'hit'
#define BUSTED -1                   // Hands with a value over 21 are 'busted'

//deck
void make_deck(int* deck_ptr);
void swap_card_position(int* card_ptr1, int* card_ptr2);
void shuffle(int* deck_ptr);
int deal_card(int* deck_ptr);
void fan_deck(int* deck_ptr);
//hand
int get_hand_value(int* hand_ptr);
bool hand_has_ace(int* hand_ptr);
//cards
int get_card_suit(int* card_ptr);
char get_card_suit_char(int suit);
int get_card_rank(int* card_ptr);
char get_card_rank_char(int rank);
void show_card(int* card_ptr);
int get_card_face_value(int* card_ptr);
