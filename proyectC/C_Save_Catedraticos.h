#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <mysql.h>
#include <mysqld_error.h> 
#include <string>


using namespace std;


class C_Save_Catedraticos{
	
	private:
		char* C_nombre;
		char* C_apellido;
	
	public:		 
	 int Save_Catedraticos(MYSQL *bjDatos, char, char);


//metodos



 int Save_Catedraticos(MYSQL *bjDatos, char *consulta, char *sentencia) {
 	
 	
 	int nResul=0;
 		
       
	// Formatea los datos enviados a la base de datos
	sprintf(consulta, sentencia,C_nombre, C_apellido);
        
	//Ejecuta consulta para realizar insert en base de datos
    if(!mysql_query(bjDatos, consulta)){
    	nResul = 0;
	}
	else
	{
		nResul = 1;
	}	    	
 	
 	return nResul;
 }
 
 //Setters

	 void set_C_nombre(char* pNombre){
	 	C_nombre = pNombre;
	 }
	
	 void set_C_apellido(char* pApellido){
	 	C_apellido = pApellido;
	 }
	 
 
 //Getters

	 char* get_C_nombre(){
	 	return C_nombre;
	 }
	
	 char* get_C_apellido(){
	 	return C_apellido;
	 }
	};
