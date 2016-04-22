#include <iostream>
struct caja2;
struct caja3;
class Lista_arcos;
struct caja1{
    int num_nodo;
    caja2 *direccion_nodo;
    float longitud;
    caja1 *siguiente;
};
struct caja2{
    int num_nodo;
    int bandera;
    float ruta_corta;
    caja2 * anterior;
    caja3 * direccion;
    Lista_arcos *salientes;
    caja2 *siguiente;
};
struct caja3{
    caja2* direccion_nodo;
    float ruta_corta;
    caja3 *anterior,*siguiente;
};
class Lista_arcos{
    caja1 *anterior,*principio,*lugar_agregado,*lugar;
    int encontrado,donde;
    enum encontrado{SI,NO};
    enum donde{VACIO,PRINCIPIO,ENMEDIO,FINAL};
public:
    Lista_arcos();
    void nuevo();
    ~Lista_arcos();
    void terminar();
    void buscar(int);
    int agregar(int);
    void pintar();
    caja1* obtener_lugar_agregado();
    void iniciar_recorrido(){lugar=principio;};
    caja1* recorrer();

};
Lista_arcos::Lista_arcos(){
    principio = NULL;
    anterior = NULL;
    encontrado = NO;
    donde = VACIO;
}
void Lista_arcos::nuevo(){
    principio = NULL;
    anterior = NULL;
    encontrado = NO;
    donde = VACIO;
}
Lista_arcos::~Lista_arcos(){
    caja1 *p;
    while(principio){
        p=principio;
        principio = p->siguiente;
        delete(p);
    }
    anterior = NULL;
    lugar_agregado = NULL;
    encontrado = NO;
    donde = VACIO;
}
void Lista_arcos::terminar(){
    caja1 *p;
    while(principio){
        p=principio;
        principio = p->siguiente;
        delete(p);
    }
    anterior = NULL;
    lugar_agregado = NULL;
    encontrado = NO;
    donde = VACIO;
}
void Lista_arcos::buscar(int a){
    caja1 *p;
    if(!principio){
        encontrado = NO;
        donde = VACIO;
        anterior = NULL;
        return;
    }
    p = principio;
    while(p){
        if(p->num_nodo == a){
            encontrado = SI;
            if(principio == p) donde = PRINCIPIO;
            else if(p->siguiente == NULL) donde = FINAL;
                 else donde = ENMEDIO;
            return;
        }else if(p->num_nodo < a){
            anterior = p;
            p = p->siguiente;
        }else{
            encontrado = NO;
            if(principio == p) donde = PRINCIPIO;
            else donde = ENMEDIO;
            return;
        }
    }
    lugar_agregado = p;
    encontrado = NO;
    donde = FINAL;
}
int Lista_arcos::agregar(int a){
    caja1 *p;
    buscar(a);
    if(encontrado == SI) return 0;
    p = new caja1;
    p->num_nodo = a;
    if(donde == VACIO){
        p->siguiente = NULL;
        principio = p;
    }else if(donde == PRINCIPIO){
        p->siguiente = principio;
        principio = p;
    }else if(donde == FINAL){
        p->siguiente = NULL;
        anterior->siguiente = p;
    }else{
        p->siguiente = anterior->siguiente;
        anterior->siguiente = p;
    }
    lugar_agregado = p;
    return 1;
}

