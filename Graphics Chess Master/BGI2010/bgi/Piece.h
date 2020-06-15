
#pragma once
#include "Position.h"
#include "graphics.h"
//#include"Board.h"
#include <iostream>
using namespace std;


enum Color { Black = -1, White = 1 };
enum COLOR { Black_P = 8, White_P = 1 };

class Board;

class Piece
{
public:


	friend class Board;
	Board* Brd;

	static bool IsHorizonMove(Position S, Position E);

	static bool IsVerticalMove(Position S, Position E);

	static bool IsDiagonalMove(Position S, Position E);
	static bool IsHorizonPathClear(Position S, Position E, Board* B);

	static bool IsVerticalPathClear(Position S, Position E, Board* B);

	static bool IsDiagonalPathClear(Position S, Position E, Board* B);
//public:

	Position P;
	Color C;

	Piece() {
	}
	Piece(Position p, Color c, Board* b);
	virtual bool isLegel(Position EP, bool IsRealMove = false, bool SelfCheck = false) = 0;
	void Move(Position EP, bool IsReal = false);
	virtual void Draw() = 0;
	Color getColor();
	virtual void unDraw() = 0;


	//~Piece();
};

