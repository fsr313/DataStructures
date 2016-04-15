/*
	Name:apqr_SE .cpp
	Author: Ana Patricia Quiroz Reyes
	Date:
	Description:
*/

#include <iostream>
#include <string.h>
using namespace std;

enum Donde {VACIO,PRINCIPIO,ENMEDIO,FINAL};

struct caja1;
struct caja2;
struct caja3;
class Lista_arcos;

//*************************************************** = ESTRUCTURA CAJA 1 = ******************************************************************

struct caja1{
	int num_nodo, valor;
	caja2*direccion_nodo;
	float longitud;
	caja1 *siguiente;
};

//*************************************************** = CLASE LISTA ARCOS = ******************************************************************

class Lista_arcos{
	caja1 *principio,*anterior,*lugar_agregado;
	bool encontrado;
	Donde donde;
	caja1 *lugar;
public:
	Lista_arcos();
	void nuevo();
	~Lista_arcos();
	void terminar();
	void buscar(int n);
	int agregar(int a);
	void pintar();
	caja1 *Lugar_agregado(){return lugar_agregado;}
	caja1 *iniciar_recorrido();
	caja1 *recorrer();
};

/*
	CONSTRUCTOR DE LA CLASE
*/

Lista_arcos::Lista_arcos(){
	principio=NULL;
	anterior=NULL;
	lugar_agregado=NULL;
	encontrado=false;
	donde=VACIO;
}

/*
	COPIA DEL CONTRUCTOR DE LISTA ARCOS
*/

void Lista_arcos::nuevo(){
	principio=NULL;
	anterior=NULL;
	lugar_agregado=NULL;
	encontrado=false;
	donde=VACIO;
}
/*
	DESTRUCTOR DE LA CLASE DE LISTA ARCOS
*/
Lista_arcos::~Lista_arcos(){
}

/*
	COPIA DEL DESTRUCTOR DE LA CLASE  DE LISTA ARCOS
*/

void Lista_arcos::terminar(){
}

/*
	FUNCION BUSCAR
*/

void Lista_arcos::buscar(int a){
	caja1 *p;

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
            lugar_agregado = p;
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
		lugar_agregado = p;
	}
}

/*
	FUNCION AGREGAR DE LISTA ARCOS
*/

int Lista_arcos::agregar(int a){
	caja1 *p;

	buscar(a);

	if(encontrado==true){return(0);} //si encuentra un elemento igual no deja que se agregue a la lista

	p = new caja1;
	p->num_nodo = a;

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
	lugar_agregado = p;
	return(1);
}

/*
	FUNCION PINTAR DE LISTA ARCOS
*/
void Lista_arcos::pintar(){
    caja1*p;
    p=principio;

    while(p){
    	cout<<"Salientes: ";
    	cout<<" "<<p->num_nodo<<" ";

    	//cout<<"Longitud: ";
    	cout<<"(";
    	cout<<p->longitud<<") ";
        p=p->siguiente;
        cout<<endl;
    }
}

/*
	FUNCION INICIAR RECORRIDO DE CLASE LISTA ARCOS
*/
caja1 *Lista_arcos::iniciar_recorrido(){
	caja1*p;
	lugar=principio;
}

/*
	FUNCION RECORRER DE CLASE LISTA ARCOS
*/

caja1 *Lista_arcos::recorrer(){
	caja1*p;
	p=lugar;
	if(p==NULL) return(NULL);
	lugar=lugar->siguiente;

	return(p);
}
//*************************************************** = ESTRUCTURA CAJA 2 = ******************************************************************

struct caja2{
	int num_nodo, bandera,  cuantos, totales, conectivo, valor_de_verdad;//, *salientes; //checar como se usa salientes porque no estoy segura de donde deberia de usarse
	float ruta_corta;
	Lista_arcos salientes;
	caja2 *siguiente,*anterior;
	caja3 *direccion;
	//int l;
	string texto;
	//nuevo para SE
};

//****************************************************** = LISTA NODOS = *********************************************************************

class Lista_nodos{
	caja2 *principio,*anterior,*lugar_agregado;

