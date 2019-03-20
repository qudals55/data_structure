#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
const int queueSize=5;
int queue[queueSize]; int top; int rear; int flag;
void create_queue();
void Enqueue(int);
void traverse_queue();
void displayqueue();
int Dequeue();
int num;
char input[10];

int main()
{
  create_queue();
  while(1)
  {
    cout<<"Enter command(Enqueue,Dequeue,traverse,exit):";
    cin >>input;
    if(strcmp(input, "Enqueue")==0)
    {

        cout <<"Enter an integer to Enqueue=>";
        cin>>num;
        Enqueue(num);

    }
    else if(strcmp(input,"Dequeue")==0)
    {
        num=Dequeue();
        cout<<num<<"is Dequeueped."<<endl;

    }
    else if(strcmp(input,"traverse")==0)
      displayqueue();
    else if(strcmp(input,"exit")==0)
      exit(0);
    else
      cout<<"Bad Command!"<<endl;
  }
}

  void create_queue()
    {
      top=0;
      rear =0;
    }

  void Enqueue(int num)
    {
      if((top==rear)&&(flag==1))
      {
        cout<<"Queue is full!!";
        exit(1);
      }
      else
      {
        queue[rear]=num;
        rear=(rear+1)%queueSize;
        flag=1;
      }
    }
  int Dequeue()
    {
      int item;
      if((top==rear)&&(flag==0))
      {
        cout<<"Queue is empty!!";
        exit(0);
      }
      else
      {

        item = queue[top];
        top= (top+1)%queueSize;
        flag =0;
        return item;
      }
    }
  void displayqueue()
  {
    int sp;
    if((top==rear)&&(flag==0))
      cout<<"Queue is Empty!"<<endl;
    else
    {
      sp=top;
      while(sp < rear)
        cout<<queue[sp++];
    cout<<endl;
    }
  }
