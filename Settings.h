/*This header file contains the settings functions of the game*/

#pragma once
#include "IO.h"

class Settings {
	
	static bool colors;
	static bool music;
	static bool score;
	static bool p1_human;  //true = human
	static bool p2_human;  //false = comp
	static bool c1_best; 
	static bool c1_good;  
	static bool c1_novice;  
	static bool c1_godMode;
	static bool c2_best;
	static bool c2_good;
	static bool c2_novice;
	static bool c2_godMode;

public:
	static constexpr int MUSIC = 1;
	static constexpr int COLOR = 2;
	static constexpr int SCORE = 3;
	static constexpr int BEST = 7;
	static constexpr int GOOD = 6;
	static constexpr int NOVICE = 5;
	static constexpr int GODMODE = 8;

	/*This function returns a boolean value that indicates whether the colors are on or off*/
	static bool getColors() { return colors; }

	/*This function returns a boolean value that indicates whether the music is on or off*/
	static bool getMusic() { return music; }

	/*This function returns a boolean value that indicates whether the score is shown or not*/
	static bool getScore() { return score; }

	/*This function returns a boolean value that indicates whether the first player is human or computer player (true = human, false = pc)*/
	static bool getP1() { return p1_human; }

	/*This function returns a boolean value that indicates whether the second player is human or computer player (true = human, false = pc)*/
	static bool getP2() { return p2_human; }

	/*This function returns a boolean value that indicates whether the first pc player is playing on "God Mode" */
	static bool getGod1() { return c1_godMode; }

	/*This function returns a boolean value that indicates whether the first pc player is playing on "Good Mode" */
	static bool getGood1() { return c1_good; }

	/*This function returns a boolean value that indicates whether the first pc player is playing on "Best Mode" */
	static bool getBest1() { return c1_best; }

	/*This function returns a boolean value that indicates whether the first pc player is playing on "Novice Mode" */
	static bool getNovice1() { return c1_novice; }

	/*This function returns a boolean value that indicates whether the second pc player is playing on "God Mode" */
	static bool getGod2() { return c2_godMode; }

	/*This function returns a boolean value that indicates whether the second pc player is playing on "Good Mode" */
	static bool getGood2() { return c2_good; }

	/*This function returns a boolean value that indicates whether the second pc player is playing on "Best Mode" */
	static bool getBest2() { return c2_best; }

	/*This function returns a boolean value that indicates whether the second pc player is playing on "Novice Mode" */
	static bool getNovice2() { return c2_novice; }

	/*This function gets a boolean value and sets the colors to on or off */
	static void setColors(bool _colors) { colors = _colors; }

	/*This function gets a boolean value and sets the music to on or off */
	static void setMusic(bool _music) { music = _music; }

	/*This function gets a boolean value and sets the score to on or off */
	static void setScore(bool _score) { score = _score; }

	/*This function gets a boolean value that indicates whether the first player is 
	human or computer player (true = human, false = pc) and sets it to the variable accordingly */
	static void set_p1_human(bool _p1_human) { p1_human = _p1_human; }

	/*This function gets a boolean value that indicates whether the second player is
	human or computer player (true = human, false = pc) and sets it to the variable accordingly */
	static void set_p2_human(bool _p2_human) { p2_human = _p2_human; }

	/*This function recieves a boolean value that indicates whether the first pc player should play on "Good Mode",
	and sets it to the variable accordingly  */
	static void setGood1(bool _good) { c1_good=_good; }

	/*This function recieves a boolean value that indicates whether the first pc player should play on "Best Mode", 
	and sets it to the variable accordingly  */
	static void setBest1(bool _best) { c1_best=_best; }

	/*This function recieves a boolean value that indicates whether the first pc player should play on "Novice Mode",
	and sets it to the variable accordingle  */
	static void setNovice1(bool _novice) { c1_novice= _novice; }

	/*This function recieves a boolean value that indicates whether the first pc player should play on "God Mode",
	and sets it to the variable accordingly  */
	static void setgodMode1(bool _godMode) { c1_godMode = _godMode; }

	/*This function recieves a boolean value that indicates whether the second pc player should play on "Good Mode",
	and sets it to the variable accordingly  */
	static void setGood2(bool _good) { c2_good = _good; }

	/*This function recieves a boolean value that indicates whether the second pc player should play on "Best Mode",
	and sets it to the variable accordingly  */
	static void setBest2(bool _best) { c2_best = _best; }

	/*This function recieves a boolean value that indicates whether the second pc player should play on "Novice Mode",
	and sets it to the variable accordingly  */
	static void setNovice2(bool _novice) { c2_novice = _novice; }

	/*This function recieves a boolean value that indicates whether the second pc player should play on "God Mode",
	and sets it to the variable accordingly  */
	static void setgodMode2(bool _godMode) { c2_godMode = _godMode; }
};