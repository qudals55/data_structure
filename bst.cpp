//20143029 공병민 HW_04 BST.cpp

// 알고리즘 : 먼저 BST의 정의를 살펴보면, BST는 자신의 부모보다 작은 노드는 왼쪽에 위치하고, 자신의 부모보다 큰 노드는 오른쪽에 위치한다. 이 형태가 트리의 모양이
//          아무리 커지더라도, 유지 되어야 한다.
//          1.insert 함수는 BST를 유지하기 위해서, 넣을 값이 루트 보다작으면, 루트 왼쪽 노드를 계속 탐색 해서 넣을 값보다 큰 노드를 찾는다. 그 큰 노드를 찾으면
//            그것의 왼쪽 노드에 넣을 값을 트리에 연결하고, 반대로, 넣을 값이 루트보다 크면, 루트의 오른쪽 노드를 계속 탐색 해서 넣을 값 보다 작은 노드를 찾는다.
//            그 작은노드를 찾으면 그것의 오른쪽 노드에 넣을값을 트리에 연결한다. 계속 찾기위해 재귀함수를 사용한다.
//          2. delete 함수는 BST를 유지하기위해서 삭제 할 값이 루트보다 작으면 왼쪽으로 가고, 루트보다 크면 오른쪽으로간다. 그리고 찾았을때, 그 노드의 왼쪽 노드가 비었는지
//            오른쪽 노드가 비었는지, 아니면 자식이 둘다 있는지를 판단해서, 왼쪽노드가 비어있으면 그것의 오른쪽 노드로 대체 시키고, 반대로 오른쪽 노드가 비어있으면
//            그것의 왼쪽노드로 대체 시킨다. 만약에 자식노드가 2개면, 방법이 두가지가 잇는데, 한가지는 그 자식의 오른쪽노드에서 가장 작은 것으로 대체 시키거나,
//             왼쪽 노드에서 가장 큰 것으로 대체시킨다.
//          3. search 함수는 재귀함수를 통해 BST의 형태를 이용해서 루트보다 작으면 계속 왼쪽으로 내려가면서 찾고, 루트보다 크면 계속 오른쪽으로 내려가면서 값을 찾는다.
//             따라서 널값에 다다르면 못 찾은것이므로 return 한다.

#include<iostream>
#include<string>
using namespace std;
class Node {  //트리를 구성할 노드를 구현한다
private:
   int  data; //노드는 데이터 값을 갖고
   Node* left;  // 다른노드를 왼쪽에서 연결시킬 주소를 갖고
   Node* right; // 다른노드를 오른쪽에서 연결시킬 주소를 갖는다
   friend class Tree; //그 노드를 구성할 트리를 프렌드로 구성한다.
public:
   Node(int value):data(value),left(NULL),right(NULL) {} // 노드생성

};
class Tree {
private:
   Node* root;  //트리는 가장 부모인 root를 갖는다
public:
   Tree():root(NULL){}
   ~Tree(){root=NULL;}
   void Bst_Insert(Node* &ptr,int key); //  노드 추가를 위한 함수 //레퍼런스를 쓴 이유는 ptr이 root를 가리킬 때, 그가리키는 값을 유지하기 위해서이다.
   Node* getroot(){return root;}  //루트를 반환하기 위한 함수
   void Bst_Search(Node* ptr, int key);   // Bst 에서 검색을 하기위한 함수
   void Bst_Delete(int key, Node* &ptr);  // 노드 삭제를 위한 함수
   Node* Find_min(Node* ptr);  // 자식이 둘인 노드를 제거할 때 root의 오른쪽 노드에서 가장 작은 노드를 반환하기 위한 함수
   void drawTree(){drawBSTree(root,1);} // 트리를 그리기 위한 함수 -> root를 drawBSTree 에 넣는다.
   void drawBSTree(Node* p, int level); // 트리를 레벨에 맞게 그리기 위한 함수
   void Insert(int key){Bst_Insert(root, key);}  //노드를 추가하기 위해, 루트 부터 검색하여 BST의 형태를 유지하기 위해 루트부터 검색한다
   void Delete(int key){Bst_Delete(key, root);} //노드를 삭제하기 위해, 루트 부터 검색하여 BST의 형태를 유지하기 위해 루트부터 검색한다
   void Search(int key){Bst_Search(root, key);} //노드를 검색하기 위해, 루트 부터 검색한다.
   void Inorder(Node* ptr); // 인오더 형식 즉 , 왼쪽->부모->오른쪽 순으로 출력으로도 해본다.
   void PrintIn(){Inorder(root);} //인오더 형식으로 출력하기 위해 루트 값을 대입한다.

};

void Tree::Bst_Insert(Node* &ptr, int key)
{
  if(ptr==NULL) //현재 루트가 비어 있으면
  {
    Node* temp = new Node(key);   //새로운 노드를 만들고
    ptr = temp; //그 새로운 노드는 루트가 된다

  }
  else if( key < ptr->data)   //넣을 값이 루트보다 작으면
      Bst_Insert(ptr->left, key); // 왼쪽자식으로 계속 가면서 자신보다 작은 노드를 찾을때까지 검색한다. 찾으면 그것의 오른쪽에 새 노드를 넣어둔다.
  else if (key > ptr->data)   //넣을 값이 루트보다 크면
      Bst_Insert(ptr->right, key);  //오른쪽 자식으로 계속 가면서 자신보다 큰 노드를 잧을때까지 검색한다. 찾으면 거것의 왼쪽에 새 노드를 넣어둔다.

}

