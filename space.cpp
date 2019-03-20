#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Node{
private:
	int data;
	Node *next;

public:
	Node() {
		this->data = 0;
		this->next = NULL;
	}
	Node(int value) {
		this->data = value;
		this->next = NULL;
	}

	friend class List;
};

class List
{
private:
	Node *head;
public:
	List(){
		head = NULL;
	}

	bool isEmpty();
	void searchList(int);
 	void create_num(int);
	Node* get_node(List* l2);
	void return_node(Node* avail);
  void insert(int);
	void SetHead(Node* n);
	Node* get_head();
};


Node* List::get_head()
{
	return head;
}

void List::SetHead(Node* n)
{
	head = n;
}

void List::insert( int data)
{
	Node* temp= get_node(&l2);

	if(isEmpty())
	{
		head = temp;
		temp->next = head;
	}
	else
	{
		temp->next = head->next;
		head->next = temp;
	}
}

void List::return_node(List* l2)
{
	head->next = l2->get_head();
	l2->get_head()=head;

}

Node* List::get_node(List* l2)
{
	Node* temp1= NULL;

		if(l2->get_head())
		{
			temp1 = l2->get_head();
			l2->SetHead(l2->get_head()->next);

		}
		return temp1;

		else
			Node *avail = new Node();
		return avail;
}


void List::create_num(int space)
{
	while(space--)
	{
		Node* avail= new Node();
		if(head==0)
			head = avail;
		else
		{
			avail->next = head;
			head = avail;
		}
	}
}


bool List::isEmpty()
{
  if(head == NULL)
    return true;
  else
    return false;
}

void List::display()
{
  Node *p;
  p = NULL;
  if(!isEmpty()){
    p= head;
  cout<<"List : ";
  while(p->next!=head){
    cout<<p->data<<" ";
    p = p->next;
  }
  cout << p->data;
  cout<<endl;
  }
  else
    cout<<"List is empty"<<endl;
}
void List::searchList(int data)
{
  Node *p;
  p = NULL;
  if(head != NULL){
    p = head;
	while (p->data != data) {
		p = p->next;
		if (p == head) {
			p = NULL;
			break;
		}
	}

	if (p)
		cout << p->data << " " << "is found." << endl;
	else
		cout << data << " is not in the list." << endl;
  }
  else
	  cout<<"List is empty"<<endl;

 }

int main()
{
  List l;
	List l2;
  int num,space;
  char input[20];
  while(1)
  {
    cout<<"Enter command(return,insert, display, searchlist, delete, exit):";
    cin >>input;
    if(strcmp(input, "display")==0)
    {
      l.display();
    }
		else if(strcmp(input, "space")==0)
    {
      cin>>space;
      l2.create_num(space);
    }
    else if(strcmp(input, "insert")==0)
    {
      cin>>num;
      l.insert(num);
    }
		else if(strcmp(input, "return")==0)
		{
			l.return_node(&l2);
		}

    else if(strcmp(input, "searchlist")==0)
    {
      cin>>num;
      l.searchList(num);
    }
    else if(strcmp(input, "delete")==0)
    {
      cin>>num;
      l2.return_node(l);
    }
    else if(strcmp(input,"exit")==0){
      exit(0);
    }
    else
        cout<<"Bad Command!"<<endl;
    }
  return 0;
}
