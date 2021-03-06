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
  new_t -> players = NULL;
  return new_t;
}

/**
 *frees memory for a team
 **/
void deleteTeam(Team * t){
  for(int i=0;i<10;i++){
    free((t->players[i].first));
    free((t->players[i].last));
  }
  free(t->players);
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

  Player * playerList = malloc(sizeof(Player)*num_players);
  int count = 0 ; // count of number of players
  //----------------------------------------------------
  FILE * file = fopen(filename,"r");
  char line[256];
  char * token;
  char * value[6];
  //--------- read until eof----------------------------
  while(fgets(line,sizeof(line),file)){
    token = strtok(line,",");
    //--------tokenize and add values -------------------
    for(int i=0;i<6 && token !=NULL;i++){
      value[i] = token;
      token = strtok(NULL,",");
    }
    //---------- add if team number matches -------------
    int teamNumber = atoi(value[0]);
    if(teamNumber == team){
      playerList[count].team = teamNumber ;
      playerList[count].first = malloc(strlen(value[1])*sizeof(char));
      for(int s1=0;s1<strlen(value[1]);s1++){
	playerList[count].first[s1] = value[1][s1];
      }
      playerList[count].last = malloc(strlen(value[2])*sizeof(char));
      for(int s2=0;s2<strlen(value[2]);s2++){
	playerList[count].last[s2] = value[2][s2];
      }
      playerList[count].number = atoi(value[3]);
      playerList[count].offensive = atoi(value[4]);
      playerList[count].defensive = atoi(value[5]);
      count++;
    }
  }
  fclose(file);
  /* printf("\n");
     for(int i=0;i<10;i++){    
     printf("%d %s %s %d %d %d\n",playerList[i].team,playerList[i].first,playerList[i].last,playerList[i].number,playerList[i].offensive,playerList[i].defensive);
     }*/
  return playerList;
}


/**
 *initilizes a Team
 *@param name, the name of the team
 *@param players, all the players fo the team
 *@return the Team
 **/
Team * initializeTeam(char * name , Player * players){
  Team * new_t = newTeam();
  new_t -> name = name;
  new_t -> players = players;
  return new_t;    
}

/**
 *plays the game between two teams
 *@param t1, the first team 
 *@param t2, the second team
 *@return the winning team
 **/
Team * game(Team * t1, Team * t2){

  if (t1==NULL && t2==NULL) return NULL;
  if (t1==NULL) return t2;
  if (t2==NULL) return t1;
  if(strcmp(t1->name,t2->name)==0) return t1;
  
  // the random generated value is compared
  // with respect to the defensive teams player of the ith round

  //----------total offensive power of teams--------
  int tot_off_team1 = 0;
  int tot_off_team2 = 0;
  for (int i = 0 ;i < 10 ; i++){
    tot_off_team1 += t1->players[i].offensive;
    tot_off_team2 += t2->players[i].offensive;  
  } 
  //-------- the game ------------------------------
  int score1 = 0;
  int score2 = 0;
  for(int i=0 ; i < 10 ; i++){
    int randV1 = rand() % tot_off_team1;
    int randV2 = rand() % tot_off_team2;
    if (randV1 >= t2->players[i].defensive){
      score1++ ;
    }
    if (randV2 >= t1->players[i].defensive){
      score2++ ;
    }
  }
  //----- comparison -------------------------------
  if (score1 > score2){
    return t1;
  }
  return t2;
}

/**
 *simulates a tournament between teams
 *@param tList, the list of teams
 *@param num_teams, the tot. number of teams
 *@return pointer to the winning team
 **/
Team * tournament(Team ** tList, int num_teams){
  int n = 2;
  int round = 1;
  while( num_teams > n){
    n = n*2;
    round++;
  }
  if( n != num_teams){
    printf("number of teams are invalid");
    return NULL;
  }
  int matchup[num_teams];
  for(int i=0;i<num_teams;i++){
    matchup[i] = i;
  }
  //---randomly swap indices for 100 times --------------
  for(int i=0;i<100;i++){
    int pos1 = rand() % num_teams;
    int pos2 = rand() % num_teams;
    int temp = matchup[pos2];
    matchup[pos2] = matchup[pos1];
    matchup[pos1] = temp;
  }  
  //----------making teams play--------------------------
  struct Team *t = tList[matchup[0]];
  for(int i=1; i<num_teams ; i++){
    t = game(t,tList[matchup[i]]);
  }
  return t;    
}

