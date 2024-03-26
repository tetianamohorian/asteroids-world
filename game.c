#include "world.h"
#include "game.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


void* init_game_level_1()
{
    
    struct Game* game = (struct Game*)malloc(sizeof(struct Game));
    game_speed(2000);	
       
    game->player.position.x = 75;
    game->player.position.y = 1;

    
    for(int i = 0; i <ASTEROID_COUNT-4; i++)
    {
    	game->asteroid[i].position.x = 100 - i*5;
    	game->asteroid[i].position.y = 50 + i * 15;
    	game->asteroid[i].direction = 1;
    	game->asteroid[i].isLive = true;
    }

	

    for(int i = 0; i < BULLET_COUNT; i++)
    {
    	game->bullet[i].position.x = -1;
    	game->bullet[i].position.y = -1;
    	game->bullet[i].isActive = false;
    }

    game->score = 0;
    game->lives = 3;
    game->gameOver = false;

    
    return game;
}

void * init_game_level_2()
{
    struct Game* game = (struct Game*)malloc(sizeof(struct Game));

    game_speed(500);

    game->player.position.x = 50;
    game->player.position.y = 1;


    for(int i = 0; i <ASTEROID_COUNT-2; i++)
    {
        game->asteroid[i].position.x = 50 + i*5;
        game->asteroid[i].position.y = 50 + i * 10;
        game->asteroid[i].direction = 1;
        game->asteroid[i].isLive = true;
    }



    for(int i = 0; i < BULLET_COUNT; i++)
    {
        game->bullet[i].position.x = -1;
        game->bullet[i].position.y = -1;
        game->bullet[i].isActive = false;
    }


    game->lives = 3;
    game->gameOver = false;


    return game;
}

void * init_game_level_3()
{  
    struct Game* game = (struct Game*)malloc(sizeof(struct Game));

    game_speed(100);

    game->player.position.x = 80;
    game->player.position.y = 1;


    for(int i = 0; i <ASTEROID_COUNT; i++)
    {
        game->asteroid[i].position.x = 100 - i*5;
        game->asteroid[i].position.y = 20 + i*20;
        game->asteroid[i].direction = 1;
        game->asteroid[i].isLive = true;
    }



    for(int i = 0; i < BULLET_COUNT-3; i++)
    {
        game->bullet[i].position.x = -1;
        game->bullet[i].position.y = -1;
        game->bullet[i].isActive = false;
    }

    game->lives = 3;
    game->gameOver = false;


    return game;	
}

int world_event(struct event* event, void* game)
{
	struct Game *g = (struct Game*) game;
	
	switch(event->type)
        {
	   case EVENT_KEY:
           {
	      if(event->key == KEY_LEFT)
              {
		if(g->player.position.x > 1)
                {
			g->player.position.x =  g->player.position.x - 1;	
                }
		
              }

              else if(event->key == KEY_RIGHT)
              {
		if(g->player.position.x <= event->width-2)
                {
		    g->player.position.x =  g->player.position.x + 1;	    
                }	
              }

	     else if(event->key == ' ')
             {
		
		for(int i = 0; i < BULLET_COUNT; i++)
		{
			if(!g->bullet[i].isActive)
                	{
		   		g->bullet[i].isActive = true;
		   		g->bullet[i].position.x = g->player.position.x; 
	          		g->bullet[i].position.y = g->player.position.y+1;	
				break;
			}				     
                }
		
			

             }
		

           }
           break;
	  case EVENT_TIMEOUT:
	  break;
          default:
            break;
        }

	for(int i = 0; i < BULLET_COUNT; i++)
        {
		if(g->bullet[i].isActive)
        	{
	    		if(g->bullet[i].position.y == event->height -4)
            		{
				g->bullet[i].isActive = false;
			}	
            	}
	    	else 
	    	{
	    		g->bullet[i].position.y++;
	    	}
	    
        }

	int asteroidCount = 0;
	for(int i = 0; i < ASTEROID_COUNT; i++)
	{
		if (g->asteroid[i].isLive) 
        	{

				if(g->asteroid[i].position.y > 1 )
				{
        				g->asteroid[i].position.y  = g->asteroid[i].position.y - 1; 
				}

				else
				{	
			
 				g->lives -= 1;
				g->asteroid[i].isLive = false;
			        
		
					if(g->lives == 0)
					{
						g->gameOver = true;
                                                abort_game("You lose");						
						
					}

					
			 
		                 }  	 
    		
                   }	

		if(g->asteroid[i].isLive)
		{
			asteroidCount++;		
		}
	
	}
	
	
	for (int i = 0; i < BULLET_COUNT; i++)
        {
        	for (int j = 0; j < ASTEROID_COUNT; j++)
        	{
            		if (g->bullet[i].isActive && g->asteroid[j].isLive)
            		{
                		if (g->bullet[i].position.x == g->asteroid[j].position.x && g->bullet[i].position.y == g->asteroid[j].position.y)
                		{
                    			g->bullet[i].isActive = false;
                    			g->asteroid[j].isLive = false;
					g->score += 15; 
                		}
            		}
        	}

	}
	
	draw_game(g,event);


	char en = ' ';
        
	if(g->gameOver == false && asteroidCount == 0)
	{
		clear_screen();
		menu();	
		
		set_message("Congratulations, you won!", 64,15);
                set_message("Menu", 75,17);
                set_message("1. Level 1", 72,19);
                set_message("2. Level 2", 72, 20);
                set_message("3. Level 3", 72, 21);
		set_message("4. Exit", 72, 22);	
		
                en = get_key();

                switch(en)
                {
                                case '1':
                                        start_world(init_game_level_1, world_event, free);
                                break;
                                case '2':
                                        start_world(init_game_level_2, world_event, free);
                                break;
                                case '3':
                                        start_world(init_game_level_3, world_event, free);
                                break;
				case '4':
					abort_game("");
				break;
                        default:
                        break;
	        }
   }

                   
	usleep(100000);
	return 0;	
}

