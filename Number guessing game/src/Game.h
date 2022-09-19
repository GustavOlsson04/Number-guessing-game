#pragma once


class Game
{
public:
	void Run();
	void Round();
	void Life();

	int i = 1;
	int life = 0;
	int Correct_Number = 0;
	int Number_Of_Success = 1;
};