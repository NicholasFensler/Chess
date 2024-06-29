#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <string>
#include <vector>
#include "ChessBoard.h"
#include "Position.h"

class ChessBoard;
enum Color { WHITE, BLACK };

class ChessPiece {
private: 

protected:
	ChessBoard* board;
	Position position;
	Color color;
public:
	ChessPiece(ChessBoard* board, Color color);
	int getRow();
	int getColumn();
	Color getColor();
	void getPosition();
	void setPosition(Position aPosition);
	virtual std::string toString();			//VIRTUAL FUNCTIONS MEANT FOR REDEFINITION IN SUBCLASSES AKA PAWNS, ROOKS, ETC
	virtual std::vector<Position>* legalMoves();

};

#endif
