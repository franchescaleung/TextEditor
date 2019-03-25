// MoveLeft.hpp
#ifndef MOVELEFT_HPP
#define MOVELEFT_HPP

#include "Command.hpp"
#include "EditorModel.hpp"

class MoveLeft : public Command
{

public:
	virtual void execute(EditorModel& model) override;
	virtual void undo(EditorModel& model) override;
	


};

#endif