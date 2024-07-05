#pragma once
#include<iostream>
#include<vector>
#include<cmath>
#include<regex>
#include<fstream>
#include<limits>
#include<string>
#include<algorithm>
#include "Offers.h"
#include "menu.h"

class User
{
public:
	char name[50];
	char surname[50];
	int age;
	char login[30];
	char password[20];
	char yphone[20];
	char ygmail[50];
	char room[50];
	int nights;
	double priceForRest;
	double priceForHot;
};

bool isvalid_data(const std::string& data, const std::string& str_re);

void bookroom(std::vector<Offers>& rooms, std::vector<User>& addclients);

void WriteIn(std::vector<User>& addclients);

std::vector<User> ReadIn(std::vector<User>& addclients);

std::vector<User> Registration(std::vector<User>& addclients, size_t& number);

std::vector<User> DeleteAccount(std::vector<User>& addclients, unsigned int& id, bool& deleted);

void ShowProf(std::vector<User>& addclients, unsigned int& id, bool& deleted);

int LogIn(std::vector<User>& addclients, unsigned int& id, bool& enter);

void roomChoose(std::vector<Offers>rooms, std::vector<User>& addclients, unsigned int roomId, unsigned int id);

