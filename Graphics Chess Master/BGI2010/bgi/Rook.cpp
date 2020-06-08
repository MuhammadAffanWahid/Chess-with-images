#include "Rook.h"


Rook::Rook()
{
}

Rook::Rook(Position p, Color c, Board* b) :
	Piece(p, c, b) {}

bool Rook::isLegel(Position EP)
{
	
	return (IsHorizonMove(P, EP) && IsHorizonPathClear(P, EP, B)) || (IsVerticalMove(P, EP), IsVerticalPathClear(P, EP, B));

}

void Rook::Draw()
{
	int x = P.ci * 100;
	int y = P.ri * 100;
	int a = (P.ci + 1) * 100;
	int b = (P.ri + 1) * 100;

	if (C == White)
	{
		cout << "r";

		if ((P.ri + P.ci) % 2 == 0)
		{

			readimagefile("img/WRL.jpg", x + 10, y + 10, a - 10, b - 10);

		}

		else
		{
			readimagefile("img/WRD.jpg", x + 10, y + 10, a - 10, b - 10);
		}
	}
	else
	{
		cout << "R";

		
		if ((P.ri + P.ci) % 2 == 0)
		{

			readimagefile("img/DRL.jpg", x + 10, y + 10, a - 10, b - 10);

		}

		else
		{

			readimagefile("img/DRD.jpg", x + 10, y + 10, a - 10, b - 10);
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

