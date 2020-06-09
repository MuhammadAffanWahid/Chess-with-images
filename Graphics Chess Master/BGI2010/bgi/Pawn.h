#pragma once
#include "Piece.h"
class Pawn :public Piece
{

public:
	Pawn(Position p, Color c, Board* b) :
		Piece(p, c, b) {}
	virtual bool isLegel(Position EP)
	{
		if (P.ri == 6 || P.ri == 1)
		{
			if (IsVerticalMove(P, EP) && IsVerticalPathClear(P, EP, B))
			{
				if (abs(EP.ri - P.ri) > 2)
					return false;
				else
					return true;
			}
			else
			return false;
		}

		else {

			if (IsVerticalMove(P, EP) && IsVerticalPathClear(P, EP, B))
			{
				if (C == White)
				{

					if (EP.ri - P.ri == 1)
						return true;
					else
						return false;
				}

				else {

					if (EP.ri - P.ri == -1)
						return true;
					else
						return false;
				}
			}
			else
				return false;


		}

		//int dr = EP.ri - P.ri;
		//int dc = EP.ci - P.ci;

		//if (abs(dc) == 0 && B->B[EP.ri][EP.ci] != nullptr) //affan
		//	return false;

		//if (C == WHITE)
		//{
		//	if (dr < 0 || abs(dr) > 2)
		//		return false;
		//	if (abs(dc) > 1)
		//		return false;
		//	if (abs(dr) == 2 && (P.ri != 1 || dc != 0))
		//		return false;
		//	if (!IsVerticalPathClear(P, EP, B))
		//		return false;
		//	if (dr == 0 && dc != 0)
		//		return 0;
		//	if (IsDiagonalMove(P, EP))
		//	{

		//		if (P.ci != 0 && P.ri != 0 && Brd->IsEnemyPiece(EP))
		//			return 1;
		//		else if (P.ci != 7 && P.ri != 0 && Brd->IsEnemyPiece(EP))
		//			return 1;
		//		else
		//			return false;
		//	}
		//}
		//else
		//{
		//	if (dr > 0 || abs(dr) > 2)
		//		return false;
		//	if (abs(dc) > 1)
		//		return false;
		//	if (!IsVerticlePathClear(P, EP, Brd))
		//		return false;
		//	if (abs(dr) == 2 && (P.ri != 6 || dc != 0))
		//		return false;
		//	if (dr == 0 && dc != 0)
		//		return 0;
		//}

		//if (IsDiagonalMove(P, EP))
		//{
		//	if (P.ci != 7 && P.ri != 7 && Brd->IsEnemyPiece(EP))
		//		return 1;
		//	else if (P.ci != 0 && P.ri != 0 && Brd->IsEnemyPiece(EP))
		//		return 1;
		//	else
		//		return false;
		//}
		//return true;

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
			cout << "p";
			//setcolor();
			//setfillstyle(SOLID_FILL, GREEN);
			//(((P.ci+1) * 100) - 50, 150, 10);
			//readimagefile("img/bB.png")
		
			if ((P.ri + P.ci) % 2 == 0)
			{

				readimagefile("img/WPL.jpg", x+5, y+5, a-5, b-5);

			}

			else
			{
				readimagefile("img/WPD.jpg", x+5, y+5, a-5, b-5);
			}

		}
		else
		{

			if ((P.ri + P.ci) % 2 == 0)
			{

				readimagefile("img/DPL.jpg",x+5, y+5, a-5, b-5);

			}

			else
			{
				readimagefile("img/DPD.jpg",x+5, y+5, a-5, b-5);
			}

			cout << "P";

			//setfillstyle(SOLID_FILL, GREEN);
			//circle(((P.ci+1) * 100) - 50, 650, 10);
		}
			
	}
	virtual void unDraw()
	{
		cout << " ";
	}

	~Pawn();
};

