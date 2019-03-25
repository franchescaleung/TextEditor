// MoveHome.hpp
#ifndef MOVEHOME_HPP
#define MOVEHOME_HPP

#include "Command.hpp"
#include "EditorModel.hpp"

class MoveHome : public Command
{

public:
	virtual void execute(EditorModel& model) override;
	virtual void undo(EditorModel& model) override;

private:
	int previousCol;


};

#endif