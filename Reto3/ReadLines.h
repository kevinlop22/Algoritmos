//Reto 4, codigo que permite crear objetos tipo "Reader" para acceder a la informacion de un archivo csv 
//con el objetivo desolucionar una serie de preguntas.
//Autores:
//Kevin López Cano A01028138
//Javier Corona del Rio A01023063
//Fecha de Creacion: Sexta semana de clases
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//Class Reader que sera la encargado de crear cada linea como un objeto, luego esos objetos se agregaran a un vector.
class Reader
{
private:
    string date, hour, ip_origin, server_origin, hostmail_origin, ip_destine, server_destine, hostname_destine;
public:
    Reader()
    {

    }
    Reader(string date_, string hour_, string ip_origin_, string server_origin_, string hostmail_origin_, string ip_destine_, string server_destine_, string hostname_destine_)
   {
       date = date_;
       hour = hour_;
       ip_origin = ip_origin_;
       server_origin = server_origin_;
       hostmail_origin = hostmail_origin_;
       ip_destine = ip_destine_;
       server_destine = server_destine_;
       hostname_destine = hostname_destine_;
   } 
   ~Reader()
   {

   }

    //Javier hizo la implementacion de los getters que luego fueron utilizados en las funciones bool.
   string getDate()
   {
       return date;
   }

   string getServerOrigin()
   {
       return hostmail_origin;
   }

   string getIPorigin()
   {
       return ip_origin;
   }

   string getIPDestine()
   {
       return ip_destine;
   }

   string getHostname_destine()
   {
       return hostname_destine;
   }

    //Funcion print para imprimir los objetos del vector DataBase kevin
   void print()
   {
       cout << date << "," << hour << "," << ip_origin << "," <<  server_origin << "," << hostmail_origin << "," << ip_destine << "," << server_destine << "," << hostname_destine << endl;
   }

};






