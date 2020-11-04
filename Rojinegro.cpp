#ifndef RN_H
#define	RN_H
#include <iostream>

using namespace std;

class NodoBinarioRN {
   public:

    NodoBinarioRN(int num, NodoBinarioRN *der = NULL, NodoBinarioRN *izq = NULL, NodoBinarioRN *papa = NULL):
        Hizq(izq), Hder(der), valor(num), padre(papa){}


    int valor;
    char color;
    NodoBinarioRN *padre;
    NodoBinarioRN *Hizq, *Hder;

    friend class ARN;
};

typedef NodoBinarioRN *pnodoRN;
typedef NodoBinarioRN *pNodoBinarioRN;

class ARN{
public:
    pNodoBinarioRN raiz;

    ARN():raiz(NULL){}

    void insercion(int key);
    void solucionarRojoRojo(pnodoRN nodoAux, int ladoH);
};

void PreordenR(NodoBinarioRN *R){
    
    if(R==NULL){
        return;
    }else{
        cout<<R->valor<< ", "<< R->color<<" - ";
        PreordenR(R->Hizq);
        PreordenR(R->Hder);
    }
}

void InordenR(NodoBinarioRN *R){

    if(R==NULL){
        return;
    }else{
        InordenR(R->Hizq);
        cout<<R->valor<< ", "<< R->color<<" - ";
        InordenR(R->Hder);
    }
}

void PostordenR(NodoBinarioRN *R){

    if(R==NULL){
        return;
    }else{
        PostordenR(R->Hizq);
        PostordenR(R->Hder);
        cout<<R->valor<<" - ";
    }
}

void ARN::insercion(int key){
  int ladohijo;
  pnodoRN hijo;
  pnodoRN ayudante;
  int bandera;
  if(!raiz){ // el arbol esta vacio cargando como raiz
    raiz = new NodoBinarioRN(key); 
    raiz->color='n';
  }
  else{ // el arbol no esta vacio buscando su lugar
    hijo = new NodoBinarioRN(key);
    hijo->color='r'; 
    ayudante=raiz;
    do{
      hijo->padre=ayudante, bandera=1;
      if(key<ayudante->valor){
        if(ayudante->Hizq) ayudante=ayudante->Hizq;
        else ayudante->Hizq=hijo, bandera=0, ladohijo=1;
      }
      else{
        if(ayudante->Hder) ayudante=ayudante->Hder;
        else ayudante->Hder=hijo, bandera=0, ladohijo=2;
      }
    }while(bandera==1);
    if(ayudante->color=='r') solucionarRojoRojo(ayudante, ladohijo);
  }
}

void ARN::solucionarRojoRojo(pnodoRN nodoAux, int ladoH){
  int ladohijo;
  pnodoRN abuelo; // en nodoAux traemos al padre, en ladoH 1 si el hijo rojo es el Hizq 2 si no
  pnodoRN tio;
  pnodoRN ayudante;
  abuelo=nodoAux->padre;
  if(abuelo->Hizq && abuelo->Hder){
    if(nodoAux==abuelo->Hizq) tio=abuelo->Hder;
    else tio=abuelo->Hizq;
    if(tio->color=='r'){ // caso uno y dos
      tio->color='n'; nodoAux->color='n';
      if(abuelo!=raiz) abuelo->color='r';
      if(abuelo->padre){
        ayudante=abuelo->padre;
        if(ayudante->Hizq==abuelo) ladohijo=1;
        else ladohijo=2;
        if(ayudante->color=='r') solucionarRojoRojo(ayudante, ladohijo);
      }
      return;
    }
  }
  if(ladoH==1 && abuelo->Hizq==nodoAux){ // caso tres
    nodoAux->color='n', abuelo->color='r';
    ayudante=nodoAux->Hder, nodoAux->Hder=abuelo, nodoAux->padre=abuelo->padre;
    abuelo->padre=nodoAux, abuelo->Hizq=ayudante;
    if(ayudante) ayudante->padre=abuelo;
    if(nodoAux->padre){
      ayudante=nodoAux->padre;
      if(ayudante->Hizq==nodoAux->Hder) ayudante->Hizq=nodoAux;
      else ayudante->Hder=nodoAux;
    }
    else raiz=nodoAux;
  }
  else if(ladoH==2 && abuelo->Hder==nodoAux){ // caso cuatro
    nodoAux->color='n', abuelo->color='r';
    ayudante=nodoAux->Hizq, nodoAux->Hizq=abuelo, nodoAux->padre=abuelo->padre;
    abuelo->padre=nodoAux, abuelo->Hder=ayudante;
    if(ayudante) ayudante->padre=abuelo;
    if(nodoAux->padre){
      ayudante=nodoAux->padre;
      if(ayudante->Hizq==nodoAux->Hizq) ayudante->Hizq=nodoAux;
      else ayudante->Hder=nodoAux;
    }
    else raiz=nodoAux;
  }
  else if(ladoH==2 && abuelo->Hizq==nodoAux){ // caso cinco
    tio=nodoAux->Hder, ayudante=tio->Hizq, abuelo->Hizq=tio;
    tio->padre=abuelo, tio->Hizq=nodoAux, nodoAux->padre=tio;
    nodoAux->Hder=ayudante;
    if(ayudante) ayudante->padre=nodoAux;
    solucionarRojoRojo(tio, 1);
  }
  else if(ladoH==1 && abuelo->Hder==nodoAux){ // caso seis
    tio=nodoAux->Hizq, ayudante=tio->Hder, abuelo->Hder=tio;
    tio->padre=abuelo, tio->Hder=nodoAux, nodoAux->padre=tio;
    nodoAux->Hizq=ayudante;
    if(ayudante) ayudante->padre=nodoAux;
    solucionarRojoRojo(tio, 2);
  }
}

#endif
