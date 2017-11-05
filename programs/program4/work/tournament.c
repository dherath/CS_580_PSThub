#include "tournament.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

/**
 *Constructor for a team
 *@return pointer to  Team
 **/
Team * newTeam(){
  Team * new_t = malloc(sizeof(Team));
  new_t -> name = NULL;
  new_t -> players = newPlayer();
  return new_t;
}

/**
 *frees memory for a team
 **/
void deleteTeam(Team * t){
  free(t->name);
  //for(int i=0;i<10;i++)
  //  deletePlayer(t.players[i]);
  free(t);
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
  Player * playerList = NULL;
  int count = 0 ; // count of number of players
  // Player * draftp = newPlayer(); // get new player
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
    int teamNumber = atoi(value[0]);
    if(teamNumber == team){
      Player * draftp = newPlayer();
      draftp -> team = teamNumber ;
      draftp -> first = value[1];
      draftp -> last = value[2];
      draftp -> number = atoi(value[3]);
      draftp -> offensive = atoi(value[4]);
      draftp -> defensive = atoi(value[5]);
      printf("%d %s %s %d %d %d\n",draftp->team,draftp->first,draftp->last,draftp->number,draftp->offensive,draftp->defensive);
      
      playerList = draftp;
      //playerList++;
      //count++;

      printf("after adding \n");

      //  printf("%d %s %s %d %d %d\n",playerList->team,playerList->first,playerList->last,playerList->number,playerList->offensive,playerList->defensive);

      // printf("done adding\n");
      printf("\n\n");
      playerList++;
      
    }
  
  }
  //----------------------------------------------------
  //free(token);
  //free(value);
  //free(FILE);
  // deletePlayer(draftp);
  //----------------------------------------------------
  while(playerList != NULL){
     printf("%d %s %s %d %d %d\n",playerList->team,playerList->first,playerList->last,playerList->number,playerList->offensive,playerList->defensive);
     playerList++;
  }
  
  return playerList;
}

Team * initializeTeam(char * name , Player * players){
  Team * new_t = newTeam();
  new_t -> name = name;
  new_t -> players = players;
  return new_t;
    
}

