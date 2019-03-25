//Character.hpp
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Command.hpp"
#include "EditorModel.hpp"

class Character : public Command
{

public:

	explicit Character(char letter);

	virtual void execute(EditorModel& model) override;
	virtual void undo(EditorModel& model) override;
	
private:
	char key;

};

#endif