#include "Meals.h"
#define CLEARBUF   cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');

using namespace std;

void WriteInFood(vector<Meals>& foods) {
	ofstream file("Food.bin", ios::binary);
	for (unsigned int i = 0; i < foods.size(); i++) {
		file.write((char*)(&foods[i].type), sizeof(foods[i].type));
		file.write((char*)(&foods[i].meal), sizeof(foods[i].meal));
		file.write((char*)(&foods[i].price), sizeof(foods[i].price));
	}
	file.close();

}

vector<Meals> ReadInFood(vector<Meals>& foods) {
	ifstream file("Food.bin", ios::binary);
	Meals ex;
	foods.clear();
	while (file)
	{
		file.read((char*)(&ex.type), sizeof(ex.type));
		file.read((char*)(&ex.meal), sizeof(ex.meal));
		file.read((char*)(&ex.price), sizeof(ex.price));
		if (!file)
			break;
		foods.push_back(ex);
	}
	file.close();
	return foods;

}


vector<Meals> FoodRegistration(vector<Meals>foods, size_t& number) {

	number = foods.size();
	cout << "Adding new object \n";
	foods.push_back(Meals());
	cout << "Enter type of food\n";
	cin.getline(foods[number].type, 100);
	cout << "Enter name of food\n";
	cin.getline(foods[number].meal, 100);
	cout << "Enter price \n";
	cin >> foods[number].price;
	while (true)
	{
		if (cin.fail())
		{
			cout << "Error: not an integer" << endl;
			cin >> foods[number].price;
		}
		if (!cin.fail())
			break;
	}

	number++;
	WriteInFood(foods);
	return foods;
}

void DeleteFood(vector<Meals>foods)
{
	cout << "Enter password\n";
	string delFood;
	getline(cin, delFood);
	char delFood1[100] = "";
	if (delFood.size() > 100) {
		cout << "Too many characters\n";
	}
	else {
		for (unsigned int i = 0; i < delFood.size(); i++)
		{
			delFood1[i] = delFood.at(i);
		}
		for (int i = 0; i < foods.size(); i++) {

			if (strcmp(foods.at(i).meal, delFood1) == 0) {
				foods.erase(foods.begin() + i);
				cout << "Successfully deleted!\n";
				WriteInFood(foods);



			}
			else {
				cout << "Something went wrong!\n";
			}

		}

	}
}

void search(vector<Meals>& foods) {
	char FilterChoice = 'Z';
	char Filter;
	double FilterAge = 0;
	ReadInFood(foods);

	cout << "All dishes:  \n\n";
	for (const auto& i : foods) {
		cout << i.meal << " / "
			<< i.type << " / "
			<< i.price << endl;
	}
	cout << endl << "Your choise: " << foods.size();
	cout << endl << endl;
	while ((FilterChoice != 'Q') && (FilterChoice != 'q')) {
		Filtering();
		cin >> FilterChoice;
		system("CLS");
		switch (FilterChoice) {
		case 'A': case 'a': {
			cout << "Filter by first letter of dishes names. Enter the letter: " << endl;
			cin >> Filter;
			CLEARBUF
				for (const auto& i : foods) {
					if (Filter == i.meal[0]) {
						cout << i.meal << " / "
							<< i.type << " / "
							<< i.price << endl;
					}
				}
			break;
		}
		case 'P': case 'p': {
			cout << "Filter by first letter of dish type. Enter the letter: " << endl;
			cin >> Filter;
			for (const auto& i : foods) {
				if (Filter == i.type[0]) {
					cout << i.meal << " / "
						<< i.type << " / "
						<< i.price << endl;

				}
			}

			break;
		}
		case 'H': case 'h': {
			cout << "Filter by dish price. Price from low to high(type lowest price from which you want to start): " << endl;
			cin >> FilterAge;
			while (true)
			{
				if (cin.fail())
				{
					CLEARBUF
						cout << "Error: not an integer" << endl;
					cin >> FilterAge;
				}
				if (!cin.fail())
					break;
			}
			for (const auto& i : foods) {
				if (FilterAge <= i.price) {
					sort(foods.begin(), foods.end(), [](const auto& x, const auto& y)
						{
							return x.price > y.price;
						});
					cout << i.meal << " / "
						<< i.type << " / "
						<< i.price << endl;
				}
			}

			break;
		}
		case 'G': case 'g': {
			cout << "Filter by dish price. Price from high to low(type highest price from which you want to start): " << endl;
			cin >> FilterAge;
			while (true)
			{
				if (cin.fail())
				{
					CLEARBUF
						cout << "Error: not an integer" << endl;
					cin >> FilterAge;
				}
				if (!cin.fail())
					break;
			}
			for (const auto& i : foods) {
				if (FilterAge <= i.price) {
					sort(foods.begin(), foods.end(), [](const auto& x, const auto& y)
						{
							return x.price < y.price;
						});
					cout << i.meal << " / "
						<< i.type << " / "
						<< i.price << endl;
				}
			}

			break;
		}

		case 'Q': case 'q': {
			cout << "Exiting \n";
			break;
		}
		default: {
			cout << "Choose a valid type of menu options \n";
			break;
		}

		}
	}
}