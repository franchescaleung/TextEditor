// MoveUp.hpp
#ifndef MOVEUP_HPP
#define MOVEUP_HPP

#include "Command.hpp"
#include "EditorModel.hpp"

class MoveUp : public Command
{

public:
	virtual void execute(EditorModel& model) override;
	virtual void undo(EditorModel& model) override;
	


};

#endif