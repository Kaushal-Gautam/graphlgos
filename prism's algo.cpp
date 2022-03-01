// prism's algorithm to find minimum spanning tree
//=======076BCT002, 076BCT018, 076BCT030

#include <iostream>
#include <climits>
#define vertices 5
#define COYB 0;

int minimum_key(int k[], int mst[])
{
    int minimum  = INT_MAX, min_key,i;

    for (i = 0; i < vertices; i++)   // finds vertices that has min key value
        if (mst[i] == 0 && k[i] < minimum )
            minimum = k[i], min_key = i;
    return min_key;
}
void prim(int g[vertices][vertices]) //adjacency matrix
{

    int parent[vertices];
    int k[vertices];
    int mst[vertices];
    int i, count,edge,v;
    for (i = 0; i < vertices; i++)
    {
        k[i] = INT_MAX;            //INT_MAX resembles infinity
        mst[i] = 0;
    }
    k[0] = 0;
    parent[0] = -1;                // to make root parent
    for (count = 0; count < vertices-1; count++)
    {

        edge = minimum_key(k, mst);
        mst[edge] = 1;
        for (v = 0; v < vertices; v++)
        {
            if (g[edge][v] && mst[v] == 0 && g[edge][v] <  k[v])
            {
                parent[v]  = edge, k[v] = g[edge][v];
            }
        }
     }
     std::cout<<"\n Edge \t  Weight\n";
     for (i = 1; i < vertices; i++)
     {
       std::cout<<parent[i]<<" <-> "<< i<<"   "<<g[i][parent[i]];
    std::cout<<std::endl;
     }


}
int main()
{
    int g[vertices][vertices] = {{0, 0, 3, 0, 0},
                                {0, 0, 10, 4, 0},
                                {3, 10, 0, 2, 6},
                                {0, 4, 2, 0, 1},
                                {0, 0, 6, 1, 0},
                                };
    prim(g);
    return COYB;
}
