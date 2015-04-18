using namespace std;

class TreeNode{
public:
	book data;
	TreeNode *parent, *left, *right;
	int height = 0;
};

class BST{
public:
	TreeNode *root;
	BST();
	~BST();
	TreeNode* BSTinsert(book B);
	TreeNode* BSTsearch(char key[20]);
	void BSTdelete(char key[20]);
	void Preorder(TreeNode *N);
	void Inorder(TreeNode *N);
	void Postorder(TreeNode *N);
	TreeNode* Successor(TreeNode* N);
};

BST::BST()
{
	root = NULL;
}

BST::~BST()
{
	root = NULL;
}

TreeNode* BST::BSTinsert(book B)
{
	TreeNode *temp = root, *temp2 = NULL;

	while (temp != NULL)
	{
		if (strcmp(B.key, temp->data.key) < 0)
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
		if (strcmp(B.key, temp2->data.key) < 0)
			temp2->left = temp;
		else
			temp2->right = temp;
	}
	temp->data = B;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = temp2;
	cout << "Insert successful" << endl;
	return temp->parent;
}

TreeNode* BST::BSTsearch(char key[20])
{
	TreeNode *temp = root;
	while (temp != NULL && strcmp(key, temp->data.key) != 0)
	{
		//cout << temp->data.key << endl;
		if (strcmp(key, temp->data.key) < 0)
			temp = temp->left;
		else
			temp = temp->right;
	}
	if (temp == NULL)
	{
		cout << "Unsuccessful search" << endl;
		return temp;
	}
	else
	{
		cout << "Successful search" << endl;
		return temp;
	}
}

void BST::BSTdelete(char key[20])
{
	TreeNode* search = BSTsearch(key);
	TreeNode* todelete;
	TreeNode *z, *p;
	if (search == NULL)
		cout << "Element not found" << endl;
	else
	{
		if (search->left == NULL || search->right == NULL)
			todelete = search;
		else
		{
			todelete = Successor(search);
		}
		if (todelete->left != NULL)
			z = todelete->left;
		else
			z = todelete->right;
		if (z != NULL)
			z->parent = todelete->parent;
		p = todelete->parent;
		if (p == NULL)
		{
			root = z;
		}
		else
		{
			if (todelete == p->left)
				p->left = z;
			else
				p->right = z;
			if (todelete != search)
				search->data = todelete->data;
		}
		cout << "delete successful" << endl;
		Inorder(root);
	}
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
		cout << N->data.key << " " << N->height << endl;
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

TreeNode* BST::Successor(TreeNode* N)
{
	TreeNode* parent1;
	if (N->right != NULL)
	{
		N = N->right;
		while (N->left != NULL)
			N = N->left;
		return N;
	}
	parent1 = N->parent;
	while (parent1 != NULL && parent1->right == N)
	{
		N = parent1;
		parent1 = parent1->parent;
	}
	return parent1;
}

class AVL : public BST
{
public:
	TreeNode* updateheight(TreeNode* N);

};

TreeNode* AVL::updateheight(TreeNode* N)
{
	int balancefactor = NULL;
	TreeNode* balancecheck = N;
		while (N != NULL)
		{
			if (N->left != NULL && N->right != NULL)
			{
				if (N->left->height > N->right->height)
					N->height = N->left->height + 1;
				else
					N->height = N->right->height + 1;
			}
			else if (N->left == NULL && N->right != NULL)
				N->height = N->right->height + 1;
			else if (N->left != NULL && N->right == NULL)
				N->height = N->left->height + 1;
			else
				N->height = 0;
			N = N->parent;
		}
		return balancecheck;
	}


