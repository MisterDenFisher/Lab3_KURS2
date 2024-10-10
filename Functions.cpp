#include "Header.h"

int InputInt() {
	string input;
	bool flag;
	while (true) {
		flag = true;
		getline(cin, input);
		if (input.length() == 0 || input[0] == ' ') {
			cout << "���� �� ������ ���� ������. ��������� �������: ";
			continue;
		}
		for (int i = 0; i < input.length(); i++)
			if (input[i] < 48 || input[i] > 57) {
				cout << "������������ �������. ��������� �������: ";
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
			cout << "���� �� ������ ���� ������. ��������� �������: ";
			continue;
		}
		for (int i = 0; i < input.length(); i++)
			if (input[i] != '.')
				if (input[i] < 48 || input[i] > 57) {
					cout << "������������ �������. ��������� �������: ";
					flag = false;
					break;
				}
		if (flag) return stof(input);
	}
}


Library* CreateLibrary() {
	Library* library = new Library[10];

	library[0] = Library("1984", "��.������", round((rand() / 17.5 + 300) * 100) / 100);
	library[1] = Library("����� ������������", "������ ��", round((rand() / 17.5 + 300) * 100) / 100);
	library[2] = Library("�������� � �������������", "��.�����", round((rand() / 17.5 + 300) * 100) / 100);
	library[3] = Library("������ � ���������", "�.�.��������", round((rand() / 17.5 + 300) * 100) / 100);
	library[4] = Library("����� � ���", "�.�.�������", round((rand() / 17.5 + 300) * 100) / 100);
	library[5] = Library("������������ � ���������", "�.�.�����������", round((rand() / 17.5 + 300) * 100) / 100);
	library[6] = Library("������ ����������", "�.�.�����������", round((rand() / 17.5 + 300) * 100) / 100);
	library[7] = Library("��� ��� �����������", "�.�.������", round((rand() / 17.5 + 300) * 100) / 100);
	library[8] = Library("���� ��������", "�.�.�������", round((rand() / 17.5 + 300) * 100) / 100);
	library[9] = Library("������������", "�.�����", round((rand() / 17.5 + 300) * 100) / 100);

	return library;
}

void printMenu() {
	cout << "\n����������\n";
	cout << "1. �������� �����\n";
	cout << "2. ������� �����\n";
	cout << "3. �������� ���� �����\n";
	cout << "4. ���������� � ����������\n";
	cout << "5. �����\n";
	cout << "��� �� ������ �������?	";
}

void Operation(Library*& library, int type) {
	if (type == 1)
		library[0].AddBook(library);
	else if (type == 2)
		library[0].DeleteBook(library);
	else
		library[0].ChangePrice(library);
}

