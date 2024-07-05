#pragma once
#include<iostream>
#include<vector>
#include<cmath>
#include<regex>
#include<fstream>
#include<limits>
#include<string>
#include<algorithm>
#include "menu.h"

class Offers
{
public:
	char edition[50];
	unsigned int price;
	unsigned int quantity;
};

void WriteInOffer(std::vector<Offers>& rooms);

std::vector<Offers> ReadInOffer(std::vector<Offers>& rooms);

std::vector<Offers> OfRegistration(std::vector<Offers>rooms, size_t& number);



