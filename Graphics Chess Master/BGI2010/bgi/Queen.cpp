#include "Queen.h"


Queen::Queen()
{
}

Queen::Queen(Position p, Color c, Board* b) :
	Piece(p, c, b) {}

bool Queen::isLegel(Position EP)
{
	return ((IsDiagonalMove(P, EP) && IsDiagonalPathClear(P, EP, B))
		||
		((IsHorizonMove(P, EP) && IsHorizonPathClear(P, EP, B)) ||
			(IsVerticalMove(P, EP), IsVerticalPathClear(P, EP, B))));
}


void Queen::Draw()
{
	int x = P.ci * 100;
	int y = P.ri * 100;
	int a = (P.ci + 1) * 100;
	int b = (P.ri + 1) * 100;
	if (C == White)
	{
		if ((P.ri + P.ci) % 2 == 0)
		{

			readimagefile("img/WQL.jpg", x + 10, y + 10, a - 10, b - 10);

		}

		else
		{
			readimagefile("img/WQD.jpg", x + 10, y + 10, a - 10, b - 10);
		}

		cout << "r";
	}
	else
	{
		cout << "R";

		if ((P.ri + P.ci) % 2 == 0)
		{

			readimagefile("img/DQL.jpg", x + 10, y + 10, a - 10, b - 10);

		}

		else
		{
			readimagefile("img/DQD.jpg", x + 10, y + 10, a - 10, b - 10);
		}
	}

}


void Queen::unDraw()
{
	cout << " ";

}


Queen::~Queen()
{
}
