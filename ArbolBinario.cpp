#include <iostream>
struct nodo{
  nodo *padre,*anterior,*siguiente,*h_der,*h_izq;
  int valor;
};
class Arbol{
  nodo *raiz,*principio,*final,*donde;
  int encontrado,como;
  enum encontrado{SI,NO,VACIO};
  enum como{H_DER,H_IZQ};
public:
  Arbol();
  ~Arbol();
  int agregar(int a);
  void buscar(int a);
  void borrar1(nodo *p);
  void pintar();
};
arbol::arbol(){
  raiz=NULL;
  principio=NULL;
  final=NULL;
  donde=NULL;
}
