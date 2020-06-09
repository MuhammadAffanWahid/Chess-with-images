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
	int x = P.ci * 75;
	int y = P.ri * 75;
	int a = (P.ci + 1) * 75;
	int b = (P.ri + 1) * 75;
	if (C == White)
	{
		if ((P.ri + P.ci) % 2 == 0)
		{

			readimagefile("img/WQL.jpg", x+7 , y+7 , a-7 , b-7 );

		}

		else
		{
			readimagefile("img/WQD.jpg", x + 7, y + 7, a - 7, b - 7);
		}

		cout << "r";
	}
	else
	{
		cout << "R";

		if ((P.ri + P.ci) % 2 == 0)
		{

			readimagefile("img/DQL.jpg", x + 6.5, y + 6.5, a - 6.5, b - 6.5);

		}

		else
		{
			readimagefile("img/DQD.jpg", x + 6.5, y + 6.5, a - 6.5, b - 6.5);
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
