#include <iostream>
using namespace std;

class Point1D{
    public:
        Point1D(){
            X = 0;
        }

        Point1D(int x){
            X = x;
        }

        int getX(){
            return X;
        }

        void setX(int x){
            X = x;
        }

        void show1D(){
            cout << "X: " << X << endl;
        }

    private:
        int X;
};

//inheritance
class Point2D: public Point1D{ //public inheritance
    public:
        Point2D(){
            Y = 0;
        }

        Point2D(int x, int y):Point1D(x){
            Y = y;
        }

        int getY(){
            return Y;
        }

        void setY(int y){
            Y = y;
        }

        void show2D(){
            show1D();
            cout << "Y: " << Y << endl;
        }

    private:
        int Y;
};

//inheritance twice
class Point3D: public Point2D{ //public inheritance
    public:
        Point3D(){
            Z = 0;
        }

        Point3D(int x, int y, int z):Point2D(x, y){
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
    Point3D p1(1, 3, 4);
    Point3D p2;

    cout << "p1: (" << p1.getX() << "," << p1.getY() << "," << p1.getZ() << ")" << endl;

    p2.setX(5);
    p2.setY(7);
    p2.setZ(8);

    cout << "p2: (" << p2.getX() << "," << p2.getY() << "," << p2.getZ() << ")" << endl;

    return 0;
}