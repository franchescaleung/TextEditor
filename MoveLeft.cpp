// MoveLeft.cpp
#include "MoveLeft.hpp"

void MoveLeft::execute(EditorModel& model)
{
	// move left one
	model.moveLeft();

}

void MoveLeft::undo(EditorModel& model)
{
	// move back right
	model.moveRight();
}