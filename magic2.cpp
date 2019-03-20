/*20143029 공병민 마방진*/
#include <iostream>
using namespace std;
#include <string>

void magic(int n)
{

  if(n%2==0)  // n 이 올바른 값인지 검사 ..........................
  {
      cout<<"n is failed!"<<endl;
      exit(1);
  }
else
{

  int key = 2, x = 0;
  int y = (n-1)/2;
  int k,l;
  int **square = new int*[n]; //2차원 배열 square을 동적으로 할당
  for(int i = 0; i < n; i++)
   {
     square[i] = new int[n];
     memset(square[i], 0, sizeof(int)*n);//2차원 배열 초기화
   }

   // square 를 0 으로 초기화 .......................
  square[0][(n-1)/2]=1; //첫 행의 중간에 1 삽입
//i와 j는 현재 위치

  while(key <= n * n)
  { // 왼쪽 위로 이동
    if(x - 1 < 0)
      k = n - 1;
    else
      k = x - 1;
    if(y -1 < 0)
      l = n - 1;
    else
      l = y - 1;
    if(square[k][l])
        x = (x + 1) % n;     // square 가 채워짐. 아래로 이동 else { // square[k][l]이 채워지지 않음
    else
    {
      x  = k;
      y = l;
    }
  square[x][y] = key;
  key++;
}
for(int i=0;i<n;i++)
{
  for(int j=0;j<n;j++)
  {
    cout<<square[i][j]<<" ";
  }
  cout<<endl;
}
for(int i = 0; i < n; i++)
 {
    delete [] square[i];

 }
   delete [] square;
}

}
int main()
{
  int num;
  cin>>num;
  magic(num);
return 0;
}
