#include "Piece.h"
#include "Board.h"

Piece::Piece(Position p, Color c, Board* b) :P(p), C(c)
{
	B = b;
}

void Piece::Move(Position EP)
{

	Position T = P;

	P = EP;
	B->Move(T, EP);
}

Color Piece::getColor()
{

	return C;
}

bool Piece::IsHorizonMove(Position S, Position E)
{
	return S.ri == E.ri;
}

bool Piece::IsVerticalMove(Position S, Position E)
{
	return S.ci == E.ci;
}

bool Piece::IsDiagonalMove(Position S, Position E)
{
	return (abs(E.ri - S.ri) == abs(E.ci - S.ci));
}



///////////////////////////////


bool Piece::IsHorizonPathClear(Position S, Position E, Board* B)
{
	if (S.ci < E.ci) //Left to Right
	{
		for (int i = S.ci + 1; i < E.ci; i++)
		{
			if (B->B[S.ri][i] != nullptr)
				return false;
		}
	}
	else // Right to Left
	{
		for (int i = E.ci + 1; i < S.ci; i++)
		{
			if (B->B[S.ri][i] != nullptr)
				return false;
		}
	}

	return true;
}

bool Piece::IsVerticalPathClear(Position S, Position E, Board* B)
{
	if (S.ri < E.ri) //Top to Bottom
	{
		for (int i = S.ri + 1; i < E.ri; i++)
		{
			if (B->B[i][S.ci] != nullptr)
				return false;
		}
	}
	else // Bottom to top
	{
		for (int i = E.ri + 1; i < S.ri; i++)
		{
			if (B->B[i][S.ci] != nullptr)
				return false;
		}
	}

	return true;
}

bool Piece::IsDiagonalPathClear(Position S, Position E, Board* B)
{

	int row = S.ri+1;
	int col = S.ci+1;
	int e_col = E.ci + 1;
	int s_row = S.ri - 1;
	int s_col = S.ci - 1;

	
		if (S.ri < E.ri && S.ci < E.ci)          // down sides of diagonal 
		{
			for (int i = S.ci + 1; i < E.ci; i++)
			{
				if (B->B[row][i] != nullptr)
					return false;
				row++;
			}
			return true;
		}


		else if (S.ci > E.ci && S.ri > E.ri)
		{
			for (int i = E.ri+1; i < S.ri; i++)
			{
				if (B->B[i][e_col] != nullptr)
					return false;
				e_col++;
			}
				
			return true;
		}


		else if (S.ri < E.ri && S.ci > E.ci)            // up sides of diagonal 
		{
			for (int i = E.ci + 1;i < S.ci;i++)
			{
				if (B->B[row][s_col] != nullptr)
					return false;

				row++;
				s_col--;
			}

			return true;
		}

		else
		{
			for (int i = E.ri + 1; i < S.ri; i++)
			{

				if (B->B[s_row][col] != nullptr)
					return false;
				col++;
				s_row--;
			}

			return true;
		}
			
	
}

Piece::~Piece()
{

}
