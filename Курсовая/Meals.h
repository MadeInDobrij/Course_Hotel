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

class Meals
{
	public:
		char type[100];
		char meal[100];
		double price;
};

void WriteInFood(std::vector<Meals>& foods);

std::vector<Meals> ReadInFood(std::vector<Meals>& foods);


std::vector<Meals> FoodRegistration(std::vector<Meals>foods, size_t& number);

void DeleteFood(std::vector<Meals>foods);

void search(std::vector<Meals>& foods);

