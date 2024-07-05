#include "User.h"
#define CLEARBUF   cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');

using namespace std;

bool isvalid_data(const string& data, const string& str_re)
{
	regex re{ str_re };
	return regex_match(data, re);
};

void bookroom(vector<Offers>& rooms, vector<User>& addclients) {
	int tempint = 0;
	for (const auto& i : addclients) {
		if (string(i.room) == string(rooms[0].edition)) {
			tempint++;

		}
	}
	cout << "| L | Lux (" << rooms[0].quantity - tempint << " rooms left)(" << rooms[0].price << " euro per night)  \n";
	tempint = 0;
	for (const auto& i : addclients) {
		if (string(i.room) == string(rooms[1].edition)) {
			tempint++;

		}
	}
	cout << "| E | Economy class (" << rooms[1].quantity - tempint << " rooms left)(" << rooms[1].price << "euro per night)                        \n";
	tempint = 0;
	for (const auto& i : addclients) {
		if (string(i.room) == string(rooms[2].edition)) {
			tempint++;

		}
	}
	cout << "| S | Superior double room (" << rooms[2].quantity - tempint << " rooms left)(" << rooms[2].price << "euro per night)                    \n";
	tempint = 0;
	for (const auto& i : addclients) {
		if (string(i.room) == string(rooms[3].edition)) {
			tempint++;

		}
	}
	cout << "| O | Family room with one child (" << rooms[3].quantity - tempint << " rooms left)(" << rooms[3].price << " euro per night)             \n";
	tempint = 0;
	for (const auto& i : addclients) {
		if (string(i.room) == string(rooms[4].edition)) {
			tempint++;

		}
	}
	cout << "| T | Family room with two or more children (" << rooms[4].quantity - tempint << " rooms left)(" << rooms[4].price << "euro per night)   \n";
	cout << "| C | Quit and save                                                            \n";
}

void WriteIn(vector<User>& addclients) {
	ofstream file("User.bin", ios::binary);
	for (unsigned int i = 0; i < addclients.size(); i++) {
		file.write((char*)(&addclients[i].name), sizeof(addclients[i].name));
		file.write((char*)(&addclients[i].surname), sizeof(addclients[i].surname));
		file.write((char*)(&addclients[i].age), sizeof(addclients[i].age));
		file.write((char*)(&addclients[i].login), sizeof(addclients[i].login));
		file.write((char*)(&addclients[i].password), sizeof(addclients[i].password));
		file.write((char*)(&addclients[i].yphone), sizeof(addclients[i].yphone));
		file.write((char*)(&addclients[i].ygmail), sizeof(addclients[i].ygmail));
		file.write((char*)(&addclients[i].room), sizeof(addclients[i].room));
		file.write((char*)(&addclients[i].nights), sizeof(addclients[i].nights));
		file.write((char*)(&addclients[i].priceForRest), sizeof(addclients[i].priceForRest));
		file.write((char*)(&addclients[i].priceForHot), sizeof(addclients[i].priceForHot));



	}
	file.close();
}

vector<User> ReadIn(vector<User>& addclients) {
	ifstream file("User.bin", ios::binary);
	User ex;
	addclients.clear();
	while (file)
	{
		file.read((char*)(&ex.name), sizeof(ex.name));
		file.read((char*)(&ex.surname), sizeof(ex.surname));
		file.read((char*)(&ex.age), sizeof(ex.age));
		file.read((char*)(&ex.login), sizeof(ex.login));
		file.read((char*)(&ex.password), sizeof(ex.password));
		file.read((char*)(&ex.yphone), sizeof(ex.yphone));
		file.read((char*)(&ex.ygmail), sizeof(ex.ygmail));
		file.read((char*)(&ex.room), sizeof(ex.room));
		file.read((char*)(&ex.nights), sizeof(ex.nights));
		file.read((char*)(&ex.priceForRest), sizeof(ex.priceForRest));
		file.read((char*)(&ex.priceForHot), sizeof(ex.priceForHot));


		if (!file)
			break;
		addclients.push_back(ex);
	}
	file.close();
	return addclients;
}

vector<User> Registration(vector<User>& addclients, size_t& number) {
	number = addclients.size();

	cout << "Adding new object \n";
	addclients.push_back(User());
	cout << "Enter name \n";
	cin.getline(addclients[number].name, 50);
	if (sizeof(addclients[number].name) > 50) {
		CLEARBUF
	}
	cout << "Enter surname \n";
	cin.getline(addclients[number].surname, 50);
	cout << "Enter age: \n";
	string tage;
	string tmail;
	string tnum;
	while (true)
	{
		cin >> tage;
		CLEARBUF
			if (isvalid_data(tage, R"re(\d{1,2})re"))
			{
				addclients[number].age = (short)stoi(tage);
				break;
			}
			else
			{
				cout << "\nIncorrect input(s). Try again!\n";
				cout << "Enter your age: ";
			}
	}
	cout << "Enter login (1 - 30 symbols): \n";
	cin >> addclients[number].login;
	CLEARBUF
		cout << "Enter password(1 - 20 symbols): \n";
	cin >> addclients[number].password;
	CLEARBUF
		cout << "Enter phone (format: 8 numbers)  \n";
	string lv{ "+371" };
	while (true)
	{
		cin >> tnum;
		CLEARBUF
			if (isvalid_data(tnum, R"re(\d{8})re"))
			{
				lv += tnum;
				strcpy_s(addclients[number].yphone, lv.c_str());
				break;
			}
			else
			{

				cout << "\nIncorrect input(s). Try again!\n";
				cout << "Enter your LV phone number (e.g 11111111): ";
			}
	}
	cout << "Enter e-mail (in format ****@gmail.com) \n";
	while (true)
	{
		cin >> tmail;
		CLEARBUF
			if (isvalid_data(tmail, R"re(^[\w-.]+@([\w-]+.)+[\w-]{2,4}$)re"))
			{
				strcpy_s(addclients[number].ygmail, tmail.c_str());
				break;
			}
			else
			{
				cout << "\nIncorrect input(s). Try again!\n";
				cout << "Enter your e-mail: ";
			}
	}

	number++;

	WriteIn(addclients);
	return addclients;
};

