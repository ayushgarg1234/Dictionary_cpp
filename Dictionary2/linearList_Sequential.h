using namespace std;

class LinearList{
public:
	int MaxSize;
	int len;
	book *element;
	LinearList(int  MaxSize);
	LinearList(const LinearList& temp);
	~LinearList();
	bool isEmpty();
	int  length();
	int  maxSize();
	book returnListElement(int k);
	bool find(int  k);
	int  search(char key[20]);
    void deleteElement(int  k);
	LinearList  insert(int  k, book x);
};

LinearList::LinearList(int MaxListSize)
{ // Constructor for the sequential linear list
	MaxSize = MaxListSize;
	element = new  book[MaxSize];
	for (int k = 0; k < MaxSize; k++)
	{
		element[k].key[0] = 0;
	}
	len = 0;
}

LinearList::LinearList(const LinearList& temp)
{ // Copy constructor
	MaxSize = temp.MaxSize;
	element = new book[MaxSize];
	len = temp.len;
	memcpy(element, temp.element, MaxSize);
}

LinearList::~LinearList()
{ // Distructor for the sequential linear list
	delete[] element;
}

bool  LinearList::isEmpty()
{ // Function that checks whether the list is empty
	return   len == 0;
}

int  LinearList::length()
{ // Function that returns the length of the list
	return   len;
}

int  LinearList::maxSize()
{ // Function that returns the length of the list
	return   MaxSize;
}

book  LinearList::returnListElement(int k)
{ //Function that returns the k-th element of the list
	return element[k];
}
bool  LinearList::find(int  k)
{ // Set x to the kth element and return true if kth element is present otherwise return false. 
	if (element[k].key[0] == 0)   return   false;
	return   true;
}

int  LinearList::search(char key[20])
{ // Search for x and return the position if found, else return 0.
	for (int i = 0; i < len; i++)
		if (element[i].key == key)    return   ++i;
	return   0;
}

void LinearList::deleteElement(int  k)
{
	element[k].key[0] = 0;
	element[k].key[1] = 0;       //flag
	/*for (int i = k; i < len; i++)
		element[i - 1] = element[i];*/
	len--;
}

LinearList  LinearList::insert(int  k, book x)
{ // Insert x after kth element. 
	/*for (int i = len - 1; i >= k; i--){
		element[i + 1] = element[i];
		}*/
	element[k] = x;
	len++;
	return   *this;
}