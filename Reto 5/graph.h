#ifndef _GRAPH_H_
#define _GRAPH_H_

#include<iostream> 
#include <list>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
template <class T>
class GraphVertex
{
private:
    T val;
    std::vector<int> adj;
public: 
    ~GraphVertex() {};
    GraphVertex() {};
    GraphVertex(T _val) {val = _val;};

    T get_val() {return val;};
    void set_val(T _val) {val = _val;};

    std::vector<int> get_adj() {return adj;};
    void add_to_adj(int idx) {adj.push_back(idx);};
};

template <class T>
class Graph
{
private:
    std::vector<GraphVertex<T> > nodes;
    bool is_directed;

public:
    ~Graph() {};
    Graph() {is_directed=true;};

    void add_node(T val)
    {
        GraphVertex<T> node(val);
        nodes.push_back(node);
    };

    void add_edge(int src, int dst)
    {
        bool found = false;
        for (auto idx : nodes[src].get_adj())
        {
            if (idx == dst)
            {
                found = true;
            }
        }
        if (!found)
        {
            nodes[src].add_to_adj(dst);
        }

    };


    void BFS(int start_vertex)
    { 
        vector<bool> visited(nodes.size(), false);
        queue<int> queue;
        visited[start_vertex] = true;
        queue.push(start_vertex);

        while(!queue.empty())
        {
            int s = queue.front();
            cout << nodes[s].get_val() << " ";

            queue.pop();
            for(vector<int>::iterator i = nodes[s].get_adj().begin(); i != nodes[s].get_adj().end(); i++)
            {
                if(!visited[*i])
                {
                    queue.push(*i);
                    visited[*i] = true;
                }
            }
        }
        cout << endl;
    };

    void DFS(int start_vertex)
    {
        vector<bool> visited(nodes.size(), false);
        stack<int> stack;

        stack.push(start_vertex);

        while(!stack.empty())
        {
            int s = stack.top();
            stack.pop();

            if(!visited[s])
            {
                visited[s] = true;
                cout << nodes[s].get_val() << " ";
            }

            for(vector<int>::iterator i = nodes[s].get_adj().begin(); i != nodes[s].get_adj().end(); i++)
            {
                if(visited[*i])
                {
                    stack.push(*i);
                }
            }
        }
        cout << endl;
    };

    void make_node_conexion(T val, T val2)
    {
        int indice1 = 0;
        int indice2 = 0;
        for(int i = 0; i < nodes.size(); i++)
        {
            if(nodes[i].get_val() == val)
            {
                indice1 = i;
                break;
            }
        }
        for(int j = 0; j < nodes.size(); j++)
        {
            if(nodes[j].get_val() == val2)
            {
                indice2 = j;
                break;
            }
        }
        add_edge(indice1, indice2);
    }

    vector<GraphVertex<T> > getNodes()
    {
        return nodes;
    }

    int return_indice(T val)
    {
        int indice = 0;
        int i = 0;
        while(i != nodes.size())
        {
            if(nodes[i].get_val() == val)
            {
                indice = i;
                break;
            }
            i++;
        }
       return indice;
    }

    void print_edges()
    {
        for (int i = 0; i < nodes.size(); i++)
        {
            cout << nodes[i].get_val() << " : ";
            for (int j = 0; j < nodes[i].get_adj().size(); j++)
            {
                cout << nodes[j].get_val() << " -> ";
            }
            cout << endl;
            cout << nodes[i].get_adj().size();
            cout << endl;
        }
    };

    std::vector<GraphVertex<T> > get_node()
    {
        return nodes;
    }



};

#endif

