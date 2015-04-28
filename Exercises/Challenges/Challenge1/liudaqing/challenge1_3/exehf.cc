#include<iostream>
using namespace std;

class Pt3d {
private:
  int id;
  double x;
  double y;
  double z;
public:
  Pt3d(int _id = 0, double a = 0, double b = 0, double c = 0): id(_id), x(a), y(b), z(c) {};
  Pt3d operator=(Pt3d);
  int getid() const{ return id; };
  double getx() const{ return x; };
  double gety() const{ return y; };
  double getz() const{ return z; };
  void change(int, double, double, double);
};

class Edge {
private:
  Pt3d* vertices;
public:
  Edge(Pt3d, Pt3d); 
  Edge(const Edge &);
  ~Edge(){ delete[] vertices; };
  Pt3d getvtc(int i) const{ return vertices[i]; };
  void change(Pt3d, Pt3d);
};

class Triangle {
private:
  Pt3d* vertices;
public:
  Triangle(Pt3d,Pt3d,Pt3d);
  Triangle(const Triangle &);
  ~Triangle(){ delete[] vertices; };
  Pt3d getvtc(int i) const{ return vertices[i]; };
  void change(Pt3d, Pt3d, Pt3d);
};

class Tetrahedron {
private:
  int id;
  Pt3d* vertices;
public:
  Tetrahedron(int, Pt3d, Pt3d, Pt3d, Pt3d);
  Tetrahedron(const Tetrahedron &);
  ~Tetrahedron(){ delete[] vertices; };
  int getid() const{ return id; };
  Pt3d getvtc(int i) const{ return vertices[i]; };
  void change(int, Pt3d, Pt3d, Pt3d, Pt3d);
};

Pt3d Pt3d::operator=(Pt3d p){
  id = p.id;
  x = p.x;
  y = p.y;
  z = p.z;
  return *this;
};

void Pt3d::change(int _id, double a, double b, double c){
  id = _id;
  x = a;
  y = b;
  z = c;
};

Edge::Edge(Pt3d p0, Pt3d p1) {
  vertices = new Pt3d [2];
  vertices[0] = p0;
  vertices[1] = p1;
};

Edge::Edge(const Edge & edg) {
  vertices = new Pt3d [2];
  vertices[0] = edg.getvtc(0);
  vertices[1] = edg.getvtc(1); 
}; 
 
void Edge::change(Pt3d p0, Pt3d p1){
  vertices[0] = p0;
  vertices[1] = p1;
};

Triangle::Triangle(Pt3d p0, Pt3d p1, Pt3d p2) {
  vertices = new Pt3d [3];
  vertices[0] = p0;
  vertices[1] = p1;
  vertices[2] = p2;
};

Triangle::Triangle(const Triangle & tri) {
  vertices = new Pt3d [3];
  vertices[0] = tri.getvtc(0);
  vertices[1] = tri.getvtc(1);
  vertices[2] = tri.getvtc(2);
};

void Triangle::change(Pt3d p0, Pt3d p1, Pt3d p2){
  vertices[0] = p0;
  vertices[1] = p1;
  vertices[2] = p2;
};

Tetrahedron::Tetrahedron(int _id, Pt3d p0, Pt3d p1, Pt3d p2, Pt3d p3){
  id = _id;
  vertices = new Pt3d [4];
  vertices[0] = p0;
  vertices[1] = p1;
  vertices[2] = p2;
  vertices[3] = p3;
};

Tetrahedron::Tetrahedron(const Tetrahedron & trhd) {
  id = trhd.getid();
  vertices = new Pt3d [4];
  vertices[0] = trhd.getvtc(0);
  vertices[1] = trhd.getvtc(1);
  vertices[2] = trhd.getvtc(2);
  vertices[3] = trhd.getvtc(3);
};

void Tetrahedron::change(int _id, Pt3d p0, Pt3d p1, Pt3d p2, Pt3d p3){
  id = _id;
  vertices[0] = p0;
  vertices[1] = p1;
  vertices[2] = p2;
  vertices[3] = p3;
};



