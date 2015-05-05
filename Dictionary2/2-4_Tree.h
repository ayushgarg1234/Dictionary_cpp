using namespace std;

class Node_234_Tree{
public:
	Node_234_Tree();
	book data[3];
	Node_234_Tree *parent, *children[4];
	int number_of_keys;
};

Node_234_Tree::Node_234_Tree()
{
	number_of_keys = 0;
	children[0] = NULL;
	children[1] = NULL;
	children[2] = NULL;
	children[3] = NULL;
	parent = NULL;
}

class Tree_234{
public:
	Node_234_Tree *root;
	Tree_234();
	~Tree_234();
	Node_234_Tree* search(Node_234_Tree* node, char key[20], int* index);
	void insert(Node_234_Tree* node, book B, Node_234_Tree* node1, Node_234_Tree* node2, int link);
	void treeinsert(book B, Node_234_Tree* node);
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

Node_234_Tree* Tree_234::search(Node_234_Tree* node, char key[20], int* index)
{
	int i = 0;
	while (i < node->number_of_keys && strcmp(key, node->data[i].key)>0)
	{
		i++;
	}
	if (i < 3 && !strcmp(key, node->data[i].key))
	{
		*index = i;
		return node;
	}
	else
	{
		Node_234_Tree* y = node->children[i];
		if (y == NULL)
			return NULL;
		else
			search(y, key, index);
	}
}

void Tree_234::insert(Node_234_Tree* node, book B, Node_234_Tree* node1, Node_234_Tree* node2, int link)
{
	int i = link;
	if (node == NULL)
	{
		//cout << "check " << node1->data[0].key;
		Node_234_Tree* temp = new Node_234_Tree;
		temp->data[0] = B;
		temp->children[0] = node1;
		temp->children[1] = node2;
		temp->number_of_keys = 1;
		node1->parent = temp;
		node2->parent = temp;
		root = temp;
		root->parent = NULL;
	}
	else if (node->number_of_keys < 3)
	{
		node->data[node->number_of_keys] = B;
		//cout << "No  begin=" << node->number_of_keys << endl;
		node->number_of_keys = node->number_of_keys + 1;
		//cout << "No  middle=" << node->number_of_keys << endl;
		for (int k = node->number_of_keys - 2; k >= 0; k--)
		{
			if (strcmp(node->data[k].key, node->data[k + 1].key) > 0)
			{
				book temp;
				temp = node->data[k];
				node->data[k + 1] = node->data[k];
				node->data[k] = temp;
			}
			else
				break;
		}
		//cout << "No  end=" << node->number_of_keys << endl;
		Node_234_Tree *temp1, *temp2;
		//cout << "I =" << i<<endl;
		if (node->children[0] != NULL)
		{
			node->children[i] = node1;
			if (node1 != NULL)
				node1->parent = node;
			temp1 = node->children[i + 1];
			node->children[i + 1] = node2;
			if (node2 != NULL)
				node2->parent = node;
			while (i + 2 < 4)
			{
				temp2 = node->children[i + 2];
				node->children[i + 2] = temp1;
				temp1 = temp2;
				i = i + 1;
			}
		}
		//cout << "No lst end=" << node->number_of_keys << endl;
	}

	else
	{
		//cout << "king";
		int l = 0;
		book a[4];
		a[0] = node->data[0];
		a[1] = node->data[1];
		a[2] = node->data[2];
		a[3] = B;
		int m = 2;
		while (strcmp(B.key, a[m].key) < 0)
		{

			book temp;
			temp = a[m + 1];
			a[m + 1] = a[m];
			a[m] = temp;
			m--;
		}

		Node_234_Tree *first = new Node_234_Tree, *second = new Node_234_Tree, *temp_p;

		book promote;

		first->data[0] = a[0];
		first->number_of_keys = 1;
		promote = a[1];
		second->data[0] = a[2];
		second->data[1] = a[3];
		second->number_of_keys = 2;

		//value to inserted in the node

		temp_p = node->parent;
		/*if (temp_p == NULL)
		{
		cout << "abc" << endl;
		}*/
		if (temp_p != NULL)
		{
			for (l = 0; l < 4; l++)
			{
				if (temp_p->children[l] == node)
					break;
			}
		}
		if (i == 0)
		{

			first->children[0] = node1;
			if (node1 != NULL)
				node1->parent = first;
			first->children[1] = node2;
			if (node2 != NULL)
				node2->parent = first;

			second->children[0] = node->children[1];
			if (second->children[0] != NULL)
				second->children[0]->parent = second;
			second->children[1] = node->children[2];
			if (second->children[1] != NULL)
				second->children[1]->parent = second;
			second->children[2] = node->children[3];
			if (second->children[2] != NULL)
				second->children[2]->parent = second;

		}

		else if (i == 1)
		{

			first->children[0] = node->children[0];
			if (first->children[0] != NULL)
				first->children[0]->parent = first;
			first->children[1] = node1;
			if (node1 != NULL)
				node1->parent = first;

			second->children[0] = node2;
			if (node2 != NULL)
				node2->parent = second;
			second->children[1] = node->children[2];
			if (second->children[1] != NULL)
				second->children[1]->parent = second;
			second->children[2] = node->children[3];
			if (second->children[2] != NULL)
				second->children[2]->parent = second;

		}

		else if (i == 2)
		{

			first->children[0] = node->children[0];
			if (first->children[0] != NULL)
				first->children[0]->parent = first;
			first->children[1] = node->children[1];
			if (first->children[1] != NULL)
				first->children[1]->parent = first;

			second->children[0] = node1;
			if (node1 != NULL)
				node1->parent = second;
			second->children[1] = node2;
			if (node2 != NULL)
				node2->parent = second;
			second->children[2] = node->children[3];
			if (second->children[2] != NULL)
				second->children[2]->parent = second;

		}

		else
		{
			//cout << "cheskk" << endl;
			first->children[0] = node->children[0];
			if (first->children[0] != NULL)
				first->children[0]->parent = first;
			first->children[1] = node->children[1];
			if (first->children[1] != NULL)
				first->children[1]->parent = first;

			second->children[0] = node->children[2];
			if (second->children[2] != NULL)
				second->children[2]->parent = second;
			second->children[1] = node1;
			if (node1 != NULL)
				node1->parent = second;
			second->children[2] = node2;
			if (node2 != NULL)
				node2->parent = second;

		}

		insert(node->parent, promote, first, second, l);

	}
}

void Tree_234::treeinsert(book B, Node_234_Tree* node)
{
	int i;

	if (node == NULL)
	{
		node = new Node_234_Tree;
		node->data[0] = B;
		node->number_of_keys++;
		root = node;
	}

	else if (node->children[0] == NULL)
	{
		Node_234_Tree *temp_p;
		int l;
		temp_p = node->parent;
		if (temp_p == NULL)
		{
			insert(node, B, NULL, NULL, 0);
		}
		else
		{
			for (l = 0; l < 4; l++)
			{
				if (temp_p->children[l] == node)
					break;
			}
			//cout << "ritesh" << l << endl;
			insert(node, B, NULL, NULL, l);
		}
	}
	else
	{
		for (i = 0; i <= 3; i++)
		{
			if (strcmp(node->data[i].key, B.key) > 0 || i == node->number_of_keys)
			{
				//cout << "number" << node->children[i]->number_of_keys << endl;
				break;
			}
		}
		//cout << "i is " << i << endl;
		treeinsert(B, node->children[i]);
	}
}
