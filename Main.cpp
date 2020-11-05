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
#include "NodoAVL.hpp"

using namespace std;


int main(){
	//Cargar estructuras
	pNodoBinario paises = CargarPaises(); //Paises
	CargarCiudades(paises);//Ciudades
	
	pNodoTipoTren tipoTrenes = CargarTipoTrenes();//Tipos de Tren
	CargarTrenes(tipoTrenes);
	ConsultarTrenes(tipoTrenes);
	
	
	
	//---------------------------------------------------------Menu Principal------------------------------------------------- 
    /*int opcion; int codPais;string nomPais; int codCiudad;string nomCiudad;int codConexion;int codPais2;int codCiudad2;int codTiempo;int codUsuario;int registrar;bool bandera=true;
	do { 
        system("cls");
         
        // Texto del men? que se ver? cada vez 
         
        cout << "\n\nSistema de Trenes" << endl; 
        cout << "\n\nInicio de sesion" << endl; 
        cout << "1. Iniciar como Administrador" << endl; 
        cout << "2. Iniciar como Usuario" << endl; 
        cout << "3. Salir" << endl; 
         
        cout << "\nIngrese una opcion: "; 
        cin >> opcion; 
         
        switch (opcion) { 
            case 1: 
				int codAdmin;                 
                cout<<"Ingrese el codigo de Administrador: "; 
                cin>> codAdmin; 
                if (bandera){ //Validar Admin
                	cout<<"Bienvenido"<<endl; 
                		int opcion; 
						do { 
					        system("cls"); 
					         
					        cout << "\n\nSistema de Trenes" << endl; 
					        cout << "\n\nMenu del Administrador" << endl; 
					        cout << "1. Insertar" << endl; 
					        cout << "2. Modificar" << endl; 
					        cout << "3. Consultar paises" << endl; 
					        cout << "4. Consultar ciudades de un pais" << endl; 
					        cout << "5. Consultar conexiones de una ciudad" << endl; 
					        cout << "6. Consultar trenes de un tipo" << endl; 
					        cout << "7. Consultar Consultar Precio" << endl; 				        
					        cout << "8. Consultar Rutas" << endl; 
					        cout << "9. Numero de asientos disponibles" << endl; 
					        cout << "10. Ruta mas utilizada" << endl;
					        cout << "11. Ruta nunca utilizada" << endl;
					        cout << "12. Pais mas visitado" << endl;
					        cout << "13. Ciudad mas visitada" << endl; 
					        cout << "14. Usuario que mas reservo" << endl;
					        cout << "15. Usuario que menos reservo" << endl;
					        cout << "16. Cantidad de reservaciones por usuario" << endl;
					        cout << "17. Tren mas utilizado" << endl;
					        cout << "18. Tren menos utilizado" << endl;
					        cout << "19. Abrir ventanilla" << endl;
					        cout << "20. Venta de tiquetes" << endl;
					        cout << "21. Reservacion" << endl;
					        cout << "22. Salir" << endl;
					        cout << "\nIngrese una opcion: "; 
					        cin >> opcion; 
					        cout<<endl; 
					        switch (opcion) { 
					            case 1: 
					            	int opcion; 
										do { 
									        system("cls");      // Para limpiar la pantalla 
									     
									        cout << "\n\nSistema de Trenes" << endl; 
									        cout << "\n\nMenu de insertar" << endl; 
									        cout << "1. Pais" << endl; 
									        cout << "2. Ciudad" << endl; 
									        cout << "3. Conexion" << endl; 
									        cout << "4. Tipo de tren " << endl; 
									        cout << "5. Ruta " << endl; 
									        cout << "6. Reporte de actividad " << endl; 
									        cout << "7. Salir" << endl; 
									        cout << "\nIngrese una opcion: "; 
									        cin >> opcion; 
									        cout<<endl; 
									         
									        switch (opcion) { 
									        	 
									            case 1: 
													system("pause>nul"); 
													break;  
									            case 2: 
									            	system("pause>nul"); 
									                break;    
												case 3: 
									                system("pause>nul"); // Pausa 
									                break;                 
									    	 	case 4: 
									                system("pause>nul"); // Pausa 
									                break;    
									            case 5: 
									                system("pause>nul"); // Pausa 
									                break;  
												case 6:
									                system("pause>nul"); // Pausa 
									                break;         
											} 
										}while (opcion != 7); 
									    system("pause>nul"); // Pausa 
									    break;    					            
								case 2: 
					                int opcion3; 
										do { 
									        system("cls");      // Para limpiar la pantalla 
									     
									        cout << "\n\nSistema de Trenes" << endl; 
									        cout << "\n\nMenu de Modificar" << endl; 
									        cout << "1. Precio" << endl; 
									        cout << "2. Tiempo" << endl; 
									        cout << "3. Numero de asientos" << endl; 
									        cout << "4. Tren " << endl; 
									        cout << "5. Ruta " << endl; 
									        cout << "6. Estado migratorio " << endl; 
									        cout << "7. Salir" << endl; 
									        cout << "\nIngrese una opcion: "; 
									        cin >> opcion3; 
									        cout<<endl; 
									         
									        switch (opcion3) { 
									            case 1: 
									                system("pause>nul"); // Pausa 
									                break;									                 
									            case 2: 
									                // Lista de instrucciones de la opci?n 2                 
									                system("pause>nul"); // Pausa 
									                break; 
												case 3: 
									                // Lista de instrucciones de la opci?n 2                 
									                system("pause>nul"); // Pausa 
									                break;                     
									    	 	case 4: 
									                system("pause>nul"); // Pausa 
									                break; 
									            case 5: 
									                system("pause>nul"); // Pausa 
									                break;       
												case 6: 
									                system("pause>nul"); // Pausa 
									                break;      
											} 
										}while (opcion3 != 7); 
									    system("pause>nul"); // Pausa 
									    break;                     
					    	 	case 3:         
					                system("pause>nul"); // Pausa 
					                break; 
								case 4: 
					                system("pause>nul"); // Pausa 
					                break; 
								case 5:          
					                system("pause>nul"); // Pausa 
					                break; 
								case 6: 
					                system("pause>nul"); // Pausa 
					                break; 
								case 7: 
					                system("pause>nul"); // Pausa 
					                break;                     
					    	 	case 8: 
					                system("pause>nul"); // Pausa 
					                break; 
								case 9: 
					                system("pause>nul"); // Pausa 
					                break; 
								case 10:                
					                system("pause>nul"); // Pausa 
					                break;
								case 11: 
					                system("pause>nul"); // Pausa 
					                break; 
								case 12: 
					                system("pause>nul"); // Pausa 
					                break;	
								case 13: 
					                system("pause>nul"); // Pausa 
					                break; 
								case 14: 
					                system("pause>nul"); // Pausa 
					                break; 
								case 15:                
					                system("pause>nul"); // Pausa 
					                break;
								case 16: 
					                system("pause>nul"); // Pausa 
					                break; 
								case 17: 
					                system("pause>nul"); // Pausa 
					                break;
								case 18:                
					                system("pause>nul"); // Pausa 
					                break;
								case 19: 
					                system("pause>nul"); // Pausa 
					                break; 
								case 20: 
					                system("pause>nul"); // Pausa 
					                break;
								case 21: 
					                system("pause>nul"); // Pausa 
					                break;				                   
						} 
				}while (opcion != 22); 
				}else{ 
					cout<<"El codigo ingresado no existe por favor vuelva a intentarlo"<<endl; 
				} 
                system("pause>nul"); 
                break;	 
            case 2:
            	cout<<"Si desea iniciar sesion digite 1 o si desea registrarse como usuario digite 2"<<endl;cin>>registrar;cout<<endl;
            	if(registrar==1){
            		cout<<"Ingrese la identificacion de usuario: "; cin>>codUsuario; cout<<endl;
	            	if(bandera){ //Validar que el Usuario exista
		                int opcion; 
								do { 
							        system("cls");      // Para limpiar la pantalla 
							        cout << "\n\nSistema de Trenes" << endl; 
							        cout << "\n\nMenu de Usuario" << endl; 
							        cout << "1. Consultar paises" << endl; 
							        cout << "2. Consultar ciudades de un pais" << endl; 
							        cout << "3. Consultar conexiones de un pais" << endl; 
							        cout << "4. Consultar rutas " << endl; 
							        cout << "5. Consultar trenes" << endl; 
							        cout << "6. Consultar Precio" << endl; 
							        cout << "7. Numero de asientos disponibles" << endl; 
							        cout << "8. Salir" << endl; 
							        cout << "\nIngrese una opcion: "; 
							        cin >> opcion; 
							        cout<<endl; 
							         
							        switch (opcion) { 
							            case 1: 

							                system("pause>nul"); // Pausa 
							                break; 
							                 
							            case 2: 
							                // Lista de instrucciones de la opci?n 2                 
							                system("pause>nul"); // Pausa 
							                break; 
										case 3: 
							                // Lista de instrucciones de la opci?n 2                 
							                system("pause>nul"); // Pausa 
							                break;                     
							    	 	case 4:        
							                system("pause>nul"); // Pausa 
							                break; 
										case 5: 
							                // Lista de instrucciones de la opci?n 2                 
							                system("pause>nul"); // Pausa 
							                break; 
										case 6:            
							                system("pause>nul"); // Pausa 
							                break; 
										case 7: 
							                // Lista de instrucciones de la opci?n 2                 
							                system("pause>nul"); // Pausa 
							                break;      
								} 
							}while (opcion != 8); 
					}else{
						cout<<"La identificacion del usuario no es valida"<<endl<<endl;
						cout<<"Si desea registrarse ingrese 1 de lo contrario ingrese 2 para regresar: ";cin>>registrar;cout<<endl;
						if(registrar==1){
							//Registrar Usuario
						}
					}  
				}else{
					//Registrar Usuario	
					}         
	                system("pause>nul"); // Pausa 
	                break;           
    	} 		 
	}while (opcion != 3);*/
    return 0;
}
