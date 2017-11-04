#include "tournament.h"

/**
 * Creates a new empty player struct
 *@return an empty Player struct
 **/
Player * newPlayer(){
  Player * new_p = malloc(sizeof(Player));
  new_p -> offensive = 0;
  new_p -> defensive = 0;
  new_p -> number = 0;
  new_p -> team = 0;
  new_p -> first = NULL;
  new_p -> last = NULL;
  return new_p;
}

/**
 *frees memory of a player struct
 **/
void deletePlayer(Player * p){
  free(p->first);
  free(p->last);
  free(p);
}


//---------- main functions--------------------------------------

/**
 *drafts a team of given players
 *@param *filename, the char pointer to file name
 *@param team, the team number
 *@param num_players, the number of players per team
 *@return pointer to array of players
 **/
Player * draftPlayers(char * filename, int team, int num_players){
  struct Player playeList[num_players];
  int count = 0 ; // count of number of players
  Player * draftp = newPlayer(); // get new player
  //----------------------------------------------------
  FILE * file = fopen(filename,"r");
  char line[256];
  //--------- read until eof----------------------------
  while(fgets(line,sizeof(line),file)){
    char * token;
    char * value[6];
    token = strtok(line,",");
    //--------tokenize and add values -------------------
    for(int i=0;i<6 && token !=NULL;i++){
      value[i] = token;
      token = strtok(NULL,",");
    }
    //---------- add if team number matches -------------
    int teamNumber = atoi(values[0]);
    if(teamNumber == team){
      draftp -> team = reamNumber ;
      draftp -> first = value[1];
      draftp -> last = value[2];
      draftp -> number = atoi(value[3]);
      draftp -> offensive = atoi(value[4]);
      draftp -> defensive = atoi(value[5]);

      playerList[count] = draftp;
      count++;
    }    
  }
  //----------------------------------------------------
  free(token);
  free(value);
  free(FILE);
  deletePlayer(draftp);
  //----------------------------------------------------
  return playerList;
}

