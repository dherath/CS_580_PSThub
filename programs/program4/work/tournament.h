#ifndef TOURNAMENT_H 

#define TOURNAMENT_H 

#pragma pack(1)

// Name - Jerome Dinal Herath Muthukumarnage
// B no - B00708543


/*
the team names were increased from 16 to 32
*/


/**
 *struct for player
 **/
typedef struct Player{
  int offensive;
  int defensive;
  int number;
  int team;
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

Player * newPlayer();
void deltePlayer(Player * p);
Player * draftPlayers(char * filename, int team, int num_players);

Team * newTeam();
void deleteTeam(Team * t);
Team * initializeTeam(char * name, Player * players);

Team * game(Team * t1, Team * t2);
Team * tournament(Team ** tList, int num_teams);

#endif
