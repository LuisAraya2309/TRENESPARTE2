#include<fstream>
#include <iostream>
#include <stdlib.h>
#include<string>
#include<sstream>
#include "Conexiones.hpp"
#include "Ciudad.hpp"
#pragma once
using namespace std;

class nodo {
public:
    nodo(int v, string cpais)
    {
        valor = v;
        pais = cpais;
        siguiente = NULL;
        anterior = NULL;
        ciudad = NULL;
        listaCiudades= listaDCCiudad();
        listaConexiones = listaD();
        primeraConexion = listaConexiones.primero;
    }

    nodo(int v, string cpais, nodo* signodo, nodo* sigCiudad)
    {
        valor = v;
        pais = cpais;
        siguiente = signodo;
        ciudad = sigCiudad;
    }

public:
    int valor;
    string pais;
    nodo* ciudad;
    nodo* siguiente;
    nodo* anterior;
    listaD listaConexiones;
    listaDCCiudad listaCiudades;
    nodoDoble *primeraConexion;
    
    friend class listaDC;
    friend class nodoDoble;
    friend class listaD;
    friend class nodoCiudad;
    friend class listaDCCiudad;
};
typedef nodo* pnodo;

class listaDC {
public:
    listaDC() { primero = NULL; }

    void InsertarInicio(int v, string pais);
    void InsertarFinal(int v, string pais);
    void InsertarPos(int v, string pais, int pos);
    bool ListaVacia() { return primero == NULL; }
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    int largoLista();
    void llenarListaPais();
    void llenarListaCiudad();
    void llenarListaConexiones();
    void ConsultarPaises();
    void ConsultarCiudades();
    void ConsultarConexiones();
    void InsertarPais(string& ultimoPais);
    void InsertarCiudades (string& ultimaCiudad);
    void InsertarConexion(int& ultimaConexion);
    void EliminarPais();
    void EliminarCiudad();
    void ModificarTiempo();
    void RegistroActividad();
    void MostrarActP();
    void MostrarActC();
    void BorrarConexion();
    bool VerificarCodPais(int codAux,int codCiudadAux);
    
public:
    pnodo primero;

};

pnodo UltimoPais(listaDC paises){   
	pnodo aux = paises.primero;
	while(aux->siguiente!=paises.primero){
		aux=aux->siguiente;
	}
	return aux;
}


int listaDC::largoLista()
{
    int cont = 0;

    pnodo aux = primero;
    if (ListaVacia())
    {
        return cont;
    }
    else
    {
        while (aux->siguiente!= primero)
        {
            aux = aux->siguiente;
            cont++;
        }
        return cont;
    }

}

void listaDC::InsertarInicio(int v, string pais)
{

    if (ListaVacia())
    {
        primero = new nodo(v, pais);
        primero->anterior = primero;
        primero->siguiente = primero;
    }
    else
    {
        pnodo nuevo = new nodo(v, pais);
        nuevo->siguiente = primero;
        nuevo->anterior = primero->anterior;
        primero->anterior->siguiente = nuevo;
        nuevo->siguiente->anterior = nuevo;
        primero = nuevo;
    }
}

void listaDC::InsertarFinal(int v, string pais)
{
    if (ListaVacia())
    {
        primero = new nodo(v, pais);
        primero->anterior = primero;
        primero->siguiente = primero;
    }
    else
    {
        pnodo nuevo = new nodo(v, pais);
        nuevo->anterior = primero->anterior;
        nuevo->siguiente = primero->anterior->siguiente;
        primero->anterior->siguiente = nuevo;
        primero->anterior = nuevo;
    }
}


void listaDC::InsertarPos(int v, string pais, int pos)
{
    if (ListaVacia())
    {
        primero = new nodo(v, pais);
        primero->anterior = primero;
        primero->siguiente = primero;
    }
    else
    {
        if (pos <= 1)
            InsertarInicio(v, pais);
        else
        {
            if (pos == largoLista())
                InsertarFinal(v, pais);
            else
            {
                pnodo aux = primero;
                int i = 2;
                while ((i != pos) && (aux->siguiente != primero))
                {
                    i++;
                    aux = aux->siguiente;
                }
                pnodo nuevo = new nodo(v, pais);
                nuevo->siguiente = aux->siguiente;
                aux->siguiente = nuevo;
                aux->siguiente->anterior = aux;
                nuevo->siguiente->anterior = nuevo;
            }
        }
    }
}

void listaDC::BorrarFinal()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            pnodo temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodo aux = primero;
            while (aux->siguiente->siguiente != primero)
                aux = aux->siguiente;
            pnodo temp = aux->siguiente;
            aux->siguiente = primero;
            primero->anterior = aux;
            delete temp;
        }
    }
}

void listaDC::BorrarInicio()
{
    if (ListaVacia())
        cout << "No hay elementos en la lista:" << endl;
    else
    {
        if (primero->siguiente == primero)
        {
            pnodo temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {
            pnodo aux = primero->anterior;
            pnodo temp = primero;
            aux->siguiente = primero->siguiente;
            primero = primero->siguiente;
            primero->anterior = aux;
            delete temp;
        }
    }
}

void listaDC::BorrarPosicion(int pos)
{

    if (ListaVacia())
        cout << "Lista vacia" << endl;
    else
    {
        if ((pos > largoLista()) || (pos < 0))
            cout << "Error en posicion" << endl;
        else
        {
            if (pos == 1)
                BorrarInicio();
            else
            {
                int cont = 2;
                pnodo aux = primero;
                while (cont < pos)
                {
                    aux = aux->siguiente;
                    cont++;
                }
                pnodo temp = aux->siguiente;
                aux->siguiente = aux->siguiente->siguiente;
                delete temp;
            }
        }
    }
}

void listaDC::Mostrar()
{
    pnodo aux = primero;
    while (aux->siguiente != primero)
    {

        cout << aux->valor << "-" << aux->pais << "->";
        aux = aux->siguiente;
    }
    cout << aux->valor << "-" << aux->pais << "->";
    cout << endl;
}

void listaDC::InsertarPais(string& ultimoPais){
	int codPais;
	string nomPais;
	cout<<"Digite el codigo del pais a ingresar: "; cin>> codPais;cout<<endl;
	cout<<"Digite el nombre del pais a ingresar: "; cin>> nomPais;cout<<endl;
	if (ListaVacia()) {
	            InsertarFinal(codPais, nomPais);
	            stringstream ss;
	            ss<<codPais;
	            string codPaisS = ss.str();
	            ultimoPais = ("Ultimo pais insertado: " + nomPais + "\n" + "Codigo: " + codPaisS);
	            cout<<"Pais ingresado con exito"<<endl;
	        }
	        else {
	            pnodo puntero = primero; bool flag = true;
	            while (puntero->siguiente != primero) {
	                if (puntero->valor == codPais) {
	                    flag = false;
	                    break;
	                }
	                else {
	                    puntero = puntero->siguiente;
	                }
	            }if (puntero->valor == codPais) {
	            	flag=false;
	            }
	            if (flag) {
	                InsertarFinal(codPais, nomPais);
	                stringstream ss;
	            	ss<<codPais;
	            	string codPaisS = ss.str();
	            	ultimoPais = ("Ultimo pais insertado: " + nomPais + "\n" + "Codigo: " + codPaisS);
	                
	               	cout<<"Pais ingresado con exito"<<endl;
	           	}else{
	           		cout<<"El codigo del pais ya existe"<<endl;
				}
			}
		}
		
		
		
