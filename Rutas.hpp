#include <fstream> 
#include <iostream> 
#include <stdlib.h> 
#include<string>
#include"NodoBinario.hpp"
#include"NodoTipoTren.hpp" 
#pragma once 
using namespace std; 
 
class nodoCir { 
public: 
    nodoCir(int v, int trenc, int rutac, int paisc, int ciudadc, int pais2c, int ciudad2c, int precioc) { 
        codTipTren = v; 
        codTren= trenc;
        codRutas = rutac; 
        codPais1 = paisc; 
        codCiudad1 = ciudadc; 
        codPais2 = pais2c; 
        codCiudad2 = ciudad2c; 
        precio = precioc; 
        siguiente = NULL; 
    } 
 
    nodoCir(int v, int trenc, int rutac, int paisc, int ciudadc, int pais2c, int ciudad2c,int precioc, nodoCir* signodo) { 
        codTipTren = v; 
        codTren= trenc; 
        codRutas = rutac; 
        codPais1 = paisc; 
        codCiudad1 = ciudadc; 
        codPais2 = pais2c; 
        codCiudad2 = ciudad2c; 
        precio = precioc; 
        siguiente = signodo; 
    } 
     
public: 
    int codTipTren; 
    int codTren; 
    int codRutas ; 
    int codPais1 ; 
    int codCiudad1 ; 
    int codPais2 ; 
    int codCiudad2 ; 
    int precio; 
    nodoCir* siguiente; 
 
 
    friend class listaC; 
}; 
 
typedef nodoCir* pnodoCir; 
 
class listaC { 
public: 
    listaC() { primero = NULL; } 
    ~listaC(); 
 
    void InsertarInicio(int v, int trenc, int rutac, int paisc, int ciudadc, int pais2c, int ciudad2c,int precioc); 
    void InsertarFinal(int v, int trenc, int rutac, int paisc, int ciudadc, int pais2c, int ciudad2c,int precioc); 
    void InsertarPos(int v, int trenc, int rutac, int paisc, int ciudadc, int pais2c, int ciudad2c,int precioc, int pos); 
    bool ListaVacia() { return primero == NULL; } 
    void ConsultarRuta(); 
    void BorrarFinal(); 
    void BorrarInicio(); 
    void borrarPosicion(int pos); 
    int largoLista(); 
    void CargarRutas(pNodoBinario &paises,pNodoTipoTren &tipoTrenes);
    bool ExisteRuta(int codRuta);
    void InsertarRutas(pNodoBinario &paises,pNodoTipoTren &tipoTrenes);
    void ModificarRutas(pNodoBinario &paises);
    void ModificarPrecio(pNodoBinario &paises);
    void ConsultarPrecio(pNodoTipoTren &tipoTrenes);
    pnodoCir DevolverRuta(int codRuta);
public:
    pnodoCir primero; 
 
}; 
 
listaC::~listaC() { 
    pnodoCir aux; 
 
    while (primero) { 
        aux = primero; 
        primero = primero->siguiente; 
        delete aux; 
    } 
 
} 
 
int listaC::largoLista() { 
    int cont = 0; 
 
    pnodoCir aux = primero; 
    if (ListaVacia()) 
        return cont; 
    else { 
        while (aux->siguiente != primero) 
        { 
            cont++; 
            aux = aux->siguiente; 
        } 
        cont = cont + 1; 
        return cont; 
    } 
} 
 
void listaC::InsertarInicio(int v, int trenc, int rutac, int paisc, int ciudadc, int pais2c, int ciudad2c,int precioc) { 
     if (ListaVacia()){ 
    primero = new nodoCir(v,  trenc,  rutac,  paisc,  ciudadc,  pais2c,  ciudad2c, precioc, primero); 
    primero->siguiente=primero; 
    } 
   else{ // La funcionalidad de esta parte es que crea un nuevo nodo con el valor asignado y la direccion de primero, luego crea un aux con el valor de primero 
   // Al entrar al while con el parametro actualizado encontraremos el valor del aux que necesitamos para enlazar el nodo con la dirrecion anterior 
   // y posterior por lo que no se hara basura. 
       pnodoCir nuevo = new nodoCir(v,  trenc,  rutac,  paisc,  ciudadc,  pais2c,  ciudad2c, precioc); 
       pnodoCir aux = primero; 
       while(aux->siguiente!=primero){ 
           aux=aux->siguiente; 
       } 
       aux->siguiente=nuevo; 
       primero=nuevo; 
   } 
} 
 
