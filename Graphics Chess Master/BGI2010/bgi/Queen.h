#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen();

	Queen(Position p, Color c, Board* b);

	virtual bool isLegel(Position EP);
	void Move(Position EP);
	virtual void Draw();
	virtual void unDraw();
	~Queen();
};

