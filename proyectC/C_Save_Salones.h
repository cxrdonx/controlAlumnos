#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <mysql.h>
#include <mysqld_error.h> 
#include <string>


using namespace std;


class C_Save_Salones{
	
	private:
		char* C_Seccion;
		char* C_Grado;
	
	public:		 
	 int Save_Salones(MYSQL *bjDatos, char, char);


//metodos



 int Save_Salones(MYSQL *bjDatos, char *consulta, char *sentencia) {
 	
 	
 	int nResul=0;
 		
       
	// Formatea los datos enviados a la base de datos
	sprintf(consulta, sentencia,C_Seccion, C_Grado);
        
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

	 void set_C_Seccion(char* pSeccion){
	 	C_Seccion = pSeccion;
	 }
	
	 void set_C_Grado(char* pGrado){
	 	C_Grado = pGrado;
	 }
	 
 
 //Getters

	 char* get_C_Seccion(){
	 	return C_Seccion;
	 }
	
	 char* get_C_Grado(){
	 	return C_Grado;
	 }
	};
