#ifndef _NODOTIPOTREN_H
#define	_NODOTIPOTREN_H
#include<string.h>
#include<string>
#include<sstream>
#include<fstream>
#include<iostream>
#include <stdlib.h>
using namespace std;
class NodoTipoTren {
   public:
	NodoTipoTren(int v,string pnombre){
		valor = v;
		nombre =pnombre;
		Hder = NULL;
		Hizq = NULL;
		siguiente = NULL;
		anterior = NULL;
	}
	
	//Atributos
    int valor;
    string nombre;
    NodoTipoTren *Hizq, *Hder, *siguiente, *anterior;

    friend class Pila;
    friend class Binario;
};

typedef NodoTipoTren *pNodoTipoTren;

bool ExistePais(pNodoTipoTren &R,int codTipTren){
	 if(R == NULL){
	 	return false;
	 }
	 else if(R->valor==codTipTren){
	 	return true;
	 }
	 else if(codTipTren<=R->valor){
	 	return ExistePais(R->Hizq,codTipTren);
	 }
	 else{
	 	return ExistePais(R->Hder,codTipTren);
	 }
}
void PreordenR(NodoTipoTren *R){
    
    if(R==NULL){
        return;
    }
	else{
        cout<<R->valor<<" -> ";
        PreordenR(R->Hizq);
        PreordenR(R->Hder);
    }
}

void InsertarNodoPais(pNodoTipoTren &tipoTrenes,int num, string nombre){
	if(tipoTrenes==NULL){
		tipoTrenes = new NodoTipoTren(num,nombre);
	}
	else{
		if(num<=tipoTrenes->valor){
			InsertarNodoPais(tipoTrenes->Hizq,num, nombre);
		}
		else{
			InsertarNodoPais(tipoTrenes->Hder,num, nombre);
		}
	}
}

pNodoTipoTren CargarTipoTrenes(){
	pNodoTipoTren tipoTrenes = NULL;
	ifstream archivo;
    string texto;
    archivo.open("TipoTren.txt",ios::in);
    if (archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    else{
    	while(!archivo.eof()){
    		getline(archivo,texto);
    		if(tipoTrenes==NULL){
    			int posPC = texto.find(";");
		        int codTipTren = atoi(texto.substr(0, posPC).c_str());
		        string nomTipTren = texto.substr(posPC + 1, texto.length());
    			tipoTrenes = new NodoTipoTren(codTipTren,nomTipTren);
			}
			else{
				int posPC = texto.find(";");
		        int codTipTren = atoi(texto.substr(0, posPC).c_str());
		        string nomTipTren = texto.substr(posPC + 1, texto.length());
		        if(ExistePais(tipoTrenes,codTipTren)){
		        	continue;
				}
				else{
					InsertarNodoPais(tipoTrenes,codTipTren,nomTipTren);
				}
			}
    		
    		
    		
    	}//llave del while
    	archivo.close();
	}
	return tipoTrenes;
}




#endif	

