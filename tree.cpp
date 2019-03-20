#include<iostream>
#include<string>
using namespace std;
class Node {
private:
   int  data;
   Node* left;
   Node* right;
   friend class Tree;
public:
   Node(int value):data(value),left(NULL),right(NULL) {}
   int getNodedata(){return data;}
};
class Tree {
private:
   Node* root;
public:
   Tree():root(NULL){}
   ~Tree(){root=NULL;}
   void Bst_Insert(Node* &ptr,int key);
   Node* getroot(){return root;}
   void Bst_Search(Node* ptr, int key);
   void Bst_Delete(int key, Node* &ptr);
   Node* Find_min(Node* ptr);
   void Insert(int key){Bst_Insert(root, key);}
   void Delete(int key){Bst_Delete(key, root);}
   void Search(int key){Bst_Search(root, key);}
   void Inorder(Node* ptr);
   void PrintIn(){Inorder(root);}

};
void  Tree::Inorder(Node* ptr)
{
  if(ptr){
    Inorder(ptr->left);
    cout<<ptr->data<<" ";
    Inorder(ptr->right);
  }
}
void Tree::Bst_Insert(Node* &ptr, int key)
{
  if(ptr==NULL)
  {
    Node* temp = new Node(key);
    ptr = temp;

  }
  else if( key < ptr->data)
      Bst_Insert(ptr->left, key);
  else if (key > ptr->data)
      Bst_Insert(ptr->right, key);

}

void Tree::Bst_Search(Node* ptr, int key)
{
  if(ptr==NULL)
  {
    cout<<key<<"is not in Bst"<<endl;
    return;
  }
  else
  {
    if(key==ptr->data)
      cout<<key<<"is in Bst"<<endl;
    else if(key>ptr->data)
      Bst_Search(ptr->right, key);
    else if(key < ptr->data)
      Bst_Search(ptr->left, key);
  }
}

void Tree::Bst_Delete(int key, Node* &ptr)
{
  Node* temp=NULL;
  Node* p=NULL;
    if(ptr!=NULL)
    {
      if(key < ptr->data)
        Bst_Delete(key, ptr->left);
      else if( key > ptr->data)
        Bst_Delete(key, ptr->right);
      else if((ptr->left ==NULL ) && (ptr->right==NULL))
        ptr=NULL;
      else
        if(ptr->left ==NULL)
        {
          p= ptr; ptr=ptr->right; delete(p);
        }
        else if(ptr->right ==NULL)
        {
          p=ptr ; ptr = ptr->left; delete(p);
        }
        else
        {
          temp = Find_min(ptr->right);
          ptr->data = temp->data;
          Bst_Delete(ptr->data, root);
        }
    }
    else
    {
      cout<<key<<"is not in Bst"<<endl;
      return;
    }

}

Node* Tree::Find_min(Node* ptr)
{
  Node* p =ptr;
  while(p->left!=0)
    p=p->left;

 return ptr;
}


int main()
{;
  Tree tree;
  string input;
  int n;
   while(1)
   {
      cout << " ( 1.insert, 2.delete, 3.print, 4.search, 5.quit ) " << endl;
      cin >> input;
      cout << endl;
      if (input == "1")
      {
         cout <<"값을 입력해주세요. : ";
         cin>>n;
         tree.Insert(n);

      }
      else if (input == "2")
        {
          cin>>n;
            tree.Delete(n);

        }
      else if (input == "3")
        tree.PrintIn();

      else if (input == "4")
      {
        cin>>n;
        tree.Search(n);

      }
      else if (input=="5")
      {
         cout << "프로그램을 종료 합니다. ";
         break;
      }
      else
      {
        cout<<"다시 입력해주세요"<<endl;
        return 0;
      }
   }
   return 0;
}
