#pragma once	
#include "Piece.h"
class Rook : public Piece
{
public:
	Rook();
	Rook(Position p, Color c, Board* b);

	virtual bool isLegel(Position EP, bool IsRealMove = false, bool SelfCheck = false)
	{
		if (SelfCheck && Brd->IsCheckAfterMove())
			return false;

		return (IsHorizonMove(P, EP) && IsHorizonPathClear(P, EP, Brd))
			||
			(IsVerticalMove(P, EP) && IsVerticalPathClear(P, EP, Brd));

	}
	virtual void Draw();
	virtual void unDraw();
	~Rook();
};

