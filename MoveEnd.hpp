// MoveEnd.hpp
#ifndef MOVEEND_HPP
#define MOVEEND_HPP

#include "Command.hpp"
#include "EditorModel.hpp"

class MoveEnd : public Command
{

public:
	virtual void execute(EditorModel& model) override;
	virtual void undo(EditorModel& model) override;

private:
	int previousCol;


};

#endif