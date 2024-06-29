#include "ChessPiece.h"

//constructor
ChessPiece::ChessPiece(ChessBoard* theBoard, Color aColor) {
	board = theBoard;//the board the piece is on
	color = aColor;//sets color
}

//main functions
int ChessPiece::getRow() {
	return position.getRow();
}
int ChessPiece::getColumn() {
	return position.getColumn();
}
Color ChessPiece::getColor() {
	return color;
}
void ChessPiece::getPosition() {
	board->getPosition(this);		//sends this piece to the chessboard getposition class, no need to rewrite it
}
void ChessPiece::setPosition(Position newPosition) {
	position = newPosition;
}
std::string ChessPiece::toString() {
	return "CP";
}
std::vector<Position>* ChessPiece::legalMoves(){
	return nullptr;
}

