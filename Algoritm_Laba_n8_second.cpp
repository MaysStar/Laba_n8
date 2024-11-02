#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

struct textEditor {
	string name;
	string madeIn;
	string license;
	float rating;
	int price;
};

textEditor newEditor;


int keyboard1() {
	int ch;
	cout << " a - add, d - delete, s - search, r - review, m - modify, f - sorting, esc >" << endl;
	ch = _getch();
	return ch;
}

fstream createFile() {
	fstream my_file;
	return my_file;
}

void operation(fstream file) {
	string text;
	file.open("file", ios::in);
	cout << "Data in file" << endl;
	while (getline(file, text)) {
		cout << text << endl;
	}
	file.close();
}

fstream add(fstream file) {
	string name;
	string maker;
	string license;
	float rating;
	int price;
	cout << "Enter name: ";
	cin >> name;
	newEditor.name = name;
	cout << "Enter maker: ";
	cin >> maker;
	newEditor.madeIn = maker;
	cout << "Enter license: ";
	cin >> license;
	newEditor.license = license;
	cout << "Enter rating: ";
	cin >> rating;
	newEditor.rating = rating;
	cout << "Enter price: ";
	cin >> price;
	newEditor.price = price;
	file.open("file", ios::out);
	if (file) {
		file << newEditor.name <<endl;
		file << newEditor.madeIn << endl;
		file << newEditor.license << endl;
		file << newEditor.rating << endl;
		file << newEditor.price << endl;
	}
	file.close();
	
	return file;
	
}

fstream minus1(fstream file) {
	newEditor.name = "-";
	newEditor.madeIn = "-";
	newEditor.license = "-";
	newEditor.rating = 0;
	newEditor.price = 0;
	file.open("file", ios::out);
	 {
		file << newEditor.name << endl;
		file << newEditor.madeIn << endl;
		file << newEditor.license << endl;
		file << newEditor.rating << endl;
		file << newEditor.price << endl;
	}
	file.close();
	return file;
}

fstream search(fstream file) {
	if (file) {
		file.open("file", ios::in);
		file >> newEditor.name;
		file >> newEditor.madeIn;
		file >> newEditor.license;
		file >> newEditor.rating;
		file >> newEditor.price;
		file.close();
		cout << newEditor.name << endl;
		cout << newEditor.madeIn << endl;
		cout << newEditor.license << endl;
		cout << newEditor.rating << endl;
		cout << newEditor.price << endl;

		cout << "Enter your search: ";
		
		string text;
		cin.ignore();
		getline(cin, text);
		file.open("file", ios::out);
		if (newEditor.name == text) {
			file << "name: " << newEditor.name;
		}
		else if (newEditor.madeIn == text) {
			file << "maker: " << newEditor.madeIn;
		}
		else if (newEditor.license == text) {
			file << "license: " << newEditor.license;
		}
		else if (to_string(newEditor.rating) == text) {
			file << "rating: " << newEditor.rating;
		}
		else if (to_string(newEditor.price) == text) {
			file << "price: " << newEditor.price;
		}
		else {
			file << "value is none";
		}
		file.close();
	}
	return file;
}
fstream review(fstream file) {
	file.open("file", ios::in);
	file >> newEditor.name;
	file >> newEditor.madeIn;
	file >> newEditor.license;
	file >> newEditor.rating;
	file >> newEditor.price;
	file.close();
	cout << newEditor.name << endl;
	cout << newEditor.madeIn << endl;
	cout << newEditor.license << endl;
	cout << newEditor.rating << endl;
	cout << newEditor.price << endl;
	file.open("file", ios::out);
	file << "File was review";
	file.close();
	return file;
}
fstream modify(fstream file) {
	file.open("file", ios::in);
	file >> newEditor.name;
	file >> newEditor.madeIn;
	file >> newEditor.license;
	file >> newEditor.rating;
	file >> newEditor.price;
	file.close();
	cout << newEditor.name << endl;
	cout << newEditor.madeIn << endl;
	cout << newEditor.license << endl;
	cout << newEditor.rating << endl;
	cout << newEditor.price << endl;
	file.open("file", ios::out);
	cout << "Enter element that you want to modify: ";
	string text;
	getline(cin, text);
	if (text == "name") {
		cout << newEditor.name << " ";
		cout << "Modify name: ";
		cin >> newEditor.name;
	}
	if (text == "maker") {
		cout << newEditor.madeIn << " ";
		cout << "Modify madeIn: ";
		cin >> newEditor.madeIn;
	}
	if (text == "license") {
		cout << newEditor.license << " ";
		cout << "Modify license: ";
		cin >> newEditor.license;
	}
	if (text == "rating") {
		cout << newEditor.rating << " ";
		cout << "Modify rating: ";
		cin >> newEditor.rating;
	}
	if (text == "price") {
		cout << newEditor.price << " ";
		cout << "Modify price: ";
		cin >> newEditor.price;
	}
	file.close();
	return file;
}

fstream sorting(fstream file) {
	file.open("file", ios::in);
	file >> newEditor.name;
	file >> newEditor.madeIn;
	file >> newEditor.license;
	file >> newEditor.rating;
	file >> newEditor.price;
	file.close();
	file.open("file", ios::out);
	cout << newEditor.name << endl;
	cout << newEditor.madeIn << endl;
	cout << newEditor.license << endl;
	cout << newEditor.rating << endl;
	cout << newEditor.price << endl;
	file << "File was sorting";
	file.close();
	return file;
}

void manipulating() {
	
	int w = keyboard1();
	if (w == 97) {
		operation(add(createFile()));
		manipulating();
	}
	else if (w == 100) {
		operation(minus1(createFile()));
		manipulating();
	}
	else if (w == 115) {
		operation(search(createFile()));
		manipulating();
	}
	else if (w== 114) {
		operation(review(createFile()));
		manipulating();
	}
	else if (w == 109) {
		operation(modify(createFile()));
		manipulating();
	}
	else if (w == 102) {
		operation(sorting(createFile()));
		manipulating();
	}
	else if (w == 27) {
		cout << "you are out";
	}
	else {
		manipulating();
	}
}



int main() {
	manipulating();
}