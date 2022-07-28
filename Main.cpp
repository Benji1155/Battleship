/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2022 Media Design School
File Name : Battleship
Description : Main file which includes a slot battleship.
Author : Maxwell Presley
Mail : MaxwellPresley@mds.ac.nz
**************************************************************************/
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void RandomPlacementOrNot();
void Credits();
void Quit();
void Menu();
void MenuAnswer();
void Player_Array_Print();
void Welcome();
void Lower();
void Upper();
void PlacementAnswer();
void Manual();
void AC_Location();
void AC_Direction();
void B_Location();
void B_Direction();
void D_Location();
void D_Direction();
void S_Location();
void S_Direction();
void P_Location();
void P_Direction();
void Enemy_Placement();
void Enemy_Array_Print();
void Valid_Placement_Algorithm(int& n1, int& n2);
void Expand_Ship(int& n1, int& n2, int& iran3);
void Up(int& n1, int& n2);
void Down(int& n1, int& n2);
void Right(int& n1, int& n2);
void Left(int& n1, int& n2);
void Auto_Valid_Placement_Algorithm(int& n1, int& n2);
void Auto_Placement();
void Auto_Expand_Ship(int& n1, int& n2, int& iran3);
void Auto_Up(int& n1, int& n2);
void Auto_Down(int& n1, int& n2);
void Auto_Right(int& n1, int& n2);
void Auto_Left(int& n1, int& n2);
void Game_Loop();
void Player_Shot(string& shot);
void Enemy_Shot(bool& enemy_turn);
void Enemy_Array_Blank_Print();

string previousletter = "W";
string menu;
string* pmenu = &menu;
string placementchoice;
string* pplacementchoice = &placementchoice;
string closed_list[100] = { };
string ac_location1;
string b_location1;
string ac_first;
string AC_Pos1;
string AC_Pos2;
string AC_Pos3;
string AC_Pos4;
string AC_Pos5;
string B_Pos1;
string B_Pos2;
string B_Pos3;
string B_Pos4;
string D_Pos1;
string D_Pos2;
string D_Pos3;
string S_Pos1;
string S_Pos2;
string S_Pos3;
string P_Pos1;
string P_Pos2;
char ship_id;
int ship_size;
int counter = 0;
int attempts = 0;
bool debug = false;
bool exists;
bool eac_dead = false;
bool ed_dead = false;
bool eb_dead = false;
bool es_dead = false;
bool ep_dead = false;
bool ac_dead = false;
bool hit = false;
bool game_loop = true;
string ac_location[5];
string b_location[4];
string player_blacklist[50];
string d_location1;
string S_Location1;
string p_location1;
string expand_code;

string hit_array[17];
signed char player_array_char[10][10] =
{
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
};
signed char enemy_array_char[10][10] =
{
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
};
signed char enemy_array_char_blank[10][10] =
{
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
{254,254,254,254,254,254,254,254,254,254},
};

string player_array[10][10] =
{
{ "A10", "B10", "C10", "D10", "E10", "F10", "G10", "H10", "I10", "J10" },
{ "A9", "B9", "C9", "D9", "E9", "F9", "G9", "H9", "I9", "J9" },
{ "A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8", "I8", "J8" },
{ "A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7", "I7", "J7" },
{ "A6", "B6", "C6", "D6", "E6", "F6", "G6", "H6", "I6", "J6" },
{ "A5", "B5", "C5", "D5", "E5", "F5", "G5", "H5", "I5", "J5" },
{ "A4", "B4", "C4", "D4", "E4", "F4", "G4", "H4", "I4", "J4" },
{ "A3", "B3", "C3", "D3", "E3", "F3", "G3", "H3", "I3", "J3" },
{ "A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2", "I2", "J2" },
{ "A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1", "I1", "J1" },
};
string enemy_array[10][10] =
{
{ "A10", "B10", "C10", "D10", "E10", "F10", "G10", "H10", "I10", "J10" },
{ "A9", "B9", "C9", "D9", "E9", "F9", "G9", "H9", "I9", "J9" },
{ "A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8", "I8", "J8" },
{ "A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7", "I7", "J7" },
{ "A6", "B6", "C6", "D6", "E6", "F6", "G6", "H6", "I6", "J6" },
{ "A5", "B5", "C5", "D5", "E5", "F5", "G5", "H5", "I5", "J5" },
{ "A4", "B4", "C4", "D4", "E4", "F4", "G4", "H4", "I4", "J4" },
{ "A3", "B3", "C3", "D3", "E3", "F3", "G3", "H3", "I3", "J3" },
{ "A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2", "I2", "J2" },
{ "A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1", "I1", "J1" },
};
HANDLE tc = GetStdHandle(STD_OUTPUT_HANDLE); //just once for text colour
int main()
{
	while (game_loop == true)
	{
		Welcome();
		Menu();
		if (placementchoice == "1")
		{
			B_Location();
			D_Location();
			S_Location();
			P_Location();
		}
		else if (placementchoice == "2")
		{
			cout << "Creating Player's board..." << endl;
			Auto_Placement();
			cout << "Creating Enemy's board..." << endl;
			Enemy_Placement();
			system("CLS");
			Game_Loop();
		}
	}
	return(0);
}

void Menu() { //menu function where you select what you want to do
	Sleep(300);
	Upper();
	Sleep(300);
	cout << " 1) Play" << endl;
	Sleep(300);
	cout << " 2) Toggle Cheat Mode (debug mode)" << endl;
	Sleep(300);
	cout << " 3) Exit Game" << endl << endl;
	Sleep(300);
	cout << " Please select an option by inputting an integer from 1-3: " << endl;
	Sleep(300);
	Lower();
	cin >> *pmenu; //stores your option in a pointer to menu
	MenuAnswer();
}
void MenuAnswer() {
	if ((menu.find_first_not_of("0123456789") == string::npos) == true) {//if the input is a number
		if (*pmenu == "1") { //enters play mode
			system("CLS");
			RandomPlacementOrNot();
		}
		else if (*pmenu == "2") { // displays credits
			system("CLS");
			if (debug == false)
			{
				Upper();
				cout << "Cheat mode enabled";
				Lower();
				debug = true;
				Sleep(1000);
			}
			else 
			{
				Upper();
				cout << "Cheat mode disabled";
				Lower();
				debug = false;
				Sleep(1000);
			}
			system("CLS");
			Menu();
		}
		else if (*pmenu == "3") {//quits game
			Quit();
		}
		else {
			system("CLS");//clears screen so it looks nicer and is easier to read
			Sleep(300);
			Upper();
			cout << " The value " << *pmenu << " is not in the range of 1-3. Try again. " << endl;
			Sleep(300);
			Lower();
			Menu();//loops back to the menu so u can try again
		}
	}
	else {//if input is not a number example 1a, a1, a, 1.1 & @#*
		system("CLS");
		Sleep(300);
		Upper();
		cout << " The value " << *pmenu << " is not a valid integer. Try again. " << endl; //tells user its not a valid int
		Sleep(300);
		Lower();
		Menu();//loops back to the menu so u can try again
	}
}

void RandomPlacementOrNot() {
	Upper();
	cout << "Select ship placement method" << endl << endl;
	cout << "1) Manually - Choose where each of your ships will be placed" << endl;
	cout << "2) Random - Your ships will be randomly placed on the field" << endl;
	Lower();
	cin >> placementchoice;
	PlacementAnswer();
}

