#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Clase Padre
template <typename T>
class Sorter
{
public:
    Sorter()
    {
        
    }
    ~Sorter()
    {
        
    }
    
    void swap(int i, int j, std::vector <T> &arr)
    {
        T aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
    }
    
    virtual void sort(std::vector <T> &arr)
    {
        
    }
};

template <typename T>
class SelectionSort : public Sorter<T>
{
    public:
    SelectionSort() {};
    ~SelectionSort() {};

    void sort(std::vector<T> &arr, bool (*compare)(T &a, T &b))
    {
        for (size_t i = 0; i < arr.size() - 1; i++)
        {
            size_t min = i;
            for (size_t j = i+1; j < arr.size(); j++)
            {
                if ((*compare)(arr[j], arr[min]))
                    min = j;
            }
            Sorter<T>::swap(i, min, arr);
        }        
    };
};

template <typename T>
class Quicksort : public Sorter<T>
{
    public:
    Quicksort() {};
    ~Quicksort() {};

    void sort(std::vector<T> &arr, bool (*compare)(T &a, T &b))
    {
        quicksort(arr, 0, arr.size() - 1, compare);
    };

    //Al inicio Javier habia implementado el seleccion Sort pero se estaba tardando aproximadamente 2 minutos en correr por lo que decidimos implementar  el ordenamiento por quick que lo hizo kevin.
    void quicksort(std::vector<T> &arr, int low, int high, bool (*compare)(T &a, T &b))
    {
        if (low < high)  
        {  
            int pi = partition(arr, low, high, compare);  
            quicksort(arr, low, pi - 1, compare);  
            quicksort(arr, pi + 1, high, compare);  
        }  
    };

    int partition (std::vector<T> &arr, int low, int high, bool (*compare)(T &a, T &b))
    {  
        T pivot = arr[high];   
        int i = (low - 1);
      
        for (int j = low; j <= high - 1; j++)  
        {   
            if ((*compare)(arr[j], pivot))  
            {  
                i++;
                Sorter<T>::swap(i, j, arr);
            }  
        }  
        Sorter<T>::swap(i+1, high, arr);
        return (i + 1);  
    }; 
};


template <typename T>
class SecuencialSearch
{
public:
    SecuencialSearch()
    {

    }
    ~SecuencialSearch()
    {

    }
    //Javier implemento la busqueda secuencial de la fecha, no lo ordenamos por que el csv ya estaba ordenado por fecha.
    void SecuencialsearchDate(string valor, vector <T> arr, bool (*compare)(T &a, string &valor))
    {
        int j = 0;
        for(size_t i = 0; i < arr.size(); i++)
        {
            if(arr[i].getDate() > valor)
                break;
            if(arr[i].getServerOrigin() == valor)
            {
                cout << "en la posicion: " << i << " esta: " << arr[i].getServerOrigin() << endl;
                break;
            }   
            if((*compare)(arr[i], valor))
                j++;
        }
        cout << "En la segunda fecha (11-8-2020) hay "<< j << " registros." << endl;
    }
    //Kevin implemento la busqueda secuanecial del IP destino, esta la utilizamos para encontrar la direccion de mail de la empresa.
    void SecuencialsearchIPDestine(string valor, vector <T> arr, bool (*compare)(T &a, string &valor))
    {
        int j = 0;
        for(size_t i = 0; i < arr.size(); i++)
        {
            if((*compare)(arr[i], valor))
                j++;
        }
        cout << "La direccion de mail de la empresa es freemailserver.com porque su direccion IP destino aparece "<< j << " veces." << endl;
    }

    //Kevin implemento la busqueda secuencial del hostname, en esta primero ordenamos los servidores por orden alfabetico y como benjamin era la primer variable ya que empieza por b la utilizamos como comparador.
    void SecuencialsearchServer(string valor, vector <T> arr, bool (*compare)(T &a, string &valor))
    {
        for(size_t i = 0; i < arr.size(); i++)
        {
            if((*compare)(arr[i], valor))
            {
                cout << arr[i].getServerOrigin() << " esta en la posicion:  " << i << " por lo que Si, una de las computadoras si pertenece a alguno de ellos." << endl;
                break;
            }   
        }
        
    }

    //Javier realizo la implementacion de la busqueda binaria, la utilizamos para buscar si server.reto.com, utilizamos busqueda binaria por que es mas eficiente si el arreglo esta ordenado en orden alfabetico.
    int BinariSearchComputer(string valor, std::vector <T> &arr, int primero, int ultimo, bool (*compare)(T &a, string &valor))
    {
        int i = 0;
        if(ultimo <= primero)
        {
            i = -1;
            cout << "Server.reto.com está en la posicion: " << i <<  endl;
        }
        else
        {
            int medio = ((primero + ultimo)/2);
            if((*compare)(arr[medio], valor))
            {
                i = medio;
                cout << "Server.reto.com está en la posicion: " << i <<  endl;
            }
            else if(valor < arr[medio].getServerOrigin())
            {
                i = BinariSearchComputer(valor, arr, primero, medio-1, (*compare));
            }
            else
            {
                i = BinariSearchComputer(valor, arr, medio+1, ultimo, (*compare));
            }
        }
        return i;
        
    }
    
};


