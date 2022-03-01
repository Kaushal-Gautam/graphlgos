//---------------Path finding using DFS--------------------
//=======076BCT002, 076BCT018, 076BCT030
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;

class graph{
private:
    int num; //no of vertices
    int graph_t [100][100]={0};
    
    // traversed list
    list <int> traversed;
        // vector as stack to hold the adjancent vertices
    vector <int> hold_stack;


public:
    graph();
    graph(int n);
    bool isReachable(int src, int dest);
    void display(int src, int dest);
    bool isTraversed(int n);
    
};

graph::graph()
{
      num = 5;
      graph_t[0][1]=1;
      graph_t[1][0]=1;
      graph_t[0][3]=1;
      graph_t[1][3]=1;
      graph_t[1][2]=1;
      graph_t[3][2]=1;
      graph_t[2][4]=1;
      graph_t[4][6]=1;

}

graph::graph(int n)
{
    num = n;
    int edge, src, dest;
    cout<<"Enter the numeber of edges:";
    cin>>edge;
    for(int i=1; i<=edge; i++)
        {
            cout<<"Enter src and des for edge no "<<i<<": ";
            cin>>src>>dest;
            graph_t[src][dest] = 1;
        }
}        

bool graph::isTraversed(int n)
{
   if(std::find(traversed.begin(), traversed.end(), n) != traversed.end())
   {
        return true;
   }
   else
   {
        return false; 
   }
};


bool graph::isReachable(int src, int dest)
{    
    //pushed the src to stack
    hold_stack.push_back(src);

    //while stack isnt empty iteration
    while (hold_stack.empty()!=true)
    {
        //popping from the stack
        int temp = hold_stack.back();
        hold_stack.pop_back();

        //adding to the traversed if it isnot in the traversed list yet
        if(isTraversed(temp)==false){
           traversed.push_back(temp);
        }

        if(temp == dest)
        {
            goto truth;
        }

        //finding the adjacent vetices
        for(int i=0; i<num; i++)
        {
            if(graph_t[temp][i]==1)//adjacent vertice isnt the destination
            {
                //if the vertice isnt traversed and isnt in the stack, pushed into the stack
                if(isTraversed(i)==false && (std::find(hold_stack.begin(), hold_stack.end(), i) == hold_stack.end()))
                {
                    hold_stack.push_back(i);
                }
            }
        }
    }

    //if the destination isn't yet reached return false
    if(traversed.back() != dest){
        return false;
    }
    
    truth:
    return true;

}

void graph::display(int src, int dest)
{
    bool isreached = isReachable ( src, dest);

    if(isreached == true)
    {
        cout<<"The path exists from "<< src <<" to " <<dest<<endl;
        cout<<"The path is :";
        for(int i:traversed)
        {
            cout<< "->" << i ;
        }
    }
    else
    {
        cout<<"The path does not  exists from "<< src <<" to " <<dest<<endl;
    }

}


int main()
{
    bool selection;
    int src, dest;
    cout<<"Enter 1 for your data entry, 0 for default graph:";
    cin>>selection;
    if(selection==0)
    {
        graph graph_1;
        src = 0; dest = 4;
        graph_1.display(src,dest);
    }
    else
    {   int n;
        cout<<"Enter the number of vertices:";
        cin>>n;
        graph graph_1(n);
        cout<<"Enter src and dest:";
        cin>>src>>dest;            

        graph_1.display(src,dest);
    }
    return 0;
}