#include <iostream>

using namespace std;

class Rectangle{
    private:
        int l;
        int b;
    public:
        Rectangle(int x, int y){
            l = x;
            b = y;
        }

        int area(){
            return l*b;
        }

        int perimeter(){
            return 2*(l+b);
        }

        void editDimensions(int x, int y){
            l = x;
            b = y;
        }
};

int main(){
    Rectangle r(10,5);
    printf("Area: %d Perimeter: %d\n", r.area(), r.perimeter());
    r.editDimensions(10, 10);
    printf("Area: %d Perimeter: %d\n", r.area(), r.perimeter());
    return 0;
}
