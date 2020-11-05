#ifndef _NODOTIPOTREN_H
#define	_NODOTIPOTREN_H
#include<string.h>
#include<string>
#include<sstream>
#include<fstream>
#include<iostream>
#include <stdlib.h>
#include "TrenAVL.hpp"
using namespace std;
class NodoTipoTren {
   public:
	NodoTipoTren(int v,string pnombre){
		valor = v;
		nombre =pnombre;
		tren = NULL;
		Hder = NULL;
		Hizq = NULL;
		siguiente = NULL;
		anterior = NULL;
	}
	
	//Atributos
    int valor;
    string nombre;
    NodoAVLTren *tren;
    NodoTipoTren *Hizq, *Hder, *siguiente, *anterior;

    friend class Pila;
    friend class Binario;
};

typedef NodoTipoTren *pNodoTipoTren;


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
void ExisteTipoTren(pNodoTipoTren& R, int tipTren){
	if(R==NULL){
	 	return false;
	 }
	 else if(R->valor==tipTren){
	 	return true;
	 }
	 else if(Tren<=R->codTren){
	 	return ExisteTipoTren(R->Hizq,tipTren);
	 }
	 else{
	 	return ExisteTipoTren(R->Hder,tipTren);
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
		        if(ExisteTipoTren(tipoTrenes,codTipTren)){
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


pNodoTipoTren DevolverTipoTren(pNodoTipoTren &R,int tipTren){
	 if(R->valor==tipTren){
	 	return R;
	 }
	 else if(tipTren<=R->valor){
	 	return DevolverTipoTren(R->Hizq,tipTren);
	 }
	 else{
	 	return DevolverTipoTren(R->Hder,tipTren);
	 }
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
void CargarTrenes(pNodoTipoTren& tipoTrenes ){
	ifstream archivo;
    string texto;
    archivo.open("Trenes.txt",ios::in);
    if (archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    else{
    	while(!archivo.eof()){
    		getline(archivo,texto);
    		int posPC = texto.find(";"); int codTipTren = atoi(texto.substr(0, posPC).c_str()); 
	        string Todo = texto.substr(posPC + 1, texto.length()); int posPC2 = Todo.find(";");int codTren = atoi(Todo.substr(0, posPC2).c_str()); 
	        string Todo2 = Todo.substr(posPC2 + 1, Todo.length()); int posPC3 = Todo2.find(";");string nomTren = (Todo2.substr(0, posPC3)); 
	        string Todo3 = Todo2.substr(posPC3 + 1, Todo2.length()); int posPC4 = Todo3.find(";"); int numAsientos = atoi((Todo3.substr(0, posPC4).c_str())); 
	        string Todo4 = Todo3.substr(posPC4 + 1, Todo3.length()); int posPC5 = Todo4.find(";"); int ruta = atoi((Todo4.substr(0, posPC5).c_str())); 
	        
		    if(ExisteTipoTren(tipoTrenes,codTipTren)){
		    	pNodoTipoTren tipoTren = DevolverTipoTren(tipoTrenes,codTipTren);
		    	if(!ExisteTren(tipoTrenes->tren,codTren)){
		    		tipoTrenes->tren = insertarnodoAVLTren(tipoTrenes->tren,codTren,nomTren,numAsientos);
				}
				else{
					continue;
				}
			}
			else{
				continue;
			}
    		
    	}//llave del while
    	archivo.close();
	}
}

//Consultar los trenes de un tipo
void preOrderTren(NodoAVLTren *raiz)  {  
    if(raiz != NULL)  {  
        cout <<raiz->codCiudad<<"-"<<raiz->nombre<<endl;  
        preOrderTren(raiz->izquierda);  
        preOrderTren(raiz->derecha);  
    }  
}

void ConsultarTrenes(pNodoTipoTren& tipoTrenes){
	int codTipTren; cout<<"Ingrese el codigo del tipo de tren al que pertenece el tren: "; cin>>codTipTren; cout<<endl;
	NodoAVLTren *tipoTrenAux = DevolverTipoTren(tipoTrenes,codTipTren);
	cout<<"Trenes de ese tipo: "<<endl;
	preOrderTren(*tipoTrenAux);
	cout<<endl;
}


#endif	

