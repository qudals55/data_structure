#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

class Node
{
  private:
    Node *left;
    Node *right;
    int data;
    Node(int value){data=value; left=0; right = 0;}
    friend class Tree;
};

class Tree
{
  private:
    Node *root;
    int result;
  public:
    Tree(){root=0;}
    ~Tree(){root=0;}
    void preorder(Node *ptr);
    void postorder(Node *ptr);
    void inorder(Node *ptr);
    void buildTree(char b[]);
    int getPriority(char a);
    void Operand(char value);
    void Operator(char value);
    Node* getRoot(){return root;}
    int evalResult(){return result;}
    int evalTree(Node *ptr);
};

int Tree::evalTree(Node *p) //생성된 트리의 연산을 하는 함수
{
  int left_val=0 , right_val=0;

  if( p!=0)
  {
    if ( isdigit(p->data)!=0 ) //숫자일 때는 48을 '0'을 빼서 char형 숫자가 아닌 int형숫자로 바꿔준다
      result = p->data-'0';
    else
    {
      left_val = evalTree(p->left);
      right_val = evalTree(p->right);

      switch (p->data)
      {
        case '+':
          result=left_val+right_val;
          break;
        case '-':
          result=left_val-right_val;
          break;
        case '*':
          result=left_val*right_val;
          break;
        case '/':
          result=left_val/right_val;
          break;
        case '^':
          result = pow(left_val,right_val);
          break;

      }
    }

  }
  else
    cout<< "Empty tree";

return result;
}

int Tree::getPriority(char a) //연산자 우선순위를 반환해준다.
{
    switch(a)
    {
        case '^':
          return 3;
          break;
        case '*':
          return 2;
          break;
        case '/':
          return 2;
          break;
        case '+':
          return 1;
          break;
        case '-':
          return 1;
          break;
        default:
          return 4;
          break;
    }
}

void Tree::preorder(Node *ptr) //전위표기
{
    if(ptr)
    {
        cout << (char)ptr->data;
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void Tree::postorder(Node *ptr) //후위표기
{
    if(ptr)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout << (char)ptr->data;
    }
}

void Tree::inorder(Node *ptr) //중위표기
{
    if(ptr)
    {
        inorder(ptr->left);
        cout << (char)ptr->data;
        inorder(ptr->right);
    }
}

void Tree::buildTree(char b[]) //트리생성
{

      for(int i = 0 ; b[i]!='\0' ; i++)
      {
          if( isdigit(b[i]) != 0 ) //피연산자일때
            Operand(b[i]);
          else //연산자일때
            Operator(b[i]);
      }
}

void Tree::Operand(char value)
{
    Node *temp = new Node(value);
    Node *p = root;
    if(!root)
    {
      root = temp;
    }
    else
    {
        while(p->right!=0)
          p=p->right;

        p->right = temp;
    }
}

void Tree::Operator(char value)
{
    Node *temp = new Node(value);

    if( getPriority(root->data) >= getPriority(temp->data) )
    {
      temp->left = root;
      root = temp;
    }
    else
    {
      temp->left = root->right;
      root->right = temp;
    }
}

int main()
{
    Tree t;
    char input[100];
    char number[3];

    cout << "수식을 입력하세요." << endl;
    cin >> input;

      t.buildTree(input);

    while(1)
    {


      cout << "1. 전위표기  2.후위표기 3.중위표기 4.계산 5.끝내기";
      cin >> number;



      if( strcmp(number,"1") == 0 )
      {
        cout << "전위 표기된 식" << endl;
        t.preorder(t.getRoot());
      }
      else if( strcmp(number,"2") == 0 )
      {
        cout << "후위 표기된 식" << endl;
        t.postorder( t.getRoot() );
      }
      else if( strcmp(number,"3") == 0 )
      {
        cout << "중위 표기된 식" << endl;
        t.inorder( t.getRoot() );
      }
      else if( strcmp(number,"4") == 0 )
      {

          cout << "계산된 결과값은  " << t.evalTree( t.getRoot() ) << "입니다.";
      }
      else if( strcmp(number,"5") == 0 )
      {
          break;
      }
      else
      {
        cout << "잘못된 명령입니다. 다시 입력하세요";
        continue;
      }
      cout << endl;
    }
    return 0;
}
