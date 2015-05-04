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
#include "2-4_Tree.h"
#include "Dictionary.h"

using namespace std;

int main()
{
	ofstream updatefile;
	int size = 41;
	ifstream file;

Rehash:
	if (size == NULL)
	{
		cout << "Enter prime number size of dictionary." << endl;
		cin >> size;
	}
	Dictionary Libraryrecord(size);
	file.open("input.txt");
	while (!file.eof())
	{
		book B;
		file >> B.key >> B.book_title >> B.author1 >> B.author2 >> B.author3 >> B.publisher >> B.price >> B.number_of_books;
		int Rehash;
		Rehash = Libraryrecord.Dictionaryinsert(B);
		if (Rehash == -1)
		{
			file.close();
			size = NULL;
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
			cin >> B.key >> B.book_title >> B.author1 >> B.author2 >> B.author3 >> B.publisher >> B.price >> B.number_of_books;
			int Rehash;
			Rehash = Libraryrecord.Dictionaryinsert(B);
			if (Rehash == -1)
			{
				size = NULL;
				goto Rehash;
			}
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

	if (Libraryrecord.dictionary == 'h' && Libraryrecord.collision != 'c')
	{
		updatefile.open("input.txt");
		for (int i = 0; i < size; i++)
		{
			char a = ' ';
			char b = '\n';
			if (Libraryrecord.Library_p->find(i))
			{
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
	}
	if (Libraryrecord.dictionary == 'h' && Libraryrecord.collision == 'c')
	{
		updatefile.open("input.txt");
		for (int i = 0; i < size; i++)
		{
			Libraryrecord.Librarychain_p->updatefile(i);
		}
		updatefile.close();
	}
	if (Libraryrecord.dictionary != 'h')
	{
		updatefile.open("input.txt");
		if (Libraryrecord.dictionary == 'b')
		{
			Libraryrecord.LibraryBST->updatefile(Libraryrecord.LibraryBST->root);
		}
		if (Libraryrecord.dictionary == 'a')
		{
			Libraryrecord.LibraryAVL->updatefile(Libraryrecord.LibraryAVL->root);
		}
		updatefile.close();
	}
	return 0;
}