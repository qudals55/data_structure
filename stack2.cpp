#include <iostream>
#include <cstring>
#include <cstdlib>

const char stackSize = 2;
char stack[stackSize];
int top;

using namespace std;

void create_stack();
void push(int num);
void displayStack();
int pop();
int isFull();
int isEmpty();



  int front; int rear;
  const char sizeQueue=3 ;
  char queue[sizeQueue];

  void create_queue();
  void enQueue(int value);
  int deQueue();
  int queue_full();
  int queue_empty();
  void print();



void create_queue() { front = -1;
rear = -1; }



void Enqueue (int item)
{

  if (rear == sizeQueue-1)
  {
    queue_full();
    return ;
  }
  queue[++rear] = item;
}



int queue_full()
{
  if (rear==sizeQueue-1)
    return 1;
  else
   return 0;
 }

int queue_empty()
{
  if (front ==rear)
    return 1;
  else
    return 0;
 }

int dequeue ()
{

  if (front == rear)
    return queue_empty();
  else /* 에러 key를 반환 */
    return queue[++front];
}

void print_queue() {
int i;
if (queue_empty())
cout << "Queue is Empty!\n";
else {
i = front + 1;
cout << "-- Print Queue --\n";
while (i <= rear) {
cout << queue[i];
i = i + 1;
}
}
}


int main()
{
  char num;
  char input[5];
  create_stack();
  create_queue();




  while(1)
  {

    cout << "Push, Pop ,Enque  ,Deque ,Displaystack ,Displayque ,exit \n";
    cin >> input;

    if(strcmp(input,"Push")==0) //푸쉬
    {
      if(!isFull())
        {
          cout << "Enter an char to push => " ;
          cin >> num;
          push(num);
        }
      else
        cout << "Stack is full!\n";
    }

    else if(strcmp(input,"Pop")==0) //팝
    {
      if(!isEmpty())
      {
        num=pop();
        cout << num << endl;
      }
      else
        cout << "Stack Empty!\n";
    }
    else if (strcmp(input,"Enque")==0) //3  enque
    {
          if(!queue_full()){
            cout << "Enter char to Enque => " ;
            cin >> num ;
            Enqueue(num);
          }
          else
            cout << "Queue Full!\n";

    }
    else if (strcmp(input,"Deque")==0) //4   deque
    {
      if(!queue_empty())
      {
          num=dequeue();
          cout << num << endl;
      }
      else
        cout << "Queue empty!\n";
    }

    else if(strcmp(input,"Displaystack")==0) //디스플레이스택
      displayStack();

    else if (strcmp(input,"Displayque")==0) //6 displayque
      {
          print_queue();
      }

    else if(strcmp(input,"exit")==0) //나가기
      exit(0);

    else
      cout << "Bad Command!\n";
  }




  return 0;
}

 //스택 정의
//함수 정의
void create_stack() //스텍 생성
{
  top=-1;
}

void push(int num) //값 입력
{
  ++top;
  stack[top] = num;
}

int pop()  //출력
{
  return stack[top--];
}

int isFull()
{
  if(top==stackSize-1)
    return 1;
  else
    return 0;
}

int isEmpty()
{
  if(top==-1)
    return 1;
  else
    return 0;
}

void displayStack()  //스택 나열
{

  if(isEmpty())
    cout << "Stack is empty!" << endl;
  else
  {
    for(int sp = 0 ; sp <=top ; sp++)
    {
      cout << stack[sp] << " ";
    }
    cout << endl;
  }
}
