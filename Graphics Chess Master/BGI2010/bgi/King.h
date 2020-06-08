#pragma once
#include "Piece.h"
class King : public Piece
{
public:
	King();
	King(Position p, Color c, Board* b) :
		Piece(p, c, b) {}
	virtual bool isLegel(Position EP)
	{
		return !(abs(EP.ri - P.ri) > 1 || abs(EP.ci - P.ci) > 1);
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
			cout << "k";
		

			if ((P.ri + P.ci) % 2 == 0)
			{

				readimagefile("img/WKL.jpg", x , y , a , b );

			}

			else
			{
				readimagefile("img/WKD.jpg", x + 10, y + 10, a - 10, b - 10);
			}

		}
		else
		{
			cout << "K";


			if ((P.ri + P.ci) % 2 == 0)
			{

				readimagefile("img/DKL.jpg", x + 10, y + 10, a - 10, b - 10);

			}

			else
			{
				readimagefile("img/DKD.jpg", x + 10, y + 10, a - 10, b - 10);
			}
		}

	}
	virtual void unDraw()
	{
		cout << " ";
	}


	~King();
};

