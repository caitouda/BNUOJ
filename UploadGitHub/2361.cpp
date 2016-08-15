#include<cmath>
#include<iomanip>
#include<iostream>

using namespace std;

const double pi=3.141592653589793;

int main()
{
    double x1, y1, x2, y2, x3, y3, a, b, c, st, cir, r, p;
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3)
    {
        a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
        c=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
        p=(a+b+c)/2;
        st=sqrt(p*(p-a)*(p-b)*(p-c)); //三角形面積，海倫公式
        r=a*b*c/(4*st);
        cir=2*pi*r;
        cout.setf(ios::fixed);
        cout.precision(2);
        cout<<cir<<endl;
    }
    return 0;
}


