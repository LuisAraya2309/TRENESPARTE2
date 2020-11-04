
#include<string.h>
#include<string>
#include<sstream>
#include<fstream>
#include<iostream>
#include <stdlib.h>
using namespace std;
class NodoAVL {
   public:
	NodoAVL(int v,string pnombre){
		valor = v;
		nombre =pnombre;
		Hder = NULL;
		Hizq = NULL;
		siguiente = NULL;
		anterior = NULL;
		FB=0;
	}
	
	//Atributos
    int valor;
    string nombre;
    int FB;
    NodoAVL *Hizq, *Hder, *siguiente, *anterior;

    friend class AVL;
};

typedef NodoAVL *pNodoAVL;

class AVL{
public:
    pNodoAVL raiz;

    AVL():raiz(NULL){}

    void InsertaNodo(int num);
    void PreordenI();
    void InordenI();
    void PostordenI();
    bool Hh;
    void Borrar(NodoAVL *nodoB, bool);
    void BorrarBalanceado(NodoAVL *r, bool, int eliminar);
    void Equilibrar1(NodoAVL *n, bool);
    void Equilibrar2(NodoAVL *n, bool);
    void InsertarBalanceado(pNodoAVL ra, bool, int codCiudad, string nombre);
    void RotacionDobleIzquierda(NodoAVL *n1, NodoAVL *n2);
    void RotacionDobleDerecha(NodoAVL *n1, NodoAVL *n2);
    void RotacionSimpleIzquierda(NodoAVL *n1, NodoAVL *n2);
    void RotacionSimpleDerecha(NodoAVL *n1, NodoAVL *n2);

};

void PreordenAVL(NodoAVL *R){
    
    if(R==NULL){
    	cout<<"NULL"<<endl;
        return;
    }
	else{
        cout<<R->valor<<"-"<<R->nombre<<"->";
        PreordenAVL(R->Hizq);
        PreordenAVL(R->Hder);
    }
}

void AVL::InsertarBalanceado(pNodoAVL ra, bool Hh, int codCiudad, string nombre){
    pNodoAVL n1;
    if(raiz==NULL){
    	cout<<"1"<<endl;
        ra=new NodoAVL(codCiudad,nombre);
        Hh = true;
    }else{
	cout<<"2"<<endl;
        if(codCiudad<=ra->valor){
            InsertarBalanceado(ra->Hizq, Hh, codCiudad, nombre);
	        if(Hh){
	            switch(ra->FB){
	                case 1: 
						ra->FB=0;
	                	Hh = false;
	                	break;
	                case 0: 
						ra->FB  = -1;
	                	break;
	                case -1: 
						n1=ra->Hizq;
		                if(n1->FB =-1){
		                    RotacionSimpleIzquierda(ra, n1);
		                }else{
		                    RotacionDobleIzquierda(ra,n1);
		                }
		                Hh = false;
	                	break;
	            }
	        }
        }else{
            if(codCiudad>ra->valor){
                InsertarBalanceado(ra->Hder, Hh, codCiudad, nombre);

                if(Hh){
                    switch(ra->FB){
                        case -1: ra->FB=0;
	                        Hh = false;
	                        break;
                        case 0:
							ra->FB=1;
	                        break;
                        case 1:
							n1=ra->Hder;
	                        if(n1->FB=1){
	                            RotacionSimpleDerecha(ra, n1);
	                        }else{
	                            RotacionDobleDerecha(ra, n1);
	                        }
	                        Hh=false;
	                        break;
                    }
                }
            }
        }
    }
}

void AVL::RotacionDobleIzquierda(NodoAVL* n, NodoAVL* n1){
    NodoAVL *n2;
    n2=n1->Hder;
    n->Hizq = n2->Hder;
    n2->Hder=n;
    n1->Hder=n2->Hizq;
    n2->Hizq=n1;

    if(n2->FB==1){
        n1->FB=-1;
    }else{
        n1->FB=0;
    }
    if(n2->FB==-1){
        n->FB=1;
    }else{
        n->FB=0;
    }
    n2->FB=0;
    n=n2;
}

void AVL::RotacionDobleDerecha(NodoAVL* n, NodoAVL* n1){
    NodoAVL *n2;
    n2=n1->Hizq;
    n->Hder = n2->Hizq;
    n2->Hizq=n;
    n1->Hizq=n2->Hder;
    n2->Hder=n1;

    if(n2->FB==1){
        n->FB=-1;
    }else{
        n->FB=0;
    }
    if(n2->FB==-1){
        n1->FB=1;
    }else{
        n1->FB=0;
    }
    n2->FB=0;
    n=n2;
}

void AVL::RotacionSimpleDerecha(NodoAVL* n, NodoAVL* n1){
    n->Hder=n1->Hizq;
    n1->Hizq=n;

    if(n1->FB==1){
        n->FB=0;
        n1->FB=0;
    }else{
        n->FB=1;
        n1->FB=-1;
    }
    n=n1;
}

void AVL::RotacionSimpleIzquierda(NodoAVL* n, NodoAVL* n1){
    n->Hizq=n1->Hder;
    n1->Hder=n;
    if(n1->FB==-1){
        n->FB=0;
        n1->FB=0;
    }else{
        n->FB=-1;
        n1->FB=-1;
    }
    n=n1;
}
