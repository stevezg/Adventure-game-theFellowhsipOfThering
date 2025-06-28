//  Adventure-Game
//  A text-based adventure game based on the Lord of the Rings universe.
//  Created by Stephen Anderson on 2/6/13.

#include <iostream>
#include <string>
#include <random>
#include <limits>

// Function prototypes
void playGandalf();
void playFrodo();
void playGollum();
void playAragorn();
void playLegolas();
void playSamwise();
bool playAgain();
void getValidChoice(int& choice, int min, int max);
void displayAsciiArt(const std::string& art);
int getRandomNumber(int min, int max);

// ASCII art constants

// Initial Lord of the Rings ASCII art
const std::string LOTR_ASCII = R"(
                                                 _______________________
       _______________________-------------------                       `\
     /:--__                                                              |
    ||< > |                                   ___________________________/
    | \__/_________________-------------------                         |
    |                                                                  |
     |                       THE LORD OF THE RINGS                      |
     |                                                                  |
     |      "Three Rings for the Elven-kings under the sky,             |
      |        Seven for the Dwarf-lords in their halls of stone,        |
      |      Nine for Mortal Men doomed to die,                          |
      |        One for the Dark Lord on his dark throne                  |
      |      In the Land of Mordor where the Shadows lie.                 |
       |       One Ring to rule them all, One Ring to find them,          |
       |       One Ring to bring them all and in the darkness bind them   |
       |     In the Land of Mordor where the Shadows lie.                |
      |                                              ____________________|_
      |  ___________________-------------------------                      `\
      |/`--_                                                                 |
      ||[ ]||                                            ___________________/
       \===/___________________--------------------------

)";

const std::string GANDALF_ASCII = R"(
                               ,---.           
                               /    |          
                              /     |          
           Gandalf           /      |          
                            /       |          
                        ___,'        |         
                      <  -'          :         
                       `-.__..--'``-,__       
                          |o/ <o>` :,.)_`>     
                          :/ `     ||/)        
                          (_.).__,-` |        
                          /( `.``   `| :       
                         \'`-.)  `  ; ;       
                          | `       /-<       
                          |     `  /   `.     
                          ,-_-..____     /|  ` 
    )";

const std::string FRODO_ASCII = R"(
         ***         You are Frodo.  
       **    **       -You must carry the One Ring  
      **     **        to rule them all 
       **   **
         ***   
    )";

const std::string GOLLUM_ASCII = R"(
                                    _..               
                                  .'   `',            
                                 ;       \           
                        .---._; ^,       ;            
                      .-'      ;{ :  .-. ._;          
                 .--''          \*' o/ o/           
                /   ,  /         :    _`*;    Gollum   
               ;      ;          `.   ` +'            
               |      }    /    _.'T -- \             
               :     /   .'.--''-,_ \    ;            
               \   /   /_         `,\   ;            
                 : /   /  `-.,_      \`.  :           
                 |;   {     .' `-     ; `, \          
                 : \  `;   {  `-,__..-'   \ `}+=,    
                  : \  ;    `.   `,        `-,"      
                  ! |\ `;    \}?|}                  
               .-'  | \ ;                             
             .'}/ i.'  \ `,                           
             ``''-'    /  \                          
                      /J|/{/                          
                        `'                            
    )";

// Updated Aragorn ASCII art
const std::string ARAGORN_ASCII = R"(
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠇⢹⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡄⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢠⣤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣤⣤⡄
⠘⢿⣍⠉⣙⠻⢶⣤⡀⠀⠀⠀⣠⡾⠃⠙⢦⡀⠀⠀⠀⣀⣤⠶⠛⡉⠉⣹⡿⠁
⠀⠈⢻⣆⢿⡷⢤⡈⠙⠳⣤⡼⠋⠀⣴⡆⠀⠻⣦⣴⠞⠋⣠⡴⢻⡇⣼⠋⠀⠀
⠀⠀⠀⢹⡎⣧⠀⠙⢶⣴⡟⠻⣦⣠⡿⣿⣠⡾⠛⢷⣤⠞⠁⢀⡿⣸⠃⠀⠀⠀
⠀⠀⠀⠀⢷⠘⣧⠀⠀⠙⢧⡀⠈⣻⠃⢹⡟⠁⢠⡞⠁⠀⠀⡼⢡⠏⠀⠀⠀⠀
⠀⠀⠀⠀⠘⡆⢘⣆⠀⠀⠀⠻⣄⣿⠀⠀⣷⣴⠋⠀⠀⠀⣼⠁⡼⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣷⣾⠛⢧⡀⠀⠀⢹⡇⠀⠀⣿⠃⠀⠀⢀⡼⠹⣧⡇⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⣿⡏⠀⠈⢳⡄⠀⠘⡇⠀⠀⣽⠀⠀⣠⡟⠀⠀⢿⣇⠀⠀⠀⠀⠀
⠀⠀⠀⠐⣶⣾⢿⡇⠀⠀⠀⠹⣆⣠⣿⡄⢠⣿⣄⣰⠏⠀⠀⠀⢸⠿⢶⣶⠀⠀⠀
⠀⠀⠀⠀⠀⠈⣇⠀⠀⠀⠀⣿⠋⠘⣿⡾⠁⠹⣇⠀⠀⠀⠀⣼⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⢸⡄⠀⠀⣸⠃⠀⣠⠏⢳⣄⠀⢹⡆⠀⠀⣰⠇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢻⡄⠀⣿⣴⣿⢿⠀⠀⡿⣿⣶⣷⠀⢠⠏⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢻⣄⠉⣸⠇⢸⠀⢠⡇⢻⡆⠉⣰⠏⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣶⡏⠀⢸⣧⣸⠃⠀⢿⡾⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⢷⣄⠀⣿⡟⠀⣠⡿⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢰⡇⠀⠻⣷⡈⣡⡾⠋⠀⢻⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⢈⣿⣿⡀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠈⡇⠀⢀⡿⠁⠈⣷⠀⠀⣼⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡀⢸⠃⠀⠀⢸⡆⢠⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢷⣸⡀⠀⠀⢸⣇⡞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣧⡀⠀⣾⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣷⡾⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡟⢷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡇⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
)";

