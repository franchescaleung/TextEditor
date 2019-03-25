// DeleteLine.cpp
#include "DeleteLine.hpp"

void DeleteLine::execute(EditorModel& model)
{
	col = model.cursorColumn();
	line = model.cursorLine();
	model.deleteLine();
	lastLine = model.returnLastLine();
	

}

void DeleteLine::undo(EditorModel& model)
{

	model.setLine(line);
	model.setColumn(col);

	model.putLine(lastLine);
	



}