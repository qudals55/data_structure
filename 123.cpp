#include <iostream>
#include<cstdlib>
#include<string>

using namespace std;

class Node
{
private:
   string data;
   Node* next = NULL;
   //friend class List;
   friend class linkedStack;
   friend class linkedQueue;
   friend class List;
public:
};
class List
{
private:
   Node* head;
   friend class linkedStack;
   friend class linkedQueue;
public:
   List()
   {
      head = 0;
   }
   void insert(string num);
   bool isEmpty();
   void printList();
   void invert();
};
void List::invert() /* head가 가리키고 있는 리스트를 역순으로 만든다. */
{
   Node* middle = NULL;
   Node* trail = NULL;
   while (head)
   {
      trail = middle;
      middle = head;
      head = head->next;
      middle->next = trail;
   }
   head = middle;
}
void List::printList()
{
   Node *p = NULL;
   if (!isEmpty()) {
      p = head;
      cout << "List: ";
      while (p) {
         cout << p->data << " ";
         p = p->next;
      }
      cout << endl;
   }
   else
      cout << "List is empty!\n";
}
bool List::isEmpty()
{
   if (head == 0)
      return true;
   else
      return false;
}

void List::insert(string num)
{
   Node *temp = new Node();
   Node* p = NULL;
   Node* q = NULL;
   temp->data = num;
   if (head == NULL)
   {
      head = temp;
   }
   else if (temp->data < head->data)
   {
      temp->next = head;
      head = temp;
   }
   else
   {
      p = head;
      while ((p != 0) && (temp->data > p->data))
      {
         q = p;
         p = p->next;
      }
      if (p != 0)
      {
         temp->next = p;
         q->next = temp;
      }
      else
         q->next = temp;
   }
}
class linkedStack
{

private:
   Node* head;
   friend class linkedQueue;
   friend class List;
public:
   linkedStack()
   {
      head = NULL;
   }
   void createStack();
   void push(string num);
   void pop();
   bool isEmpty();
   void printList();
   void concatenate(linkedQueue &queue,List &mlist);
   ~linkedStack()
   {
   }
};
class linkedQueue
{

private:
   Node* front;
   Node* rear;
   friend class linkedStack;
   friend class List;
public:
   linkedQueue()
   {
      front = NULL;
      rear = NULL;
   }
   int isEmpty();
   void createQueue();
   void enqueue(string num);
   void dequeue();
   void displayQueue();
   ~linkedQueue()
   {
   }
};
void linkedStack::concatenate(linkedQueue &queue,List &mlist)/* 리스트 ptr1 뒤에 리스트 ptr2가 접합된 새 리스트를 생성한다.     ptr1이 가리키는 리스트는 영구히 바뀐다.*/
{
   Node* p = NULL;
   Node* temp = NULL;
   temp = queue.front;
   if (head == 0)
      head = temp;
   else
   {
      p = head;
      while (p->next != 0)
         p = p->next;
      p->next = temp;
   }
   p = head;
   while (p != 0)
   {
      string s;
      s= p->data;

      mlist.insert(s);

      p = p->next;
   }

}
void linkedQueue::enqueue(string num)
{
   Node *temp = new Node;
   temp->data = num;
   if (front == 0)
   {
      front = temp;
      rear = temp;
   }
   else
   {
      rear->next = temp;
      rear = temp;
   }
   cout << temp->data << "가 List에 들어갑니다." << endl;
}
void linkedQueue::dequeue()
{
   Node *p;

   p = front;

   if (front == rear)
   {
      front = 0;   rear = 0;
   }
   else
      front = front->next;

   cout << p->data << "삭제되었습니다." << endl;
   delete p;
}
void linkedQueue::displayQueue()
{
   Node* p;

   if (!isEmpty())
   {
      p = front;
      while (p)
      {
         cout << p->data << " ";
         p = p->next;
      }
      cout << endl;
   }
   else  cout << "Queue is empty!\n";
}
void linkedQueue::createQueue()
{
   front = 0;
   rear = 0;
}
int linkedQueue::isEmpty()
{
   if (front == 0)
      return 1;
   else
      return 0;
}
void linkedStack::createStack()
{
   head = NULL;
}
void linkedStack::push(string num)
{
   Node *temp = new Node();
   Node* p = NULL;
   Node* q = NULL;
   temp->data = num;
   if (head == NULL)
   {
      head = temp;
   }
   /*else if (temp->data < head->data)
   {*/else
   {
      temp->next = head;
      head = temp;
   }
   //}
   //else
   //{
   //   p = head;
   //   while ((p != 0) && (temp->data > p->data))
   //   {
   //      q = p;
   //      p = p->next;
   //   }
   //   if (p != 0)
   //   {
   //      temp->next = p;
   //      q->next = temp;
   //   }
   //   else
   //      q->next = temp;
   //}
   cout << temp->data << endl;
}
void linkedStack::pop()
{
   Node * p = NULL;
   if (head == 0)
      cout << "empty" << endl;
   else
   {
      p = head;
      head = head->next;
      cout << p->data << "삭제되었습니다." << endl;
      delete p;
   }
}

bool linkedStack::isEmpty()
{
   if (head == 0)
      return true;
   else
      return false;
}

void linkedStack::printList()
{
   Node *p = NULL;
   if (!isEmpty()) {
      p = head;
      cout << "List: ";
      do {
         cout << p->data << " ";
         p = p->next;
      } while (p != 0);
      cout << endl;
   }
   else
      cout << "List is empty!\n";
}
int main(void)
{
   linkedStack stack;
   linkedQueue queue;
   List mlist;
   stack.createStack();
   queue.createQueue();
   string num;
   char input[20];
   while (1)
   {
      cout << " ( 1. push, 2 pop, 3.stackdiplay, 4.enqueue, 5.dequeue, 6.queuedisplay, 7.concat, 8.concatdisplay, 9.concatdisplay_invert) " << endl;
      cin >> input;
      cout << endl;
      if (strcmp(input, "1") == 0)
      {
         cout << "넣고 싶은 문자를 써주세요 : ";
         cin >> num;
         stack.push(num);
         cout << "list에 " << num << "이 들어갔습니다." << endl;
      }
      else if (strcmp(input, "2") == 0)
         stack.pop();
      else if (strcmp(input, "3") == 0)
      {
         cout << "리스트를 전부 출력합니다" << endl;
         stack.printList();
      }
      else if (strcmp(input, "4") == 0)
      {
         cout << "넣고 싶은 문자를 써주세요.:";
         cin >> num;
         queue.enqueue(num);
      }
      else if (strcmp(input, "5") == 0)
         queue.dequeue();
      else if (strcmp(input, "6") == 0)
      {
         cout << "리스트를 전부 출력합니다" << endl;
         queue.displayQueue();
      }
      else if (strcmp(input, "7") == 0)
         stack.concatenate(queue,mlist);
      else if (strcmp(input, "8") == 0)
      {
         mlist.printList();
      }
      else if (strcmp(input, "9") == 0)
      {
         mlist.invert();
         mlist.printList();
      }
   }
   return 0;
}
