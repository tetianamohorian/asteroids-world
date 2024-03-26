#include "game.h"
#include "world.h"
#include <stdlib.h>

void intro_menu()
{
	set_message("ASTEROIDS", 72,  10);
	set_message("Menu", 75,  15);
	set_message("1. Level 1", 72,  17);
	set_message("2. Level 2", 72, 18);
	set_message("3. Level 3", 72, 19);		
}


int main(int argc, char** argv)
{
	     
        menu();
	intro_menu();
	char k = get_key();
	
	switch(k)
	{
	  case '1':
		 start_world(init_game_level_1, world_event, free);
	  case '2':
		 start_world(init_game_level_2, world_event, free);
	  case '3':
		 start_world(init_game_level_3, world_event, free);
	}
		
        
	return 0;
}
