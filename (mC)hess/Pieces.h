#ifndef PIECES_H
#define PIECES_H
#include "ChessPiece.h"
#include "Position.h"
#include <string>
#include <vector>

class King : public ChessPiece {
	public:
		King(ChessBoard *board, Color color) : ChessPiece(board, color) {}
		std::string toString() {	
			if (color == WHITE)
				return "WK";
			else if (color == BLACK)
				return "BK";
		}				 
		std::vector<Position>* legalMoves() { return nullptr; }//<--------- this is where we code how the king can move
};

class Queen : public ChessPiece {
public:
	Queen(ChessBoard* board, Color color) : ChessPiece(board, color) {}
	std::string toString() {
		if (color == WHITE)
			return "WQ";
		else if (color == BLACK)
			return "BQ";
	}
	std::vector<Position>* legalMoves() { return nullptr; };//<--------- this is where we code how the queen can move
};

class Knight : public ChessPiece {
public:
	Knight(ChessBoard* board, Color color) : ChessPiece(board, color) {}
	std::string toString() {
		if (color == WHITE)
			return "WN";
		if (color == BLACK)
			return "BN";
	}
	std::vector<Position>* legalMoves() { return nullptr; }	//<--------- this is where the knight code how the knight can move
};
///=====================================================================================================================================================================
class Rook : public ChessPiece {	
public:
	Rook(ChessBoard* board, Color color) : ChessPiece(board, color) {}
	std::string toString() {
		if (color == WHITE)
			return "WR";
		if (color == BLACK)
			return "BR";
	}
	std::vector<Position>* legalMoves() 
	{ 
		std::vector<Position>* moves = new std::vector<Position>();
		Position temp = position;	//dummy position

		//position[col+][row]	right moves
		while (temp.isValid(temp)) {
			temp.setColumn(temp.getColumn() + 1);		//< increment the column
			if (temp.isValid(temp)){					//< if new position is on board
				if (board->getPiece(temp) != nullptr) {	//< if new position has a piece
					moves->push_back(temp);				//< add that as a possible location and stop
					break;								//< we cant go to any position past that point
				}
				else
					moves->push_back(temp);				//< no piece at location keep going. 
			}				
		}

		temp = position;//temp reset
		//position[col-][row]	left moves
		while (temp.isValid(temp)) {
			temp.setColumn(temp.getColumn() - 1);
			if (temp.isValid(temp))
				if (board->getPiece(temp) != nullptr) {
					moves->push_back(temp);
					break;
				}
				else
					moves->push_back(temp);
		}

		temp = position;//temp reset
		//position[col][row+]	up moves
		while (temp.isValid(temp)) {
			temp.setRow(temp.getRow() + 1);
			if (temp.isValid(temp))
				if (board->getPiece(temp) != nullptr) {
					moves->push_back(temp);
					break;
				}
				else
					moves->push_back(temp);
		}

		temp = position;//temp reset
		//position[col][row-]	down moves
		while (temp.isValid(temp)) {
			temp.setRow(temp.getRow() - 1);
			if (temp.isValid(temp))
				if (board->getPiece(temp) != nullptr) {
					moves->push_back(temp);
					break;
				}
				else
					moves->push_back(temp);
		}	
			return moves;		
	}	
};

