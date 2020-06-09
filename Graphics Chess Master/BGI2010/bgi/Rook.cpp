#include "Rook.h"


Rook::Rook()
{
}

Rook::Rook(Position p, Color c, Board* b) :
	Piece(p, c, b) {}

bool Rook::isLegel(Position EP)
{
	
	return (IsHorizonMove(P, EP) && IsHorizonPathClear(P, EP, B)) 
									||
		    (IsVerticalMove(P, EP) && IsVerticalPathClear(P, EP, B));

}

void Rook::Draw()
{
	int x = P.ci * 75;
	int y = P.ri * 75;
	int a = (P.ci + 1) * 75;
	int b = (P.ri + 1) * 75;

	if (C == White)
	{
		cout << "r";

		if ((P.ri + P.ci) % 2 == 0)
		{

			readimagefile("img/WRL.jpg", x + 5, y + 5, a - 5, b - 5);

		}

		else
		{
			readimagefile("img/WRD.jpg", x + 5, y + 5, a - 5, b - 5);
		}
	}
	else
	{
		cout << "R";

		
		if ((P.ri + P.ci) % 2 == 0)
		{

			readimagefile("img/DRL.jpg", x + 5, y + 5, a - 5, b - 5);

		}

		else
		{

			readimagefile("img/DRD.jpg", x + 5, y + 5, a - 5, b - 5);
		}
	}
}

void Rook::unDraw()
{
	cout << " ";

}

Rook::~Rook()
{
}

