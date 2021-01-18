#include "Header.h"
int main() {

	do {
		system("cls");
		p1.account = 500;
		p2.account = 500;
		srand(time(NULL));
		cout << "___________________________________________________________________________________________________________" << endl;
		cout << "                                Welcome to the Craps Game! " << endl;
		cout << "___________________________________________________________________________________________________________" << endl << endl;
		Sleep(1000);
		cout << "Player 1 please enter your name: ";
		cin >> p1.name;
		cout << "Player 2 please enter your name: ";
		cin >> p2.name;
		cout << endl << endl;

		game();

		if (p1.account <= 0) {
			cout << p2.name << " you have won the game!" << endl << endl << endl;
		}
		else {
			cout << p1.name << " you have won the game!" << endl << endl << endl;
		}

		cout << "Would you like to play the game again? (Y/N) ";
		cin >> cont;
	} while (cont == 'Y');
	
	system("pause");
}

int dice() {
	return (rand() % 6) + 1;
}

void update_account(int p, int update) {
	if (p == 1) {
		p1.account = p1.account + update;
	}
	else {
		p2.account = p2.account + update;
	}
}

void bet_checker(int p) {
	if (p == 1) {
		if (p1.bet > p1.account) {
			cout << "Sorry you do not have enough money. PLease enter another amount: ";
			cin >> p1.bet;
			bet_checker(1);
		}
	}
	else {
		if (p2.bet > p2.account) {
			cout << "Sorry you do not have enough money. PLease enter another amount: ";
			cin >> p2.bet;
			bet_checker(2);
		}
	}
}

void drawDice(int dNum) {
	switch (dNum) {
	case 1:
		cout << "+-----+" << endl;
		cout << "|     |" << endl;
		cout << "|  o  |" << endl;
		cout << "|     |" << endl;
		cout << "+-----+" << endl;
		break;
	case 2:
		cout << "+-----+" << endl;
		cout << "| o   |" << endl;
		cout << "|     |" << endl;
		cout << "|   o |" << endl;
		cout << "+-----+" << endl;
		break;
	case 3:
		cout << "+-----+" << endl;
		cout << "| o   |" << endl;
		cout << "|  o  |" << endl;
		cout << "|   o |" << endl;
		cout << "+-----+" << endl;
		break;
	case 4:
		cout << "+-----+" << endl;
		cout << "| o o |" << endl;
		cout << "|     |" << endl;
		cout << "| o o |" << endl;
		cout << "+-----+" << endl;
		break;
	case 5:
		cout << "+-----+" << endl;
		cout << "| o o |" << endl;
		cout << "|  o  |" << endl;
		cout << "| o o |" << endl;
		cout << "+-----+" << endl;
		break;
	case 6:
		cout << "+-----+" << endl;
		cout << "| o o |" << endl;
		cout << "| o o |" << endl;
		cout << "| o o |" << endl;
		cout << "+-----+" << endl;
		break;
	}
}

void win(int pNum) {
	if (pNum == 1) {
		update_account(1, p2.bet);
		update_account(2, (-1 * p2.bet));
		if (result == 1) {
			cout << "Congratulations " << p1.name << " you have won " << p2.bet << endl;
		}
		else {
			cout << "Congratulations " << p2.name << " you have won " << p1.bet << endl;
		}
		cout << p1.name << " has $" << p1.account << endl;
		cout << p2.name << " has $" << p2.account << endl;
		

	}
	else if (pNum == 2) {
		update_account(2, p1.bet);
		update_account(1, (-1 * p1.bet));
		if (result == 1) {
			cout << "Congratulations " << p2.name << " you have won " << p1.bet << endl;
		}
		else {
			cout << "Congratulations " << p1.name << " you have won " << p2.bet << endl;
		}
		cout << p2.name << " has $" << p2.account << endl;
		cout << p1.name << " has $" << p1.account << endl;
	}
	else {
		cout << "Sorry no one won anything" << endl;
		cout << p1.name << " has $" << p1.account << endl;
		cout << p2.name << " has $" << p2.account << endl;
	}
	p1.bet = 0;
	p2.bet = 0;
	point = 0;
	result = 0;
}

int processFirstDiceRoll(int num0, int num1) {
	if ((num0 == 6 && num1 == 6) || (num0 == 1 && num1 == 1)) {
		return 1;
	}

	else {
		point = num0 + num1;
		return 0;
	}
}