	Donde donde;

public:
    bool encontrado;
	Lista_nodos();
	void nuevo();
	~Lista_nodos();
	void terminar();
	void buscar(int n);
	caja2* Lugar_agregado(){return lugar_agregado;}
	int agregar(int a);
	void pintar();
};
/*
	CONSTRUCTOR DE LA CLASE LISTA NODOS
*/
Lista_nodos::Lista_nodos(){
	principio=NULL;
	anterior=NULL;
	lugar_agregado=NULL;
	encontrado=false;
	donde=VACIO;
}
/*
	DESCONSTRUCTOR DE LA CLASE LISTA NODOS
*/
Lista_nodos::~Lista_nodos(){ }
/*
	COPIA DEL CONSTRUCTOR DE LA CLASE LISTA NODOS
*/
void Lista_nodos::nuevo(){
	principio=NULL;
	anterior=NULL;
	lugar_agregado=NULL;
	encontrado=false;
	donde=VACIO;
}
/*
	COPIA DEL DECONSTRUCTOR DE LA CLASE LISTA NODOS
*/
void Lista_nodos::terminar(){ }
/*
	FUNCION BUSCAR DE LA CLASE LISTA NODOS
*/
void Lista_nodos::buscar(int a){
	caja2 *p;

	 if(principio==NULL){
    	encontrado=false;
    	donde=VACIO;
    	anterior=NULL;
    	lugar_agregado=NULL;
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
				donde=ENMEDIO;  }
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
		lugar_agregado = p;
	}
}
/*
	FUNCION AGREGAR DE LA CLASE LISTA NODOS
*/
int Lista_nodos::agregar(int a){
	caja2 *p;
	Lista_arcos q;

	buscar(a);

	if(encontrado==true) return(0); //si encuentra un elemento igual no deja que se agregue a la lista

	p=new caja2;
	p->num_nodo = a; //nodos
    p->bandera=0;
    p->ruta_corta=0.0;
    p->anterior=NULL;
	p->salientes.nuevo(); //crear salientes tipo lista arco

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
	lugar_agregado = p;
	return(1);
}
/*
	FUNCION PINTAR DE LA CLASE LISTA NODOS
    Lista nodos manda llamar lista arcos que esta pinta toda la lista (salientes) y grafico llama a este pintar
*/

void Lista_nodos::pintar(){
    caja2*p;
    p=principio;

    while(p){
    	cout<<"Numero de nodo :";
		cout<<p->num_nodo<<endl;

		(p->salientes).pintar();
    	p=p->siguiente;
    	cout<<endl;
    }
}

//*************************************************** = ESTRUCTURA CAJA3 = *******************************************************************

struct caja3{
	caja2*direccion_nodo;
	float ruta_corta, valor;
	caja3 *siguiente, *anterior;
};

//***************************************************** = CLASE LISTA = **********************************************************************

class Lista{
	caja3* principio, *final, *anterior, *lugar_agregado;
	bool encontrado;
	Donde donde;
public:
	Lista();
	~Lista();
void nuevo();
void terminar();
void buscar(float a);
void agregar(caja2*p);
void pintar();
caja2* sacar(); //saca la dieccion del nodo
caja3* Lugar_agregado(){ return lugar_agregado;}
void ajustar(caja3 *p, float a);
};
/*
	CONSTRUCTOR DE LA CLASE LISTA
*/
Lista::Lista(){
	principio=NULL;
	final=NULL;
	anterior=NULL;
	lugar_agregado=NULL;
	encontrado=false;
	donde=VACIO;
}
/*
	COPIA DEL CONSTRUCTOR DE LA CLASE LISTA
*/
void Lista::nuevo(){
	principio=NULL;
	final=NULL;
	anterior=NULL;
	lugar_agregado=NULL;
	encontrado=false;
	donde=VACIO;
}
/*
	DESCONSTRUCTOR DE LA CLASE LISTA
*/
Lista::~Lista(){
    caja3*p;
    while(principio){
        p=principio;
        principio=p->siguiente;
        delete p;
    }
}
/*
	COPIA DEL DESCONSTRUCTOR DE LA CLASE LISTA
*/
void Lista::terminar(){
 caja3*p;
    while(principio){
        p=principio;
        principio=p->siguiente;
        delete p;
    }
}
/*
	FUNCION BUSCAR DE LA CLASE LISTA
*/
//CAMBIAR
void Lista::buscar(float a){
    caja3*p;

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
			encontrado=true;

			if(principio==p){
				donde=PRINCIPIO;

			}else if(p->siguiente==NULL){
				donde=FINAL;

			}else{
				donde=ENMEDIO;
			}
				return;
			}else if(p->valor<a){
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
        }
	encontrado=false;
	donde=FINAL;
	lugar_agregado=p;
}
/*
	FUNCION AGREGAR DE LA CLASE LISTA
*/

