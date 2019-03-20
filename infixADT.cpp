#include "infix.h" // 새로이 만든 헤더파일을 불러온다
void create_stack(){  // top = -1 로 top 값을 만든다.
    top = -1;
}

int push(int t){ //top 이 쌓이면서 값이 배열의 크기에 도달하면 스택이 꽉차게된다, 그렇지 않으면 스택안에 값을 넣는다.

    if (top >= MAX - 1){
        cout<<"Stack is full!!"<<endl;
        return -1;
    }

    stack[++top] = t;
    return t;
}

int pop(){ //top 이 0 보다 작다면 , 스택의 크기는 0이다. 그리고 삭제시에는 제일 마지막에 push한 값 부터 삭제된다.
    if (top < 0){
        cout<<" Stack is empty!!"<<endl;
        return -1;
    }
    return stack[top--];
}

void print_stack(){ // 지금까지 스택에 들어있는 값을 프린트해준다.
    int i;
    cout<<"TOP ——> Bottom"<<endl;
    for (i = top; i >= 0; i--){ //입력된 순서대로 출력하기 위해서 i 를 탑부터 진행시켰다.
        cout<<stack[i]<<" ";
    }
}


int get_stack_top(){ // 스택의 TOP의 값을 가져온다.
    return (top < 0) ? -1 : stack[top];
}


int Is_empty(){ // 스택이 비어있는지 검사
    return (top <0);
}

int is_operator(int t){   // k 가 연산자인지 판단한다.
    return (t == '+' || t == '-' || t == '*' || t == '/');
}


int is_okay(char *s){ // 후위표기법 수식이 적접한가 체크한다.
    int j = 0;
    while (*s){
        while (*s == ' '){  // 처음에 공백이 있어도 넘어간다
            s++;
        }

        if (is_operator(*s)){ //받은 문자가 연산자일 때를 검사한다
            j--;
        }
        else{ // 받은 문자가 숫자일 때를 검사한다
            j++;
            while (*s != ' '){ //받은 문자의 검사가 끝날때까지지 검사한다
                s++;
            }
        }
        if (j < 1) // 숫자보다 연산자가 많은경우는 성립하지 않는다.
         break;
        s++;
    }
    return (j == 1);
}
