// EditorModel.cpp
//
// ICS 45C Winter 2019
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include "EditorModel.hpp"
#include "EditorException.hpp"
#include <string>
#include <iostream>

EditorModel::EditorModel()
	: currentLine{1}, currentColumn{1}
{

	allText.push_back(""); //
	ErrorMessage = "";

}


int EditorModel::cursorLine() const // Y
{
    return currentLine;
}


int EditorModel::cursorColumn() const // X
{
    return currentColumn;
}


int EditorModel::lineCount() const
{
    return allText.size();
}


const std::string& EditorModel::line(int lineNumber) const // not static = not constant...
{

	static std::string someText;
    someText = allText.at(lineNumber-1); // use at so error can be checked 
    return someText;

}


const std::string& EditorModel::currentErrorMessage() const // static = constant...
{
    //static std::string errorMessage = ErrorMessage;
    static std::string errorMessage;
    errorMessage = ErrorMessage;
    return errorMessage;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
	ErrorMessage = errorMessage;
}


void EditorModel::clearErrorMessage()
{
	ErrorMessage = "";
}

// own functions

void EditorModel::moveRight()
{
	// if current y position is equal to line count and
	// current column is size of line + 1 then show error

	if (currentColumn == (line(currentLine).size() + 1) && currentLine == lineCount())
	{
		// no need to set error, already done in interaction processor
		throw(EditorException("Already at end"));
			
	}

	else if (currentColumn == (line(currentLine).size() + 1) && currentLine != lineCount()) // if line has reached last column, but line is not at end of file
	{
		// just go to next line
		currentLine = currentLine + 1; // go to next line
		currentColumn = 1;	// go back to first spot
	}
	

	else // just move column over 1
	{
		// error message alread cleared after every loop
		currentColumn = currentColumn + 1;
	}
}

// move left one space
void EditorModel::moveLeft()
{

	if (currentColumn == 1 && currentLine == 1) // if at beginnging of file, can't move left so show error
	{
		// error message set while throwing exception
		throw(EditorException("Already at beginning"));
	}

	else if (currentLine != 1 && currentColumn == 1) // if moving left at first column, go to end of column above
	{
		clearErrorMessage();
		currentLine = currentLine - 1;
		currentColumn = line(currentLine).size() + 1;


	}
	else // just move column left by 1 if not at beginning of line
	{
		clearErrorMessage();
		currentColumn = currentColumn - 1;
	}
	
	
}

// add character to the current column, current line
void EditorModel::addChar(char toAdd)
{
	// insert at current line the character toAdd

	allText.at(currentLine-1).insert(allText.at(currentLine-1).begin() + (currentColumn-1), toAdd);
	// move to next column
	currentColumn = currentColumn + 1;
	
}

// make current line and current column ""
void EditorModel::deleteChar() 
{
	//if at beginning, set to 1, 1
	if (currentColumn == 1 && currentLine == 1) // throw error if at
	{
		currentColumn = 1;
		currentLine = 1;
		
		
	}
		
	else // if in middle of a line
	{	
		if (currentColumn >= 2) // if not at begining of line
		{
			lastChar = getCurrentChar(); // remember character deleted
		}
		
		else // if at beginning, go up one line
		{
			currentLine = currentLine - 1;
		}
		currentColumn = currentColumn - 1; // go back one column
		// erase line before
		allText.at(currentLine-1).erase(allText.at(currentLine-1).begin() + currentColumn-1);
		

	}
}


// cursor moves up by one line
void EditorModel::moveUp()
{
	if (currentLine == 1)
	{
		// thorw error if already at top and trying to move up
		throw(EditorException("Already at top"));
	}

	else
	{
		
		currentLine = currentLine - 1;
		if (currentColumn > line(currentLine).size() + 1) // if line above is shorter, go to end of line
		{
			currentColumn = line(currentLine).size() + 1;
		}


	}
}


// cursoer moves down
void EditorModel::moveDown()
{
	if (currentLine == lineCount()) // if at end of file, throw error
	{
		// throw exception
		throw(EditorException("Already at end"));
	}

	else
	{
		
		currentLine = currentLine + 1;
		if (currentColumn > line(currentLine).size() + 1) // if previous line is longer than current line, go to last column of current line
		{
			currentColumn = line(currentLine).size() + 1;
		}
	}
}

