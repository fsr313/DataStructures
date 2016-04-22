#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct nodo;
class ListaArcos;
class Lista;

struct arco{
  nodo* direccion_nodo;
  int valor;
  arco* siguiente;
};
struct nodo{
  int bandera,cuantos,totales,valor_de_verdad,conectivo;
  string enunciado;
  ListaArcos *salientes;
  nodo* siguiente;
};
struct contenedor{
  nodo* direccion_nodo;
  contenedor *siguiente;
};
class Lista{
  contenedor *principio,*final,*anterior;
public:
  Lista();
  ~Lista();
  void agregar(nodo *p);
  bool buscar(nodo *p);
  nodo* getPrincipio();
};
Lista::Lista(){
  principio=NULL;
  final=NULL;
  anterior=NULL;
}
Lista::~Lista(){
  contenedor *p;
  while(principio){
    p=principio;
    principio=principio->siguiente;
    delete p;
  }
}
bool Lista::buscar(nodo *q){
  contenedor *p;
  p=principio;
  while(p){
    if(p->direccion_nodo==q)return true;
    p=p->siguiente;
  }
  return false;
}
void Lista::agregar(nodo *p){
  if(buscar(p))return;
  contenedor *q;
  q=new contenedor;
  q->direccion_nodo=p;
  if(principio){
    final->siguiente=q;
    final=q;
  }else{
    principio=q;
    final=q;
  }
  q->siguiente=NULL;
  return;
}
nodo* Lista::getPrincipio(){
  if(!principio)return NULL;
  nodo *q=principio->direccion_nodo;
  contenedor *p=principio;
  principio=principio->siguiente;
  delete p;
  return q;
}
class ListaArcos{
  arco *principio,*final,*anterior;
public:
  ListaArcos();
  ~ListaArcos();
  bool buscar(string a);
  void agregar(nodo *p,int valor);
  void pintar();
  arco* getPrincipio(){return principio;}
};
ListaArcos::ListaArcos(){
  principio=NULL;
  final=NULL;
  anterior=NULL;
}
ListaArcos::~ListaArcos(){
  arco *p;
  while(principio){
    p=principio;
    principio=principio->siguiente;
    delete p;
  }
}
bool ListaArcos::buscar(string a){
  arco *p;
  p=principio;
  while(p){
    if(p->direccion_nodo->enunciado==a)return true;
    p=p->siguiente;
  }
  return false;
}
void ListaArcos::agregar(nodo *p,int valor){
  if(buscar(p->enunciado))return;
  arco *q;
  q=new arco;
  q->direccion_nodo=p;
  q->valor=valor;
  if(principio){
    final->siguiente=q;
    final=q;
  }else{
    principio=q;
    final=q;
  }
  q->siguiente=NULL;
  return;
}
void ListaArcos::pintar(){
  arco *p;
  p=principio;
  while(p){
    cout<<p->direccion_nodo->enunciado<<", "<<p->valor<<" ";
    p=p->siguiente;

  }
}
class ListaNodos{
  nodo *principio,*final,*anterior,*principio2,*final2,*lugarAgregado;
public:
  ListaNodos();
  ~ListaNodos();
  bool buscar(string cadena);
  void agregar(string cadena,int tipo,int conectivo);
  void pintar();
  nodo* getLugar(){return lugarAgregado;}
  nodo* getPrincipio(){return principio;}
};
ListaNodos::ListaNodos(){
  principio=NULL;
  final=NULL;
  anterior=NULL;
  principio2=NULL;
  final2=NULL;
}
ListaNodos::~ListaNodos(){
  nodo *p;
  while(principio){
    p=principio;
    principio=principio->siguiente;
    delete p;
  }
}
bool ListaNodos::buscar(string cadena){
  nodo *p;
  p=principio;
  while(p){
    if(p->enunciado==cadena){
      lugarAgregado=p;
      return true;
    }
    p=p->siguiente;
  }
  return false;
}
void ListaNodos::agregar(string cadena,int tipo,int conectivo){
  if(buscar(cadena))return;
  nodo *p;
  p=new nodo;
  lugarAgregado=p;
  p->bandera=tipo;
  p->cuantos=0;
  p->totales=0;
  p->valor_de_verdad=-1;
  p->enunciado=cadena;
  p->conectivo=conectivo;
  p->salientes=new ListaArcos;
  if(tipo==0){
    p->siguiente=principio2;
    if(principio){
      final->siguiente=p;
      final=p;
    }else{
      principio=p;
      final=p;
    }
  }else{
    if(principio2){
      final2->siguiente=p;
      final2=p;
    }else{
      final->siguiente=p;
      principio2=p;
      final2=p;
    }
  }
}
void ListaNodos::pintar(){
  nodo *p;
  p=principio;
  while(p){
    cout<<p->enunciado<<", "<<p->bandera<<", "<<p->cuantos<<", "<<p->totales<<", "<<p->valor_de_verdad<<" "<<endl;;
    p->salientes->pintar();
    cout<<endl;
    p=p->siguiente;
  }
}
class SistemaExperto{
  ListaNodos *A;
  Lista *B;
public:
  SistemaExperto();
  ~SistemaExperto();
  void agregar(string cadena,int tipo,int conectivo){A->agregar(cadena,tipo,conectivo);}
  void procesar();
  void conectar(string cadena,string cadena2,int valor);
  void pintar();
  void procesar(nodo *p);
  bool es_redundante(nodo *p);
  void hacerPregunta(nodo *p);
  void correrSistema();
  void imprimirRespuesta(nodo *p);
};
SistemaExperto::SistemaExperto(){
  A=new ListaNodos;
  B=new Lista;
}
SistemaExperto::~SistemaExperto(){
  delete A;
  delete B;
}
void SistemaExperto::conectar(string cadena,string cadena2, int valor){
  nodo *p,*q;
  A->buscar(cadena);
  p=A->getLugar();
  A->buscar(cadena2);
  q=A->getLugar();
  p->salientes->agregar(q,valor);
  q->totales++;
}
void SistemaExperto::pintar(){
  A->pintar();
}
void SistemaExperto::correrSistema(){
  nodo *p;
  p=A->getPrincipio();
  while(p){
    if(es_redundante(p)){
      p=p->siguiente;
      continue;
    }else{
      hacerPregunta(p);
      if(p->valor_de_verdad==2){
        p=p->siguiente;
        continue;
      }else{
        procesar(p);
        nodo *q;
        while(q=B->getPrincipio()){
          procesar(q);
        }
      }
    }
  }
  cout<<"no se pudo llegar a una solucion"<<endl;
}
void SistemaExperto::procesar(nodo *p){
  arco *q=p->salientes->getPrincipio();
  while(q){
    if(q->direccion_nodo->valor_de_verdad!=-1){
      q=q->siguiente;
      continue;
    }
    int a=p->valor_de_verdad;
    if(q->valor==1){
      if(a==0)a=1;
      else a=0;
    }
    if(q->direccion_nodo->conectivo==0){
      if(a==0){
        q->direccion_nodo->valor_de_verdad=0;
        B->agregar(q->direccion_nodo);
        continue;
      }else{
        q->direccion_nodo->cuantos++;
        if(q->direccion_nodo->totales==q->direccion_nodo->cuantos){
          if(q->direccion_nodo->bandera==2)return imprimirRespuesta(q->direccion_nodo);
          else B->agregar(q->direccion_nodo);
        }
        continue;
      }
    }else{
      if(a==1){
        q->direccion_nodo->valor_de_verdad=1;
        if(q->direccion_nodo->bandera==2)return imprimirRespuesta(q->direccion_nodo);
        else B->agregar(q->direccion_nodo);
        continue;
      }else{
        q->direccion_nodo->cuantos++;
        if(q->direccion_nodo->cuantos==q->direccion_nodo->totales){
          q->direccion_nodo->valor_de_verdad=0;
          B->agregar(q->direccion_nodo);
        }
      }
    }
  }
}
void SistemaExperto::imprimirRespuesta(nodo *p){
  cout<<"es un "<<p->enunciado<<endl;
  exit (0);
}
void SistemaExperto::hacerPregunta(nodo *p){
  cout<<p->enunciado<<" 0)no,1)si,2)no se"<<endl;
  cin>>p->valor_de_verdad;
  cout<<endl;
}
bool SistemaExperto::es_redundante(nodo *p){
  arco *q;
  q=p->salientes->getPrincipio();
  while(q){
    if(q->direccion_nodo->valor_de_verdad==-1)return false;
    q=q->siguiente;
  }
  return true;
}

int main(){
  SistemaExperto *A= new SistemaExperto;
  string c[35]={"tiene pelo?", "da leche?","tiene plumas?","vuela?","pone huevos?","come carne?","tiene dientes agudos?","tiene garras?",
     				"tiene ojos que miren hacia adeltante?","tiene pezunas?","rumia?","tiene color leonado?","tiene manchas oscuras?",
     				"tiene franjas negras?","tiene patas largas?","tiene cuello largo?","es de color blanco?","es blanco y negro?","nada?",
     				"es mamifero","es una ave","es carnivoro","es un angulado","d1","d2","d3","d4","d5","es una onza","es un tigre","es una jirafa",
     				"es una cebra","es un avestruz","es un pinguino","es un alabatros"};

  /*for(int i=0;i<19;i++){
    A->agregar(c[i],0,0);
  }
  for(int i=19;i<23;i++){
    A->agregar(c[i],0,1);
  }
  for(int i=23;)*/
  A->agregar("p",0,0);
  A->agregar("q",0,0);
  A->agregar("P",2,0);
  A->agregar("Q",2,0);
  A->conectar("p","P",0);
  A->conectar("q","Q",0);
  A->correrSistema();
  return 0;

}
