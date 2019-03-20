#include <iostream>
#include <string.h>
using namespace std;

#define max_size 10

int visited[max_size] = {0};

class Node
{
  public:
    Node *link;
    int num;
    Node(int data){ num = data; link = NULL;}

  friend class Graph;
};

class Graph
{
  private:
    Node *front ;
     Node *rear;
    Node *head;
  public:
    void insert(int data);
    Graph(){head=NULL; front = NULL; rear = NULL;}
    Node* getHead(){return head;}
    void initHead(){head=NULL;}
    void traverse();
    void DFS(int v);
    void BFS(int v);
    void enque(int data);
    int deque();
};

Graph graph[max_size];



void Graph::insert(int data)
{
  Node *temp = new Node(data);
  Node *p;
    if(head==NULL)
    {

        head = temp;
    }
    else
    {
        p=head;

        while( p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp;
    }
}

void Graph::traverse()
{
    Node *p;

    p=head;

    while(p!=NULL)
    {
        cout << p->num << " ";
        p=p->link;
    }

    cout << endl;
}

void Graph::DFS(int v)
{
    Node *w = graph[v].head;

    visited[v] = 1;

    cout << v << " ";


      for( w=graph[v].head ; w!=NULL ; w = w->link)
      {
        if(w->link != NULL)
        {
          if( !visited[(w->link)->num] )
            DFS( (w->link)->num );
        }
      }


}

void Graph::BFS(int v)
{
  Node *p;
    visited[v]=1;

    enque(v);

    cout << v << " ";

    while(front)
    {


        for(p=graph[v].head ; p ; p=p->link)
        {
            if(!visited[p->num])
            {
                enque(p->num);
                visited[p->num]=1;
                cout << p->num << " ";
            }
        }

        v=deque();
    }

}

void Graph::enque(int data)
{
    Node *temp = new Node(data);

    if (front == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->link = temp;
        rear = temp;
    }
}

int Graph::deque()
{
    Node *p;
    int num;

    num = front->num;
    p = front;

    if (front == rear) //한칸 차있는 경우에 프론트와 리어가 같으므로 삭제해주고, 초기화시킨다.
    {
      front = NULL;
      rear = NULL;
    }
    else
      front = front->link;

    delete p;

    return num;
}
int main()
{
    Graph g;
    int input;
    int num;
    int index=0;


    graph[0].insert(0); graph[0].insert(1);  graph[0].insert(2);
    graph[1].insert(1); graph[1].insert(0); graph[1].insert(3); graph[1].insert(4);
    graph[2].insert(2); graph[2].insert(0); graph[2].insert(5); graph[2].insert(6);
    graph[3].insert(3); graph[3].insert(1); graph[3].insert(7);
    graph[4].insert(4); graph[4].insert(1); graph[4].insert(7);
    graph[5].insert(5); graph[5].insert(2); graph[5].insert(7);
    graph[6].insert(6); graph[6].insert(2); graph[6].insert(7);
    graph[7].insert(7); graph[7].insert(3); graph[7].insert(4); graph[7].insert(5); graph[7].insert(6);

    for(int i = 0; i <=7 ; i++)
    {
        graph[i].traverse();
        cout << endl;
    }

    graph[0].DFS(0);

}
