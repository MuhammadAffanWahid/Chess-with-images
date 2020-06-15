#pragma once
#include "Piece.h"
#include "Rook.h"
#include "Horse.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include "Position.h"
#include "graphics.h"

class Board
{
protected:
	char HL[8][8];
	Color Turn;
	Position S, E;
	friend class Piece;

public:
	Piece* B[8][8];
	Board();
	void DisplayMsg();
	void Init();
	void PrintBoard();//
	void Move(Position S, Position E);
	~Board();
	void TurnChange();
	void Highlight();
	void UnHighlight();
	void SelectDestination();
	void SelectPiece();
	bool IsValidSelection();
	bool IsValidDestination();
	void Play();
	void getRowColbyLeftClick(int & , int &);
	void DisplayMove(Position s , Position e);
	bool IsCheckAfterMove();//
	bool IsStaleMate();//
	bool IsCheckMate();//
	///////////////
	Position KingPos();
	bool IsCheck();

};

