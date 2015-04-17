using namespace std;

class Dictionary
{
public:
	char dictionary;
	char collision;
	Dictionary(int MaxSize);
	~Dictionary();
	BST* LibraryBST;
	LinkListarray* Librarychain_p;
	LinearList* Library_p;
	int Dictionaryinsert(book B);
	void Dictionarysearch();
	void Dictionarydelete();
	int MaxSize1;
};

Dictionary::Dictionary(int MaxSize)
{

	MaxSize1 = MaxSize;
	int offset;
	cout << "Which method you want to use to implement dictionary? Press 'h' for hashing, 'b' for BST ";
	cin >> dictionary;
	if (dictionary == 'b')
	{
		LibraryBST = new BST();
	}

	else if (dictionary == 'h')
	{
		cout << "Which collision method is to be used? Press 'c' for chaining, 'l' for linear probing, 'd' for double hashing.";
		cin >> collision;
		if (collision == 'c')
		{
			Librarychain_p = new LinkListarray(MaxSize1);
		}
		else if (collision == 'd' || collision == 'l')
		{
			Library_p = new LinearList(MaxSize1);
		}
		else
			cout << "Wrong input" << endl;
	}

	else
		cout << "Wrong input";
}

Dictionary::~Dictionary()
{

}

int Dictionary::Dictionaryinsert(book B)
{
	if (dictionary == 'b')
	{
		LibraryBST->BSTinsert(B);
		return 0;
	}

	if (dictionary == 'h')
	{
		unsigned int hvalue;
		int index;
		hashing Hash;
		switch (collision)
		{
		case 'c':
			hvalue = Hash.hash_code_map(B.key);
			index = Hash.hash_compression_map(hvalue, MaxSize1);
			//cout << hvalue << " " << index << endl;
			//chaining
			int rehash;
			rehash = Librarychain_p->insert(index % MaxSize1, B);
			//cout << Librarychain.element[index % size].Head->element1.key << endl;
			if (rehash == -1)
			{
				return -1;
			}
			break;
		case 'l':

			hvalue = Hash.hash_code_map(B.key);
			index = Hash.hash_compression_map(hvalue, MaxSize1);
			//cout << hvalue << " " << index << " ";
			//linear probing
			while (Library_p->len < MaxSize1)
			{
				if (!Library_p->find(index % MaxSize1))
				{
					//cout << index << endl;
					Library_p->insert(index % MaxSize1, B);
					break;
				}
				else
					index++;
			}
			if (Library_p->len == MaxSize1)
			{
				return -1;
			}
			break;
		case 'd':
			int offset;
			hvalue = Hash.hash_code_map(B.key);
			index = Hash.hash_compression_map(hvalue, MaxSize1);
			offset = Hash.hash_compression_map2(hvalue);
			//cout << hvalue << " " << index << " " << offset << " ";
			//double hashing
			while (Library_p->len < MaxSize1)
			{
				if (!Library_p->find(index % MaxSize1))
				{
					//cout << Library_p->len << endl;
					Library_p->insert(index % MaxSize1, B);
					break;
				}
				else
				{
					index = index + offset;
				}
			}
			if (Library_p->len == MaxSize1)
			{
				cout << "rehashing please enter new size and inputs again." << endl;
				return -1;
			}
			break;
		default:
			;
		}
		return 0;
	}
}

