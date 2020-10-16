#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "SortSearch.h"
#include "ReadLines.h"


using namespace std;

//Las funciones de bool las hicimos cada uno para su respectiva busqueda y ordenamiento.
template <typename T>
bool searchFecha(T &a, string &valor)
{
    return a.getDate() == valor;
}

template <typename T>
bool searchIPDestine(T &a, string &valor)
{
    return a.getIPDestine() == valor;
}

template <typename T>
bool searchServer(T &a, string &valor)
{
    return a.getServerOrigin() == valor;
}

template <typename T>
bool compareServerOrigin(T &a, T &b)
{
    return a.getServerOrigin() < b.getServerOrigin();
}

int main()
{
    //Instances for sort and search
    SecuencialSearch <Reader> seccSearch;
    Quicksort <Reader> quickSort;
    vector <Reader> DataBase;
    SelectionSort <Reader> selSort;
    //Lectura del archivo Kevin
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
    
    //Preguntas
    cout << "Hay " << DataBase.size() << " registros en total."<< endl;
    seccSearch.SecuencialsearchDate("11-8-2020", DataBase, &searchFecha);
    quickSort.sort(DataBase, &compareServerOrigin);
    seccSearch.SecuencialsearchServer("benjamin.reto.com", DataBase, &searchServer);
    
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
    string cero = ".0";
    string ip_suma = ip_result+cero;
    cout << "La red interna de la compañia es: " << ip_suma << endl;

    seccSearch.BinariSearchComputer("server.reto.com", DataBase, 0, DataBase.size(), &searchServer);
    seccSearch.SecuencialsearchIPDestine("137.172.218.129", DataBase, &searchIPDestine);

    //For para imprimir el vector
    for(int i = 0; i < DataBase.size(); i++) //36373
    {
        DataBase[i].print();
    }
    
    return 0;

}
