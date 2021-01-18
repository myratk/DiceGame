#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include<ctime>
#include <windows.h>
//#include"Header.h"
using namespace std;

class Player {
public:
	string name;
	int account;
	int bet;
};

Player p1;
Player p2;
int point;
int result;
int nums[2];
char temp_char;
char response;
char cont;
int dice();
void update_account(int p, int update);
void bet_checker(int p);
void drawDice(int dNum);
void win(int pNum);
int processFirstDiceRoll(int num0, int num1);
void firstRound(int pNum);
void evenPoint();
void oddPoint(char r);
void round(int pNum);
void game();