void Lista::agregar(caja2* a){

	caja3 *p;

	p=new caja3;
    p->direccion_nodo = a;

	if(donde==VACIO){  //si no se puede encontrar el lugar donde esta el elemento se le asigna el lugar del principio
		principio=p;
		p->siguiente=NULL;
		p->anterior=NULL;
		final=p;

	}else if(donde==PRINCIPIO){
		p->siguiente=principio;
		p->anterior=NULL;
		principio->anterior=p;
		principio=p;

	}else if(donde==FINAL){
		p->siguiente=NULL;
		p->anterior=final;
		final->siguiente=p;
		final=p;

	}else{
        p->siguiente=anterior->siguiente;
        p->anterior=anterior;
        anterior->siguiente=p;
        p->siguiente->anterior=p;

	}
	lugar_agregado=p;
}

caja2* Lista::sacar(){
	//Es analoga a la funcion borrar
	//En lugar de eliminar como penultimo paso, guardamos temporalmente el nodo
	//La funcion devuelve el nodo guardado
	//Al terminar la funcion el nodo es eliminado automaticamente+

	caja2 *p;
	caja3 *q;

	if(!principio) return NULL;

	q=principio;
	principio=principio->siguiente;

	if(principio){
		principio->anterior =NULL;
	}

	p= q->direccion_nodo;
	p->direccion=NULL;

	delete q;
    return p;
}

//*********************************************** = SISTEMA EXPERTO = ********************************************************************

class SE{
    Lista_nodos A;
    Lista B;

    int resultado;
public:

    SE();
    ~SE();
    void agregar_nodo(int , int b, int c,string s); //recibe el numero de nodo, la bandera y el tipo de conectivo
    void agregar_salientes(int a, int b,int c); //recibe el nodo inicial, nodo final y el valor de verdad
    void pintar();
    int  es_redundante(caja2 *p);
    void procesar(caja2* p);
    void procesarSE();
    void hacer_pregunta(caja2*p);
    void resultados();
};

SE::SE(){
	resultado=0;

}

SE::~SE(){

}

void SE::agregar_nodo(int a, int b, int c, string s){
  caja2*p;
  A.buscar(a);
  if(A.encontrado == true) return;

  A.agregar(a);
  p=A.Lugar_agregado();
  p->bandera = b;
  p->conectivo=c;
  p->cuantos=0;
  p->totales=0;
  p->valor_de_verdad=-1;
  p->texto=s;
}

void SE::agregar_salientes(int a, int b, int c){
  caja1 *p;
  caja2 *q;

  A.buscar(a);

  q=A.Lugar_agregado();
  (q->salientes).agregar(b);
  p= (q->salientes).Lugar_agregado();
  p->valor=c;
  A.agregar(b);
  q=A.Lugar_agregado();
  p->direccion_nodo=q;
}

int SE::es_redundante(caja2 *p){
  caja1 *q;
  (p->salientes).iniciar_recorrido();
  q=(p->salientes).recorrer();

  while(q){
    if((q->direccion_nodo)->valor_de_verdad=1){
      return 0;
      q=(p->salientes).recorrer();//{
        //cuetar este return 1;
        //}
      }
    }
    return 1; //checar si en vez de aqui se debe de poner una llave arriba
}