void draw_game(struct Game* game, struct event* event)
{
    for (int y = 0; y < event->height - 2; y++)
    {
        for (int x = 0; x < event->width - 2; x++)
        {
            if (x == game->player.position.x && y == game->player.position.y)
            {
                set_color_cell('P', x, y, 7, 2);
            }
            else
            {
                bool asteroidFound = false;
                bool bulletFound = false;

                for (int i = 0; i < ASTEROID_COUNT; i++)
                {
                    if (game->asteroid[i].isLive && x == game->asteroid[i].position.x && y == game->asteroid[i].position.y)
                    {
                        set_color_cell('A', x, y, 7, 1);
                        asteroidFound = true;
                        break;
                    }
                }
                if (!asteroidFound)
                {
                    for (int i = 0; i < BULLET_COUNT; i++)
                    {
                        if (game->bullet[i].isActive && x == game->bullet[i].position.x && y == game->bullet[i].position.y)
                        {

                            bulletFound = true;
                            break;
                        }
                    }
                    if (!bulletFound)
                    {
                        set_cell(' ', x, y);
                    }
                }
            }
        }
    }

    for (int i = 0; i < BULLET_COUNT; i++)
    {
        if (game->bullet[i].isActive)
        {
            set_cell(' ', game->bullet[i].position.x, game->bullet[i].position.y - 1);

            game->bullet[i].position.y++;

            if (game->bullet[i].position.y < event->height - 2)
            {
                bool asteroidHit = false;
                for (int j = 0; j < ASTEROID_COUNT; j++)
                {
                    if (game->asteroid[j].isLive && (game->bullet[i].position.x == game->asteroid[j].position.x && game->bullet[i].position.y == game->asteroid[j].position.y) /*|| (game->bullet[i].position.x == game->asteroid[j].position.x && game->bullet[i].position.y-1 == game->asteroid[j].position.y )|| (game->bullet[i].position.x == game->asteroid[j].position.x && game->bullet[i].position.y+1 == game->asteroid[j].position.y )*/ )
                    {
			game->score += 15;
                        asteroidHit = true;
			game->asteroid[j].position.y = event->height - 4; 
                        game->asteroid[j].isLive = false;
                        set_cell(' ', game->asteroid[j].position.x, game->asteroid[j].position.y);
                        set_cell(' ', game->bullet[i].position.x, game->bullet[i].position.y-1);
			
                        break;
                    }

                }

                if (asteroidHit)
                {
		            game->bullet[i].position.y = event->height - 4; 
                }
                else
                {
                    set_color_cell('B', game->bullet[i].position.x, game->bullet[i].position.y, 7, 3);
                }
            }
            else
            {
		            game->bullet[i].position.y = event->height - 4;
         	
            }
        }
    }

    set_message("Lives: ", event->width - 25, 0);
    char message[256];
    sprintf(message, "%d", game->lives);
    set_message(message, event->width - 14, 0);

    set_message("Scores: ", event->width - 25, 1);
    char message_2[256];
    sprintf(message_2, "%d", game->score);
    set_message(message_2, event->width - 14, 1);
	
}





