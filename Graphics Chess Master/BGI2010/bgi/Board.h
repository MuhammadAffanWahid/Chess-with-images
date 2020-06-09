#pragma once
#include "Piece.h"
#include "Pawn.h"
#include "Position.h"
#include "graphics.h"

class Board
{
protected:
	Piece* B[8][8];
	char HL[8][8];
	Color Turn;
	Position S, E;
	friend class Piece;

public:
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
};

