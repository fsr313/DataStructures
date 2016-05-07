#include "struct.hpp"

class tail{
public:
  node *start,*end;
  tail();
  ~tail(){};
  void add(node *);
  void swap(node*,node*);
  void poplast();
  void print();
};
void tail::poplast(){
  if(end){
    end=end->previous;
    if(end)end->next=NULL;
    else start=NULL;
  }
}
void tail::swap( node* a, node* b) {

  if (a == b) return;

  if (a == start) start = b;
  else if (b == start) start = a;

  if (a == end) end = b;
  else if (b == end) end = a;

  node *aux;

  if (b->next == a) {
    aux = a;
    a = b;
    b = aux;
  }

  aux = a->previous;
  if (b->previous == a) a->previous = b;
  else a->previous = b->previous;
  b->previous = aux;

  aux = b->next;
  if (a->next == b) b->next = a;
  else b->next = a->next;
  a->next = aux;

  if (a->previous) a->previous->next = a;
  if (a->next) a->next->previous = a;
  if (b->previous) b->previous->next = b;
  if (b->next) b->next->previous = b;
}
tail::tail(){
  start=NULL;
  end=NULL;
}
void tail::add(node *n){
  if(start)end->next=n;
  else start=n;
  n->previous=end;
  end=n;
}
void tail::print() {
  node *aux = start;
  while (aux) {
    std::cout << "Node: " << aux->key << std::endl;
    if (aux->father) std::cout << "father: " << aux->father->key << std::endl;
    if (aux->right) std::cout << "right: " << aux->right->key << std::endl;
    if (aux->left) std::cout << "left: " << aux->left->key << std::endl;
    std::cout << "-------------------------------" << std::endl;
    aux = aux->next;
  }
}
