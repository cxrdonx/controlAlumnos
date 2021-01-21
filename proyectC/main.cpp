//created by: cxrdonx

#include "C_Conexion.h"
#include "C_Save_Catedraticos.h"
#include "C_Save_Curso.h"
#include "C_Save_Salones.h"
#include "C_Save_Alumnos.h"
#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <mysql.h>
#include <mysqld_error.h> 
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <iomanip>




using namespace std;


struct Catedraticos {

	char cNombre[15];	
	char cApellido[15];

} inf_Catedraticos;

struct Curso{
	char cNombreCurso[15];
	char cIdCatedratico[15];
}inf_Curso;
 
struct Salones{
	char Seccion[15];
	char Grado[15];
}inf_Salones;

struct Alumnos{
	char Carnet[15];
	char Nombre[15];
	char Apellido[15];
	char idCursos[15];
	char Nota[15];
	char idSalones[15];
}inf_Alumnos;

struct AcutalizarNota{
	char Nota[15];
	char idNota[15];
}inf_ActualizarNota;

struct ActualizarSalones{
	char idSalones[15];
	char Seccion[15];
	char Grado[15];
}inf_ActualizarSalones;

struct ActualizarCatedraticos{
	char idCatedratico[15];
	char Nombre[15];
	char Apellido[15];
}inf_ActualizarCatedraticos;

struct ActualizarCurso{
	char idCurso[15];
	char Curso[15];
	char idCatedratico[15];
}inf_ActualizarCurso;

struct ActualizarNuevo{
	char idNuevo[15];
	char Carnet[15];
	char Nombre[15];
	char Apellido[15];
	char idCursos[15];
	char idSalones[15];
}inf_ActualizarNuevo;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	MYSQL  *bjDatos;
	char *consulta;

	//Clases
	C_Conexion conn;
	C_Save_Catedraticos Save_Catedraticos;
	C_Save_Curso Save_Curso;
	C_Save_Salones Save_Salones;
	C_Save_Alumnos Save_Alumnos;

	
	
if(!(bjDatos = mysql_init(0))) {
    // Imposible crear el objeto objDatos
      std::cout << "ERROR: imposible crear el objeto objDatos.\n";          
      return 1;
    }
   //Creando objetos
	conn.conecta_base_datos(bjDatos);
	
	//_____________________________________________________________________________________
	

