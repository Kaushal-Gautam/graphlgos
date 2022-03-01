// Cpp Program for Floyd Warshall Algorithm for shortest path
//=======076BCT002, 076BCT018, 076BCT030

#include<iostream>
#include<iomanip>
#define V 7
#define INF 99999  // for infinity
#define COYB 0

using namespace std;
void printSolution(int dist[][V]);     // disp min distance from each vertices to other
void floydWarshall (int graph[][V])
{

    int dist[V][V], i, j, k;  /* dist[][] will be the output matrix that will finally have the shortest distances between every pair of vertices */

    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])  // relaxation eqn
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist);
}
void printSolution(int dist[][V])
{
    std::cout<<"Matrix that shows the shortest distances between every pair of vertices \n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                std::cout<<std::setw(7)<<"INF";
           else
                    cout<<setw(7)<<dist[i][j];
        }
        cout<<"\n";
    }
}
int main()
{

    int graph[V][V] = {
    {0, 3, 6,INF,INF,INF,INF},
   {3, 0, 2, 1,INF,INF,INF},
   {6, 2, 0, 1, 4, 2,INF},
   {INF, 1, 1, 0, 2, INF, 4},
   {INF,INF, 4, 2, 0, 2, 1},
   {INF,INF, 2,INF, 2, 0, 1},
   {INF,INF,INF, 4, 1, 1, 0}
                      };

    floydWarshall(graph);   // the solution
    return COYB;
}
