#include <iostream>
#include <cstring>
using namespace std;
#define MAX_SIZE 200

typedef struct{
  int key;

}element;
element heap[MAX_SIZE]={0,};

int n=1;

bool HeapFull()
{
  if(n==MAX_SIZE)
    return true;
  else
    return false;
}
bool HeapEmpty()
{
  if(n==1)
    return true;
  else
    return false;

}
void MaxHeap_Insert(element item)
{
  if(HeapFull())
  {
    cout<<"Heap is full"<<endl;
    exit(1);
  }
  int i=++n;
  while((i!=1) && (item.key > heap[i/2].key))
  {
    heap[i].key=heap[i/2].key;
    i/=2;
  }
  heap[i].key= item.key;

}

element MaxHeap_Delete()
{
  int parent=1, child=2;
  element item, temp;
  item.key = heap[1].key;
  temp.key = heap[n--].key;
  if(HeapEmpty())
  {
    cout<<"Heap is Empty"<<endl;
    exit(1);
  }
  while(child <=n)
  {
    if((child<n) && (heap[child].key<heap[child+1].key))
      child ++;
    if(temp.key >= heap[child].key)
      break;
    heap[parent]=heap[child];
    parent = child;
    child *=2;
  }
  heap[parent].key= temp.key;
  return item;

}
void Heap_print()
{
  for(int i =1; i<=n;i++)
    cout<<heap[i].key<<" ";
  cout<<endl;
}
int main()
{
  element num;
  string input;

   while(1)
   {
      cout << " ( 1.insert, 2.delete, 3.print, 4.quit ) " << endl;
      cin >> input;
      cout << endl;
      if (input == "1")
      {
         std::cout <<"값을 입력해주세요. : ";
         cin >> num.key;
         MaxHeap_Insert(num);

      }
      else if (input == "2")
        cout<<MaxHeap_Delete().key<<endl;
      else if (input == "3")
        Heap_print();
      else if (input=="4")
      {
         std::cout << "프로그램을 종료 합니다. ";
         break;
      }
      else
      {
        cout<<"다시 입력해주세요"<<endl;
        return 1;
      }
   }
   return 0;
}
