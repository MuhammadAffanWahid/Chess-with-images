#pragma once
#include "Piece.h"
class Bishop : public Piece
{
public:
	Bishop();
	Bishop(Position p, Color c, Board* b) :
		Piece(p, c, b) {}
	virtual bool isLegel(Position EP)
	{
		//return true;
		return (IsDiagonalMove(P, EP) && IsDiagonalPathClear(P, EP, B));
	}
	void Move(Position EP);
	virtual void Draw()
	{
		int x = P.ci * 75;
		int y = P.ri * 75;
		int a = (P.ci + 1) * 75;
		int b = (P.ri + 1) * 75;

		if (C == White)
		{
			if ((P.ri + P.ci) % 2 == 0)
			{

				readimagefile("img/WBL.jpg", x + 5, y + 5, a - 5, b - 5);

			}

			else
			{
				readimagefile("img/WBD.jpg", x + 5, y + 5, a - 5, b - 5);
			}

			cout << "b";
		}
		else
		{
			cout << "B";

			if ((P.ri + P.ci) % 2 == 0)
			{

				readimagefile("img/DBL.jpg", x + 5, y + 5, a - 5, b - 5);

			}

			else
			{
				readimagefile("img/DBD.jpg", x + 5, y + 5, a - 5, b - 5);
			}
		}

	}
	virtual void unDraw()
	{
		cout << " ";
	}


	~Bishop();
};

