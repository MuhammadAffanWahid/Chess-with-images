#pragma once
#include "Piece.h"
class Horse : public Piece
{
public:
	Horse();
	Horse(Position p, Color c, Board* b) :
		Piece(p, c, b) {}
	virtual bool isLegel(Position EP)
	{
		return  (((abs(P.ri - EP.ri) == 2) && (abs(P.ci - EP.ci) == 1)) || ((abs(P.ri - EP.ri) == 1) && (abs(P.ci - EP.ci) == 2)));
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
			cout << "h";
			
			
				//sector((P.ci*100)+50, 50 , 0, 90, 20, 20);

				if ((P.ri + P.ci) % 2 == 0)
				{
					
					readimagefile("img/WHL.jpg", x + 10, y + 10, a - 10, b - 10);

				}

				else
				{
					readimagefile("img/WHD.jpg", x + 10, y + 10, a - 10, b - 10);
				}

			
		}
		else
		{
			cout << "H";
			
				//sector((P.ci * 100) + 50, 750, 0, 90, 20, 20);
				if ((P.ri + P.ci) % 2 == 0)
				{
				
					readimagefile("img/DHL.jpg", x + 10, y + 10, a - 10, b - 10);

				}

				else
				{
					readimagefile("img/DHD.jpg", x + 10, y + 10, a - 10, b - 10);
				}
			
		}
			

	}
	virtual void unDraw()
	{
		cout << " ";
	}


	~Horse();
};

