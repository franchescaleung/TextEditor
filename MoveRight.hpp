// MoveRight.hpp
#ifndef MOVERIGHT_HPP
#define MOVERIGHT_HPP

#include "Command.hpp"
#include "EditorModel.hpp"

class MoveRight : public Command
{

public:
	virtual void execute(EditorModel& model) override;
	virtual void undo(EditorModel& model) override;
	


};

#endif