void SE::procesar(caja2 *p){
//void procesar(caja2 *p){ //no se que caja es
caja3*q;

  q->valor=p->valor_de_verdad;
    //nota: depende del arco para ver donde llega
    while(p){
  if(q->valor==1){ //se cambia el valor
    if(q->valor== -1){
      q->valor =0;
    }else{
      q->valor=1; //si tiene valor =0 se hace uno
    }
	//valor va a llegar a un nodo con direccion
  if((q->direccion_nodo)->valor_de_verdad != -1) {  //del tipo de conectipo depende lo que voy a hacer , en este caso al ser -1 este se tiene que responder
        q=q->siguiente; //falta instruccion para que hacia mas abajo no siga haciendo nada //checar esta nota porque me confunde poco
        continue;
  }

  if((q->direccion_nodo)->conectivo ==0){  //supone que el conectivo es un OR
      if(q->valor==1){
      (q->direccion_nodo)->valor_de_verdad = 1; //puede sig que ya se llego a la conclusion
        if((q->direccion_nodo)->bandera==2){
          resultado = (q->direccion_nodo)->num_nodo;
          return;//se llego a una conclusion //  a resultado se le puso un  numero
        }else{
          B.agregar(q->direccion_nodo); // sino se llego a una concluscion, llego a un intermedio se agrega a la lista el intermedio
        }

      }else{ //el valor= 0 // caso contrario
        (q->direccion_nodo)->cuantos++; //se cuentas los negativos//contador especialmente para negativos

        if((q->direccion_nodo)->totales == (q->direccion_nodo)->cuantos){ //se compara el numero de cuandos a numero de totales
            (q->direccion_nodo)->valor_de_verdad =0;
            B.agregar(q->direccion_nodo); //se agrega para ser procesado despues
        }
        //si no fuera igual se deja
        else{ //conectivo==1 ^ (y)
          if(q->valor==1){
            (q->direccion_nodo)->cuantos++;
              if((q->direccion_nodo)->cuantos == (q->direccion_nodo->totales)){
                (q->direccion_nodo)->valor_de_verdad=1;
                  if((q->direccion_nodo)->bandera==2){
                    resultado=(q->direccion_nodo)->num_nodo;
                    return; }
                    else{
                    B.agregar(q->direccion_nodo);
                    }
                }else{ //chechar a donde se conecta este else {}
                (q->direccion_nodo)->valor_de_verdad = 0;
                B.agregar(q->direccion_nodo);
                }
              }
            q=q->siguiente;
          }
        }
      }
    }
  }
}

void SE::procesarSE(){
    caja2* p;
    caja2* q;
	while(p){
	if((p->bandera==0) && (p->valor_de_verdad == -1)){
		if((es_redundante(p)) == 1){ //NO
			hacer_pregunta(p); //se guarda respuesta // p->valor_de_verdad va a adquirir valor
		if(p->valor_de_verdad == 2){
			p=p->siguiente;
		}else{
			procesar(p);
			q=B.sacar();
			while(q){ //va a jalar hasta que q sea nulo
				procesar(q);
				q=B.sacar();
				}
			}
		}
	}
	p=p->siguiente;
	if(p->bandera!=0) return;
    }
}

void SE::resultados(){
    int conclusion; //por mientras se donde ponerlo
	if(conclusion!=0){ //bandera =2
		cout<<"no se pudo llegar a una conclusion concreta"<<endl;
		//se recorre hasta llegar a la seccion de conclusiones y se imprimen
		//las conclusiones con -1 como posibles soluciones/candidatos
	}
}

void SE::hacer_pregunta(caja2*p){
	cout<<p->texto<<endl;
	cin>>p->valor_de_verdad;
	//return p->resp;
 //solo hacer la pregunta sacandola del arreglo de strings
     //checar si puedo hacer un arreglo tipo punteros caja2 para asignarles los 5 datos
}

//NOTA: ver si puedo asignarle los elementos a cada parte del arreglo ej relacionar la respuesta de "responder pregunta" hacia las conclusiones y asi

