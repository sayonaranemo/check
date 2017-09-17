#include "h_test.h"
#include <iostream>
#include <fstream>
#include <conio.h>

using namespace std;

list use; 
int s = 5;	

			

void InPut() {

	int i, j;
	char name[20];

	
	cout << " \n Name your file please: ";
	cin >> name;
	ofstream f_out(name, ios::out);

	
	int r;
	cout << " \n How many students would you like to add : ";
	cin >> r;

	
	for (i = 1; i <= r; i++) {
		cout << " \n(1)Enter name: ";
		cin >> use.name;

		cout << " (2)Enter surname: ";
		cin >> use.surname;

		cout << " (3)Enter form: ";
		cin >> use.form;

		for (j = 1; j <= s; j++) {
			cout << " Enter score of " << j << "'s subject: ";
			cin >> use.count[j - 1];
		}

		f_out.write((char*)& use, sizeof(use)); 
	}

	f_out.close();

	_getch();
}



void OutTextPut() {

	int i;
	char nameExisting[20], nameTxt[20];

	
	cout << " \nEnter name of exist file: " << endl;
	cin >> nameExisting;

	ifstream f_in(nameExisting, ios::in); 
	if (!f_in) {
		cerr << " \nSystem error, check your input!" << endl;
		exit(1);
	}

	cout << " Enter the name of new txt file: " << endl;
	cin >> nameTxt;

	ofstream f_out(nameTxt, ios::out); 


									
	while (!f_in.eof()) {

		f_in.read((char*)& use, sizeof(use));
		f_out << use.name << " " << use.surname << " " << use.form << " ";
		for (i = 1; i <= s; i++) f_out << use.count[i - 1] << " ";
		f_out << "\n";
	}

	f_out.close();
	f_in.close();

	_getch();
}


void AddInfo() {

	char name[30];
	int i, j;

	
	cout << " \nEnter the name of existing file: " << endl;
	cin >> name;

	ofstream f_add(name, ios::app); 
	if (!f_add) {
		cerr << " \nSystem error, check your input!" << endl;
		exit(1);
	}

	int r;
	cout << " \nHow many students would you like to add: ";
	cin >> r;

	
	for (i = 1; i <= r; i++) {
		cout << " \n(1)Enter name: ";
		cin >> use.name;

		cout << " (2)Enter surname: ";
		cin >> use.surname;

		cout << " (3)Enter form: ";
		cin >> use.form;

		for (j = 1; j <= s; j++) {
			cout << " Enter mark for the " << j << "'s subject: ";
			cin >> use.count[j - 1];
		}

		f_add.write((char*)& use, sizeof(use)); 
	}

	f_add.close();

	_getch();
}



void Correction() {

	int  j;
	char name[50];

	
	cout << " \nEnter the name of existing file: " << endl;
	cin >> name;

	ofstream f_corr(name, ios::ate); 
	if (!f_corr) {
		cerr << " \nSystem error, check your input" << endl;
		exit(1);
	}

	int lineindex; 

	cout << " \Enter index of the line you would like to correct : ";
	cin >>lineindex;

	while (1) {

		cout << " \n(1)Enter name: ";
		cin >> use.name;

		cout << " (2)Enter surname: ";
		cin >> use.surname;

		cout << " (3)Enter form: ";
		cin >> use.form;

		for (j = 1; j <= s; j++) {
			cout << " Enter score of " << j << "'s subject: ";
			cin >> use.count[j - 1];
		}

		f_corr.seekp((lineindex - 1) * sizeof(use));
		f_corr.write((char*)& use, sizeof(use));

		int answer; 
		cout << " \n Did you end the correction? (Y or N): ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y') break;
	}

	f_corr.close();

	_getch();
}



void FullOptiCorr() {

	char name[70];

	
	cout << " \nEnter the name of existing file: " << endl;
	cin >> name;

	fstream f_corr(name, ios::ate | ios::out | ios::in);
	if (!f_corr) {
		cerr << " \nSystem error, check your input" << endl;
		exit(1);
	}


	while (1)
	{
		int generalIndex;				

		cout << " \Enter index of the necessary function: ";
		cin >> generalIndex;

		f_corr.seekg((generalIndex - 1) * sizeof(use));
		f_corr.read((char*)&use, sizeof(use));

		cout << "\n What would you like to correct: \n" << endl;
		cout << " 1. Name" << endl;
		cout << " 2. Surname" << endl;
		cout << " 3. Form" << endl;
		cout << " 4. Mark for the 1's subject  " << endl;
		cout << " 5. Mark for the 2's subject  " << endl;
		cout << " 6. Mark for the 3's subject  " << endl;
		cout << " 7. Mark for the 4's subject  " << endl;
		cout << " 8. Mark for the 5's subject  " << endl;

		int correctionIndex;
		cin >> correctionIndex;

		switch (correctionIndex)
		{
		case 1: cout << "Enter name: ";
			cin >> use.surname;
			break;
		case 2: cout << "Enter surname: ";
			cin >> use.name;
			break;
		case 3: cout << "Enter class: ";
			cin >> use.form;
			break;
		case 4: cout << " Mark for the 1's subject  " << endl;
			cin >> use.count[0];
			break;
		case 5: cout << " Mark for the 2's subject  " << endl;
			cin >> use.count[1];
			break;
		case 6: cout << " Mark for the 3's subject  " << endl;
			cin >> use.count[2];
			break;
		case 7: cout << " Mark for the 4's subject  " << endl;
			cin >> use.count[3];
			break;
		case 8: cout << " Mark for the 5's subject  " << endl;
			cin >> use.count[4];
			break;
		case 0: break;
		default: cout << "System error!Check your input";
		}

		f_corr.seekp((correctionIndex - 1) * sizeof(use));
		f_corr.write((char*)&use, sizeof(use));

		int answer; 
		cout << " \n Did you end the correction? (Y or N): ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y') break;
	}

	f_corr.close();

	_getch();

}



void CorrType() {

	char s;

	cout << " \n Correct all info? (Y or N): ";
	cin >> s;

	if (s == 'Y' || s == 'y') FullOptiCorr();
	else Correction();
}

