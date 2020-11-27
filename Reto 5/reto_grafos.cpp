//Reto 5, codigo con el fin de utilizar grafos para la solucion de una serie de preguntas 
//basadas en la informacion de un archivo .csv
//Autores:
//Kevin López Cano A01028138
//Javier Corona del Rio A01023063
//Fecha de Creacion: 26/11/2020


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include "ReadLines.h"
#include "graph.h"
using namespace std;

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
    //Creamos un vector con 10 grafos
    vector < Graph<string> > grafos(10);
    // //Creamos un set para las ips
    set <string> ips;
    string ip_company = "10.221.242";
    int j = 0;
    for(int i = 1; i < DataBase.size(); i++)
    {
        string fecha = DataBase[i].getDate();
        string fecha2 = DataBase[i-1].getDate();
        string ip = DataBase[i].getIPorigin();
        string ip2 = DataBase[i].getIPDestine();
        int w = ip.find_last_of(".\\");
        string ip1 = ip.substr(0, w);
        string ip3 = ip2.substr(0, w);

        if(ips.find(ip) == ips.end())
        {
            grafos[j].add_node(ip);
            ips.insert(ip);
        }
        if(ip3 == ip_company)
        {
            
            if(ips.find(ip2) == ips.end())
            {
                grafos[j].add_node(ip2);
                ips.insert(ip2);
            }
            grafos[j].make_node_conexion(ip, ip2);
        }
        if(fecha != fecha2)
        {
            ips.clear();
            j++;
        }
    }
    // for(int i = 0; i < 10; i++)
    // {
    //     grafos[i].print_edges();
    // }
    //Pregunta 1
    string a = "10.221.242.69";
    int total = 0;
    cout << "A = 10.221.242.69" << endl;
    cout << "Pregunta 1" << endl;
    for(int i = 0; i < grafos.size(); i++)
    {
        for(int j = 0; j < grafos[i].get_node().size(); j++)
        {
            if(a == grafos[i].get_node()[j].get_val())
            {
                cout << "Dia: " << i+1 << " Cantidad: " << grafos[i].get_node()[j].get_adj().size()<<  endl;
                total = total+grafos[i].get_node()[j].get_adj().size();
            }
        }
    }
    cout << "la cantidad de computadoras con las que se ha conectado A en el total de dias es " << total << ", pero no es el vértice que más conexiones salientes hacia la red interna tiene" << endl;
    for(int i = 0; i < grafos.size(); i++)
    {
        for(int j = 0; j < grafos[i].get_node().size(); j++)
        {
            grafos[i].get_node()[j].get_adj().size();
        }
    }
    cout << "Pregunta 2" << endl;
    int g = 0;
    for(int i = 0; i < grafos.size(); i++)
    {
        int h = 0;
        for(int j = 0; j < grafos[i].get_node().size(); j++)
        {
            for(int k = 0; k < grafos[i].get_node()[j].get_adj().size(); k++)
            {
                if(grafos[i].get_node()[j].get_adj()[k] == grafos[i].return_indice(a))
                {
                    h++;
                    g++;
                }
            }
            
        }
        cout << "Dia: " << i+1 << " Cantidad: " << h <<  endl;
    }
    if(g == 0)
    {
        cout << "No existen conexiones de las demás computadoras hacia A" << endl;
    }
    if(g > 0)
    {
        cout << "Si existen conexiones de las demás computadoras hacia A y son: " << g << endl;
    }
    //Creamos un vector con 10 grafos
    vector < Graph<string> > grafos2(10);
    // //Creamos un set para las ips
    set <string> ips2;
    j = 0;
    for(int i = 1; i < DataBase.size(); i++)
    {
        string fecha = DataBase[i].getDate();
        string fecha2 = DataBase[i-1].getDate();
        string ip = DataBase[i].getIPorigin();
        string ip2 = DataBase[i].getIPDestine();
    
        if(ips2.find(ip) == ips2.end())
        {
            grafos2[j].add_node(ip);
            ips2.insert(ip);
        }
        if(DataBase[i].get_server_destine() == "443")
        {
            if(ips2.find(ip2) == ips2.end())
            {
                grafos2[j].add_node(ip2);
                ips2.insert(ip2);
            }
            grafos2[j].make_node_conexion(ip, ip2);
        }
        if(fecha != fecha2)
        {
            ips2.clear();
            j++;
        }
    }

    // for(int i = 0; i < 10; i++)
    // {
    //     grafos2[i].print_edges();
    // }
    string b = "44.167.41.91";
    cout << "B = rn2wzlj4fwo5rioc8egp.xxx" << endl;
    cout << "Pregunta 3" << endl;
    
    for(int i = 0; i < grafos2.size(); i++)
    {
        for(int j = 0; j < grafos2[i].get_node().size(); j++)
        {
            grafos2[i].get_node()[j].get_adj().size();
        }
    }
    g = 0;
    for(int i = 0; i < grafos2.size(); i++)
    {
        int h = 0;
        for(int j = 0; j < grafos2[i].get_node().size(); j++)
        {
            for(int k = 0; k < grafos2[i].get_node()[j].get_adj().size(); k++)
            {
                if(grafos2[i].get_node()[j].get_adj()[k] == grafos2[i].return_indice(b))
                {
                    h++;
                    g++;
                }
            }
            
        }
        cout << "Dia: " << i+1 << " Cantidad: " << h <<  endl;
    }
    for(int i = 0; i < grafos2.size(); i++)
    {
        for(int j = 0; j < grafos2[i].get_node().size(); j++)
        {
            grafos2[i].get_node()[j].get_adj().size();
        }
    }
    g = 0;
    cout << "Pregunta 4" << endl;
    cout << "Conexiones a C por dia:" << endl;
    cout << "C = play.google.com" << endl;
    string c = "28.90.150.27";
    for(int i = 0; i < grafos2.size(); i++)
    {
        int h = 0;
        for(int j = 0; j < grafos2[i].get_node().size(); j++)
        {
            for(int k = 0; k < grafos2[i].get_node()[j].get_adj().size(); k++)
            {
                if(grafos2[i].get_node()[j].get_adj()[k] == grafos2[i].return_indice(c))
                {
                    h++;
                    g++;
                }
            }
            
        }
        cout << "Dia: " << i+1 << " Cantidad: " << h <<  endl;
    }
    return 0;
}