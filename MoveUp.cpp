// MoveUp.cpp
#include "MoveUp.hpp"

void MoveUp::execute(EditorModel& model)
{

	// move up by one
	model.moveUp();

}

void MoveUp::undo(EditorModel& model)
{
	// move back down by one
	model.moveDown();
}