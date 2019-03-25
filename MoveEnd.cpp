// MoveEnd.cpp
#include "MoveEnd.hpp"

void MoveEnd::execute(EditorModel& model)
{
	// move to just beyond the end of line
	previousCol = model.cursorColumn();
	model.goToEndOfLine();

}

void MoveEnd::undo(EditorModel& model)
{
	// move back to last spot
	model.setColumn(previousCol);
}