void pausa();
    bool bandera=false;
    char tecla;
	 do
 
    {
 
        system("cls");
        cin.clear();
        system ("color 1f");

         time_t current_time;
         struct tm * time_info;
         char timeString[9];
         
         time(&current_time);
         time_info = localtime(&current_time);
         
        strftime(timeString, sizeof(timeString),"%H:%M:%S", time_info);
        printf("\t\t\t\t Hora Actual: %s",timeString);
        
        cout << "\n\n\t\t ----BIENVENIDOS----\n\n" << endl;
        
		cout << "_____________________________________________________________________________________" << endl;
		cout << "_____________________________________________________________________________________" << endl << endl;
        cout << "\t1 .- Guardar Catedraticos" << endl;
        cout << "\t2 .- Mostrar Informacion" << endl;
        cout << "\t3 .- Modificar " << endl;
        cout << "\t4 .- Guardar Cursos" << endl;
        cout << "\t5 .- Guardar Salones" << endl;
        cout << "\t6 .- Guardar Alumnos" << endl;
        cout << "\t7 .- Eliminar Registros" << endl;
		cout << "\t8 .- Salir" << endl << endl;
        cout << "_____________________________________________________________________________________" << endl;
		cout << "_____________________________________________________________________________________|" << endl << endl;
 
        cout << "Elije una opcion: ";
 
        cin >> tecla;
 
		switch(tecla)
		{
 
			case '1':
				{
				system("color f4");
						system("cls");
						//---GUARDAR CATEDRATICOS	
						std::cout<<"Ingrese primer nombre: ";
						std::cin>>inf_Catedraticos.cNombre;
						std::cout<<"Ingrese Apellido: ";
						std::cin>>inf_Catedraticos.cApellido;
					
	
						//Seteando valores
					
						Save_Catedraticos.set_C_nombre(inf_Catedraticos.cNombre);
						Save_Catedraticos.set_C_apellido(inf_Catedraticos.cApellido);
					
						
						
						//String para ralizar la inserción a la base de datos
						char sentencia[] = "INSERT INTO alumnos.catedraticos(Nombre, Apellido) VALUES(\'%s\', \'%s\')";
						// Para datos enteros utilizar  %d        
					    consulta = new char[strlen(sentencia)+sizeof(Catedraticos)-sizeof(int)];   
						
					    if(Save_Catedraticos.Save_Catedraticos(bjDatos,consulta,sentencia)==0){
					    	std::cout<<"Catedratico guardado con exito..";
						}else{
							std::cout<<"Error al grabar alumno.."<<mysql_error(bjDatos);
						}
						
	
	
				printf("\n\n\n");
				pausa();
				break;
				
 				}
			case '2': 
			 	{
			 
				system("cls");
				
				int Menu;
				std::cout<<"1) Mostrar todos los catedraticos";
				std::cout<<"\n2) Mostrar todos los cursos";
				std::cout<<"\n3) Mostrar todos los Salones";
				std::cout<<"\n4) Mostrar todos los Alumnos";
				std::cout<<"\n5) Consulta de notas alumnos";	
				std::cout<<"\n6) Consulta alumnos por salon";
				std::cout<<"\n7) consulta cursos por catedraticos";
				std::cout<<"\n8) consulta notas por alumno y curso";
				std::cout<<"\n9) Mostrar todo del alumno";
				std::cout<<"\nIngresar al numero = ";
				std::cin>>Menu;
				
				
				if(Menu==1){
					//----------------------------------------------------------------------------------
					
										
					if(mysql_query(bjDatos, "select * from alumnos.catedraticos")) 
				     {
				      // Error al realizar la consulta:
				      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
				      mysql_close(bjDatos);
				      //rewind(stdin);
				      //getchar();
				      return 2;
				     }
				    else
				     {	
			          /* Obteniendo el resultado de la consulta */ 
			          MYSQL_RES * resultado = mysql_store_result(bjDatos);
			
			         
			          /* Recorrer fila a fila */
			          MYSQL_ROW row;
			          cout<<"                 **  L I S T A D O  D E  C A T E D R A T I C O S  **    \n\n";
			          
			           //Encabezado reporte
					   cout << left << setw(15) << setfill(' ') << "Id";
			           cout << left << setw(15) << setfill(' ') << "Nombres";
			           cout << left << setw(15) << setfill(' ') << "Apellidos\n\n";
			         
			            
			              while(row=mysql_fetch_row(resultado))
			              {
			               
						   // Detalle
						    cout << left<<"\n";
			                cout << left << setw(15) << setfill(' ') << row[0];
			                cout << left << setw(15) << setfill(' ') << row[1];
			                cout << left << setw(15) << setfill(' ') << row[2];
			                
			             }
			
			          // Liberar el resultado de la consulta
			          mysql_free_result(resultado);
			
			       }
					
					//----------------------------------------------------------------------------------
				}else if(Menu==2){
					//----------------------------------------------------------------------------------
					
					if(mysql_query(bjDatos, "SELECT c.idCursos, c.Cursos,ca.Nombre,ca.Apellido FROM alumnos.cursos c join catedraticos ca on ca.idCatedraticos=c.idCatedratico")) 
				     {
				      // Error al realizar la consulta:
				      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
				      mysql_close(bjDatos);
				      //rewind(stdin);
				      //getchar();
				      return 2;
				     }
				    else
				     {	
			          /* Obteniendo el resultado de la consulta */ 
			          MYSQL_RES * resultado = mysql_store_result(bjDatos);
			
			         
			          /* Recorrer fila a fila */
			          MYSQL_ROW row;
			          cout<<"                 **  L I S T A D O  D E  C U R S O S **    \n\n";
			          
			           //Encabezado reporte
					   cout << left << setw(15) << setfill(' ') << "Id";
			           cout << left << setw(15) << setfill(' ') << "Cursos";
			           cout << left << setw(15) << setfill(' ') << "Nombre";
			           cout << left << setw(15) << setfill(' ') << "Apellido\n";
			         
			            
			              while(row=mysql_fetch_row(resultado))
			              {
			               
						   // Detalle
						  	cout << left <<"\n";
			                cout << left << setw(15) << setfill(' ') << row[0];
			                cout << left << setw(15) << setfill(' ') << row[1];
			                cout << left << setw(15) << setfill(' ') << row[2];
			                cout << left << setw(15) << setfill(' ') << row[3];
			                
			             }
			
			          // Liberar el resultado de la consulta
			          mysql_free_result(resultado);
			
			       }
					
					//----------------------------------------------------------------------------------
				}else if(Menu==3){
					//------------------------------------------------------------------------------------
					if(mysql_query(bjDatos, "SELECT * FROM alumnos.salones")) 
				     {
				      // Error al realizar la consulta:
				      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
				      mysql_close(bjDatos);
				      //rewind(stdin);
				      //getchar();
				      return 2;
				     }
				    else
				     {	
			          /* Obteniendo el resultado de la consulta */ 
			          MYSQL_RES * resultado = mysql_store_result(bjDatos);
			
			         
			          /* Recorrer fila a fila */
			          MYSQL_ROW row;
			          cout<<"                 **  L I S T A D O  D E  S A L O N E S  **    \n\n";
			          
			           //Encabezado reporte
					   cout << left << setw(15) << setfill(' ') << "Id";
			           cout << left << setw(15) << setfill(' ') << "Seccion";
			           cout << left << setw(15) << setfill(' ') << "Grado\n\n";
			         
			            
			              while(row=mysql_fetch_row(resultado))
			              {
			               
						   // Detalle
						    cout << left<<"\n";
			                cout << left << setw(15) << setfill(' ') << row[0];
			                cout << left << setw(15) << setfill(' ') << row[1];
			                cout << left << setw(15) << setfill(' ') << row[2];
			                
			             }
			
			          // Liberar el resultado de la consulta
			          mysql_free_result(resultado);
			
			       }
			//----------------------------------------------------------------------------------------------------------------		
				}else if(Menu==4){
					
						if(mysql_query(bjDatos, "SELECT distinct Carnet,Nombre,Apellido FROM alumnos.nuevo")) 
				     {
				      // Error al realizar la consulta:
				      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
				      mysql_close(bjDatos);
				      //rewind(stdin);
				      //getchar();
				      return 2;
				     }
				    else
				     {	
			          /* Obteniendo el resultado de la consulta */ 
			          MYSQL_RES * resultado = mysql_store_result(bjDatos);
			
			         
			          /* Recorrer fila a fila */
			          MYSQL_ROW row;
			          cout<<"                 **  L I S T A D O  D E  A L U M N O S  **    \n\n";
			          
			           //Encabezado reporte
					   cout << left << setw(15) << setfill(' ') << "Carnet";
			           cout << left << setw(15) << setfill(' ') << "Nombre";
			           cout << left << setw(15) << setfill(' ') << "Apellido\n\n";
			         
			            
			              while(row=mysql_fetch_row(resultado))
			              {
			               
						   // Detalle
						    cout << left<<"\n";
			                cout << left << setw(15) << setfill(' ') << row[0];
			                cout << left << setw(15) << setfill(' ') << row[1];
			                cout << left << setw(15) << setfill(' ') << row[2];
			                
			             }
			
			          // Liberar el resultado de la consulta
			          mysql_free_result(resultado);
					
					//-----------------------------------------------------------------------------------------------
			       }
				}else if(Menu==5){
					
					if(mysql_query(bjDatos, "SELECT n.Carnet,n.Nombre,n.Apellido, n.Nota, cu.Cursos FROM alumnos.nuevo n join cursos cu on cu.idCursos=n.idCursos")) 
				     {
				      // Error al realizar la consulta:
				      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
				      mysql_close(bjDatos);
				      //rewind(stdin);
				      //getchar();
				      return 2;
				     }
				    else
				     {	
			          /* Obteniendo el resultado de la consulta */ 
			          MYSQL_RES * resultado = mysql_store_result(bjDatos);
			
			         
			          /* Recorrer fila a fila */
			          MYSQL_ROW row;
			          cout<<"                 **  L I S T A D O   D E   N O T A S   A L U M N O S  **    \n\n";
			          
			           //Encabezado reporte
					   cout << left << setw(15) << setfill(' ') << "Carnet";
			           cout << left << setw(15) << setfill(' ') << "Nombre";
			           cout << left << setw(15) << setfill(' ') << "Apellido";
			           cout << left << setw(15) << setfill(' ') << "Nota";
					   cout << left << setw(15) << setfill(' ') << "Cursos\n";
			         
			            
			              while(row=mysql_fetch_row(resultado))
			              {
			               
						   // Detalle
						    cout << left<<"\n";
			                cout << left << setw(15) << setfill(' ') << row[0];
			                cout << left << setw(15) << setfill(' ') << row[1];
			                cout << left << setw(15) << setfill(' ') << row[2];
							cout << left << setw(15) << setfill(' ') << row[3];
							cout << left << setw(15) << setfill(' ') << row[4];			                
			             }
			
			          // Liberar el resultado de la consulta
			          mysql_free_result(resultado);
			
			       }
					
				}else if(Menu==6){
					
						if(mysql_query(bjDatos, "SELECT n.Carnet,n.Nombre,n.Apellido, cu.Seccion, cu.Grado FROM alumnos.nuevo n join salones cu on cu.idSalones=n.idSalones")) 
				     {
				      // Error al realizar la consulta:
				      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
				      mysql_close(bjDatos);
				      //rewind(stdin);
				      //getchar();
				      return 2;
				     }
				    else
				     {	
			          /* Obteniendo el resultado de la consulta */ 
			          MYSQL_RES * resultado = mysql_store_result(bjDatos);
			
			         
			          /* Recorrer fila a fila */
			          MYSQL_ROW row;
			          cout<<"                 **  L I S T A D O   A L U M N O S   P O R   S A L O N  **    \n\n";
			          
			           //Encabezado reporte
					   cout << left << setw(15) << setfill(' ') << "Carnet";
			           cout << left << setw(15) << setfill(' ') << "Nombre";
			           cout << left << setw(15) << setfill(' ') << "Apellido";
			           cout << left << setw(15) << setfill(' ') << "Seccion";
					   cout << left << setw(15) << setfill(' ') << "Grado\n";
			         
			            
			              while(row=mysql_fetch_row(resultado))
			              {
			               
						   // Detalle
						    cout << left<<"\n";
			                cout << left << setw(15) << setfill(' ') << row[0];
			                cout << left << setw(15) << setfill(' ') << row[1];
			                cout << left << setw(15) << setfill(' ') << row[2];
							cout << left << setw(15) << setfill(' ') << row[3];
							cout << left << setw(15) << setfill(' ') << row[4];			                
			             }
			
			          // Liberar el resultado de la consulta
			          mysql_free_result(resultado);
			
			       }
					
					
					
				}else if(Menu==7){
					
						if(mysql_query(bjDatos, "SELECT c.idCursos, c.Cursos, ca.idCatedraticos, ca.Nombre, ca.Apellido FROM alumnos.cursos c join catedraticos ca on ca.idCatedraticos=c.idCatedratico")) 
				     {
				      // Error al realizar la consulta:
				      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
				      mysql_close(bjDatos);
				      //rewind(stdin);
				      //getchar();
				      return 2;
				     }
				    else
				     {	
			          /* Obteniendo el resultado de la consulta */ 
			          MYSQL_RES * resultado = mysql_store_result(bjDatos);
			
			         
			          /* Recorrer fila a fila */
			          MYSQL_ROW row;
			          cout<<"                 **  L I S T A D O   D E   C U R S O S   P O R   C A T E D R A T I C O S  **    \n\n";
			          
			           //Encabezado reporte
					   cout << left << setw(15) << setfill(' ') << "idCursos";
			           cout << left << setw(15) << setfill(' ') << "Cursos";
			           cout << left << setw(15) << setfill(' ') << "idCatedraticos";
			           cout << left << setw(15) << setfill(' ') << "Nombre";
					   cout << left << setw(15) << setfill(' ') << "Apellido\n";
			         
			            
			              while(row=mysql_fetch_row(resultado))
			              {
			               
						   // Detalle
						    cout << left<<"\n";
			                cout << left << setw(15) << setfill(' ') << row[0];
			                cout << left << setw(15) << setfill(' ') << row[1];
			                cout << left << setw(15) << setfill(' ') << row[2];
							cout << left << setw(15) << setfill(' ') << row[3];
							cout << left << setw(15) << setfill(' ') << row[4];			                
			             }
			
			          // Liberar el resultado de la consulta
			          mysql_free_result(resultado);
			
			       }
					
				}else if(Menu==8){
					
						if(mysql_query(bjDatos, "select c.Carnet, c.Nombre, c.Apellido, c.Nota, cd.Cursos from alumnos.nuevo c join cursos cd on cd.idCursos=c.idCursos")) 
				     {
				      // Error al realizar la consulta:
				      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
				      mysql_close(bjDatos);
				      //rewind(stdin);
				      //getchar();
				      return 2;
				     }
				    else
				     {	
			          /* Obteniendo el resultado de la consulta */ 
			          MYSQL_RES * resultado = mysql_store_result(bjDatos);
			
			         
			          /* Recorrer fila a fila */
			          MYSQL_ROW row;
			          cout<<"                 **  L I S T A D O   D E   N O T A S   P O R  A L U M N O   Y   C U R S O **    \n\n";
			          
			           //Encabezado reporte
					   cout << left << setw(15) << setfill(' ') << "Carnet";
			           cout << left << setw(15) << setfill(' ') << "Nombre";
			           cout << left << setw(15) << setfill(' ') << "Apellido";
			           cout << left << setw(15) << setfill(' ') << "Nota";
					   cout << left << setw(15) << setfill(' ') << "Curso\n";
			         
			            
			              while(row=mysql_fetch_row(resultado))
			              {
			               
						   // Detalle
						    cout << left<<"\n";
			                cout << left << setw(15) << setfill(' ') << row[0];
			                cout << left << setw(15) << setfill(' ') << row[1];
			                cout << left << setw(15) << setfill(' ') << row[2];
							cout << left << setw(15) << setfill(' ') << row[3];
							cout << left << setw(15) << setfill(' ') << row[4];			                
			             }
			
			          // Liberar el resultado de la consulta
			          mysql_free_result(resultado);
			
			       }
				}else if(Menu==9){
					
					if(mysql_query(bjDatos, "select n.idNuevo,n.Carnet,n.Nombre,n.Apellido,n.Nota,cu.Cursos,s.idSalones,s.Seccion,s.Grado,ca.idCatedraticos,ca.Nombre,ca.Apellido from alumnos.nuevo n join cursos cu on cu.idCursos=n.idCursos join salones s on s.idSalones=n.idSalones join catedraticos ca on ca.idCatedraticos=cu.idCatedratico")) 
				     {
				      // Error al realizar la consulta:
				      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
				      mysql_close(bjDatos);
				      //rewind(stdin);
				      //getchar();
				      return 2;
				     }
				    else
				     {	
			          /* Obteniendo el resultado de la consulta */ 
			          MYSQL_RES * resultado = mysql_store_result(bjDatos);
			
			         
			          /* Recorrer fila a fila */
			          MYSQL_ROW row;
			          cout<<"                 **  L I S T A D O   G E N E R A L   D E   A L U M N O S **    \n\n";
			          
			           //Encabezado reporte
					   cout << left << setw(10) << setfill(' ') << "id Nuevo";
			           cout << left << setw(8) << setfill(' ') << "Carnet";
			           cout << left << setw(15) << setfill(' ') << "Nombre";
			           cout << left << setw(15) << setfill(' ') << "Apellido";
			           cout << left << setw(15) << setfill(' ') << "Nota";
			           cout << left << setw(15) << setfill(' ') << "Cursos";
			           cout << left << setw(10) << setfill(' ') << "id Salones";
			           cout << left << setw(10) << setfill(' ') << "Seccion";
			           cout << left << setw(15) << setfill(' ') << "Grado";
			           cout << left << setw(17) << setfill(' ') << "id Catedraticos";
			           cout << left << setw(15) << setfill(' ') << "Nombre ";
					   cout << left << setw(15) << setfill(' ') << "Apellido\n";
			         
			            
			              while(row=mysql_fetch_row(resultado))
			              {
			               
						   // Detalle
						    cout << left<<"\n";
			                cout << left << setw(10) << setfill(' ') << row[0];
			                cout << left << setw(8) << setfill(' ') << row[1];
			                cout << left << setw(15) << setfill(' ') << row[2];
							cout << left << setw(15) << setfill(' ') << row[3];
							cout << left << setw(15) << setfill(' ') << row[4];	
							cout << left << setw(15) << setfill(' ') << row[5];
							cout << left << setw(10) << setfill(' ') << row[6];
							cout << left << setw(10) << setfill(' ') << row[7];
							cout << left << setw(15) << setfill(' ') << row[8];	
							cout << left << setw(17) << setfill(' ') << row[9];
							cout << left << setw(15) << setfill(' ') << row[10];	
							cout << left << setw(15) << setfill(' ') << row[11];	
															                
			             }
			
			          // Liberar el resultado de la consulta
			          mysql_free_result(resultado);
			
			       }
					
					
				}else{
					std::cout<<"No ingreso numero valido";
				}
			
				
			 
				
				
				printf("\n\n\n");
				pausa();
				break;

				}
 
			case '3':
				{
					
				
				system("cls");
								
								
								int N1;
								std::cout<<"1) Editar Nota";
								std::cout<<"\n2) Editar Alumno";
								std::cout<<"\n3) Editar Curso";
								std::cout<<"\n4) Editar Catedratico";
								std::cout<<"\n5) Editar Salones";	
								
								std::cout<<"\nIngresar al numero = ";
								std::cin>>N1;
								
								if(N1==1){
									
														if(mysql_query(bjDatos, "SELECT n.idNuevo,n.Carnet,n.Nombre,n.Apellido,n.Nota,cu.Cursos FROM alumnos.nuevo n join cursos cu on cu.idCursos=n.idCursos")) 
													     {
													      // Error al realizar la consulta:
													      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
													      mysql_close(bjDatos);
													      //rewind(stdin);
													      //getchar();
													      return 2;
													     }
													    else
													     {	
												          /* Obteniendo el resultado de la consulta */ 
												          MYSQL_RES * resultado = mysql_store_result(bjDatos);
												
												         
												          /* Recorrer fila a fila */
												          MYSQL_ROW row;
												          cout<<"                 **  A C T U A L I Z A R    N O T A  D E   A L U M N O **    \n\n";
												          
												           //Encabezado reporte
														   cout << left << setw(15) << setfill(' ') << "id Alumno";
												           cout << left << setw(15) << setfill(' ') << "Carnet";
												           cout << left << setw(15) << setfill(' ') << "Nombre";
												           cout << left << setw(15) << setfill(' ') << "Apellido";
												           cout << left << setw(15) << setfill(' ') << "Nota";
												           cout << left << setw(15) << setfill(' ') << "Curso\n";
												         
												            
												              while(row=mysql_fetch_row(resultado))
												              {
												               
															   // Detalle
															    cout << left<<"\n";
												                cout << left << setw(15) << setfill(' ') << row[0];
												                cout << left << setw(15) << setfill(' ') << row[1];
												                cout << left << setw(15) << setfill(' ') << row[2];
																cout << left << setw(15) << setfill(' ') << row[3];
																cout << left << setw(15) << setfill(' ') << row[4];	
																cout << left << setw(15) << setfill(' ') << row[5];			                
												             }
												
												          // Liberar el resultado de la consulta
												          mysql_free_result(resultado);
												
												       }
												       
												       
												       
												        std::cout<<"\nIngrese el id del alumno a editar nota = ";
													    std::cin>>inf_ActualizarNota.idNota;
													   
													    std::cout<<"Ingrese Nota: ";
														std::cin>>inf_ActualizarNota.Nota;
														
															// Para datos enteros utilizar  %d        
															
														
														char nSQL[]= "update alumnos.nuevo set Nota= \'%s\' WHERE idNuevo=\'%s\'";
														 //char nSQLwhere[]= " where idNuevo=\'%s\'";
														
														consulta= new char[strlen(nSQL)+strlen(inf_ActualizarNota.Nota)+strlen(inf_ActualizarNota.idNota)]; 
														 sprintf(consulta, nSQL, inf_ActualizarNota.Nota,inf_ActualizarNota.idNota);
														if(mysql_query(bjDatos,consulta)) 
													     {
													      // Error al realizar la consulta:
													      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
													      mysql_close(bjDatos);
													      //rewind(stdin);
													      //getchar();
													      return 2;
													      
													     }else{
													     	std::cout<<"Dato actualizado";
														 }
													
														
				
													   
									
								}else if(N1==2){
									
										if(mysql_query(bjDatos, "select n.idNuevo,n.Carnet,n.Nombre,n.Apellido,n.Nota,cu.Cursos,s.idSalones,s.Seccion,s.Grado,ca.idCatedraticos,ca.Nombre,ca.Apellido from alumnos.nuevo n join cursos cu on cu.idCursos=n.idCursos join salones s on s.idSalones=n.idSalones join catedraticos ca on ca.idCatedraticos=cu.idCatedratico")) 
									     {
									      // Error al realizar la consulta:
									      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
									      mysql_close(bjDatos);
									      //rewind(stdin);
									      //getchar();
									      return 2;
									     }
									    else
									     {	
								          /* Obteniendo el resultado de la consulta */ 
								          MYSQL_RES * resultado = mysql_store_result(bjDatos);
								
								         
								          /* Recorrer fila a fila */
								          MYSQL_ROW row;
								          cout<<"                 **  L I S T A D O   G E N E R A L   D E   A L U M N O S **    \n\n";
								          
								           //Encabezado reporte
										   cout << left << setw(10) << setfill(' ') << "id Nuevo";
								           cout << left << setw(8) << setfill(' ') << "Carnet";
								           cout << left << setw(15) << setfill(' ') << "Nombre";
								           cout << left << setw(15) << setfill(' ') << "Apellido";
								           cout << left << setw(15) << setfill(' ') << "Nota";
								           cout << left << setw(15) << setfill(' ') << "Cursos";
								           cout << left << setw(10) << setfill(' ') << "id Salones";
								           cout << left << setw(10) << setfill(' ') << "Seccion";
								           cout << left << setw(15) << setfill(' ') << "Grado";
								           cout << left << setw(17) << setfill(' ') << "id Catedraticos";
								           cout << left << setw(15) << setfill(' ') << "Nombre ";
										   cout << left << setw(15) << setfill(' ') << "Apellido\n";
								         
								            
								              while(row=mysql_fetch_row(resultado))
								              {
								               
											   // Detalle
											    cout << left<<"\n";
								                cout << left << setw(10) << setfill(' ') << row[0];
								                cout << left << setw(8) << setfill(' ') << row[1];
								                cout << left << setw(15) << setfill(' ') << row[2];
												cout << left << setw(15) << setfill(' ') << row[3];
												cout << left << setw(15) << setfill(' ') << row[4];	
												cout << left << setw(15) << setfill(' ') << row[5];
												cout << left << setw(10) << setfill(' ') << row[6];
												cout << left << setw(10) << setfill(' ') << row[7];
												cout << left << setw(15) << setfill(' ') << row[8];	
												cout << left << setw(17) << setfill(' ') << row[9];
												cout << left << setw(15) << setfill(' ') << row[10];	
												cout << left << setw(15) << setfill(' ') << row[11];	
																				                
								             }
												
												          // Liberar el resultado de la consulta
												          mysql_free_result(resultado);
												
												       }
												       
												       
												       
												        std::cout<<"\nIngrese el id del Alumno = ";
													    std::cin>>inf_ActualizarNuevo.idNuevo;
													   
													    std::cout<<"Ingrese Carnet: ";
														std::cin>>inf_ActualizarNuevo.Carnet;
														
														std::cout<<"\nIngrese Nombre: ";
													    std::cin>>inf_ActualizarNuevo.Nombre;
													    
													    std::cout<<"\nIngrese Apellido: ";
													    std::cin>>inf_ActualizarNuevo.Apellido;
													    
													    std::cout<<"\nIngrese id Curso: ";
													    std::cin>>inf_ActualizarNuevo.idCursos;
													    
													    std::cout<<"\nIngrese id Salones: ";
													    std::cin>>inf_ActualizarNuevo.idSalones;
														
															// Para datos enteros utilizar  %d        
															
														
														char nSQL[]= "update alumnos.nuevo set Carnet= \'%s\', Nombre= \'%s\',Apellido= \'%s\',idCursos= \'%s\',idSalones= \'%s\' WHERE idNuevo=\'%s\'";
														 //char nSQLwhere[]= " where idNuevo=\'%s\'";
														
														consulta= new char[strlen(nSQL)+strlen(inf_ActualizarNuevo.Carnet)+strlen(inf_ActualizarNuevo.Nombre)+strlen(inf_ActualizarNuevo.Apellido)+strlen(inf_ActualizarNuevo.idCursos)+strlen(inf_ActualizarNuevo.idSalones)+strlen(inf_ActualizarNuevo.idNuevo)]; 
														 sprintf(consulta, nSQL, inf_ActualizarNuevo.Carnet,inf_ActualizarNuevo.Nombre,inf_ActualizarNuevo.Apellido,inf_ActualizarNuevo.idCursos,inf_ActualizarNuevo.idSalones,inf_ActualizarNuevo.idNuevo);
														if(mysql_query(bjDatos,consulta)) 
													     {
													      // Error al realizar la consulta:
													      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
													      mysql_close(bjDatos);
													      //rewind(stdin);
													      //getchar();
													      return 2;
													      
													     }else{
													     	std::cout<<"Dato actualizado";
														 }
									
								}else if(N1==3){
									if(mysql_query(bjDatos, "select c. idCursos, c.Cursos, c.idCatedratico,ca.Nombre,ca.Apellido from alumnos.cursos c join catedraticos ca on ca.idCatedraticos=c.idCatedratico")) 
													     {
													      // Error al realizar la consulta:
													      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
													      mysql_close(bjDatos);
													      //rewind(stdin);
													      //getchar();
													      return 2;
													     }
													    else
													     {	
												          /* Obteniendo el resultado de la consulta */ 
												          MYSQL_RES * resultado = mysql_store_result(bjDatos);
												
												         
												          /* Recorrer fila a fila */
												          MYSQL_ROW row;
												          cout<<"                 **  A C T U A L I Z A R   D A T O S    C U R S O **    \n\n";
												          
												           //Encabezado reporte
														   cout << left << setw(15) << setfill(' ') << "id Curso";
												           cout << left << setw(15) << setfill(' ') << "Cursos";
												           cout << left << setw(15) << setfill(' ') << "id Catedratico";
												           cout << left << setw(15) << setfill(' ') << "Nombre";
												           cout << left << setw(15) << setfill(' ') << "Apellido";
												           
												         
												            
												              while(row=mysql_fetch_row(resultado))
												              {
												               
															   // Detalle
															    cout << left<<"\n";
												                cout << left << setw(15) << setfill(' ') << row[0];
												                cout << left << setw(15) << setfill(' ') << row[1];
												                cout << left << setw(15) << setfill(' ') << row[2];
																cout << left << setw(15) << setfill(' ') << row[3];
																cout << left << setw(15) << setfill(' ') << row[4];	
																	                
												             }
												
												          // Liberar el resultado de la consulta
												          mysql_free_result(resultado);
												
												       }
												       
												       
												       
												        std::cout<<"\nIngrese el id del Curso = ";
													    std::cin>>inf_ActualizarCurso.idCurso;
													   
													    std::cout<<"Ingrese Nombre del Curso: ";
														std::cin>>inf_ActualizarCurso.Curso;
														
														std::cout<<"\nIngrese el id del Catedratico = ";
													    std::cin>>inf_ActualizarCurso.idCatedratico;
														
															// Para datos enteros utilizar  %d        
															
														
														char nSQL[]= "update alumnos.cursos set Cursos= \'%s\', idCatedratico= \'%s\' WHERE idCursos=\'%s\'";
														 //char nSQLwhere[]= " where idNuevo=\'%s\'";
														
														consulta= new char[strlen(nSQL)+strlen(inf_ActualizarCurso.Curso)+strlen(inf_ActualizarCurso.idCatedratico)+strlen(inf_ActualizarCurso.idCurso)]; 
														 sprintf(consulta, nSQL, inf_ActualizarCurso.Curso,inf_ActualizarCurso.idCatedratico,inf_ActualizarCurso.idCurso);
														if(mysql_query(bjDatos,consulta)) 
													     {
													      // Error al realizar la consulta:
													      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
													      mysql_close(bjDatos);
													      //rewind(stdin);
													      //getchar();
													      return 2;
													      
													     }else{
													     	std::cout<<"Dato actualizado";
														 }
									
								}else if(N1==4){
															if(mysql_query(bjDatos, "SELECT * FROM alumnos.catedraticos")) 
																			     {
															cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
														  mysql_close(bjDatos);
													      //rewind(stdin);
													      //getchar();
													      return 2;
													     }
													    else
													     {	
												          /* Obteniendo el resultado de la consulta */ 
												          MYSQL_RES * resultado = mysql_store_result(bjDatos);
												
												         
												          /* Recorrer fila a fila */
												          MYSQL_ROW row;
												          cout<<"                 **  A C T U A L I Z A R  C A T E D R A T I C O **    \n\n";
												          
												           //Encabezado reporte
														   cout << left << setw(15) << setfill(' ') << "id Catedratico";
												           cout << left << setw(15) << setfill(' ') << "Nombre";
												           cout << left << setw(15) << setfill(' ') << "Apellido\n";
												        
												         
												            
												              while(row=mysql_fetch_row(resultado))
												              {
												               
															   // Detalle
															    cout << left<<"\n";
												                cout << left << setw(15) << setfill(' ') << row[0];
												                cout << left << setw(15) << setfill(' ') << row[1];
												                cout << left << setw(15) << setfill(' ') << row[2];
																	                
												             }
												
												          // Liberar el resultado de la consulta
												          mysql_free_result(resultado);
												
												       }
												       
												       
												       
												        std::cout<<"\nIngrese el id del Catedratico = ";
													    std::cin>>inf_ActualizarCatedraticos.idCatedratico;
													   
													    std::cout<<"Ingrese Nombre: ";
														std::cin>>inf_ActualizarCatedraticos.Nombre;
														
														std::cout<<"Ingrese Apellido: ";
														std::cin>>inf_ActualizarCatedraticos.Apellido;
														
															// Para datos enteros utilizar  %d        
															
														
														char nSQL[]= "update alumnos.catedraticos set Nombre= \'%s\', Apellido=\'%s\' WHERE idCatedraticos=\'%s\'";
														 //char nSQLwhere[]= " where idNuevo=\'%s\'";
														
														consulta= new char[strlen(nSQL)+strlen(inf_ActualizarCatedraticos.Nombre)+strlen(inf_ActualizarCatedraticos.Apellido)+strlen(inf_ActualizarCatedraticos.idCatedratico)]; 
														 sprintf(consulta, nSQL, inf_ActualizarCatedraticos.Nombre,inf_ActualizarCatedraticos.Apellido,inf_ActualizarCatedraticos.idCatedratico);
														if(mysql_query(bjDatos,consulta)) 
													     {
													      // Error al realizar la consulta:
													      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
													      mysql_close(bjDatos);
													      //rewind(stdin);
													      //getchar();
													      return 2;
													      
													     }else{
													     	std::cout<<"Dato actualizado";
														 }
									
								}else if(N1==5){
									if(mysql_query(bjDatos, "SELECT * FROM alumnos.salones")) 
													     {
													      // Error al realizar la consulta:
													      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
													      mysql_close(bjDatos);
													      //rewind(stdin);
													      //getchar();
													      return 2;
													     }
													    else
													     {	
												          /* Obteniendo el resultado de la consulta */ 
												          MYSQL_RES * resultado = mysql_store_result(bjDatos);
												
												         
												          /* Recorrer fila a fila */
												          MYSQL_ROW row;
												          cout<<"                 **  A C T U A L I Z A R   S A L O N E S **    \n\n";
												          
												           //Encabezado reporte
														   cout << left << setw(15) << setfill(' ') << "id Salones";
												           cout << left << setw(15) << setfill(' ') << "Seccion";
												           cout << left << setw(15) << setfill(' ') << "Grado\n";
												        
												         
												            
												              while(row=mysql_fetch_row(resultado))
												              {
												               
															   // Detalle
															    cout << left<<"\n";
												                cout << left << setw(15) << setfill(' ') << row[0];
												                cout << left << setw(15) << setfill(' ') << row[1];
												                cout << left << setw(15) << setfill(' ') << row[2];
																	                
												             }
												
												          // Liberar el resultado de la consulta
												          mysql_free_result(resultado);
												
												       }
												       
												       
												       
												        std::cout<<"\nIngrese el id del salon = ";
													    std::cin>>inf_ActualizarSalones.idSalones;
													   
													    std::cout<<"Ingrese Seccion: ";
														std::cin>>inf_ActualizarSalones.Seccion;
														
														std::cout<<"Ingrese Grado: ";
														std::cin>>inf_ActualizarSalones.Grado;
														
															// Para datos enteros utilizar  %d        
															
														
														char nSQL[]= "update alumnos.salones set Seccion= \'%s\', Grado=\'%s\' WHERE idSalones=\'%s\'";
														 //char nSQLwhere[]= " where idNuevo=\'%s\'";
														
														consulta= new char[strlen(nSQL)+strlen(inf_ActualizarSalones.Seccion)+strlen(inf_ActualizarSalones.Grado)+strlen(inf_ActualizarSalones.idSalones)]; 
														 sprintf(consulta, nSQL, inf_ActualizarSalones.Seccion,inf_ActualizarSalones.Grado,inf_ActualizarSalones.idSalones);
														if(mysql_query(bjDatos,consulta)) 
													     {
													      // Error al realizar la consulta:
													      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
													      mysql_close(bjDatos);
													      //rewind(stdin);
													      //getchar();
													      return 2;
													      
													     }else{
													     	std::cout<<"Dato actualizado";
														 }
								}else{
										std::cout<<"Error al ingresar ";
								}
								
				 
				
				
			
				printf("\n\n\n");
				pausa();
				break;
 				
				}
 
			case '4':
				{
				
				system("cls");
				if(mysql_query(bjDatos, "select * from alumnos.catedraticos")) 
				     {
				      // Error al realizar la consulta:
				      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
				      mysql_close(bjDatos);
				      //rewind(stdin);
				      //getchar();
				      return 2;
				     }
				    else
				     {	
			          /* Obteniendo el resultado de la consulta */ 
			          MYSQL_RES * resultado = mysql_store_result(bjDatos);
			
			         
			          /* Recorrer fila a fila */
			          MYSQL_ROW row;
			          cout<<"                 **  L I S T A D O  D E  C A T E D R A T I C O S  **    \n\n";
			          
			           //Encabezado reporte
					   cout << left << setw(15) << setfill(' ') << "Id";
			           cout << left << setw(15) << setfill(' ') << "Nombres";
			           cout << left << setw(15) << setfill(' ') << "Apellidos\n";
			         
			            
			              while(row=mysql_fetch_row(resultado))
			              {
			               
						   // Detalle
						  	cout << left <<"\n";
			                cout << left << setw(15) << setfill(' ') << row[0];
			                cout << left << setw(15) << setfill(' ') << row[1];
			                cout << left << setw(15) << setfill(' ') << row[2];
			                
			             }
			
			          // Liberar el resultado de la consulta
			          mysql_free_result(resultado);
			
			       }
					
						std::cout<<"\n\nIngrese Nombre Del Curso: ";
						std::cin>>inf_Curso.cNombreCurso;
						std::cout<<"Ingrese Id Del Curso: ";
						std::cin>>inf_Curso.cIdCatedratico;
					
	
						//Seteando valores
					
						Save_Curso.set_C_nombreCurso(inf_Curso.cNombreCurso);
						Save_Curso.set_C_idCatedratico(inf_Curso.cIdCatedratico);
					
						
						
						//String para ralizar la inserción a la base de datos
						char sentencia[] = "INSERT INTO alumnos.cursos(Cursos, idCatedratico) VALUES(\'%s\', \'%s\')";
						// Para datos enteros utilizar  %d        
					    consulta = new char[strlen(sentencia)+sizeof(Curso)-sizeof(int)];   
						
					    if(Save_Curso.Save_Curso(bjDatos,consulta,sentencia)==0){
					    	std::cout<<"Curso guardado con exito..";
						}else{
							std::cout<<"Error al grabar Curso.."<<mysql_error(bjDatos);
						}
					
			
			
			
				printf("\n\n\n");
				pausa();
				break;
 
 				}
 				
 			case '5':
				{
				
				system("cls");
				
			
						std::cout<<"Ingrese Seccion: ";
						std::cin>>inf_Salones.Seccion;
						std::cout<<"Ingrese Grado: ";
						std::cin>>inf_Salones.Grado;
					
	
						//Seteando valores
					
						Save_Salones.set_C_Seccion(inf_Salones.Seccion);
						Save_Salones.set_C_Grado(inf_Salones.Grado);
					
						
						
						//String para ralizar la inserción a la base de datos
						char sentencia[] = "INSERT INTO alumnos.salones(Seccion, Grado) VALUES(\'%s\', \'%s\')";
						// Para datos enteros utilizar  %d        
					    consulta = new char[strlen(sentencia)+sizeof(Salones)-sizeof(int)];   
						
					    if(Save_Salones.Save_Salones(bjDatos,consulta,sentencia)==0){
					    	std::cout<<"Salon guardado con exito..";
						}else{
							std::cout<<"Error al grabar Salon.."<<mysql_error(bjDatos);
						}
			
				printf("\n\n\n");
				pausa();
				break;
 
 				}
 				
 				
 				case '6':
				{
				system("color f4");
						system("cls");
						//---GUARDAR Nuevo	
						std::cout<<"Ingrese Carnet: ";
						std::cin>>inf_Alumnos.Carnet;
						std::cout<<"Ingrese Nombre: ";
						std::cin>>inf_Alumnos.Nombre;
						std::cout<<"Ingrese Apellido: ";
						std::cin>>inf_Alumnos.Apellido;
						
						//-------------------------------------------------
						
						
						if(mysql_query(bjDatos, "SELECT c.idCursos, c.Cursos,ca.Nombre,ca.Apellido FROM alumnos.cursos c join catedraticos ca on ca.idCatedraticos=c.idCatedratico")) 
				     {
				      // Error al realizar la consulta:
				      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
				      mysql_close(bjDatos);
				      //rewind(stdin);
				      //getchar();
				      return 2;
				     }
				    else
				     {	
			          /* Obteniendo el resultado de la consulta */ 
			          MYSQL_RES * resultado = mysql_store_result(bjDatos);
			
			         
			          /* Recorrer fila a fila */
			          MYSQL_ROW row;
			          cout<<"                 **  L I S T A D O  D E  C U R S O S **    \n\n";
			          
			           //Encabezado reporte
					   cout << left << setw(15) << setfill(' ') << "Id";
			           cout << left << setw(15) << setfill(' ') << "Cursos";
			           cout << left << setw(15) << setfill(' ') << "Nombre";
			           cout << left << setw(15) << setfill(' ') << "Apellido\n";
			         
			            
			              while(row=mysql_fetch_row(resultado))
			              {
			               
						   // Detalle
						  	cout << left <<"\n";
			                cout << left << setw(15) << setfill(' ') << row[0];
			                cout << left << setw(15) << setfill(' ') << row[1];
			                cout << left << setw(15) << setfill(' ') << row[2];
			                cout << left << setw(15) << setfill(' ') << row[3];
			                
			             }
			
			          // Liberar el resultado de la consulta
			          mysql_free_result(resultado);
			
			       }
			       
						
						
						std::cout<<"\nIngrese id del Curso: ";
						std::cin>>inf_Alumnos.idCursos;
						std::cout<<"Ingrese Nota del curso asignado: ";
						std::cin>>inf_Alumnos.Nota;
						
										if(mysql_query(bjDatos, "SELECT * FROM alumnos.salones")) 
				     {
				      // Error al realizar la consulta:
				      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
				      mysql_close(bjDatos);
				      //rewind(stdin);
				      //getchar();
				      return 2;
				     }
				    else
				     {	
			          /* Obteniendo el resultado de la consulta */ 
			          MYSQL_RES * resultado = mysql_store_result(bjDatos);
			
			         
			          /* Recorrer fila a fila */
			          MYSQL_ROW row;
			          cout<<"                 **  L I S T A D O  D E  S A L O N E S **    \n\n";
			          
			           //Encabezado reporte
					   cout << left << setw(15) << setfill(' ') << "Id";
			           cout << left << setw(15) << setfill(' ') << "Seccion";
			           cout << left << setw(15) << setfill(' ') << "Grado\n";
			         
			            
			              while(row=mysql_fetch_row(resultado))
			              {
			               
						   // Detalle
						  	cout << left <<"\n";
			                cout << left << setw(15) << setfill(' ') << row[0];
			                cout << left << setw(15) << setfill(' ') << row[1];
			                cout << left << setw(15) << setfill(' ') << row[2];
			            
			                
			             }
			
			          // Liberar el resultado de la consulta
			          mysql_free_result(resultado);
			
			       }
			       
						
						std::cout<<"\nIngrese id del salon: ";
						std::cin>>inf_Alumnos.idSalones;
						
	
						//Seteando valores
					
						Save_Alumnos.set_C_Carnet(inf_Alumnos.Carnet);
						Save_Alumnos.set_C_Nombre(inf_Alumnos.Nombre);
						Save_Alumnos.set_C_Apellido(inf_Alumnos.Apellido);
						Save_Alumnos.set_C_idCursos(inf_Alumnos.idCursos);
						Save_Alumnos.set_C_Nota(inf_Alumnos.Nota);
						Save_Alumnos.set_C_idSalones(inf_Alumnos.idSalones);
					
					
					
						
						
						//String para ralizar la inserción a la base de datos
						char sentencia[] = "INSERT INTO alumnos.nuevo(Carnet, Nombre, Apellido, idCursos, Nota, idSalones) VALUES(\'%s\', \'%s\', \'%s\', \'%s\', \'%s\', \'%s\')";
						// Para datos enteros utilizar  %d        
					    consulta = new char[strlen(sentencia)+sizeof(Alumnos)-sizeof(int)];   
						
					    if(Save_Alumnos.Save_Alumnos(bjDatos,consulta,sentencia)==0){
					    	std::cout<<" guardado con exito..";
						}else{
							std::cout<<"Error al grabar alumno.."<<mysql_error(bjDatos);
						}
						
	
	
				printf("\n\n\n");
				pausa();
				break;
				
 				}
 				
 				
 			case '7':
				{
				system("cls");
				system("color f4");
				
				
				int Contra;
				int Eliminar;
				char Dato_Eliminar[5];
				
				std::cout<<" Ingresar password de super usuario para realizar la eliminacion...\n";
				std::cin>>Contra;
				if(Contra==123){
					std::cout<<" Bienvenido..";
				
					std::cout<<"\n1) Eliminar Alumno";
					std::cout<<"\n2) Eliminar Catedratico";
					std::cout<<"\n3) Eliminar Cursos";
					std::cout<<"\n4) Eliminar Salones";
					std::cin>>Eliminar;
				if(Eliminar==1){
					
														std::cout<<"\nID PARA ELIMINAR=";
														std::cin>>Dato_Eliminar;
														char nSQL[]= "Delete from alumnos.nuevo WHERE idNuevo=\'%s\'";
														 //char nSQLwhere[]= " where idNuevo=\'%s\'";
														
														consulta= new char[strlen(nSQL)+strlen(Dato_Eliminar)]; 
														 sprintf(consulta, nSQL, Dato_Eliminar);
														if(mysql_query(bjDatos,consulta)) 
													     {
													      // Error al realizar la consulta:
													      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
													      mysql_close(bjDatos);
													      //rewind(stdin);
													      //getchar();
													      return 2;
													      
													     }else{
													     	std::cout<<"Dato Eliminado";
														 }
				}else if(Eliminar==2){
														std::cout<<"\nID PARA ELIMINAR=";
														std::cin>>Dato_Eliminar;
														char nSQL[]= "Delete from alumnos.catedraticos WHERE idCatedraticos=\'%s\'";
														 //char nSQLwhere[]= " where idNuevo=\'%s\'";
														
														consulta= new char[strlen(nSQL)+strlen(Dato_Eliminar)]; 
														 sprintf(consulta, nSQL, Dato_Eliminar);
														if(mysql_query(bjDatos,consulta)) 
													     {
													      // Error al realizar la consulta:
													      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
													      mysql_close(bjDatos);
													      //rewind(stdin);
													      //getchar();
													      return 2;
													      
													     }else{
													     	std::cout<<"Dato Eliminado";
														 }
				}else if(Eliminar==3){
														std::cout<<"\nID PARA ELIMINAR=";
														std::cin>>Dato_Eliminar;
														char nSQL[]= "Delete from alumnos.cursos WHERE idCursos=\'%s\'";
														 //char nSQLwhere[]= " where idNuevo=\'%s\'";
														
														consulta= new char[strlen(nSQL)+strlen(Dato_Eliminar)]; 
														 sprintf(consulta, nSQL, Dato_Eliminar);
														if(mysql_query(bjDatos,consulta)) 
													     {
													      // Error al realizar la consulta:
													      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
													      mysql_close(bjDatos);
													      //rewind(stdin);
													      //getchar();
													      return 2;
													      
													     }else{
													     	std::cout<<"Dato Eliminado";
														 }
				}else if(Eliminar==4){
														std::cout<<"\nID PARA ELIMINAR=";
														std::cin>>Dato_Eliminar;
														char nSQL[]= "Delete from alumnos.salones WHERE idSalones=\'%s\'";
														 //char nSQLwhere[]= " where idNuevo=\'%s\'";
														
														consulta= new char[strlen(nSQL)+strlen(Dato_Eliminar)]; 
														 sprintf(consulta, nSQL, Dato_Eliminar);
														if(mysql_query(bjDatos,consulta)) 
													     {
													      // Error al realizar la consulta:
													      cout << "ERROR AL EJECUTAR CONSULTA, CONTACTE A SU PROVEEDOR: " <<  mysql_error(bjDatos) << endl;
													      mysql_close(bjDatos);
													      //rewind(stdin);
													      //getchar();
													      return 2;
													      
													     }else{
													     	std::cout<<"Dato Eliminado";
														 }
				}else{
						std::cout<<"ERROR......";
				}
				
				
				
				
				}else{
					std::cout<<" password Incorrecta..";
				}
				
				
				printf("\n\n\n");
				pausa();
				break;
				
				}
				
				
			case '8':
				{
				
				bandera=true;
 
				//exit(1);
 
				break;
	
				
				}
				default:
				system("cls");
				cout << "Opcion no valida.\a\n";
				pausa();
				break;
		}
 
    }while(bandera!=true);
  
  system("PAUSE");
	
 
    return 0;
}
 

void pausa()
 
{
    cout << "Pulsa ENTER para volver al menu...";
    getwchar();
    getwchar();
}	

	 


	
