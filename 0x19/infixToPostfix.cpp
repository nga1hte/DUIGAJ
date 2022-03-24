#include <iostream>
using namespace std;
#include "../0x18/stack.h"

int isOperand(char s){
    switch(s){
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '(':
        case ')':
            return 0;
        default:
            return 1;
    }
}

int outPrec(char s){
    switch(s){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 3;
        case '^':
            return 6;
        case '(':
            return 7;
        case ')':
            return 0;
        default:
            return -1;
   }
}

int inPrec(char s){
    switch(s){
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 4;
        case '^':
            return 5;
        case '(':
            return 0;
        default:
            return -1;
   }
}

int isBalanced(char *s){
    int i;
    stack b;
    for(i = 0; s[i] != '\0'; i++){
        if(s[i] == '(')
            b.push(s[i]);
        else if(s[i] == ')'){
            if(b.isEmpty())
                return 0;
            b.pop();
        }
    }
    if(b.isEmpty())
        return 1;
    else 
        return 0;

}

char *infixToPostfix(char *s){
    if(!isBalanced(s)){
        cout << "It is not balanced! Aborting" << endl;
        return nullptr;
    }
    stack st;
    char *p = new char[20];
    int i = 0, k = 0;
    while(s[i] != '\0'){
        if(isOperand(s[i]))
            p[k++] = s[i++];
        else{
            if(st.isEmpty())
                st.push(s[i++]);
            else{
                if(outPrec(s[i]) > inPrec(st.stackTop()))
                    st.push(s[i++]);
                else if(outPrec(s[i]) == inPrec(st.stackTop())){
                    st.pop();
                    i++;
                }else{
                    p[k++] = st.pop();
                }
            }
        }
    }
    while(!st.isEmpty() && st.stackTop() != ')'){
        p[k++] = st.pop();
    }
    p[k] = '\0';
    return p;
}

int evaluatePostfix(char *s){
    int i = 0;
    stack op;
    int a, b, res;
    while(s[i] != '\0'){
        if(isOperand(s[i]))
            op.push(s[i] - 48);
        else{
            b = op.pop();
            a = op.pop();

            if(s[i] == '+')
                res = a+b;
            else if(s[i] == '-')
                res = a-b;
            else if(s[i] == '*')
                res = a*b;
            else if(s[i] == '/')
                res = a/b;
            op.push(res);
        }
        i++;
    }
    return op.stackTop();
}

char *infixToPrefix(char *s){
    int i = 0;
    int k = 0;
    int len;

    while(s[i] !='\0')
        i++;
    i--;
    len = i;

    char *rev = new char[i+1];
    while(i >= 0)
        rev[k++] = s[i--];
    rev[k] = '\0';

    char *p = infixToPostfix(rev);

    i = len; k = 0;
    while(i >= 0)
        rev[k++] = p[i--];
    rev[k] = '\0';

    return rev;

}

int main(){
    char s[] = "3*5+6/2-4";
    char *p = infixToPostfix(s);
    cout << s << endl;
    cout << p << endl;
    cout << evaluatePostfix(p) << endl;
    char *i = infixToPrefix(s);
    cout << i << endl;
    return 0;
}