void listaC::InsertarFinal(int v, int trenc, int rutac, int paisc, int ciudadc, int pais2c, int ciudad2c,int precioc) { 
    if (ListaVacia()) { 
    	pnodoCir nuevo = new nodoCir(v,  trenc,  rutac,  paisc,  ciudadc,  pais2c,  ciudad2c, precioc); 
    	primero= nuevo; 
    	primero->siguiente=primero; 
    } 
    else { 
        pnodoCir nuevo = new nodoCir( v,  trenc,  rutac,  paisc,  ciudadc,  pais2c,  ciudad2c, precioc); 
        pnodoCir aux = primero; 
        while (aux->siguiente != primero){ 
        	aux = aux->siguiente; 
		} 
		aux->siguiente=nuevo; 
		nuevo->siguiente=primero; 
    } 
} 
 
void listaC::InsertarPos(int v, int trenc, int rutac, int paisc, int ciudadc, int pais2c, int ciudad2c,int precioc ,int pos) 
{ 
    if (ListaVacia()) 
    { 
        pnodoCir nuevo = new nodoCir( v,  trenc,  rutac,  paisc,  ciudadc,  pais2c,  ciudad2c, precioc); 
        primero = nuevo; 
        nuevo->siguiente = primero; 
    } 
    else 
    { 
        if (pos <= 1) 
        { 
            InsertarInicio(v,  trenc,  rutac,  paisc,  ciudadc,  pais2c,  ciudad2c, precioc); 
        } 
        else 
        { 
            pnodoCir aux = primero; 
            int i = 2; 
            while ((i != pos) && (aux->siguiente != primero)) 
            { 
                i++; 
                aux = aux->siguiente; 
            } 
            pnodoCir nuevo = new nodoCir(v,  trenc,  rutac,  paisc,  ciudadc,  pais2c,  ciudad2c, precioc); 
            nuevo->siguiente = aux->siguiente; 
            aux->siguiente = nuevo; 
        } 
    } 
} 
 
void listaC::BorrarFinal() 
{ 
    if (ListaVacia()) 
        cout << "No hay elementos en la lista:" << endl; 
    else 
    { 
        if (primero->siguiente == primero) 
        { 
            pnodoCir temp = primero; 
            primero = NULL; 
            delete temp; 
        } 
        else 
        { 
            pnodoCir aux = primero; 
            while (aux->siguiente->siguiente != primero) 
                aux = aux->siguiente; 
            pnodoCir temp = aux->siguiente; 
            aux->siguiente = primero; 
            delete temp; 
        } 
    } 
} 
 
void listaC::BorrarInicio() 
{ 
    if (ListaVacia()) 
        cout << "No hay elementos en la lista:" << endl; 
    else 
    { 
        if (primero->siguiente == primero) 
        { 
            pnodoCir temp = primero; 
            primero = NULL; 
            delete temp; 
        } 
        else 
        { 
            pnodoCir aux = primero; 
            pnodoCir temp = primero; 
            while (aux->siguiente != primero) 
                aux = aux->siguiente; 
            primero = primero->siguiente; 
            aux->siguiente = primero; 
            delete temp; 
        } 
    } 
} 
 
void listaC::borrarPosicion(int pos) 
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
                pnodoCir aux = primero; 
                while (cont < pos) 
                { 
                    aux = aux->siguiente; 
                    cont++; 
                } 
                pnodoCir temp = aux->siguiente; 
                aux->siguiente = aux->siguiente->siguiente; 
                delete temp; 
            } 
        } 
    } 
} 
 
void listaC::ConsultarRuta() { 
    pnodoCir aux = primero;
    if(aux== NULL){
    	cout<<"No hay ninuna ruta registrada"<<endl;
	}else{
		while (aux->siguiente != primero) { 
        cout <<"Tipo tren: "<<aux->codTipTren << " Tren: " << aux->codTren << " Ruta: " << aux->codRutas << " Pais1: " << aux->codPais1 << " Ciudad1: "<< aux->codCiudad1 << " Pais2: "<< aux->codPais2 << " Ciudad2: "<< aux->codCiudad2 <<" Precio: "<< aux->precio << "-> "<<endl; 
        aux = aux->siguiente; 
	    } 
	    cout <<"Tipo tren: "<<aux->codTipTren << " Tren: " << aux->codTren << " Ruta: " << aux->codRutas << " Pais1: " << aux->codPais1 << " Ciudad1: "<< aux->codCiudad1 << " Pais2: "<< aux->codPais2 << " Ciudad2: "<< aux->codCiudad2 <<" Precio: "<< aux->precio << "-> "<<endl;
	    cout << endl; 	
	}
}

//CargarRutas
bool listaC::ExisteRuta(int codRuta){
	pnodoCir aux = primero; bool bandera = false;
	if(aux==NULL){
		return false;
	}else{
		while(aux->siguiente != primero){
			if(aux->codRutas==codRuta){
				return true;
			}
			else{
				aux = aux->siguiente; 
			}
		}
		if(aux->codRutas==codRuta){
			return true;
		}
		else{
			return false;
		}
	}
}