void Tree::Bst_Search(Node* ptr, int key)
{
  if(ptr==NULL) //루트가 NULL이면 찾을 값이 없다.
  {
    cout<<key<<"is not in Bst"<<endl;
    return;
  }
  else
  {
    if(key==ptr->data) // 키를 찾는다면
      cout<<key<<"is in Bst"<<endl; // 키를 찾았다.
    else if(key>ptr->data)  // 키보다 루트의 데이터가 작으면
      Bst_Search(ptr->right, key);  //계속오른쪽으로가면서 키보다 작은 값을 찾는다.
    else if(key < ptr->data)  //  키보다 루트의 데이터가 크면
      Bst_Search(ptr->left, key); // 계속 왼쪽으로가면서 키보다 큰 값을 찾는다.
  }
}

void Tree::Bst_Delete(int key, Node* &ptr)
{
  Node* temp=NULL;
  Node* p=NULL;
    if(ptr!=NULL) //루트가 널값이 아니면
    {
      if(key < ptr->data) //루트보다 키값이 작으면
        Bst_Delete(key, ptr->left); //왼쪽으로 계속 가면서 키값을 찾는다
      else if( key > ptr->data) //루트보다 키값이 크면
        Bst_Delete(key, ptr->right);//오른쪽으로 가면서 키값을 계속 찾는다
      else if((ptr->left ==NULL ) && (ptr->right==NULL)) // 찾은 키값이 leaf노드라면
        ptr=NULL; // leaf 노드를 삭제시킨다
      else
        if(ptr->left ==NULL)  //찾은 키값의 왼쪽자식이 널이면
        {
          p= ptr; ptr=ptr->right; delete(p);  //찾은 키의 오른쪽 자식을 본래 위치에 붙이고, 찾은 키값을 삭제시킨다
        }
        else if(ptr->right ==NULL)  //찾은 키값의 오른쪽 자식이 널이면
        {
          p=ptr ; ptr = ptr->left; delete(p);   //찾은 키의 왼쪽 자식을 본래 위치에 붙이고, 찾은 키 값을 삭제시킨다
        }
        else
        {
          temp = Find_min(ptr->right);  // 오른쪽에서 가장 작은 값을 찾기위해 오른쪽의 왼쪽 끝 값을 계속 찾는다.
          ptr->data = temp->data; // 찾은값을 데이터에 넣고
          Bst_Delete(ptr->data, ptr->right);  // 다시 그 값을 찾아서 본래 값을 삭제시킨다.
        }
    }
    else
    {
      cout<<key<<"is not in Bst"<<endl;
      return;
    }

}

Node* Tree::Find_min(Node* ptr) //오른쪽 노드에서 가장 작은 값을 찾기 위한 함수
{
  Node* p =ptr;
  while(p->left!=0) //왼쪽노드가 없을때까지 가서
    p=p->left;  //그 노드를 가리킨다

 return p;
}
void Tree::drawBSTree(Node* p, int level) //BST를 그리기 위한 함수
{
  if(p!=0 && level<=7)  // 레벨이 7 이하이면
  {
    drawBSTree(p->right, level+1);  // 맨끝 오른쪽 자식을 먼저 찾는다.
    for(int i=1; i<=level-1;i++)  // 그레벨만큼 빈공간으로 만들어서 자식 과 부모 관계를 잘보이게 한다
      cout<<" "; //빈공간
    cout<<p->data;  // 빈공간이 지난후 데이터 출력
    if(p->left!=0 && p->right !=0) // 자식노드가 2개있는 부모노드라면
      cout<<"<"<<endl;  // <출력
    else if(p->right!=0)  //오른쪽 노드가 없는 부모노드라면
      cout<<"/"<<endl;  // '\'출력
    else if(p->left!=0) //왼쪽 자식 노드가 없는 부모노드라면
      cout<<"\\"<<endl; // '\\'출력
    else
      cout<<endl;// 부모자식관계를 보이게 하기위해 줄띄어쓰기를 출력한다.
     drawBSTree(p->left, level+1);  // 루트노드 까지오면 왼쪽 자식을 찾아서 다시 출력한다.

  }
}
void  Tree::Inorder(Node* ptr) // 왼쪽 자식 -> 부모 -> 오른쪽 자식 출력
{
  if(ptr){
    Inorder(ptr->left);   //  왼쪽 자식 출력
    cout<<ptr->data<<" "; //부모 출력
    Inorder(ptr->right);  //오른쪽 자식 출력
  }
}


int main()
{
  Tree tree;
  string input;
  int n;
   while(1)
   {
      cout << " ( 1.insert, 2.delete, 3.print, 4.search, 5.Inorder, 6.quit ) " << endl;
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
        tree.drawTree();

      else if (input == "4")
      {
        cin>>n;
        tree.Search(n);

      }
      else if (input == "5")
        tree.PrintIn();
      else if (input=="6")
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
