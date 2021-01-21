#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <mysql.h>
#include <mysqld_error.h> 
#include <string>


using namespace std;


class C_Actualizar_Nota{
	
	private:
		char* C_Nota;
		char* C_idNota;
	
	public:		 
	 int Save_Curso(MYSQL *bjDatos, char, char);


//metodos



 int Actualizar_Nota(MYSQL *bjDatos, char *consulta, char *sentencia) {
 	
 	
 	int nResul=0;
 		
       
	// Formatea los datos enviados a la base de datos
	sprintf(consulta, sentencia,C_Nota, C_idNota);
    if(mysql_query(bjDatos, consulta)==0){
    	
	}else{
		cout<<"Error Curso"<<mysql_error(bjDatos);
	}  
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

	 void set_C_Nota(char* pNota){
	 	C_Nota = pNota;
	 }
	
	 void set_C_idNota(char* pidNota){
	 	C_idNota = pidNota;
	 }
	 
 
 //Getters

	 char* get_C_Nota(){
	 	return C_Nota;
	 }
	
	 char* get_C_idNota(){
	 	return C_idNota;
	 }
