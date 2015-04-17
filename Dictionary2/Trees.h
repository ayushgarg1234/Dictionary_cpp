using namespace std;

class TreeNode{
public:
	book data;
	TreeNode *parent, *left, *right;
};

class BST{
public:
	TreeNode *root;
	BST();
	~BST();
	void BSTinsert(book B);
	void BSTsearch(char key[20]);
	void BSTdelete(char key[20]);

};

BST::BST()
{
	root = new TreeNode;
	root->data.key[0] = 0;
	root->left = NULL;
	root->right = NULL;
	root->parent = NULL;
}

BST::~BST()
{
	root = NULL;
}

void BST::BSTinsert(book B)
{
	TreeNode *temp = root, *temp2 = NULL;

	while (temp != NULL && temp->data.key[0] != 0)
	{
		if (strcmp(B.key, temp->data.key) == -1)
		{
			temp2 = temp;
			temp = temp->left;
		}
		else
		{
			temp2 = temp;
			temp = temp->right;
		}
	}

	if (temp == NULL)
	{
		temp = new TreeNode;
		if (strcmp(B.key, temp2->data.key) == -1)
			temp2->left = temp;
		else
			temp2->right = temp;
	}
	temp->data = B;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = temp2;
}

void BST::BSTsearch(char key[20])
{
	TreeNode *temp = root;
	while (temp != NULL && strcmp(key, temp->data.key) != 0 && temp->data.key[0] != 0)
	{
		//cout << temp->data.key << endl;
		if (strcmp(key, temp->data.key) == -1)
			temp = temp->left;
		else
			temp = temp->right;
	}
	if (temp == NULL || temp->data.key[0] == 0)
		cout << "Unsuccessful search";
	else
		cout << "Successful search";
}

