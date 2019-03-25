// MoveRight.cpp
#include "MoveRight.hpp"

void MoveRight::execute(EditorModel& model)
{
	// move right
	model.moveRight();

}

void MoveRight::undo(EditorModel& model)
{
	// move back left one
	model.moveLeft();
}