// Updated Legolas ASCII art
const std::string LEGOLAS_ASCII = R"(
                      .;;,.
                     ; '" ;\ \//
                    \|a (a|7 \//
                    j| ..  | ||/
                   //'.--.')\-,/
                 .-||- '' ||/  `-.
                ;  | \ |/ |/ L.  ,|
                f\ |\| Y  || \ '._\
               j | \|     (| |   | |
              |  L_\         L.__: |
               \(  '-.,-,    |   ; |
                |'-.'.L_rr>  f--f  |
 .-=,,______,--------- J-. ;  ;__ 
    ``"-,__   |  |      h  |  f  '--.__
        `--;;--,_       h  f-j   |   __;==-.
             / `-''-,,__J,'  \_..--:'-'     '
             | |    `' --L7//'-'`|
             | ,     ||  h    |  (
             | ;     | \ J    j   |
             | L__   | |  L_.'    |
             |   |'-.| L.'h  |  : |
             |;  \     |  J ; : : |
             | :  (    \  'L| : : |
             | ;   '.--|    \  : |
             | | : \    \-, /`\ : |
             L-'-;__\   \\ '  | | |
                     ;   \\   |'L_j
                     _>  _|   |
              snd   <___/ /-  \
                         /    /
                         '---'
)";

const std::string SAMWISE_ASCII = R"(
      _.-/|\-._
     /  / | \  \
    |  |  |  |  |
    \  \ / \ /  /
     `-/|\-`
      / | \
     /  .  \
    /  / \  \
   |  |   |  |
   \  \   /  /
    `-' `-'`
)";

// ASCII art of the entrance of Moria
const std::string MORIA_ENTRANCE_ASCII = R"(
                                 .     @$* @$3
                                '$Nueeed$$ed$$eeec$$
             ,            4$Lze@*$C2$b* ed(he*rb$CC$*$bc@$r
       /@ |~~            .e$$"W$$B$B$**  ^$  e""##d?$Bd$$$Nc. ..      @\/~\
       \==|         4$kd*Cr$6F#"`  **   .*==      # '"**F#$I$b$*       |   I
          |         d$5N@$$"   ....eu$$$$$$N$*$zbeuu     #$d$$$$b.     / @/
         @/     . z$Ted*"$P zue$*9d$$$@#       W$e@B$$L.    "#@$E$b@N
               #d$Id*P#  'Nd$$B$**"       .*,     "#*N$$b$c   $$$*$$c
              .d#+C6J   @@$B$*"          -***-        "#$$$$c   *$$$#$u
           ..u$l4@"^"zJ$7W*"              '*`            ^*$@$$$r "$$E$@B>
           *@$l$P"+Rd$$N#"          *     /|\     *        '"$$$c.. ?E$*b
           z$ "*.  .Jz$"           ***   / | \   ***         '*@N$b   d**N
         .z$JBR^bs@$$#          *   *   /  |  \   *  *         "$l*9N "bN$Nee
        4$$.C*   dB@"          ***    _/  /^\  \_   ***         '$$$z> 3$b$$#
         $"$e$  @*$"        *   *     \\^|   |^//    *   *        $$$u.^*$N$c
        JPd$%  @@d"        ***        ***********       ***       '$Ni$  $EP$
      :e$"*$  :et$          *         ***********        *         ^$$E  4$N$be
      ')$ud"  @6$                                                   9$$   $*@$"
       @F*$   *4P                       ./                          '$m#   .$$.
    u*""""""""""""h                     ##=====                    e#""""""""""#
    E +e       ue. N                 ___##_______                 4F e=c     z*c
    #e$@e.. ..z6+6d"                #*************/               ^*cBe$u.  .$$@
       $ ^"""" 4F"  ze=eu              ********              z***hc ^"$ ""*"" $
       $       ^F :*    3r                                  @"  e "b  $       $
     .e$        N $  'be$L...                            ...?be@F  $F $       9F
    4" $        $ $.  zm$*****h.                      ue""""*h6   J$" $       4%
    $  $        $ $$u5e" .     "k                    d"       #$bu$F  $       4F
    "N $        $ ^d%P  dF      $  .            .e   $     -c  "N$F  .$       4F
     #$$        $  $4*. "N.    zP  3r ..    ..  $c   *u     $  u$K$  4F       4L
      ^N$e.     3  F$k*. "*C$$$# .z$" '$    4L  "$c. '#$eeedF  $$$9r JF       J$
       $'"$$eu. 4  F3"K$ .e=*CB$$$$L .e$    '$bc.u$***hd6C""  4kF$4F $F     u@$F
       $   '"*$*@u N'L$B*"z*""     "$F" 4k 4c '7$"      "*$eu 4'L$J" $   .e$*"4F
       $      '"hC*$ "$#.P"          $me$"  #$*$       .  ^*INJL$"$  $e$$*#   4F
       $         $b"h ".F     $"     ^F        $       9r   #L#$FJEd#C@"      4L
      .$         $Jb   J"..  4b      uF        *k      J%    #c^ $" d$        4L
     :"$         $k9   $ $%4c $Bme.ze$         '*$+eee@*$"  :r$    @L$        4$
     $ $         $$Jr  $d" '$r "*==*"            "#**"" $r  4$3r  db$F        4F
     $c$         $'*F  $"   '$            /\            $    *(L  $$$F         k
     #i*e.       $ 4>  $  ue $         \`.||.'/         'L c  $$ .L$d         .$
      "b."*e.    4 4   $  $%db=eL     `.<\||/>.'      e*+$/$r  $ '$"$       .d$$
       $^#+cC*mu 4r4   4r:6@F  $$    -----++-----    <$. "N?N  F  $ $    ud$$* $
       $    "*eJ"@L4   4k*3Ic.*"      .'`.      #*5.J$$..F  $ $ ue#2*"   $
       $       "N."@r  4Fd" '$r        /.'||`.\        4$ '"N*d"  9.$#Ce*"     $
       $         "e^"  'd" uz$%           \/           '$czr"k#"  4Pu@"        $

)";

int main() {
    int choice;
    bool keepPlaying = true;

    // Display the initial Lord of the Rings ASCII art
    displayAsciiArt(LOTR_ASCII);

    while (keepPlaying) {
        std::cout << "Lord of The Rings Adventure Game\n" << std::endl;
        std::cout << "You are about to embark on an adventure. Prepare yourself!\n" << std::endl;
        std::cout << "You may choose to be one of the following characters:" << std::endl;
        std::cout << "1. Gandalf" << std::endl;
        std::cout << "2. Frodo" << std::endl;
        std::cout << "3. Gollum" << std::endl;
        std::cout << "4. Aragorn" << std::endl;
        std::cout << "5. Legolas" << std::endl;
        std::cout << "6. Samwise" << std::endl;
        std::cout << "Enter the number corresponding to your choice:" << std::endl;

        std::cin >> choice;
        getValidChoice(choice, 1, 6);

        switch (choice) {
            case 1:
                playGandalf();
                break;
            case 2:
                playFrodo();
                break;
            case 3:
                playGollum();
                break;
            case 4:
                playAragorn();
                break;
            case 5:
                playLegolas();
                break;
            case 6:
                playSamwise();
                break;
        }

        keepPlaying = playAgain();
    }

    return 0;
}

// Function to validate user input
void getValidChoice(int& choice, int min, int max) {
    while (std::cin.fail() || choice < min || choice > max) {
        std::cin.clear(); // Clear the error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Invalid choice. Please enter a number between " << min << " and " << max << "." << std::endl;
        std::cin >> choice;
    }
}

// Function to display ASCII art
void displayAsciiArt(const std::string& art) {
    std::cout << art << std::endl;
}

// Function to generate a random number between min and max inclusive
int getRandomNumber(int min, int max) {
    static std::random_device rd;  // Seed for random number engine
    static std::mt19937 gen(rd()); // Mersenne Twister engine
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

// Function to handle Gandalf's storyline
void playGandalf() {
    displayAsciiArt(GANDALF_ASCII);
    int choice;

    std::cout << "After leaving the Shire, you may either venture to see your friend Saruman at Orthanc or meet up with the fellowship on their journey to Mount Doom.\n" << std::endl;
    std::cout << "Press 1 to consult with your friend Saruman or press 2 to meet up with the fellowship carrying the ring." << std::endl;

    std::cin >> choice;
    getValidChoice(choice, 1, 2);

    if (choice == 1) {
        // Saruman storyline
        std::cout << "You have chosen to consult with the elder wizard Saruman.\n" << std::endl;
        std::cout << "Once you arrive at Orthanc, Saruman starts speaking of a strange and powerful enemy. You suspect he is speaking of Sauron. He asks you to join with this growing power before it is too late. What will you do?\n" << std::endl;
        std::cout << "Press 1 to join Sauron and help him in his search for the ring or press 2 to oppose Sauron and continue to shield the ring." << std::endl;

        std::cin >> choice;
        getValidChoice(choice, 1, 2);

        if (choice == 1) {
            std::cout << "You have decided to ally yourself with Sauron. A bold move, no doubt.\n\nWith your help, Sauron eventually finds and kills Frodo, taking back the One Ring to rule them all. With his power restored, Sauron asserts complete dominance over Middle-earth. Sauron recognizes your help in his rise to power and thus names you the Prince of Rivendell." << std::endl;
            std::cout << "Game Over" << std::endl;
        } else if (choice == 2) {
            std::cout << "You have chosen to openly oppose Sauron and his quest for the ring. Saruman is enraged by your decision and demands a duel...wizard style. Saruman resorts to dark magic and manages to beat you. The next thing you know, you wake up on top of the tower and your staff is nowhere to be found." << std::endl;
            std::cout << "You are trapped on top of Orthanc. You can try to escape using your magic, or call for help, or even attempt a desperate jump.\n" << std::endl;
            std::cout << "Press 1 to attempt a magical escape, 2 to call a moth for help, or 3 to jump off the tower." << std::endl;

            std::cin >> choice;
            getValidChoice(choice, 1, 3);

            if (choice == 1) {
                std::cout << "You focus your remaining strength, attempting to conjure a spell to escape.\n" << std::endl;
                int escapeOutcome = getRandomNumber(1, 2); // 1: success, 2: fail
                if (escapeOutcome == 1) {
                    std::cout << "With a burst of light, you manage to teleport away from Orthanc, landing safely far from Saruman's reach.\nGame Over" << std::endl;
                } else {
                    std::cout << "Your magic fails you, and you remain trapped. Saruman's power is too great.\n" << std::endl;
                    std::cout << "You are forced to choose again: call a moth (1) or jump (2)?" << std::endl;
                    std::cin >> choice;
                    getValidChoice(choice, 1, 2);
                    if (choice == 1) {
                        std::cout << "You have chosen to call upon a moth to save your life. However, you do not know for sure if the moth will do as you say or is in fact a spy for the enemy. The moth might fetch a giant eagle to save your life or it might fetch a ringwraith, the most terrible of the enemy's servants." << std::endl;
                        std::cout << "Press Enter to continue." << std::endl;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cin.get();

                        int outcome = getRandomNumber(1, 2); // 1: eagle comes, 2: ringwraith comes
                        if (outcome == 1) {
                            std::cout << "Hooray! The moth cooperated and told the giant eagles you were in peril. They have come to save you!\nGame Over" << std::endl;
                        } else {
                            std::cout << "You encountered a corrupt moth, and the flying wraiths have come to kill you.\nGame Over" << std::endl;
                        }
                    }
                    else if (choice == 2) {
                        std::cout << "You have chosen to jump into the unknown depths that lie beneath. This decision results in you dying immediately on impact.\nGame Over" << std::endl;
                    }
                }
            } else if (choice == 2) {
                std::cout << "You have chosen to call upon a moth to save your life. However, you do not know for sure if the moth will do as you say or is in fact a spy for the enemy. The moth might fetch a giant eagle to save your life or it might fetch a ringwraith, the most terrible of the enemy's servants." << std::endl;
                std::cout << "Press Enter to continue." << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();

                int outcome = getRandomNumber(1, 2); // 1: eagle comes, 2: ringwraith comes
                if (outcome == 1) {
                    std::cout << "Hooray! The moth cooperated and told the giant eagles you were in peril. They have come to save you!\nGame Over" << std::endl;
                } else {
                    std::cout << "You encountered a corrupt moth, and the flying wraiths have come to kill you.\nGame Over" << std::endl;
                }
            } else if (choice == 3) {
                std::cout << "You have chosen to jump into the unknown depths that lie beneath. This decision results in you dying immediately on impact.\nGame Over" << std::endl;
            }
        }
    } else if (choice == 2) {
        // Fellowship storyline
        std::cout << "Nice move... You have chosen to meet up with the Fellowship." << std::endl;
        std::cout << "Now you can either choose to cross the high mountain pass, albeit the treacherous weather, or you can resort to the abandoned dwarf tunnel far below. Which will it be, Gandalf?" << std::endl;
        std::cout << "Press 1 to go over the mountain or 2 to go through the Mines of Moria." << std::endl;

        std::cin >> choice;
        getValidChoice(choice, 1, 2);

        if (choice == 1) {
            std::cout << "You have chosen to endure the storm and attempt to cross the mountain pass.\nUnfortunately, the snowstorm forces you back, and you decide to take the path through Moria.\n" << std::endl;
            // Continue to Moria
        }

        if (choice == 2 || choice == 1) {
            std::cout << "You have chosen to go through the Mines of Moria. Despite warnings, you lead the company into the darkness." << std::endl;

            // Display the ASCII art of the entrance of Moria
            displayAsciiArt(MORIA_ENTRANCE_ASCII);

            std::cout << "As you journey through Moria, you come to a fork in the path. One way leads deeper into the known tunnels, the other to a less-traveled, ancient passage.\n" << std::endl;
            std::cout << "Do you take the main path or explore the ancient passage?" << std::endl;
            std::cout << "Press 1 for the main path or 2 for the ancient passage." << std::endl;

            std::cin >> choice;
            getValidChoice(choice, 1, 2);

            if (choice == 1) {
                std::cout << "You continue along the main path, and soon you encounter the Balrog, a powerful fire demon.\n" << std::endl;
            } else if (choice == 2) {
                std::cout << "You venture into the ancient passage. After some time, you discover a hidden chamber filled with ancient dwarven treasures and lore. However, your presence awakens something ancient and terrible... the Balrog!\n" << std::endl;
            }

            std::cout << "Do you face the Balrog to protect the Fellowship or attempt to flee?" << std::endl;
            std::cout << "Press 1 to face the Balrog or 2 to flee." << std::endl;

            std::cin >> choice;
            getValidChoice(choice, 1, 2);

            if (choice == 1) {
                std::cout << "You stand your ground and confront the Balrog on the Bridge of Khazad-dûm.\n" << std::endl;
                std::cout << "With a mighty shout, you declare: 'You shall not pass!'\n" << std::endl;
                std::cout << "You manage to defeat the Balrog but are pulled down into the abyss.\n" << std::endl;
                std::cout << "After a long battle, you emerge victorious and are reborn as Gandalf the White.\n" << std::endl;
                std::cout << "Now, reborn and more powerful, you must decide your next course of action.\n" << std::endl;
                std::cout << "Do you seek counsel in the golden woods of Lothlórien or journey to Fangorn Forest to rouse the Ents?" << std::endl;
                std::cout << "Press 1 to go to Lothlórien or 2 to go to Fangorn Forest." << std::endl;

                std::cin >> choice;
                getValidChoice(choice, 1, 2);

                if (choice == 1) {
                    std::cout << "You travel to Lothlórien, where you are welcomed by Lady Galadriel and Lord Celeborn.\nTheir wisdom and the beauty of the golden wood restore your spirit and clarify your purpose.\nGame Over" << std::endl;
                } else if (choice == 2) {
                    std::cout << "You journey to Fangorn Forest and awaken Treebeard and the other Ents.\nWith their aid, you march on Isengard, bringing ruin to Saruman's fortress.\nGame Over" << std::endl;
                }
            } else if (choice == 2) {
                std::cout << "You attempt to flee, but the Balrog catches up to the Fellowship.\n" << std::endl;
                std::cout << "Without your sacrifice, the entire Fellowship is destroyed.\n" << std::endl;
                std::cout << "Game Over" << std::endl;
            }
        }
    }
}

// Function to handle Frodo's storyline
void playFrodo() {
    displayAsciiArt(FRODO_ASCII);
    int choice;
    std::string s = "please reconsider.'"; // Loop to make Gandalf plead with Frodo

    std::cout << "Gandalf presents you, Frodo, with the One Ring. You must now decide to accept the quest to destroy it or decline in favor of a humble life in the Shire.\n" << std::endl;
    std::cout << "Press 1 to accept or 2 to decline." << std::endl;

    std::cin >> choice;
    getValidChoice(choice, 1, 2);

    while (choice == 2) {
        std::cout << "Gandalf pleads with you, 'Frodo, this is of the utmost importance " << s << std::endl;
        s = "please, " + s;
        std::cout << "Press 1 to reconsider or press 2 to stubbornly decline." << std::endl;
        std::cin >> choice;
        getValidChoice(choice, 1, 2);
    }

    if (choice == 1) {
        std::cout << "You have accepted the quest to destroy the ring in the fiery depths of Mount Doom." << std::endl;
        std::cout << "Now, you must begin your perilous journey. Do you head directly towards Rivendell, or do you make a stop at Bree and the Prancing Pony Inn?" << std::endl;
        std::cout << "Press 1 to go directly to Rivendell or 2 to stop at Bree." << std::endl;

        std::cin >> choice;
        getValidChoice(choice, 1, 2);

        if (choice == 1) {
            std::cout << "You decide to avoid unnecessary delays and head straight for Rivendell.\n" << std::endl;
            // Continue to Rivendell section
        } else if (choice == 2) {
            std::cout << "You arrive at Bree and settle into the Prancing Pony Inn. Here, you encounter a mysterious ranger known as Strider.\n" << std::endl;
            std::cout << "Do you trust Strider and accept his offer of guidance, or do you try to avoid him?" << std::endl;
            std::cout << "Press 1 to trust Strider or 2 to avoid him." << std::endl;

            std::cin >> choice;
            getValidChoice(choice, 1, 2);

            if (choice == 1) {
                std::cout << "You accept Strider's help, and he becomes your guide to Rivendell.\n" << std::endl;
                std::cout << "On your journey, you reach Weathertop. Suddenly, you are ambushed by the Nazgûl!\n" << std::endl;
                std::cout << "Do you put on the One Ring to escape, or do you try to fight them off with Strider's help?" << std::endl;
                std::cout << "Press 1 to put on the Ring or 2 to fight." << std::endl;

                std::cin >> choice;
                getValidChoice(choice, 1, 2);

                if (choice == 1) {
                    std::cout << "You put on the One Ring, becoming invisible to the Nazgûl, but you are struck by the Morgul-blade.\nStrider drives them off, but you are gravely wounded.\nGame Over" << std::endl;
                } else if (choice == 2) {
                    std::cout << "You and Strider bravely fight off the Nazgûl, but you are still wounded, though less severely.\nGame Over" << std::endl;
                }
            } else if (choice == 2) {
                std::cout << "You try to avoid Strider, but the Nazgûl find you alone in Bree and capture you.\nGame Over" << std::endl;
            }
        }
        std::cout << "You eventually reach Rivendell, where you begin to recover and the Council of Elrond is held.\n" << std::endl;
        std::cout << "Do you seek counsel from Lord Elrond or from Bilbo Baggins?" << std::endl;
        std::cout << "Press 1 to speak with Elrond or 2 to speak with Bilbo." << std::endl;

        std::cin >> choice;
        getValidChoice(choice, 1, 2);

        if (choice == 1) {
            std::cout << "Lord Elrond discusses the history of the Ring and the grave dangers ahead, strengthening your resolve.\n" << std::endl;
        } else if (choice == 2) {
            std::cout << "Bilbo shares stories of his own adventures and offers words of encouragement, along with his sword, Sting, and a mithril shirt.\n" << std::endl;
        }

        std::cout << "The Fellowship of the Ring is formed! Now, you must choose your path forward.\n" << std::endl;
        std::cout << "Do you attempt to cross the treacherous Caradhras, or brave the dark Mines of Moria?" << std::endl;
        std::cout << "Press 1 to go over Caradhras or 2 to go through Moria." << std::endl;

        std::cin >> choice;
        getValidChoice(choice, 1, 2);

        if (choice == 1) {
            std::cout << "You attempt to cross Caradhras, but the mountain's harsh weather forces you to turn back.\n" << std::endl;
            std::cout << "You are forced to take the path through Moria.\n" << std::endl;
        }

        std::cout << "You enter the Mines of Moria. After a perilous journey, you encounter the Balrog.\n" << std::endl;
        std::cout << "Gandalf faces the Balrog to protect the Fellowship. Do you stay and fight alongside him, or follow the others to escape?" << std::endl;
        std::cout << "Press 1 to stay with Gandalf or 2 to follow the Fellowship." << std::endl;

        std::cin >> choice;
        getValidChoice(choice, 1, 2);

        if (choice == 1) {
            std::cout << "You bravely stand with Gandalf, but the Balrog's power is too great. Both you and Gandalf are overwhelmed.\nGame Over" << std::endl;
        } else if (choice == 2) {
            std::cout << "You follow the rest of the Fellowship, escaping Moria as Gandalf battles the Balrog.\n" << std::endl;
            std::cout << "The Fellowship continues its journey, but soon reaches Amon Hen, where it is attacked by Uruk-hai.\n" << std::endl;
            std::cout << "Do you try to escape alone with the Ring, or do you seek help from Aragorn?" << std::endl;
            std::cout << "Press 1 to escape alone or 2 to seek Aragorn's help." << std::endl;

            std::cin >> choice;
            getValidChoice(choice, 1, 2);

            if (choice == 1) {
                std::cout << "You attempt to escape alone, but Boromir, trying to protect you, is slain. You and Samwise escape, continuing your journey to Mordor alone.\nGame Over" << std::endl;
            } else if (choice == 2) {
                std::cout << "You seek Aragorn's help, and together you fight valiantly, but the Fellowship is scattered, and the Ring is nearly lost.\nGame Over" << std::endl;
            }
        }
    } else if (choice == 2) {
        std::cout << "You have chosen to decline the quest to destroy the ring and save Middle-earth." << std::endl;
        std::cout << "The Shire burns to the ground and everything you once loved is lost.\nGame Over" << std::endl;
    }
}

// Function to handle Gollum's storyline
void playGollum() {
    displayAsciiArt(GOLLUM_ASCII);
    int choice;

    std::cout << "As Gollum, you have been happily living in your cave. All of a sudden, you encounter a hobbit named Baggins. You might notice he has your precious ring, and you might not. It's a random chance." << std::endl;
    std::cout << "Press Enter to continue." << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    int noticeRing = getRandomNumber(1, 2); // 1: notice, 2: don't notice

    if (noticeRing == 1) {
        std::cout << "You notice that Baggins has the ring, and you intend to take it back." << std::endl;
        std::cout << "Will you fight Baggins or trick him into giving the ring to you?" << std::endl;
        std::cout << "Press 1 to fight and 2 to trick." << std::endl;

        std::cin >> choice;
        getValidChoice(choice, 1, 2);

        if (choice == 1) {
            std::cout << "You have chosen to fight Baggins for the ring. Good call...\nBecause of your specialized vision accustomed to the darkness, you are able to overcome Baggins and win back the ring. Congratulations!!" << std::endl;
            std::cout << "Game Over" << std::endl;
        } else if (choice == 2) {
            std::cout << "You have opted to trick Baggins in order to retrieve the ring. Too bad Baggins is way smarter than you. Because of this, you lose and, upon your agreement, must let Baggins leave knowing he has the ring." << std::endl;
            std::cout << "Game Over" << std::endl;
        }
    } else {
        std::cout << "You do not notice Baggins has the ring; however, you still want to eat him." << std::endl;
        std::cout << "You propose a riddle game to Baggins: if he loses, you get to eat him, but if Baggins wins, you let him leave." << std::endl;
        std::cout << "It's a random outcome." << std::endl;
        std::cout << "Press Enter to continue." << std::endl;
        std::cin.get();

        int riddleOutcome = getRandomNumber(1, 2); // 1: Gollum wins, 2: Baggins wins

        if (riddleOutcome == 1) {
            std::cout << "Hooray!! Baggins loses, and you get to eat him." << std::endl;
            std::cout << "Game Over" << std::endl;
        } else {
            std::cout << "Sorry, Baggins wins, and you must let him go, only later to realize he has the ring." << std::endl;
            std::cout << "Game Over" << std::endl;
        }
    }
}

// Function to handle Aragorn's storyline
void playAragorn() {
    displayAsciiArt(ARAGORN_ASCII);
    int choice;

    std::cout << "As Aragorn, the heir of Isildur, you must decide whether to accept your destiny as the King of Gondor or remain a ranger.\n" << std::endl;
    std::cout << "Press 1 to accept your destiny or 2 to continue as a ranger." << std::endl;

    std::cin >> choice;
    getValidChoice(choice, 1, 2);

    if (choice == 1) {
        std::cout << "You accept your destiny and set out to gather allies to fight against Sauron's forces.\n" << std::endl;
        std::cout << "Before gathering allies, do you seek counsel in Rivendell or immediately go to Rohan/Army of the Dead?" << std::endl;
        std::cout << "Press 1 to go to Rivendell or 2 to proceed directly to gathering allies." << std::endl;

        std::cin >> choice;
        getValidChoice(choice, 1, 2);

        if (choice == 1) {
            std::cout << "You travel to Rivendell, the Last Homely House East of the Sea.\n" << std::endl;
            std::cout << "Do you seek the wisdom of Lord Elrond or the guidance of Arwen Undómiel?" << std::endl;
            std::cout << "Press 1 to consult Elrond or 2 to speak with Arwen." << std::endl;

            std::cin >> choice;
            getValidChoice(choice, 1, 2);

            if (choice == 1) {
                std::cout << "Lord Elrond shares ancient lore and advises you on the strength of your lineage.\nHe reinforces your resolve to claim your birthright.\n" << std::endl;
            } else if (choice == 2) {
                std::cout << "Arwen reaffirms her love and faith in you, presenting you with the Evenstar pendant.\nHer unwavering belief strengthens your spirit for the trials ahead.\n" << std::endl;
            }
            std::cout << "With renewed purpose, you prepare to gather allies.\n" << std::endl;
        }

        std::cout << "Now, do you first go to Rohan to aid King Théoden or seek the Army of the Dead?" << std::endl;
        std::cout << "Press 1 to go to Rohan or 2 to seek the Army of the Dead." << std::endl;

        std::cin >> choice;
        getValidChoice(choice, 1, 2);

        if (choice == 1) {
            std::cout << "You ride to Rohan and help free King Théoden from Saruman's influence.\n" << std::endl;
            std::cout << "Together, you prepare to defend Helm's Deep against the approaching army.\n" << std::endl;
            std::cout << "The Uruk-hai army is at the gates. How do you lead the defense?" << std::endl;
            std::cout << "Press 1 to lead a charge from the gate, 2 to defend the walls, or 3 to prepare an ambush." << std::endl;

            std::cin >> choice;
            getValidChoice(choice, 1, 3);

            if (choice == 1) {
                std::cout << "Your bold charge from the gate inspires the men, and with the arrival of Gandalf and Erkenbrand, you turn the tide of battle.\nVictory is yours!\nGame Over" << std::endl;
            } else if (choice == 2) {
                std::cout << "You rally the defenders on the walls, holding back the enemy with fierce determination.\nThough the battle is long and hard, the dawn brings Gandalf and the Rohirrim, securing your victory.\nGame Over" << std::endl;
            } else if (choice == 3) {
                std::cout << "You devise a clever ambush, luring a portion of the Uruk-hai into a trap before unleashing your forces.\nThis tactical brilliance, combined with Gandalf's arrival, shatters the enemy's morale and secures a decisive victory.\nGame Over" << std::endl;
            }
        } else if (choice == 2) {
            std::cout << "You journey through the Paths of the Dead to enlist the help of the cursed army.\n" << std::endl;
            std::cout << "Upon reaching the Stone of Erech, you confront the King of the Dead.\n" << std::endl;
            std::cout << "Do you confront the King of the Dead with courage and demand their oath, or attempt to purify their spirits?" << std::endl;
            std::cout << "Press 1 to confront with courage or 2 to attempt purification." << std::endl;

            std::cin >> choice;
            getValidChoice(choice, 1, 2);

            if (choice == 1) {
                std::cout << "Your bravery convinces the Army of the Dead to fulfill their oath.\nWith their help, you secure victory at the Battle of Pelennor Fields.\nGame Over" << std::endl;
            } else if (choice == 2) {
                std::cout << "You attempt to purify their tormented spirits, but the task is beyond your current power.\nThey remain bound by their curse, unable to aid you, and you must face the war without them.\nGame Over" << std::endl;
            }
        }
    } else if (choice == 2) {
        std::cout << "You choose to remain a ranger. Sauron's power grows unchecked, and Middle-earth falls into darkness.\nGame Over" << std::endl;
    }
}

// Function to handle Legolas's storyline
void playLegolas() {
    displayAsciiArt(LEGOLAS_ASCII);
    int choice;

    std::cout << "As Legolas, Prince of the Woodland Realm, you join the Fellowship to destroy the One Ring.\n" << std::endl;
    std::cout << "Before embarking on your journey, do you seek Elven wisdom in Lothlórien or train with Gimli to hone your combat skills?" << std::endl;
    std::cout << "Press 1 to go to Lothlórien or 2 to train with Gimli." << std::endl;

    std::cin >> choice;
    getValidChoice(choice, 1, 2);

    if (choice == 1) {
        std::cout << "You travel to Lothlórien, the heart of Elvendom on Middle-earth.\n" << std::endl;
        std::cout << "Lady Galadriel offers you a glimpse into the future. Do you accept her vision?" << std::endl;
        std::cout << "Press 1 to accept the vision or 2 to decline." << std::endl;

        std::cin >> choice;
        getValidChoice(choice, 1, 2);

        if (choice == 1) {
            std::cout << "You witness the potential darkness that lies ahead, strengthening your resolve to fight for Middle-earth.\n" << std::endl;
        } else if (choice == 2) {
            std::cout << "You choose to face the future without foreknowledge, relying on your own strength and the bonds of the Fellowship.\n" << std::endl;
        }
        std::cout << "With renewed spirit, you continue your journey.\n" << std::endl;
    } else if (choice == 2) {
        std::cout << "You spend time training with Gimli, learning to fight alongside a Dwarf and improving your close-quarters combat skills.\n" << std::endl;
        std::cout << "Your bond with Gimli strengthens, and you become a more versatile warrior.\n" << std::endl;
    }

    std::cout << "During your journey, you can focus on aiding your companions or scouting ahead for dangers.\n" << std::endl;
    std::cout << "Press 1 to aid your companions or 2 to scout ahead." << std::endl;

    std::cin >> choice;
    getValidChoice(choice, 1, 2);

    if (choice == 1) {
        std::cout << "You stay close to your companions, providing support with your keen archery skills.\n" << std::endl;
        std::cout << "In the Battle of Helm's Deep, your actions are crucial in holding the fortress.\n" << std::endl;
        std::cout << "Do you focus on eliminating key Uruk-hai leaders or protecting the vulnerable civilians?" << std::endl;
        std::cout << "Press 1 to target leaders or 2 to protect civilians." << std::endl;

        std::cin >> choice;
        getValidChoice(choice, 1, 2);

        if (choice == 1) {
            std::cout << "Your precise shots fell many Uruk-hai leaders, demoralizing their forces and turning the tide of battle.\nGame Over" << std::endl;
        } else if (choice == 2) {
            std::cout << "You bravely defend the civilians, ensuring their safety amidst the chaos of battle.\nYour compassion inspires hope in the darkest hour.\nGame Over" << std::endl;
        }
    } else if (choice == 2) {
        std::cout << "While scouting ahead, you discover a massive Uruk-hai army approaching.\n" << std::endl;
        std::cout << "Do you return to warn your companions or attempt to hinder the enemy with a daring ambush?" << std::endl;
        std::cout << "Press 1 to return and warn or 2 to hinder the enemy." << std::endl;

        std::cin >> choice;
        getValidChoice(choice, 1, 2);

        if (choice == 1) {
            std::cout << "Your timely warning allows the Fellowship to prepare for the attack, setting up defenses and ambushes.\n" << std::endl;
            std::cout << "Your actions contribute significantly to the survival of your companions.\nGame Over" << std::endl;
        } else if (choice == 2) {
            std::cout << "You set a cunning trap, delaying the Uruk-hai army and allowing your companions more time to escape or prepare.\nHowever, you are gravely wounded in the process.\nGame Over" << std::endl;
        }
    }

    std::cout << "Later, you find yourself on the Pelennor Fields, facing the full might of Mordor.\n" << std::endl;
    std::cout << "Do you join the charge of the Rohirrim or seek out the Mûmakil to bring them down?" << std::endl;
    std::cout << "Press 1 to join the Rohirrim charge or 2 to hunt Mûmakil." << std::endl;

    std::cin >> choice;
    getValidChoice(choice, 1, 2);

    if (choice == 1) {
        std::cout << "You ride alongside the Rohirrim, your arrows finding their marks amidst the enemy ranks.\nYour skill and bravery help break the siege of Minas Tirith.\nGame Over" << std::endl;
    } else if (choice == 2) {
        std::cout << "You bravely take on the colossal Mûmakil, bringing down several of the beasts with your precise archery.\nYour actions sow chaos among the enemy and save many lives.\nGame Over" << std::endl;
    }
}

// Function to handle Samwise's storyline
void playSamwise() {
    displayAsciiArt(SAMWISE_ASCII);
    int choice;

    std::cout << "As Samwise Gamgee, your loyalty to Mr. Frodo is unwavering. You embark on the perilous journey to Mordor, determined to see him through to the end.\n" << std::endl;
    std::cout << "Frodo is weary and the path is hard. Do you offer words of encouragement or share your meager rations?" << std::endl;
    std::cout << "Press 1 to offer encouragement or 2 to share rations." << std::endl;

    std::cin >> choice;
    getValidChoice(choice, 1, 2);

    if (choice == 1) {
        std::cout << "Your heartfelt words lift Frodo's spirits, giving him the strength to continue.\n" << std::endl;
    } else if (choice == 2) {
        std::cout << "You share your precious food, ensuring Frodo has the energy to keep going, even if it means you go without.\n" << std::endl;
    }

    std::cout << "You encounter a difficult obstacle: a steep, rocky climb. Frodo is struggling.\n" << std::endl;
    std::cout << "Do you carry the Ring for a short while to ease Frodo's burden, or do you help him physically up the climb?" << std::endl;
    std::cout << "Press 1 to carry the Ring or 2 to help him climb." << std::endl;

    std::cin >> choice;
    getValidChoice(choice, 1, 2);

    if (choice == 1) {
        std::cout << "You bravely take the Ring, feeling its immense weight and temptation, but your loyalty to Frodo allows you to resist its power.\n" << std::endl;
        std::cout << "Game Over" << std::endl;
    } else if (choice == 2) {
        std::cout << "You put your own strength aside and help Frodo, pushing him up the difficult terrain. Your dedication is truly inspiring.\n" << std::endl;
        std::cout << "Game Over" << std::endl;
    }
}

// Function to ask the player if they want to play again
bool playAgain() {
    char k;
    std::cout << "\nWould you like to play again?" << std::endl;
    std::cout << "Press 'y' to keep playing or 'n' to quit." << std::endl;
    std::cin >> k;

    while (k != 'y' && k != 'n') {
        std::cout << "Invalid choice. Please press 'y' to keep playing or 'n' to quit." << std::endl;
        std::cin >> k;
    }

    return k == 'y';
}