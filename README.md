# Asteroids
### 1. Popis hry

Hráč ovláda vesmírnu loď, ktorá sa pohybuje doľava a doprava a strieľa na asteroidy. Cieľom hry je zničiť všetky asteroidy a získať čo najviac bodov. Hra má tri úrovne, v každej z nich sa objavujú asteroidy, ktoré sa pohybujú po obrazovke. Hráč musí vyhýbať sa zrážkam s asteroidmi a strieľať na ne, aby ich zničil. Ak sa hráč zrazí s asteroidom, stratí život. Hra sa končí, ak hráč stratí všetky životy. Po úspešnom dokončení každej úrovne má hráč možnosť vybrať si ďalšiu úroveň alebo ukončiť hru.

### 2. Ako hru preložiť a spustiť ?

- Program skompilujte pomocou príkazu
    
    ````c
     make
    ````
- Spustite program pomocou príkazu
    
    ````c
    ./game
    ````

### 3. Pokyny na hranie hry

- Hráčova vesmírna loď je označená písmenom "P". Pomocou klávesov so šípkami vľavo a vpravo sa loď pohybuje horizontálne.

- Ak chcete strieľať, stlačte medzerník. Pri každom jeho stlačení loď vystrelí jednu guľku smerom nadol.

- Asteroidy sú označené písmenom "A". Vaším cieľom je zničiť asteroidy tak, že ich zasiahnete strelami. Keď sa guľka zrazí s asteroidom, asteroid aj guľka zmiznú a vy získate body.

- Hra sa končí, ak sú zničené všetky asteroidy alebo ak asteroid preletí okolo lode alebo do nej narazí.

- Máte tri životy. Keď okolo vás preletí asteroid alebo sa zrazí s vesmírnou loďou, stratíte jeden život. Ak vám dôjdu životy, hra sa skončí a vy prehráte.

- Vaše skóre sa zobrazuje v pravom hornom rohu obrazovky.

- Ak vyhráte, po skončení hry sa zobrazí ponuka, v ktorej si môžete vybrať novú úroveň alebo ukončiť hru.

- Ak chcete vybrať úroveň z ponuky, stlačte príslušné tlačidlo (1, 2, 3).

- Ak chcete ukončiť hru, vyberte v ponuke možnosť "Exit" (Ukončiť).

### 4. Ako je hra naprogramovaná?

- Najdôležitejšie herné funkcie a ich funkcie

    * Funkcia init_game_level_1() inicializuje prvú úroveň hry. Vytvorí inštanciu štruktúry Game a nastaví počiatočné hodnoty pre hráča, asteroidy, náboje, skóre a životy.

    * Podobne funkcie init_game_level_2() a init_game_level_3() inicializujú úrovne 2 a 3.

    * Funkcia world_event() spracováva udalosti herného sveta. Reaguje na stlačenia klávesov hráča (ľavý, pravý, medzerník), aktualizuje pozície striel a asteroidov a spracováva kolízie striel a asteroidov. Ak už nie je žiadny asteroid nažive, zavolá sa funkcia draw_game(), ktorá zobrazí aktuálny stav hry a vyzve používateľa, aby vybral ďalšiu úroveň alebo ukončil hru.

    * Draw_game() zobrazí aktuálny stav hry. Na obrazovku terminálu nakreslí hráča, asteroidy a guľky a zobrazí informácie o dĺžke života hráča a skóre.

- Dôležité konštrukcie v tejto hre sú:

    * Inicializácia herných úrovní s rôznymi parametrami, ako sú rýchlosť, počiatočné pozície objektov a počet asteroidov.
    * Spracovanie udalostí herného sveta vrátane stlačenia klávesov, aktualizácie pozícií objektov a spracovania kolízií.
    * Zobrazenie aktuálneho stavu hry na obrazovke terminálu pomocou funkcie draw_game().

### 5. Odkazy na zdrojový kód a webové stránky, ktoré boli použité pri riešení

-   [GitHub Game World](https://github.com/hladek/world)
   
-   [Youtube](https://www.youtube.com/watch?v=V5qB6KVe8pY)

-   [GitHub Asteroids](https://github.com/maslovsa/asteroids/tree/master/Classes)

### 6. Používanie hry so ZAPа

Nepoužila som hru od ZAP, pretože to bola nudná hra (2048)

### 7. Modifikácie knižnice World

Pridanie dvoch funkcií: menu() a get_key().

- menu(): Táto funkcia je zodpovedná za nastavenie knižnice ncurses a konfiguráciu terminálu na prácu v režime curses. Funkcia initscr()inicializuje obrazovku a ďalšie vnútorné štruktúry, ktoré vyžaduje ncurses. Funkcia noecho()zakáže zobrazovanie užívateľského vstupu, takže znaky zadané užívateľom sa nezobrazia na obrazovke. Funkcia cbreak()zapína režim cbreak, ktorý umožňuje programu okamžite prečítať vstup používateľa bez čakania na znak nového riadku.
Užitočné na zobrazenie ponúk na začiatku hry a po výhre.

- get_key(): Táto funkcia používa funkciu getch() z knižnice ncurses na čítanie jedného znaku užívateľského vstupu z terminálu. To umožňuje programu zachytiť stlačenia klávesov a použiť ich na ďalšie spracovanie. Túto funkciu potrebujete pre menu, stlačenie klávesu vyberie buď úroveň, alebo ukončenie
