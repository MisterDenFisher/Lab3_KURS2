#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Library {
	
	char* title;
	char* author;
	float price;

	void AddBook(Library*&);
	void DeleteBook(Library*&);
	void ChangePrice(Library*&);

	~Library();
	Library(const char* _title = "XXXXX", const char* _author = "И.И.Иванов", float _price = 0);
	Library&operator=(const Library& other);
	Library(const Library&);

public:
	static int number_of_book;

	void InfoLibrary(Library*);

	friend Library* CreateLibrary();
	friend void Operation(Library*&, int);
};

Library* CreateLibrary();
void Operation(Library*&, int);

int InputInt();
float InputFloat();
void printMenu();
