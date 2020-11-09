#include <stddef.h>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

//Clase Conexciones computadora que permitirá crear objetos con IP nombre y nuestras estructuras de datos lineales.
class ConexionesComputadora
{
private:
    string IP;
    string Nombre;
    stack <string> ConexionesEntrantes;
    queue <string> ConexionesSalientes;

public:
    //Constructor por default
    ConexionesComputadora()
    {

    }
    //Constructor con parametros
    ConexionesComputadora(string IP_, string Nombre_, stack <string> ConexionesEntrantes_, queue <string> ConexionesSalientes_)
    {
        setIP(IP_);
        setNombre(Nombre_);
        ConexionesEntrantes = ConexionesEntrantes_;
        ConexionesSalientes = ConexionesSalientes_;
    }
    //Destructor
    ~ConexionesComputadora()
    {

    }
    //Setters
    void setIP(string IP_)
    {
        IP = IP_;
    }

    void setNombre(string Nombre_)
    {
        Nombre = Nombre_;
    }
    //Getters
    string getIP()
    {
        return IP;
    }

    string getNombre()
    {
        return Nombre;
    }

    stack <string> getStack()
    {
        return ConexionesEntrantes;
    }

    queue <string> getQueue()
    {
        return ConexionesSalientes;
    }
    //Funcion print para imprimir el objeto.
    void print()
    {
        cout << "Ahora el IP del usuario es: " << getIP() << endl;
        cout << endl;
        cout << "El hostmail del usuario es: " << getNombre() << endl;
        cout << endl;
    }
};