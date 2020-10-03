#include "Linked_List.h"

using namespace std;

int main()
{    
    try
    {
        //instancias
        LinkedList<int> list;
        Node<int> node1(3, NULL);
        Node<int> node2(1, NULL);
        Node<int> node3(5, NULL);

        //Casos de prueba
        list.push(4);
        list.push(42);
        list.push(3);
        list.push(56);
        list.push(48);
        list.push(48);
        list.push(56);
        list.push(67);
        list.push(32);
        list.print();

        list.append(92);
        list.append(88);
        list.append(98);
        list.print();

        list.insert_item(66, 1);
        list.print();
        list.delete_item(1);
        list.print();
        cout << "El elemento 48" << " esta " << list.count(48) << " veces en la lista." << endl;
        cout << "El elemento 98" << " esta " << list.count(98) << " veces en la lista." << endl;
        list.DeleteList();
        list.print();
        list.push(48);
        list.push(48);
        list.push(53);
        list.push(53);
        list.push(87);
        list.push(87);
        cout << "Lista con duplicados." << endl;
        list.print();
        list.RemoveDuplicates();
        cout << "Lista sin duplicados." << endl;
        list.print();
        list.DeleteList();
        list.print();
        list.push(9);
        list.push(8);
        list.push(7);
        list.push(6);
        list.push(5);
        list.push(4);
        list.push(3);
        list.push(2);
        list.push(1);
        cout << "Lista sin inserciones." << endl;
        list.print();
        cout << "Lista con inserciones(1,3,5)." << endl;
        list.SortedInsert(&node1);
        list.SortedInsert(&node2);
        list.SortedInsert(&node3);
        list.print();
        cout << "Lista revertida." << endl;
        list.Reverse();
        list.print();

        // for (size_t i = 0; i < list.length(); i++)
        // {
        //     int item;
        //     list.get_nth(i, item);
        //     cout << item << ", ";
        // }       
    }
    catch(const char* e)
    {
        cerr << "ERROR caught: " << e << endl;
    } 

    return 0;
}
