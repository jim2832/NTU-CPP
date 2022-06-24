#include <iostream>
using namespace std;

class Point2D{
    public:
        Point2D(){
            X = 0;
            Y = 0;
        }

        Point2D(int x, int y){
            X = x;
            Y = y;
        }

        int getX(){
            return X;
        }

        int getY(){
            return Y;
        }

        void setX(int x){
            X = x;
        }

        void setY(int y){
            Y = y;
        }

        void show2D(){
            cout << "X: " << X << endl;
            cout << "Y: " << Y << endl;
        }

    private:
        int X;
        int Y;
};

class Point3D: public Point2D{ //inheritance
    public:
        Point3D(){ //會呼叫父類別Point2D的constructor
            Z = 0;
        }

        //inheritance
        Point3D(int x, int y, int z): Point2D(x, y){ //call父類別的建構式
            Z = z;
        }

        int getZ(){
            return Z;
        }

        void setZ(int z){
            Z = z;
        }

        void show3D(){
            show2D();
            cout << "Z: " << Z << endl;
        }

    private:
        int Z;
};

int main(void){
    Point3D p3d1, p3d2;

    cout << "P3d1:" << endl;
    p3d1.show2D();

    cout << "P3d2:" << endl;
    p3d2.show3D(); //show2D()也可以呼叫，因為有繼承

    return 0;
}