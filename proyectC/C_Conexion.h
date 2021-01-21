//created by: cxrdonx
#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <mysql.h>
#include <mysqld_error.h> 

using namespace std;

class C_Conexion{
	

	//Métodos
	 public:
	 void conecta_base_datos(MYSQL *bjDatos);	

};


void C_Conexion::conecta_base_datos(MYSQL  *bjDatos){
 
 if(mysql_real_connect(bjDatos, "localhost", "root", "41092193CristopherC", "alumnos", 3306, NULL, 0)){ 
	std::cout<<"Conexion realizada con exito \n";
 }
 else{
 	std::cout<<"Conexion fallida \n"<<mysql_error(bjDatos); 	
 }
 
 }
 
