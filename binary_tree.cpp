#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stack>
using namespace std;
struct node{
  int value;
  node *left;
  node *right;
};
class btree{
public:
  btree();
  ~btree();
  void insert(int , node *);
  //node * search(int , node *);
  void destroy(node *);
  void print(node *);
  void erase(node * , int);
  bool search(int);
  void destroy(){destroy(root);}
  void print(){print(root);}
  void insert(int);
  void erase(int value){erase(root, value);}
private:
  node *root;
};
btree::btree(){
  root=NULL;
}
void btree::destroy(node *leaf){
  if (leaf!=NULL){
    destroy(leaf->left);
    destroy(leaf->right);
    delete leaf;
  }
}
void btree::insert(int key){
  if(root!=NULL)
    insert(key, root);
  else{
    root=new node;
    root->value=key;
    root->left=NULL;
    root->right=NULL;
  }
}
bool btree::search(int key){
  if (root == NULL)
  return false;
  stack<node *> nodeStack;
  nodeStack.push(root);
  node *leaf;
  while (nodeStack.empty() == false){
    // See the top item from stack and check if it is same as x
    leaf = nodeStack.top();
    if (node->value == key)
      return true;
    nodeStack.pop();
    // Push right and left children of the popped node to stack
    if (leaf->right)
     nodeStack.push(leaf->right);
    if (leaf->left)
      nodeStack.push(leaf->left);
  }
  return false;
}
/*node *btree::search(int key){
  return search(key, root);
}*/
/*void btree::insert(int value){
  node* q= root;
  if (!q){
    q = new node;
    q->value = value;
    q->left = q->right = NULL;
  }
  else{
    node * p = q ;
    for ( ; ; ){
      while ( value < p->value ){
        if ( p->left ) p = p->left ;
        else{
          p->left = new node ;
          p->left->value = value ;
          p->left->left = p->left->right = NULL ;
          return;
        }
      }
      while ( value > p->value )  {
        if ( p->right )p = p->right ;
        else{
          p->right = new node ;
          p->right->value = value ;
          p->right->left = p->right->right = NULL ;
          return;
        }
      }
    }
  }
}*/
void btree::print(node* leaf){
    if(leaf != NULL){
        if(leaf->left)print(leaf->left);
        cout << leaf->value << ", ";
        if(leaf->right)print(leaf->right);
    }
    else return;
}
/*node *btree::search(int key, node *leaf){
  if(leaf!=NULL){
    if(key==leaf->value)return leaf;
    if(key<leaf->value)return search(key, leaf->left);
    else return search(key, leaf->right);
  }
  else return NULL;
}*/
void btree::erase(node* n, int value){
	node* father=NULL;
	node* current=n;
	if(search(value)==NULL){
		cout<<endl<<value<<" not in Tree."<<endl;
		return;
	}
	if((current->left==NULL && current->right != NULL) || (current->left != NULL && current->right==NULL)){
		if(current->left==NULL && current->right != NULL){
			if(father->left==current){
				father->left=current->right;
				delete current;
				current=NULL;

			}
			else{
				father->right=current->right;
				delete current;
				current=NULL;

			}
		}
		else
		{
			if(father->left==current)
			{
				father->left=current->left;
				delete current;
				current=NULL;

			}
			else
			{
				father->right=current->left;
				delete current;
				current=NULL;

			}
		}
		return;
	}
	if(current->left==NULL && current->right==NULL){
		if(father->left==current)
			father->left=NULL;
		else
			father->right=NULL;
		delete current;

		return;
	}
	if(current->left != NULL && current->right != NULL){
		node* check=current->right;
		if((current->left==NULL)&&(current->right==NULL))
		{
			current=check;
			delete check;
			current->right==NULL;

		}
		else{
			if((current->right)->left!=NULL){
				node* leftCurrent;
				node* leftCurrentPred;
				leftCurrentPred=current->right;
				leftCurrent=(current->right)->left;
				while(leftCurrent->left != NULL){
					leftCurrentPred=leftCurrent;
					leftCurrent=leftCurrent->left;
				}
				current->value=leftCurrent->value;
				delete leftCurrent;
				leftCurrentPred->left==NULL;

			}
			else{
				node* temp=current->right;
				current->value=temp->value;
				current->right=temp->right;
				delete temp;

			}
		}
		return;
	}
}
int main(){
  srand(time(NULL));
  btree * a= new btree;
  a->insert(2);
  a->insert(4);
  a->insert(5);
  a->insert(1);
  a->insert(3);
  a->insert(9);
  a->insert(0);
  a->insert(7);
  a->print();
  a->destroy();
  return 0;
}
