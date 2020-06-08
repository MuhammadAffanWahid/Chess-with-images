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
		int x = P.ci * 100;
		int y = P.ri * 100;
		int a = (P.ci + 1) * 100;
		int b = (P.ri + 1) * 100;

		if (C == White)
		{
			if ((P.ri + P.ci) % 2 == 0)
			{

				readimagefile("img/WBL.jpg", x + 10, y + 10, a - 10, b - 10);

			}

			else
			{
				readimagefile("img/WBD.jpg", x + 10, y + 10, a - 10, b - 10);
			}

			cout << "b";
		}
		else
		{
			cout << "B";

			if ((P.ri + P.ci) % 2 == 0)
			{

				readimagefile("img/DBL.jpg", x + 10, y + 10, a - 10, b - 10);

			}

			else
			{
				readimagefile("img/DBD.jpg", x + 10, y + 10, a - 10, b - 10);
			}
		}

	}
	virtual void unDraw()
	{
		cout << " ";
	}


	~Bishop();
};

