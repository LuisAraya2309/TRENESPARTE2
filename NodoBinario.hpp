#ifndef _NODOBINARIO_H
#define	_NODOBINARIO_H
#include<string.h>
#include<string>
#include<sstream>
#include<fstream>
#include<iostream>
#include <stdlib.h>
#include "NodoAVL.hpp"
using namespace std;
class NodoBinario {
   public:
	NodoBinario(int v,string pnombre){
		valor = v;
		nombre =pnombre;
		ciudad = NULL;
		Hder = NULL;
		Hizq = NULL;
		siguiente = NULL;
		anterior = NULL;
	}
	
	//Atributos
    int valor;
    string nombre;
    NodoBinario *Hizq, *Hder, *siguiente, *anterior;
    NodoAVL *ciudad;

    friend class Pila;
    friend class Binario;
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
        cout<<R->valor<<"-"<<R->nombre<<"->";
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

void InsertarPais(pNodoBinario &paises){
	int codPais;
	string nombrePais;
	cout<<"Ingrese el codigo del pais nuevo: "<<endl;
	cin>>codPais;
	cout<<"Ingrese el nombre del pais: "<<endl;
	cin>>nombrePais;
	if(ExistePais(paises,codPais)){
		cout<<"El codigo del pais ingresado ya existe."<<endl;
	}
	else{
		InsertarNodoPais(paises,codPais,nombrePais);
		cout<<"El pais fue ingresado con exito."<<endl;
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
//Devuelve un pais
pNodoBinario DevolverPais(pNodoBinario &R,int pais){
	 if(R->valor==pais){
	 	return R;
	 }
	 else if(pais<=R->valor){
	 	return DevolverPais(R->Hizq,pais);
	 }
	 else{
	 	return DevolverPais(R->Hder,pais);
	 }
}
//Cargar Ciudades
void CargarCiudades(pNodoBinario& paises ){
	ifstream archivo;
    string texto;
    archivo.open("Ciudades.txt",ios::in);
    if (archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    else{
    	while(!archivo.eof()){
    		getline(archivo,texto);
    		int posPC = texto.find(";");
		    int codPais = atoi(texto.substr(0, posPC).c_str());
		    if(ExistePais(paises,codPais)){
		    	pNodoBinario pais = DevolverPais(paises,codPais);
		    	string CiudadTotal = texto.substr(posPC + 1, texto.length());
		        int auxPC = CiudadTotal.find(";");
		        int codCiudad = atoi(CiudadTotal.substr(0, auxPC).c_str());
		        string nomCiudad = CiudadTotal.substr(auxPC+1, CiudadTotal.length());
		    	if(!ExisteCiudad(pais->ciudad,codCiudad)){
		    		pais->ciudad = insertarnodoAVL(pais->ciudad,codCiudad,nomCiudad);
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


void InsertarCiudad(pNodoBinario& paises ){
    int codPais; cout<<"Ingrese el codigo del pais al que pertenece la ciudad: "; cin>>codPais; cout<<endl;
    if(ExistePais(paises,codPais)){
    	pNodoBinario pais = DevolverPais(paises,codPais);
        int codCiudad; cout<<"Ingrese el codigo de la ciudad: "; cin>>codCiudad; cout<<endl;
        string nomCiudad; cout<<"Ingrese el nombre de la ciudad: "; cin>>nomCiudad; cout<<endl;
    	if(!ExisteCiudad(pais->ciudad,codCiudad)){
    		pais->ciudad = insertarnodoAVL(pais->ciudad,codCiudad,nomCiudad);
		}
		else{
			cout<<"El codigo de la ciudad ya existe"<<endl;
		}
	}
	else{
		cout<<"El pais no existe"<<endl;
	}
}


//Consultar Paises
void ConsultarPaises(pNodoBinario &paises){
	PreordenR(paises);
	cout<<endl;
}

//Consultar Ciudades
void preOrder(NodoAVL *raiz)  {  
    if(raiz != NULL)  {  
        cout <<raiz->codCiudad<<"-"<<raiz->nombre<<endl;  
        preOrder(raiz->izquierda);  
        preOrder(raiz->derecha);  
    }  
}

void ConsultarCiudades(pNodoBinario &paises){
	int paisAux;
	cout<<"Ingrese el codigo del pais para ver las ciudades: ";cin>>paisAux; cout<<endl;
	pNodoBinario pais = DevolverPais(paises,paisAux);
	cout<<"Ciudades de ese pais: "<<endl;
	preOrder(pais->ciudad);
}

#endif	

