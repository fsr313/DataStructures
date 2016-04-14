#include <iostream>
#include <string.h>
using namespace std;
enum Donde{VACIO,PRINCIPIO,ENMEDIO,FINAL}
struct caja1{
  int num_nodo;
  caja2 *direccion_nodo;
  int valor;
  caja1 *siguiente;
}
struct caja2{
  int num_nodo;
  int bandera;
  int totales;
  int conectivo;
  int valor_de_verdad;
  ListaArcos salientes;
  caja2 *siguiente;
}
struct caja3{
  caja2 *direccion_nodo;
  caja3 *siguiente;
}
class ListaArcos{
  caja1 *principio,*anterior,*lugar_agregado;
  bool encontrado;
  Donde donde;
  caja1 *lugar;
public:
  ListaArcos();
  void nuevo();
  ~ListaArcos();
  void termiarn();
  void buscar(int n);
  int agregar(int a);
  void pintar();
  caja1 * Lugar_agregado();
  caja1 * iniciar_recorrido();
  caja1 * recorrer();
}
ListaArcos::ListaArcos(){
  principio=NULL;
  anterior=NULL;
  lugar_agregado=NULL;
  encontrado=false;
  donde=VACIO;
}
void ListaArcos::ListaArcos(){
  principio=NULL;
  anterior=NULL;
  lugar_agregado=NULL;
  encontrado=false;
  donde=VACIO;
}
void ListaArcos::buscar(int a){
  caja1 *p;
  if(!principio){
    encontrado=false;
    donde=VACIO;
    anterior=NULL;
    return;
  }
  p=principio;
  while(p){
    if(p->num_nodo==a){
      encontrado=true;
      lugar_agregado=p;
      if(principio==p){
        donde=PRINCIPIO;
      }else if(p->siguiente==NULL){
        donde=FINAL;
      }else{
        donde=ENMEDIO;
      }
      return;
    }else if(p->num_nodo<a){
      anterior=p;
      p=p->siguiente;
    }else{
      encontrado=false;
      if(principio==p){
        donde=PRINCIPIO;
      }else if(p->siguiente==NULL){
        donde=FINAL;
      }else{
        donde=ENMEDIO;
      }
      return;
    }
    encontrado=false;
    donde=FINAL;
    lugar_agregado=p;
  }
}
int ListaArcos::agregar(int a){
  caja1 *p;
  buscar(a);
  if(encontrado==true)return 0;
  p=new caja1;
  p-<num_nodo = a;
  if(donde==VACIO){
    p->siguiente=NULL;
    principio=p;
  }else if(donde==PRINCIPIO){
    p->siguiente=principio;
    principio=p;
  }else if(donde==FINAL){
    p->siguiente=NULL;
    anterior->siguiente=p
  }else{
    p->siguiente=anterior->siguiente;
    anterior->siguiente=p;
  }
  lugar_agregado=p;
  return (1);
}
void ListaArcos::pintar(){
  caja1* p;
  p=principio;
  while(p){
    cout<<'salientes: ';
    cout<<' '<<p->num_nodo<<' ';
    cout<<'(';
    cout<<p->longitud<<') ';
    p=p->siguiente;
    cout<<endl;
  }
}
class lista_nodos{
  caja2 *principio,*anterior,*lugar_agregado;
  Donde donde;
public:
  bool encontrado;
  lista_nodos();
  void nuevo();
  ~lista_nodos();
  void terminar();
  void buscar(int n);
  caja2* Lugar_agregado();
  int agregar(int a);
  void (int a);
  void pintar();
}
lista_nodos::lista_nodos(){
  principio=NULL;
  anterior=NULL;
  lugar_agregado=NULL;
  encontrado=false;
  donde=VACIO;
}
void lista_nodos::nuevo(){
  principio=NULL;
  anterior=NULL;
  lugar_agregado=NULL;
  encontrado=false;
  donde=VACIO;
}
void lista_nodos::buscar(int a){
  caja2 *p;
  if(principio==NULL){
    encontrado=false;
    donde=VACIO;
    anterior=NULL;
    return;
  }
  p=principio;
  while(p){
    if(p->num_nodo==a){
      encontrado=true;
      lugar_agregado=p;
      if(principio==p){
        donde=principio;
      }else if(p->siguiente==NULL){
        donde=FINAl;
      }else{
        donde=ENMEDIO;
      }
      return;
    }else if(p->num_nodo<a){
      anterior=p;
      p=p->siguiente;
    }else{
      encontrado=false;
      if(principio==p){
        donde=PRINCIPIO;
      }else if(p->siguiente==NULL){
        donde=FINAl;
      }else{
        donde=ENMEDIO;
      }
      return;
    }
    encontrado=false;
    donde=final;
    lugar_agregado=p;
  }
}
int lista_nodos::agregar(int a){
  caja2 *p;
  ListaArcos q;
  buscar(a);
  if(encontrado==true)return(0)
  P=new caja2;
  p->num_nodo=a;
  p->bandera=0;
  p->ruta_corta=0;
  p->anterior=NULL;
  p->salientes.nuevo();
  if(donde==VACIO){
    p->siguiente=NULL;
    principio=p;
  }else if(donde==PRINCIPIO){
    p->siguiente=principio;
    principio=p;
  }else if(donde==FINAL){
    p->siguiente=NULL;
    anterior->siguiente=p;
  }else{
    p->siguiente=anterior->siguiente;
    anterior->siguiente=p;
  }
  lugar_agregado=p;
  return(1);
}
void lista_nodos::pintar(){
  caja2*p;
  p=principio;
  while(p){
  cout<<"nodo: ";
    cout<<p->num_nodo<<endl;
    (p->salientes).pintar();
    p=p->siguiente;
    cout<<endl;
  }
}
class Lista{
  caja3 *principio,*final,*anterior,*lugar_agregado;
  bool encontrado;
  Donde donde;
public:
  Lista();
  ~Lista();
  void nuevo();
  void terminar();
  void buscar(float a);
  void agregar(caja2* p);
  void pintar();
  caja2* sacar();
  caja3* Lugar_agregado();
  void ajustar(caja3 *p,float a);
}
Lista::Lista(){
  principio=NULL;
  final=NULL;
  anterior=NULL;
  lugar_agregado=NULL;
  encontrado=false;
  donde=VACIO;
}
void Lista::nuevo(){
  principio=NULL;
  final=NULL;
  anterior=NULL;
  lugar_agregado=NULL;
  encontrado=false;
  donde=VACIO;
}
Lista::~Lista(){
  caja3 *p;
  while(principio){
    p=principio;
    principio=p-siguiente
    delete p;
  }
}
void Lista::terminar(){
  caja3 *p;
  while(principio){
    p=principio;
    principio=p-siguiente
    delete p;
  }
}
void Lista::buscar(float a){
  caja3 *p;
  if(principio==NULL){
    encontrado=false;
    donde=VACIO;
    anterior=NULL;
    lugar_agregado=NULL;
    return;
  }
  p=principio;
  while(p){
    if(p->valor==a){

    }
  }
}
class SistemaExperto{
  lista_nodos A;
  Lista B;
  int resultado;
public:
  SistemaExperto();
  ~SistemaExperto();
  void agregar_nodo(int a,int b,int c);//A=num_nodo,B=bandera,C=tipo
  int es_redundante(caja2 *p);
}
void SistemaExperto::agregar_nodo(a,b,c){
  caja2 *p;
  A->buscar(a);
  if(A.encontrado==SI)return;
  p=new caja2;
  p->num_nodo=a;
  p->bandera=b;
  p->conectivo=c;
  p->cuantos=0;
  p->totales=0;
  p->valor_de_verdad=-1;
}
int SistemaExperto::es_redundante(caja2 *p){
  caja1 *q;
  p->salientes.iniciar_recorrido();
  q=p->salientes.recorrer();
  while(q){
    if(q->direccion_nodo->valor_de_verdad==-1){
      return 0;
    }
    q=p->salientes.recorrer();
  }
  return 1;
}
