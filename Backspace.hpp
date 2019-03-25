//Backspace.hpp
#ifndef BACKSPACE_HPP
#define BACKSPACE_HPP

#include "Command.hpp"
#include "EditorModel.hpp"
#include <string>
class Backspace : public Command
{

public:

	virtual void execute(EditorModel& model) override;
	virtual void undo(EditorModel& model) override;
	
private:
	char previousChar;
	int col;

};

#endif