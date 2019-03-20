#include "infixADT.cpp" //새로이 만든 infix.h 헤더파일을 포함하는는 함수파일을 불러온다.


int token(int op){    // 연산자의 우선순위를 수치로 변환하기 위한 함수
    if (op == '(') return 0;  //우선순위가 제일낮음
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2; // 우선순위가 더하기 빼기보다 큼
    else return 3; // 우선순위가 제일 높음
}


void postfix(char *result, char *test){   // 중위표기법을 후위표기법으로 변환하기 위한 함수
    char c;
    create_stack();   // 탑 값을 -1 로 변환한다.
    while (*test){  //입력받은 값에서 '(' 연산자를 찾아 푸쉬한다.
        if (*test == '('){
            push(*test);
            test++;
        }
        else if (*test == ')'){ // 입력받은 값이 ')' 연산자 이면
            while (get_stack_top() != '('){ // '('연산자를 만날때까지
                *result++ = pop();  // 스택에 있던 값들을 팝하여 출력한다
                *result++ = ' ';  // 한번 넣을때마다 공백 하나씩
            }
            pop();  //  '('를 버린다
            test++;
        }
        else if (is_operator(*test)){ //다음 문자가 연산자이면
            while (!Is_empty() &&
                token(get_stack_top()) >= token(*test)){ //스택에 있는 연산자의 수치보다 입력받은 연산자의 수치가 큰 경우
                *result++ = pop(); //스택에있던 값들을 팝하여 출력한다.
                *result++ = ' ';
            }
            push(*test);  // 작은경우에는 입력받은 연산을 삽입한다.
            test++;
        }
        else if (*test >= '0' && *test <= '9'){   //  입력받은 값이 숫자인경우
            do{
                *result++ = *test++; //테스트의 값을 바로바로 출력한다.
            } while (*test >= '0' && *test <= '9');
            *result++ = ' ';
        }
        else{
            test++;
        }
    }

    while (!Is_empty()){
        *result++ = pop(); //입력이 끝나면 모든 값을 팝하여 출력한다.
        *result++ = ' ';
    }
    result--;   //배열의 마지막에 null값을 대입한다.
    *result = 0;
}


int calc(char *result){   // 후위표기법을 계산한다.
    int i;
    create_stack(); //top 값을 -1로 선언한다.
    while (*result){
        if (*result >= '0' && *result <= '9'){  // 숫자인경우에는
            i = 0;
            do{
                i = i * 10 + *result - '0'; //i를 숫자로 변환한다.
                result++;
            } while (*result >= '0' && *result <= '9'); //0과 9 사이의 결과인 경우에 삽입한다.
            push(i);
        }
        else if (*result == '+'){   // 더하기 연산자이면
            push(pop() + pop()); //맨 위의 두 수를 더해준다.
            result++;
        }
        else if (*result == '*'){ //곱하기 연산자이면
            push(pop() * pop()); //맨 위의 두 수를 곱해준다.
            result++;
        }
        else if (*result == '-'){ // 뺄셈 연산자이면
            i = pop();  // 교환법칙이 성립안되므로 밑에 값에서 위의 값을 뺀다.
            push(pop() - i);
            result++;
        }
        else if (*result == '/'){ //나눗셈 연산자이면
            i = pop(); // 뺄셈과 마찬가지로 교환법칙이 성립안되므로 밑의 값에서 위의 값을 뺀다.
            push(pop() / i);
            result++;
        }
        else{
            result++;
        }
    }
    return pop(); //마지막 남은 수를 출력한다.
}

int main(void){

    int r;
    char * test = new char[20];
  	cin>> test;
    char result[256];

    cout<< test <<endl;

    postfix(result, test);

    cout<<result<<endl;

    if (!is_okay(result)){
        cout<< " no correct !!"<<endl;

    }
    r = calc(result);
     cout<< "Answer : "<<" "<<r<<endl;

    return 0;
}
