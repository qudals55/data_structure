/*20143029 공병민*/
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Node{
private:
  char data;
  Node *next;


public:
  Node(){
  }
  Node(char value){
    data = value;
    next = NULL;
  }

  friend class List;
};

class List{
private:
  Node *head;
  Node *rear;
public:
  List(){ head =0; rear=0;}
  void insert(char);
  void Delete(char);
 ~List();
  bool isEmpty();
  void display();
  void invert();
  void concatenate(List* l2);
  int length1();
  int length();
  Node* get_head();
  void stack();
  void push(char data);
  char pop();
  void queue();
  void inqueue(char data);
  char dequeue();
  void plusdis();
};
void List::concatenate(List* l2)
{
  Node* temp = head;
  if (isEmpty())
  {
    if(l2->isEmpty())
    {
      head = NULL;
      return ;
    }
    else
    {
      head = l2->get_head();
      return ;
    }
  }

   else
   {
    if (!l2->isEmpty())
     {
       for (temp = head; temp->next; temp = temp->next);

       temp->next = l2->get_head();
    }
    else
      return;
  }
}

char List::dequeue()
{
  Node *p; char num;


    if(head!=0)
    {
      num = head->data;
      p = head;

      if (head == rear)
      {
        queue();
      }
      else
        head = head->next;

      delete p;
    }
    else{
      cout<<"Queue is Empty!"<<endl;
    }
    cout<<num<<endl;
  return num;
}

void List::inqueue(char data)
{
Node *temp = new Node(data);
if (head == 0)
{
  head = temp;
  rear = temp;
}
else {
  rear->next = temp;
  rear = temp; }
}
void List::queue()
{
  head = 0;
  rear = 0;
}
void List::stack()
{
  head=0;
}
void List::push(char data)
{
  Node *temp = new Node(data);
  if(head==0)
    head = temp;
  else{
    temp->next =head;
    head= temp;
  }
}
char List::pop()
{
  Node *p=NULL;
  char num;
  if(isEmpty())
  {

    return 0;
  }
  else{
  num = head->data;
  p=head;
  head= head->next;
  delete p;
  return num;
}
}
int List::length1()
{
Node* temp;

int count =0;
if(head)
{
temp=head;
do{
count++;
temp = temp->next;
}while(temp != rear->next);
}
return count;
}
int List::length()
{
Node* temp;

int count =0;
if(head)
{
temp=head;
do{
count++;
temp = temp->next;
}while(temp != NULL);
}
return count;
}


Node* List::get_head()
{
  return head;
}



void List::invert()
{
  Node *p, *q, *i;
  p=head;
  q=NULL;
  i=NULL;
  while(p)
  {
    i=q;
    q=p;
    p=p->next;
    q->next=i;
  }
  head=q;
}


void List::insert(char data)
{
  Node* temp = new Node(data);
  Node *p, *q;
  p = NULL;
  q = NULL;
  if(isEmpty()) head = temp;
  else if( temp->data < head->data){
    temp->next=head;
    head = temp;
  }
  else{
    p= head;
    while((p!=NULL)&&(temp->data > p->data))
    {
      q=p;
      p=p->next;
    }
    if(p!=NULL){
      temp -> next = p;
      q-> next = temp;
    }
    else
      q->next = temp;
  }
}


bool List::isEmpty()
{
  if(head == NULL )
    return true;
  else
    return false;
}
void List::display()
{
  Node* p=head;
  if(!isEmpty())
  {
    while(p!=0)
    {
      cout<<p->data<<" ";
      p=p->next;
    }
  }
  else
    cout<<"List is empty"<<endl;
}
List::~List()
{
  Node *p;
  while (head!=0){
    p=head;
    head = head->next;
    delete p;
  }
}

int main()
{
  List l;
  List l2;
  char num,spop,sq='0';
  int  ans;
  char input[100];
  l.stack();
  l2.queue();

  while(1)
  {
    cout<<"Enter command(plus,ls,lq,invert, ins,inq,diss,disq, pop, deq,exit):";
    cin >>input;
    if(strcmp(input, "diss")==0)
    {
      l.invert();
      l.display();
    }
    else if(strcmp(input, "disq")==0)
    {

      l2.display();
    }

    else if(strcmp(input, "ls")==0)
    {
      int ans=l.length();
      cout<<ans<<endl;
    }
    else if(strcmp(input, "lq")==0)
    {
      int ans=l2.length1();
      cout<<ans<<endl;
    }
    else if(strcmp(input, "invert")==0)
    {
      l.invert();
    }
    else if(strcmp(input, "ins")==0)
    {
      cin>>num;
      l.push(num);
    }
    else if(strcmp(input, "plus")==0)
    {
      l.invert();
      l.concatenate(&l2);

    }
    else if(strcmp(input, "inq")==0)
    {
      cin>>num;
      l2.inqueue(num);
    }


    else if(strcmp(input, "deq")==0)
    {

        l2.dequeue();

    }
    else if(strcmp(input, "pop")==0)
    {

      spop=l.pop();
      if(spop==0)
      {
        cout<<"stack empty"<<endl;
      }
      else
      cout<<spop<<endl;
    }
    else if(strcmp(input,"exit")==0){

      exit(0);
    }
    else
        cout<<"Bad Command!"<<endl;
    }
  return 0;
}
