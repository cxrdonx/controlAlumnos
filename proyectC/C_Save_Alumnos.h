#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <mysql.h>
#include <mysqld_error.h> 
#include <string>


using namespace std;


class C_Save_Alumnos{
	
	private:
		char* C_Carnet;
		char* C_Nombre;
		char* C_Apellido;
		char* C_Nota;
		char* C_idCursos;
		char* C_idSalones;
		
	
	public:		 
	 int Save_Alumnos(MYSQL *bjDatos, char, char);


//metodos



 int Save_Alumnos(MYSQL *bjDatos, char *consulta, char *sentencia) {
 	
 	
 	int nResul=0;
 		
       
	// Formatea los datos enviados a la base de datos
	sprintf(consulta, sentencia,C_Carnet, C_Nombre,C_Apellido,C_Nota,C_idCursos,C_idSalones);
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

	 void set_C_Carnet(char* pCarnet){
	 	C_Carnet = pCarnet;
	 }
	
	 void set_C_Nombre(char* pNombre){
	 	C_Nombre = pNombre;
	 }
	void set_C_Apellido(char* pApellido){
	 	C_Apellido = pApellido;
	 }
	void set_C_Nota(char* pNota){
	 	C_Nota = pNota;
	 }
	void set_C_idCursos(char* pIdCursos){
	 	C_idCursos = pIdCursos;
	 }
	void set_C_idSalones(char* pIdSalones){
	 	C_idSalones = pIdSalones;
	 }
 
 //Getters

	 char* get_C_Carnet(){
	 	return C_Carnet;
	 }
	
	 char* get_C_Nombre(){
	 	return C_Nombre;
	 }
	 	 char* get_C_Apellido(){
	 	return C_Apellido;
	 }
	
	 char* get_C_Nota(){
	 	return C_Nota;
	 }
	 char* get_C_idCursos(){
	 	return C_idCursos;
	 }
	
	 char* get_C_idSalones(){
	 	return C_idSalones;
	 }
	 
	};
