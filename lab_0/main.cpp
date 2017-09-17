#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "h_test.h"

using namespace std;

int main() {

	int switcher;

start: 


	cout << " Select your option please: " << endl;

	cout << "\n 1. Create file " << endl;
	cout << " 2. Convertig to txt " << endl;
	cout << " 3. Add information to cpp file " << endl;
	cout << " 4. Edit file " << endl;
	cout << " 5. Start " << endl;

	cout << " 0. Exit" << endl;

	cout << "\n Your Choice: ";

	cin >> switcher;
	system("cls");


	switch (switcher) {
	case 1:	InPut();
		_getch();
		system("cls");
		goto start;
		break;
	case 2: OutTextPut();
        _getch();
		system("cls");
		goto start;
		break;
	case 3: AddInfo();
		_getch();
		system("cls");
		goto start;
		break;
	case 4: CorrType();
		_getch();
		system("cls");
		goto start;
		break;
	case 0: return 1;
		_getch();
	default: cerr << "Chek your input please" << endl;
	}

	return 0;
}