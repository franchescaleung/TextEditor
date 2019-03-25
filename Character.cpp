//Character.cpp
#include "Character.hpp"


Character::Character(char character)
	:key{character}
{

}

void Character::execute(EditorModel& model)
{

	//insert typed character onto editor
	model.addChar(key);

}

void Character::undo(EditorModel& model)
{
	// delete character typed
	model.deleteChar();
	
}