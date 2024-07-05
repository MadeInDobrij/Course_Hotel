#include "Offers.h"

using namespace std;

void WriteInOffer(vector<Offers>& rooms) {
	ofstream file("Rooms.bin", ios::binary);
	for (unsigned int i = 0; i < rooms.size(); i++) {
		file.write((char*)(&rooms[i].edition), sizeof(rooms[i].edition));
		file.write((char*)(&rooms[i].price), sizeof(rooms[i].price));
		file.write((char*)(&rooms[i].quantity), sizeof(rooms[i].quantity));
	}
	file.close();

}

vector<Offers> ReadInOffer(vector<Offers>& rooms) {
	ifstream file("Rooms.bin", ios::binary);
	Offers ex;
	rooms.clear();
	while (file)
	{
		file.read((char*)(&ex.edition), sizeof(ex.edition));
		file.read((char*)(&ex.price), sizeof(ex.price));
		file.read((char*)(&ex.quantity), sizeof(ex.quantity));
		if (!file)
			break;
		rooms.push_back(ex);
	}
	file.close();
	return rooms;

}

vector<Offers> OfRegistration(vector<Offers>rooms, size_t& number) {

	number = rooms.size();
	cout << "Adding new object \n";
	rooms.push_back(Offers());
	cout << "Enter variant of room\n";
	cin.ignore();
	cin.getline(rooms[number].edition, 50);
	cout << "Enter price \n";
	cin >> rooms[number].price;
	while (true)
	{
		if (cin.fail())
		{
			cout << "Error: not an integer" << endl;
			cin >> rooms[number].price;
		}
		if (!cin.fail())
			break;
	}
	cout << "Enter quantity \n";
	cin >> rooms[number].quantity;
	while (true)
	{
		if (cin.fail())
		{
			cout << "Error: not an integer" << endl;
			cin >> rooms[number].quantity;
		}
		if (!cin.fail())
			break;
	}
	number++;
	WriteInOffer(rooms);
	return rooms;
}