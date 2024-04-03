#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

struct Date {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct Record
{
	char name[17];
	char type;
	double price;
	unsigned short minCount;
	struct Date date;
};

struct node {
	Record data;
	struct node* next;
};
struct node* myHead;
int countItem = 0;

void addItem(Record data)
{
	struct node* newItem = new node();
	newItem->data = data;
	if (countItem == 0) {
		newItem->next = NULL;
	}
	else
	{
		newItem->next = myHead;
	}
	myHead = newItem;
	countItem++;
}

void insertItem(int index, Record data) {
	if (not (index >= 0 and index <= countItem and countItem >= 0))
		return;
	if (index == 0) {
		addItem(data);
	}
	else {
		struct node* current = myHead;
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}
		struct node* newItem = new node();
		newItem->data = data;
		newItem->next = current->next;
		current->next = newItem;
		countItem++;
	}
}

void editItem(int index, Record data) {
	if (index >= 0 and index < countItem and countItem>0) {
		struct node* current = myHead;
		for (int i = 0; i < index; i++) {
			current = current->next;
			//cout << "+" << current->data;
		}
		current->data = data;
	}
	else {
		cout << endl << "Ошибка индекс не в диапазоне";
	}
}

void deleteItem(int index) {
	if (index >= 0 and index < countItem and countItem>0) {
		struct node* current = myHead;
		struct node* old;
		if (index == 0) {
			old = myHead;
			myHead = current->next;
			delete old;
			countItem--;
		}
		else {
			int i = 0;
			while (current) {
				if (i == index - 1) {
					old = current->next->next;
					delete current->next;
					current->next = old;
					countItem--;
					break;
				}
				i++;
				current = current->next;
			}
		}
	}
}


void myCentr(string s, int wLine) {

	int w = s.length();
	int delta = (wLine - w) / 2;
	cout << left;
	cout.width(delta); cout << " ";
	cout << s;
	cout.width(delta + 1); cout << " ";

}

void printDate(unsigned short day, unsigned short month, unsigned short year, int wLine) {
	int w = 10;
	int delta = (wLine - w) / 2 - 1;
	cout << left;
	cout.width(delta); cout << " ";
	if (day > 9) {
		cout << day;
	}
	else {
		cout << "0" << day;
	}
	cout << ".";
	if (month > 9) {
		cout << month;
	}
	else {
		cout << "0" << month;
	}
	cout << ".";
	cout << year;
	cout.width(delta); cout << " ";
}

void printWithZero4(int num, int width) {

	if (num < 10) {
		cout << "000" << num;
	}
	if (num > 9 and num < 100) {
		cout.width(width + 1);
		cout << "00" << num;
	}
	if (num > 99 and num < 1000) {
		cout.width(width);
		cout << "0" << num;
	}
	if (num > 999 and num < 10000) {
		cout << num;
	}

}

void printWithSpace4(double num, int width, int spaceCount) {

	if (num < 10) {
		cout.precision(5);
		cout.width(spaceCount + 3); cout.fill(' ');
		cout << " " << left << fixed << num;
	}
	if (num > 9 and num < 100) {
		cout.precision(5);
		cout.width(spaceCount + 2); cout.fill(' ');
		cout << " " << left << fixed << num;
	}
	if (num > 99 and num < 1000) {
		cout.precision(5);
		cout.width(spaceCount + 1); cout.fill(' ');
		cout << " " << left << fixed << num;
	}
	if (num > 999 and num < 10000) {
		cout.precision(5);
		cout.width(spaceCount); cout.fill(' ');
		cout << " " << left << fixed << num;
	}

}

void Draw(struct Record* records, int elementCount) {

	unsigned short width = 95;
	cout << endl;	cout.width(width); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width - 1);  cout << left << "|Прайс-лист"; cout << "|" << endl;
	cout.width(width); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "|Наименование товара ";
	cout << left << "|Тип товара";
	cout << left << "|Цена за 1 шт (грн)";
	cout << left << "|  Минимальное количество  ";
	cout << left << " |     Дата     ";
	cout << "|" << endl;
	cout.width(width); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	for (int i = 0; i < elementCount; i++) {
		cout << left << "|"; cout.width(20); cout << left << records[i].name;
		cout << left << "|"; cout.width(10); cout << left << records[i].type;
		cout << left << "|"; cout.width(16); cout << left;
		printWithSpace4(records[i].price, 16, 8);
		cout << left << "|"; cout.width(27); cout << left << records[i].minCount;
		cout << left << "|";
		printDate(records[i].date.day, records[i].date.month, records[i].date.year, 16);
		cout << "|" << endl;
	}
	cout.width(width); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width - 1);  cout << left << "|Примечание: К – канцтовары, О – оргтехника "; cout << "|" << endl;
	cout.width(width); cout.fill('-'); cout << "-" << endl;
}

void insertMaxRecord(struct Record* table, int* currentElementCount, int maxElementCount) {
	if (*currentElementCount < maxElementCount) {
		*currentElementCount = *currentElementCount + 1;
		table[*currentElementCount - 1] = { "Bruh",'B',999.00000,999,{12,12,9999} };
	}
}

void DrawWithList() {
	unsigned short width = 95;
	cout << endl; cout.width(width); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width-1); cout << left << "|Прайс-лист"; cout << "|"
		<< endl;
	cout.width(width); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "|Наименование товара ";
	cout << left << "|Тип товара";
	cout << left << "|Цена за 1 шт (грн)";
	cout << left << "|  Минимальное количество  ";
	cout << left << " |     Дата     ";
	cout << "|" << endl;
	cout.width(width); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	struct node* current = myHead;
	while (current) {
		cout << left << "|"; cout.width(16); cout << left << current -> data.name;
		cout << left << "|"; cout.width(11); cout << left << current -> data.type;
		cout << left << "|+"; cout.width(10); cout << left << current -> data.price;
		std::cout.precision(2);
		cout << left << "|"; cout.width(27); cout << left << fixed << current -> data.minCount;
		cout << left << "|";
		printDate(current->data.date.day, current->data.date.month, current -> data.date.year, 26);
		cout << "|" << endl;
		current = current->next;
	}
	cout.width(width); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width - 1);  cout << left << "|Примечание: К – канцтовары, О – оргтехника "; cout << "|" << endl;
	cout.width(width); cout.fill('-'); cout << "-" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int maxElementCount = 10;
	int currentElementCount = 3;

	struct Record table[10];
	table[0] = { "Папка", 'К', 4.75000, 4, {03,07,2022} };
	table[1] = { "Бумага", 'К', 13.90000, 10, {03,04,2021} };
	table[2] = { "Калькулятор", 'О', 411.00000, 1, {4,3,2022} };

	Draw(table, currentElementCount);
	insertMaxRecord(table, &currentElementCount, maxElementCount);
	Draw(table, currentElementCount);

	cout << "Практика 3 Динамический список" << endl;
	//system("mspaint");
	addItem(table[0]);
	addItem(table[1]);
	addItem(table[2]);
	DrawWithList();
	struct Record newRecord = { "Скрепка", 'K', 198.00000, 7, {01,02,2024}};
	insertItem(1, newRecord);
	DrawWithList();
	deleteItem(3);	
	DrawWithList();
	struct Record editRecord = { "Скоба", 'К', 196.00000, 20, {01,02,2024} };
	editItem(1, editRecord);
	DrawWithList();

}