void Lista_arcos::pintar(){
    caja1 *p;
    p = principio;
    while(p){
        std::cout << "(" << p->num_nodo << "," << p->longitud << ")";
        p = p->siguiente;
    }
}
caja1* Lista_arcos::obtener_lugar_agregado(){
    return lugar_agregado;
}
caja1* Lista_arcos::recorrer(){
    if(lugar==NULL) return NULL;
    caja1* p;
    p=lugar;
    lugar = lugar->siguiente;
    return p;
}class Lista{
    caja3 *principio, *anterior, *final, *lugar_agregado;
    int encontrado, donde;
    enum encontrado{SI,NO};
    enum donde{VACIO,PRINCIPIO,ENMEDIO,FINAL};
public:
    Lista();
    ~Lista();
    void nuevo();
    void terminar();
    void buscar(float);
    void agregar(caja2*,float);
    void pintar();
    caja2* sacar();
    caja3* obtener_lugar_agregado();
    void ajustar(caja3*,float);
    void borrar(float);
};
Lista::Lista(){
    principio = NULL;
    anterior = NULL;
    final = NULL;
    encontrado = NO;
    donde = VACIO;
}
void Lista::nuevo(){
    principio = NULL;
    anterior = NULL;
    final = NULL;
    encontrado = NO;
    donde = VACIO;
}
Lista::~Lista(){
    caja3 *p;
    while(principio){
        p = principio;
        principio = p->siguiente;
        delete(p);
    }
}
void Lista::terminar(){
    caja3 *p;
    while(principio){
        p = principio;
        principio = p->siguiente;
        delete(p);
    }
    anterior = NULL;
    final = NULL;
    encontrado = NO;
    donde = VACIO;
}
void Lista::buscar(float a){
    caja3 *p;
    if(!principio){
        encontrado = NO;
        donde = VACIO;
        anterior = NULL;
        lugar_agregado = p;
        return;
    }
    p = principio;
    while(p){
        if(p->ruta_corta == a){
            encontrado = SI;
            if(principio == p) donde = PRINCIPIO;
            else if(p->siguiente == NULL) donde = FINAL;
                 else donde = ENMEDIO;
            lugar_agregado = p;
            return;
        }else if(p->ruta_corta < a){
            anterior = p;
            p = p->siguiente;
        }else{
            encontrado = NO;
            if(principio == p) donde = PRINCIPIO;
            else donde = ENMEDIO;
            return;
        }
    }
    encontrado = NO;
    donde = FINAL;
}
void Lista::agregar(caja2* q, float a){
    caja3 *p;
    buscar(a);
    p = new caja3;
    p->direccion_nodo = q;
    p->ruta_corta = a;
    if(donde == VACIO){
        p->siguiente = NULL;
        p->anterior = NULL;
        principio = p;
        final = p;
    }else if(donde == PRINCIPIO){
        p->siguiente = principio;
        p->anterior = NULL;
        principio->anterior = p;
        principio = p;
    }else if(donde == FINAL){
        p->siguiente = NULL;
        p->anterior = final;
        anterior->siguiente = p;
        final = p;
    }else{
        p->siguiente = anterior->siguiente;
        p->anterior = anterior;
        anterior->siguiente->anterior = p;
        anterior->siguiente = p;
    }
    lugar_agregado = p;
    return;
}
void Lista::pintar(){
    caja3* p;
    p = principio;
    std::cout << "num_nodo + ruta_corta" << std::endl;
    while(p){
        std::cout << p->direccion_nodo->num_nodo << "," << p->ruta_corta << std::endl;
        p = p->siguiente;
    }
}
caja3* Lista::obtener_lugar_agregado(){
    return lugar_agregado;
}
void Lista::ajustar(caja3* p, float a){
    caja3* q = p;
    borrar(a);
    agregar(p->direccion_nodo,a);
    delete p;
}
caja2* Lista::sacar(){
    caja3* p;
    if(principio == NULL) return NULL;
    p = principio;
    principio = p->siguiente;
    return p->direccion_nodo;
    delete(p);
}
void Lista::borrar(float a){
    caja3 *p;
    buscar(a);
    if(encontrado == NO) return;
    if(donde == PRINCIPIO){
        p=principio;
        principio = p->siguiente;
        principio->anterior = NULL;
    }else if(donde == FINAL){
        p=final;
        final=anterior;
        final->siguiente=NULL;
    }else{
        p=anterior->siguiente;
        anterior->siguiente = p->siguiente;
        p->siguiente->anterior = anterior;
    }
    delete(p);
    return;
}
class Lista_nodos{
    caja2 *anterior,*principio,*lugar_agregado;
    int encontrado,donde;
    enum encontrado{SI,NO};
    enum donde{VACIO,PRINCIPIO,ENMEDIO,FINAL};
public:
    Lista_nodos();
    void nuevo();
    ~Lista_nodos();
    void terminar();
    void buscar(int);
    int agregar(int);
    void pintar();
    caja2* obtener_lugar_agregado();
};
Lista_nodos::Lista_nodos(){
    principio = NULL;
    anterior = NULL;
    encontrado = NO;
    donde = VACIO;
}
void Lista_nodos::nuevo(){
    principio = NULL;
    anterior = NULL;
    encontrado = NO;
    donde = VACIO;
}
Lista_nodos::~Lista_nodos(){
    caja2 *p;
    while(principio){
        p=principio;
        delete(p->salientes);
        principio = p->siguiente;
        delete(p);
    }
    anterior = NULL;
    encontrado = NO;
    donde = VACIO;
}
void Lista_nodos::terminar(){
    caja2 *p;
    while(principio){
        p=principio;
        principio = p->siguiente;
        delete(p);
    }
    anterior = NULL;
    lugar_agregado = NULL;
    encontrado = NO;
    donde = VACIO;
}
void Lista_nodos::buscar(int a){
    caja2 *p;
    if(!principio){
        encontrado = NO;
        donde = VACIO;
        anterior = NULL;
        lugar_agregado = p;
        return;
    }
    p = principio;
    while(p){
        if(p->num_nodo == a){
            encontrado = SI;
            if(principio == p) donde = PRINCIPIO;
            else if(p->siguiente == NULL) donde = FINAL;
                 else donde = ENMEDIO;
            lugar_agregado = p;
            return;
        }else if(p->num_nodo < a){
            anterior = p;
            p = p->siguiente;
        }else{
            encontrado = NO;
            if(principio == p) donde = PRINCIPIO;
            else donde = ENMEDIO;
            lugar_agregado = p;
            return;
        }
    }
    lugar_agregado = p;
    encontrado = NO;
    donde = FINAL;
}
int Lista_nodos::agregar(int a){
    caja2 *p;
    buscar(a);
    if(encontrado == SI) return 0;
    p = new caja2;
    p->num_nodo = a;
    p->bandera = 0;
    p->ruta_corta = 0;
    p->anterior = NULL;
    p->direccion = NULL;
    p->salientes = new Lista_arcos;
    if(donde == VACIO){
        p->siguiente = NULL;
        principio = p;
    }else if(donde == PRINCIPIO){
        p->siguiente = principio;
        principio = p;
    }else if(donde == FINAL){
        p->siguiente = NULL;
        anterior->siguiente = p;
    }else{
        p->siguiente = anterior->siguiente;
        anterior->siguiente = p;
    }
    lugar_agregado = p;
    return 1;
}
void Lista_nodos::pintar(){
    caja2 *p;
    p = principio;
    while(p){
        std::cout << "Numero de nodo: "<< p->num_nodo << std::endl;
        std::cout << "salientes: ";
        (p->salientes)->pintar();
        std::cout << std::endl;
        p = p->siguiente;
    }
}
caja2* Lista_nodos::obtener_lugar_agregado(){
    return lugar_agregado;
}
class Grafica{
    Lista_nodos *A;
    Lista *B;
    int existe_ruta;
public:
    Grafica();
    ~Grafica();
    void agregar_arco(int,int,float);
    void pintar_rutacorta();
    void calcular_ruta(int,int);
};
Grafica::Grafica(){
    existe_ruta = 0;
    A = new Lista_nodos();
    B = new Lista();
}
Grafica::~Grafica(){
    existe_ruta = 0;
    delete(A);
    delete(B);
}
void Grafica::calcular_ruta(int a,int b){
    caja1 *p;
    caja2 *q;
    A->agregar(a);
    q = A->obtener_lugar_agregado();
    while(q){
        q->bandera = 2;
        if(q->num_nodo == b){
            existe_ruta = 1;
            delete B;
            B = new Lista();
            while(q){
                B->agregar(q,q->ruta_corta);
                q = q->anterior;
            }
            return;
        }
        q->salientes->iniciar_recorrido();
        p = q->salientes->recorrer();
        while(p){
            if(p->direccion_nodo->bandera == 0){
                p->direccion_nodo->bandera = 1;
                p->direccion_nodo->anterior = q;
                p->direccion_nodo->ruta_corta = q->ruta_corta + p->longitud;
                B->agregar(p->direccion_nodo,q->ruta_corta+p->longitud);
                p->direccion_nodo->direccion = B->obtener_lugar_agregado();
            }else if(p->direccion_nodo->bandera == 1 && ((q->ruta_corta + p->longitud) < p->direccion_nodo->ruta_corta)){
                p->direccion_nodo->anterior = q;
                p->direccion_nodo->ruta_corta = q->ruta_corta + p->longitud;
                B->ajustar(p->direccion_nodo->direccion,q->ruta_corta + p->longitud);
            }
            p = q->salientes->recorrer();
        }
        q = B->sacar();
    }
}
void Grafica::pintar_rutacorta(){
    if(existe_ruta == 1) B->pintar();
    else std::cout << "no hay ruta entre esos 2 nodos" << std::endl;
}
void Grafica::agregar_arco(int a,int b,float lon){
    caja1 *p;
    caja2 *q,*r;
    A->agregar(a);
    q = A->obtener_lugar_agregado();
    (q->salientes)->agregar(b);
    p = (q->salientes)->obtener_lugar_agregado();
    A->agregar(b);
    r = A->obtener_lugar_agregado();
    p->direccion_nodo = r;
    p->longitud = lon;
}
int main(){
    return 0;
}
