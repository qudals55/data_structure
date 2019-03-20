#include <iostream>
#include <string.h>

using namespace std;

int main()
{
  int arr[10][5];

    for(int j =0;j<5;j++)
    {

        arr[10][j]=1;
    }

  memset(arr,0,sizeof(arr)-20);
  for(int i=0;i<10;i++)
  {

    for(int j =0;j<5;j++)
    {
          cout<< arr[i][j]<<" ";
    }
    cout<<endl;

  }
}