class Bishop : public ChessPiece {
public:
	Bishop(ChessBoard* board, Color color) : ChessPiece(board, color) {}
	std::string toString() {
		if (color == WHITE)
			return "WB";
		else if (color == BLACK)
			return "BB";
	}
	std::vector<Position>* legalMoves()
	{ 
		//possible moves	
		std::vector<Position>* moves = new std::vector<Position>();
		Position temp = position;	//dummy position

		//position[col+][row+] up right
		while (temp.isValid(temp)) {
			temp.setColumn(temp.getColumn() + 1);
			temp.setRow(temp.getRow() + 1);
			if (temp.isValid(temp))
				if (board->getPiece(temp) == nullptr)
					moves->push_back(temp);
				else if (color != board->getPiece(temp)->getColor()) {
					moves->push_back(temp);
					break;
				}
				else
					break;

		}

		temp = position;//temp reset
		//position[col+][row-] down right
		while (temp.isValid(temp)) {
			temp.setColumn(temp.getColumn() + 1);
			temp.setRow(temp.getRow() - 1);
			if (temp.isValid(temp))
				if (board->getPiece(temp) == nullptr)
					moves->push_back(temp);
				else if (color != board->getPiece(temp)->getColor()) {
					moves->push_back(temp);
					break;
				}
				else
					break;
		}

		temp = position;//temp reset
		//position[col-][row+] up left
		while (temp.isValid(temp)) {
			temp.setColumn(temp.getColumn() - 1);
			temp.setRow(temp.getRow() + 1);
			if (temp.isValid(temp))
				if (board->getPiece(temp) == nullptr)
					moves->push_back(temp);
				else if (color != board->getPiece(temp)->getColor()) {
					moves->push_back(temp);
					break;
				}
				else
					break;
		}

		temp = position;//temp reset
		//position[col-][row-] down left
		while (temp.isValid(temp)) {
			temp.setColumn(temp.getColumn() - 1);
			temp.setRow(temp.getRow() - 1);
			if (temp.isValid(temp))
				if (board->getPiece(temp) == nullptr)
					moves->push_back(temp);
				else if (color != board->getPiece(temp)->getColor()) {
					moves->push_back(temp);
					break;
				}
				else
					break;
		}
			return moves;	
	}//end of legalMoves()	
};



class Pawn : public ChessPiece {
public:
	Pawn(ChessBoard* board, Color color) : ChessPiece(board, color) {}
	std::string toString() {
		if (color == WHITE)
			return "WP";
		else if (color == BLACK)
			return "BP";
	}
	std::vector<Position>* legalMoves() 
	{ 
		std::vector<Position>* moves = new std::vector<Position>();
		Position temp = position;										//We will assume that Black pawns will always be on the top side here and White pawns will be on the bottom 
		//WHITE PAWN CODE
		if (this->getColor() == WHITE) {		
			//debug
			temp.setRow(temp.getRow() + 1);
			if (temp.isValid(temp) && board->getPiece(temp)==nullptr) {//no piece at location in front: can move forward
				moves->push_back(temp);
				temp.setColumn(position.getColumn() - 1);			//check upleft
				if (temp.isValid(temp) && board->getPiece(temp) != nullptr){	//if piece found, allow move
					moves->push_back(temp);
				}
				temp.setColumn(position.getColumn() + 1);			//check upright
				if (temp.isValid(temp) && board->getPiece(temp) != nullptr) {
					moves->push_back(temp);
				}
				if (position.getRow() == 1); {	//if it hasn't moved yet aka second row 
					temp = position;
					temp.setRow(position.getRow() + 2);	//check two spaces up
					if (temp.isValid(temp) && board->getPiece(temp) == nullptr) 
						moves->push_back(temp);					
				}					
			}	
		}//end of if white
		else {									//the piece is black and moving downwards
			temp.setRow(temp.getRow() - 1);
			if (temp.isValid(temp) && board->getPiece(temp) == nullptr) {//no piece at location in front: can move forward
				moves->push_back(temp);
				temp.setColumn(position.getColumn() - 1);			//check downleft
				if (temp.isValid(temp) && board->getPiece(temp) != nullptr) {	//if piece found, allow move
					moves->push_back(temp);
				}
				temp.setColumn(position.getColumn() + 1);			//check downright
				if (temp.isValid(temp) && board->getPiece(temp) != nullptr) {
					moves->push_back(temp);
				}
				if (position.getRow() == 6); {	//if it hasn't moved yet aka second row 
					temp = position;
					temp.setRow(position.getRow() - 2);	//check two spaces down
					if (temp.isValid(temp) && board->getPiece(temp) == nullptr)
						moves->push_back(temp);
				}
			}
		}//end of if black
			return moves;
	}//end of legalMoves() 
};

#endif