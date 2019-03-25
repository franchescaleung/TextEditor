//NewLine.hpp
#ifndef NEWLINE_HPP
#define NEWLINE_HPP

#include "Command.hpp"
#include "EditorModel.hpp"
#include <string>

class NewLine : public Command
{

public:

	virtual void execute(EditorModel& model) override;
	virtual void undo(EditorModel& model) override;
	
private:
	int previousLine;
	int previousCol;
	std::string lastLine;

};

#endif