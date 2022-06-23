#include <Point2D.h>

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