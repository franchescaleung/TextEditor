// InteractionProcessor.cpp
//
// ICS 45C Winter 2019
// Project #4: People Just Love to Play with Words
//
// Implementation of the InteractionProcessor class

#include "InteractionProcessor.hpp"
#include "EditorException.hpp"
#include "Interaction.hpp"
#include "BooEditLog.hpp"

#include <iostream>

// This function implements command execution, but does not handle "undo"
// and "redo"; you'll need to add that handling.

void InteractionProcessor::run()
{
    view.refresh();


    while (true)
    {
        Interaction interaction = interactionReader.nextInteraction();

        if (interaction.type() == InteractionType::quit)
        {
            // cleans up all command pointers
            std::for_each(undo.begin(), undo.end(), [](Command* command) {delete command;});
            std::for_each(redo.begin(), redo.end(), [](Command* command) {delete command;});
            undo.clear();
            redo.clear();
          
            
     
            break;
        }

        else if (interaction.type() == InteractionType::undo)
        {
          
            if (undo.size() != 0)   // if undo stack is not empty
            {   
                
              
                Command* c = undo.back(); // reference to last action in undo stack
                redo.push_back(c); // add action
                c->undo(model); // undo the last action
                
                undo.pop_back(); // delete last action from undo stack
               

                model.clearErrorMessage();
                
                view.refresh();
            }

            
        }

        else if (interaction.type() == InteractionType::redo)
        {
            
            if (redo.size() != 0)
            {
             
                Command* c = redo.back();
                c->execute(model);
          
                undo.push_back(c);
              
                redo.pop_back();

                model.clearErrorMessage();
               
            }

            view.refresh();
        }
        else if (interaction.type() == InteractionType::command)
            /// MAKE SURE TO CLEAN UP!!
        {
            Command* command = interaction.command();


            try
            {
                command->execute(model);
                undo.push_back(command);

                

                if (redo.size() != 0)
                {
                     // cleans up all commands in redo
                    std::for_each(redo.begin(), redo.end(), [](Command* command) {delete command;});
                    

                 }
                 
                 redo.clear();
                 model.clearErrorMessage();
            
            }

            catch (EditorException& e)
            {
                model.setErrorMessage(e.getReason());
                delete command;
              
            }

            view.refresh();

            // Note that you'll want to be more careful about when you delete
            // commands once you implement undo and redo.  For now, since
            // neither is implemented, I've just deleted it immediately
            // after executing it.  You'll need to wait to delete it until
            // you don't need it anymore.

           // delete command;
        }
    }

}