void Quit() {
	system("CLS");
	Upper();
	Sleep(300);
	cout << " Thanks for playing!" << endl;
	Sleep(300);
	cout << " Exitting Game..." << endl;
	Sleep(300);
	Lower();
	game_loop = false;
	return;
}
void Credits() {
	Upper();
	Sleep(300);
	cout << " Bachelor of Software Engineering" << endl;
	Sleep(300);
	cout << " Media Design School" << endl;
	Sleep(300);
	cout << " Auckland" << endl;
	Sleep(300);
	cout << " New Zealand" << endl;
	Sleep(300);
	cout << " (c)2022 Media Design School" << endl;
	Sleep(300);
	cout << " File Name : Battleship" << endl;
	Sleep(300);
	cout << " Description : Main file which includes a battleship game." << endl;
	Sleep(300);
	cout << " Author : Maxwell Presley" << endl;
	Sleep(300);
	cout << " Mail : Maxwell.Presley@mds.ac.nz" << endl;
	Sleep(300);
	Lower();
}
void Enemy_Array_Print()
{
	bool is_there = false;
	cout << endl;
	//setting the max size of length and height
	const int m = 10, n = 10;
	int start_num = 11;
	for (int i = 0; i < m; i++) {
		start_num--;
		if (start_num == 10)
		{
			cout << start_num << " ";
		}
		else
		{
			cout << start_num << "  ";
		}
		for (int j = 0; j < n; j++) {
			is_there = false;
			Sleep(5);
			//if the char is 254 change colour to red (4) then print the char then change back to white (7)
			if (enemy_array_char[i][j] == 65)
			{
				SetConsoleTextAttribute(tc, 9);
				cout << enemy_array_char[i][j] << " ";
				SetConsoleTextAttribute(tc, 7);
			}
			else if (enemy_array_char[i][j] == 66)
			{
				SetConsoleTextAttribute(tc, 6);
				cout << enemy_array_char[i][j] << " ";
				SetConsoleTextAttribute(tc, 7);
			}
			else if (enemy_array_char[i][j] == 68)
			{
				SetConsoleTextAttribute(tc, 4);
				cout << enemy_array_char[i][j] << " ";
				SetConsoleTextAttribute(tc, 7);
			}
			else if (enemy_array_char[i][j] == 83)
			{
				SetConsoleTextAttribute(tc, 5);
				cout << enemy_array_char[i][j] << " ";
				SetConsoleTextAttribute(tc, 7);
			}
			else if (enemy_array_char[i][j] == 80)
			{
				SetConsoleTextAttribute(tc, 3);
				cout << enemy_array_char[i][j] << " ";
				SetConsoleTextAttribute(tc, 7);
			}
			// 88 == X
			else if (enemy_array_char[i][j] == 88)
			{
				//if A1 is = to any element in hit array do something, if not do something else
				for (int p = 1; p <= 20; ++p) {
					{
						if (enemy_array[i][j] == hit_array[p])
						{
							SetConsoleTextAttribute(tc, 4);
							cout << enemy_array_char[i][j] << " ";
							SetConsoleTextAttribute(tc, 7);
							is_there = true;
						}
					}
				}
				if (is_there == false)
				{
					SetConsoleTextAttribute(tc, 7);
					cout << enemy_array_char[i][j] << " ";
					SetConsoleTextAttribute(tc, 7);
				}
			}
			else
			{
				SetConsoleTextAttribute(tc, 7);
				cout << enemy_array_char[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << "   A B C D E F G H I J" << endl;
}
void Enemy_Array_Blank_Print()
{
	bool is_there = false;
	cout << endl;
	//setting the max size of length and height
	const int m = 10, n = 10;
	int start_num = 11;
	for (int i = 0; i < m; i++) {
		start_num--;
		if (start_num == 10)
		{
			cout << start_num << " ";
		}
		else
		{
			cout << start_num << "  ";
		}
		for (int j = 0; j < n; j++) {
			is_there = false;
			Sleep(5);
			//if the char is 254 change colour to red (4) then print the char then change back to white (7)
			//cout << enemy_array_char[i][j] << endl;
			if (enemy_array_char[i][j] == 65)
			{
				SetConsoleTextAttribute(tc, 7);
				cout << enemy_array_char_blank[i][j] << " ";
				SetConsoleTextAttribute(tc, 7);
			}
			else if (enemy_array_char[i][j] == 66)
			{
				SetConsoleTextAttribute(tc, 7);
				cout << enemy_array_char_blank[i][j] << " ";
				SetConsoleTextAttribute(tc, 7);
			}
			else if (enemy_array_char[i][j] == 68)
			{
				SetConsoleTextAttribute(tc, 7);
				cout << enemy_array_char_blank[i][j] << " ";
				SetConsoleTextAttribute(tc, 7);
			}
			else if (enemy_array_char[i][j] == 83)
			{
				SetConsoleTextAttribute(tc, 7);
				cout << enemy_array_char_blank[i][j] << " ";
				SetConsoleTextAttribute(tc, 7);
			}
			else if (enemy_array_char[i][j] == 80)
			{
				SetConsoleTextAttribute(tc, 7);
				cout << enemy_array_char_blank[i][j] << " ";
				SetConsoleTextAttribute(tc, 7);
			}
			// 88 == X
			else if (enemy_array_char[i][j] == 88)
			{
				//if A1 is = to any element in hit array do something, if not do something else
				for (int p = 1; p <= 20; ++p) {
					{
						if (enemy_array[i][j] == hit_array[p])
						{
							SetConsoleTextAttribute(tc, 4);
							cout << enemy_array_char_blank[i][j] << " ";
							SetConsoleTextAttribute(tc, 7);
							is_there = true;
						}
					}
				}
				if (is_there == false)
				{
					SetConsoleTextAttribute(tc, 7);
					cout << enemy_array_char_blank[i][j] << " ";
					SetConsoleTextAttribute(tc, 7);
				}
			}
			else
			{
				SetConsoleTextAttribute(tc, 7);
				cout << enemy_array_char_blank[i][j] << " ";
				SetConsoleTextAttribute(tc, 7);
			}
		}
		cout << endl;
	}
	cout << "   A B C D E F G H I J" << endl;
}
void Player_Array_Print()
{
	//setting the max size of length and height
	const int m = 10, n = 10;
	int start_num = 11;
	for (int i = 0; i < m; i++) {
		start_num--;
		if (start_num == 10)
		{
			cout << start_num << " ";
		}
		else
		{
			cout << start_num << "  ";
		}
		for (int j = 0; j < n; j++) {
			Sleep(5);
			//if the char is 254 change colour to red (4) then print the char then change back to white (7)
			if (player_array_char[i][j] == 65)
			{
				SetConsoleTextAttribute(tc, 9);
				cout << player_array_char[i][j] << " ";
				SetConsoleTextAttribute(tc, 7);
			}
			else if (player_array_char[i][j] == 66)
			{
				SetConsoleTextAttribute(tc, 6);
				cout << player_array_char[i][j] << " ";
				SetConsoleTextAttribute(tc, 7);
			}
			else if (player_array_char[i][j] == 68)
			{
				SetConsoleTextAttribute(tc, 4);
				cout << player_array_char[i][j] << " ";
				SetConsoleTextAttribute(tc, 7);
			}
			else if (player_array_char[i][j] == 83)
			{
				SetConsoleTextAttribute(tc, 5);
				cout << player_array_char[i][j] << " ";
				SetConsoleTextAttribute(tc, 7);
			}
			else if (player_array_char[i][j] == 80)
			{
				SetConsoleTextAttribute(tc, 3);
				cout << player_array_char[i][j] << " ";
				SetConsoleTextAttribute(tc, 7);
			}
			else
			{
				SetConsoleTextAttribute(tc, 7);
				cout << player_array_char[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << "   A B C D E F G H I J" << endl;
}
void Welcome()
{
	SetConsoleTextAttribute(tc, 4);
	cout << endl << endl << endl << char(201);
	for (int i = 0; i < 23; i++) {
		cout << char(205);
	}
	cout << char(187) << endl;
	Sleep(300);
	cout << char(186);
	SetConsoleTextAttribute(tc, 15);
	cout << "Welcome to Battleships!";
	SetConsoleTextAttribute(tc, 4);
	Sleep(300);
	cout << char(186) << endl;
	cout << char(200);
	for (int i = 0; i < 23; i++) {
		cout << char(205);
	}
	cout << char(188) << endl << endl << endl << endl;
	SetConsoleTextAttribute(tc, 15);
	Sleep(300);
}
void Upper()
{
	SetConsoleTextAttribute(tc, 4);
	for (int i = 0; i < 63; i++) {
		cout << char(205);
	}
	cout << endl;
}
void Lower()
{
	cout << endl;
	for (int i = 0; i < 63; i++) {
		cout << char(205);
	}
	SetConsoleTextAttribute(tc, 15);
	cout << endl;
}
void PlacementAnswer() {
	if ((placementchoice.find_first_not_of("0123456789") == string::npos) == true) {//if the input is a number
		if (*pplacementchoice == "1") {
			Manual();
		}
		else if (*pplacementchoice == "2") {
			system("CLS");
		}
		else {
			system("CLS");//clears screen so it looks nicer and is easier to read
			Sleep(300);
			Upper();
			cout << " The value " << *pplacementchoice << " is not in the range of 1-2. Try again. " << endl;
			Sleep(300);
			Lower();
			RandomPlacementOrNot();//loops back to the menu so u can try again
		}
	}
	else {//if input is not a number example 1a, a1, a, 1.1 & @#*
		system("CLS");
		Sleep(300);
		Upper();
		cout << " The value " << *pplacementchoice << " is not a valid integer. Try again. " << endl; //tells user its not a valid int
		Sleep(300);
		Lower();
		RandomPlacementOrNot();//loops back to the menu so u can try again
	}
}
void Manual()
{
	system("CLS");
	Upper();
	cout << "You Selected Manual.";
	Lower();
	Sleep(500);
	system("CLS");
	AC_Location();
	/*if (player_array[0][0] == "A9")
	{
		//cout << player_array[0][0];
		cout << "A10 Selected";
	}
	else
	{
		cout << "Nope";
	}*/
}
void AC_Location()
{
	Player_Array_Print();
	bool exists = false;
	Upper();
	cout << "These are your ships and their size, you have one of each." << endl << endl;
	cout << "{Type}           | {Size}" << endl;
	cout << "Aircraft Carrier | 5" << endl;
	cout << "Battleship       | 4" << endl;
	cout << "Destroyer        | 3" << endl;
	cout << "Submarine        | 3" << endl;
	cout << "Patrol Boat      | 2" << endl << endl;
	cout << "Please Place your Aircraft Carrier on the grid by inputting" << endl << "the first coordinate(Example: B3): ";
	Lower();
	cin >> ac_location1;

	const int m = 10, n = 10;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (exists == false)
			{
				if (player_array[i][j] == ac_location1)
				{
					//player_array[i][j] = player_array_char[i][j];
					player_array_char[i][j] = 65;
					//if (ac_location
					exists = true;
				}
				else
				{
					exists = false;
				}
			}
		}
	}
	if (exists == true)
	{
		system("CLS");
		Upper();
		cout << ac_location1 << " has been selected";
		Lower();
		Sleep(2000);
		system("CLS");
		AC_Direction();
	}
	else
	{
		system("CLS");
		Upper();
		cout << ac_location1 << " was not found. Make sure your input is correct. (Case sensitive)";
		Lower();
		Sleep(500);
		system("CLS");
		Upper();
		cout << ac_location1 << " was not found. Make sure your input is correct. (Case sensitive).";
		Lower();
		Sleep(500);
		system("CLS");
		Upper();
		cout << ac_location1 << " was not found. Make sure your input is correct. (Case sensitive)..";
		Lower();
		Sleep(500);
		system("CLS");
		Upper();
		cout << ac_location1 << " was not found. Make sure your input is correct. (Case sensitive)...";
		Lower();
		Sleep(500);
		system("CLS");
		AC_Location();
	}
}
void AC_Direction()
{;
	string ac_direction;
	string* pac_direction = &ac_direction;
	Player_Array_Print();
	Upper();
	exists = false;
	cout << "Please choose in which way you want to expand your ship by inputting the corresponding number" << endl;
	cout << "1) Up" << endl;
	cout << "2) Down" << endl;
	cout << "3) Left" << endl;
	cout << "4) Right" << endl;
	cout << "5) Reset Selection";
	Lower();
	cin >> *pac_direction;
	if ((ac_direction.find_first_not_of("0123456789") == string::npos) == true) {//if the input is a number
		if (*pac_direction == "1")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (exists == false)
					{
						if (player_array[i][j] == ac_location1)
						{
							if (i > 3)
							{
								AC_Pos1 = player_array[i][j];
								i--;
								AC_Pos2 = player_array[i][j];
								player_array_char[i][j] = 65;
								i--;
								AC_Pos3 = player_array[i][j];
								player_array_char[i][j] = 65;
								i--;
								AC_Pos4 = player_array[i][j];
								player_array_char[i][j] = 65;
								i--;
								AC_Pos5 = player_array[i][j];
								player_array_char[i][j] = 65;
								system("CLS");
								Upper();
								cout << "Up has been selected";
								Lower();
								Sleep(2000);
								system("CLS");

								exists = true;
							}
							else
							{
								system("CLS");
								Upper();
								cout << "Sorry this ship is to big to place upwards, try again." << endl;
								Lower();
								AC_Direction();
							}
						}
					}
				}
			}
		}
		else if (*pac_direction == "2")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (exists == false)
					{
						if (player_array[i][j] == ac_location1)
						{
							if (i < 6)
							{
								AC_Pos1 = player_array[i][j];
								i++;
								AC_Pos2 = player_array[i][j];
								player_array_char[i][j] = 65;
								i++;
								AC_Pos3 = player_array[i][j];
								player_array_char[i][j] = 65;
								i++;
								AC_Pos4 = player_array[i][j];
								player_array_char[i][j] = 65;
								i++;
								AC_Pos5 = player_array[i][j];
								player_array_char[i][j] = 65;
								exists = true;
								system("CLS");
								Upper();
								cout << "Down has been selected";
								Lower();
								Sleep(2000);
								system("CLS");
							}
							else
							{
								system("CLS");
								Upper();
								cout << "Sorry this ship is to big to place downwards, try again." << endl;
								Lower();
								AC_Direction();
							}
						}
					}
				}
			}
		}
		else if (*pac_direction == "3")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (exists == false)
					{
						if (player_array[i][j] == ac_location1)
						{
							if (j > 3)
							{
								AC_Pos1 = player_array[i][j];
								j--;
								AC_Pos2 = player_array[i][j];
								player_array_char[i][j] = 65;
								j--;
								AC_Pos3 = player_array[i][j];
								player_array_char[i][j] = 65;
								j--;
								AC_Pos4 = player_array[i][j];
								player_array_char[i][j] = 65;
								j--;
								AC_Pos5 = player_array[i][j];
								player_array_char[i][j] = 65;
								system("CLS");
								Upper();
								cout << "Left has been selected";
								Lower();
								Sleep(2000);
								system("CLS");

								exists = true;
							}
							else
							{
								system("CLS");
								Upper();
								cout << "Sorry this ship is to big to place leftwards, try again." << endl;
								Lower();
								AC_Direction();
							}
						}
					}
				}
			}
		}
		else if (*pac_direction == "4")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (exists == false)
					{
						if (player_array[i][j] == ac_location1)
						{
							if (j < 6)
							{
								AC_Pos1 = player_array[i][j];
								j++;
								AC_Pos2 = player_array[i][j];
								player_array_char[i][j] = 65;
								j++;
								AC_Pos3 = player_array[i][j];
								player_array_char[i][j] = 65;
								j++;
								AC_Pos4 = player_array[i][j];
								player_array_char[i][j] = 65;
								j++;
								AC_Pos5 = player_array[i][j];
								player_array_char[i][j] = 65;
								system("CLS");
								Upper();
								cout << "Right has been selected";
								Lower();
								Sleep(2000);
								system("CLS");

								exists = true;
							}
							else
							{
								system("CLS");
								Upper();
								cout << "Sorry this ship is to big to place right, try again." << endl;
								Lower();
								AC_Direction();
							}
						}
					}
				}
			}
		}
		else if (*pac_direction == "5")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (exists == false)
					{
						if (player_array[i][j] == ac_location1)
						{
							//player_array[i][j] = player_array_char[i][j];
							player_array_char[i][j] = 254;
							//if (ac_location
							exists = true;
						}
						else
						{
							exists = false;
						}
					}
				}
			}
			system("CLS");
			AC_Location();;
		}
		else {
			system("CLS");//clears screen so it looks nicer and is easier to read
			Sleep(300);
			Upper();
			cout << " The value " << *pac_direction << " is not in the range of 1-5. Try again. " << endl;
			Sleep(300);
			Lower();
			AC_Direction();//loops back to the menu so u can try again
		}
	}
	else
	{//if input is not a number example 1a, a1, a, 1.1 & @#*
		system("CLS");
		Sleep(300);
		Upper();
		cout << " The value " << *pac_direction << " is not a valid integer. Try again. " << endl; //tells user its not a valid int
		Sleep(300);
		Lower();
		AC_Direction();//loops back to the menu so u can try again
	}
}