void firstRound(int pNum) {
	if (pNum % 2 == 0) { //p1 will be called with an even number
		cout << "                               " << p1.name << " it is now your turn" << endl;
		cout << "___________________________________________________________________________________________________________" << endl << endl;
		cout << p1.name << " please place your bet: ";
		cin >> p1.bet;
		bet_checker(1);
		cout << p2.name << " please place your bet: ";
		cin >> p2.bet;
		bet_checker(2);

		nums[0] = dice();
		nums[1] = dice();

		cout << "Press 'r' to roll the dice. Roll a double 6 or a double 1 to win immediately. Any other number will be saved as your point ";
		cin >> temp_char;

		cout << "You rolled: " << endl;
		Sleep(1000);
		drawDice(nums[0]);
		Sleep(1000);
		drawDice(nums[1]);

		result = processFirstDiceRoll(nums[0], nums[1]);

	}
	else {
		cout << "                               " << p2.name << " it is now your turn" << endl;
		cout << "___________________________________________________________________________________________________________" << endl << endl;
		cout << p2.name << " please place your bet: ";
		cin >> p2.bet;
		bet_checker(2);
		cout << p1.name << " please place your bet: ";
		cin >> p1.bet;
		bet_checker(1);

		nums[0] = dice();
		nums[1] = dice();

		cout << "Press 'r' to roll the dice. Roll a double 6 or a double 1 to win immediately. Any other number will be saved as your point";
		cin >> temp_char;

		cout << "You rolled: " << endl;
		Sleep(1000);
		drawDice(nums[0]);
		Sleep(1000);
		drawDice(nums[1]);

		result = processFirstDiceRoll(nums[0], nums[1]);

	}
}

void evenPoint() {
	while (result == 0) {
		cout << "Press 'r' to roll the dice";
		cin >> temp_char;
		nums[0] = dice();
		nums[1] = dice();

		cout << "You rolled: " << endl;
		Sleep(1000);
		drawDice(nums[0]);
		Sleep(1000);
		drawDice(nums[1]);

		if (nums[0] + nums[1] == point) {
			result = 1;
		}
		else if (nums[0] == nums[1]) {
			result = -1;
		}
	}
}

void oddPoint(char r) {
	if (response == 'S') {
		cout << "Press 'r' to roll the dice ";
		cin >> temp_char;
		nums[0] = dice();
		nums[1] = dice();

		cout << "You rolled: " << endl;
		Sleep(1000);
		drawDice(nums[0]);
		Sleep(1000);
		drawDice(nums[1]);

		if (nums[0] + nums[1] > point) {
			cout << "Excellent, you played a higher number!";
			result = -1;
		}

		else {
			cout << "Sorry, you didn't play a higher number.";
			result = 1;
		}
	}
	else {
		cout << "Press 'r' to roll the dice";
		cin >> temp_char;
		nums[0] = dice();
		nums[1] = dice();

		cout << "You rolled: " << endl;
		Sleep(1000);
		drawDice(nums[0]);
		Sleep(1000);
		drawDice(nums[1]);

		if (nums[0] + nums[1] > point) {
			cout << "Excellent, you played a higher number!";
			result = 1;
		}
		else {
			cout <<  "Sorry, you didn't play a higher number.";
			result = -1;
		}
	}
}

void round(int pNum) {
	firstRound(pNum);
	if (pNum % 2 == 0) {
		if (result == 1) {
			win(1);
		}
		else {
			if (point % 2 == 0) {
				cout << p1.name << " you rolled an even number. You must roll " << point << " again to win. If you roll a double however, you will loose" << endl;
				evenPoint();
			}
			else {
				cout << p1.name << " you rolled an odd number. " << p2.name << " now has a chance to steal your turn. Press 'S' to steal and you will have 1 chance to roll a higher number. Press 'N' and " << p1.name << " will have 1 chance to roll a higher number ";
				cin >> response;

				oddPoint(response);
			}

			if (result == 1) {
				win(1);
			}
			else if (result == -1) {
				win(2);
			}
			else {
				win(0);
			}
		}

	}

	else {
		if (result == 1) {
			win(2);
		}
		else {
			if (point % 2 == 0 && result == 0) {
				cout << p2.name << " you rolled an even number. You must roll " << point << " before you roll a double to win" << endl;
				evenPoint();
			}
			else {
				cout << p2.name << " you rolled an odd number. " << p1.name << " now has a chance to steal your turn. Press 'S' to steal and you will have 1 chance to roll a higher number. Press 'N' and " << p2.name << " wil have 1 chance to roll a higher number ";
				cin >> response;

				oddPoint(response);
			}

			if (result == 1) {
				win(2);
			}
			else if (result == -1) {
				win(1);
			}
			else {
				win(0);
			}
		}

	}
}

void game() {
	for (int i = 0; p1.account > 0 && p2.account > 0; i++) {
		round(i);
		cout << endl << endl;
	}
}




