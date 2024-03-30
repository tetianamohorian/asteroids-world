# Asteroids
### 1. Game description

The player controls a spaceship that moves left and right and shoots at asteroids. The aim of the game is to destroy all the asteroids and score as many points as possible. The game has three levels, in each of which asteroids appear and move around the screen. The player must avoid collisions with asteroids and shoot at them to destroy them. If the player collides with an asteroid, he loses a life. The game ends if the player loses all lives. After successfully completing each level, the player has the option to choose the next level or quit the game.

### 2. How to translate and run the game ?

- Compile the program using the command
    
    ````c
     make
    ````
- Run the program using the command
    
    ````c
    ./game
    ````

### 3. Instructions on how to play the game

- The player's spaceship is marked with a "P". Use the left and right arrow keys to move the ship horizontally.

- To shoot, press the space bar. Each time you press it, the ship fires one bullet downwards.

- Asteroids are marked with the letter "A". Your goal is to destroy the asteroids by hitting them with missiles. When a bullet collides with an asteroid, both the asteroid and the bullet disappear and you score points.

- The game ends if all asteroids are destroyed or if an asteroid flies past or crashes into the ship.

- You have three lives. If an asteroid flies past you or collides with a spaceship, you lose one life. If you run out of lives, the game ends and you lose.

- Your score is displayed in the top right corner of the screen.

- If you win, a menu will appear at the end of the game, allowing you to choose a new level or exit the game.

- To select a level from the menu, press the corresponding button (1, 2, 3).

- To exit the game, select 'Exit' from the menu.

### 4. How is the game programmed?

- The most important game features and their functions

    * The init_game_level_1() function initializes the first level of the game. It creates an instance of the Game structure and sets the initial values for the player, asteroids, charges, score, and lives.

    * Similarly, the init_game_level_2() and init_game_level_3() functions initialize levels 2 and 3.

    * The world_event() function handles game world events. It responds to player keystrokes (left, right, spacebar), updates missile and asteroid positions, and handles missile and asteroid collisions. If no asteroid is alive, the draw_game() function is called, which displays the current game state and prompts the user to select the next level or quit the game.

    * Draw_game() displays the current state of the game. It draws the player, asteroids and bullets on the terminal screen and displays information about the player's lifetime and score.

- Important constructions in this game are:
    * Initialization of game levels with different parameters such as speed, initial positions of objects and number of asteroids.
    * Game world event processing including keystrokes, object position updates and collision handling.
    * Display the current state of the game on the terminal screen using the draw_game() function.

### 5. Links to source code and websites that were used in the solution

-   [GitHub Game World](https://github.com/hladek/world)
   
-   [Youtube](https://www.youtube.com/watch?v=V5qB6KVe8pY)

-   [GitHub Asteroids](https://github.com/maslovsa/asteroids/tree/master/Classes)

### 6. World Library Modifications

Adding two functions: menu() and get_key().

- menu(): This function is responsible for setting up the ncurses library and configuring the terminal to work in curses mode. The initscr()function initializes the screen and other internal structures required by ncurses. The noecho()function disables the display of user input, so that characters entered by the user are not displayed on the screen. The cbreak()function enables cbreak mode, which allows the program to immediately read user input without waiting for a newline character.
Useful for displaying menus at the beginning of a game and after a win.

- get_key(): this function uses the getch() function from the ncurses library to read a single character of user input from the terminal. This allows the program to capture keystrokes and use them for further processing. You need this function for menus, a keystroke selects either level or exit
