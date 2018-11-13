//
//  main.cpp
//  Adventure-Game
//
//  Created by Stephen Anderson on 2/6/13.
//  Copyright (c) 2013 Stephen Anderson. All rights reserved.
//

#include <iostream> // to import cin/cout functions
#include <cstdlib> // to access rand and srand functions
#include <ctime> // to access the computer's time
using namespace std;

int main()
{
    srand(time(0)); // seeded with time to make it truly random
    string s; // Gandalf Loop
    char c; // continue
    char k; // keep playin
    int choice = 0; // choice variable
    
    if (choice != 0 ||choice != 1 || choice != 2 || choice != 3) {
        cout << "Wrong option!" << endl;
    }
    bool keepPlaying = true; // to make it loop
    
    while (keepPlaying == true) { // to make it loop
        
        
        
        cout << "Lord of The Rings Adventure Game\n" << endl;
        cout << "You are about to embark on an adventure. Prepare yourself!\n" << endl;
        cout << "You may either be Gandalf, Frodo, or Golum." << endl;
        cout << "Enter 1 for Gandalf, 2 for Frodo, or 3 for Golum" << endl;
        cin >> choice;
        
        
        switch(choice)
        {
            {
            case 1:
                // Gandalf
                cout <<  "                       ,---.           " << endl;
                cout << "                       /    |          " << endl;
                cout << "                      /     |          " << endl;
                cout << "   Gandalf           /      |          " << endl;
                cout << "                    /       |          " << endl;
                cout << "                ___,'        |         " << endl;
                cout << "              <  -'          :         " << endl;
                cout << "               `-.__..--'``-,__       " << endl;
                cout << "                  |o/ <o>` :,.)_`>     " << endl;
                cout << "                  :/ `     ||/)        " << endl;
                cout << "                  (_.).__,-` |        " << endl;
                cout << "                  /( `.``   `| :       " << endl;
                cout << "                 \'`-.)  `  ; ;       " << endl;
                cout << "                  | `       /-<       " << endl;
                cout << "                  |     `  /   `.     " << endl;
                cout << "                  ,-_-..____     /|  ` \n" << endl;
                
                cout << "After leaving the Shire, you may either venture to see your friend Saroumon at the Two Towers or Meet up with the fellowship on their journey to Mt. Doom.\n" << endl;
                cout << "Press 1 to consult with your friend Saromon or press 2 to Meet up with the fellowship carrying the ring" << endl;
                cin >> choice;
                switch (choice) {
                    case 1:
                        cout << "You have chosen to consult with the elder wizard Saromon\n" << endl;
                        cout << "Once You arrive at the Two Towers, Saromon starts speaking of a strange and powerful enemy. You suspect he is speaking of Sauron. He asks you to join with this growing power before it is too late. What Will you do?\n" << endl;
                        cout << "Press 1 to join Sauron and help him in his search for the ring or press 2 to oppose sauron and continue to shield the ring." << endl;
                        cin >> choice;
                        switch (choice) {
                            case 1:
                                cout << "You have decided to ally yourself with Sauron. A bold move no doubt.\n\nWith your help Sauron eventually finds and kills Frodo, taking back the one ring to rule them all. With his power restored, Sauron asserts complete dominance over middle earth. Sauron recognizes your help in his rise to power and thus names you the prince of rivendell." << endl;
                                cout << "Game Over" << endl;
                                break;
                            case 2:
                                cout << "You have chosen to openly oppose Sauron and his quest for the ring. Saromon is enraged by your decision and demands a dual...wizard style. Saromon resorts to dark magic and manages to beat you. The next thing you know you wake up on top of the tower and your staff is no where to be found." << endl;
                                cout << "you can either call a butterfly and tell it to send a message to the eagles in hopes that they will rescue you. the other option is that you can jump off the tower out of Sheer boredom. Who knows, maybe you'll make it." << endl;
                                cout << "Press 1 to call a butterfly or Press 2 to end this struggle and Jump towards your death" << endl;
                                cin >> choice;
                                switch (choice) {{
                                case 1:
                                    cout << "You have chosen to Call upon a butterfly to save your life. However you do not know for sure if the butterfly will do as you say or is in fact a spy for the enemy. The butterfly might fetch a giant eagle to save your life or it might fetch a ring wraith, the most terrible of the enemy's servants." << endl;
                                    cout << "press c to continue" << endl;
                                    choice = 1+(rand()%2); // random function to decide whether the butterfly is corrupt or not
                                    cin >> c;
                                    if (c == 'c' && choice == 1) {
                                        cout << "Hooray! the butterfly cooperated and told the giant eagles you were in peril. they have come to save you!" << endl;
                                    }
                                    if (c== 'c' && choice ==2) {
                                        cout << "You encountered a corrupt butterfly and the flying wraiths have come to kill you.\nGame Over" << endl;
                                    }
                                }
                                        break;
                                        
                                    case 2:
                                        cout << "you have chosen to Jump into unknown depths that lie beneath. This decision results in you dying immediately on impact. \nGood one\nGame Over" << endl;
                                        break;
                                    default:
                                        cout << "Bad Choice!" << endl;
                                        break;
                                }
                                break;
                        }
                        break;
                    case 2:
                        cout << "Nice Move...You have chosen to meet up with the Fellowship." << endl;
                        cout << "Now you can either choose to cross the high mountain pass albeit the treacherous weather or you can resort to the abandoned Dwarf tunnel far below. Which will it be Gandalf?" << endl;
                        cout << " Press 1 to go over the mountain or 2 to go through the dwarf tunnel" << endl;
                        cin >> choice;
                        switch (choice) {
                            case 1:
                                cout << "you have chosen to endure the storm and attempt to cross the mountain pass.\nunfortunately this was the wrong choice and you and the fellowship freeze to death./nThe ring is lost for eternity" << endl;
                                
                                break;
                            case 2:
                                cout << "You have chosen to go through the abandoned dwarf tunnel. Dont you know its abandoned for a reason? \nAnyways you lead the company through the tunnel and are almost at the end when there is a bridge everyone must cross. suddenly there appears a giant fire-shadow monster behind you guys. quickly you must decide if you want to push Frodo aside to selfishly save yourself or sacrifice yourself to the fire monster in order to save the ring." << endl;
                                cout << "Press 1 to screw Frodo over and save yourself or press 2 to sacrifice yourself to save middle earth" << endl;
                                cin >> choice;
                                switch (choice) {
                                    case 1:
                                        cout << "You have chosen to selfishly save yourself. Nice Call!\nFrodo is eaten by the fire monster and the ring is lost. You however are alive and well" << endl;
                                        cout << "Game Over" << endl;
                                        break;
                                    case 2:
                                        cout << "You have chosen to sacrifice yourself to the fire monster. Now theres a chance you will survive this struggle and come back stronger than ever as Gandalf the White. but theres also a chance that you Die" << endl;
                                        cout << "press c to continue" << endl;
                                        choice = 1+(rand()%2); // random function to decide whether Gandalf comes back as Gandalf the White or dies
                                        cin >> c;
                                        if (c == 'c' && choice == 1) {
                                            cout << "Hooray! You have defeated the fire monster and come back as Gandalf The White!" << endl;
                                        }
                                        if (c== 'c' && choice ==2) {
                                            cout << "You Died in the epic battle that ensued between you and beast\nGame Over" << endl;
                                        }
                                        break;
                                    default:
                                        cout << "Bad Choice!" << endl;
                                        break;
                                }
                                break;
                            default:
                                cout << "Bad Choice!" << endl;
                                break;
                        }
                        break;
                    default:
                        cout << "Bad Choice!" << endl;
                        break;
                }
                break;
                
            default:
                cout << "Bad Choice!" << endl;
                break;
            }
                
            case 2:
                // Frodo
                
                
                
                cout << endl;
                cout << "     ***         You are Frodo.  "                 << endl;
                cout << "   **    **       -You must carry the one ring  "  << endl;
                cout << "  **     **        to rule them all "              << endl;
                cout << "   **   **"                                        << endl;
                cout << "     ***   "                                       << endl;
                
                cout << "Gandalf presents Frodo with the Ring. Frodo must now decide to accept the quest to destroy it or decline in favor of a humble life in the Shire\n" << endl;
                cout << "Press 1 to accept or 2 to decline" << endl;
                cin >> choice;
                
                s = "please reconsider.'"; // loop to make Gandalf plead with Frodo
                for (int x=0; x<=4 && choice==2; x++) {
                    cout << "Gandalf pleads with you, 'Frodo this is of the utmost importance " << s << endl;
                    s= "please, " + s;
                    cout << "press 1 to reconsider or press 2 to stubbornly decline" << endl;
                    cin >> choice;
                }
                
                switch (choice) {
                    case 1:
                        
                        cout << "you have accepted the quest to destroy the ring in the fiery depths of Mt. Doom." << endl;
                        cout << "Now, will you leave now or rest quickly to prepare for such a demanding journey?\n" << endl;
                        cout << "press 1 to leave now or 2 to take a quick nap" << endl;
                        cin >> choice;
                        if (choice ==1) {
                            cout << "you chose to leave promptly, how adventurous of you!" <<endl;
                        }
                        if (choice ==2){
                            
                            choice = 1 + rand()%2; // random function to decide if Frodo oversleeps his alarm
                            if (choice==1){
                                cout << "You awoke after a quick nap and embarked on the great journey" << endl;
                            }
                            
                        }
                        
                        switch (choice) {
                            case 1:
                                
                                cout << "After being on the road for several miles you are confronted by ring-wraiths who intend to steal the ring from you. In an attempt to escape you can either Run, Fight, or try to Outsmart them." << endl;
                                cout << "Which option would you like to do?" << endl;
                                cout << "press 1 to Run, 2 to Fight, or 3 to try to trick them" << endl;
                                
                                cin >> choice;
                                switch (choice) {
                                    case 1:
                                        cout << "You have chosen to Run. A seemingly good idea, although you dont know where to go. You end up stumbling over a cliff only to die shortly after" << endl;
                                        cout << "A wraith finds you and takes the ring out of your limp hand" << endl;
                                        cout << "Game Over" << endl;
                                        break;
                                    case 2:
                                        cout << "You have chosen to Fight, a noble act. The ring-wraiths are much more adept than you at sword play and quickly overcome your feeble attempts to fight."<< endl;
                                        cout << "You Die\nGame Over" << endl;
                                        break;
                                    case 3:
                                        cout << "You have chosen to attempt to outsmart the ring wraiths. The dangerous figures approach and ask for you to give up the ring. you reply saying that you have no idea what ring they are talking about. somehow the ring wraiths do not press you for details and instead walk away. astonished, you quickly continue on your journey." << endl;
                                        cout << "Finally you reach Mt. Doom and are faced with the decision of casting the ring into the molten lava or keeping it out of sheer temptation. You do like being invisible after all" << endl;
                                        cout << "press 1 to destroy the ring forever or 2 to keep it for yourself" << endl;
                                        cin >> choice;
                                        switch (choice) {
                                            case 1:
                                                cout << "You have destroyed the ring for good and assured peace to middle earth!" << endl;
                                                cout << "Hooray!\n";
                                                
                                                break;
                                            case 2:
                                                cout << "you have selfishly decided to keep the ring for yourself. Saroun eventually finds you and takes back what is rightfully his." << endl;
                                                cout << " Game Over" << endl;
                                                break;
                                                
                                            default:
                                                cout << "Wrong Answer... Guess Again" << endl;
                                                break;
                                        }
                                        
                                        break;
                                    default:
                                        cout << "Wrong Answer... Guess Again" << endl;
                                }
                                
                                break;
                            case 2:
                                cout << "Shit, you overslept by a lot... The ring wraiths wake you up and proceed to take the ring and stab you mercilessly." << endl;
                                cout << "You are now DEAD..."<< endl;
                                cout << " GAME OVER" << endl;
                                break;
                        }
                        break;
                        
                    case 2:
                        
                        cout << "You have chosen to decline the quest to destroy the ring and save middle earth." << endl;
                        cout << "The Shire burns to the ground and everything you once love is lost" << endl;
                        cout << "Game Over" << endl;
                        
                        break;
                        
                        
                        
                }
                
                break;
                
            case 3:
                // Golum
                
                cout << "                                _..               " << endl;
                cout << "                              .'   `',            " << endl;
                cout << "                             ;       \\           " << endl;
                cout << "                    .---._; ^,       ;            " << endl;
                cout << "                  .-'      ;{ :  .-. ._;          " << endl;
                cout << "             .--''          \\*' o/ o/           " << endl;
                cout << "            /   ,  /         :    _`*;    Golum   " << endl;
                cout << "           ;      ;          `.   ` +'            " << endl;
                cout << "           |      }    /    _.'T -- \\             " << endl;
                cout << "           :     /   .'.--''-,_ \\    ;            " << endl;
                cout << "           \\   /   /_         `,\\   ;            " << endl;
                cout << "             : /   /  `-.,_      \\`.  :           " << endl;
                cout << "             |;   {     .' `-     ; `, \\          " << endl;
                cout << "             : \\  `;   {  `-,__..-'   \\ `}+=,    " << endl;
                cout << "              : \\  ;    `.   `,        `-,\"      " << endl;
                cout << "              ! |\\ `;    \\}?|}                  " << endl;
                cout << "           .-'  | \\ ;                             " << endl;
                cout << "         .'}/ i.'  \\ `,                           " << endl;
                cout << "         ``''-'    /  \\                          " << endl;
                cout << "                  /J|/{/                          " << endl;
                cout << "                    `'                            " << endl;
                
                cout << "As Golum you have been happily living in you cave. All of a sudden you encounter a hobbit named Bagins. You might notice he has your precious ring and you might not. its a random function" << endl;
                cout << "press c to continue" << endl;
                choice = 1+(rand()%2); // random function to decide if he notices the ring
                cin >> c;
                if (c == 'c' && choice == 1) {
                    cout << "You notice that Bagins has the ring and you intend to take it back." << endl;
                    cout << "Will you fight bagins or trick him into giving the ring to you?" << endl;
                    cout << "press 1 to fight and 2 to trick" << endl;
                    cin >> choice;
                    switch (choice) {
                        case 1:
                            cout << "You have chosen to fight Bagins For the ring. Good call...\nBecause of your specialized vision accustomed to the darkness you are able to overcome Bagins and win back the ring. Congratulations!!" << endl;
                            cout << "Game Over" << endl;
                            break;
                        case 2:
                            cout << "You have opted to trick Bagins in order to retrieve the ring. Too bad Bagins is way Smarter than you. Because of this you lose and upon your agreement must let Bagins leave knowing he has the ring" << endl;
                            cout << "Game Over" << endl;
                            break;
                        default:
                            cout << "Wrong option... choose again" << endl;
                            break;
                    }
                    break;
                }
                if (c== 'c' && choice ==2) { // random function to decide if bagins wins the riddle
                    cout << "You do not notice Bagins has the ring however you still want to eat him." << endl;
                    cout << "You tell a riddle to Bagins and if he loses you get to eat him. but if Bagins wins you let him leave" << endl;
                    cout << "its a random decision" << endl;
                    cout << "press c to continue" << endl;
                    choice = 1+(rand()%2);
                    cin >> c;
                    if (c == 'c' && choice == 1) {
                        cout << "Hooray!! Bagins Loses and You get to eat him." << endl;
                        cout << "Game Over" << endl;
                    }
                    if (c== 'c' && choice ==2) {
                        cout << "Sorry, Bagins Wins and you must let him go only later to realize he has the ring" << endl;
                        cout << "Game Over" << endl;
                        
                    }
                    
                }
                
        }
        
        
        cout << "\nWould you like to play again?" << endl; // prompted to play again
        cout << "Press 'y' to keep playing or 'n' to quit" << endl;
        cin >> k;
        if (k == 'n'){
            keepPlaying = false; // changes boolean value to false thus shutting off the loop
        }
        if (k== 'y'){
            keepPlaying = true;
        }
    } // closes while loop
    return 0;
} //closes main
