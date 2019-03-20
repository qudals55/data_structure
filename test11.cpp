#include <iostream>

using namespace std;
#define TRUE 1
#define FALSE 0

#define VERTICES 6
#define INF 100

int adj_mat[VERTICES][VERTICES]=
{
{ INF, 6, 1, 5, INF, INF},
{ 6,  INF, 4, INF, 3, INF},
{ 1, 4, INF, 5, 6, 5 },
{ 5, INF, 5, INF, INF, 2 },
{ INF, 3, 6, INF, INF, 6 },
{ INF, INF, 5, 2, 6, INF }};

int selected[VERTICES];
int dist[VERTICES];

// 최소 dist[v] 값을 갖는 정점을 반환
int get_min_vertex(int n)
{
	int v,i;

	for (i = 0; i <n; i++)
	{
		if (!selected[i])
		{
			v = i;
			break;
		}
	}
	// 선택하지 않은 간선들 중 최소 가중치값을 갖는 정점을 찾는다.
	for (i = 0; i < n; i++)
	{
		if( !selected[i] && (dist[i] < dist[v]))
			v = i;
	}

	return (v);
}

//
void prim(int s, int n)
{
	int i, u=0, v,k;
  int q= 10;

	for(u=0;u<n;u++)
		dist[u]=INF;

	dist[s]=0;
	for(i=0;i<n;i++)
	{
		u = get_min_vertex(n);
		selected[u]=TRUE; // 지나간 경로 체크

		if( dist[u] == INF ) return;

      cout<<u+1<<" ";

		for( v=0; v<n; v++)
		{
			if( adj_mat[u][v]!= INF)
			{
				if( !selected[v] && adj_mat[u][v]< dist[v] )
					{
            dist[v] = adj_mat[u][v];
            k=u;
             // 간선의 거리를 확정
          }
			}
		}

    if(i && i!=n-1)
      cout<<k+1<<" ";
    else  if(i && i!=n-1 && k !=u)
        cout<<k<<" " ;


	}
}

//
int main()
{
  for(int i =0; i<VERTICES; i++)
  {
    for(int j =0; j <VERTICES; j++)
      cout<<adj_mat[i][j]<<" ";
    cout<<endl;
  }
	prim(0, VERTICES);
}
