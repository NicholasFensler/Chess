#include "ChessBoard.h"
#include "Pieces.h"
#include <vector>
class CheessPiece;

//default constuctor
ChessBoard::ChessBoard() {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			board[i][j] = nullptr;
}
ChessBoard::~ChessBoard() {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			delete board[i][j];
}


void ChessBoard::print() {		//prints the state of the board.
	std::cout << "\t\t     BLACK\n";
	std::cout << "   +----+----+----+----+----+----+----+----+\n";
	for (int i = 7; i >= 0; i--) {
		std::cout << i+1;

		for (int j = 0; j < 8; j++) {
			std::cout << "  |";
			if (board[i][j] == nullptr) //no piece found, prints empty space
				std::cout << "  ";							
			else						//piece found
				std::cout << board[i][j]->toString(); 
		}//end of inner loop
		std::cout << "  |\n   +----+----+----+----+----+----+----+----+\n";
	}//end of outter loop
	std::cout << "     A    B    C    D    E    F    G    H\n";
	std::cout << "\t\t     WHITE\n\n";
}

//realchessboard initialization
void ChessBoard::initialize() {

	placePiece(new Rook(this, WHITE), 0, 0); 
	placePiece(new Knight(this, WHITE), 0, 1);
	placePiece(new Bishop(this, WHITE), 0, 2);
	placePiece(new Queen(this, WHITE), 0, 3);
	placePiece(new King(this, WHITE), 0, 4);
	placePiece(new Bishop(this, WHITE), 0, 5);
	placePiece(new Knight(this, WHITE), 0, 6);
	placePiece(new Rook(this, WHITE), 0, 7);	
	for (int i = 0; i < 8; i++) { 
		placePiece(new Pawn(this, WHITE), 1, i); 	
	}

	placePiece(new Rook(this, BLACK), 7, 0);
	placePiece(new Knight(this, BLACK), 7, 1);
	placePiece(new Bishop(this, BLACK), 7, 2);
	placePiece(new Queen(this, BLACK), 7, 3);
	placePiece(new King(this, BLACK), 7, 4);
	placePiece(new Bishop(this, BLACK), 7, 5);
	placePiece(new Knight(this, BLACK), 7, 6);
	placePiece(new Rook(this, BLACK), 7, 7);
	for (int i = 0; i < 8; i++) {
		placePiece(new Pawn(this, BLACK), 6, i);		
	}
}

ChessPiece* ChessBoard::getPiece(Position& position) {		
	//returns piece at a passed position if any, 
	if (board[position.getRow()][position.getColumn()] != nullptr)
		return board[position.getRow()][position.getColumn()];
	else
		return nullptr;
}

Position ChessBoard::getPosition(ChessPiece* piece) {// return the position of a piece.
	for (int r = 0; r < 8; r++) {
		for (int c = 0; c < 8; c++) {
			if (piece == board[r][c]) {
				return Position{r,c};
			}	
		}
	}
}

bool ChessBoard::placePiece(ChessPiece* piece, int r, int c){
	Position p(r, c);
	return placePiece(piece, p);
}

bool ChessBoard::placePiece(ChessPiece* piece, Position position) {
	//checks if there is a piece at the location
	if (board[position.getRow()][position.getColumn()] != nullptr){	
		
		if (getPiece(position)->getColor() != piece->getColor()) {			//if colors are not equal, take the piece at the location entered
			//std::cout << "taking/deleting piece\n";						//<----debug delete later or comment
			delete getPiece(position);	

			board[position.getRow()][position.getColumn()] = piece;
			piece->setPosition(position);			
			return true;
		}
		else//colors match, cannot place piece on own color
		{ return false; }
	}
	else {//there is no piece at location, just place piece	
		board[position.getRow()][position.getColumn()] = piece;
		piece->setPosition(position);
		return true;
	}
}

bool ChessBoard::move(Position fromPosition, Position toPosition) {
	if (placePiece(getPiece(fromPosition),toPosition)) {
		board[fromPosition.getRow()][fromPosition.getColumn()] = nullptr; //removing the piece from previous location
		return true;
	}
	else
		return false;
}

std::string ChessBoard::toString() {
	//debug?? unsure how to use it yet/atm
	return "?default stub return, location: ChessBoard.cpp toString";
}