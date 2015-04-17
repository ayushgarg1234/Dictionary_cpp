using namespace std;

class Node{
public:

	book element1;
	Node *next;
};

class LinkList{
public:

	Node* Head;
	int length;
	LinkList();
	~LinkList();
	bool search1(char key[20]);
	int insert1(book x, int size);
	void deleteElement1(char key[20]);
	bool Isempty1(LinkList L);
	int lengthreturn(LinkList L);
	void updatefile1();
};

LinkList::LinkList()
{
	Head = new Node;
	Head->element1.key[0] = 0;
	Head->next = NULL;
	length = 0;
}

LinkList::~LinkList()
{

}

int LinkList::insert1(book x, int size)
{
	if (Head->element1.key[0] == 0)
	{
		Head->element1 = x;
	}
	else
	{
		Node* newelement = new Node;
		newelement->element1 = x;
		newelement->next = Head->next;
		Head->next = newelement;
	}
	length++;
	if (length > size / 2)
		return -1;
	return 0;
}

bool LinkList::search1(char key[20])
{
	Node* temp = Head;
	while (temp && strcmp(temp->element1.key, key))
	{
		temp = temp->next;
	}
	if (temp)
		return true;
	return false;
}

void LinkList::deleteElement1(char key[20])
{
	Node* temp = Head;
	Node* previous = Head;
	while (temp && strcmp(temp->element1.key, key))
	{
		previous = temp;
		temp = temp->next;
	}
	if (temp)
	{
		if (temp == Head)
		{
			Head->element1.key[0] = 0;
		}
		previous->next = temp->next;
	}
}

void LinkList::updatefile1()
{
	ofstream file1;
	file1.open("input.txt", std::ios_base::app);
	char a = ' ';
	char b = '\n';
	book tempbook;
	Node* temp = Head;
	while (temp)
	{

		if (Head->element1.key[0] != 0)
		{
			tempbook = temp->element1;
			file1 << tempbook.key << a;
			file1 << tempbook.book_title << a;
			file1 << tempbook.author1 << a;
			file1 << tempbook.author2 << a;
			file1 << tempbook.author3 << a;
			file1 << tempbook.publisher << a;
			file1 << tempbook.price << a;
			file1 << tempbook.number_of_books << b;
		}
		temp = temp->next;
	}

}

bool LinkList::Isempty1(LinkList L)
{
	if (L.Head->element1.key[0] == 0) return true;
	return false;
}

int LinkList::lengthreturn(LinkList L)
{
	return L.length;
}

class LinkListarray{
public:
	int MaxSize;
	int len;
	LinkList *element;
	LinkListarray(int  MaxSize);
	LinkListarray(const LinkListarray& temp);
	~LinkListarray();
	bool isEmpty();
	int  length();
	int  maxSize();
	LinkList returnListElement(int k);
	bool find(int  k);
	int  search(char key[20], int index);
	void deleteElement(int  k, char key[20]);
	int insert(int  k, book x);
	void updatefile(int k);
};

LinkListarray::LinkListarray(int MaxListSize)
{ // Constructor for the sequential linear list
	MaxSize = MaxListSize;
	element = new  LinkList[MaxSize];
	len = 0;
}

LinkListarray::LinkListarray(const LinkListarray& temp)
{ // Copy constructor
	MaxSize = temp.MaxSize;
	element = new LinkList[MaxSize];
	len = temp.len;
	memcpy(element, temp.element, MaxSize);
}

LinkListarray::~LinkListarray()
{ // Distructor for the sequential linear list
	delete[] element;
}

bool  LinkListarray::isEmpty()
{ // Function that checks whether the list is empty
	return   len == 0;
}

int  LinkListarray::length()
{ // Function that returns the length of the list
	return   len;
}

int  LinkListarray::maxSize()
{ // Function that returns the length of the list
	return   MaxSize;
}

LinkList  LinkListarray::returnListElement(int k)
{ //Function that returns the k-th element of the list
	return element[k];
}
bool  LinkListarray::find(int  k)
{ // Set x to the kth element and return true if kth element is present otherwise return false. 
	if (element[k].length == 0)   return   false;
	return   true;
}

int  LinkListarray::search(char key[20], int index)
{ // Search for x and return the position if found, else return 0.
	if (element[index].search1(key) == true)    return   1;
	return   0;
}

void LinkListarray::deleteElement(int  k, char key[20])
{
	element[k].deleteElement1(key);

	len--;
}

void LinkListarray::updatefile(int index)
{
	element[index].updatefile1();
}

int LinkListarray::insert(int  k, book x)
{ // Insert x after kth element. 
	/*for (int i = len - 1; i >= k; i--){
	element[i + 1] = element[i];
	}*/
	int value = element[k].insert1(x, MaxSize);
	len++;
	return   value;
}