void B_Location()
{
	Player_Array_Print();
	bool exists = false;
	bool confirm = false;
	Upper();
	cout << "{Type}           | {Size}" << endl;
	cout << "Battleship       | 4" << endl;
	cout << "Destroyer        | 3" << endl;
	cout << "Submarine        | 3" << endl;
	cout << "Patrol Boat      | 2" << endl << endl;
	cout << "Please Place your battleship on the grid by inputting" << endl << "the first coordinate(Example: B3): ";
	Lower();
	cin >> b_location1;
	const int min = 4;
	const int m = 10, n = 10;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (exists == false)
			{
				if (player_array[i][j] == b_location1)
				{
					if (b_location1 == AC_Pos1 or b_location1 == AC_Pos2 or b_location1 == AC_Pos3 or b_location1 == AC_Pos4 or b_location1 == AC_Pos5)
					{
						system("CLS");
						Upper();
						cout << "Sorry, you cannot place your ship on a pre-existing ship.";
						Lower();
						exists = true;
						B_Location();
					}
					else
					{
						player_array_char[i][j] = 66;
						exists = true;
						confirm = true;
					}
				}
				else
				{
					exists = false;
				}
			}
		}
	}
	if (exists == true and confirm == true)
	{
		system("CLS");
		Upper();
		cout << b_location1 << " has been selected";
		Lower();
		Sleep(2000);
		system("CLS");
		B_Direction();
		player_blacklist[0] = b_location1;
		b_location[0] = b_location1;
	}
	if (exists == false)
	{
		system("CLS");
		Upper();
		cout << b_location1 << " was not found. Make sure your input is correct. (Case sensitive)";
		Lower();
		Sleep(500);
		system("CLS");
		Upper();
		cout << b_location1 << " was not found. Make sure your input is correct. (Case sensitive).";
		Lower();
		Sleep(500);
		system("CLS");
		Upper();
		cout << b_location1 << " was not found. Make sure your input is correct. (Case sensitive)..";
		Lower();
		Sleep(500);
		system("CLS");
		Upper();
		cout << b_location1 << " was not found. Make sure your input is correct. (Case sensitive)...";
		Lower();
		Sleep(500);
		system("CLS");
		B_Location();
	}
}
void B_Direction()
{
	//CAircraft_Carrier AirCraft_Carrier;
	string b_direction;
	string* pb_direction = &b_direction;
	Player_Array_Print();
	Upper();
	exists = false;
	cout << "Please choose in which way you want to expand your ship by inputting the corresponding number" << endl;
	cout << "1) Up" << endl;
	cout << "2) Down" << endl;
	cout << "3) Left" << endl;
	cout << "4) Right" << endl;
	cout << "5) Reset Postion";
	Lower();
	cin >> *pb_direction;
	if ((b_direction.find_first_not_of("0123456789") == string::npos) == true) {//if the input is a number
		if (*pb_direction == "1")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (exists == false)
					{
						if (player_array[i][j] == b_location1)
						{
							if (i > 2)
							{
								B_Pos1 = player_array[i][j];
								i--;
								B_Pos2 = player_array[i][j];
								i--;
								B_Pos3 = player_array[i][j];
								i--;
								B_Pos4 = player_array[i][j];
								if (B_Pos2 == AC_Pos1 or B_Pos2 == AC_Pos2 or B_Pos2 == AC_Pos3 or B_Pos2 == AC_Pos4 or B_Pos2 == AC_Pos5 or
									B_Pos3 == AC_Pos1 or B_Pos3 == AC_Pos2 or B_Pos3 == AC_Pos3 or B_Pos3 == AC_Pos4 or B_Pos3 == AC_Pos5 or
									B_Pos4 == AC_Pos1 or B_Pos4 == AC_Pos2 or B_Pos4 == AC_Pos3 or B_Pos4 == AC_Pos4 or B_Pos4 == AC_Pos5)
								{
									system("CLS");
									Upper();
									cout << "Sorry this ship is to big to place upwards, try again.";
									Lower();
									exists = true;
									B_Direction();
								}
								else
								{
									player_array_char[i][j] = 66;
									i++;
									player_array_char[i][j] = 66;
									i++;
									player_array_char[i][j] = 66;
									i++;
									system("CLS");
									Upper();
									cout << "Up has been selected";
									Lower();
									Sleep(2000);
									system("CLS");
									exists = true;
								}
							}
							else if (i < 3)
							{
								system("CLS");
								Upper();
								cout << "Sorry this ship is to big to place upwards, try again.";
								Lower();
								B_Direction();
							}
						}
					}
				}
			}
		}
		else if (*pb_direction == "2")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (exists == false)
					{
						if (player_array[i][j] == b_location1)
						{
							if (i < 7)
							{
								B_Pos1 = player_array[i][j];
								i++;
								B_Pos2 = player_array[i][j];
								i++;
								B_Pos3 = player_array[i][j];
								i++;
								B_Pos4 = player_array[i][j];
								if (B_Pos2 == AC_Pos1 or B_Pos2 == AC_Pos2 or B_Pos2 == AC_Pos3 or B_Pos2 == AC_Pos4 or B_Pos2 == AC_Pos5 or
									B_Pos3 == AC_Pos1 or B_Pos3 == AC_Pos2 or B_Pos3 == AC_Pos3 or B_Pos3 == AC_Pos4 or B_Pos3 == AC_Pos5 or
									B_Pos4 == AC_Pos1 or B_Pos4 == AC_Pos2 or B_Pos4 == AC_Pos3 or B_Pos4 == AC_Pos4 or B_Pos4 == AC_Pos5)
								{
									system("CLS");
									Upper();
									cout << "Sorry this ship is to big to place downwards, try again.";
									Lower();
									exists = true;
									B_Direction();
								}
								else
								{
									player_array_char[i][j] = 66;
									i--;
									player_array_char[i][j] = 66;
									i--;
									player_array_char[i][j] = 66;
									i--;
									system("CLS");
									Upper();
									cout << "Down has been selected";
									Lower();
									Sleep(2000);
									system("CLS");
									exists = true;
								}
							}
							else if (i > 6)
							{
								system("CLS");
								Upper();
								cout << "Sorry this ship is to big to place downwards, try again.";
								Lower();
								B_Direction();
							}
						}
					}
				}
			}
		}
		else if (*pb_direction == "3")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (exists == false)
					{
						if (player_array[i][j] == b_location1)
						{
							if (j > 2)
							{
								B_Pos1 = player_array[i][j];
								j--;
								B_Pos2 = player_array[i][j];
								j--;
								B_Pos3 = player_array[i][j];
								j--;
								B_Pos4 = player_array[i][j];
								if (B_Pos2 == AC_Pos1 or B_Pos2 == AC_Pos2 or B_Pos2 == AC_Pos3 or B_Pos2 == AC_Pos4 or B_Pos2 == AC_Pos5 or
									B_Pos3 == AC_Pos1 or B_Pos3 == AC_Pos2 or B_Pos3 == AC_Pos3 or B_Pos3 == AC_Pos4 or B_Pos3 == AC_Pos5 or
									B_Pos4 == AC_Pos1 or B_Pos4 == AC_Pos2 or B_Pos4 == AC_Pos3 or B_Pos4 == AC_Pos4 or B_Pos4 == AC_Pos5)
								{
									system("CLS");
									Upper();
									cout << "Sorry this ship is to big to place leftwards, try again.";
									Lower();
									exists = true;
									B_Direction();
								}
								else
								{
									player_array_char[i][j] = 66;
									j++;
									player_array_char[i][j] = 66;
									j++;
									player_array_char[i][j] = 66;
									j++;
									system("CLS");
									Upper();
									cout << "Left has been selected";
									Lower();
									Sleep(2000);
									system("CLS");
									exists = true;
								}
							}
							else if (j < 3)
							{
								system("CLS");
								Upper();
								cout << "Sorry this ship is to big to place leftwards, try again.";
								Lower();
								B_Direction();
							}
						}
					}
				}
			}
		}
		else if (*pb_direction == "4")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (exists == false)
					{
						if (player_array[i][j] == b_location1)
						{
							if (j < 7)
							{
								B_Pos1 = player_array[i][j];
								j++;
								B_Pos2 = player_array[i][j];
								j++;
								B_Pos3 = player_array[i][j];
								j++;
								B_Pos4 = player_array[i][j];
								if (B_Pos2 == AC_Pos1 or B_Pos2 == AC_Pos2 or B_Pos2 == AC_Pos3 or B_Pos2 == AC_Pos4 or B_Pos2 == AC_Pos5 or
									B_Pos3 == AC_Pos1 or B_Pos3 == AC_Pos2 or B_Pos3 == AC_Pos3 or B_Pos3 == AC_Pos4 or B_Pos3 == AC_Pos5 or
									B_Pos4 == AC_Pos1 or B_Pos4 == AC_Pos2 or B_Pos4 == AC_Pos3 or B_Pos4 == AC_Pos4 or B_Pos4 == AC_Pos5)
								{
									system("CLS");
									Upper();
									cout << "Sorry this ship is to big to place rightwards, try again.";
									Lower();
									exists = true;
									B_Direction();
								}
								else
								{
									player_array_char[i][j] = 66;
									j--;
									player_array_char[i][j] = 66;
									j--;
									player_array_char[i][j] = 66;
									j--;
									system("CLS");
									Upper();
									cout << "Right has been selected";
									Lower();
									Sleep(2000);
									system("CLS");
									exists = true;
								}
							}
							else if (j > 6)
							{
								system("CLS");
								Upper();
								cout << "Sorry this ship is to big to place rightwards, try again.";
								Lower();
								B_Direction();
							}
						}
					}
				}
			}
		}
		else if (*pb_direction == "5")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (exists == false)
					{
						if (player_array[i][j] == b_location1)
						{
							player_array_char[i][j] = 254;
							exists = true;
						}
						else
						{
							exists = false;
						}
					}
				}
			}
			system("CLS");
			B_Location();
		}
		else
		{
			system("CLS");//clears screen so it looks nicer and is easier to read
			Sleep(300);
			Upper();
			cout << " The value " << *pb_direction << " is not in the range of 1-4. Try again. " << endl;
			Sleep(300);
			Lower();
			B_Direction();//loops back to the menu so u can try again
		}
	}
	else
	{//if input is not a number example 1a, a1, a, 1.1 & @#*
		system("CLS");
		Sleep(300);
		Upper();
		cout << " The value " << *pb_direction << " is not a valid integer. Try again. " << endl; //tells user its not a valid int
		Sleep(300);
		Lower();
		B_Direction();//loops back to the menu so u can try again
	}
}
void D_Location()
{
	Player_Array_Print();
	bool exists = false;
	bool confirm = false;
	Upper();
	cout << "{Type}           | {Size}" << endl;
	cout << "Destroyer        | 3" << endl;
	cout << "Submarine        | 3" << endl;
	cout << "Patrol Boat      | 2" << endl << endl;
	cout << "Please Place your destroyer on the grid by inputting" << endl << "the first coordinate(Example: B3): ";
	Lower();
	cin >> d_location1;
	const int min = 4;
	const int m = 10, n = 10;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (exists == false)
			{
				if (player_array[i][j] == d_location1)
				{
					if (d_location1 == AC_Pos1 or d_location1 == AC_Pos2 or d_location1 == AC_Pos3 or d_location1 == AC_Pos4 or d_location1 == AC_Pos5 or
						d_location1 == B_Pos1 or d_location1 == B_Pos2 or d_location1 == B_Pos3 or d_location1 == B_Pos4)
					{
						system("CLS");
						Upper();
						cout << "Sorry, you cannot place your ship on a pre-existing ship.";
						Lower();
						exists = true;
						D_Location();
					}
					else
					{
						player_array_char[i][j] = 68;
						exists = true;
						confirm = true;
					}
				}
				else
				{
					exists = false;
				}
			}
		}
	}
	if (exists == true and confirm == true)
	{
		system("CLS");
		Upper();
		cout << d_location1 << " has been selected";
		Lower();
		Sleep(2000);
		system("CLS");
		D_Direction();
		player_blacklist[0] = d_location1;
		b_location[0] = d_location1;
	}
	if (exists == false)
	{
		system("CLS");
		Upper();
		cout << d_location1 << " was not found. Make sure your input is correct. (Case sensitive)";
		Lower();
		Sleep(500);
		system("CLS");
		Upper();
		cout << d_location1 << " was not found. Make sure your input is correct. (Case sensitive).";
		Lower();
		Sleep(500);
		system("CLS");
		Upper();
		cout << d_location1 << " was not found. Make sure your input is correct. (Case sensitive)..";
		Lower();
		Sleep(500);
		system("CLS");
		Upper();
		cout << d_location1 << " was not found. Make sure your input is correct. (Case sensitive)...";
		Lower();
		Sleep(500);
		system("CLS");
		D_Location();
	}
}
void D_Direction()
{
	//CAircraft_Carrier AirCraft_Carrier;
	string d_direction;
	string* pd_direction = &d_direction;
	Player_Array_Print();
	Upper();
	exists = false;
	cout << "Please choose in which way you want to expand your ship by inputting the corresponding number" << endl;
	cout << "1) Up" << endl;
	cout << "2) Down" << endl;
	cout << "3) Left" << endl;
	cout << "4) Right" << endl;
	cout << "5) Reset Postion";
	Lower();
	cin >> *pd_direction;
	if ((d_direction.find_first_not_of("0123456789") == string::npos) == true) {//if the input is a number
		if (*pd_direction == "1")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (exists == false)
					{
						if (player_array[i][j] == d_location1)
						{
							if (i > 1)
							{
								D_Pos1 = player_array[i][j];
								i--;
								D_Pos2 = player_array[i][j];
								i--;
								D_Pos3 = player_array[i][j];
								if (D_Pos2 == AC_Pos1 or D_Pos2 == AC_Pos2 or D_Pos2 == AC_Pos3 or D_Pos2 == AC_Pos4 or D_Pos2 == AC_Pos5 or
									D_Pos3 == AC_Pos1 or D_Pos3 == AC_Pos2 or D_Pos3 == AC_Pos3 or D_Pos3 == AC_Pos4 or D_Pos3 == AC_Pos5 or
									D_Pos2 == B_Pos1 or D_Pos2 == B_Pos2 or D_Pos2 == B_Pos3 or D_Pos2 == B_Pos4 or
									D_Pos3 == B_Pos1 or D_Pos3 == B_Pos2 or D_Pos3 == B_Pos3 or D_Pos3 == B_Pos4)
								{
									system("CLS");
									Upper();
									cout << "Sorry this ship is to big to place upwards, try again.";
									Lower();
									exists = true;
									D_Direction();
								}
								else
								{
									player_array_char[i][j] = 68;
									i++;
									player_array_char[i][j] = 68;
									i++;
									system("CLS");
									Upper();
									cout << "Up has been selected";
									Lower();
									Sleep(2000);
									system("CLS");
									exists = true;
								}
							}
							else if (i < 2)
							{
								system("CLS");
								Upper();
								cout << "Sorry this ship is to big to place upwards, try again.";
								Lower();
								D_Direction();
							}
						}
					}
				}
			}
		}
		else if (*pd_direction == "2")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (exists == false)
					{
						if (player_array[i][j] == d_location1)
						{
							if (i < 8)
							{
								D_Pos1 = player_array[i][j];
								i++;
								D_Pos2 = player_array[i][j];
								i++;
								D_Pos3 = player_array[i][j];
								if (D_Pos2 == AC_Pos1 or D_Pos2 == AC_Pos2 or D_Pos2 == AC_Pos3 or D_Pos2 == AC_Pos4 or D_Pos2 == AC_Pos5 or
									D_Pos3 == AC_Pos1 or D_Pos3 == AC_Pos2 or D_Pos3 == AC_Pos3 or D_Pos3 == AC_Pos4 or D_Pos3 == AC_Pos5 or
									D_Pos2 == B_Pos1 or D_Pos2 == B_Pos2 or D_Pos2 == B_Pos3 or D_Pos2 == B_Pos4 or
									D_Pos3 == B_Pos1 or D_Pos3 == B_Pos2 or D_Pos3 == B_Pos3 or D_Pos3 == B_Pos4)
								{
									system("CLS");
									Upper();
									cout << "Sorry this ship is to big to place downwards, try again.";
									Lower();
									exists = true;
									D_Direction();
								}
								else
								{
									player_array_char[i][j] = 68;
									i--;
									player_array_char[i][j] = 68;
									i--;
									system("CLS");
									Upper();
									cout << "Down has been selected";
									Lower();
									Sleep(2000);
									system("CLS");
									exists = true;
								}
							}
							else if (i > 7)
							{
								system("CLS");
								Upper();
								cout << "Sorry this ship is to big to place downwards, try again.";
								Lower();
								D_Direction();
							}
						}
					}
				}
			}
		}
		else if (*pd_direction == "3")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (exists == false)
					{
						if (player_array[i][j] == d_location1)
						{
							if (j > 1)
							{
								D_Pos1 = player_array[i][j];
								j--;
								D_Pos2 = player_array[i][j];
								j--;
								D_Pos3 = player_array[i][j];
								if (D_Pos2 == AC_Pos1 or D_Pos2 == AC_Pos2 or D_Pos2 == AC_Pos3 or D_Pos2 == AC_Pos4 or D_Pos2 == AC_Pos5 or
									D_Pos3 == AC_Pos1 or D_Pos3 == AC_Pos2 or D_Pos3 == AC_Pos3 or D_Pos3 == AC_Pos4 or D_Pos3 == AC_Pos5 or
									D_Pos2 == B_Pos1 or D_Pos2 == B_Pos2 or D_Pos2 == B_Pos3 or D_Pos2 == B_Pos4 or
									D_Pos3 == B_Pos1 or D_Pos3 == B_Pos2 or D_Pos3 == B_Pos3 or D_Pos3 == B_Pos4)
								{
									system("CLS");
									Upper();
									cout << "Sorry this ship is to big to place leftwards, try again.";
									Lower();
									exists = true;
									D_Direction();
								}
								else
								{
									player_array_char[i][j] = 68;
									j++;
									player_array_char[i][j] = 68;
									j++;
									system("CLS");
									Upper();
									cout << "Left has been selected";
									Lower();
									Sleep(2000);
									system("CLS");
									exists = true;
								}
							}
							else if (j < 2)
							{
								system("CLS");
								Upper();
								cout << "Sorry this ship is to big to place leftwards, try again.";
								Lower();
								D_Direction();
							}
						}
					}
				}
			}
		}
		else if (*pd_direction == "4")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (exists == false)
					{
						if (player_array[i][j] == d_location1)
						{
							if (j < 8)
							{
								D_Pos1 = player_array[i][j];
								j++;
								D_Pos2 = player_array[i][j];
								j++;
								D_Pos3 = player_array[i][j];
								if (D_Pos2 == AC_Pos1 or D_Pos2 == AC_Pos2 or D_Pos2 == AC_Pos3 or D_Pos2 == AC_Pos4 or D_Pos2 == AC_Pos5 or
									D_Pos3 == AC_Pos1 or D_Pos3 == AC_Pos2 or D_Pos3 == AC_Pos3 or D_Pos3 == AC_Pos4 or D_Pos3 == AC_Pos5 or
									D_Pos2 == B_Pos1 or D_Pos2 == B_Pos2 or D_Pos2 == B_Pos3 or D_Pos2 == B_Pos4 or
									D_Pos3 == B_Pos1 or D_Pos3 == B_Pos2 or D_Pos3 == B_Pos3 or D_Pos3 == B_Pos4)
								{
									system("CLS");
									Upper();
									cout << "Sorry this ship is to big to place rightwards, try again.";
									Lower();
									exists = true;
									D_Direction();
								}
								else
								{
									player_array_char[i][j] = 68;
									j--;
									player_array_char[i][j] = 68;
									j--;
									system("CLS");
									Upper();
									cout << "Right has been selected";
									Lower();
									Sleep(2000);
									system("CLS");
									exists = true;
								}
							}
							else if (j > 7)
							{
								system("CLS");
								Upper();
								cout << "Sorry this ship is to big to place rightwards, try again.";
								Lower();
								D_Direction();
							}
						}
					}
				}
			}
		}
		else if (*pd_direction == "5")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (exists == false)
					{
						if (player_array[i][j] == d_location1)
						{
							player_array_char[i][j] = 254;
							exists = true;
						}
						else
						{
							exists = false;
						}
					}
				}
			}
			system("CLS");
			D_Location();
		}
		else
		{
			system("CLS");//clears screen so it looks nicer and is easier to read
			Sleep(300);
			Upper();
			cout << " The value " << *pd_direction << " is not in the range of 1-4. Try again. " << endl;
			Sleep(300);
			Lower();
			D_Direction();//loops back to the menu so u can try again
		}
	}
	else
	{
		system("CLS");
		Sleep(300);
		Upper();
		cout << " The value " << *pd_direction << " is not a valid integer. Try again. " << endl; //tells user its not a valid int
		Sleep(300);
		Lower();
		D_Direction();
	}
}