int main(){
	SE s;
	/*
	c[35]={"tiene pelo?", "da leche?","tiene plumas?","vuela?","pone huevos?","come carne?","tiene dientes agudos?","tiene garras?",
     				"tiene ojos que miren hacia adeltante?","tiene pezuñas?","rumia?","tiene color leonado?","tiene manchas oscuras?",
     				"tiene franjas negras?","tiene patas largas?","tiene cuello largo?","es de color blanco?","es blanco y negro?","nada?",
     				"es mamifero","es una ave","es carnivoro","es un angulado","d1","d2","d3","d4","d5","es una onza","es un tigre","es una jirafa",
     				"es una cebra","es un avestruz","es un pinguino","es un alabatros"}; */
    s.agregar_nodo(1,0,0,"tiene pelo?");
    s.agregar_salientes(1,20,1);

    s.agregar_nodo(2,0,0,"da leche?");
    s.agregar_salientes(2,20,1);

	s.agregar_nodo(3,0,0,"tiene plumas?");
	s.agregar_salientes(3,21,1);
	s.agregar_salientes(3,24,1);

	s.agregar_nodo(4,0,0, "vuela?");
	s.agregar_salientes(4,27,1);
	s.agregar_salientes(4,33,0);
	s.agregar_salientes(4,34,0);
	s.agregar_salientes(4,21,1);
	s.agregar_salientes(4,24,1);
	s.agregar_salientes(4,28,1);

	s.agregar_nodo(5,0,0,"pone huevos?");
	s.agregar_salientes(5,33,1);
	s.agregar_salientes(5,34,1);
	s.agregar_salientes(5,35,1);

    s.agregar_nodo(6,0,0,"come carne?");

    s.agregar_nodo(7,0,0,"tiene dientes agudos?");
    s.agregar_nodo(8,0,0,"tiene garras?");
    s.agregar_nodo(9,0,0,"tiene ojos que miren hacia adelante?");
    s.agregar_nodo(10,0,0,"tiene pezuñas?");
    s.agregar_nodo(11,0,0,"rumia?");
    s.agregar_nodo(12,0,0,"tiene color leonado?");
    s.agregar_nodo(13,0,0,"tiene manchas oscuras?");
    s.agregar_nodo(14,0,0,"tiene franjas negras?");
    s.agregar_nodo(15,0,0, "tiene patas largas");
    s.agregar_nodo(16,0,0,"tiene cuello largo?");
    s.agregar_nodo(17,0,0,"es de color blanco?");
    s.agregar_nodo(18,0,0,"es blanco y negro?");
    s.agregar_nodo(19,0,0,"nada?");
    s.agregar_nodo(20,1,0,"es un mamifero");
    s.agregar_nodo(21,1,0,"es una ave");
    s.agregar_nodo(22,1,0,"es un carnivoro");
    s.agregar_nodo(23,1,0, "es un angulado");
    s.agregar_nodo(24,1,0,"d1");
    s.agregar_nodo(25,1,1,"d2");
    s.agregar_nodo(26,1,1,"d3");
    s.agregar_nodo(27,1,1,"d4");
    s.agregar_nodo(28,1,1,"d5");
    s.agregar_nodo(29,2,1,"es una onza");
    s.agregar_nodo(30,2,1,"es un tigre");
    s.agregar_nodo(31,2,1,"es una jirafa");
    s.agregar_nodo(32,2,1,"es una cebra");
    s.agregar_nodo(33,2,1,"es un avestruz");
    s.agregar_nodo(34,2,1,"es un pinguino");
    s.agregar_nodo(35,2,1,"es alabatros");
    /*
	s.agregar_nodo(1,0,0);
	// s.agregar_arco(20,1); //saliente
    s.agregar_nodo(2,0,0);
	s.agregar_nodo(3,0,0);
	s.agregar_nodo(4,0,0);
	s.agregar_nodo(5,0,0);
    s.agregar_nodo(6,0,0);
    s.agregar_nodo(7,0,0);
    s.agregar_nodo(8,0,0);
    s.agregar_nodo(9,0,0);
    s.agregar_nodo(10,0,0);
    s.agregar_nodo(11,0,0);
    s.agregar_nodo(12,0,0);
    s.agregar_nodo(13,0,0);
    s.agregar_nodo(14,0,0);
    s.agregar_nodo(15,0,0);
    s.agregar_nodo(16,0,0);
    s.agregar_nodo(17,0,0);
    s.agregar_nodo(18,0,0);
    s.agregar_nodo(19,0,0);
    s.agregar_nodo(20,1,0);
    s.agregar_nodo(21,1,0);
    s.agregar_nodo(22,1,0);
    s.agregar_nodo(23,1,0);
    s.agregar_nodo(24,1,0);
    s.agregar_nodo(25,1,1);
    s.agregar_nodo(26,1,1);
    s.agregar_nodo(27,1,1);
    s.agregar_nodo(28,1,1);
    s.agregar_nodo(29,2,1);
    s.agregar_nodo(30,2,1);
    s.agregar_nodo(31,2,1);
    s.agregar_nodo(32,2,1);
    s.agregar_nodo(33,2,1);
    s.agregar_nodo(34,2,1);
    s.agregar_nodo(35,2,1);
    */
	s.procesarSE();
	//S.resultados();
	//TENGO QUE AGREGAR 36 NODOS HOLY SHIT
return 0;
}
