#include <iostream>
#include <string>
#include <stdio>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

class Tree
{
private:
    node *root;

public:
    Tree(int d)
    {
        root = new node;
        root->data = d;
    }

    void traverse()
    {
        traverse_subtree(root);
        cout << endl;
    }

    void traverse_subtree(node * ptr)
    {
        if ( ptr == NULL )
            return;
        
        traverse_subtree(ptr->left); 
        cout << ptr->data << " ";  
        traverse_subtree(ptr->right);  
    }

    string search(int data)
    {
        node * ptr = root;
        string path = "root";

        while (ptr != NULL)
        {
            if (data == ptr->data)
                return path;
            
            if (data < ptr->data)
            {
                path += " -> left";
                ptr = ptr->left;
            }
            else
            {
                path += " -> right";
                ptr = ptr->right;
            }       
        }
        return "Not found";
    }


    void insert(int d)
    {
        node *newnode = new node;
        newnode->data = d;

        if (root == NULL)
        {
            root = newnode;
            return;
        }

        node * ptr = root;
        while (true)
        {
            if (newnode->data < ptr->data)
            {
                if (ptr->left == NULL)
                {
                    ptr->left = newnode;
                    return;
                }
                else
                    ptr = ptr->left;
            }

            else
            {
                if (ptr->right == NULL)
                {
                    ptr->right = newnode;
                    return;
                }
                else
                    ptr = ptr->right;
            }
        }
    }
};

int main()
{
    Tree mytree(10);

    int x[] = {2,3,4,5,6,3,65,76,89};

    for (int i=0; i<9; i++)
    {
        mytree.insert(x[i]);
    }

    mytree.traverse();  

    cout<<mytree.search(89)<<endl;  

    return 0;
}
