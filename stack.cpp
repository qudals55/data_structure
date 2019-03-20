

#include <iostream>
#include <stdlib.h>
using namespace std;
const int stackSize=36;//미로의 크기가 36이기때문에 길의 최대크기는 36
typedef struct stack_s//행과 열과 방향을 저장할 구조체 선언
{
  short int row;//미로의 행
  short int col;//미로의 열
  short int dir;//미로의 방향
}element;

element stack[stackSize]={0}; //구조체 스택의 크기 초기화
typedef struct direct// 방문할 길을 찾기 위해서 방향을 바꿀 구조체
{
  short int vert;//북쪽과 남쪽
  short int horiz;//동쪽과 서쪽

}offsets;

void push(int &top, element& temp );//방문한 곳이 갈 수 있는 길이면 그것을 저장하기 위한 함수
element pop(int &top);//아직 출구에 도착하지 않았는데, 방문할 곳이 없으면, 현재 경로로 다시 돌아오기 위한 함수
int isEmpty(int &top);//스택이 비어있는지 확인하기위한 함수



int main()
{

  int maze[6][6] = { 0,1,1,1,1,1, 1,0,1,1,1,1, 1,0,0,0,0,1, 1,1,0,1,1,1, 1,0,1,0,0,1, 1,1,1,1,1,0 };//주어진 미로
  int mark[6][6]= {0,};//가능한 길을 표시하기 위한 행렬
  int found =0;//출구를 찾으면 found =1
  int top =-1;//첫 스택

  offsets move[8];
  move[0].vert=-1; move[0].horiz=0;//북쪽
  move[1].vert=-1; move[1].horiz=1;//북동쪽
  move[2].vert=0; move[2].horiz=1;//동쪽
  move[3].vert=1; move[3].horiz=1;//남동쪽
  move[4].vert=1; move[4].horiz=0;//남쪽
  move[5].vert=1; move[5].horiz=-1;//남서쪽
  move[6].vert=0; move[6].horiz=-1;//서쪽
  move[7].vert=-1; move[7].horiz=-1;//북서쪽


  element temp ={0};// 스택에 위치를 넣기 위한 구조체변수이다

  mark[0][0]= 1;//출발점
  stack[0].row=1;//출발점이기 때문에 1로 마크한다
  stack[0].col=1;//출발점이기 때문에 1로 마크한다
  stack[0].dir=2;//처음 출발할 때 방향은 동쪽이다

  int row, col, dir, next_row=0,next_col=0;   //현재위치와 다음위치를 저장 하기 위한 변수
  push(top, temp);//출발점이므로 스택에 넣는다

  while (!isEmpty(top)&& !found)  //스택이 비어있지 않고, 출구를 찾을때 까지
   {

        temp = pop(top); //길을 못찾았기 때문에 현재 위치를 변경한다.
        row = temp.row; //삭제한 행의 값을 현재 위치로 한다.
        col=temp.col;//삭제한 열의 값을 현재 위치로 한다.
        dir=temp.dir;//삭제한 방향을 현재 위치로 한다.

      while (dir<8 && !found)// 방문할 방향을 계속 찾는다
      {
        next_row = row + move[dir].vert; //이동할 다음 방향을 저장
        next_col = col + move[dir].horiz;//이동할 다음 방향을 저장
        if(next_row == 5 && next_col == 5)//출구에 다다랐을 때에
        {
          found = 1; //출구를 찾았기 때문에 found=1
          mark[next_row][next_col]=1;//출구이기 떄문에 1로 마킹한다.
          temp.row = row; temp.col=col; //현재 위치를 스택에 넣기 위해 임의의 변수에 저장해 둔다. 아직 스택에는 모든 출구가 삽입되어 있지 않다.
          push(top, temp);//현재위치를 스택에 넣어둔다.
          temp.row = next_row; temp.col=next_col;//마지막 출구를 스택에 넣기 위해 임의의 변수에 저장해 둔다.
          push(top,temp);//마지막 출구를 스택에 넣는다.
        }

        else if (!maze[next_row][next_col] && !mark[next_row][next_col])//출구로 갈 수 있는 길일때
        {

            mark[next_row][next_col]=1;//갈 수 있는 길이기 때문에 1로 마킹한다.
            temp.row = row; temp.col=col; temp.dir=++dir;//그 방문한 곳을 1로 지정하고, 방향을 옮긴다.
            push(top, temp);//갈 수 있는 길이기 때문에 일단 스택에 넣어둔다.
            row=next_row; col = next_col;  dir = 0;// 위치를 출구로 갈 수 있는 길로 옮겨서 다시 출구를 찾는다.
        }
        else

         dir++; //계속 회전하며 갈 수 있는 길을 찾는다.

      }
    }

    cout<<"The path is"<<endl;
    cout<<"row"<<" "<<"col"<<endl;

    for(int i =0;i <top+1; i++)
      cout<<stack[i].row<<"   "<<stack[i].col<<endl;//결국 남은 스텍에 넣어둔 위치들은 미로의 해답이다.




    cout<<"Marked matrix"<<endl;
    for(int i=0;i<=next_row;i++)//갈 수 있는 길들을 출력한다.
    {
      for(int j=0;j<=next_col;j++)
       cout<<mark[i][j]<<" ";
      cout<<endl;
    }


    return 0;
  }


  int isEmpty(int &top)
  {
    if(top==-1)
      return 1;
    else
      return 0;
  }

  void push(int &top, element &temp)
    {stack[++top]=temp;}


  element pop(int &top)
    {return stack[top--];}
