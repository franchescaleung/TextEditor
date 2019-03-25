//NewLine.cpp
#include "NewLine.hpp"


void NewLine::execute(EditorModel& model)
{
	// remember previous line and col
	previousLine = model.cursorLine();
	previousCol = model.cursorColumn();

	// remember last line
	lastLine = model.line(previousLine);

	model.goToNewLine();

}

void NewLine::undo(EditorModel& model) // think about setting the line and column
{
	//remember last line
	lastLine = model.line(model.cursorLine());
	// place text back and set line and col back
	model.cleaningNewLine(lastLine, previousCol, previousLine);
	
	
}