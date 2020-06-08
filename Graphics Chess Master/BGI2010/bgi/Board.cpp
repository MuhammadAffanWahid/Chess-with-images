#include "Board.h"
#include "Rook.h"
#include "Horse.h"
#include "Bishop.h"
#include "King.h"
#include "Queen.h"
#include "graphics.h"

Board::Board()
{
	Init();
	Turn = White;
}

void Board::Init()
{
	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			//pawn piece
			if (ri == 1)
			{
				B[ri][ci] = new	Pawn(Position(ri, ci), White, this);
			}
			else if (ri == 6)
			{
				B[ri][ci] = new	Pawn(Position(ri, ci), Black, this);
			}
			//Rook Piece
			else if ((ri == 0 && ci == 0) || (ri == 0 && ci == 7))
			{
				B[ri][ci] = new	Rook(Position(ri, ci), White, this);

			}

			else if ((ri == 7 && ci == 0) || (ri == 7 && ci == 7))
			{
				B[ri][ci] = new	Rook(Position(ri, ci), Black, this);

			}
			//Horse Piece
			else if ((ri == 0 && ci == 1) || (ri == 0 && ci == 6))
			{
				B[ri][ci] = new	Horse(Position(ri, ci), White, this);

			}

			else if ((ri == 7 && ci == 1) || (ri == 7 && ci == 6))
			{
				B[ri][ci] = new	Horse(Position(ri, ci), Black, this);

			}

			//Bishop Piece
			else if ((ri == 0 && ci == 2) || (ri == 0 && ci == 5))
			{
				B[ri][ci] = new	Bishop(Position(ri, ci), White, this);

			}

			else if ((ri == 7 && ci == 2) || (ri == 7 && ci == 5))
			{
				B[ri][ci] = new	Bishop(Position(ri, ci), Black, this);

			}

			//Queen Piece
			else if (ri == 0 && ci == 3)
			{
				B[ri][ci] = new	Queen(Position(ri, ci), White, this);

			}
			else if (ri == 7 && ci == 3)
			{
				B[ri][ci] = new	Queen(Position(ri, ci), Black, this);

			}

			//King Piece
			else if (ri == 0 && ci == 4)
			{
				B[ri][ci] = new	King(Position(ri, ci), White, this);

			}
			else if (ri == 7 && ci == 4)
			{
				B[ri][ci] = new	King(Position(ri, ci), Black, this);
			}

			//else
			else
			{
				B[ri][ci] = nullptr;
			}

		}
	}

}

void Board::PrintBoard()
{
	system("cls");


	for (int i = 0;i < 8;i++)// i=1
	{
		for (int j = 0;j < 8; j++)   //   800/8
		{
			int x = j * 100;
			int y = i * 100;
			int a = (j + 1) * 100;
			int b = (i + 1) * 100;
			if ((i + j) % 2 == 0)
			{
				setfillstyle(SOLID_FILL, COLOR(230, 204, 171));
				bar(x, y, a, b);
			}
			else
			{
				setfillstyle(SOLID_FILL, COLOR(157, 87, 27));
				bar(x, y, a, b);
			}
		}
	}

	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			if (B[ri][ci] == nullptr)
			{
				cout << "-";
			}

			else
			{
				B[ri][ci]->Draw();
			}

		}

		cout << endl;
	}
}

void Board::Move(Position S, Position E)
{
	//B[E.ri][E.ci]->unDraw();
	//B[S.ri][S.ci]->unDraw();

	B[E.ri][E.ci] = B[S.ri][S.ci];
	B[S.ri][S.ci] = nullptr;
}

void Board::TurnChange()
{
	if (Turn == White)
		Turn = Black;
	else
		Turn = White;
}


void Board::SelectPiece()
{
	cin >> S.ri >> S.ci;
}

void Board::SelectDestination()
{
	cin >> E.ri >> E.ci;
}
bool Board::IsValidDestination()
{
	if (S.ri < 0 || S.ri>7 || S.ci < 0 || S.ci>7)
		return false;
	return (B[E.ri][E.ci] == nullptr || B[S.ri][S.ci]->getColor() != Turn);

}

bool Board::IsValidSelection()
{
	if (S.ri < 0 || S.ri>7 || S.ci < 0 || S.ci>7)
		return false;
	return (B[S.ri][S.ci] != nullptr && B[S.ri][S.ci]->getColor() == Turn);

}

void Board::DisplayMsg()
{
	if (Turn == White)
	{
		cout << "White's Turn :";
	}

	else
		cout << "Black's Turn :";

}

void Board::Highlight()
{
	for (int r = 0; r < 8;r++)
	{
		for (int c = 0;c < 8;c++)
		{
			E = Position(r, c);

			int x = E.ci * 100;
			int y = E.ri * 100;
			int a = (E.ci + 1) * 100;
			int b = (E.ri + 1) * 100;

			if (IsValidDestination() && B[S.ri][S.ci]->isLegel(E))
			{
				setcolor(GREEN);
				circle(x + 50, y + 50, 20);
				setfillstyle(SOLID_FILL, GREEN);
				floodfill(x + 50, y + 50, GREEN);
				HL[E.ri][E.ci] = '*';
			}
			else
			{
				HL[E.ri][E.ci] = ' ';
			}
		}

	}
}

void Board::UnHighlight()
{
	for (int r = 0; r < 8;r++)
	{
		for (int c = 0;c < 8;c++)
		{
			int x = c * 100;
			int y = r * 100;
			int a = (c + 1) * 100;
			int b = (r + 1) * 100;

			E = Position(r, c);
			if (HL[E.ri][E.ci] == '*')
			{
				if ((r + c) % 2 == 0)
				{
					setfillstyle(SOLID_FILL, COLOR(230, 204, 171));
					bar(x, y, a, b);
				}
				else
				{
					setfillstyle(SOLID_FILL, COLOR(157, 87, 27));
					bar(x, y, a, b);
				}
			}
		}
	}
}


void Board::Play()
{
	
	Init();
	Turn = ((rand() % 2 == 0) ? White : Black);


	while (1)
	{
		PrintBoard();

		do
		{
			DisplayMsg();
			do {
				cout << "\n Select Piece :";
				SelectPiece();

			} while (IsValidSelection() == false);

			Highlight();

			cout << "\n Select Destination :";
			SelectDestination();


			if (IsValidDestination() == false)
				cout << "\n Invalid Destination ............\n";



		} while (IsValidDestination() == false);

		if (B[S.ri][S.ci]->isLegel(E))
		{
			B[S.ri][S.ci]->Move(E);
			UnHighlight();

			TurnChange();
		}

		else
		{
			cout << "\nInvalid Move";
		}


	}


}


Board::~Board()
{

}

