// KeypressInteractionReader.cpp
//
// ICS 45C Winter 2019
// Project #4: People Just Want to Play with Words
//
// Implementation of the KeypressInteractionReader
//
// YOU WILL NEED TO IMPLEMENT SOME THINGS HERE

#include "KeypressInteractionReader.hpp"
#include "MoveRight.hpp"
#include "MoveLeft.hpp"
#include "Character.hpp"
#include "MoveUp.hpp"
#include "MoveDown.hpp"
#include "MoveHome.hpp"
#include "MoveEnd.hpp"
#include "NewLine.hpp"
#include "Backspace.hpp"
#include "DeleteLine.hpp"

#include <string>
#include <iostream>
// You will need to update this member function to watch for the right
// keypresses and build the right kinds of Interactions as a result.
//
// The reason you'll need to implement things here is that you'll need
// to create Command objects, which you'll be declaring and defining
// yourself; they haven't been provided already.
//
// I've added handling for "quit" here, but you'll need to add the others.

Interaction KeypressInteractionReader::nextInteraction()
{
    
    while (true)
    {
        
        Keypress keypress = keypressReader.nextKeypress();

        if (keypress.ctrl())
        {
            // The user pressed a Ctrl key (e.g., Ctrl+X); react accordingly

            switch (keypress.code())
            {
            case 'X':
                return Interaction::quit();
            case 'Z':
                return Interaction::undo();
            
            case 'A':
                return Interaction::redo();
                // move right
            case 'O':
                {   
                    
                    MoveRight* right = new MoveRight;
                    return Interaction::command(right);
                }

            case 'U': // cursor left
                {
                    
                    MoveLeft* left = new MoveLeft;
                   
                    return Interaction::command(left);
                }

        
            case 'I': // cursor up
                {
               
                    MoveUp* up = new MoveUp;
                    
                    return Interaction::command(up);
                }
            
            case 'K': // cursor down
                {
                    // MoveDown* 
                    //delete down;
                    MoveDown* down = new MoveDown;
                    
                    return Interaction::command(down);
                }

            // go to beginning of line
            case 'Y':
                {
                  
                   MoveHome* home = new MoveHome;
                    
                    return Interaction::command(home);
                }

                // move to end of line

            case 'P':
                {
                   
                   MoveEnd* end = new MoveEnd;
                    
                    return Interaction::command(end);
                }

            case 'J':
                {
                    // move to new line
                    NewLine* newline = new NewLine;
                   
                    return Interaction::command(newline);

                }

               // movew to new line
            case 'M':
                {

      
                    NewLine* newline = new NewLine;
                   
                    return Interaction::command(newline);
                }

            case 'H':
            {
                // go back one space
                Backspace* back = new Backspace;
                return Interaction::command(back);
            }

            case 'D':
            {
                // delete entire line
                DeleteLine* d = new DeleteLine;
                return Interaction::command(d);
            }
            
            }
        }   


        
        else
        {
           // insert character
            Character* cha = new Character{keypress.code()};
            return Interaction::command(cha);




        }
    }

}


