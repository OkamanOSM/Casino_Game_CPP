#include <iostream>
#include <stdlib.h> // randomness
#include <time.h> // randomness
#include <Windows.h> // it's your choice to use windows.h library
#include <string> // for getline and cin>>ws
#include "Header.h"
#include <cmath> 
#include <iomanip> // for setw()
using namespace std;
int global = 0;


void instruction () {

	cout << "=======" << endl;
	cout << " RULES" << endl;
	cout << "=======" << endl;
	cout << "1) You have to confirm your ID before game." << endl
		<< "2) If you win,you'll get a valid win bonus" <<endl
		<< "3) In a lose case,you'll lose all your bet" << endl;

} // first knowledgement

person ab[15]; // empty class list

int game(int);

void peopleget() {
	string name;
	int age;
	string id;
	int money_value;
	static int personnumb = 0; // to get aware how many people have been got in
	cout << "Your name: ";
	cin >> ws;
	getline(cin, name);
		cout << "Age: ";
		cin >> age;
		cout << "Your ID: ";
		cin >> id;
		if (id.length() != 11) { cout << "Your ID is not compitable"; return; }
		cout << "Money Value: ";
		cin >> money_value;
		ab[personnumb].get(name,age,id,money_value);
		global++; personnumb++;
		cout << "Your account has been established." << endl;
		return;
}
void playentrance() {
	if (global == 0) { cout << "Please register in system."; return; }
	string idcopy; cout << "Please write your ID before playing: ";
	cin >> idcopy; 
	if (idcopy.size() != 11) { cout << "Wrong ID."; return; }
	string idcopy1; int persons = 16; // to learn which of the people belong in that id
		for (int i = 0; i < global; i++) {
			idcopy1 = ab[i].returnid();
			if (idcopy == idcopy1) {persons = i;}
		}
		if (persons == 16) { cout << "Nobody has this ID." << endl; return; } // if nobody has account,it will stay in 16 value

		string namex = ab[persons].returnname();
		int money = ab[persons].returnvalue(); 
		int betmoney;

		cout << "Hello mr/mrs '" << namex << "' you have  " << money  << " dollars. How many will you bet? ";
		cin >> betmoney; 
		if (betmoney > money) {
			cout << "You don't have enough money. Please wrtite bet value again: ";
			cin >> betmoney;
			if (betmoney > money) { cout << "Sorry we can not help you." << endl; return; }
		}		money -= betmoney;
		ab[persons].setvalue(money);
       
	betmoney =	game(betmoney); 
	money += betmoney;
	ab[persons].setvalue( money );
	
	
	cout << "Your now money is: " << money << endl
		<< "==========================================" << endl;
	return;
}

int game (int money) {
	cout << "==========================================" << endl
		<< "Please enter numbers between 1-10: ";
	srand(time(NULL));
	int playernumb; cin >> playernumb;
	int gamenumb = rand() % 10 + 1;

	if (playernumb == gamenumb) { 
		cout << "Congrulations,you won" << endl;
		int profit_margin = rand() % 3 + 1;
		return money * profit_margin;
	}
	else { 
		cout << "Unfortunaately you lost all your bet " << endl;
		return 0; }


}

int main() {
	int returnint = 0;
	instruction();
	cout << "-----------------WELCOME CASINO GAME--------------------" << endl;
	do {
		cout << "What do you want to do?" << endl << endl
			<< "1)Register" <<endl << "2)Play Game" << endl << "9)End Up Application and Delete Data" << endl << "-> ";
		cin >> returnint;
		if (returnint == 1) {
			peopleget();
			Sleep(150);
		}
		else if (returnint == 2) {
			playentrance();
			Sleep(2000);
		}

		else if (returnint == 9) {
			cout << "Thanks for playing" << endl;
		}
		else {	cout << "Please get in a valid value." << endl; Sleep(150);}

		cout << setw(743);
		
	} while (returnint != 9);

}