void S_Location()
{
	Player_Array_Print();
	bool exists = false;
	bool confirm = false;
	Upper();
	cout << "{Type}           | {Size}" << endl;
	cout << "Submarine        | 3" << endl;
	cout << "Patrol Boat      | 2" << endl << endl;
	cout << "Please Place your submarine on the grid by inputting" << endl << "the first coordinate(Example: B3): ";
	Lower();
	cin >> S_Location1;
	const int min = 4;
	const int m = 10, n = 10;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (exists == false)
			{
				if (player_array[i][j] == S_Location1)
				{
					if (S_Location1 == AC_Pos1 or S_Location1 == AC_Pos2 or S_Location1 == AC_Pos3 or S_Location1 == AC_Pos4 or S_Location1 == AC_Pos5 or
						S_Location1 == B_Pos1 or S_Location1 == B_Pos2 or S_Location1 == B_Pos3 or S_Location1 == B_Pos4 or
						S_Location1 == D_Pos1 or S_Location1 == D_Pos2 or S_Location1 == D_Pos3)
					{
						system("CLS");
						Upper();
						cout << "Sorry, you cannot place your ship on a pre-existing ship.";
						Lower();
						exists = true;
						S_Location();
					}
					else
					{
						player_array_char[i][j] = 83;
						exists = true;
						confirm = true;
					}
				}
				else
				{
					exists = false;
				}
			}
		}
	}
	if (exists == true and confirm == true)
	{
		system("CLS");
		Upper();
		cout << S_Location1 << " has been selected";
		Lower();
		Sleep(2000);
		system("CLS");
		S_Direction();
		player_blacklist[0] = S_Location1;
		b_location[0] = S_Location1;
	}
	if (exists == false)
	{
		system("CLS");
		Upper();
		cout << S_Location1 << " was not found. Make sure your input is correct. (Case sensitive)";
		Lower();
		Sleep(500);
		system("CLS");
		Upper();
		cout << S_Location1 << " was not found. Make sure your input is correct. (Case sensitive).";
		Lower();
		Sleep(500);
		system("CLS");
		Upper();
		cout << S_Location1 << " was not found. Make sure your input is correct. (Case sensitive)..";
		Lower();
		Sleep(500);
		system("CLS");
		Upper();
		cout << S_Location1 << " was not found. Make sure your input is correct. (Case sensitive)...";
		Lower();
		Sleep(500);
		system("CLS");
		S_Location();
	}
}
void S_Direction()
{
	//CAircraft_Carrier AirCraft_Carrier;
	string s_direction;
	string* ps_direction = &s_direction;
	Player_Array_Print();
	Upper();
	exists = false;
	cout << "Please choose in which way you want to expand your ship by inputting the corresponding number" << endl;
	cout << "1) Up" << endl;
	cout << "2) Down" << endl;
	cout << "3) Left" << endl;
	cout << "4) Right" << endl;
	cout << "5) Reset Postion";
	Lower();
	cin >> *ps_direction;
	if ((s_direction.find_first_not_of("0123456789") == string::npos) == true) {//if the input is a number
		if (*ps_direction == "1")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (exists == false)
					{
						if (player_array[i][j] == S_Location1)
						{
							if (i > 1)
							{
								S_Pos1 = player_array[i][j];
								i--;
								S_Pos2 = player_array[i][j];
								i--;
								S_Pos3 = player_array[i][j];
								if (S_Pos2 == AC_Pos1 or S_Pos2 == AC_Pos2 or S_Pos2 == AC_Pos3 or S_Pos2 == AC_Pos4 or S_Pos2 == AC_Pos5 or
									S_Pos3 == AC_Pos1 or S_Pos3 == AC_Pos2 or S_Pos3 == AC_Pos3 or S_Pos3 == AC_Pos4 or S_Pos3 == AC_Pos5 or
									S_Pos2 == B_Pos1 or S_Pos2 == B_Pos2 or S_Pos2 == B_Pos3 or S_Pos2 == B_Pos4 or
									S_Pos3 == B_Pos1 or S_Pos3 == B_Pos2 or S_Pos3 == B_Pos3 or S_Pos3 == B_Pos4 or
									S_Pos2 == D_Pos1 or S_Pos2 == D_Pos2 or S_Pos2 == D_Pos3 or
									S_Pos3 == D_Pos1 or S_Pos3 == D_Pos2 or S_Pos3 == D_Pos3)
								{
									system("CLS");
									Upper();
									cout << "Sorry this ship is to big to place upwards, try again.";
									Lower();
									exists = true;
									S_Direction();
								}
								else
								{
									player_array_char[i][j] = 83;
									i++;
									player_array_char[i][j] = 83;
									i++;
									system("CLS");
									Upper();
									cout << "Up has been selected";
									Lower();
									Sleep(2000);
									system("CLS");
									exists = true;
								}
							}
							else if (i < 2)
							{
								system("CLS");
								Upper();
								cout << "Sorry this ship is to big to place upwards, try again.";
								Lower();
								S_Direction();
							}
						}
					}
				}
			}
		}
		else if (*ps_direction == "2")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (exists == false)
					{
						if (player_array[i][j] == S_Location1)
						{
							if (i < 8)
							{
								S_Pos1 = player_array[i][j];
								i++;
								S_Pos2 = player_array[i][j];
								i++;
								S_Pos3 = player_array[i][j];
								if (S_Pos2 == AC_Pos1 or S_Pos2 == AC_Pos2 or S_Pos2 == AC_Pos3 or S_Pos2 == AC_Pos4 or S_Pos2 == AC_Pos5 or
									S_Pos3 == AC_Pos1 or S_Pos3 == AC_Pos2 or S_Pos3 == AC_Pos3 or S_Pos3 == AC_Pos4 or S_Pos3 == AC_Pos5 or
									S_Pos2 == B_Pos1 or S_Pos2 == B_Pos2 or S_Pos2 == B_Pos3 or S_Pos2 == B_Pos4 or
									S_Pos3 == B_Pos1 or S_Pos3 == B_Pos2 or S_Pos3 == B_Pos3 or S_Pos3 == B_Pos4 or
									S_Pos2 == D_Pos1 or S_Pos2 == D_Pos2 or S_Pos2 == D_Pos3 or
									S_Pos3 == D_Pos1 or S_Pos3 == D_Pos2 or S_Pos3 == D_Pos3)
								{
									system("CLS");
									Upper();
									cout << "Sorry this ship is to big to place downwards, try again.";
									Lower();
									exists = true;
									S_Direction();
								}
								else
								{
									player_array_char[i][j] = 83;
									i--;
									player_array_char[i][j] = 83;
									i--;
									system("CLS");
									Upper();
									cout << "Up has been selected";
									Lower();
									Sleep(2000);
									system("CLS");
									exists = true;
								}
							}
							else if (i > 7)
							{
								system("CLS");
								Upper();
								cout << "Sorry this ship is to big to place downwards, try again.";
								Lower();
								S_Direction();
							}
						}
					}
				}
			}
		}
		else if (*ps_direction == "3")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (exists == false)
					{
						if (player_array[i][j] == S_Location1)
						{
							if (j > 1)
							{
								S_Pos1 = player_array[i][j];
								j--;
								S_Pos2 = player_array[i][j];
								j--;
								S_Pos3 = player_array[i][j];
								if (S_Pos2 == AC_Pos1 or S_Pos2 == AC_Pos2 or S_Pos2 == AC_Pos3 or S_Pos2 == AC_Pos4 or S_Pos2 == AC_Pos5 or
									S_Pos3 == AC_Pos1 or S_Pos3 == AC_Pos2 or S_Pos3 == AC_Pos3 or S_Pos3 == AC_Pos4 or S_Pos3 == AC_Pos5 or
									S_Pos2 == B_Pos1 or S_Pos2 == B_Pos2 or S_Pos2 == B_Pos3 or S_Pos2 == B_Pos4 or
									S_Pos3 == B_Pos1 or S_Pos3 == B_Pos2 or S_Pos3 == B_Pos3 or S_Pos3 == B_Pos4 or
									S_Pos2 == D_Pos1 or S_Pos2 == D_Pos2 or S_Pos2 == D_Pos3 or
									S_Pos3 == D_Pos1 or S_Pos3 == D_Pos2 or S_Pos3 == D_Pos3)
								{
									system("CLS");
									Upper();
									cout << "Sorry this ship is to big to place leftwards, try again.";
									Lower();
									exists = true;
									S_Direction();
								}
								else
								{
									player_array_char[i][j] = 83;
									j++;
									player_array_char[i][j] = 83;
									j++;
									system("CLS");
									Upper();
									cout << "Up has been selected";
									Lower();
									Sleep(2000);
									system("CLS");
									exists = true;
								}
							}
							else if (j < 2)
							{
								system("CLS");
								Upper();
								cout << "Sorry this ship is to big to place leftwards, try again.";
								Lower();
								S_Direction();
							}
						}
					}
				}
			}
		}
		else if (*ps_direction == "4")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (exists == false)
					{
						if (player_array[i][j] == S_Location1)
						{
							if (j < 8)
							{
								S_Pos1 = player_array[i][j];
								j++;
								S_Pos2 = player_array[i][j];
								j++;
								S_Pos3 = player_array[i][j];
								if (S_Pos2 == AC_Pos1 or S_Pos2 == AC_Pos2 or S_Pos2 == AC_Pos3 or S_Pos2 == AC_Pos4 or S_Pos2 == AC_Pos5 or
									S_Pos3 == AC_Pos1 or S_Pos3 == AC_Pos2 or S_Pos3 == AC_Pos3 or S_Pos3 == AC_Pos4 or S_Pos3 == AC_Pos5 or
									S_Pos2 == B_Pos1 or S_Pos2 == B_Pos2 or S_Pos2 == B_Pos3 or S_Pos2 == B_Pos4 or
									S_Pos3 == B_Pos1 or S_Pos3 == B_Pos2 or S_Pos3 == B_Pos3 or S_Pos3 == B_Pos4 or
									S_Pos2 == D_Pos1 or S_Pos2 == D_Pos2 or S_Pos2 == D_Pos3 or
									S_Pos3 == D_Pos1 or S_Pos3 == D_Pos2 or S_Pos3 == D_Pos3)
								{
									system("CLS");
									Upper();
									cout << "Sorry this ship is to big to place rightwards, try again.";
									Lower();
									exists = true;
									S_Direction();
								}
								else
								{
									player_array_char[i][j] = 83;
									j--;
									player_array_char[i][j] = 83;
									j--;
									system("CLS");
									Upper();
									cout << "Up has been selected";
									Lower();
									Sleep(2000);
									system("CLS");
									exists = true;
								}
							}
							else if (j > 7)
							{
								system("CLS");
								Upper();
								cout << "Sorry this ship is to big to place rightwards, try again.";
								Lower();
								S_Direction();
							}
						}
					}
				}
			}
		}
		else if (*ps_direction == "5")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (exists == false)
					{
						if (player_array[i][j] == S_Location1)
						{
							player_array_char[i][j] = 254;
							exists = true;
						}
						else
						{
							exists = false;
						}
					}
				}
			}
			system("CLS");
			S_Location();
		}
		else
		{
			system("CLS");//clears screen so it looks nicer and is easier to read
			Sleep(300);
			Upper();
			cout << " The value " << *ps_direction << " is not in the range of 1-4. Try again. " << endl;
			Sleep(300);
			Lower();
			S_Direction();//loops back to the menu so u can try again
		}
	}
	else
	{
		system("CLS");
		Sleep(300);
		Upper();
		cout << " The value " << *ps_direction << " is not a valid integer. Try again. " << endl; //tells user its not a valid int
		Sleep(300);
		Lower();
		S_Direction();
	}
}
void P_Location()
{
	Player_Array_Print();
	bool exists = false;
	bool confirm = false;
	Upper();
	cout << "{Type}           | {Size}" << endl;
	cout << "Patrol Boat      | 2" << endl << endl;
	cout << "Please Place your patrol boat on the grid by inputting" << endl << "the first coordinate(Example: B3): ";
	Lower();
	cin >> p_location1;
	const int min = 4;
	const int m = 10, n = 10;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (exists == false)
			{
				if (player_array[i][j] == p_location1)
				{
					if (p_location1 == AC_Pos1 or p_location1 == AC_Pos2 or p_location1 == AC_Pos3 or p_location1 == AC_Pos4 or p_location1 == AC_Pos5 or
						p_location1 == B_Pos1 or p_location1 == B_Pos2 or p_location1 == B_Pos3 or p_location1 == B_Pos4 or
						p_location1 == D_Pos1 or p_location1 == D_Pos2 or p_location1 == D_Pos3 or
						p_location1 == S_Pos1 or p_location1 == S_Pos2 or p_location1 == S_Pos3)
					{
						system("CLS");
						Upper();
						cout << "Sorry, you cannot place your ship on a pre-existing ship.";
						Lower();
						exists = true;
						P_Location();
					}
					else
					{
						player_array_char[i][j] = 80;
						exists = true;
						confirm = true;
					}
				}
				else
				{
					exists = false;
				}
			}
		}
	}
	if (exists == true and confirm == true)
	{
		system("CLS");
		Upper();
		cout << p_location1 << " has been selected";
		Lower();
		Sleep(2000);
		system("CLS");
		P_Direction();
		player_blacklist[0] = p_location1;
		b_location[0] = p_location1;
	}
	if (exists == false)
	{
		system("CLS");
		Upper();
		cout << p_location1 << " was not found. Make sure your input is correct. (Case sensitive)";
		Lower();
		Sleep(500);
		system("CLS");
		Upper();
		cout << p_location1 << " was not found. Make sure your input is correct. (Case sensitive).";
		Lower();
		Sleep(500);
		system("CLS");
		Upper();
		cout << p_location1 << " was not found. Make sure your input is correct. (Case sensitive)..";
		Lower();
		Sleep(500);
		system("CLS");
		Upper();
		cout << p_location1 << " was not found. Make sure your input is correct. (Case sensitive)...";
		Lower();
		Sleep(500);
		system("CLS");
		P_Location();
	}
}
void P_Direction()
{
	//CAircraft_Carrier AirCraft_Carrier;
	string s_direction;
	string* ps_direction = &s_direction;
	Player_Array_Print();
	Upper();
	exists = false;
	cout << "Please choose in which way you want to expand your ship by inputting the corresponding number" << endl;
	cout << "1) Up" << endl;
	cout << "2) Down" << endl;
	cout << "3) Left" << endl;
	cout << "4) Right" << endl;
	cout << "5) Reset Postion";
	Lower();
	cin >> *ps_direction;
	if ((s_direction.find_first_not_of("0123456789") == string::npos) == true) {//if the input is a number
		if (*ps_direction == "1")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (exists == false)
					{
						if (player_array[i][j] == p_location1)
						{
							if (i > 1)
							{
								P_Pos1 = player_array[i][j];
								i--;
								P_Pos2 = player_array[i][j];
								if (P_Pos2 == AC_Pos1 or P_Pos2 == AC_Pos2 or P_Pos2 == AC_Pos3 or P_Pos2 == AC_Pos4 or P_Pos2 == AC_Pos5 or
									P_Pos2 == B_Pos1 or P_Pos2 == B_Pos2 or P_Pos2 == B_Pos3 or P_Pos2 == B_Pos4 or
									P_Pos2 == D_Pos1 or P_Pos2 == D_Pos2 or P_Pos2 == D_Pos3 or
									P_Pos2 == S_Pos2 or P_Pos2 == S_Pos3)
								{
									system("CLS");
									Upper();
									cout << "Sorry this ship is to big to place upwards, try again.";
									Lower();
									exists = true;
									P_Direction();
								}
								else
								{
									player_array_char[i][j] = 80;
									i++;
									player_array_char[i][j] = 80;
									system("CLS");
									Upper();
									cout << "Up has been selected";
									Lower();
									Sleep(2000);
									system("CLS");
									exists = true;
								}
							}
							else if (i < 2)
							{
								system("CLS");
								Upper();
								cout << "Sorry this ship is to big to place upwards, try again.";
								Lower();
								P_Direction();
							}
						}
					}
				}
			}
		}
		else if (*ps_direction == "2")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (exists == false)
					{
						if (player_array[i][j] == p_location1)
						{
							if (i < 8)
							{
								P_Pos1 = player_array[i][j];
								i++;
								P_Pos2 = player_array[i][j];
								if (P_Pos2 == AC_Pos1 or P_Pos2 == AC_Pos2 or P_Pos2 == AC_Pos3 or P_Pos2 == AC_Pos4 or P_Pos2 == AC_Pos5 or
									P_Pos2 == B_Pos1 or P_Pos2 == B_Pos2 or P_Pos2 == B_Pos3 or P_Pos2 == B_Pos4 or
									P_Pos2 == D_Pos1 or P_Pos2 == D_Pos2 or P_Pos2 == D_Pos3 or
									P_Pos2 == S_Pos2 or P_Pos2 == S_Pos3)
								{
									system("CLS");
									Upper();
									cout << "Sorry this ship is to big to place downwards, try again.";
									Lower();
									exists = true;
									P_Direction();
								}
								else
								{
									player_array_char[i][j] = 80;
									i--;
									player_array_char[i][j] = 80;
									system("CLS");
									Upper();
									cout << "Up has been selected";
									Lower();
									Sleep(2000);
									system("CLS");
									exists = true;
								}
							}
							else if (i > 7)
							{
								system("CLS");
								Upper();
								cout << "Sorry this ship is to big to place downwards, try again.";
								Lower();
								P_Direction();
							}
						}
					}
				}
			}
		}
		else if (*ps_direction == "3")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (exists == false)
					{
						if (player_array[i][j] == p_location1)
						{
							if (j > 1)
							{
								P_Pos1 = player_array[i][j];
								j--;
								P_Pos2 = player_array[i][j];
								if (P_Pos2 == AC_Pos1 or P_Pos2 == AC_Pos2 or P_Pos2 == AC_Pos3 or P_Pos2 == AC_Pos4 or P_Pos2 == AC_Pos5 or
									P_Pos2 == B_Pos1 or P_Pos2 == B_Pos2 or P_Pos2 == B_Pos3 or P_Pos2 == B_Pos4 or
									P_Pos2 == D_Pos1 or P_Pos2 == D_Pos2 or P_Pos2 == D_Pos3 or
									P_Pos2 == S_Pos2 or P_Pos2 == S_Pos3)
								{
									system("CLS");
									Upper();
									cout << "Sorry this ship is to big to place leftwards, try again.";
									Lower();
									exists = true;
									P_Direction();
								}
								else
								{
									player_array_char[i][j] = 80;
									j++;
									player_array_char[i][j] = 80;
									system("CLS");
									Upper();
									cout << "Up has been selected";
									Lower();
									Sleep(2000);
									system("CLS");
									exists = true;
								}
							}
							else if (j < 2)
							{
								system("CLS");
								Upper();
								cout << "Sorry this ship is to big to place leftwards, try again.";
								Lower();
								P_Direction();
							}
						}
					}
				}
			}
		}
		else if (*ps_direction == "4")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (exists == false)
					{
						if (player_array[i][j] == p_location1)
						{
							if (j < 8)
							{
								P_Pos1 = player_array[i][j];
								j++;
								P_Pos2 = player_array[i][j];
								if (P_Pos2 == AC_Pos1 or P_Pos2 == AC_Pos2 or P_Pos2 == AC_Pos3 or P_Pos2 == AC_Pos4 or P_Pos2 == AC_Pos5 or
									P_Pos2 == B_Pos1 or P_Pos2 == B_Pos2 or P_Pos2 == B_Pos3 or P_Pos2 == B_Pos4 or
									P_Pos2 == D_Pos1 or P_Pos2 == D_Pos2 or P_Pos2 == D_Pos3 or
									P_Pos2 == S_Pos2 or P_Pos2 == S_Pos3)
								{
									system("CLS");
									Upper();
									cout << "Sorry this ship is to big to place rightwards, try again.";
									Lower();
									exists = true;
									P_Direction();
								}
								else
								{
									player_array_char[i][j] = 80;
									j--;
									player_array_char[i][j] = 80;
									system("CLS");
									Upper();
									cout << "Up has been selected";
									Lower();
									Sleep(2000);
									system("CLS");
									exists = true;
								}
							}
							else if (j > 7)
							{
								system("CLS");
								Upper();
								cout << "Sorry this ship is to big to place rightwards, try again.";
								Lower();
								P_Direction();
							}
						}
					}
				}
			}
		}
		else if (*ps_direction == "5")
		{
			const int m = 10, n = 10;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (exists == false)
					{
						if (player_array[i][j] == p_location1)
						{
							player_array_char[i][j] = 254;
							exists = true;
						}
						else
						{
							exists = false;
						}
					}
				}
			}
			system("CLS");
			P_Location();
		}
		else
		{
			system("CLS");//clears screen so it looks nicer and is easier to read
			Sleep(300);
			Upper();
			cout << " The value " << *ps_direction << " is not in the range of 1-4. Try again. " << endl;
			Sleep(300);
			Lower();
			P_Direction();//loops back to the menu so u can try again
		}
	}
	else
	{
		system("CLS");
		Sleep(300);
		Upper();
		cout << " The value " << *ps_direction << " is not a valid integer. Try again. " << endl; //tells user its not a valid int
		Sleep(300);
		Lower();
		P_Direction();
	}
}
void Enemy_Placement()
{
	attempts++;
	srand(time(NULL));
	int iran1 = rand();
	int iran2 = rand();
	int iran3 = rand();
	int n1 = iran1 % 10 + 0;
	int n2 = iran2 % 10 + 0;
	for (int i = 1; i <= 5; ++i)
	{
		if (i == 1)
		{
			ship_id = 65;
			enemy_array_char[n1][n2] = ship_id;
			ship_size = 5;
			Valid_Placement_Algorithm(n1, n2);
			Expand_Ship(n1, n2, iran3);
		}
		else if (i == 2)
		{
			ship_id = 66;
			ship_size = 4;
			while (enemy_array_char[n1][n2] == 65)
			{
				iran1 = rand();
				iran2 = rand();
				n1 = iran1 % 10 + 0;
				n2 = iran2 % 10 + 0;
			}
			enemy_array_char[n1][n2] = ship_id;
			Valid_Placement_Algorithm(n1, n2);
			Expand_Ship(n1, n2, iran3);
		}
		else if (i == 3)
		{
			ship_id = 68;
			ship_size = 3;
			while (enemy_array_char[n1][n2] == 65 or enemy_array_char[n1][n2] == 66 or enemy_array_char[n1][n2] == 65 or enemy_array_char[n1][n2] == 66)
			{
				iran1 = rand();//generating 3 random numbers which are seeded to the users time
				iran2 = rand();
				n1 = iran1 % 10 + 0;
				n2 = iran2 % 10 + 0;
			}

			enemy_array_char[n1][n2] = ship_id;
			Valid_Placement_Algorithm(n1, n2);
			Expand_Ship(n1, n2, iran3);
		}
		else if (i == 4)
		{
			ship_id = 83;
			ship_size = 3;
			while (enemy_array_char[n1][n2] == 65 or enemy_array_char[n1][n2] == 66 or enemy_array_char[n1][n2] == 68 or enemy_array_char[n1][n2] == 65 or enemy_array_char[n1][n2] == 66 or n2 == 68)
			{
				iran1 = rand();//generating 3 random numbers which are seeded to the users time
				iran2 = rand();
				n1 = iran1 % 10 + 0;
				n2 = iran2 % 10 + 0;
			}

			enemy_array_char[n1][n2] = ship_id;
			Valid_Placement_Algorithm(n1, n2);
			Expand_Ship(n1, n2, iran3);
		}
		else if (i == 5)
		{
			ship_id = 80;
			ship_size = 2;
			while (enemy_array_char[n1][n2] == 65 or enemy_array_char[n1][n2] == 66 or enemy_array_char[n1][n2] == 68 or enemy_array_char[n1][n2] == 83 or enemy_array_char[n1][n2] == 65 or enemy_array_char[n1][n2] == 66 or enemy_array_char[n1][n2] == 68 or enemy_array_char[n1][n2] == 83)
			{
				iran1 = rand();//generating 3 random numbers which are seeded to the users time
				iran2 = rand();
				n1 = iran1 % 10 + 0;
				n2 = iran2 % 10 + 0;
			}

			//enemy_array_char[n1][n2] = ship_id;
			Valid_Placement_Algorithm(n1, n2);
			Expand_Ship(n1, n2, iran3);
		}
	}
	int eac_count = 0;
	int ed_count = 0;
	int eb_count = 0;
	int es_count = 0;
	int ep_count = 0;
	const int m = 10, n = 10;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (enemy_array_char[i][j] == 65)
			{
				eac_count++;
			}
			else if (enemy_array_char[i][j] == 66)
			{
				eb_count++;
			}
			else if (enemy_array_char[i][j] == 68)
			{
				ed_count++;
			}
			else if (enemy_array_char[i][j] == 83)
			{
				es_count++;
			}
			else if (enemy_array_char[i][j] == 80)
			{
				ep_count++;
			}
		}
	}
	if (eac_count == 5 and ed_count == 3 and eb_count == 4 and es_count == 3 and ep_count == 2)
	{
		cout << "Total attempts: " << attempts;
	}
	else
	{
		const int m = 10, n = 10;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				Sleep(6);
				enemy_array_char[i][j] = 254;
			}
		}
		Enemy_Placement();
	}
}

