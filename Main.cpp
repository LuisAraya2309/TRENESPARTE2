#include <stdlib.h>
#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<cstdlib>
#include<string>
#include<sstream>
#include <math.h>
#include "NodoBinario.hpp"
#include "NodoTipoTren.hpp"


using namespace std;

int main(){
	cout<<"Arboles ABB"<<endl<<endl;
	cout<<"Paises"<<endl;
	pNodoBinario paises = CargarPaises();
	cout<<"Tipos de Trenes"<<endl;
	pNodoTipoTren tipoTrenes = CargarTipoTrenes();
    return 0;
}
