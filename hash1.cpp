#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;

const int SIZE=23;
const int divi=10;

class Node{

  int data;
  Node *next;
  friend class Hash;
};
class Hash{
private:
  Node *head[SIZE];
  int value;
  int key;
public:
  Hash()
  {
    for(int i=0; i<SIZE; i++)
    {
      head[i]=0;
    }
    value=0;key=0;
  }
  void insert_(int value)
  {
    Node *temp = new Node();
    Node *p;
    temp->data = value;
    key = value%divi;
    if(head[key]==0)
    {
      head[key]=temp;
    }
    else
    {
      p=head[key+SIZE];
      while(p->next!=0)
      {
        p=p->next;
      }
      p->next=temp;
    }
  }
  void delete_(int value)
  {
    key = value%divi;
    Node *p,*q;
    if(head[key]->data==value)
    {
      p=head[key];
      head[key]=head[key]->next;
      delete p;
    }
    else
    {
      p=head[key];
      while(p!=0&&p->data!=value)
      {
        q=p;
        p=p->next;
      }
      if(p!=0)
      {
        q->next = p->next;
        delete p;
      }
      else
      cout << value << "없다"<<endl;
    }
  }

  void search_(int value)
  {
    key = value%divi;
    Node *p;
    if(head[key]!=0)
    {
      p=head[key];
      while(p->next!=0&&p->data!=value)
        p=p->next;
      if(p->data==value)
        cout << p->data << "는" << key <<"테이블에 있다" << endl;
      else if(p->next==0)
        cout << value << "는" << key << "테이블에 없다" << endl;
    }
    else
      cout <<"테이블이 빔" <<endl;
  }

  void printtable()
  {
    Node *p;
    for(int i=0; i<SIZE;i++)
    {
      if(head[i]!=0)
      {
        p=head[i];
        while(p!=0)
        {
          cout << i<<" "<<p->data << " ";
          p=p->next;
        }
      }
      else
        cout << i<<" "<<"is empty";

      cout << endl;
    }


  }
};

int main()

{
  Hash hs;
	int num = 0;
	char input[20];
	while (1)
	{
		std::cout << " ( 1.insert, 2.delete, 3.search, 4.printtable, 5.quit) " << std::endl;
		std::cin >> input;
		std::cout << std::endl;
		if (strcmp(input, "1") == 0)
		{
			std::cout << "넣고 싶은 수를 써주세요 : ";
			std::cin >> num;

			hs.insert_(num);
			std::cout << num << "이 들어갔습니다." << std::endl;

		}

		else if (strcmp(input, "2") == 0)
		{
			std::cout << "지우고 싶은 수를 써주세요 : ";
			std::cin >> num;
      hs.delete_(num);

		}
		else if (strcmp(input, "3") == 0)

		{
			std::cout << "찾으시는 수를 써주세요 : ";
			std::cin >> num;
      hs.search_(num);
		}

		else if (strcmp(input, "4") == 0)
		{
			hs.printtable();
		}
		else if (strcmp(input, "5") == 0)
		{
			std::cout << "프로그램을 종료 합니다. ";
			break;

		}
		else
			std::cout << "잘못 입력하셨습니다." << std::endl;
	}
	return 0;

}