void Valid_Placement_Algorithm(int& n1, int& n2)
{
	bool cant_left{};
	bool cant_right{};
	bool cant_down{};
	bool cant_up{};
	if (n1 < 4)
	{
		cant_up = true;
	}
	if (n1 > 5)
	{
		cant_down = true;
	}
	if (n2 < 4)
	{
		cant_left = true;
	}
	if (n2 > 5)
	{
		cant_right = true;
	}
	if (cant_down == true)
	{
		if (cant_up == true)
		{
			if (cant_right == true)
			{
				if (cant_left == true)
				{
					//cant up or down or lefr or right
					expand_code = "A";
				}
				else
				{ // cant up or down or right
					expand_code = "B";
				}
			}
			else
			{
				if (cant_left == true)
				{//cant up or down or left
					expand_code = "C";
				}
				else
				{//cant up or down
					expand_code = "D";
				}
			}
		}
		else
		{
			if (cant_right == true)
			{
				if (cant_left == true)
				{//cant down or right or left
					expand_code = "E";
				}
				else
				{//cant down or right
					expand_code = "F";
				}
			}
			else
			{
				if (cant_right == true)
				{
					if (cant_left == true)
					{//cant down or right  or left
						expand_code = "G";
					}
					else
					{//cant down or right
						expand_code = "H";
					}
				}
				else
				{
					if (cant_left == true)
					{//cant down or left
						expand_code = "I";
					}
					else
					{//cant down
						expand_code = "J";
					}
				}
			}
		}
	}
	else
	{
		if (cant_up == true)
		{
			if (cant_right == true)
			{
				if (cant_left == true)
				{//cant up or right or left
					expand_code = "K";
				}
				else
				{//cant up or right
					expand_code = "M";
				}
			}
			else
			{
				if (cant_left == true)
				{//cant up or left
					expand_code = "N";
				}
				else
				{//cant up
					expand_code = "O";
				}
			}
		}
		else
		{
			if (cant_right == true)
			{
				if (cant_left == true)
				{//cant left or right
					expand_code = "P";
				}
				else
				{//cant right
					expand_code = "Q";
				}
			}
			else
			{
				if (cant_left == true)
				{//cant left
					expand_code = "R";
				}
				else
				{//Can do anything
					expand_code = "S";
				}
			}
		}
	}
}
void Expand_Ship(int& n1, int& n2, int& iran3)
{
	if (expand_code == "A")
	{
		//	cout << "cant up or down or left or right";
	}
	else if (expand_code == "B")
	{
		Left(n1, n2);
	}
	else if (expand_code == "C")
	{
		//	cout << "cant expand down or up or left";
		Right(n1, n2);
	}
	else if (expand_code == "D")
	{
		//	cout << "cant expand down or up";
		int n3 = iran3 % 2 + 1;
		if (n3 == 1)
		{
			Right(n1, n2);
		}
		else
		{
			Left(n1, n2);
		}
	}
	else if (expand_code == "E")
	{
		//	cout << "cant expand down or left or right";
		Up(n1, n2);
	}
	else if (expand_code == "F")
	{
		//cout << "cant expand down or right" << endl;
		int n3 = iran3 % 2 + 1;
		if (n3 == 1)
		{
			Left(n1, n2);
		}
		else
		{
			Up(n1, n2);
		}
	}
	else if (expand_code == "G")
	{
		//cout << "cant expand down or right or left";
		Up(n1, n2);
	}
	else if (expand_code == "H")
	{
		//cout << "cant expand down or right";
		int n3 = iran3 % 2 + 1;
		if (n3 == 1)
		{
			Up(n1, n2);
		}
		else
		{
			Left(n1, n2);
		}
	}
	else if (expand_code == "I")
	{
		//cout << "cant expand down or left";
		int n3 = iran3 % 2 + 1;
		if (n3 == 1)
		{
			Up(n1, n2);
		}
		else
		{
			Right(n1, n2);
		}
	}
	else if (expand_code == "J")
	{
		//cout << "cant expand down";
		int n3 = iran3 % 3 + 1;
		if (n3 == 1)
		{
			Up(n1, n2);
		}
		else if (n3 == 2)
		{
			Right(n1, n2);
		}
		else
		{
			Left(n1, n2);
		}
	}
	else if (expand_code == "K")
	{
		//cout << "cant expand up or right or left";
		Down(n1, n2);
	}
	else if (expand_code == "M")
	{
		//cout << "cant expand up or right";
		int n3 = iran3 % 2 + 1;
		if (n3 == 1)
		{
			Down(n1, n2);
		}
		else
		{
			Left(n1, n2);
		}
	}
	else if (expand_code == "N")
	{
		//cout << "cant expand up or left";
		int n3 = iran3 % 2 + 1;
		if (n3 == 1)
		{
			Down(n1, n2);
		}
		else
		{
			Right(n1, n2);
		}
	}
	else if (expand_code == "O")
	{
		//cout << "cant expand up";
		int n3 = iran3 % 3 + 1;
		if (n3 == 1)
		{
			Down(n1, n2);
		}
		else if (n3 == 2)
		{
			Right(n1, n2);
		}
		else
		{
			Left(n1, n2);
		}
	}
	else if (expand_code == "P")
	{
		//cout << "cant expand left or right";
		int n3 = iran3 % 2 + 1;
		if (n3 == 1)
		{
			Down(n1, n2);
		}
		else
		{
			Up(n1, n2);
		}
	}
	else if (expand_code == "Q")
	{
		//cout << "cant expand right";
		int n3 = iran3 % 3 + 1;
		if (n3 == 1)
		{
			Down(n1, n2);
		}
		else if (n3 == 2)
		{
			Up(n1, n2);
		}
		else
		{
			Left(n1, n2);
		}
	}
	else if (expand_code == "R")
	{
		//cout << "cant expand left";
		int n3 = iran3 % 3 + 1;
		if (n3 == 1)
		{
			Down(n1, n2);
		}
		else if (n3 == 2)
		{
			Up(n1, n2);
		}
		else
		{
			Right(n1, n2);
		}
	}
	else if (expand_code == "S")
	{
		//cout << "cant expand down or up or left or right";
		int n3 = iran3 % 4 + 1;
		if (n3 == 1)
		{
			Down(n1, n2);
		}
		else if (n3 == 2)
		{
			Up(n1, n2);
		}
		else if (n3 == 3)
		{
			Right(n1, n2);
		}
		else
		{
			Left(n1, n2);
		}
	}
}
void Left(int& n1, int& n2)
{
	if (ship_size == 2)
	{
		n2--;
		enemy_array_char[n1][n2] = ship_id;
		n2--;
		enemy_array_char[n1][n2] = ship_id;
	}
	else if (ship_size == 3)
	{
		n2--;
		enemy_array_char[n1][n2] = ship_id;
		n2--;
		enemy_array_char[n1][n2] = ship_id;
	}
	else if (ship_size == 4)
	{
		n2--;
		enemy_array_char[n1][n2] = ship_id;
		n2--;
		enemy_array_char[n1][n2] = ship_id;
		n2--;
		enemy_array_char[n1][n2] = ship_id;
	}
	else if (ship_size == 5)
	{
		n2--;
		enemy_array_char[n1][n2] = ship_id;
		n2--;
		enemy_array_char[n1][n2] = ship_id;
		n2--;
		enemy_array_char[n1][n2] = ship_id;
		n2--;
		enemy_array_char[n1][n2] = ship_id;
	}
}
void Right(int& n1, int& n2)
{
	if (ship_size == 2)
	{
		n2++;
		enemy_array_char[n1][n2] = ship_id;
		n2++;
		enemy_array_char[n1][n2] = ship_id;
	}
	else if (ship_size == 3)
	{
		n2++;
		enemy_array_char[n1][n2] = ship_id;
		n2++;
		enemy_array_char[n1][n2] = ship_id;
	}
	else if (ship_size == 4)
	{
		n2++;
		enemy_array_char[n1][n2] = ship_id;
		n2++;
		enemy_array_char[n1][n2] = ship_id;
		n2++;
		enemy_array_char[n1][n2] = ship_id;
	}
	else if (ship_size == 5)
	{
		n2++;
		enemy_array_char[n1][n2] = ship_id;
		n2++;
		enemy_array_char[n1][n2] = ship_id;
		n2++;
		enemy_array_char[n1][n2] = ship_id;
		n2++;
		enemy_array_char[n1][n2] = ship_id;
	}
}
void Up(int& n1, int& n2)
{
	if (ship_size == 2)
	{
		n1--;
		enemy_array_char[n1][n2] = ship_id;
		n1--;
		enemy_array_char[n1][n2] = ship_id;
	}
	else if (ship_size == 3)
	{
		n1--;
		enemy_array_char[n1][n2] = ship_id;
		n1--;
		enemy_array_char[n1][n2] = ship_id;
	}
	else if (ship_size == 4)
	{
		n1--;
		enemy_array_char[n1][n2] = ship_id;
		n1--;
		enemy_array_char[n1][n2] = ship_id;
		n1--;
		enemy_array_char[n1][n2] = ship_id;
	}
	else if (ship_size == 5)
	{
		n1--;
		enemy_array_char[n1][n2] = ship_id;
		n1--;
		enemy_array_char[n1][n2] = ship_id;
		n1--;
		enemy_array_char[n1][n2] = ship_id;
		n1--;
		enemy_array_char[n1][n2] = ship_id;
	}
}
void Down(int& n1, int& n2)
{
	if (ship_size == 2)
	{
		n1++;
		enemy_array_char[n1][n2] = ship_id;
		n1++;
		enemy_array_char[n1][n2] = ship_id;
	}
	else if (ship_size == 3)
	{
		n1++;
		enemy_array_char[n1][n2] = ship_id;
		n1++;
		enemy_array_char[n1][n2] = ship_id;
	}
	else if (ship_size == 4)
	{
		n1++;
		enemy_array_char[n1][n2] = ship_id;
		n1++;
		enemy_array_char[n1][n2] = ship_id;
		n1++;
		enemy_array_char[n1][n2] = ship_id;
	}
	else if (ship_size == 5)
	{
		n1++;
		enemy_array_char[n1][n2] = ship_id;
		n1++;
		enemy_array_char[n1][n2] = ship_id;
		n1++;
		enemy_array_char[n1][n2] = ship_id;
		n1++;
		enemy_array_char[n1][n2] = ship_id;
	}
}
void Auto_Placement()
{
	attempts++;
	srand(time(NULL));
	int iran1 = rand();//generating 3 random numbers which are seeded to the users time
	int iran2 = rand();
	int iran3 = rand();
	int n1 = iran1 % 10 + 0;
	int n2 = iran2 % 10 + 0;
	for (int i = 1; i <= 5; ++i)
	{
		if (i == 1)
		{
			ship_id = 65;
			player_array_char[n1][n2] = ship_id;
			ship_size = 5;
			Auto_Valid_Placement_Algorithm(n1, n2);
			Auto_Expand_Ship(n1, n2, iran3);
		}
		else if (i == 2)
		{
			ship_id = 66;
			ship_size = 4;
			while (player_array_char[n1][n2] == 65)
			{
				iran1 = rand();
				iran2 = rand();
				n1 = iran1 % 10 + 0;
				n2 = iran2 % 10 + 0;
			}
			player_array_char[n1][n2] = ship_id;
			Auto_Valid_Placement_Algorithm(n1, n2);
			Auto_Expand_Ship(n1, n2, iran3);
		}
		else if (i == 3)
		{
			ship_id = 68;
			ship_size = 3;
			while (player_array_char[n1][n2] == 65 or player_array_char[n1][n2] == 66 or player_array_char[n1][n2] == 65 or player_array_char[n1][n2] == 66)
			{
				iran1 = rand();//generating 3 random numbers which are seeded to the users time
				iran2 = rand();
				n1 = iran1 % 10 + 0;
				n2 = iran2 % 10 + 0;
			}

			player_array_char[n1][n2] = ship_id;
			Auto_Valid_Placement_Algorithm(n1, n2);
			Auto_Expand_Ship(n1, n2, iran3);
		}
		else if (i == 4)
		{
			ship_id = 83;
			ship_size = 3;
			while (player_array_char[n1][n2] == 65 or player_array_char[n1][n2] == 66 or player_array_char[n1][n2] == 68 or player_array_char[n1][n2] == 65 or player_array_char[n1][n2] == 66 or n2 == 68)
			{
				iran1 = rand();//generating 3 random numbers which are seeded to the users time
				iran2 = rand();
				n1 = iran1 % 10 + 0;
				n2 = iran2 % 10 + 0;
			}

			player_array_char[n1][n2] = ship_id;
			Auto_Valid_Placement_Algorithm(n1, n2);
			Auto_Expand_Ship(n1, n2, iran3);
		}
		else if (i == 5)
		{
			ship_id = 80;
			ship_size = 2;
			while (player_array_char[n1][n2] == 65 or player_array_char[n1][n2] == 66 or player_array_char[n1][n2] == 68 or player_array_char[n1][n2] == 83 or player_array_char[n1][n2] == 65 or player_array_char[n1][n2] == 66 or player_array_char[n1][n2] == 68 or player_array_char[n1][n2] == 83)
			{
				iran1 = rand();//generating 3 random numbers which are seeded to the users time
				iran2 = rand();
				n1 = iran1 % 10 + 0;
				n2 = iran2 % 10 + 0;
			}

			//player_array_char[n1][n2] = ship_id;
			Auto_Valid_Placement_Algorithm(n1, n2);
			Auto_Expand_Ship(n1, n2, iran3);
		}
	}
	int eac_count = 0;
	int ed_count = 0;
	int eb_count = 0;
	int es_count = 0;
	int ep_count = 0;
	const int m = 10, n = 10;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (player_array_char[i][j] == 65)
			{
				eac_count++;
			}
			else if (player_array_char[i][j] == 66)
			{
				eb_count++;
			}
			else if (player_array_char[i][j] == 68)
			{
				ed_count++;
			}
			else if (player_array_char[i][j] == 83)
			{
				es_count++;
			}
			else if (player_array_char[i][j] == 80)
			{
				ep_count++;
			}
		}
	}
	if (eac_count == 5 and ed_count == 3 and eb_count == 4 and es_count == 3 and ep_count == 2)
	{
		Player_Array_Print();
		Sleep(300);
	}
	else
	{
		const int m = 10, n = 10;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				Sleep(6);
				player_array_char[i][j] = 254;
			}
		}
		Auto_Placement();
	}
}

