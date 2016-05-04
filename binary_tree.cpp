#include <iostream>
using namespace std;
struct node{
  int value;
  node *left,*right,*previous,*next;
};
class btree{
public:
  btree(){root=NULL;}
  ~btree(){destroy();}
  void destroy();
  bool search(int);
  void print();
  void insert(int);
  node *newNode(int);
  bool erase(int);
private:
  node *start,*last;
  node *root;
};
bool btree::erase(int key){
  node *current, *target, *previous;
  current = root;
  target = NULL;
  if (current == NULL) return false;
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
    return false;

  if (!target->left || !target->right) {
      if(target == root) {
        root = target->left ? target->left : target->right;
      } else {
        if(previous->left == target)
          previous->left = target->left ? target->left : target->right;
        else
          previous->right = target->left ? target->left : target->right;
      }
    if (start == target) {
      start = start->next;
      start->previous = NULL;
    }
    else if(last == target){
      last = last->previous;
      last->next=NULL;
    }else{
      target->previous->next=target->next;
      target->next->previous=target->previous;
    }
    delete target;
  }else{
    swap(current->value, target->value);
    if(previous->right == current) previous->right = current->right;
    else previous->left = current->right;
    delete current;
  }
  return true;
}
void btree::destroy(){
  node *current=start;
  node *target;
  while(current){
    target=current;
    current=current->next;
    delete target;
  }
}
node* btree::newNode(int key){
  node *leaf=new node;
  leaf->value=key;
  leaf->left=NULL;
  leaf->right=NULL;
  leaf->next=NULL;
  leaf->previous=NULL;
}
void btree::insert(int key){
  node *leaf,*father;
  bool lado;
  leaf = root;
  if(leaf==NULL){
    root=newNode(key);
    start=root;
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
  if(lado){
    father->right=leaf;
    leaf->previous=father;
    leaf->next=father->next;
    if(leaf->next)leaf->next->previous=leaf;
    else last=leaf;
    father->next=leaf;
  }
  else{
    father->left=leaf;
    leaf->previous=father->previous;
    leaf->next=father;
    if(leaf->previous)father->previous->next=leaf;
    else start = leaf;
    father->previous=leaf;
  }
}
bool btree::search(int key) {
  node *n = root;
  node *father = NULL;
  while (n)
      if( n->value < key ){
        father = n;
        n = n->right;
      }
      else if( n->value > key ){
        father = n; n = n->left;
      }
      else return true;
  return NULL;
}
void btree::print() {
  node *current=start;
  while(current){
    cout<<current->value<<"  ";
    current=current->next;
  }
}
int main(){
  btree * a= new btree;
  a->insert(8);
  a->insert(3);
  a->insert(1);
  a->insert(6);
  a->insert(4);
  a->insert(7);
  a->insert(10);
  a->insert(14);
  a->insert(13);
  a->print();
  cout<<endl;
  a->erase(1);
  a->print();
  cout<<endl;
  cout<<endl;
  a->erase(10);
  cout<<endl;
  a->print();
  return 0;
}
