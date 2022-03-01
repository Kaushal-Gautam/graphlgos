//DIJKSTRA'S SHORTEST PATH
//=======076BCT002, 076BCT018, 076BCT030


#include<iostream>
#include<climits>
#define COYB 0;
using namespace std;

int miniDist(int distance[], bool Tset[]) // finding minimum distance
{
    int minimum=INT_MAX,ind;               //INT_MAX IMPLIES INFINITY

    for(int k=0;k<6;k++)
    {
        if(Tset[k]==false && distance[k]<=minimum)
        {
            minimum=distance[k];
            ind=k;
        }
    }
    return ind;
}
void DijkstraAlgo(int graph[6][6],int source)
{
    int distance[6];                        // to calculate the min distance for each node
    bool Tset[6];                           // to mark visited and unvisited for each node
    for(int k = 0; k<6; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;
    }
    distance[source] = 0;                   // Source vertex distance is set 0

    for(int k = 0; k<6; k++)
    {
        int m=miniDist(distance,Tset);
        Tset[m]=true;
        for(int k = 0; k<6; k++)
        {
            if(!Tset[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k])  //relaxation eqn to update dis of neighbour vertex
                distance[k]=distance[m]+graph[m][k];
        }
    }
    cout<<"Vertex\t\tDistance from source vertex"<<endl;
    for(int k = 0; k<6; k++)
    {
        char str=65+k;
        cout<<str<<"\t\t\t"<<distance[k]<<endl;
    }
}
//main to fiind graph short path
int main()
{
    int graph[6][6]=
    {
        {0,50,45,10,0,0},
        {0,0,10,15,0,0},
        {0,0,0,0,30,0},
        {10,0,0,0,15,0},
        {0,20,35,0,0},
        {0,0,0,0,3,0}

    };
    DijkstraAlgo(graph,0);
    return COYB;
}


//
