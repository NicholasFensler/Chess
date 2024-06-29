#ifndef POSITION_H
#define POSITION_H
#include <string>

class Position {	
private:
	int column;
	int row;
public:
	Position() {
		column = 0;
		row = 0;
	}
	Position(int r, int c) :  row(r),column(c) {
			column = c;
			row = r;
	}
	bool operator==(const Position&right) {
		return (row == right.row) && (column == right.column);
	}

	void setRow(int r) { row = r; }			//only using this in the piece classes to determine pieces possible positions
	void setColumn(int c) { column = c; }		//ditto
	int getRow() { return row; }
	int getColumn() { return column; }

	bool isValid(Position position){
		//checks if the position is within the value on the board, row=0-7 and col=0-7
		if (position.getRow()>=0 && position.getRow()<=7 && position.getColumn()>=0 && position.getColumn()<=7) 
			return true;
		else //otherwise return false
			return false; 
	}

	//toString used for nice formatting to the user.
	std::string toString() {
		switch (this->getColumn()) {
		case 0:
			return "a" + std::to_string(this->getRow() + 1);
		case 1:
			return "b" + std::to_string(this->getRow() + 1);
		case 2:
			return "c" + std::to_string(this->getRow() + 1);
		case 3:
			return "d" + std::to_string(this->getRow() + 1);
		case 4: 
			return "e" + std::to_string(this->getRow() + 1);
		case 5:
			return "f" + std::to_string(this->getRow() + 1);
		case 6:
			return "g" + std::to_string(this->getRow() + 1);
		case 7:
			return "h" + std::to_string(this->getRow() + 1);
		default:
			return "invalid location"; //<-- this case should not ever happen
		}
	}

	
};

#endif