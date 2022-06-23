#include <iostream>
using namespace std;

class Point2D{
    public:
        Point2D();
        Point2D(int x, int y);
        int getX();
        int getY();
        void show2D(){
            cout << "X: " << X << endl;
            cout << "Y: " << Y << endl;
        }
        Point2D operator+(Point2D &p); //重載+運算子
        Point2D operator-(Point2D &p); //重載-運算子

    private:
        int X;
        int Y;
};