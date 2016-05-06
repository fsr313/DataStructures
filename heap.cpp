struct node{
  int key;
  node* father, next, last, right, left;
};
class heap{
public:
  heap();
  ~heap();
  bool insert(key);
  bool delete(key);
  void print();
private:
  node* root, end, start, donde;

};
node* heap::newNode(key){
  node *p=new node;
  p->father=NULL;
  p->next=NULL;
  p->last=NULL;
  p->right=NULL;
  p->left=NULL;
  return p;
}
bool heap::insert(key){
  node* target=newNode();
  insertList(target);
  if(root==NULL){
    root=target;
    donde=target;
    return true;
  }
  if (!donde->left){
    donde->left=target;
    donde->next=target;
  }else{
    donde->right=target;
    target->father=donde;
    donde=donde->next;
  }

}
//father, left ,right , last, next
void heap::swap(node *a,node *b){
  node* aux = a->father;
  a->father=b->father;

  if(b->left==a){
    b->
  }
}
void heap::rise(node *target){
  while(target->father && target->father-key>target->key){

  }
}
void heap::insertList(node *target){
  if(start){
    end->next=targert;
    target->last=end;
    end=target;
  }else{
    start=target;
    end=target;
  }
}