vector<User> DeleteAccount(vector<User>& addclients, unsigned int& id, bool& deleted)

{
	cout << "Enter password\n";
	string delPas;
	cin.ignore();
	getline(cin, delPas);
	char delPass[30] = "";
	if (delPas.size() > 30) {
		cout << "Too many characters\n";
	}
	else {
		for (unsigned int i = 0; i < delPas.size(); i++)
		{
			delPass[i] = delPas.at(i);
		}

		if (strcmp(addclients.at(id).password, delPass) == 0) {
			addclients.erase(addclients.begin() + id);
			deleted = true;
			cout << "Successfully deleted account!\n";
			WriteIn(addclients);
		}

		if (deleted == false) {
			cout << "Account not found\n";
		}
	}
	return addclients;
}

void ShowProf(vector<User>& addclients, unsigned int& id, bool& deleted) {
	char choose;
	char del;

	ReadIn(addclients);
	cout << "Name: " << addclients[id].name << endl
		<< "Surname: " << addclients[id].surname << endl
		<< "Age: " << addclients[id].age << " years old" << endl
		<< "Your login: " << addclients[id].login << endl
		<< "Your phone: " << addclients[id].yphone << endl
		<< "Your e-mail: " << addclients[id].ygmail << endl;

	cout << "You owe the hotel: " << addclients[id].priceForHot << " $" << endl;
	cout << "You owe the restaurant: " << addclients[id].priceForRest << " $" << endl;
	cout << "In general you have to pay: " << addclients[id].priceForRest + addclients[id].priceForHot << " $" << endl;
	cout << "If you want to pay bill,press y/Y " << endl;
	cin >> choose;
	if ((choose == 'Y') || (choose == 'y')) {

		if (addclients[id].priceForHot != 0 || addclients[id].priceForRest != 0) {
			cout << "Thank you, your account has been paid" << endl;
			addclients[id].priceForHot = 0;
			addclients[id].priceForRest = 0;
		}
		else {
			cout << "You don't owe anything" << endl;
		}
	}
	cout << "If you want to delete accaunt, press F: " << endl;
	cin >> del;
	if ((del == 'F') || (del == 'f')) {
		DeleteAccount(addclients, id, deleted);
	}

	WriteIn(addclients);

}

int LogIn(vector<User>& addclients, unsigned int& id, bool& enter) {
	ReadIn(addclients);
	string wlogin;
	string ylogg;
	string ypass;
	unsigned int i = 0;
	cout << "Enter your login \n ";
	getline(cin, ylogg);

	for (i; i < addclients.size(); i++) {

		if (addclients[i].login == ylogg) {
			cout << "Enter your password" << endl;

			getline(cin, ypass);
			if (addclients[i].password == ypass) {
				cout << "Entrance success" << endl;
				id = i;
				i = INT_MAX;
				enter = true;
			}
			else {

				cout << "Invalid login or password,please try again" << endl;
				i = INT_MAX;
			}

		}

	}
	for (i = 0; i < addclients.size(); i++) {
		if (addclients[i].login == ylogg) {
			ylogg = wlogin;
		}
	}
	if (wlogin != ylogg) {
		cout << "Enter your password" << endl;

		getline(cin, ypass);
		cout << "Invalid login or password,please try again" << endl;
	}
	return id;
}

void roomChoose(vector<Offers>rooms, vector<User>& addclients, unsigned int roomId, unsigned int id) {
	unsigned int tempint = 0;
	for (const auto& i : addclients) {
		if (string(i.room) == string(rooms[roomId].edition)) {
			tempint++;

		}
	}

	if (rooms[roomId].quantity > tempint) {
		string temp;
		char tempCh[50] = "";
		temp = rooms[roomId].edition;

		for (unsigned int i = 0; i < temp.size(); i++)
		{
			tempCh[i] = temp.at(i);
		}
		strcpy_s(addclients.at(id).room, 50, tempCh);

		cout << "For how many nights ?" << endl;
		string tage;
		while (true)
		{
			cin >> tage;
			CLEARBUF
				if (isvalid_data(tage, R"re(\d{1,2})re"))
				{
					addclients[id].nights = (short)stoi(tage);
					break;
				}
				else
				{
					cout << "\nIncorrect input(s). Try again!\n";
					cout << "For how many nights ?" << endl;
				}
		}

	}
	else {
		cout << "There are no rooms of this type left" << endl;
	}
	WriteIn(addclients);

}

