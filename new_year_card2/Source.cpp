#include <iostream>
#include <ctime>
#include <Windows.h>
#include <queue>
#include <stdlib.h>

using namespace std;

const int ROWS = 25; //max 54
const int COLS = 129;
const int totalTimes = 300;
const int numSnowPerLine = 3;
const char SNOW = '*';
const double WAIT = 0.2;

//Romove Cursor
void showConsoleCursor(bool showFlag) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}
void changeTextColor(HANDLE hConsole, WORD &value) {
	SetConsoleTextAttribute(hConsole, value);
}
void plot(char arr[ROWS][COLS], int topRow, int numOfTime) {
	system("cls");		//clear the screen, then curser move to upper left
	WORD arr2[] = { 10, 11, 12, 13, 14 };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	changeTextColor(hConsole, arr2[numOfTime % 5]);
	cout << "				      ___   ___     _________     _________     _________    ___    ___" << endl;
	changeTextColor(hConsole, arr2[(numOfTime + 1) % 5]);
	cout << "				     /  /| /  /|   /  ___   /|   /  ___   /|   /  ___   /|  |\\  \\  /  /|" << endl;	
	changeTextColor(hConsole, arr2[(numOfTime + 2) % 5]);
	cout << "				    /  /__/  / /  /  /|_/  / |  /  /|_/  / /  /  /|_/  / /  \\ \\  \\/  / /" << endl;
	changeTextColor(hConsole, arr2[(numOfTime + 3) % 5]);
	cout << "				   /  ___   / /  /  ___   / /  /  ______/ /  /  ______/ /    \\ \\    / /" << endl;
	changeTextColor(hConsole, arr2[(numOfTime + 4) % 5]);
	cout << "				  /  /| /  / /  /  / |/  / /  /  / _____|/  /  / _____|/      \\/   / /" << endl;
	changeTextColor(hConsole, arr2[(numOfTime + 5) % 5]);
	cout << "				 /__/ //__/ /  /__/ //__/ /  /__/ /        /__/ /            _/   / /" << endl;
	changeTextColor(hConsole, arr2[numOfTime % 5]);
	cout << "				 |__|/ |__|/   |__|/ |__|/   |__|/         |__|/            |\\___/ /" << endl;
	changeTextColor(hConsole, arr2[(numOfTime + 1) % 5]);
	cout << "				                                                            \\|___|/" << endl;
	changeTextColor(hConsole, arr2[(numOfTime + 2) % 5]);
	cout << "        ____________     ________      ___       ___      ___    ___     ________      _________      ____________         ____" << endl;
	changeTextColor(hConsole, arr2[(numOfTime + 3) % 5]);
	cout << "       /   ____    /|   /  _____/|    /  /|     /  /|    |\\  \\  /  /|   /  _____/|    /  ___   /|    /   ____    /|       /   /|" << endl;
	changeTextColor(hConsole, arr2[(numOfTime + 4) % 5]);
	cout << "      /   / _ /   / /  /  / ____|/   /  //     /  / /    \\ \\  \\/  / /  /  /|____|/   /  /|_/  / |   /   /|__/   / /      /   / /" << endl;
	changeTextColor(hConsole, arr2[(numOfTime + 5) % 5]);
	cout << "     /   / / /   / /  /  /_/___     /  //___  /  / /      \\ \\    / /  /  /_/___     /        / /   /   //__/   / /      /   / /" << endl;
	changeTextColor(hConsole, arr2[numOfTime % 5]);
	cout << "    /   / / /   / /  /  ______/|   /  ///  /|/  / /        \\/   / /  /  ______/|   /  ___   / /   /   __    __/ /      /___/ /" << endl;
	changeTextColor(hConsole, arr2[(numOfTime + 1) % 5]);
	cout << "   /   / / /   / /  /  / _____|/  /  ///  ///  / /         /   / /  /  / _____|/  /  / //  / /   /   / _\\   \\_|/       |___|/" << endl;
	changeTextColor(hConsole, arr2[(numOfTime + 2) % 5]);
	cout << "  /   / / /   / /  /  /_/___     /  /_/  /_/  / /        _/   / /  /  /_/___     /  / //  / /   /   / /  \\   \\        ____" << endl;
	changeTextColor(hConsole, arr2[(numOfTime + 3) % 5]);
	cout << " /___/ / /___/ /  /________/|   /____________/ /        |\\___/ /  /________/|   /__/ //__/ /   /___/ /    \\___\\      /___/|" << endl;
	changeTextColor(hConsole, arr2[(numOfTime + 4) % 5]);
	cout << " |___|/  |___|/   |________|/   |____________|/         \\|___|/   |________|/   |__|/ |__|/    |___|/     |___|      |___|/" << endl;


	SetConsoleTextAttribute(hConsole, 15);
	for (int split_line = 0; split_line < COLS; split_line++)
		cout << "-" ;		//split area
	SetConsoleTextAttribute(hConsole, WORD(rand() % 15 + 1));
	cout << endl;
	for (int i = 0; i < ROWS; i++) {
		int row = (topRow + i) % ROWS;
		for (int j = 0; j < COLS; j++) {
			cout << arr[row][j];
		}
		cout << endl;
	}
}
void color(HANDLE hConsole, WORD value) {
	SetConsoleTextAttribute(hConsole, value);
}
void waitTime(double waitSec) {
	clock_t start = clock();
	while ((clock() - start) < (CLOCKS_PER_SEC * waitSec));
}
int main() {
	int topRow = 0;
	char arr[ROWS][COLS] = {' '};
	

	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < totalTimes; i++) {
		showConsoleCursor(false);
		plot(arr, topRow, i);
		topRow = topRow - 1;
		if (topRow < 0) {
			topRow = ROWS - 1;
		}
		for (int j = 0; j < COLS; j++) {
			arr[topRow][j] = ' ';
		}
		for (int k = 0; k < numSnowPerLine; k++) {
			arr[topRow][rand() % COLS] = SNOW;
		}
		waitTime(WAIT);
	}

}

