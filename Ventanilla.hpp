#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<string>
#pragma once
using namespace std;

class nodoVentanilla { 

public:
    nodoVentanilla(int iD , int cTren) 
    {
        codTren = cTren;
        identificacion = iD;
        siguiente = NULL;
    }

    nodoVentanilla(int iD , int cTren , nodoVentanilla* signodoVentanilla) 
    {
        identificacion = iD;
        codTren = cTren;
        siguiente = signodoVentanilla;
    }


public: // atributos
    int identificacion;
    int codTren;
    nodoVentanilla* siguiente; /
};
typedef nodoVentanilla* pnodoVentanilla; 

class listaVentanilla {
public:
    listaVentanilla()
    {
        primero = NULL;

    }
    ~listaVentanilla();
    void InsertarInicio(int identificacion,  int codTren);
    void InsertarFinal(int identificacion,  int codTren);
    void InsertarPos(int identificacion,  int codTren, int pos);
    bool ListaVacia() { return primero == NULL; }
    void Imprimir();
    void Mostrar();
    void Primero();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    void CrearColaPasajeros();
public:
    pnodoVentanilla primero; 

};

listaVentanilla::~listaVentanilla(){
    pnodoVentanilla aux;

    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }

}

int listaVentanilla::largoLista() { 
    int cont = 0;

    pnodoVentanilla aux; 
    aux = primero;
    if (ListaVacia()) {
        return cont;
    }
    else {
        while (aux != NULL) {
            aux = aux->siguiente;
            cont++;
        }
        return cont;
    }

}

void listaVentanilla::InsertarInicio(int identificacion,  int codTren){
    if (ListaVacia())
        primero = new nodoVentanilla(identificacion, codTren);
    else
        primero = new nodoVentanilla(identificacion, codTren, primero);
}

void listaVentanilla::InsertarFinal(int identificacion,  int codTren){
    if (ListaVacia())
        primero = new nodoVentanilla(identificacion, codTren);
    else
    {
        pnodoVentanilla aux = primero;
        while (aux->siguiente != NULL)
            aux = aux->siguiente;
        aux->siguiente = new nodoVentanilla(identificacion, codTren);
    }
}

void listaVentanilla::InsertarPos(int identificacion,  int codTren, int pos){
    if (ListaVacia())
        primero = new nodoVentanilla(identificacion, codTren);
    else {
        if (pos <= 1) {                    
            pnodoVentanilla nuevo = new nodoVentanilla(identificacion, codTren);
            nuevo->siguiente = primero;
            primero = nuevo;
        }
        else
        {
            if (pos >= largoLista())
                InsertarFinal(identificacion, codTren);
            else
            {

                pnodoVentanilla aux = primero;
                int i = 2;
                while ((i != pos) && (aux->siguiente != NULL)) {
                    i++;
                    aux = aux->siguiente;
                }
                pnodoVentanilla nuevo = new nodoVentanilla(identificacion, codTren); 
                nuevo->siguiente = aux->siguiente; 
                aux->siguiente = nuevo;
            }

        }
    }
}

void listaVentanilla::BorrarFinal(){
    if (ListaVacia()) {
        cout << "No hay elementos en la lista:" << endl;

    }
    else {
        if (primero->siguiente == NULL) {
            primero = NULL;
        }
        else {

            pnodoVentanilla aux = primero;
            while (aux->siguiente->siguiente != NULL) {
                aux = aux->siguiente;

            }

            pnodoVentanilla temp = aux->siguiente;
            aux->siguiente = NULL;


            delete temp;
        }
    }
}

void listaVentanilla::BorrarInicio(){
    if (ListaVacia()) {
        cout << "No hay elementos en la lista:" << endl;

    }
    else
    {
        if (primero->siguiente == NULL)
        {
            pnodoVentanilla temp = primero;
            primero = NULL;
            delete temp;
        }
        else
        {

            pnodoVentanilla aux = primero;
            primero = primero->siguiente;
            delete aux;
        }
    }
}


void listaVentanilla::borrarPosicion(int pos) {
    if (ListaVacia()) {
        cout << "Lista vacia" << endl;
    }
    else {
        if ((pos > largoLista()) || (pos < 0)) {
            cout << "Error en posicion" << endl;
        }
        else {
            if (pos == 1) {
                primero = primero->siguiente;
            }
            else {
                int cont = 2;
                pnodoVentanilla aux = primero;
                while (cont < pos) {
                    aux = aux->siguiente;
                    cont++;
                }
                aux->siguiente = aux->siguiente->siguiente;
            }
        }
    }
}


void listaVentanilla::Mostrar(){
    nodoVentanilla* aux;
    if (primero == NULL)
        cout << "No hay elementos";
    else
    {
        aux = primero;
        while (aux)
        {
            cout << aux->identificacion <<" / "<<aux->codTren<< "-> ";
            aux = aux->siguiente;
        }
        cout << endl;
    }
}

