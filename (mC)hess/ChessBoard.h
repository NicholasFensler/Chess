#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include "ChessPiece.h"
#include "Position.h"
#include <iostream>
#include <string>
		//this might not be needed depending on how implementation of the pieces works, the pieces will absolutely have 

class ChessPiece;

class ChessBoard {
private:
	ChessPiece* board[8][8];

public:
	ChessBoard();		//constructor
	~ChessBoard();		//destructor
	void initialize();	//constructor in a way/initializer 
	void print();
	ChessPiece* getPiece(Position& position);				//getPiece
	Position getPosition(ChessPiece* piece);
	bool placePiece(ChessPiece* piece, Position position);	//setPiece
	bool placePiece(ChessPiece* piece, int r, int c); 	//setPiece
	bool move(Position fromPosition,Position toPosition);
	std::string toString();
	
};

#endif
