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
	void insert(int );
	void Delete(int);
	bool isEmpty();
	void display();
	void searchList(int);
	int length();

};


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
			}while(temp != head);
		}
	return count;
}

void List::insert( int data)
{
	Node* temp = new Node(data);
	if(isEmpty())
	{
		head = temp;
		temp->next = head;
	}
	else
	{
		temp->next = head->next;
		head->next = temp;
		temp= head;
	}
}

void List::Delete(int data)
{
	Node *p,*q;
	p = NULL;
	q = NULL;
	if(head==NULL)
		cout<<"list is empty"<<endl;
	else
	{
		p = head; q = head;
		while (p->data != data) {
			q = p;
			p = p->next;
			if (p == head) {
				p = NULL;
				break;
			}
		}
		if (p) {
			q->next = p->next;
			delete p;
		}
		else
			cout << data << " is not founded\n";
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

  int num;
  char input[20];
  while(1)
  {
    cout<<"Enter command(length,insert,display, searchlist, delete, exit):";
    cin >>input;
    if(strcmp(input, "display")==0)
    {
      l.display();
    }

    else if(strcmp(input, "insert")==0)
    {
      cin>>num;
      l.insert(num);
    }
    else if(strcmp(input, "searchlist")==0)
    {
      cin>>num;
      l.searchList(num);
    }
    else if(strcmp(input, "delete")==0)
    {
      cin>>num;
      l.Delete(num);
    }
    else if(strcmp(input,"exit")==0){

      exit(0);
    }
    else if(strcmp(input, "length")==0)
    {
      int ans=l.length();
      cout<<ans<<endl;
    }
    else
        cout<<"Bad Command!"<<endl;
    }
  return 0;
}
