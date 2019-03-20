// Shortestpath 알고리즘 : Shortestpath의 의미는 주어진 행렬의 각 점들을 한점을 기준점을 통해서 가장 빠르게 접근핤 수 있는 알고리즘이다.
// 먼저 기준점을 잡고, choose 함수를 통해 기준점에서 다른 점으로 이동할 수 있는 가장 짧은거리를 구한다.
// 이 choose함수를 이용하여 얻은 최단거리의 점과 기준점을 제외하고, 나머지 점들의 거리를 Shortestpath 함수를 통해서 비교한다.
// 비교하는 방법은 기준점에서 직접가는 거리가 더 긴지, 아니면 choose 함수를 통해서 가는 거리가 더긴지를 판단하고, 만약 choose함수를 통해서 가는거리가 더 짧다면 최단 거리를 choose함수를 통해서 가는 거리로 바꿔준다.
// 또 그 최단거리가 정해지면 다음 점으로 이동해 똑같은 알고리즘을 진행한다.
// 이런식으로 방문점 found[i]가 모두 true가 될때까지 진행하면 모든점을 이동하는 최단 거리를 계산할 수 있게 된다.





#include <iostream>

using namespace std;


int choose(int dist[], int n, bool found[]) //현재 위치에서 방문하지 않은 곳 중에 한번에 이동할 수 있는 가장 작은 값을 찾는다.
{
  int i, min= 999,k;
  for( i =0; i<n ; i ++)
  {
    if(dist[i]<min && !found[i])  // 현재 위치에서 방문하지 않은, 가장 작은 값을 골라 최단경로로 설정한다.
    {
      min = dist[i];
      k=i;
    }
  }
  return k;
}

void Shortestpath(int v, int cost[7][7], int dist[],int n, bool found[]) // choose에서 고른 최단경로를 가지고, 한번에 이동하는 거리가 더 긴지, 가장 최단 거리를 거쳐서 이동하는 거리가 더큰지 비교하여 택한다.
{
  int i, u ,w;
  for(int i =0; i<n ; i++ )
  {
    found[i]= false; // 처음에는 아무 곳도 방문하지 않은 곳으로 설정한다.
    dist[i]=cost[v][i]; // 처음에는 이동거리를 출발점에 맞게 설정한다.
  }
  found[v]= true; // 시작점을 방문했다고 하고,
  dist[v]=0;  //시작점부터 시작점 까지의 거리는 0이다.

  for(int i =0; i <n-1; i++)
  {
    u= choose(dist, n, found);  // 시작점 부터 이동할 수 있는 가장 짧은 방문점을 택한다.
    found[u]= true; // 그 방문점을 방문했다고 마킹하고,
    for(int w=0; w<n; w++)
    {
      if(!found[w]) // 그 방문점을 제외한 다른 방문점들의 최단 거리를 바꾼다.
      {
        if(dist[u]+ cost[u][w]<dist[w])   //직접이동보다 거쳐서 이동하는 거리가 작다면
          dist[w]=dist[u]+ cost[u][w];  // 최단거리를 직접 이동하는 거리가 아닌 거쳐서 이동하는 거리로 바꾼다.
      }
    }
    for(int k=0;k < n; k++) // 한번 이동 할 때마다의 최단거리를 출력한다.
      cout<<dist[k]<<" ";
    cout<<endl;
  }

}


int main()
{
  int dist[7]={0,};
  bool found[7];

  int matrix[7][7]={{100,2,4,5,100,100,100},{100,100,100,2,7,100,100},{100,100,100,1,100,4,100},{100,2,1,100,4,3,100},{100,7,100,4,100,1,5},{100,100,4,3,1,100,7},{100,100,100,100,7,5,100}};

  for(int i =0; i < 7; i++)
  {
    for(int j =0; j < 7 ; j ++)
      cout<<matrix[i][j]<<" ";
    cout<<endl;
  }
  Shortestpath(0, matrix,  dist, 7, found);

}
