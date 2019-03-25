// MoveDown.hpp
#ifndef MOVEDOWN_HPP
#define MOVEDOWN_HPP

#include "Command.hpp"
#include "EditorModel.hpp"

class MoveDown : public Command
{

public:
	virtual void execute(EditorModel& model) override;
	virtual void undo(EditorModel& model) override;
	


};

#endif