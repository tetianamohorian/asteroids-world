#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "world.h"

#define ASTEROID_COUNT 7
#define BULLET_COUNT 10

 
struct Point
{
	double x;
	double y;
};

struct Player
{
   struct  Point position;
};

struct Asteroid
{
   struct  Point position;
   int direction;
   bool isLive;
};

struct Bullet
{
   struct  Point position;
   bool isActive;
};

struct Game
{
   struct  Player player;
   struct  Asteroid asteroid[ASTEROID_COUNT];
   struct  Bullet bullet[BULLET_COUNT];
   int score;
   int lives;
   bool gameOver;
};




void* init_game_level_1();

void* init_game_level_2();

void* init_game_level_3();


int world_event(struct event* event,void* game);

void draw_game(struct Game *game,struct event* event);

#endif




