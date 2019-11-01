// author : Gabriel De Ioannes
// author : Sagar Nagaraj

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class Point2D {
public:
    int x;
    int y;
};

int ORI(Point2D p1, Point2D p2,Point2D p3);
string Inter(Point2D &a, Point2D &b,Point2D &p, Point2D &q);
string interPoint(Point2D &a, Point2D &b,Point2D &p, Point2D &q);
string getPointCords(Point2D &a);

int main (){
    string line;
    
    while(getline(std::cin,line)){
        if(line == "0 0 0 0 0 0 0 0"){
            break;
        }
        istringstream ss(line);
        Point2D a,b,p,q;
        ss >> a.x >> a.y >> b.x >> b.y >> p.x >> p.y >> q.x >> q.y;
        cout << Inter(a,b,p,q);
        cout.flush();
    }
    return 0;
}

int ORI(Point2D p1, Point2D p2,Point2D p3){
double dx21 = p2.x - p1.x;
double dy21 = p2.y - p1.y;
double dx31 = p3.x - p1.x;
double dy31 = p3.y - p1.y;
if (dx21*dy31 < dy21*dx31) return -1; // ccw

if (dx21*dy31 > dy21*dx31) return +1; // cw

if (dx21*dx31 < 0 || dy21*dy31<0) return -1; // ccw

if (dx31*dx31 + dy31*dy31 > dx21*dx21 + dy21*dy21) return +1; //cw

return 0; // p3 is inside p1,p2
}

string Inter(Point2D &a, Point2D &b,Point2D &p, Point2D &q){
    if( ORI(a,b,p)*ORI(a,b,q)<0 && ORI(p,q,a)*ORI(p,q,b)<0){
        //return "intersection\n";
        return interPoint(a,b,p,q);
    }
    if( ORI(a,b,p)*ORI(a,b,q)==0 && ORI(p,q,a)*ORI(p,q,b)==0){
        if(a.x==b.x && a.y==b.y){
            return getPointCords(a);
        }
        
        if(p.x==q.x && p.y==q.y){
            return getPointCords(q);
        }
        
        if((b.x==p.x && b.y==p.y || a.x==p.x && a.y==p.y) && !(b.x==q.x && b.y==q.y || a.x==q.x && a.y==q.y)){
            return getPointCords(p);
        }
        
        if((b.x==q.x && b.y==q.y || a.x==q.x && a.y==q.y) && !(b.x==p.x && b.y==p.y || a.x==p.x && a.y==p.y)){
            return getPointCords(q);
        }
        
        return "segment intersection\n";
    }
    return "no intersection\n";
}

string getPointCords(Point2D &a){
    ostringstream text;
    text << fixed;
    text << std::setprecision(2) << (double)(a.x);
    text << " ";
    text << std::setprecision(2) << (double)(a.y);
    text << "\n"; 
    return text.str();
}

string interPoint(Point2D &a, Point2D &b,Point2D &p, Point2D &q){
    double ua1 = ((q.x-p.x)*(a.y-p.y)-(q.y-p.y)*(a.x-p.x));
    double ua2 = ((q.y-p.y)*(b.x-a.x)-(q.x-p.x)*(b.y-a.y));
    double ua = ua1/ua2;
    double ub1 = ((b.x-a.x)*(a.y-p.y)-(b.y-a.y)*(a.x-p.x));
    double ub2 = ((q.y-p.y)*(b.x-a.x)-(q.x-p.x)*(b.y-a.y));
    double ub = ub1/ub2;

    double x = a.x + ua*(b.x-a.x);
    double y = a.y + ub*(b.y-a.y);
    
    ostringstream text;
    text << fixed;
    text << std::setprecision(2) << x;
    text << " ";
    text << std::setprecision(2) << y;
    text << "\n"; 
    return text.str();
}