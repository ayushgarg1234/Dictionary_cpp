#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include "Book.h"
#include "Hash.h"
#include "linearList_Sequential.h"
#include "LinkList.h"
#include "Trees.h"
#include "Dictionary.h"

using namespace std;

int main()
{
	ofstream updatefile;
	int size;
	ifstream file;

Rehash:
	cout << "Enter prime number size of dictionary." << endl;
	cin >> size;
	Dictionary Libraryrecord(size);
	file.open("input.txt");
	while (!file.eof())
	{
		book B;
		char key[20];
		char book_title[20];
		char author1[20];
		char author2[20];
		char author3[20];
		char publisher[20];
		float price;
		int number_of_books;
		file >> key;
		file >> book_title;
		file >> author1;
		file >> author2;
		file >> author3;
		file >> publisher;
		file >> price;
		file >> number_of_books;

		strcpy(B.author1, author1);
		strcpy(B.author2, author2);
		strcpy(B.author3, author3);
		strcpy(B.book_title, book_title);
		B.number_of_books = number_of_books;
		B.price = price;
		strcpy(B.publisher, publisher);
		strcpy(B.key, key);

		int Rehash;
		Rehash = Libraryrecord.Dictionaryinsert(B);
		if (Rehash == -1)
		{
			file.close();
			goto Rehash;
		}
	}
	file.close();
	while (true)
	{
		cout << "What do you want to do insert(i), search(s), delete(d). Enter anything else to exit." << endl;
		char option;
		cin >> option;
		switch (option)
		{
		case 'i':
			book B;
			char key[20];
			char book_title[20];
			char author1[20];
			char author2[20];
			char author3[20];
			char publisher[20];
			float price;
			int number_of_books;
			cin >> key;
			cin >> book_title;
			cin >> author1;
			cin >> author2;
			cin >> author3;
			cin >> publisher;
			cin >> price;
			cin >> number_of_books;

			strcpy(B.author1, author1);
			strcpy(B.author2, author2);
			strcpy(B.author3, author3);
			strcpy(B.book_title, book_title);
			B.number_of_books = number_of_books;
			B.price = price;
			strcpy(B.publisher, publisher);
			strcpy(B.key, key);

			int Rehash;
			Rehash = Libraryrecord.Dictionaryinsert(B);
			if (Rehash == -1)
				goto Rehash;
			
			break;
		case 's':
			Libraryrecord.Dictionarysearch();
			break;
		case 'd':
			Libraryrecord.Dictionarydelete();
			break;
		default:
			;
		}
		if (!(option == 'i' || option == 's' || option == 'd'))
			break;
	}

	updatefile.open("input.txt");
	bool check = false;

	for (int i = 0; i < size; i++)
	{
		char a = ' ';
		char b = '\n';
		if (Libraryrecord.Library_p->find(i))
		{
			check = true;
			updatefile << Libraryrecord.Library_p->element[i].key << a;
			updatefile << Libraryrecord.Library_p->element[i].book_title << a;
			updatefile << Libraryrecord.Library_p->element[i].author1 << a;
			updatefile << Libraryrecord.Library_p->element[i].author2 << a;
			updatefile << Libraryrecord.Library_p->element[i].author3 << a;
			updatefile << Libraryrecord.Library_p->element[i].publisher << a;
			updatefile << Libraryrecord.Library_p->element[i].price << a;
			updatefile << Libraryrecord.Library_p->element[i].number_of_books << b;
		}
	}
	updatefile.close();
	if (check == false)
	{
		for (int i = 0; i < size; i++)
		{
			Libraryrecord.Librarychain_p->updatefile(i);
		}
	}
	system("pause");
	return 0;
}