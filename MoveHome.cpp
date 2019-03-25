// MoveHome.cpp
#include "MoveHome.hpp"

void MoveHome::execute(EditorModel& model)
{
	previousCol = model.cursorColumn();

	model.goToBeginningOfLine();

}

void MoveHome::undo(EditorModel& model)
{
	model.setColumn(previousCol);
}