pnodoCir listaC::DevolverRuta(int codRuta){
	pnodoCir aux = primero; bool bandera = false;
	while(aux->siguiente != primero){
		if(aux->codRutas==codRuta){
			return aux;
		}
		else{
			aux = aux->siguiente; 
		}
	}
	if(aux->codRutas==codRuta){
		return aux;
	}
}

void listaC::CargarRutas(pNodoBinario &paises,pNodoTipoTren &tipoTrenes){
	ifstream archivo;
    string texto;
    archivo.open("Rutas.txt",ios::in);
    if (archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    else{
    	while(!archivo.eof()){
    		getline(archivo,texto);
    		int posPC = texto.find(";"); int codTipTren = atoi(texto.substr(0, posPC).c_str()); 
	        string Todo = texto.substr(posPC + 1, texto.length()); int posPC2 = Todo.find(";"); int codTren = atoi(Todo.substr(0, posPC2).c_str()); 
	        string Todo2 = Todo.substr(posPC2 + 1, Todo.length()); int posPC3 = Todo2.find(";"); int codRuta = atoi((Todo2.substr(0, posPC3).c_str())); 
	        string Todo3 = Todo2.substr(posPC3 + 1, Todo2.length()); int posPC4 = Todo3.find(";"); int codPais = atoi((Todo3.substr(0, posPC4).c_str())); 
	        string Todo4 = Todo3.substr(posPC4 + 1, Todo3.length()); int posPC5 = Todo4.find(";"); int codCiudad = atoi((Todo4.substr(0, posPC5).c_str())); 
	        string Todo5 = Todo4.substr(posPC5 + 1, Todo4.length()); int posPC6 = Todo5.find(";"); int codPais2 = atoi((Todo5.substr(0, posPC6).c_str())); 
	        string Todo6 = Todo5.substr(posPC6 + 1, Todo5.length()); int posPC7 = Todo6.find(";"); int codCiudad2 = atoi((Todo6.substr(0, posPC7).c_str())); 
	        string Todo7 = Todo6.substr(posPC7 + 1, Todo6.length()); int posPC8 = Todo7.find(";"); int codPrecio = atoi((Todo7.substr(0, posPC8).c_str())); 
	        
	        if(ExistePais(paises,codPais)&&(ExistePais(paises,codPais2))){
	        	pNodoBinario paisAux = DevolverPais(paises,codPais);
				pNodoBinario paisAux2 = DevolverPais(paises,codPais2);
				if((ExisteCiudad(paisAux->ciudad,codCiudad))&&(ExisteCiudad(paisAux2->ciudad,codCiudad2))){
					if(ExisteTipoTren(tipoTrenes,codTipTren)){
						pNodoTipoTren trenAux = DevolverTipoTren(tipoTrenes,codTipTren);
						if(ExisteTren(trenAux->tren,codTren)){
							if(!ExisteRuta(codRuta)){
								InsertarFinal(codTipTren,codTren,codRuta,codPais,codCiudad,codPais2,codCiudad2,codPrecio);					
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


void listaC::InsertarRutas(pNodoBinario &paises,pNodoTipoTren &tipoTrenes){
	int codTipTren; cout<<"Ingrese el codigo tipo de tren: "; cin>>codTipTren; cout<<endl;
	int codTren; cout<<"Ingrese el codigo de tren: "; cin>>codTren; cout<<endl;
	int codRuta; cout<<"Ingrese el codigo de la ruta: "; cin>>codRuta; cout<<endl;
	int codPais; cout<<"Ingrese el codigo del pais: "; cin>>codPais; cout<<endl;
	int codCiudad; cout<<"Ingrese el codigo de la ciudad: "; cin>>codCiudad; cout<<endl;
	int codPais2; cout<<"Ingrese el codigo del pais destino: "; cin>>codPais2; cout<<endl;
	int codCiudad2; cout<<"Ingrese el codigo de la ciudad destino: "; cin>>codCiudad2; cout<<endl;
	int codPrecio; cout<<"Ingrese el precio de la ruta: "; cin>>codPrecio; cout<<endl;
	if(ExistePais(paises,codPais)&&(ExistePais(paises,codPais2))){
    	pNodoBinario paisAux = DevolverPais(paises,codPais);
		pNodoBinario paisAux2 = DevolverPais(paises,codPais2);
		if((ExisteCiudad(paisAux->ciudad,codCiudad))&&(ExisteCiudad(paisAux2->ciudad,codCiudad2))){
			if(ExisteTipoTren(tipoTrenes,codTipTren)){
				pNodoTipoTren trenAux = DevolverTipoTren(tipoTrenes,codTipTren);
				if(ExisteTren(trenAux->tren,codTren)){
					if(!ExisteRuta(codRuta)){
						InsertarFinal(codTipTren,codTren,codRuta,codPais,codCiudad,codPais2,codCiudad2,codPrecio);
						cout<<"Ruta insertada con exito"<<endl;				
					}
					else{
						cout<<"El codigo de ruta ya existe"<<endl;
					}
				}
				else{
					cout<<"El codigo de tren no existe"<<endl;
				}
			}
			else{
				cout<<"El codigo de tipo de tren no existe"<<endl;
			}
		}
		else{
			cout<<"La ciudad de origen o destino no existe"<<endl;
		}
	}
	else{
		cout<<"El pais de origen o destino no existe"<<endl;
	} 
}

void listaC :: ModificarRutas(pNodoBinario &paises){
	int codRuta; cout<<"Ingrese el codigo de la ruta: "; cin>>codRuta; cout<<endl;
	int codPais; cout<<"Ingrese el codigo nuevo del pais: "; cin>>codPais; cout<<endl;
	int codCiudad; cout<<"Ingrese el codigo nuevo de la ciudad: "; cin>>codCiudad; cout<<endl;
	int codPais2; cout<<"Ingrese el codigo nuevo del pais destino: "; cin>>codPais2; cout<<endl;
	int codCiudad2; cout<<"Ingrese el codigo nuevo de la ciudad destino: "; cin>>codCiudad2; cout<<endl;
	int codPrecio; cout<<"Ingrese el precio nuevo de la ruta: "; cin>>codPrecio; cout<<endl;
	if(ExistePais(paises,codPais)&&(ExistePais(paises,codPais2))){
    	pNodoBinario paisAux = DevolverPais(paises,codPais);
		pNodoBinario paisAux2 = DevolverPais(paises,codPais2);
		if((ExisteCiudad(paisAux->ciudad,codCiudad))&&(ExisteCiudad(paisAux2->ciudad,codCiudad2))){
			if(ExisteRuta(codRuta)){
				pnodoCir cambio = DevolverRuta(codRuta);
				cambio->codPais1 = codPais;
				cambio->codPais2 = codPais2;
				cambio->codCiudad1 = codCiudad;
				cambio->codCiudad2 = codCiudad2;
				cambio->precio = codPrecio;	
				cout<<"Modificacion exitosa"<<endl;			
			}
			else{
				cout<<"El codigo de ruta no existe"<<endl;
			}
		}
		else{
			cout<<"La ciudad de origen o destino no existe"<<endl;
		}
	}
	else{
		cout<<"El pais de origen o destino no existe"<<endl;
	} 
}

void listaC :: ModificarPrecio(pNodoBinario &paises){
	int codRuta; cout<<"Ingrese el codigo de la ruta: "; cin>>codRuta; cout<<endl;
	int codPrecio; cout<<"Ingrese el precio nuevo de la ruta: "; cin>>codPrecio; cout<<endl;
	if(ExisteRuta(codRuta)){
		pnodoCir cambio = DevolverRuta(codRuta);
		cambio->precio = codPrecio;	
		cout<<"Modificacion exitosa"<<endl;			
	}
	else{
		cout<<"El codigo de ruta no existe"<<endl;
	}
}

void listaC :: ConsultarPrecio(pNodoTipoTren &tipoTrenes){
	int codTipTren; cout<<"Ingrese el codigo tipo de tren: "; cin>>codTipTren; cout<<endl;
	int codTren; cout<<"Ingrese el codigo de tren: "; cin>>codTren; cout<<endl;
	pnodoCir aux = primero;
	cout<<"Los precios de las rutas del tren "<<codTren<<" son: " <<endl;
	if(ExisteTipoTren(tipoTrenes,codTipTren)){
		pNodoTipoTren trenAux = DevolverTipoTren(tipoTrenes,codTipTren);
		if(ExisteTren(trenAux->tren,codTren)){
			while(aux->siguiente != primero){
				if((aux->codTipTren == codTipTren)&&(aux->codTren == codTren)){
					cout<<"Ruta: "<<aux->codRutas<<" Precio: "<<aux->precio<<endl;
					aux= aux->siguiente;
				}else{
					aux= aux->siguiente;
				}
			}if((aux->codTipTren == codTipTren)&&(aux->codTren == codTren)){
					cout<<"Ruta: "<<aux->codRutas<<" Precio: "<<aux->precio<<endl;
				}
		}else{
			cout<<"El codigo de tren no existe"<<endl;
		}
	}else{
		cout<<"El codigo de tipo de tren no existe"<<endl;
	}
}
