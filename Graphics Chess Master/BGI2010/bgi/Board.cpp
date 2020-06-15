#include "Board.h"
//#include "Pawn.h"
#include "graphics.h"
///////////////
void Board::getRowColbyLeftClick(int& rpos, int& cpos)
{
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD Events;
	INPUT_RECORD InputRecord;
	SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
	do
	{
		ReadConsoleInput(hInput, &InputRecord, 1, &Events);
		if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
			rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
			break;
		}
	} while (true);
}

void Board::DisplayMove(Position s , Position e)
{

	B[s.ri][s.ci]->Draw();
	B[e.ri][e.ci]->Draw();

}


/////////
Board::Board()
{
	
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
			 if ((ri == 0 && ci == 0) || (ri == 0 && ci == 7))
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
			else if (ri == 0 && ci == 4)
			{
				B[ri][ci] = new	Queen(Position(ri, ci), White, this);

			}
			else if (ri == 7 && ci == 4)
			{
				B[ri][ci] = new	Queen(Position(ri, ci), Black, this);

			}

			//King Piece
			else if (ri == 0 && ci == 3)
			{
				B[ri][ci] = new	King(Position(ri, ci), White, this);

			}
			else if (ri == 7 && ci == 3)
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

Position Board::KingPos()
{
	King* k;
	Position pos(-1, -1);
	for (int i = 0;i < 8;i++)
	{
		for (int j = 0;j < 8;j++)
		{
			if (B[i][j] != nullptr && Turn == B[i][j]->getColor())
			{
				k = dynamic_cast<King*>(B[i][j]);
				if (k == B[i][j])
				{
					Position Posi(i, j);
					return Posi;
				}
			}
		
		}
	}
	return pos;
}

bool Board::IsCheck()
{
	Position Ptemp;
	Ptemp = KingPos();
	E.ri = Ptemp.ri;
	E.ci = Ptemp.ci;
	TurnChange();
	for (int R = 0; R < 8; R++)
	{
		for (int C = 0; C < 8; C++)
		{
			S.ri = R;
			S.ci = C;
			if (IsValidSelection() && IsValidDestination() && B[S.ri][S.ci]->isLegel(E))///////////////////////
			{
				TurnChange();
				return true;
			}
		}
	}
	TurnChange();
	return false;
}


bool Board::IsCheckAfterMove()
{
	bool Is = false; //
	Piece* SP;
	Position TS = S;
	Position TE = E;

	SP = B[E.ri][E.ci];
	B[S.ri][S.ci]->Move(E);
	if (IsCheck())  Is = true; 
	S = TS;
	E = TE;


	B[E.ri][E.ci]->P.ri = S.ri; //->ChangePos(S.ri, S.ci);
	B[E.ri][E.ci]->P.ci = S.ci;

	B[S.ri][S.ci] = B[E.ri][E.ci];
	B[E.ri][E.ci] = SP;
	return Is;
}

bool Board::IsStaleMate()
{
	for (int Sr = 0; Sr < 8; Sr++)
	{
		for (int Sc = 0; Sc < 8; Sc++)
		{
			S.ri = Sr;
			S.ci = Sc;

			if (IsValidSelection())
			{
				for (int Er = 0; Er < 8; Er++)
				{
					for (int Ec = 0; Ec < 8; Ec++)
					{
						E.ri = Er;
						E.ci = Ec;
						if (IsValidDestination() && B[S.ri][S.ci]->isLegel(E, false, true))
						{
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}

bool Board::IsCheckMate()
{
	if (!IsCheck())
		return false;
	return IsStaleMate();
}



void Board::PrintBoard()
{
	system("cls");


	for (int i = 0;i < 8;i++)// i=1
	{
		for (int j = 0;j < 8; j++)   //   800/8
		{
			int x = j * 75;
			int y = i * 75;
			int a = (j + 1) * 75;
			int b = (i + 1) * 75;
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
	do
	{
		
	} while (!ismouseclick(WM_LBUTTONDOWN));
	getmouseclick(WM_LBUTTONDOWN, S.ci, S.ri);
	Beep(1023, 50);
	S.ci = S.ci / 75;
	S.ri = S.ri / 75;
	//cin >> S.ri >> S.ci;
	//getRowColbyLeftClick(S.ri, S.ci);
}

void Board::SelectDestination()
{
	do
	{

	} while (!ismouseclick(WM_LBUTTONDOWN));
	getmouseclick(WM_LBUTTONDOWN, E.ci, E.ri);
	Beep(2023, 50);
	E.ci = E.ci / 75;
	E.ri = E.ri / 75;
	//cin >> E.ri >> E.ci;
	//getRowColbyLeftClick(E.ri, E.ci);
}
bool Board::IsValidDestination()
{
	if (S.ri < 0 || S.ri>7 || S.ci < 0 || S.ci>7)
		return false;
	return (B[E.ri][E.ci] == nullptr || B[E.ri][E.ci]->getColor() != Turn);

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

			int x = E.ci * 75;
			int y = E.ri * 75;
			int a = (E.ci + 1) * 75;
			int b = (E.ri + 1) * 75;

			

		    if (IsValidDestination() && B[S.ri][S.ci]->isLegel(E, false, true))
			{
				setcolor(GREEN);
				circle(x + 37.5, y + 37.5, 10);
				setfillstyle(SOLID_FILL, GREEN);
				floodfill(x + 37.5, y + 37.5, GREEN);

				HL[E.ri][E.ci] = '*';	
			}
			if (IsValidDestination() && B[E.ri][E.ci] != nullptr && B[S.ri][S.ci]->isLegel(E, false, true)  &&  B[E.ri][E.ci]->getColor() != Turn )
			{
			setcolor(RED);
			circle(x + 37.5, y + 37.5, 10);
			setfillstyle(SOLID_FILL, RED);
			floodfill(x + 37.5, y + 37.5, RED);

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
			int x = c * 75;
			int y = r * 75;
			int a = (c + 1) * 75;
			int b = (r + 1) * 75;

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
			{
				cout << "\n Invalid Destination ............\n";
				UnHighlight();

			}



		} while (IsValidDestination() == false);

		if (B[S.ri][S.ci]->isLegel(E, false, true))
		{
			B[S.ri][S.ci]->Move(E, true);
			//DisplayMove( S,  E);

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

