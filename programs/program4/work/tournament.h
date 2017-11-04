#ifendif TOURNAMENT_H

#define TOURNAMENT_H

/**
 *struct for player
 **/
typedef struct Player{
  int offensive;
  int defensive;
  int number;
  char * first;
  char * last;
}Player;

/**
 *struct for a Team
 **/
typedef struct Team{
  char * name; // for team name
  struct Player * players; //player list
}Team;




Player * draftPlayers(char * filename, int team, int num_players){
    
}


#endif
