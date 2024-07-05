#include<iostream>
#include<vector>
#include<cmath>
#include<regex>
#include<fstream>
#include<limits>
#include<string>
#include<algorithm>
#include "Offers.h"
#include "User.h"
#include "Meals.h"
#include "menu.h"

#define CLEARBUF   cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');

using namespace std;


int main() {
	size_t number = 0;
	unsigned int id = 0;
	bool enter = false;
	unsigned int roomId{};
	double costOfRoomOrder{};
	int RestaurantOrder{};
	double restOrder = 0;
	bool deleted = false;

	vector<User>client;
	vector<string> restaurant;
	vector<Offers>roomAdd;
	vector<Meals>SmtToEat;
	ReadInOffer(roomAdd);
	ReadIn(client);
	ReadInFood(SmtToEat);


	char i = 'g';
	char yORn = 'Z';
	while (i != '7') {
		char b = 'g';
		char c = 'f';
		enter == false;
		welcome_menu();
		cin >> i;
		system("CLS");
		CLEARBUF
			switch (i) {
			case '1':

				while (b != 'c') {
					bookroom(roomAdd, client);
					cin >> b;
					CLEARBUF
						switch (b) {
						case 'l': case 'L':
							yORn = 'Z';
							system("CLS");
							cout << "All inclusive, beautiful view from the window, spacious, and modern design" << endl;
							cout << "If you want to sign this type of a contract press Y,if not enter any other letter" << endl;
							cin >> yORn;
							CLEARBUF
								if ((yORn == 'Y') || (yORn == 'y')) {
									c = 'f';
									while (c != '3') {
										system("CLS");
										if (enter == true) {
											roomId = 0;
											roomChoose(roomAdd, client, roomId, id);
											costOfRoomOrder = client[id].nights * roomAdd[roomId].price;
											client[id].priceForHot = costOfRoomOrder;
											cout << "You ordered : " << client[id].room << endl;
											cout << "for " << client[id].nights << " nights" << endl;
											cout << "It will cost you: " << costOfRoomOrder << endl;
											cout << "But you can change it ,if you want to ." << endl << endl;
											WriteIn(client);
											break;
										}
										else {
											Registr();
											cin >> c;
											CLEARBUF
												switch (c) {
												case '1': {
													LogIn(client, id, enter);
													if (enter == true) {
														roomId = 0;
														roomChoose(roomAdd, client, roomId, id);
														costOfRoomOrder = client[id].nights * roomAdd[roomId].price;
														client[id].priceForHot = costOfRoomOrder;
														cout << "You ordered : " << client[id].room << endl;
														cout << "for " << client[id].nights << " nights" << endl;
														cout << "It will cost you: " << costOfRoomOrder << endl;
														cout << "But you can change it ,if you want to ." << endl << endl;
														WriteIn(client);

														for (const auto& i : client) {
															cout << i.name << " / "
																<< i.surname << " / "
																<< i.room << endl;
														}
													}
													c = '3';
													break;
												}
												case'2': {
													client = Registration(client, number);
													break;
												}
												case '3': {

													break;
												}
												default: {
													cout << "Please enter one of shown numbers \n";
												}
													   break;
												}
										}
									}

								}
							break;
						case 'e': case 'E':
							yORn = 'Z';
							system("CLS");
							cout << "Good view from the window, electronic devices not included, space for two people" << endl;
							cout << "If you want to sign this type of a contract press Y,if not enter any other letter" << endl;
							cin >> yORn;
							CLEARBUF
								if ((yORn == 'Y') || (yORn == 'y')) {
									c = 'f';
									while (c != '3') {
										system("CLS");
										if (enter == true) {
											roomId = 1;
											roomChoose(roomAdd, client, roomId, id);
											costOfRoomOrder = client[id].nights * roomAdd[roomId].price;
											client[id].priceForHot = costOfRoomOrder;
											cout << "You ordered : " << client[id].room << endl;
											cout << "for " << client[id].nights << " nights" << endl;
											cout << "It will cost you: " << costOfRoomOrder << endl;
											cout << "But you can change it ,if you want to ." << endl << endl;
											WriteIn(client);
											break;
										}
										else {
											Registr();
											cin >> c;
											CLEARBUF
												switch (c) {
												case '1': {
													LogIn(client, id, enter);
													if (enter == true) {
														roomId = 1;
														roomChoose(roomAdd, client, roomId, id);
														costOfRoomOrder = client[id].nights * roomAdd[roomId].price;
														client[id].priceForHot = costOfRoomOrder;
														cout << "You ordered : " << client[id].room << endl;
														cout << "for " << client[id].nights << " nights" << endl;
														cout << "It will cost you: " << costOfRoomOrder << endl;
														cout << "But you can change it ,if you want to ." << endl << endl;
														WriteIn(client);
													}
													c = '3';
													break;
												}
												case'2': {
													client = Registration(client, number);
													break;
												}
												case '3': {
													b = 'c';
													break;
												}
												default: {
													cout << "Please enter one of shown numbers \n";
												}
													   break;
												}
										}
									}
								}
							break;
						case 's': case 'S':
							yORn = 'Z';
							system("CLS");
							cout << "Almost like a suite, but from electrical equipment there is only a microwave and a hair dryer" << endl;
							cout << "If you want to sign this type of a contract press Y,if not enter any other letter" << endl;
							cin >> yORn;
							CLEARBUF
								if ((yORn == 'Y') || (yORn == 'y')) {
									c = 'f';
									while (c != '3') {
										system("CLS");
										if (enter == true) {
											roomId = 2;
											roomChoose(roomAdd, client, roomId, id);
											costOfRoomOrder = client[id].nights * roomAdd[roomId].price;
											client[id].priceForHot = costOfRoomOrder;
											cout << "You ordered : " << client[id].room << endl;
											cout << "for " << client[id].nights << " nights" << endl;
											cout << "It will cost you: " << costOfRoomOrder << endl;
											cout << "But you can change it ,if you want to ." << endl << endl;
											WriteIn(client);
											break;
										}
										else {
											Registr();
											cin >> c;
											CLEARBUF
												switch (c) {
												case '1': {
													LogIn(client, id, enter);
													if (enter == true) {
														roomId = 2;
														roomChoose(roomAdd, client, roomId, id);
														costOfRoomOrder = client[id].nights * roomAdd[roomId].price;
														client[id].priceForHot = costOfRoomOrder;
														cout << "You ordered : " << client[id].room << endl;
														cout << "for " << client[id].nights << " nights" << endl;
														cout << "It will cost you: " << costOfRoomOrder << endl;
														cout << "But you can change it ,if you want to ." << endl << endl;
														WriteIn(client);
													}
													c = '3';
													break;
												}
												case'2': {
													client = Registration(client, number);
													break;
												}
												case '3': {
													b = 'c';
													break;
												}
												default: {
													cout << "Please enter one of shown numbers \n";
												}
													   break;
												}
										}
									}
								}
							break;
						case 'o': case 'O':
							yORn = 'Z';
							system("CLS");
							cout << "Breakfast included, fairly spacious room, multiple beds" << endl;
							cout << "If you want to sign this type of a contract press Y,if not enter any other letter" << endl;
							cin >> yORn;
							CLEARBUF
								if ((yORn == 'Y') || (yORn == 'y')) {
									c = 'f';
									while (c != '3') {
										system("CLS");
										if (enter == true) {
											roomId = 3;
											roomChoose(roomAdd, client, roomId, id);
											costOfRoomOrder = client[id].nights * roomAdd[roomId].price;
											client[id].priceForHot = costOfRoomOrder;
											cout << "You ordered : " << client[id].room << endl;
											cout << "for " << client[id].nights << " nights" << endl;
											cout << "It will cost you: " << costOfRoomOrder << endl;
											cout << "But you can change it ,if you want to ." << endl << endl;
											WriteIn(client);
											break;
										}
										else {
											Registr();
											cin >> c;
											CLEARBUF
												switch (c) {
												case '1': {
													LogIn(client, id, enter);
													if (enter == true) {
														roomId = 0;
														roomChoose(roomAdd, client, roomId, id);
														costOfRoomOrder = client[id].nights * roomAdd[roomId].price;
														client[id].priceForHot = costOfRoomOrder;
														cout << "You ordered : " << client[id].room << endl;
														cout << "for " << client[id].nights << " nights" << endl;
														cout << "It will cost you: " << costOfRoomOrder << endl;
														cout << "But you can change it ,if you want to ." << endl << endl;
														WriteIn(client);
													}
													c = '3';
													break;
												}
												case'2': {
													client = Registration(client, number);
													break;
												}
												case '3': {
													b = 'c';
													break;
												}
												default: {
													cout << "Please enter one of shown numbers \n";
												}
													   break;
												}
										}
									}
								}
							break;
						case 't': case 'T':
							system("CLS");
							cout << "Three beds or more on request, breakfast is also included, there are many towels for the whole family and two windows" << endl;
							cout << "If you want to sign this type of a contract press Y,if not enter any other letter" << endl;
							cin >> yORn;
							CLEARBUF
								if ((yORn == 'Y') || (yORn == 'y')) {
									c = 'f';
									while (c != '3') {
										system("CLS");
										if (enter == true) {
											roomId = 4;
											roomChoose(roomAdd, client, roomId, id);
											costOfRoomOrder = client[id].nights * roomAdd[roomId].price;
											client[id].priceForHot = costOfRoomOrder;
											cout << "You ordered : " << client[id].room << endl;
											cout << "for " << client[id].nights << " nights" << endl;
											cout << "It will cost you: " << costOfRoomOrder << endl;
											cout << "But you can change it ,if you want to ." << endl << endl;
											break;
										}
										else {
											Registr();
											cin >> c;
											CLEARBUF
												switch (c) {
												case '1': {
													LogIn(client, id, enter);
													if (enter == true) {
														roomId = 4;
														roomChoose(roomAdd, client, roomId, id);
														costOfRoomOrder = client[id].nights * roomAdd[roomId].price;
														client[id].priceForHot = costOfRoomOrder;
														cout << "You ordered : " << client[id].room << endl;
														cout << "for " << client[id].nights << " nights" << endl;
														cout << "It will cost you: " << costOfRoomOrder << endl;
														cout << "But you can change it ,if you want to ." << endl << endl;
													}
													c = '3';
													break;
												}
												case'2': {
													client = Registration(client, number);
													break;
												}
												case '3': {
													b = 'c';
													break;
												}
												default: {
													cout << "Please enter one of shown numbers \n";
												}
													   break;
												}
										}
									}
								}
							break;
						case 'c': case 'C':
							break;
						}
				}
				break;
			case'2':
				c = 'f';
				while (c != '3') {
					system("CLS");
					if (enter == true) {
						restOrder = client[id].priceForRest;
						while (c != '7') {
							char d = 'f';
							char v = 'z';
							char z = 'l';
							char n = 'f';
							char g = 'f';
							char x = 'f';
							restaurantintro(restOrder);
							cin >> c;
							switch (c) {
							case '1':
								while (d != '8' && d != '7') {
									restaurant1(restOrder);
									cin >> d;
									switch (d) {
									case '1':
										restaurant.push_back(SmtToEat[0].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[0].price;
										break;
									case '2':
										restaurant.push_back(SmtToEat[1].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[1].price;
										break;
									case '3':
										restaurant.push_back(SmtToEat[2].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[2].price;
										break;
									case '4':
										restaurant.push_back(SmtToEat[3].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[3].price;
										break;
									case '5':
										restaurant.push_back(SmtToEat[4].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[4].price;
										break;
									case '6':
										restaurant.push_back(SmtToEat[5].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[5].price;
										break;
									case '7':
										cout << "Printing out clients \n\n";
										for (const auto& i : restaurant) {
											cout << i << "/" << endl;
										}
										break;
									case '8':
										c = '7';
										break;
									default:
										cout << "Please eneter one of shown numbers \n";
									}
									RestaurantOrder++;
									break;
								}
								break;
							case '2':

								while (v != '8' && v != '7') {
									restaurant2(restOrder);
									cin >> v;
									switch (v) {
									case '1':
										restaurant.push_back(SmtToEat[6].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[6].price;
										break;
									case '2':
										restaurant.push_back(SmtToEat[7].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[7].price;
										break;
									case '3':
										restaurant.push_back(SmtToEat[8].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[8].price;
										break;
									case '4':
										restaurant.push_back(SmtToEat[9].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[9].price;
										break;
									case '5':
										restaurant.push_back(SmtToEat[10].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[10].price;
										break;
									case '6':
										restaurant.push_back(SmtToEat[11].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[11].price;
										break;
									case '7':
										break;
									case '8':
										c = '7';
										break;
									default:
										cout << "Please eneter one of shown numbers \n";
									}
									RestaurantOrder++;
									break;
								}
								break;
							case '3':

								while (z != '8' && z != '7') {
									restaurant3(restOrder);
									cin >> z;
									switch (z) {
									case '1':
										restaurant.push_back(SmtToEat[12].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[12].price;
										break;
									case '2':
										restaurant.push_back(SmtToEat[13].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[13].price;
										break;
									case '3':
										restaurant.push_back(SmtToEat[14].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[14].price;
										break;
									case '4':
										restaurant.push_back(SmtToEat[15].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[15].price;
										break;
									case '5':
										restaurant.push_back(SmtToEat[16].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[16].price;
										break;
									case '6':
										restaurant.push_back(SmtToEat[17].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[17].price;
										break;
									case '7':
										break;
									case '8':
										c = '7';
										break;
									default:
										cout << "Please eneter one of shown numbers \n";
									}
									RestaurantOrder++;
									break;
								}

								break;
							case '4':

								while (n != '6' && n != '5') {
									restaurant4(restOrder);
									cin >> n;
									switch (n) {
									case '1':
										restaurant.push_back(SmtToEat[18].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[18].price;
										break;
									case '2':
										restaurant.push_back(SmtToEat[19].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[19].price;
										break;
									case '3':
										restaurant.push_back(SmtToEat[20].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[20].price;
										break;
									case '4':
										restaurant.push_back(SmtToEat[21].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[21].price;
										break;
									case '5':
										break;
									case '6':
										c = '7';
										break;
									default:
										cout << "Please eneter one of shown numbers \n";
									}
									RestaurantOrder++;
									break;
								}

								break;
							case '5':

								while (g != '7' && g != '6') {
									restaurant5(restOrder);
									cin >> g;
									switch (g) {
									case '1':
										restaurant.push_back(SmtToEat[22].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[22].price;
										break;
									case '2':
										restaurant.push_back(SmtToEat[23].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[23].price;
										break;
									case '3':
										restaurant.push_back(SmtToEat[24].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[24].price;
										break;
									case '4':
										restaurant.push_back(SmtToEat[25].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[25].price;
										break;
									case '5':
										restaurant.push_back(SmtToEat[26].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[26].price;
										break;
									case '6':
										break;
									case '7':
										c = '7';
										break;
									default:
										cout << "Please eneter one of shown numbers \n";
									}
									RestaurantOrder++;
									break;
								}

								break;
							case '6':

								while (x != '6' && x != '5') {
									restaurant6(restOrder);
									cin >> x;
									switch (x) {
									case '1':
										restaurant.push_back(SmtToEat[27].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[27].price;
										break;
									case '2':
										restaurant.push_back(SmtToEat[28].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[28].price;
										break;
									case '3':
										restaurant.push_back(SmtToEat[29].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[29].price;
										break;
									case '4':
										restaurant.push_back(SmtToEat[30].meal);
										cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
										restOrder += SmtToEat[30].price;
										break;
									case '5':
										break;
									case '6':
										c = '7';
										break;
									default:
										cout << "Please eneter one of shown numbers \n";
									}
									RestaurantOrder++;
									break;
								}

								break;
							case '7':
								cout << "Your order is:" << endl;
								for (unsigned int i = 0; i < restaurant.size(); i++)
								{
									cout << i + 1 << ". " << restaurant.at(i) << endl;
								}

								cout << "Please pay:" << restOrder << " euros.Your bill will be on your account." << endl;
								client[id].priceForRest = restOrder;
								cout << endl;
								WriteIn(client);
								c = '7';
								break;
							case '8':
								search(SmtToEat);
								break;
							default:
								cout << "Please eneter one of shown numbers \n";
							}
						}
						WriteIn(client);
						break;
					}
					else {
						Registr();
						cin >> c;
						CLEARBUF
							switch (c) {
							case '1': {
								LogIn(client, id, enter);
								if (enter == true) {
									restOrder = client[id].priceForRest;
									cout << client[id].priceForRest;
									while (c != '7') {
										char d = 'f';
										char v = 'z';
										char z = 'l';
										char n = 'f';
										char g = 'f';
										char x = 'f';
										restaurantintro(restOrder);
										cin >> c;
										switch (c) {
										case '1':
											while (d != '8' && d != '7') {
												restaurant1(restOrder);
												cin >> d;
												switch (d) {
												case '1':
													restaurant.push_back(SmtToEat[0].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[0].price;
													break;
												case '2':
													restaurant.push_back(SmtToEat[1].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[1].price;
													break;
												case '3':
													restaurant.push_back(SmtToEat[2].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[2].price;
													break;
												case '4':
													restaurant.push_back(SmtToEat[3].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[3].price;
													break;
												case '5':
													restaurant.push_back(SmtToEat[4].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[4].price;
													break;
												case '6':
													restaurant.push_back(SmtToEat[5].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[5].price;
													break;
												case '7':
													cout << "Printing out clients \n\n";
													for (const auto& i : restaurant) {
														cout << i << "/" << endl;
													}
													break;
												case '8':
													c = '7';
													break;
												default:
													cout << "Please eneter one of shown numbers \n";
												}
												RestaurantOrder++;
												break;
											}
											break;
										case '2':

											while (v != '8' && v != '7') {
												restaurant2(restOrder);
												cin >> v;
												switch (v) {
												case '1':
													restaurant.push_back(SmtToEat[6].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[6].price;
													break;
												case '2':
													restaurant.push_back(SmtToEat[7].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[7].price;
													break;
												case '3':
													restaurant.push_back(SmtToEat[8].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[8].price;
													break;
												case '4':
													restaurant.push_back(SmtToEat[9].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[9].price;
													break;
												case '5':
													restaurant.push_back(SmtToEat[10].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[10].price;
													break;
												case '6':
													restaurant.push_back(SmtToEat[11].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[11].price;
													break;
												case '7':
													break;
												case '8':
													c = '7';
													break;
												default:
													cout << "Please eneter one of shown numbers \n";
												}
												RestaurantOrder++;
												break;
											}
											break;
										case '3':

											while (z != '8' && z != '7') {
												restaurant3(restOrder);
												cin >> z;
												switch (z) {
												case '1':
													restaurant.push_back(SmtToEat[12].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[12].price;
													break;
												case '2':
													restaurant.push_back(SmtToEat[13].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[13].price;
													break;
												case '3':
													restaurant.push_back(SmtToEat[14].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[14].price;
													break;
												case '4':
													restaurant.push_back(SmtToEat[15].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[15].price;
													break;
												case '5':
													restaurant.push_back(SmtToEat[16].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[16].price;
													break;
												case '6':
													restaurant.push_back(SmtToEat[17].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[17].price;
													break;
												case '7':
													break;
												case '8':
													c = '7';
													break;
												default:
													cout << "Please eneter one of shown numbers \n";
												}
												RestaurantOrder++;
												break;
											}

											break;
										case '4':

											while (n != '6' && n != '5') {
												restaurant4(restOrder);
												cin >> n;
												switch (n) {
												case '1':
													restaurant.push_back(SmtToEat[18].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[18].price;
													break;
												case '2':
													restaurant.push_back(SmtToEat[19].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[19].price;
													break;
												case '3':
													restaurant.push_back(SmtToEat[20].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[20].price;
													break;
												case '4':
													restaurant.push_back(SmtToEat[21].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[21].price;
													break;
												case '5':
													break;
												case '6':
													c = '7';
													break;
												default:
													cout << "Please eneter one of shown numbers \n";
												}
												RestaurantOrder++;
												break;
											}

											break;
										case '5':

											while (g != '7' && g != '6') {
												restaurant5(restOrder);
												cin >> g;
												switch (g) {
												case '1':
													restaurant.push_back(SmtToEat[22].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[22].price;
													break;
												case '2':
													restaurant.push_back(SmtToEat[23].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[23].price;
													break;
												case '3':
													restaurant.push_back(SmtToEat[24].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[24].price;
													break;
												case '4':
													restaurant.push_back(SmtToEat[25].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[25].price;
													break;
												case '5':
													restaurant.push_back(SmtToEat[26].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[26].price;
													break;
												case '6':
													break;
												case '7':
													c = '7';
													break;
												default:
													cout << "Please eneter one of shown numbers \n";
												}
												RestaurantOrder++;
												break;
											}

											break;
										case '6':

											while (x != '6' && x != '5') {
												restaurant6(restOrder);
												cin >> x;
												switch (x) {
												case '1':
													restaurant.push_back(SmtToEat[27].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[27].price;
													break;
												case '2':
													restaurant.push_back(SmtToEat[28].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[28].price;
													break;
												case '3':
													restaurant.push_back(SmtToEat[29].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[29].price;
													break;
												case '4':
													restaurant.push_back(SmtToEat[30].meal);
													cout << restaurant.at(RestaurantOrder) << " Added to your order \n";
													restOrder += SmtToEat[30].price;
													break;
												case '5':
													break;
												case '6':
													c = '7';
													break;
												default:
													cout << "Please eneter one of shown numbers \n";
												}
												RestaurantOrder++;
												break;
											}

											break;
										case '7':
											cout << "Your order is:" << endl;
											for (unsigned int i = 0; i < restaurant.size(); i++)
											{
												cout << i + 1 << ". " << restaurant.at(i) << endl;
											}

											cout << "Please pay:" << restOrder << " euro's.Your bill will be on your account." << endl;
											client[id].priceForRest = restOrder;
											cout << endl;
											WriteIn(client);
											c = '7';
											break;
										case '8':
											search(SmtToEat);
											break;
										default:
											cout << "Please eneter one of shown numbers \n";
										}
									}
									WriteIn(client);

								}
								c = '3';
								break;
							}
							case'2': {
								client = Registration(client, number);
								break;
							}
							case '3': {

								break;
							}
							default: {
								cout << "Please enter one of shown numbers \n";
							}
								   break;
							}
					}
				}

				break;
			case'3':
				if (enter == false) {
					cout << "At first you need to log in" << endl;
				}
				else {
					ShowProf(client, id, deleted);
					if (deleted == true) {
						enter = false;	
					}
				}
				break;
			case '4':
				client = Registration(client, number);
				break;
			case '5':
				if (enter == true) {
					cout << "You are already on account" << endl;
				}
				else {
					LogIn(client, id, enter);
				}
				break;
			case '6':
				if (enter == true) {
					enter = false;
				}
				else {
					cout << "You are not loged in" << endl;
				}

				break;
			case '7':
				break;
			default:
				cout << "Please eneter one of shown numbers \n";
			}
	}
}