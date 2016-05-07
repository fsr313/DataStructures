
#include "tail.hpp"

class heap{
private:
  node *father, *root;
  tail *MyTail;
public:
  heap();
  void agregar(int );
  void fall(node*);
  void rise(node*);
  int popfirst();
  void add(int);
  void swap(node*,node*);
  void print(){MyTail->print();}
  node* newNode(int );
};
int heap::popfirst(){
  if(!root)return -1337420;
  node *n=root;
  node *m=root;

  if(father->left){
    n=father->left;
  }else{
    father=father->previous;
    if(father) n=father->right;
  }

  swap(n,m);
  std::cout << "hola" << std::endl;
  MyTail->poplast();

  int value = m->key;
  std::cout << "value" << std::endl;
  if(m->father)
    if(m->father->right==m)m->father->right=NULL;
    else if(m->father->left)m->father->left=NULL;
  if(m==root)root=0;
  delete m;
  fall(n);
  return value;
}
void heap::fall(node *n){
  node *m;
  while (n->left || n->right) {
    if (!n->right)m=n->left;
    else if (!n->left)m=n->right;
    else if (n->right->key>n->left->key) m = n->left;
    else m=n->right;
    if(m->key < n->key) swap(n,m);
    else break;
    std::cout << "HOLA" << std::endl;
  }
}
node* heap::newNode(int a){
  node* leaf= new node;
  leaf->key=a;
  leaf->father=NULL;
  leaf->left=NULL;
  leaf->next=NULL;
  leaf->previous=NULL;
}
heap::heap(){
  father=NULL;
  root=NULL;
  MyTail=new tail;
}
void heap::swap( node *a, node*b ) {
  if (a == b) return;
  node *aux;
  if (a == root) root = b;
  else if ( b == root ) root = a;
  if (a == father) father = b;
  else if ( b == father ) father = a;

  if ( a->father == b ) {
    aux = b;
    b = a;
    a = aux;
  }
  MyTail->swap(a,b);
  aux = b->left;
  if (a->left == b) b->left = a;
  else b->left = a->left;
  a->left = aux;
  aux = b->right;
  if (a->right == b) b->right = a;
  else b->right = a->right;
  a->right = aux;
  aux = a->father;
  if (b->father == a) a->father = b;
  else a->father = b->father;
  b->father = aux;
  if (a->left) a->left->father = a;
  if (a->right) a->right->father = a;
  if (b->left) b->left->father = b;
  if (b->right) b->right->father = b;
  if (a->father)
    if (a->father->right == b) a->father->right = a;
    else if ( a->father->left == b)a->father->left = a;
  if (b->father){
    if (b->father->right == a) b->father->right = b;
    else if ( b->father->left == a)b->father->left = b;
  }
}

void heap::rise(node* n){
  while(n->father && n->father->key>n->key){
    swap(n->father,n);
  }
}
void heap::add(int a){
  node *n = newNode(a);
  MyTail->add(n);
  if(root){
    if(father->left){
      father->right=n;
      n->father=father;
      father=father->next;
    }else{
      father->left=n;
      n->father=father;
    }
    rise(n);
  }else{
    root=n;
    father=n;
  }
}
