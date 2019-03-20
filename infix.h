#include <iostream>
using namespace std;
#define MAX 100

int stack[MAX];        // 스택의 크기
int top;            // 스택의 탑

void create_stack(); //스택의 탑을 만드는 함수
int push(int t); // 스택에 값을 넣기 위한 함수
int pop();// 스택에 있는 값을 삭제 하기 위한 함수
void print_stack();//스특에 있는 값을 출력하기 위한 함수
int get_stack_top();// 스택의 탑 값을 가져오기위한 함수
int Is_empty();// 스택이 비어있는지 확인하기 위한 함수
int is_operator(int t);// 주어진 값이 연산자인지 판별하기 위한 함수
int is_okay(char *s); // 후위표기법 함수가 적합한지 판별하기위한 함수
