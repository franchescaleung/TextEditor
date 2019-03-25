// MoveDown.cpp
#include "MoveDown.hpp"

void MoveDown::execute(EditorModel& model)
{

	//  move down one line but same column or end of line
	model.moveDown();

}

void MoveDown::undo(EditorModel& model)
{
	// move back up
	model.moveUp();
}