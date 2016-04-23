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
  void destroy(node *);
  bool search(int);
  void destroy(){destroy(root);}
  void print();
  void insert(int);
  node *newNode(int);
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
node* btree::newNode(int key){
  node *leaf=new node;
  leaf->value=key;
  leaf->left=NULL;
  leaf->right=NULL;
}
void btree::insert(int key){
  node *leaf,*father;
  bool lado;
  leaf = root;
  if(leaf==NULL){
    root=newNode(key);
    return;
  }
  while(leaf!=NULL){
    if(leaf->value==key)return;
    father=leaf;
    if(key<leaf->value){
      leaf=leaf->left;
      lado=false;
    }
    else{
      leaf=leaf->right;
      lado = true;
    }
  }
  leaf=newNode(key);
  if(lado)father->right=leaf;
  else father->left=leaf;
}
bool btree::search(int key){
  if (root == NULL)
  return false;
  stack<node *> nodeStack;
  nodeStack.push(root);
  node *leaf;
  while (nodeStack.empty() == false){
    leaf = nodeStack.top();
    if(leaf->value == key)
      return true;
    nodeStack.pop();
    if(leaf->right)
     nodeStack.push(leaf->right);
    if(leaf->left)
      nodeStack.push(leaf->left);
  }
  return false;
}
void btree::print() {
  stack<node*> s;
  node *current = root;
  while (!s.empty() || current) {
    if (current) {
      s.push(current);
      current = current->left;
    } else {
      current = s.top();
      s.pop();
      cout << current->value << " ";
      current = current->right;
    }
  }
}
int main(){
  btree * a= new btree;
  a->insert(2);
  a->insert(4);
  a->insert(5);
  a->insert(1);
  a->insert(3);
  a->insert(9);
  a->insert(0);
  a->insert(7);
  a->insert(7);
  a->print();
  a->destroy();
  cout<<"Arreglar el search, crear funcion borrar, transformar el destroy a una forma iterativa";
  return 0;
}
