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
	//Cargar estructuras
	pNodoBinario paises = CargarPaises(); //Paises
	pNodoTipoTren tipoTrenes = CargarTipoTrenes();//Tipos de Tren
    return 0;
}
