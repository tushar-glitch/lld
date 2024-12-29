#include <iostream>
using namespace std;

class Point{
    int x, y, z;
    public:
    Point() = default;
    Point(int xx, int yy, int zz) : x{xx}, y{yy}, z{zz}{};
    friend ostream& operator<<(ostream&, const Point&);
    friend istream& operator>>(istream&, Point&);
};

istream& operator>>(istream &in, Point &point){
    in>>point.x>>point.y>>point.z;
    return in;
}

ostream& operator<<(ostream &out, const Point &point){
    out<<point.x<<" "<<point.y<<" "<<point.z<<endl;
    return out;
}

int main()
{
    Point p{1,2,3};
    cout<<p;
    return 0;
}