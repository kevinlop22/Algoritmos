//Reto 4, codigo con el fin de utilizar arboles de ordenamiento para la solucion de una serie de preguntas 
//basadas en la informacion de un archivo .csv
//Autores:
//Kevin López Cano A01028138
//Javier Corona del Rio A01023063
//Fecha de Creacion: 06/11/2020


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include "ConexionComputadoras.h"
#include "ReadLines.h"
#include "bst.h"
using namespace std;

//Funcion que recibe una fecha y un vector y devuelve un map con las conexiones a cada sitio web.
map<string, int> conexionesPorDia(string fecha, vector<Reader> DataBase)
{
    map <string, int> Dominios_por_Fecha;
    int i = 0;
    while(i < DataBase.size())
    {
        if(fecha == DataBase[i].getDate())
        {
            if(DataBase[i].getHostname_destine() != "-")
            {
                string cadena3 = DataBase[i].getHostname_destine();
                int l = cadena3.find_first_of(".\\");
                string Hostname_result2 = cadena3.substr(l, cadena3.size());
                if(Hostname_result2 != ".reto.com")
                {
                    if(Dominios_por_Fecha.find(cadena3) == Dominios_por_Fecha.end())
                    {
                        Dominios_por_Fecha.insert(make_pair(cadena3, 1));
                    }
                    if(Dominios_por_Fecha.find(cadena3) != Dominios_por_Fecha.end())
                    {
                        Dominios_por_Fecha[cadena3]++;
                    }
                }
            }
        }
        i++;
    }
    //Printer del diccionario en caso de que se requiera.
    // map<string, int>::iterator ik = Dominios_por_Fecha.begin();
    // while(ik != Dominios_por_Fecha.end())
    // {

    //     cout << ik->first << ": " << ik->second << endl;
    //     ik++;
    // }
    return Dominios_por_Fecha;  
}

//Funcion bool para organizar las tuplas.
bool pairCompare(const pair<string, int>& firstElem, const pair<string, int>& secondElem)
{
     return firstElem.second > secondElem.second;
}

//Funcion que imprime las n top conexiones en una fecha especifica
void top(int n, string fecha, map <string, int> Dominios_por_Fechas)
{
    BinarySearchTree<pair<string,int> > top;
    map<string, int>::iterator ik = Dominios_por_Fechas.begin();
    vector<pair<string, int> > v;
    while(ik != Dominios_por_Fechas.end())
    {
        top.insert_node_recursive(make_pair(ik->first, ik->second));
        v.push_back(make_pair(ik->first, ik->second));
        ik++;
    }
    sort(v.begin(), v.end(), pairCompare);

    for(int i = 0; i < n and i < v.size(); i++)
    {
        cout << v[i].first << ": " << v[i]. second << endl;
    }
    cout << endl;

    //Printers de nuestro bst en caso de que se requiera.
    //top.print_preorder();
    //top.print_bts();
}
    

int main()
{
    //Creamos nuestros objetos "Reader" en un vector
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

    int i = 0;
    //Agregamos todas las fechas de nuestro archivo csv a un set.
    set <string> Dates;
    while(i < DataBase.size())
    {
        Dates.insert(DataBase[i].getDate());
        i++;
    }

    //Recorremos nuestro set para imprimir el top 5 de cada fecha de nuestro csv.
    set<string>::iterator it = Dates.begin(); 
        while(it != Dates.end())
        {
            map <string, int> Dominios_por_Fechas = conexionesPorDia(*it, DataBase);
            cout << "Date: " << *it << endl;
            top(5, *it, Dominios_por_Fechas);
            it++;
        }
    cout << "Preguntas:" << endl;
    cout << "¿Existe algún sitio que se mantenga en el top 5 en todos los días?" << endl;
    cout << "R//Si, el sitio “freemailserver.com” está presente en el top 5 de todas las fechas." << endl;
    cout << "¿Existe algún sitio que entre al top 5 a partir de un día y de ahí aparezca en todos los días subsecuentes?" << endl;
    cout << "R//Si, el sitio “rn2wzlj4fwo5rioc8egp.xxx” entra en el top 5 a partir de la fecha número 6 y de ahí en adelante aparece en todos los top 5 siguientes." << endl;
    cout << "¿Existe algún sitio que aparezca en el top 5 con una cantidad más alta de tráfico que lo normal?" << endl;
    cout << "Si, el sitio “freemailserver.com” aparece con una cantidad de entre 1200 y 1400 aproximadamente en el top 5 de cada fecha lo cual genera un flujo muy alto diariamente. Ademas, el sitio “rn2wzlj4fwo5rioc8egp.xxx” a partir de la sexta fecha aparece en todos los tops 5 con entre 99 y 244 visitas lo cual también es un flujo de visitas muy elevado." << endl;

    return 0;
}