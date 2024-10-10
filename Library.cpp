#include "Header.h"

int Library::number_of_book = 0;

Library& Library::operator=(const Library& other) {
	if (this != &other) {
		delete[] title;
		delete[] author;

		title = new char[strlen(other.title) + 1];
		strcpy(title, other.title);

		author = new char[strlen(other.author) + 1];
		strcpy(author, other.author);

		price = other.price;
	}
	return *this;
}

Library::Library(const Library& other) {
	title = new char[strlen(other.title) + 1];
	strcpy(title, other.title);

	author = new char[strlen(other.author) + 1];
	strcpy(author, other.author);

	price = other.price;

	number_of_book++;
}

Library::Library(const char* _title, const char* _author, float _price) {
	title = new char[strlen(_title) + 1];
	strcpy(title, _title);

	author = new char[strlen(_author) + 1];
	strcpy(author, _author);

	price = _price;

	number_of_book++;
};

Library::~Library() {
	delete[] title;
	delete[] author;

	number_of_book--;
}

void Library::InfoLibrary(Library* library) {
	cout << "\nВсего книг: " << number_of_book << endl;
	for (int i = 0; i < number_of_book; i++)
		printf("%d. '%s' %s\nЦена: %.2f\n", i + 1, library[i].title, library[i].author, library[i].price);
}

void Library::AddBook(Library*& library) {
	int count = number_of_book;
	Library* newLibrary = new Library[count + 1];

	for (int i = 0; i < count; i++)
		newLibrary[i] = library[i];
	
	cout << "\nВведите название книги:	";
	char* _title = new char[30];
	cin.getline(_title, 30);
	
	cout << "Введите автора книги:	";
	char* _author = new char[30];
	cin.getline(_author, 30);
	
	cout << "Введите цену: ";
	float _price = InputFloat();

	newLibrary[count] = Library(_title, _author, _price);
	delete[] library;

	library = newLibrary;
}

void Library::DeleteBook(Library*& library) {
	cout << "\nКакую книгу удалить?[Номер книги]	";
	int numb_book = InputInt();
	if (numb_book > number_of_book || number_of_book < 1) {
		cout << "Такой книги нет!\n";
		return;
	}

	int count = number_of_book;
	Library* newLibrary = new Library[count - 1];

	for (int i = 0; i < numb_book - 1; i++)
		newLibrary[i] = library[i];
	for (int i = numb_book - 1; i < count - 1; i++)
		newLibrary[i] = library[i+1];

	delete[] library;

	library = newLibrary;
}

void Library::ChangePrice(Library*& library) {
	cout << "Цену какой книги вы хотите изменить?[Номер книги]	";
	int numb_book = InputInt();
	if (numb_book > number_of_book || number_of_book < 1) {
		cout << "Такой книги нет!\n";
		return;
	}
	cout << "Какая новая цена книги?	";
	float new_price = InputFloat();

	library[numb_book - 1].price = new_price;
}