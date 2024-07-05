#include "menu.h"

using namespace std;

void welcome_menu() {
	cout << "|----------------------------|\n"
		<< "|  Welcome to HotelTempest   |\n"
		<< "|----------------------------|\n"
		<< "| 1 - Reserve a hotel room   |\n"
		<< "|----------------------------|\n"
		<< "| 2 - Book a table           |\n"
		<< "|----------------------------|\n"
		<< "| 3 - Your profile           |\n"
		<< "|----------------------------|\n"
		<< "| 4 - New acc. registration  |\n"
		<< "|----------------------------|\n"
		<< "| 5 - Log In                 |\n"
		<< "|----------------------------|\n"
		<< "| 6 - Log Out                |\n"
		<< "|----------------------------|\n"
		<< "| 7 - Quit                   |\n"
		<< "|----------------------------|\n"; ;

}

void Filtering() {
	cout << "+---+----------------------------------------+ \n"
		<< "| A |   Filter by first letter of dish name  | \n"
		<< "+---+----------------------------------------+ \n"
		<< "| P | Filter by first letter of dish type    | \n"
		<< "+---+----------------------------------------+ \n"
		<< "| H |         Filter by price                | \n"
		<< "+---+----------------------------------------+ \n"
		<< "| Q |      I dont need filtering             | \n"
		<< "+---+----------------------------------------+ \n";
}



void Registr() {

	cout << "|------------------------------|\n"
		<< "| 1 - Log in                   |\n"
		<< "|------------------------------|\n"
		<< "| 2 - New acc. registration    |\n"
		<< "|------------------------------|\n"
		<< "| 3 - Quit                     |\n"
		<< "|------------------------------|\n";

}

void restaurantintro(double& restOrder) {
	cout << "1 - Salads and appetizers                \n"
		<< "2 - Main dishes                          \n"
		<< "3 - Sauces and side dishes               \n"
		<< "4 - Desserts                             \n"
		<< "5 - Wine map                             \n"
		<< "6 - Drinks and cocktails                 \n"
		<< "7 - Quit restaurant and finish order     \n"
		<< "8 - See all                              \n"
		<< "Your order price: " << restOrder << "    \n";
}

void restaurant1(double& restOrder) {
	cout << "1 - Augplant rolls with assorted fillings(3euro)                   \n"
		<< "2 - Bell pepper rolls with cheese filling and romesco souce(2euro) \n"
		<< "3 - Olivier with cold smoked salamon(3euro)                        \n"
		<< "4 - Chicken stasivi(4euro)                                         \n"
		<< "5 - Herring under a fur coat(2.5euro)                              \n"
		<< "6 - Greek salad(5euro)                                             \n"
		<< "7 - Cancel last order                                              \n"
		<< "8 - Quit restaurant                                                \n"
		<< "Your order price: " << restOrder << "    \n";
}

void restaurant2(double& restOrder) {
	cout << "1 - Meat cutlets in bavet sauce with mashed potatoes(11euro)  \n"
		<< "2 - Asian style lamb ribs(10euro)                             \n"
		<< "3 - French fries(4.5euro)                                     \n"
		<< "4 - Udon with chicken and vegetables(8euro)                   \n"
		<< "5 - Uzbek pilaf(7euro)                                        \n"
		<< "6 - Chicken cutlets with french fries(12euro)                 \n"
		<< "7 - Cancel last order                                         \n"
		<< "8 - Quit restaurant                                           \n"
		<< "Your order price: " << restOrder << "    \n";
}

void restaurant3(double& restOrder) {
	cout << "1 - Potato idaho(0.5euro)  \n"
		<< "2 - Ketchup(0.5euro)       \n"
		<< "3 - Sour cream(0.3euro)    \n"
		<< "4 - Mayonnaise(0.5euro)    \n"
		<< "5 - Mustard(0.3euro)       \n"
		<< "6 - Garlic sauce(1euro)    \n"
		<< "7 - Cancel last order      \n"
		<< "8 - Quit restaurant        \n"
		<< "Your order price: " << restOrder << "    \n";
}

void restaurant4(double& restOrder) {
	cout << "1 - Pistachio roll(5euro)                    \n"
		<< "2 - Bakhlava for tea(4euro)                  \n"
		<< "3 - Cheesecakewith peach and passion(4euro)  \n"
		<< "4 - Cake with condensed milk(7euro)          \n"
		<< "5 - Cancel last order                        \n"
		<< "6 - Quit restaurant                          \n"
		<< "Your order price: " << restOrder << "    \n";
}

void restaurant5(double& restOrder) {
	cout << "1 - Venezia Giulia Bianco 2017(38euro)      \n"
		<< "2 - Gavi DOCG NV(21euro)                    \n"
		<< "3 - Fiano di Avellino D.O.C.G. 2020(19euro) \n"
		<< "4 - Brut Nature NV(71euro)                  \n"
		<< "5 - Moelleux 2009(39euro)                   \n"
		<< "6 - Cancel last order                       \n"
		<< "7 - Quit restaurant                         \n"
		<< "Your order price: " << restOrder << "    \n";
}

void restaurant6(double& restOrder) {
	cout << "1 - Water250ml(2euro)           \n"
		<< "2 - Peach juice250ml(2.5euro)   \n"
		<< "3 - Tomato juice250ml(2.5euro)  \n"
		<< "4 - Cola250ml(2euro)            \n"
		<< "5 - Cancel lasr order           \n"
		<< "6 - Quit restaurant             \n"
		<< "Your order price: " << restOrder << "    \n";
}