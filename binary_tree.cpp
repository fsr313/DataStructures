#include <iostream>
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
  node * search(int , node *);
  void destroy(node *);
  void print(node *);
  void erase(node * , int);
  node * search(int);
  void destroy(){destroy(root);}
  void print(){print(root);}
  void insert(int);
  void erase(int value){erase(root, value);}
  bool erase(int);
private:
  node *root;
};
bool btree::erase(int key){
  node *current, *target, *previous;
  current = root;
  target = NULL;
  if (current == NULL) return FALSE;
  while (1){
    if (current->value == key)
      target = current;
    if (key < current->value){
      if (current->left == NULL)
        break;
      previous = current;
      current = current->left;
    }else{
      if (current->right == NULL)
      break;
      previous = current;
      current = current->right;
    }
  }
  if (target == NULL)
    return FALSE;
  else{
  if(previous == NULL){
    delete current;
    root = NULL;
  }
  else{
    target->value = current->value;
    if (previous->left == current)
      previous->left = current->right;
    else
      previous->right = current->left;
    delete current;
    }
  }
  return TRUE;
}
btree::btree(){
  root=NULL;
}
void btree::imprimir(){
  node *p = root;
  stack<node> = pila;
  while (p){
    pila.push(p);
    if(p->left==NULL){
      cout<<p->value;
    }
  }
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
node *btree::search(int key){
  return search(key, root);
}
void btree::insert(int key, node *leaf){
  if(key<leaf->value){
    if(leaf->left!=NULL)insert(key, leaf->left);
    else{
      leaf->left=new node;
      leaf->left->value=key;
      leaf->left->left=NULL;
      leaf->left->right=NULL;
    }
  }
  else if(key>=leaf->value){
    if(leaf->right!=NULL)insert(key, leaf->right);
    else{
      leaf->right=new node;
      leaf->right->value=key;
      leaf->right->left=NULL;
      leaf->right->right=NULL;
    }
  }
}
void btree::print(node* leaf){
    if(leaf != NULL){
        if(leaf->left)print(leaf->left);
        cout << leaf->value << ", ";
        if(leaf->right)print(leaf->right);
    }
    else return;
}
node *btree::search(int key, node *leaf){
  if(leaf!=NULL){
    if(key==leaf->value)return leaf;
    if(key<leaf->value)return search(key, leaf->left);
    else return search(key, leaf->right);
  }
  else return NULL;
}
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
  btree * a= new btree;
  a->insert(3);
  a->insert(2);
  a->insert(4);
  a->insert(1);
  a->insert(5);
  a->insert(-1);
  a->insert(0);
  a->print();
  cout<<endl;
  a->erase(3);
  a->erase(3);
  a->print();
  return 0;
}
