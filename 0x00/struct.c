#include <stdio.h>
#include <stdlib.h>

typedef struct test{
    int arr[2];
    int val;
}test;

void change_arr(test t){
    t.arr[0] = 4;
    t.arr[1] = 5;
    t.val = 6;
    printf("%d %d %d\n", t.arr[0],t.arr[1], t.val);

}

int main(){
    test a = { {0, 1}, 2};
    printf("%d %d %d\n", a.arr[0],a.arr[1], a.val);
    change_arr(a);
    printf("%d %d %d\n", a.arr[0],a.arr[1], a.val);

}
