#include "Menu.h"

void Menu::run()
{
	int choice;
	bool exit = false;
	bool chosen;
	while (!exit)
	{
		printMenu();
		std::cin >> choice;
		
		switch (choice)
		{
		case (HUMVSHUM):
			Settings::set_p1_human(true);
			Settings::set_p2_human(true);
			newGame(); 
			break;

		case (HUMVSCOMP):
			chooseLevel(chosen,Player::PLAYER2);
			if (chosen)
			{
				Settings::set_p1_human(true);
				Settings::set_p2_human(false);
				newGame();
			}
			break;

		case (COMPVSCOMP):
			chooseLevel(chosen, Player::PLAYER1);
			if (chosen)
			{
				chooseLevel(chosen, Player::PLAYER2);
				if (chosen)
				{
					Settings::set_p1_human(false);
					Settings::set_p2_human(false);
					newGame();
				}
			}
		
			break;

		case (CONTINUE):
			continueGame();
			break;

		case(SETTINGS):
			setSettings();
			break;

		case (INSTRUCTIONS):
			showInstructions();
			break;

		case(EXIT):
			exit = true;
		default:
			break;
		}
	}
	std::cout << "Goodbye!";
}

void Menu::newGame() 
{

	IO::clrscr();
	if (game)
		delete game;
	game = new Game;
	inProgress = true;
	continueGame();

}

void Menu::continueGame()
{
	if (game->play())
	{
		inProgress = false;
		delete game;
		game = nullptr;
	}
}


void Menu::printMenu() const
{
	IO::clrscr();
	std::cout << " Welcome to our Tetris Game\n press:\n";
	std::cout << "(1) Start a new game - Human vs Human\n";
	std::cout << "(2) Start a new game - Human vs Computer\n";
	std::cout << "(3) Start a new game - Computer vs Computer\n";
	if (inProgress) //paused game
		std::cout << "(4) Continue a paused game\n";

	std::cout << "(7) Present & change settings\n";
	std::cout << "(8) Present instructions and keys\n";
	std::cout << "(9) EXIT\n";
}

void Menu::showInstructions() const {

	IO::clrscr();
	IO::colorizeText(IO::MAGNETA);
	std::cout << "Goal:\n";
	IO::colorizeText(IO::WHITE);
	std::cout << "You have to make full horizontal lines with the different shaped blocks that fall into the game area.\n";
	std::cout << "Full lines will then disappear and provide points.\n";
	std::cout << "The more lines you make at the same time, the more points you earn.\n";
	IO::colorizeText(IO::MAGNETA);
	std::cout << "\nPlayer's keys: \n";
	std::cout << "\n(if you choose to play against the computer - your keyboard is the left player's)\n";
	IO::colorizeText(IO::WHITE);
	std::cout << "  ________________________________________________________________________________________\n";
	std::cout << " |   Shape Action         |      Left Player         |         Right Player               |\n";
	std::cout << " |________________________|__________________________|____________________________________|\n";
	std::cout << " |       LEFT             |    a or A                |            j or J                  |\n";
	std::cout << " |________________________|__________________________|____________________________________|\n";
	std::cout << " |       RIGHT            |    d or D                |          l (small L) or L          |\n";
	std::cout << " |________________________|__________________________|____________________________________|\n";
	std::cout << " |    ROTATE clockwise    |    s or S                |            k or K                  |\n";
	std::cout << " |________________________|__________________________|____________________________________|\n";
	std::cout << " |ROTATE counterclockwise |    w or W                |          i or I (uppercase i)      |\n";
	std::cout << " |________________________|__________________________|____________________________________|\n";
	std::cout << " |        DROP            |    x or X                |             m or M                 |\n";
	std::cout << " |________________________|__________________________|____________________________________|\n\n";

	std::cout << "Press any key to continue";
	_getch();
	if (_kbhit())
		return;
}


void Menu::setSettings() const
{

	int choice;
	bool exit = false;
	while (!exit)
	{
		printSettings();
		std::cin >> choice;
		switch (choice)
		{
		case (Settings::MUSIC):
			Settings::setMusic(!Settings::getMusic());
			break;

		case (Settings::COLOR):
			Settings::setColors(!Settings::getColors());
			break;

		case(Settings::SCORE):
			Settings::setScore(!Settings::getScore());
			break;

		case(EXIT):
			exit = true;
		}
	}
	return;
}


void Menu::chooseLevel(bool& chosen,int cmp) const
{
	int choice;
	chosen = true;
	IO::clrscr();
	std::cout << " Please choose the level for player number " << cmp << " (computer player):\n";
	std::cout << "(5) NOVICE\n"; 
	std::cout << "(6) GOOD\n";
	std::cout << "(7) BEST\n";
	std::cout << "(8) God Mode (For the brave)\n";
	std::cout << "(9) Return to Main Menu\n";
	std::cin >> choice;
	
	switch (choice)
	{
	case (Settings::BEST):
		if(cmp== Player::PLAYER1)
			Settings::setBest1(true);
		else
			Settings::setBest2(true);
		break;

	case (Settings::GOOD):
		if (cmp== Player::PLAYER1)
			Settings::setGood1(true);
		else
			Settings::setGood2(true);
		break;

	case(Settings::NOVICE):
		if (cmp== Player::PLAYER1)
			Settings::setNovice1(true);
		else
			Settings::setNovice2(true);
		break;

	case(Settings::GODMODE):
		if(cmp== Player::PLAYER1)
			Settings::setgodMode1(true);
		else
			Settings::setgodMode2(true);
		break;	
	
	case(EXIT):
		chosen = false;
		return;

	default:
		break;
	}
}



void Menu::printSettings() const
{
	bool music = Settings::getMusic();
	bool colors = Settings::getColors();
	bool scores = Settings::getScore();
	IO::clrscr();
	std::cout << "Your Settings Are:\n\n";
	std::cout << "* Game Music is currently " << (music ? "on " : "off ") << "\n";
	std::cout << "* Game Colors are currently " << (colors ? "on " : "off ") << "\n";
	std::cout << "* Game Scores are currently " << (scores ? "on " : "off ") << "\n";
	std::cout << "\n";
	std::cout << "press (1) to turn the Game Music " << (music ? "off " : "on ") << "\n";
	std::cout << "press (2) to turn the Game Colors " << (colors ? "off " : "on ") << "\n";
	std::cout << "press (3) to turn the Game Scores " << (scores ? "off " : "on ") << "\n";
	std::cout << "press (9) to go back to the main menu \n";

}