void Auto_Valid_Placement_Algorithm(int& n1, int& n2)
{
	bool cant_left{};
	bool cant_right{};
	bool cant_down{};
	bool cant_up{};
	if (n1 < 4)
	{
		cant_up = true;
	}
	if (n1 > 5)
	{
		cant_down = true;
	}
	if (n2 < 4)
	{
		cant_left = true;
	}
	if (n2 > 5)
	{
		cant_right = true;
	}
	if (cant_down == true)
	{
		if (cant_up == true)
		{
			if (cant_right == true)
			{
				if (cant_left == true)
				{
					//cant up or down or lefr or right
					expand_code = "A";
				}
				else
				{ // cant up or down or right
					expand_code = "B";
				}
			}
			else
			{
				if (cant_left == true)
				{//cant up or down or left
					expand_code = "C";
				}
				else
				{//cant up or down
					expand_code = "D";
				}
			}
		}
		else
		{
			if (cant_right == true)
			{
				if (cant_left == true)
				{//cant down or right or left
					expand_code = "E";
				}
				else
				{//cant down or right
					expand_code = "F";
				}
			}
			else
			{
				if (cant_right == true)
				{
					if (cant_left == true)
					{//cant down or right  or left
						expand_code = "G";
					}
					else
					{//cant down or right
						expand_code = "H";
					}
				}
				else
				{
					if (cant_left == true)
					{//cant down or left
						expand_code = "I";
					}
					else
					{//cant down
						expand_code = "J";
					}
				}
			}
		}
	}
	else
	{
		if (cant_up == true)
		{
			if (cant_right == true)
			{
				if (cant_left == true)
				{//cant up or right or left
					expand_code = "K";
				}
				else
				{//cant up or right
					expand_code = "M";
				}
			}
			else
			{
				if (cant_left == true)
				{//cant up or left
					expand_code = "N";
				}
				else
				{//cant up
					expand_code = "O";
				}
			}
		}
		else
		{
			if (cant_right == true)
			{
				if (cant_left == true)
				{//cant left or right
					expand_code = "P";
				}
				else
				{//cant right
					expand_code = "Q";
				}
			}
			else
			{
				if (cant_left == true)
				{//cant left
					expand_code = "R";
				}
				else
				{//Can do anything
					expand_code = "S";
				}
			}
		}
	}
}
void Auto_Expand_Ship(int& n1, int& n2, int& iran3)
{
	if (expand_code == "A")
	{
		//cout << "cant up or down or left or right";
	}
	else if (expand_code == "B")
	{
		Auto_Left(n1, n2);
	}
	else if (expand_code == "C")
	{
		//cout << "cant expand down or up or left";
		Auto_Right(n1, n2);
	}
	else if (expand_code == "D")
	{
		//cout << "cant expand down or up";
		int n3 = iran3 % 2 + 1;
		if (n3 == 1)
		{
			Auto_Right(n1, n2);
		}
		else
		{
			Auto_Left(n1, n2);
		}
	}
	else if (expand_code == "E")
	{
		//cout << "cant expand down or left or right";
		Auto_Up(n1, n2);
	}
	else if (expand_code == "F")
	{
		//cout << "cant expand down or right" << endl;
		int n3 = iran3 % 2 + 1;
		if (n3 == 1)
		{
			Auto_Left(n1, n2);
		}
		else
		{
			Auto_Up(n1, n2);
		}
	}
	else if (expand_code == "G")
	{
		//cout << "cant expand down or right or left";
		Auto_Up(n1, n2);
	}
	else if (expand_code == "H")
	{
		//cout << "cant expand down or right";
		int n3 = iran3 % 2 + 1;
		if (n3 == 1)
		{
			Auto_Up(n1, n2);
		}
		else
		{
			Auto_Left(n1, n2);
		}
	}
	else if (expand_code == "I")
	{
		//cout << "cant expand down or left";
		int n3 = iran3 % 2 + 1;
		if (n3 == 1)
		{
			Auto_Up(n1, n2);
		}
		else
		{
			Auto_Right(n1, n2);
		}
	}
	else if (expand_code == "J")
	{
		//cout << "cant expand down";
		int n3 = iran3 % 3 + 1;
		if (n3 == 1)
		{
			Auto_Up(n1, n2);
		}
		else if (n3 == 2)
		{
			Auto_Right(n1, n2);
		}
		else
		{
			Auto_Left(n1, n2);
		}
	}
	else if (expand_code == "K")
	{
		//cout << "cant expand up or right or left";
		Auto_Down(n1, n2);
	}
	else if (expand_code == "M")
	{
		//cout << "cant expand up or right";
		int n3 = iran3 % 2 + 1;
		if (n3 == 1)
		{
			Auto_Down(n1, n2);
		}
		else
		{
			Auto_Left(n1, n2);
		}
	}
	else if (expand_code == "N")
	{
		//cout << "cant expand up or left";
		int n3 = iran3 % 2 + 1;
		if (n3 == 1)
		{
			Auto_Down(n1, n2);
		}
		else
		{
			Auto_Right(n1, n2);
		}
	}
	else if (expand_code == "O")
	{
		//cout << "cant expand up";
		int n3 = iran3 % 3 + 1;
		if (n3 == 1)
		{
			Auto_Down(n1, n2);
		}
		else if (n3 == 2)
		{
			Auto_Right(n1, n2);
		}
		else
		{
			Auto_Left(n1, n2);
		}
	}
	else if (expand_code == "P")
	{
		//cout << "cant expand left or right";
		int n3 = iran3 % 2 + 1;
		if (n3 == 1)
		{
			Auto_Down(n1, n2);
		}
		else
		{
			Auto_Up(n1, n2);
		}
	}
	else if (expand_code == "Q")
	{
		//cout << "cant expand right";
		int n3 = iran3 % 3 + 1;
		if (n3 == 1)
		{
			Auto_Down(n1, n2);
		}
		else if (n3 == 2)
		{
			Auto_Up(n1, n2);
		}
		else
		{
			Auto_Left(n1, n2);
		}
	}
	else if (expand_code == "R")
	{
		//cout << "cant expand left";
		int n3 = iran3 % 3 + 1;
		if (n3 == 1)
		{
			Auto_Down(n1, n2);
		}
		else if (n3 == 2)
		{
			Auto_Up(n1, n2);
		}
		else
		{
			Auto_Right(n1, n2);
		}
	}
	else if (expand_code == "S")
	{
		//cout << "cant expand down or up or left or right";
		int n3 = iran3 % 4 + 1;
		if (n3 == 1)
		{
			Auto_Down(n1, n2);
		}
		else if (n3 == 2)
		{
			Auto_Up(n1, n2);
		}
		else if (n3 == 3)
		{
			Auto_Right(n1, n2);
		}
		else
		{
			Auto_Left(n1, n2);
		}
	}
}
void Auto_Left(int& n1, int& n2)
{
	if (ship_size == 2)
	{
		n2--;
		player_array_char[n1][n2] = ship_id;
		n2--;
		player_array_char[n1][n2] = ship_id;
	}
	else if (ship_size == 3)
	{
		n2--;
		player_array_char[n1][n2] = ship_id;
		n2--;
		player_array_char[n1][n2] = ship_id;
	}
	else if (ship_size == 4)
	{
		n2--;
		player_array_char[n1][n2] = ship_id;
		n2--;
		player_array_char[n1][n2] = ship_id;
		n2--;
		player_array_char[n1][n2] = ship_id;
	}
	else if (ship_size == 5)
	{
		n2--;
		player_array_char[n1][n2] = ship_id;
		n2--;
		player_array_char[n1][n2] = ship_id;
		n2--;
		player_array_char[n1][n2] = ship_id;
		n2--;
		player_array_char[n1][n2] = ship_id;
	}
}
void Auto_Right(int& n1, int& n2)
{
	if (ship_size == 2)
	{
		n2++;
		player_array_char[n1][n2] = ship_id;
		n2++;
		player_array_char[n1][n2] = ship_id;
	}
	else if (ship_size == 3)
	{
		n2++;
		player_array_char[n1][n2] = ship_id;
		n2++;
		player_array_char[n1][n2] = ship_id;
	}
	else if (ship_size == 4)
	{
		n2++;
		player_array_char[n1][n2] = ship_id;
		n2++;
		player_array_char[n1][n2] = ship_id;
		n2++;
		player_array_char[n1][n2] = ship_id;
	}
	else if (ship_size == 5)
	{
		n2++;
		player_array_char[n1][n2] = ship_id;
		n2++;
		player_array_char[n1][n2] = ship_id;
		n2++;
		player_array_char[n1][n2] = ship_id;
		n2++;
		player_array_char[n1][n2] = ship_id;
	}
}
void Auto_Up(int& n1, int& n2)
{
	if (ship_size == 2)
	{
		n1--;
		player_array_char[n1][n2] = ship_id;
		n1--;
		player_array_char[n1][n2] = ship_id;
	}
	else if (ship_size == 3)
	{
		n1--;
		player_array_char[n1][n2] = ship_id;
		n1--;
		player_array_char[n1][n2] = ship_id;
	}
	else if (ship_size == 4)
	{
		n1--;
		player_array_char[n1][n2] = ship_id;
		n1--;
		player_array_char[n1][n2] = ship_id;
		n1--;
		player_array_char[n1][n2] = ship_id;
	}
	else if (ship_size == 5)
	{
		n1--;
		player_array_char[n1][n2] = ship_id;
		n1--;
		player_array_char[n1][n2] = ship_id;
		n1--;
		player_array_char[n1][n2] = ship_id;
		n1--;
		player_array_char[n1][n2] = ship_id;
	}
}
void Auto_Down(int& n1, int& n2)
{
	if (ship_size == 2)
	{
		n1++;
		player_array_char[n1][n2] = ship_id;
		n1++;
		player_array_char[n1][n2] = ship_id;
	}
	else if (ship_size == 3)
	{
		n1++;
		player_array_char[n1][n2] = ship_id;
		n1++;
		player_array_char[n1][n2] = ship_id;
	}
	else if (ship_size == 4)
	{
		n1++;
		player_array_char[n1][n2] = ship_id;
		n1++;
		player_array_char[n1][n2] = ship_id;
		n1++;
		player_array_char[n1][n2] = ship_id;
	}
	else if (ship_size == 5)
	{
		n1++;
		player_array_char[n1][n2] = ship_id;
		n1++;
		player_array_char[n1][n2] = ship_id;
		n1++;
		player_array_char[n1][n2] = ship_id;
		n1++;
		player_array_char[n1][n2] = ship_id;
	}
}
void Game_Loop()
{
	bool deny_fire = false;
	cout << "Enemy Grid!" << endl;
	//Enemy_Array_Print();
	if (debug == true)
	{
		Enemy_Array_Print();
	}
	else
	{
		Enemy_Array_Blank_Print();
	}
	cout << "Your Grid!" << endl << endl;
	Player_Array_Print();
	exists = false;
	string shot;
	Upper();
	cout << "Please input where you want to fire your shot (Example: B3): ";
	Lower();
	cin >> shot;
	const int m = 10, n = 10;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (exists == false)
			{
				if (player_array[i][j] == shot)
				{
					if (enemy_array_char[i][j] == 88)
					{
						exists = false;
						deny_fire = true;
					}
					else
					{
						exists = true;
					}
				}
				else
				{
					//cout << "Try again" << endl;
					exists = false;
				}
			}
		}
	}
	if (exists == true)
	{
		system("CLS");
		Upper();
		cout << shot << " has been selected";
		Lower();
		Sleep(2000);
		system("CLS");
		Player_Shot(shot);
		int eac_count = 0;
		int ed_count = 0;
		int eb_count = 0;
		int es_count = 0;
		int ep_count = 0;
		int ac_count = 0;
		int d_count = 0;
		int b_count = 0;
		int s_count = 0;
		int p_count = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (enemy_array_char[i][j] == 65)
				{
					eac_count++;
				}
				else if (enemy_array_char[i][j] == 66)
				{
					eb_count++;
				}
				else if (enemy_array_char[i][j] == 68)
				{
					ed_count++;
				}
				else if (enemy_array_char[i][j] == 83)
				{
					es_count++;
				}
				else if (enemy_array_char[i][j] == 80)
				{
					ep_count++;
				}
			}
		}
		if (eac_count == 0 and ed_count == 0 and eb_count == 0 and es_count == 0 and ep_count == 0)
		{
			Upper();
			cout << "You have won! ";
			Lower();
		}
		else
		{
			bool enemy_turn = true;
			Enemy_Shot(enemy_turn);
			enemy_turn = false;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (player_array_char[i][j] == 65)
					{
						ac_count++;
					}
					else if (player_array_char[i][j] == 66)
					{
						b_count++;
					}
					else if (player_array_char[i][j] == 68)
					{
						d_count++;
					}
					else if (player_array_char[i][j] == 83)
					{
						s_count++;
					}
					else if (player_array_char[i][j] == 80)
					{
						p_count++;
					}
				}
			}
			if (ac_count == 0 and d_count == 0 and b_count == 0 and s_count == 0 and p_count == 0)
			{
				Upper();
				cout << "You have lost! ";
				Lower();
			}
			else
			{
				Game_Loop();
			}
		}
	}
	else
	{
		if (deny_fire == true)
		{
			system("CLS");
			Upper();
			cout << "You cannot fire where you have already shot";
			Lower();
		}
		else
		{
			system("CLS");
			Upper();
			cout << shot << " was not found. Make sure your input is correct. (Case sensitive)";
			Lower();
			Sleep(500);
			system("CLS");
			Upper();
			cout << shot << " was not found. Make sure your input is correct. (Case sensitive).";
			Lower();
			Sleep(500);
			system("CLS");
			Upper();
			cout << shot << " was not found. Make sure your input is correct. (Case sensitive)..";
			Lower();
			Sleep(500);
			system("CLS");
			Upper();
			cout << shot << " was not found. Make sure your input is correct. (Case sensitive)...";
			Lower();
			Sleep(500);
			system("CLS");
		}
		Game_Loop();
	}
}
void Player_Shot(string& shot)
{
	const int m = 10, n = 10;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (enemy_array[i][j] == shot)
			{
				if (enemy_array_char[i][j] == 65)
				{
					enemy_array_char[i][j] = 88;
					enemy_array_char_blank[i][j] = 88;
					counter++;
					hit_array[counter] = enemy_array[i][j];
				}
				else if (enemy_array_char[i][j] == 66)
				{
					enemy_array_char[i][j] = 88;
					enemy_array_char_blank[i][j] = 88;
					counter++;
					hit_array[counter] = enemy_array[i][j];
				}
				else if (enemy_array_char[i][j] == 68)
				{
					enemy_array_char[i][j] = 88;
					enemy_array_char_blank[i][j] = 88;
					counter++;
					hit_array[counter] = enemy_array[i][j];
				}
				else if (enemy_array_char[i][j] == 83)
				{
					enemy_array_char[i][j] = 88;
					enemy_array_char_blank[i][j] = 88;
					counter++;
					hit_array[counter] = enemy_array[i][j];
				}
				else if (enemy_array_char[i][j] == 80)
				{
					enemy_array_char[i][j] = 88;
					enemy_array_char_blank[i][j] = 88;
					counter++;
					hit_array[counter] = enemy_array[i][j];
				}
				else
				{
					enemy_array_char[i][j] = 88;
					enemy_array_char_blank[i][j] = 88;
				}
			}
		}
	}
	int eac_count = 0;
	int ed_count = 0;
	int eb_count = 0;
	int es_count = 0;
	int ep_count = 0;
	int ac_count = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (enemy_array_char[i][j] == 65)
			{
				eac_count++;
			}
			else if (enemy_array_char[i][j] == 66)
			{
				eb_count++;
			}
			else if (enemy_array_char[i][j] == 68)
			{
				ed_count++;
			}
			else if (enemy_array_char[i][j] == 83)
			{
				es_count++;
			}
			else if (enemy_array_char[i][j] == 80)
			{
				ep_count++;
			}
		}
	}
	if (eac_count == 0 and eac_dead == false)
	{
		Upper();
		cout << "Enemy Aircraft Carrier Destroyed!";
		Lower();
		Sleep(1000);
		eac_dead = true;
	}
	if (ed_count == 0 and ed_dead == false)
	{
		Upper();
		cout << "Enemy Destroyer Destroyed!";
		Lower();
		Sleep(1000);
		ed_dead = true;
	}
	if (eb_count == 0 and eb_dead == false)
	{
		Upper();
		cout << "Enemy Battleship Destroyed!";
		Lower();
		Sleep(1000);
		eb_dead = true;
	}
	if (es_count == 0 and es_dead == false)
	{
		Upper();
		cout << "Enemy Submarine Destroyed!";
		Lower();
		Sleep(1000);
		es_dead = true;
	}
	if (ep_count == 0 and ep_dead == false)
	{
		Upper();
		cout << "Enemy Patrol Boat Destroyed!";
		Lower();
		Sleep(1000);
		ep_dead = true;
	}
}
void Enemy_Shot(bool& enemy_turn)
{
	int iran1 = rand();
	int iran2 = rand();
	int n1 = iran1 % 10 + 0;
	int n2 = iran2 % 10 + 0;
	while (player_array_char[n1][n2] == 88)
	{
		iran1 = rand();
		iran2 = rand();
		n1 = iran1 % 10 + 0;
		n2 = iran2 % 10 + 0;
	}
	player_array_char[n1][n2] = 88;
}