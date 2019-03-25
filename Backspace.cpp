//Backspace.cpp
#include "Backspace.hpp"


void Backspace::execute(EditorModel& model)
{
	col = model.cursorColumn();
	model.backspace();

	if (col > 1)
	{
		previousChar = model.returnLastChar();
	}
	
	
}

void Backspace::undo(EditorModel& model)
{
	if (col != 1) // if not at beginning of column
	{
		// just add character back
		model.addChar(previousChar);
	}
	
	else // go to next line
	{
		model.goToNewLine();
	}

	
}