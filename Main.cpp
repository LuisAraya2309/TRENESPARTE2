#include <stdlib.h>
#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include<cstdlib>
#include<string>
#include<sstream>
#include <math.h>
#include "Paises.hpp"
#include "TipoTren.hpp"
#include "Ciudades.hpp"
#include "Rutas.hpp"
#include "Admin.hpp"
#include "Usuarios.hpp"
#include "Boleteria.hpp"
#include "CodRutas.hpp"
#include "Reservacion.hpp"
#include "UsuarioReservacion.hpp"
using namespace std;


int main(){
	//Variables de reportes
	string ultimoPais;
	string ultimaCiudad;
	string ultimaConexion;
	string ultimoTren;
	//Cargar estructuras
	pNodoBinario paises = CargarPaises();//Paises
	CargarCiudades(paises);//Ciudades
	CargarConexiones(paises);//Conexiones
	
	
	pNodoTipoTren tipoTrenes = CargarTipoTrenes();//Tipos de Tren
	CargarTrenes(tipoTrenes);//Trenes
	
	
	listaC rutas;
	rutas.CargarRutas(paises,tipoTrenes); //Rutas
	CargarCodRutas(tipoTrenes,rutas); //CodRutas
	
	BTree admins(3);
	CargarAdmin(admins);//Carga admin
	
	ArbolUsuario usuarios(5);
	CargarUsuarios(usuarios,paises);//Carga usuarios
	
	listaBoleteria boletos;
	listaUsuario listaUsuarios;
	
	listaUsuario listaRP;
	listaUsuario listaRC;
	listaUsuario listaRT;

	
	//---------------------------------------------------------Menu Principal------------------------------------------------- 
	//Variables del menu-----------------------------
    int opcion,codUsuario,registrar,RutaMayor,RutaMenor;
    //------------------------------------------------
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
                if (admins.ExisteAdmin(codAdmin)){ //Validar Admin
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
					        cout << "7. Consultar Precio de una ruta" << endl;
							cout << "8. Consultar Precio de una conexion" << endl;       
					        cout << "9. Consultar Rutas" << endl; 
					        cout << "10. Numero de asientos disponibles" << endl; 
					        cout << "11. Ruta mas utilizada" << endl;
					        cout << "12. Ruta nunca utilizada" << endl;
					        cout << "13. Pais mas visitado" << endl;
					        cout << "14. Ciudad mas visitada" << endl; 
					        cout << "15. Usuario que mas reservo" << endl;
					        cout << "16. Usuario que menos reservo" << endl;
					        cout << "17. Cantidad de reservaciones por usuario" << endl;
					        cout << "18. Tren mas utilizado" << endl;
					        cout << "19. Tren menos utilizado" << endl;
					        cout << "20. Abrir ventanilla" << endl;
					        cout << "21. Venta de tiquetes" << endl;
					        cout << "22. Reservacion" << endl;
					        cout << "23. Salir" << endl;
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
									        cout << "6. Registrar Tren " << endl; 
									        cout << "7. Reporte de actividad " << endl; 
									        cout << "8. Salir" << endl; 
									        cout << "\nIngrese una opcion: "; 
									        cin >> opcion; 
									        cout<<endl; 
									         
									        switch (opcion) { 
									        	 
									            case 1:
									            	InsertarPais(paises , ultimoPais);
													system("pause>nul"); 
													break;  
									            case 2:
									            	InsertarCiudad(paises, ultimaCiudad);
									            	system("pause>nul"); 
									                break;    
												case 3:
													InsertarConexion(paises, ultimaConexion);
									                system("pause>nul"); // Pausa 
									                break;                 
									    	 	case 4:
									    	 		InsertarTipoTrenes(tipoTrenes);
									                system("pause>nul"); // Pausa 
									                break;    
									            case 5:
									            	rutas.InsertarRutas(paises,tipoTrenes);
									                system("pause>nul"); // Pausa 
									                break;  
												case 6:
													RegistrarTrenes(tipoTrenes, ultimoTren);
									                system("pause>nul"); // Pausa 
									                break; 
												case 7:
													cout<<"Actividad de insertados: "<<endl;
													if(ultimoPais==""){
														cout<<"No se ha insertado ningun pais"<<endl;
													}else{
														cout<<ultimoPais<<endl;
													}
													if(ultimaCiudad==""){
														cout<<"No se ha insertado ninguna ciudad"<<endl;
													}else{
														cout<<ultimaCiudad<<endl;
													}
													if(ultimaConexion==""){
														cout<<"No se ha insertado ninguna conexion"<<endl;
													}else{
														cout<<ultimaConexion<<endl;
													}
													if(ultimoTren==""){
														cout<<"No se ha insertado ningun tren"<<endl;
													}else{
														cout<<ultimoTren<<endl;
													}
									                system("pause>nul"); // Pausa 
									                break;        
											} 
										}while (opcion != 8); 
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
									            	rutas.ModificarPrecio(paises);
									                system("pause>nul"); // Pausa 
									                break;									                 
									            case 2: 
									            	ModificarTiempo(paises);             
									                system("pause>nul"); // Pausa 
									                break; 
												case 3: 
													ModificarAsientos(tipoTrenes);              
									                system("pause>nul"); // Pausa 
									                break;                     
									    	 	case 4:
									    	 		ModificarTren(tipoTrenes);
									                system("pause>nul"); // Pausa 
									                break; 
									            case 5:
									            	rutas.ModificarRutas(paises);
									                system("pause>nul"); // Pausa 
									                break;    
												case 6: 
													ModificarEstMigracion(usuarios);
									                system("pause>nul"); // Pausa 
									                break;      
											} 
										}while (opcion3 != 7); 
									    system("pause>nul"); // Pausa 
									    break;                     
					    	 	case 3:
								 	ConsultarPaises(paises);     
					                system("pause>nul"); // Pausa 
					                break; 
								case 4:
									ConsultarCiudades(paises);
					                system("pause>nul"); // Pausa 
					                break; 
								case 5:
									ConsultarConexiones(paises);    
					                system("pause>nul"); // Pausa 
					                break; 
								case 6:
									ConsultarTrenes(tipoTrenes);
					                system("pause>nul"); // Pausa 
					                break; 
								case 7:
									rutas.ConsultarPrecio(tipoTrenes);
					                system("pause>nul"); // Pausa 
					                break;                     
					    	 	case 8:
					    	 		ConsultarPrecioConexion(paises);
					                system("pause>nul"); // Pausa 
					                break; 
								case 9:
									rutas.ConsultarRuta();
					                system("pause>nul"); // Pausa 
					                break; 
								case 10:
									CantAsientos(tipoTrenes);            
					                system("pause>nul"); // Pausa 
					                break;
								case 11:
					                system("pause>nul"); // Pausa 
					                break; 
								case 12: 
					                system("pause>nul"); // Pausa 
					                break;	
								case 13:
									cout<<"El pais mas visitado es "<<DevolverPais2(paises, PaisMayor(listaRP))<<endl;
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
									boletos.CrearColaPasajeros();
					                system("pause>nul"); // Pausa 
					                break;
								case 21: 
									VentaTiquetes(boletos,usuarios,paises,tipoTrenes);
					                system("pause>nul"); // Pausa 
					                break;				                   
						} 		case 22:
									Reservacion(tipoTrenes,listaUsuarios,rutas);
					                system("pause>nul"); // Pausa 
					                break;	
				}while (opcion != 23);
				}else{ 
					cout<<"El codigo ingresado no existe por favor vuelva a intentarlo"<<endl; 
				} 
                system("pause>nul"); 
                break;	 
            case 2:
            	cout<<"Si desea iniciar sesion digite 1 o si desea registrarse como usuario digite 2"<<endl;cin>>registrar;cout<<endl;
            	if(registrar==1){
            		cout<<"Ingrese la identificacion de usuario: "; cin>>codUsuario; cout<<endl;
	            	if(usuarios.ExisteUsuario(codUsuario)){ //Validar que el Usuario exista
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
							            	ConsultarPaises(paises);
							                system("pause>nul"); // Pausa 
							                break; 
							                 
							            case 2: 
							                ConsultarCiudades(paises);              
							                system("pause>nul"); // Pausa 
							                break; 
										case 3: 
							                ConsultarConexiones(paises);            
							                system("pause>nul"); // Pausa 
							                break;                     
							    	 	case 4:
										 	rutas.ConsultarRuta();
							                system("pause>nul"); // Pausa 
							                break; 
										case 5: 
							                ConsultarTrenes(tipoTrenes);
							                system("pause>nul"); // Pausa 
							                break; 
										case 6:
											rutas.ConsultarPrecio(tipoTrenes);     
							                system("pause>nul"); // Pausa 
							                break; 
										case 7: 
							                CantAsientos(tipoTrenes);               
							                system("pause>nul"); // Pausa 
							                break;      
								} 
							}while (opcion != 8); 
					}else{
						cout<<"La identificacion del usuario no es valida"<<endl<<endl;
						cout<<"Si desea registrarse ingrese 1 de lo contrario ingrese 2 para regresar: ";cin>>registrar;cout<<endl;
						if(registrar==1){
							RegistrarUsuario(usuarios, paises);
						}
					}  
				}else{
					RegistrarUsuario(usuarios, paises);
					}         
	                system("pause>nul"); // Pausa 
	                break;           
    	} 		 
	}while (opcion != 3);
    return 0;
}
