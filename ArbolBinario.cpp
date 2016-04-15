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
void Arbol::pintar(){
  nodo *p=principio;
  while(p){
  }
}
void Arbol::buscar(int a){
	nodo *p;
	p=raiz;
	if(!p){
		encontrado = NO;
		como = VACIO;
		return;
	}
	while(p){
		if(p->valor==a){
			encontrado=SI;
      donde=p;
			return;
		}else if(p->valor<a){
			if(!(p->h_der)){
				encontrado=NO;
				como=H_DER;
				return;
			}
			else{
				donde = p;
				como=H_DER;
				p=p->h_der;
				continue;
			}
		}else{
			if(!p->h_izq){
				encontrado=NO;
				donde=p;
				como=H_IZQ;
				return;
			}else{
				donde=p;
				como=H_IZQ;
				p=p->h_izq;
			}
		}
	}
}
int Arbol::agregar(int a){
	nodo *p;
	buscar(a);
	if(encontrado==SI)return(0);
	p=new nodo;
	if(como==VACIO){
		raiz=p;
		principio=p;
		final=p;
		p->padre=NULL;
		p->h_izq=NULL;
		p->h_der=NULL;
		p->anterior=NULL;
		p->siguiente=NULL;
		return(1);
	}else if(como==H_DER){
		donde->h_der=p;
		p->padre=NULL;
		p->h_der=NULL;
		p->h_izq=NULL;
		if(!donde->siguiente){
			donde->siguiente=p;
			p->siguiente=NULL;
			final=p;
			p->anterior=donde;
			return(1);
		}else{
			p->siguiente=donde->siguiente;
			p->siguiente->anterior=p;
			donde->siguiente=p;
			p->anterior=donde;
		}
	}else{
		donde->h_izq=p;
		p->padre=donde;
		p->h_der=NULL;
		p->h_izq=NULL;
		if(!(donde->anterior)){
			donde->anterior==NULL;
			p->anterior=NULL;
			principio=p;
			p->siguiente=donde;
			return(1);
		}else{
			p->anterior=donde->anterior;
			p->anterior->siguiente=p;
			donde->anterior=p;
			p->siguiente=donde;
			return(1);
		}
	}
}

void Arbol::borrar1(nodo *p){
  if(p->h_izq==NULL && p->h_der==NULL){
    p->padre=NULL;
    p->anterior->siguiente=p->siguiente;
    p->siguiente->anterior=p->anterior;
    delete p;
    return;
  }else if((p->h_izq!=NULL && p->h_der==NULL)||(p->h_izq==NULL && p->h_der!=NULL)){
    if(p->padre->h_izq==p){
      if(p->h_izq){
        p->padre->h_izq=p->h_izq;
      }else{
        p->padre->h_izq=p->h_der;
      }
    }else{
      if(p->h_izq!=NULL){
        p->padre->h_der=p->h_der;
      }else{
        p->padre->h_der=p->h_izq;
      }
    }
    p->anterior->siguiente=p->siguiente;
    p->siguiente->anterior=p->anterior;
    delete p;
    return;
  }
}
void Arbol::intercambiar(nodo *p,nodo *q){
  nodo *r;
  if(p->padre==q){
    if(q->h_der==p){
      FUNCION
    }else{

    }
  }else if(q->padre==p){
    FUNCION
  }else{
    r=p->padre;
    p->padre=q->padre;
    q->padre=r;
    r=p->h_der;
    p->h_der=q->h_der;
    q->h_der=r;
    r=p->h_izq;
    p->h_izq=q->h_izq;
    q->h_izq=r;
    if(p->padre==NULL){
      raiz=p;
    }else{
      if(p->padre->h_der==q){
        p->padre->h_der==p;
      }else{
        p->padre->h_izq=q;
      }
    }
  }
}
int main(){
  return 1;
}
