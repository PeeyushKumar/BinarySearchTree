#include<stdio.h>
#include<stdlib.h>

struct node { 
  int data; 
  struct node *left, *right;
} ;

typedef struct node *BSTNODE;

BSTNODE newNodeInBST(int item) {
  BSTNODE temp = (BSTNODE)malloc(sizeof(struct node)); 
  temp->data = item;
  temp->left = temp->right = NULL;
  return temp;
}

void inorderInBST(BSTNODE root) {   
  	if (root != NULL) 
	{ 
		inorderInBST(root->left); 
		printf("%d ", root->data); 
		inorderInBST(root->right); 
	}
}

void preorderInBST(BSTNODE root) {
	if(root != NULL){
		printf("%d ", root->data); 
		preorderInBST(root->left); 
		preorderInBST(root->right);
	}
}

void postorderInBST(BSTNODE root) { 
  	if(root != NULL){		 
		postorderInBST(root->left); 
		postorderInBST(root->right);
		printf("%d ", root->data);
	}
}
BSTNODE insertNodeInBST(BSTNODE node, int ele) {

  if(node == NULL){
    printf("Successfully inserted,\n");
    return newNodeInBST(ele);
  }
  else{
    if(ele <= node->data){
     node->left = insertNodeInBST(node->left, ele);
    }
    else if(ele > node->data){
     node->right = insertNodeInBST(node->right, ele);
    } 
    else
		printf("Element already exists in BST");
  }
  return node;
}

BSTNODE deleteNodeInBST(BSTNODE root, int ele){
	if(root = NULL){
		printf("Cannot find %d in the binary search tree.\n",ele);
		return root;
	}
	
	if(ele < root->data){
		root->left = deleteNodeInBST(root->left, ele);
	}
	else if(ele > root->data){
		root->right = deleteNodeInBST(root->right, ele);
	}
	else if(ele == root->data){
		if(root->left == NULL){
			BSTNODE temp = root->right;
			printf("Deleted %d from binary search tree.\n", ele);
			free(root);
			return temp;
		}
		
		else if(root->right == NULL){
			BSTNODE temp = root->left;
			printf("Deleted %d from binary search tree.\n", ele);
			free(root);
			return temp;
		}
		
		BSTNODE temp = root->left;
		root = temp->data;
		temp->data = ele;
		root->right = deleteNodeInBST(root->right, ele);
	}
	return root;
}

BSTNODE searchNodeInBST(BSTNODE root, int ele){
	if(root == NULL || root->data == ele)
		return root;
	else if(ele > root->data)
		return searchNodeInBST(root->right, ele);
	else
		return searchNodeInBST(root->left, ele);		
}

int main(){  
  int x, op;
  BSTNODE root = NULL;
  while(1) {
    printf("1.Insert 2.Inorder Traversal 3.Preorder Traversal 4.Postorder Traversal 5.Delete a Node 6.Search 9.Exit\n"); 
    printf("Enter your option :");
    scanf("%d", &op);
    switch(op) {		    	
		case 1: printf("Enter an element to be inserted : "); 
		  scanf("%d", &x);
		  root = insertNodeInBST(root,x);
		  break;
		case 2:
		  if(root == NULL)
		    printf("Binary Search Tree is empty.\n");
		  else {
			printf("Elements of the BST (in-order traversal): "); 
			inorderInBST(root);
			printf("\n");
			}
		  break;
		case 3:
		  if(root == NULL)
		    printf("Binary Search Tree is empty.\n");
		  else {
		    printf("Elements of the BST (pre-order traversal): "); 
		    preorderInBST(root);
		    printf("\n");
			}
		  break;
		case 4:
		  if(root == NULL)
		    printf("Binary Search Tree is empty.\n");
		  else {
		    printf("Elements of the BST (post-order traversal): ");
		    postorderInBST(root);
		    printf("\n");
			}
		  break;
		case 5:
			printf("Enter an element to be deleted : ");
			scanf("%d",&x);
			root = deleteNodeInBST(root,x);
			break;			  
		case 6: 
			printf("Enter an element to be searched : ");
			scanf("%d",&x);
			if(searchNodeInBST(root, x) == NULL)
				printf("Element not found in the binary search tree.\n");
			else
				printf("Element found in the binary search tree.\n");	
			break;	  
		case 9:
		  exit(0);
      }
  }
  
  return 0;
}