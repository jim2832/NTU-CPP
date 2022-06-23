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

Point2D::Point2D(){
    X = 0;
    Y = 0;
}

Point2D::Point2D(int x, int y){
    X = x;
    Y = y;
}

int Point2D::getX(){
    return X;
}

int Point2D::getY(){
    return Y;
}

Point2D Point2D::operator+(Point2D &p){ //第一個Point2D是回傳型態
    int x = X + p.X;
    int y = Y + p.Y;
    Point2D temp(x, y); //初始化 -> 新生成之物件(參數, 參數)
    return temp;
}

Point2D Point2D::operator-(Point2D &p){ //第一個Point2D是回傳型態
    int x = X - p.X;
    int y = Y - p.Y;
    Point2D temp(x, y); //初始化
    return temp;
}

int main(void){
    Point2D p1(5, 5);
    Point2D p2(10, 10);
    Point2D p3;

    cout << "P1:" << endl;
    p1.show2D();
    cout << endl;

    cout << "P2:" << endl;
    p2.show2D();
    cout << endl;

    cout << "P3:" << endl;
    p3.show2D();
    cout << endl;

    p3 = p1 + p2;
    cout << "p3(x, y) = (" << p3.getX() << "," << p3.getY() << ")" << endl;

    p3 = p2 - p1;
    cout << "p3(x, y) = (" << p3.getX() << "," << p3.getY() << ")" << endl;

    return 0;
}