// cursor goes to first column of current line
// no error message shown if already at beginning
void EditorModel::goToBeginningOfLine()
{
	currentColumn = 1;
}

// // used to set current column in other classes
// // used in newline.cpp
void EditorModel::setColumn(int col)
{
	currentColumn = col;
}


// cursor goes to just one space beyond end of current line
// no error if already at end
void EditorModel::goToEndOfLine()
{
	currentColumn = line(currentLine).size() + 1;
}


// set new line 
// used in newline.cpp function: undo
void EditorModel::setLine(int row)
{

	currentLine = row;
	
	
}



// go to beginning of new line

void EditorModel::goToNewLine()
{
	// move text to next line
	// remember last line for undo later
	lastLine = line(currentLine);
	allText.insert(allText.begin() + currentLine, allText.at(currentLine-1).substr(currentColumn-1));
	// erase the text on previous line starting from previous position
	allText.at(currentLine-1).erase(allText.at(currentLine-1).begin() + (currentColumn-1), allText.at(currentLine-1).end());

	// change line and column
	currentLine = currentLine + 1;
	currentColumn = 1;
	
	
}


// delete one character when back space
// very similar to delete char used to undo inserting characters
// but this one sets error messages and moves lines together
void EditorModel::backspace()
{
	// if at beginning of file, send error
	if (currentColumn == 1 && currentLine == 1) // throw error if at beginning
	{
		
		throw(EditorException("Already at beginning"));
		
		
	}

	else if (currentColumn == 1) // if at column one
	{
		
		currentLine = currentLine - 1; // go to line above because at beginning of line
		currentColumn = allText.at(currentLine-1).size()+ 1; // go to end of new line
		allText.at(currentLine-1) = allText.at(currentLine-1) + allText.at(currentLine); // add lines together
		allText.erase(allText.begin() + currentLine); // erase line below
		
	}

	else // if in middle of a line
	{	
		lastChar = getCurrentChar(); // remember character deleted
		currentColumn = currentColumn - 1; // go back one column
		allText.at(currentLine-1) = allText.at(currentLine-1).erase(currentColumn-1,1);
	}
}

// returns char at current line and column
char EditorModel::getCurrentChar()
{
	return allText.at(currentLine-1).at(currentColumn-2);
	
}

// return last char variable which remembers the laSt char
char EditorModel::returnLastChar()
{
	return lastChar;
}

// delete line
void EditorModel::deleteLine() 
{
	// if at line 1 and everything is empty then throw exception

	if (currentColumn == 1 && currentLine == 1 && line(currentLine).length() == 0)
	{
		
		throw(EditorException("Already empty"));
	}
 
 	// if at first line then rememeber line then keep last line and insert and erase line
 	// set column and line at 1
	else if	(currentLine == 1 && lineCount() == 1) 
	{
	
		lastLine = line(currentLine);
		allText.insert(allText.begin() + currentLine, "");
		allText.erase(allText.begin() + (currentLine - 1));
		currentColumn = 1;
		currentLine = 1;
	}

	else if (currentLine == 1) // condition isn't line count one
	{
		// move everything up
		//keep at column1 line 1
		lastLine = line(currentLine);
		allText.erase(allText.begin() + (currentLine -1));
		currentColumn = allText.at(currentLine-1).size()+ 1;
		//move stuff up one line

	}
	else
	{
		lastLine = line(currentLine); // remember last line
		allText.erase(allText.begin() + (currentLine - 1));
		
		if (currentColumn > line(currentLine - 1).size() + 1) // if previous line is longer than current line, go to last column of current line
		{
			currentColumn = line(currentLine - 1).size() + 1;
		}

		currentLine = currentLine - 1; // go up one line
		
	}
	
}

// returns last remembered line
std::string EditorModel::returnLastLine()
{
	return lastLine;
}


// used in delete line
// put line back to original
void EditorModel::putLine(std::string l)
{

	allText.insert(allText.begin() + (currentLine - 1), l);
	if (currentLine == 1)
	{
		allText.erase(allText.begin() + (currentLine));
	}



}


// erases current line
// changes col and row
// puts text back
// used for undo new line

void EditorModel::cleaningNewLine(std::string l, int previousCol, int previousLine)
{


	allText.erase(allText.begin() + (currentLine - 1));

	currentLine = previousLine;
	currentColumn = previousCol;

	allText.at(currentLine - 1).append(l);
	
}

