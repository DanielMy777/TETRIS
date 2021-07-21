#include "Game.h"

Game::Game()
{
	if (Settings::getP1())
		p1 = new Player(Board::STARTX1, Board::STARTY1, Player::PLAYER1);
	else {
		p1 = new ComputerPlayer(Board::STARTX1, Board::STARTY1, Player::PLAYER1);
		(*p1).setLevels(Settings::getNovice1(), Settings::getGood1(),Settings::getBest1(),Settings::getGod1() );
	}

	if(Settings::getP2())
		p2 = new Player(Board::STARTX2, Board::STARTY2, Player::PLAYER2);
	else {
		p2 = new ComputerPlayer(Board::STARTX2, Board::STARTY2, Player::PLAYER2);
		(*p2).setLevels(Settings::getNovice2(), Settings::getGood2(), Settings::getBest2(), Settings::getGod2());
	}
}

bool Game::play()
{
	MOVES p1Move, p2Move;
	int c = 1;
	bool run = true, p1lose = false, p2lose = false;
	IO::hidecursor(false);

	if (Settings::getMusic())
		PlaySound(TEXT("TetrisAudio.wav"), NULL, SND_FILENAME | SND_ASYNC);

	IO::clrscr();
	(*p1).printBoard();
	(*p2).printBoard();


	while (run && c!= IO::ESC)
	{
		p1Move = p2Move = MOVES::NONE;
		(*p1).printShape();
		(*p2).printShape();
		Sleep(300);
		if (getPress(p1Move, p2Move))
			break;
		p1Move = (*p1).calcBestMove(p1Move);
		c = (*p1).takeTurn(p1Move);
		p1lose = (c == 1);
		p2Move = (*p2).calcBestMove(p2Move);
		c = (*p2).takeTurn(p2Move);
		p2lose = (c == 1);
		
		if(p1lose || p2lose)
			run = false;
	}
	if(!run)
		printResult(p1lose, p2lose);
	IO::hidecursor(true);
	PlaySound(NULL, NULL, SND_ASYNC);
	return !run;
}


bool Game::getPress(MOVES& p1, MOVES& p2) 
{
	char c = 0;
	if (_kbhit())
		c = _getch();
	switch (c){
	case 'w':
	case 'W':
		p1 = MOVES::COUNTER;
		break;	
	case 's':
	case 'S':
		p1 = MOVES::CLOCK;
		break;
	case 'a':
	case 'A':
		p1 = MOVES::LEFT;
		break;
	case 'd':
	case 'D':
		p1 = MOVES::RIGHT;
		break;
	case 'x':
	case 'X':
		p1 = MOVES::DROP;
		break;
	case 'i':
	case 'I':
		p2 = MOVES::COUNTER;
		break;
	case 'k':
	case 'K':
		p2 = MOVES::CLOCK;
		break;
	case 'j':
	case 'J':
		p2 = MOVES::LEFT;
		break;
	case 'l':
	case 'L':
		p2 = MOVES::RIGHT;
		break;
	case 'm':
	case 'M':
		p2 = MOVES::DROP;
		break;
	case IO::ESCAPE:
		return true;
		break;
	default:
		break;
	}
	return false;
}


void Game::printResult(bool p1lose, bool p2lose) const
{
	bool tie = false;
	if (p1lose)
	{
		if (p2lose) //tie
		{
			if (Settings::getScore())
			{
				if (p1->getScore() > p2->getScore())
					p1lose = false;
				else if (p2->getScore() > p1->getScore())
					p2lose = false;
				else
					tie = true;
			}
			else
				tie = true;
		}
	}
	
	IO::printResultHelper(p1lose,p2lose,tie,Settings::getP1(),Settings::getP2());
	
}

Game::~Game()
{
	delete p1;
	delete p2;
}
