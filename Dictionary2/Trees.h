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
	void Preorder(TreeNode *N);
	void Inorder(TreeNode *N);
	void Postorder(TreeNode *N);
};

BST::BST()
{
	root = NULL;
}

BST::~BST()
{
	root = NULL;
}

void BST::BSTinsert(book B)
{
	TreeNode *temp = root, *temp2 = NULL;

	while (temp != NULL)
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

	temp = new TreeNode;
	if (root == NULL)
		root = temp;
	if (temp2 != NULL)
	{
		if (strcmp(B.key, temp2->data.key) == -1)
			temp2->left = temp;
		else
			temp2->right = temp;
	}
	temp->data = B;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = temp2;
	cout << "traversal" << endl;
}

void BST::BSTsearch(char key[20])
{
	TreeNode *temp = root;
	while (temp != NULL && strcmp(key, temp->data.key) != 0)
	{
		//cout << temp->data.key << endl;
		if (strcmp(key, temp->data.key) == -1)
			temp = temp->left;
		else
			temp = temp->right;
	}
	if (temp == NULL)
		cout << "Unsuccessful search";
	else
		cout << "Successful search";
}

void BST::BSTdelete(char key[20])
{

}

void BST::Preorder(TreeNode *N)
{
	if (N != NULL)
	{
		cout << N->data.key << endl;
		Preorder(N->left);
		Preorder(N->right);
	}
}

void BST::Inorder(TreeNode *N)
{
	if (N != NULL)
	{
		Inorder(N->left);
		cout << N->data.key << endl;
		Inorder(N->right);
	}
}

void BST::Postorder(TreeNode *N)
{
	if (N != NULL)
	{
		Postorder(N->left);
		Postorder(N->right);
		cout << N->data.key << endl;
	}
}

