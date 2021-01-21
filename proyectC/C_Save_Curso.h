#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <mysql.h>
#include <mysqld_error.h> 
#include <string>


using namespace std;


class C_Save_Curso{
	
	private:
		char* C_nombreCurso;
		char* C_idCatedratico;
	
	public:		 
	 int Save_Curso(MYSQL *bjDatos, char, char);


//metodos



 int Save_Curso(MYSQL *bjDatos, char *consulta, char *sentencia) {
 	
 	
 	int nResul=0;
 		
       
	// Formatea los datos enviados a la base de datos
	sprintf(consulta, sentencia,C_nombreCurso, C_idCatedratico);
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

	 void set_C_nombreCurso(char* pNombreCurso){
	 	C_nombreCurso = pNombreCurso;
	 }
	
	 void set_C_idCatedratico(char* pidCatedratico){
	 	C_idCatedratico = pidCatedratico;
	 }
	 
 
 //Getters

	 char* get_C_nombreCurso(){
	 	return C_nombreCurso;
	 }
	
	 char* get_C_idCatedratico(){
	 	return C_idCatedratico;
	 }
	};
