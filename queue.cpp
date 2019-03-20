#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
const int queueSize=3;
int queue[queueSize]; int top; int rear;
void create_queue();
void Enqueue(int);
void traverse_queue();
void displayqueue();
int Dequeue();
int isFull();
int isEmpty(int num);
int num;
char input[10];

int main()
{
  create_queue();
  while(1)
  {
    cout<<"Enter command(Enqueue,Dequeue,traverse_queue,exit):";
    cin >>input;
    if(strcmp(input, "Enqueue")==0)
    {
      if(!isFull())
      {
        cout <<"Enter an integer to Enqueue=>";
        cin>>num;
        Enqueue(num);
      }
    else
      cout<<"queue is full!"<<endl;
    }
    else if(strcmp(input,"Dequeue")==0)
    {
      if(!isEmpty(num))
      {
        num=Dequeue();
        cout<<num<<"is Dequeueped."<<endl;
      }
      else
        cout<<"queue is empty!"<<endl;
    }
    else if(strcmp(input,"traverse_queue")==0)
      displayqueue();
    else if(strcmp(input,"exit")==0)
      exit(0);
    else
      cout<<"Bad Command!"<<endl;
  }
}

  void create_queue()
    {
      top=-1;
      rear =-1;
    }

  int isFull()
  {
    if(rear==queueSize-1)
      return 1;
    else
     return 0;
  }

  int isEmpty(int num)
  {
    if(top==rear)
      return 1;
    else
      return 0;
  }

  void Enqueue(int num)
    {
      if(rear==queueSize)
      {
        isFull();
        return;
      }
      queue[++rear]=num;
    }
  int Dequeue()
    {
      if(top==rear)
        return isEmpty(num);

      return queue[++top];

    }
  void displayqueue()
  {
    int sp;
    if(isEmpty(num))
      cout<<"Queue is Empty!"<<endl;
    else
    {
      sp=top+1;

      while(sp <= rear)
        cout<<queue[sp++];
    cout<<endl;
  }
  }
