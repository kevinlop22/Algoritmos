//Reto 3, codigo con el fin de utilizar diccionarios y conjuntos para la solucion de una serie de preguntas 
//basadas en la informacion de un archivo .csv
//Autores:
//Kevin López Cano A01028138
//Javier Corona del Rio A01023063
//Fecha de Creacion: 05/11/2020

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include "ConexionComputadoras.h"
#include "ReadLines.h"
using namespace std;

int main()
{
    //Creamos nuestro vector de objetos tipo "Reader".
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

    //Inicializamoss nuestro set y nuestro map.
    set <string> Hostmail;
    map <string, ConexionesComputadora> Diccionario;
    int i = 0;

    //Agregamos a nuestro set y map segun las caracteristicas pedidas en el reto basandonos en el hostname y en el server.
    while(i < DataBase.size())
    {
        string cadena = DataBase[i].getServerOrigin();
        string cadena2 = DataBase[i].getHostname_destine();
        int j = cadena.find_first_of(".\\");
        string Hostmail_result = cadena.substr(j, cadena.size());
        
        if(DataBase[i].getHostname_destine() != "-")
        {
            int l = cadena2.find_first_of(".\\");
            string Hostname_result = cadena2.substr(l, cadena2.size());
            
            if(Hostname_result != ".reto.com")
            {
                Hostmail.insert(cadena2);
            }
            string nombre;
            stack<string> stack;
            queue<string> queue;
            if(Diccionario.find(cadena) == Diccionario.end())
            {
                int j = 0;
                string ip_iterator = DataBase[j].getIPorigin();
                while(j < DataBase.size())
                {
                    if(ip_iterator == DataBase[j].getIPorigin())
                    {
                        stack.push(DataBase[j].getIPDestine());
                        string nombre = DataBase[j].getServerOrigin();
                    }
                    if(ip_iterator == DataBase[j].getIPDestine())
                        queue.push(DataBase[j].getIPorigin());
                    j++;
                }
                ConexionesComputadora conexion(ip_iterator, nombre, stack, queue);
                Diccionario.insert(make_pair(cadena, conexion));
            }

            if(Diccionario.find(cadena2) == Diccionario.end())
            {
                j = 0;
                string ip_iterator = DataBase[j].getIPDestine();
                while(j < DataBase.size())
                {
                    if(ip_iterator == DataBase[j].getIPorigin())
                    {
                        queue.push(DataBase[j].getIPDestine());
                        string nombre = DataBase[j].getServerOrigin();
                    }
                    if(ip_iterator == DataBase[j].getIPDestine())
                        stack.push(DataBase[j].getIPorigin());
                    j++;
                }
                ConexionesComputadora conexion(ip_iterator, nombre, stack, queue);
                Diccionario.insert(make_pair(cadena2, conexion));
            }
        }


        if(Hostmail_result != ".reto.com")
        {
            Hostmail.insert(cadena);
        }
        i++;
    }

    //Printers de nuestro set y de nuestro map en caso de necesitarlo.
    set<string>::iterator it = Hostmail.begin(); 
    //     while(it != Hostmail.end())
    //     {
    //         cout << (*it) << endl;
    //         it++;
    //     }
    
    map<string, ConexionesComputadora>::iterator ik = Diccionario.begin();
    // while(ik != Diccionario.end())
    // {

    //     cout << ik->first << " " << ik->second.getStack().size() << endl;
    //     ik++;
    // }

    //Pregunta 1 análisis visual.
    cout << "1) Las conexiones anomalas son:" << endl;
    cout << "3hdppu5kkb36hua85azm.org" << endl;
    cout << "rn2wzlj4fwo5rioc8egp.xxx" << endl;
    cout << endl;

    //Pregunta 2 Para encontrar las ips de las conexiones anomalas en la complejidad temporal mas eficiente recorrimos nuestro vector "DataBase" y cuando las encuentra hacemos un break que finaliza la busqueda.
    cout << "2) Las ip de las conexiones anomalas son:" << endl;
    cout << endl;
    vector <string> Anomalos;
    int p = 0;
    while(p < DataBase.size())
    {
        if(DataBase[p].getHostname_destine() == "3hdppu5kkb36hua85azm.org")
        {
            Anomalos.push_back(DataBase[p].getIPDestine());
            cout << "3hdppu5kkb36hua85azm.org: " << DataBase[p].getIPDestine() << endl;
        }
        if(DataBase[p].getHostname_destine() == "rn2wzlj4fwo5rioc8egp.xxx")
        {
            Anomalos.push_back(DataBase[p].getIPDestine());
            cout << "rn2wzlj4fwo5rioc8egp.xxx: " << DataBase[p].getIPDestine() << endl;
        }
        if(Anomalos.size() == 2)
            break;
        p++;
    }
    cout << endl;

    //Pregunta 3 Cada vez que el size de un stack es mayor que cero nos indica que tiene conexiones entrantes por lo que aumentamos un contador.
    ik = Diccionario.begin();
    int contador = 0;
    while(ik != Diccionario.end())
    {
        string cadena = ik->first;
        int l = cadena.find_first_of(".\\");
        string result = cadena.substr(l, cadena.size()-1);
        if(result == ".reto.com")
        {
            if(ik->second.getStack().size() > 0)
            {
                contador++;
            }
        }
        ik++;
    }
    cout << "3) La cantidad de ips que tienen al menos una conexión entrante es: " << contador  << endl;
    cout << endl;

    //Pregunta 4 En esta pregunta almacenamos las conexiones entrantes de las computadoras seleccionadas en un set llamado ips.
    ik = Diccionario.begin();
    set<string> ips;
    while(ik != Diccionario.end())
    {
        stack<string> stack2 = ik->second.getStack();
        while(stack2.empty() == false)
        {
            if(stack2.top() != "-")
           { 
                ips.insert(stack2.top());
           }
           stack2.pop();
        }
        ik++;
    }


    cout << "4) Las ip únicas de las conexiones entrantes estan en un set de tamaño: "<< ips.size() << endl;
    cout << endl;
    //Printer del set ips en caso de necesitarse.
    // it = ips.begin(); 
    // while(it != ips.end())
    // {
    //     cout << (*it) << endl;
    //     it++;
    // }

    //Pregunta 6 Finalmente si alguna de las ips guardadas en "ips" coincide con las ips de las conexiones anomalas podemos saber si estas tuvieron comunicacion.
    it = ips.begin();
    int p6 = 0;
    while(it != ips.end())
    {
        if((*it) == "171.172.170.23")
            p6++;
        if((*it) == "44.167.41.91")
            p6++;
        it++;
    }
    if(p6 == 0)
        cout << "6) No, no se han comunicado los datos encontrados en la pregunta 1 con las ips encontradas en el paso anterior." << endl;
    if(p6 > 0)
        cout << "6) Si, se han comunicado los datos encontrados en la pregunta 1 con las ips encontradas en el paso anterior y han tenido " << p6 << " conexiones." << endl;
    //Pregunta 7
    //Con las computadoras que elegimos en el paso anterior, se puede decir que no tuvieron comunicacion con las del paso 1 por lo que esta pregunta no aplica.
    return 0;
}