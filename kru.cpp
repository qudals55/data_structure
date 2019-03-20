  #include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define MAX 20

int check[100];

typedef struct _Graph
{
  int from;
  int to;
  int value;
}Graph;


int find(int u)
{
  if( check[u]==u)
    return u;

  return check[u]=find(check[u]);
}


void sort(Graph k[],int cnt )
{
  for(int i = 0 ; i< cnt; i++)
  {
    for(int j= 0; j <cnt-i;j++)
    {
      if(k[j].value>k[j+1].value)
      {
        Graph temp;
        temp=k[j];
        k[j]=k[j+1];
        k[j+1]=temp;
      }
    }
  }
}

void add_Kru(Graph k[],  int num,int cnt)
{
  int ans=0;
  for (int i = 0; i < cnt; i++)
    {
        int nv = find(k[i].from);
        int nw = find(k[i].to);
        if (nv == nw)
            continue;

        check[nv] = nw;
        ans += k[i].value;
      cout<<nv<<" "<<nw<<endl;
    }
    cout<<ans<<endl;
}

int main()
{


  int num=0,cnt;
  ifstream in("input.txt");
  in>>cnt;
  for(int i =1; i < cnt; i++)
    check[i]=i;
  in>>num;

  Graph k[MAX]={0,};
  for(int i =0; i < num; i ++)
    in>>k[i].from>>k[i].to>>k[i].value;

  sort(k, num);

  add_Kru(k,cnt,num);


}
