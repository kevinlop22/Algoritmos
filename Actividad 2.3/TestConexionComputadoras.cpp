//Actividad 2.3, codigo con el fin de utilizar estrcuturas de datos lineales para la solucion de una serie de preguntas 
//basadas en la informacion de un archivo .csv
//Autores:
//Kevin López Cano A01028138
//Javier Corona del Rio A01028
//Fecha de Creacion: 14/10/2020

#include "ConexionComputadoras.h"
#include <fstream>
#include "ReadLines.h"

int main()
{
    vector <Reader> DataBase;
    ifstream equipo6;
    equipo6.open("equipo6.csv");
    string date, hour, ip_origin, server_origin, hostmail_origin, ip_destine, server_destine, hostname_destine;
    while (equipo6.good())
    {
        getline(equipo6, date, ',');
        getline(equipo6, hour, ',');
        getline(equipo6, ip_origin, ',');
        getline(equipo6, server_origin, ',');
        getline(equipo6, hostmail_origin, ',');
        getline(equipo6, ip_destine, ',');
        getline(equipo6, server_destine, ',');
        getline(equipo6, hostname_destine, '\n');
        Reader object(date, hour, ip_origin, server_origin, hostmail_origin, ip_destine, server_destine, hostname_destine);
        DataBase.push_back(object);
    }
    equipo6.close();
    stack<string> stack;
    queue<string> queue;

    int i = 0;
    string ip_search = "-";
    while(ip_search == "-")
    {
        ip_search = DataBase[i].getIPorigin();
        i++;
    }
    //Con el while buscamos la direccion IP de la compañia.
    int j = ip_search.find_last_of(".\\");
    string ip_result = ip_search.substr(0, j);
    string ipGenerator;
    cout << "Ingrese un numero del 1 al 150 para generar su IP: " << endl;
    cin >> ipGenerator;
    string ip_suma = ip_result+"."+ipGenerator;
    cout << endl;
    cout << "Tu IP generada es: " << ip_suma << endl;
    cout << endl;
    int check = 0;
    string nombre;
    while(check != DataBase.size())
    {
        if(ip_suma == DataBase[check].getIPorigin())
        {
            queue.push(DataBase[check].getIPDestine());
            nombre = DataBase[check].getServerOrigin();
        }
        if(ip_suma == DataBase[check].getIPDestine())
            stack.push(DataBase[check].getIPorigin());
        check++;
    }
    ConexionesComputadora conexion(ip_suma, nombre, stack, queue);
    conexion.print();
    int w = conexion.getStack().top().find_last_of(".\\");
    string result2 = conexion.getStack().top();
    cout << "La ip de la última conexión que recibió esta computadora es: "  << result2 << endl;
    string result3 = conexion.getStack().top().substr(0, w);
    if(result3 == ip_result)
    {
        cout << "La ultima conexion es interna." << endl;
        cout << endl;
    }
    else
    {
        cout << "La ultima conexion es externa." << endl;
        cout << endl;
    }
    cout << "Son " << stack.size()<< " conexiones entrantes en esta computadora." << endl;
    cout << endl;
    cout << "Son " << queue.size()<< " conexiones salientes en esta computadora." << endl;
    cout << endl;
    while(conexion.getStack().empty() == false)
   {
       string v1 = conexion.getStack().top();
       conexion.getStack().pop();
       string v2 = conexion.getStack().top();
       if(v1 == v2)
       {
           conexion.getStack().pop();
           string v3 = conexion.getStack().top();
           if(v3 == v2)
           {
               cout << "Si, esta computadora tiene 3 conexiones seguidas a un mismo sitio web." << endl;
               cout << endl;
               break;
           }
       }
   } 
    return 0;

}