using namespace std;

class Node_234_Tree{
public:
	book data[3];
	Node_234_Tree *parent, *children[4];
};

class Tree_234{
public:
	Node_234_Tree *root;
	Tree_234();
	~Tree_234();
	void insert();
	void treeinsert(book B);
	void search();
};

Tree_234::Tree_234()
{
	root = NULL;
}

Tree_234::~Tree_234()
{
	root = NULL;
}

void Tree_234::insert()
{

}

void Tree_234::treeinsert(book B)
{

}

