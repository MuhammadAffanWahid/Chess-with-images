
#pragma once
#include "Position.h"
#include "graphics.h"

#include <iostream>
using namespace std;


enum Color { Black = -1, White = 1 };
enum COLOR { Black_P = 8, White_P = 1 };

class Board;

class Piece
{
protected:
	Color C;
	Position P;
	Board* B;

	static bool IsHorizonMove(Position S, Position E);

	static bool IsVerticalMove(Position S, Position E);

	static bool IsDiagonalMove(Position S, Position E);
	static bool IsHorizonPathClear(Position S, Position E, Board* B);

	static bool IsVerticalPathClear(Position S, Position E, Board* B);

	static bool IsDiagonalPathClear(Position S, Position E, Board* B);
public:
	Piece() {
	}
	Piece(Position p, Color c, Board* b);
	virtual bool isLegel(Position EP) = 0;
	void Move(Position EP);
	virtual void Draw() = 0;
	Color getColor();
	virtual void unDraw() = 0;


	~Piece();
};

