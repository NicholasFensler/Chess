///Hello Professor, thank you for this semester professor. 
//bug notes--> for some reason the pawns are always allowed to move twice despite the hard coding of checking it's row.
//if my presentation was lackluster i apologize i am running of very little sleep because of finals week and was also cramming in to finish this up
//i've never waited this long to turn in an assignment (its 8:22 on 6/5/2024) 


#include "ChessBoard.h";
#include <vector>

using namespace std;

Position stringToPosition(char[]);

//welcome to main
int main() {

	cout << "Welcome to Chess (Mess)\n\n";

		//create, initialize and print board:
		ChessBoard board = ChessBoard();
		board.initialize();
		board.print();
		//user inputed values:
		Position from;		
		Position to;		
		bool flag = false;

		/*//some test code
		Position from(1, 1), to(2, 1);
		board.move(from, to);
		board.print();
		*/

		//main user input loop and functionality
		cout << "Please enter the position of the piece you would like to move." << endl; 
		cout << "For example: e2. possible moves will be listed after, input a possible position to move." << endl;
		cout << "An error will occur if you incorrectly send more data then necessary." << endl << endl;
		char input[2] = { ' ',' ' };

		//main input loop
		while (true) {
			//ENTERING PIECE TO MOVE
			cout << "what piece would you like to move: ";
			while (!flag){		//turn loop
				cin >> input;
				from = stringToPosition(input);						//set position = to fromPosition

				if (from.isValid(from)) {							//if position is on board

						if (board.getPiece(from)!=nullptr){			//if there's a piece at position find it's possible moves
							vector<Position>* moves = board.getPiece(from)->legalMoves();	
							if (moves == nullptr) 
								cout << "no moves for this piece:\n";							
							else{
								cout << "Here are your possible moves:\t";
								for (auto move : *moves) {
									cout << move.toString() << ", ";
								}
								cout << "\npick a move: ";
								cin >> input;
								to = stringToPosition(input);
									for (auto possibleMove : *moves) {
										if (to == possibleMove) {  
											board.move(from, to);		//move piece
											delete moves;				//cleanup
											moves = nullptr;
											flag = true;				//for loops
											break;
										}
											
									}
								} 							

							
						}
				}
				else { 
					cout << "Invalid move, Out of bounds. Enter move again: "; 
				}
				
			}//end of if valid input loop & execute loop
			flag = false;	//loop correction
			cout << endl;
			board.print();
			
		}//end of main input loop
	
	
	return 0;
}

Position stringToPosition(char input[]) {
	Position temporary;
	temporary.setColumn((int)input[0] - 'a');
	temporary.setRow(input[1] - '0'- 1 );
	return temporary;
}