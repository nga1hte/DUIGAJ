#include <iostream>
using namespace std;
#include "stack.h"

int balancedP(char *s){
    stack b;
    int i = 0;
    char p;
    while(s[i]  != '\0'){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            b.push(s[i]);
        else if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
            if(b.isEmpty())
                return 0;
            else{
                p = b.pop();
                if(!((p == '(' && s[i] == ')') || (p == '{' && s[i] == '}') ||
                (p == '[' && s[i] == ']')))
                    return 0;
            }

        }
        i++;
    }
    return b.isEmpty();
}

int main(){
    char s[] = "{(a+b) * (c-d)}[a])";
    if(balancedP(s))
        cout << "It is balanced" << endl;
    else
        cout << "It is not balanced" << endl;
}
