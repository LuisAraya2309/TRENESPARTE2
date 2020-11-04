
#include<string.h>
#include<string>
#include<sstream>
#include<fstream>
#include<iostream>
#include <stdlib.h>
#pragma once
using namespace std;

class NodoAVLTren{  
    public: 
    int codTren;
	string nombre;
	int cantAsientos;
    NodoAVLTren *izquierda;  
    NodoAVLTren *derecha;  
    int FB;  
};  

//Funcion para obtener el balance de un nodo
  
int FB(NodoAVLTren *N){  
    if (N == NULL)  
        return 0;  
    return N->FB;  
}
int balanceo(NodoAVLTren *N){  
    if (N == NULL)  
        return 0;  
    return FB(N->izquierda) - FB(N->derecha);  
}  
  
//Obtiene el numero mayor para identificar a la hora de ingresar en el arbol
int numeroMayor(int a, int b); 

int numeroMayor(int a, int b){  
    return (a > b)? a : b;  
}  
 
NodoAVLTren* newNodoAVLTren(int codTren,string pnombre, int cantAsientos){  
    NodoAVLTren *nodoAVLTren = new NodoAVLTren(); 
    nodoAVLTren->codTren = codTren;
	nodoAVLTren->nombre = pnombre;
	nodoAVLTren->cantAsientos= cantAsientos;  
    nodoAVLTren->izquierda = NULL;  
    nodoAVLTren->derecha = NULL;  
    nodoAVLTren->FB = 1; 
    return(nodoAVLTren);  
}  
   
NodoAVLTren *RotacionDerecha(NodoAVLTren *y)  {  
    NodoAVLTren *raizN = y->izquierda;  
    NodoAVLTren *T2 = raizN->derecha;  
  
    raizN->derecha = y;  
    y->izquierda = T2;  
  
    y->FB = numeroMayor(FB(y->izquierda), 
    FB(y->derecha)) + 1;  
    raizN->FB = numeroMayor(FB(raizN->izquierda), 
    FB(raizN->derecha)) + 1;
    
    return raizN;  
}  
   
NodoAVLTren *RotacionIzquierda(NodoAVLTren *x) {  
    NodoAVLTren *raizN = x->derecha;  
    NodoAVLTren *T2 = raizN->izquierda;  
   
    raizN->izquierda = x;  
    x->derecha = T2;  
   
    x->FB = numeroMayor(FB(x->izquierda),     
    FB(x->derecha)) + 1;  
    raizN->FB = numeroMayor(FB(raizN->izquierda),  
    FB(raizN->derecha)) + 1;  
  
    return raizN;  
}  
  

NodoAVLTren* insertarnodoAVLTren(NodoAVLTren* nodo, int codTren,string nombre, int cantAsientos)  {  
	//Si la raiz es nula
    if (nodo == NULL){
    	return(newNodoAVLTren(codTren,nombre,cantAsientos));  
	}//else
	if (codTren < nodo->codTren){
    	nodo->izquierda = insertarnodoAVLTren(nodo->izquierda, codTren ,nombre);  
	}else if (codTren > nodo->codCiudad){
    	nodo->derecha = insertarnodoAVLTren(nodo->derecha, codTren,nombre);  
	}else{
		return nodo;  
	}   
    nodo->FB = 1 + numeroMayor(FB(nodo->izquierda),  
    FB(nodo->derecha));  
  
    int balance = balanceo(nodo);  //Esta variable sera la del balance
    
    //Casos de las rotaciones
    //ROTACION IZQUIERDA 
    if (balance > 1 && codTren < nodo->izquierda->codTren){
    	return RotacionDerecha(nodo);  
	}
    // ROTACION DERECHA
    if (balance < -1 && codTren > nodo->derecha->codTren){
    	return RotacionIzquierda(nodo);  
	} 
    //ROTACION DOBLE IZQUIERDA 
    if (balance > 1 && codTren > nodo->izquierda->codTren){  
        nodo->izquierda = RotacionIzquierda(nodo->izquierda);  
        return RotacionDerecha(nodo);  
    } 
    //ROTACION DOBLE DERECHA
    if (balance < -1 && codTren < nodo->derecha->codTren){  
        nodo->derecha = RotacionDerecha(nodo->derecha);  
        return RotacionIzquierda(nodo);  
    }  
  
    return nodo;  
} 


bool ExisteTren(NodoAVLTren *R,int Tren){
	 if(R==NULL){
	 	return false;
	 }
	 else if(R->codTren==Tren){
	 	return true;
	 }
	 else if(Tren<=R->codTren){
	 	return ExisteCiudad(R->izquierda,Tren);
	 }
	 else{
	 	return ExisteCiudad(R->derecha,Tren);
	 }
}
