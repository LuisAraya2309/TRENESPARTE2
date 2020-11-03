#ifndef _NODOBINARIO_H
#define	_NODOBINARIO_H
#include<string.h>
#include<string>
#include<sstream>
#include<fstream>
#include<iostream>
#include <stdlib.h>
using namespace std;
class NodoBinario {
   public:
	NodoBinario(int v,string pnombre){
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
    NodoBinario *Hizq, *Hder, *siguiente, *anterior;

    friend class Pila;
    friend class Binario;
	//Metodos
    void InsertaBinario(string num);
};

typedef NodoBinario *pNodoBinario;

bool ExistePais(pNodoBinario &R,int pais){
	 if(R == NULL){
	 	return false;
	 }
	 else if(R->valor==pais){
	 	return true;
	 }
	 else if(pais<=R->valor){
	 	return ExistePais(R->Hizq,pais);
	 }
	 else{
	 	return ExistePais(R->Hder,pais);
	 }
}
void PreordenR(NodoBinario *R){
    
    if(R==NULL){
        return;
    }
	else{
        cout<<R->valor<<" -> ";
        PreordenR(R->Hizq);
        PreordenR(R->Hder);
    }
}

void InsertarNodoPais(pNodoBinario &paises,int num, string nombre){
	if(paises==NULL){
		paises = new NodoBinario(num,nombre);
	}
	else{
		if(num<=paises->valor){
			InsertarNodoPais(paises->Hizq,num, nombre);
		}
		else{
			InsertarNodoPais(paises->Hder,num, nombre);
		}
	}
}

pNodoBinario CargarPaises(){
	pNodoBinario paises = NULL;
	ifstream archivo;
    string texto;
    archivo.open("Paises.txt",ios::in);
    if (archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    else{
    	while(!archivo.eof()){
    		getline(archivo,texto);
    		if(paises==NULL){
    			int posPC = texto.find(";");
		        int codPais = atoi(texto.substr(0, posPC).c_str());
		        string nomPais = texto.substr(posPC + 1, texto.length());
    			paises = new NodoBinario(codPais,nomPais);
			}
			else{
				int posPC = texto.find(";");
		        int codPais = atoi(texto.substr(0, posPC).c_str());
		        string nomPais = texto.substr(posPC + 1, texto.length());
		        if(ExistePais(paises,codPais)){
		        	continue;
				}
				else{
					InsertarNodoPais(paises,codPais,nomPais);
				}
			}
    		
    		
    		
    	}//llave del while
    	archivo.close();
	}
	return paises;
}




#endif	

