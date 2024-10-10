#include "Header.h"

int InputInt() {
	string input;
	bool flag;
	while (true) {
		flag = true;
		getline(cin, input);
		if (input.length() == 0 || input[0] == ' ') {
			cout << "Поле не должно быть пустым. Повторите попытку: ";
			continue;
		}
		for (int i = 0; i < input.length(); i++)
			if (input[i] < 48 || input[i] > 57) {
				cout << "Некорректные символы. Повторите попытку: ";
				flag = false;
				break;
			}
		if (flag) return stoi(input);
	}
}

float InputFloat() {
	string input;
	bool flag;
	while (true) {
		flag = true;
		getline(cin, input);
		if (input.length() == 0 || input[0] == ' ') {
			cout << "Поле не должно быть пустым. Повторите попытку: ";
			continue;
		}
		for (int i = 0; i < input.length(); i++)
			if (input[i] != '.')
				if (input[i] < 48 || input[i] > 57) {
					cout << "Некорректные символы. Повторите попытку: ";
					flag = false;
					break;
				}
		if (flag) return stof(input);
	}
}


Library* CreateLibrary() {
	Library* library = new Library[10];

	library[0] = Library("1984", "Дж.Оруэлл", round((rand() / 17.5 + 300) * 100) / 100);
	library[1] = Library("Убить пересмешника", "Харпер Ли", round((rand() / 17.5 + 300) * 100) / 100);
	library[2] = Library("Гордость и предубеждение", "Дж.Остин", round((rand() / 17.5 + 300) * 100) / 100);
	library[3] = Library("Мастер и Маргарита", "М.А.Булгаков", round((rand() / 17.5 + 300) * 100) / 100);
	library[4] = Library("Война и мир", "Л.Н.Толстой", round((rand() / 17.5 + 300) * 100) / 100);
	library[5] = Library("Преступление и наказание", "Ф.М.Достоевский", round((rand() / 17.5 + 300) * 100) / 100);
	library[6] = Library("Братья Карамазовы", "Ф.М.Достоевский", round((rand() / 17.5 + 300) * 100) / 100);
	library[7] = Library("Сто лет одиночества", "Г.Г.Маркес", round((rand() / 17.5 + 300) * 100) / 100);
	library[8] = Library("Анна Каренина", "Л.Н.Толстой", round((rand() / 17.5 + 300) * 100) / 100);
	library[9] = Library("Франкенштейн", "М.Шелли", round((rand() / 17.5 + 300) * 100) / 100);

	return library;
}

void printMenu() {
	cout << "\nБиблиотека\n";
	cout << "1. Добавить книгу\n";
	cout << "2. Удалить книгу\n";
	cout << "3. Поменять цену книги\n";
	cout << "4. Информация о библиотеке\n";
	cout << "5. Выйти\n";
	cout << "Что вы хотите сделать?	";
}

void Operation(Library*& library, int type) {
	if (type == 1)
		library[0].AddBook(library);
	else if (type == 2)
		library[0].DeleteBook(library);
	else
		library[0].ChangePrice(library);
}

