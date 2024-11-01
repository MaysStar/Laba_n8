#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct notoriety {
	string lastName;
	string name;
	string father;
	string address;
	string phoneNumber = "-";
};

string enterName() {
	string name;
	cout << "Enter student's name: ";
	getline(cin, name);
	return name;
}

void getData(string name, notoriety students[]) {
	int i = 0;
	while (i < 10) {
		if (students[i].lastName == name) {
			if (students[i].phoneNumber == "-") {
				cout << "Student's " << students[i].address;

			}
			if (students[i].phoneNumber[0] == '0') {
				cout << "Phone number: " << students[i].phoneNumber;
			}
		}
		i++;
	}
}

fstream setData() {
	fstream my_file;
	my_file.open("my_file", ios::out);
	struct notoriety students[] = {
		{"Hrytsak", "Rostyslav", "Yaroslavovich", "address: Sambir", "0688447781"},
		{"Boyko", "Yuriy", "Andriyovich", "address: Lviv", "0699093183"},
		{"Burov", "Nikita", "Andriyovich", "address: Vinnutsya", "-"},
		{"Yarovoy", "Dinilo", "Sergiyovich", "address: Lviv", "0429808292"},
		{"Strashivskiy", "Roman", "Nazarovich", "address: Lviv", "0319103891"},
		{"Kovalchuk", "Nazar", "Romanovich", "address: Koval", "-"},
		{"Hresko", "Oleg", "Sergiyovich", "address: Drogobych", "0294827193"},
		{"Vovk", "Yuliya", "Sergiivna", "address: Lviv", "-"},
		{"Kovalenko", "Olena", "Igorivna", "address: Odesa", "0681313424"},
		{"Bessarab", "Oleksandra", "Sergiivna", "address: Herson", "0971319183"}
	};
	my_file.close();
	getData(enterName(), students);
	return my_file;
}





int main() {
	setData();
}
