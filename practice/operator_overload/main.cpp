#include <iostream>
#include "Point2D.h"
using namespace std;

int main(void){
    Point2D p1(5, 5);
    Point2D p2(10, 10);
    Point2D p3;

    p3 = p1 + p2;
    cout << "p3(x, y) = (" << p3.getX() << "," << p3.getY() << ")" << endl;

    p3 = p1 - p2;
    cout << "p3(x, y) = (" << p3.getX() << "," << p3.getY() << ")" << endl;

    return 0;
}