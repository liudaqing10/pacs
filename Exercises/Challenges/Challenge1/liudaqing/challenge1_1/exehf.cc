#include<iostream>
using namespace std;

class Pt2d {
private:
  int id;
  double x;
  double y;
public:
  Pt2d(int _id = 0, double a = 0, double b = 0): id(_id), x(a), y(b) {};
  Pt2d operator=(Pt2d);
  int getid() const{ return id; };
  double getx() const{ return x; };
  double gety() const{ return y; };
  void change(int, double, double);
};

class Edge {
private:
  Pt2d* vertices;
public:
  Edge(Pt2d, Pt2d); 
  Edge(const Edge &);
  ~Edge(){ delete[] vertices; };
  Pt2d getvtc(int i) const{ return vertices[i]; };
  void change(Pt2d, Pt2d);
};

class Triangle {
private:
  int id;
  Pt2d* vertices;
public:
  Triangle(int, Pt2d, Pt2d, Pt2d);
  Triangle(const Triangle &);
  ~Triangle(){ delete[] vertices; };
  int getid() const{ return id; };
  Pt2d getvtc(int i) const{ return vertices[i]; };
  void change(int, Pt2d, Pt2d, Pt2d);
};

Pt2d Pt2d::operator=(Pt2d p){
  id = p.id;
  x = p.x;
  y = p.y;
  return *this;
};

void Pt2d::change(int _id, double a, double b){
  id = _id;
  x = a;
  y = b;
};

Edge::Edge(Pt2d p0, Pt2d p1) {
  vertices = new Pt2d [2];
  vertices[0] = p0;
  vertices[1] = p1;
};

Edge::Edge(const Edge & edg) {
  vertices = new Pt2d [2];
  vertices[0] = edg.getvtc(0);
  vertices[1] = edg.getvtc(1); 
}; 
 
void Edge::change(Pt2d p0, Pt2d p1){
  vertices[0] = p0;
  vertices[1] = p1;
};

Triangle::Triangle(int _id, Pt2d p0, Pt2d p1, Pt2d p2) {
  id = _id;
  vertices = new Pt2d [3];
  vertices[0] = p0;
  vertices[1] = p1;
  vertices[2] = p2;
};

Triangle::Triangle(const Triangle & tri) {
  id = tri.getid();
  vertices = new Pt2d [3];
  vertices[0] = tri.getvtc(0);
  vertices[1] = tri.getvtc(1);
  vertices[2] = tri.getvtc(2);
};

void Triangle::change(int _id, Pt2d p0, Pt2d p1, Pt2d p2){
  id = _id;
  vertices[0] = p0;
  vertices[1] = p1;
  vertices[2] = p2;
};

