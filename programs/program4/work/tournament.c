#include "tournament.h"

PLayer * newPlayer(){
  Player * new_p = malloc(sizeof(Player));
  new_p -> offensive = 0;
  new_p -> defensive = 0;
  new_p -> number = 0;
  new_p -> first = NULL;
  new_p -> last = NULL;
}

Player * draftPlayers(char * filename, int team, int num_players){
  Player * draftp = newPlayer(); // get new player
  
}

