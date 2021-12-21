#include <iostream>
#include "malloc.h"

using namespace std;

struct node
{
	int data;
    struct node* left,
               * right;
};

void insert(struct node** r, int val)
{
    if (*r == NULL)
	{
        *r = (struct node*) malloc(sizeof (struct node));
        (*r)->data = val;
        (*r)->left = (*r)->right = NULL;
	}
    else if (val < (*r)->data)
	{
        insert(&(*r)->left, val);
	}
    else if (val > (*r)->data)
	{
        insert(&(*r)->right, val);
	}
}

void inorderTraverse(struct node* r )
{
	if (r)
	{
        inorderTraverse(r->left );
		cout << r->data << " ";
        inorderTraverse(r->right );
	}
}

void preorderTraverse(struct node* r)
{
    if (r)
    {
        cout << r->data << " ";
        preorderTraverse(r->left);
        preorderTraverse(r->right);
    }
}

void postorderTraverse(struct node* r)
{
    if (r)
    {
        postorderTraverse(r->left);
        postorderTraverse(r->right);
        cout << r->data << " ";
    }
}

int main()
{
    struct node* root = NULL;
    insert(&root, 20);
    insert(&root, 16);
    insert(&root, 24);
    insert(&root, 18);
    insert(&root, 10);
    insert(&root, 30);

    cout << "Inorder Traversal: "; inorderTraverse(root ); cout << endl;
    cout << "Preorder Traversal: "; preorderTraverse(root); cout << endl;
    cout << "Postorder Traversal: "; postorderTraverse(root); cout << endl;

	return 0;
}