void Dictionary::Dictionarysearch()
{
	if (dictionary == 'b')
	{
		TreeNode* temp;
		cout << endl << "Enter the key to be searched." << endl;
		char keytemp[20];
		cin >> keytemp;
		temp = LibraryBST->BSTsearch(keytemp);
		if (temp != NULL)
			cout << temp->data.key << " " << temp->data.book_title << " " << temp->data.author1 << " " << temp->data.author2 << " " << temp->data.author3 << " " << temp->data.publisher << " " << temp->data.price << " " << temp->data.number_of_books << endl;
	}

	if (dictionary == 'h')
	{
		unsigned int hvalue;
		int index, offset;
		hashing Hash;
		switch (collision)
		{
		case 'c':
			cout << endl << "Enter the key to be searched." << endl;
			char keytemp[20];
			cin >> keytemp;
			hvalue = Hash.hash_code_map(keytemp);
			index = Hash.hash_compression_map(hvalue, MaxSize1);
			int j;
			j = 0;
			//cout << index;
			//cout << Librarychain.element[index].Head->next->element1.key;
			if (Librarychain_p->search(keytemp, index) == 1)
				cout << "Successful search at index " << index << endl;
			else
				cout << "Element not found" << endl;
			break;
		case 'l':
			cout << endl << "Enter the key to be searched." << endl;
			cin >> keytemp;
			hvalue = Hash.hash_code_map(keytemp);
			index = Hash.hash_compression_map(hvalue, MaxSize1);
			j = 0;
			//cout << index;
			while (j != MaxSize1)
			{
				if (!Library_p->find(index % MaxSize1))
				{
					if (Library_p->element[index % MaxSize1].key[1] != 0)
						break;
				}
				else if (!strcmp(Library_p->element[index % MaxSize1].key, keytemp))
				{
					break;
				}

				index++;
				j++;
			}
			if (!Library_p->find(index % MaxSize1))
				cout << "Search failed, element not found." << endl;
			if (!strcmp(Library_p->element[index % MaxSize1].key, keytemp))
				cout << "Search successfull. The index for the element is: " << index % MaxSize1 << endl;
			if (j == MaxSize1)
				cout << "Search failed, element not found." << endl;

			break;
		case 'd':
			cout << endl << "Enter the key to be searched." << endl;
			cin >> keytemp;
			hvalue = Hash.hash_code_map(keytemp);
			index = Hash.hash_compression_map(hvalue, MaxSize1);
			offset = Hash.hash_compression_map2(hvalue);
			j = 0;
			//cout << index;
			while (j != MaxSize1)
			{
				if (!Library_p->find(index % MaxSize1))
				{
					if (Library_p->element[index % MaxSize1].key[1] != 0)
						break;
				}
				else if (!strcmp(Library_p->element[index % MaxSize1].key, keytemp))
				{
					break;
				}

				index = index + offset;
				j++;
			}
			if (!Library_p->find(index % MaxSize1))
				cout << "Search failed, element not found." << endl;
			if (!strcmp(Library_p->element[index % MaxSize1].key, keytemp))
				cout << "Search successfull. The index for the element is: " << index % MaxSize1;
			if (j == MaxSize1)
				cout << "Search failed, element not found." << endl;

			break;
		default:
			;
		}
	}
}

void Dictionary::Dictionarydelete()
{
	if (dictionary == 'b')
	{
		cout << endl << "Enter the key to be deleted." << endl;
		char keytemp[20];
		cin >> keytemp;
		LibraryBST->BSTdelete(keytemp);
	}

	if (dictionary == 'h')
	{
		unsigned int hvalue;
		int index, offset;
		hashing Hash;
		int j;

		switch (collision)
		{
		case 'c':
			cout << endl << "Enter the key to be deleted." << endl;
			char keytemp[20];
			cin >> keytemp;
			hvalue = Hash.hash_code_map(keytemp);
			index = Hash.hash_compression_map(hvalue, MaxSize1);
			j = 0;
			//cout << index;
			if (Librarychain_p->search(keytemp, index) == 1)
			{
				Librarychain_p->deleteElement(index, keytemp);
				cout << "Delete successful at index " << index << endl;
			}
			else
				cout << "Element not found" << endl;

			break;
		case 'l':
			cout << endl << "Enter the key to be deleted." << endl;
			cin >> keytemp;
			hvalue = Hash.hash_code_map(keytemp);
			index = Hash.hash_compression_map(hvalue, MaxSize1);
			j = 0;
			//cout << index;
			while (j != MaxSize1)
			{
				if (!Library_p->find(index % MaxSize1))
				{
					break;
				}
				else if (!strcmp(Library_p->element[index % MaxSize1].key, keytemp))
				{
					break;
				}
				else
					index++;
				j++;
			}
			if (!Library_p->find(index % MaxSize1))
				cout << "Delete failed, element not found." << endl;
			if (!strcmp(Library_p->element[index % MaxSize1].key, keytemp))
			{
				cout << "Delete successfull. The index for the deletion of element is: " << index % MaxSize1 << endl;
				Library_p->deleteElement(index % MaxSize1);
			}
			if (j == MaxSize1)
				cout << "Delete failed, element not found." << endl;

			break;
		case 'd':
			cout << endl << "Enter the key to be deleted." << endl;
			cin >> keytemp;
			hvalue = Hash.hash_code_map(keytemp);
			index = Hash.hash_compression_map(hvalue, MaxSize1);
			offset = Hash.hash_compression_map2(hvalue);
			j = 0;
			cout << index;
			while (j != MaxSize1)
			{
				if (!Library_p->find(index % MaxSize1))
				{
					break;
				}
				else if (!strcmp(Library_p->element[index % MaxSize1].key, keytemp))
				{
					break;
				}
				else
					index = index + offset;
				j++;
			}
			if (!Library_p->find(index % MaxSize1))
				cout << "Delete failed, element not found." << endl;
			if (!strcmp(Library_p->element[index % MaxSize1].key, keytemp))
			{
				cout << "Delete successfull. The index for the deletion of element is: " << index % MaxSize1 << endl;
				Library_p->deleteElement(index % MaxSize1);
			}
			if (j == MaxSize1)
				cout << "Delete failed, element not found." << endl;

			break;
		default:
			;
		}
	}
}

