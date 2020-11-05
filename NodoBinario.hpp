#ifndef _NODOBINARIO_H
#define	_NODOBINARIO_H
#include<string.h>
#include<string>
#include<sstream>
#include<fstream>
#include<iostream>
#include <stdlib.h>
#include "NodoAVL.hpp"
#include "Rojinegro.cpp"
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
//Devuelve una ciudad
NodoAVL* DevolverCiudad(NodoAVL* R,int codCiudad){
	 if(R->codCiudad==codCiudad){
	 	return R;
	 }
	 else if(codCiudad<=R->codCiudad){
	 	return DevolverCiudad(R->izquierda,codCiudad);
	 }
	 else{
	 	return DevolverCiudad(R->derecha,codCiudad);
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

//CargarConexiones

bool ExisteConexion(pNodoBinarioRN R,int codConexion){
	 if(R == NULL){
	 	return false;
	 }
	 else if(R->valor==codConexion){
	 	return true;
	 }
	 else if(codConexion<=R->valor){
	 	return ExisteConexion(R->Hizq,codConexion);
	 }
	 else{
	 	return ExisteConexion(R->Hder,codConexion);
	 }
}

void CargarConexiones(pNodoBinario &paises){
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
    		int posPC = texto.find(";");int codPais = atoi(texto.substr(0, posPC).c_str());                                                         
			string ConexionTotal = texto.substr(posPC + 1, texto.length());int posPC2 = ConexionTotal.find(";");int codCiudad = atoi((ConexionTotal.substr(0, posPC2).c_str()));                            
			string Conexion = ConexionTotal.substr(posPC2 + 1, ConexionTotal.length());int posPC3 = Conexion.find(";");int codConexionAux = atoi((Conexion.substr(0, posPC3).c_str()));
			string ConexionPais = Conexion.substr(posPC3 + 1, Conexion.length());int posPC4 = ConexionPais.find(";");int codPais2 = atoi((ConexionPais.substr(0, posPC4).c_str()));
			string ConexionCiudad = ConexionPais.substr(posPC4 + 1, ConexionPais.length());int posPC5 = ConexionCiudad.find(";");int codCiudad2 = atoi((ConexionCiudad.substr(0, posPC5).c_str()));
			string Tiempo = ConexionCiudad.substr(posPC5 + 1, ConexionCiudad.length());int posPC6 = Tiempo.find(";");int codTiempo = atoi((Tiempo.substr(0, posPC6).c_str()));
			if(ExistePais(paises,codPais)){
				pNodoBinario paisAux = DevolverPais(paises,codPais);
				if(ExisteCiudad(paisAux->ciudad,codCiudad)){
					NodoAVL *ciudadAux = DevolverCiudad(paisAux->ciudad,codCiudad);
					if(!ExisteConexion(*ciudadAux->conexiones->raiz,codConexionAux)){
						
					}
					else{
						continue;
					}
				}
				else{
					continue;
				}
			}
			else{
				continue;
			}
    	}
    	archivo.close();
    }
}

#endif	

