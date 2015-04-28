#include<iostream>
#include<vector>
#include<set>
#include<array>
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

struct clscmp {
  bool operator()(Triangle const & t1, Triangle const & t2) {
    auto t1id1 = min(min(t1.getvtc(0).getid(), t1.getvtc(1).getid()), t1.getvtc(2).getid());
    auto t1id2 = max(min(t1.getvtc(0).getid(), t1.getvtc(1).getid()), min(max(t1.getvtc(0).getid(), t1.getvtc(1).getid()), t1.getvtc(2).getid()));
    auto t1id3 = max(max(t1.getvtc(0).getid(), t1.getvtc(1).getid()), t1.getvtc(2).getid());
    auto t2id1 = min(min(t2.getvtc(0).getid(), t2.getvtc(1).getid()), t2.getvtc(2).getid());
    auto t2id2 = max(min(t2.getvtc(0).getid(), t2.getvtc(1).getid()), min(max(t2.getvtc(0).getid(), t2.getvtc(1).getid()), t2.getvtc(2).getid()));
    auto t2id3 = max(max(t2.getvtc(0).getid(), t2.getvtc(1).getid()), t2.getvtc(2).getid());
    if (t1id1 == t2id1){
      if (t1id2 == t2id2) return t1id3 < t2id3;
      return t1id2 < t2id2;
    };
    return t1id1 < t2id1;
  };
};

bool find_equal(Triangle t1, Triangle t2) {
  auto t1_id1 = min(min(t1.getvtc(0).getid(), t1.getvtc(1).getid()), t1.getvtc(2).getid());
  auto t1_id2 = max(min(t1.getvtc(0).getid(), t1.getvtc(1).getid()), min(max(t1.getvtc(0).getid(), t1.getvtc(1).getid()), t1.getvtc(2).getid()));
  auto t1_id3 = max(max(t1.getvtc(0).getid(), t1.getvtc(1).getid()), t1.getvtc(2).getid());
  auto t2_id1 = min(min(t2.getvtc(0).getid(), t2.getvtc(1).getid()), t2.getvtc(2).getid());
  auto t2_id2 = max(min(t2.getvtc(0).getid(), t2.getvtc(1).getid()), min(max(t2.getvtc(0).getid(), t2.getvtc(1).getid()), t2.getvtc(2).getid()));
  auto t2_id3 = max(max(t2.getvtc(0).getid(), t2.getvtc(1).getid()), t2.getvtc(2).getid());
  return ((t1_id1 == t2_id1) && (t1_id2 == t2_id2) && (t1_id3 == t2_id3));
};

int main() {

  Pt3d p0(0,0,0,0);
  Pt3d p1(1,1,0,0);
  Pt3d p2(2,1,1,0);
  Pt3d p3(3,0,1,0);
  Pt3d p4(4,0,0,1);

  Tetrahedron ttrhd0(0,p0,p1,p2,p4);
  vector<Tetrahedron> vttrhd(2, ttrhd0);
  vttrhd[1].change(1,p0,p2,p3,p4);

  Triangle trg1(vttrhd[0].getvtc(0), vttrhd[0].getvtc(1), vttrhd[1].getvtc(2));
  int vtrhs = vttrhd.size();
  vector<Triangle> vtr(4*vtrhs, trg1);

  for (auto i=0; i<vtrhs; ++i) {
    vtr[i*4].change(vttrhd[i].getvtc(0), vttrhd[i].getvtc(1), vttrhd[i].getvtc(2));
    vtr[i*4+1].change(vttrhd[i].getvtc(0), vttrhd[i].getvtc(1), vttrhd[i].getvtc(3));
    vtr[i*4+2].change(vttrhd[i].getvtc(0), vttrhd[i].getvtc(2), vttrhd[i].getvtc(3));
    vtr[i*4+3].change(vttrhd[i].getvtc(1), vttrhd[i].getvtc(2), vttrhd[i].getvtc(3));
  };

/*
  for (int i=0; i<4*vtrhs; i++) cout<<"("<<vtr[i].getvtc(0).getid()<<", "<<vtr[i].getvtc(0).getx()<<", "<<vtr[i].getvtc(0).gety()<<", "<<vtr[i].getvtc(0).getz()<<"), ("\
                       <<vtr[i].getvtc(1).getid()<<", "<<vtr[i].getvtc(1).getx()<<", "<<vtr[i].getvtc(1).gety()<<", "<<vtr[i].getvtc(1).getz()<<"), ("\
                       <<vtr[i].getvtc(2).getid()<<", "<<vtr[i].getvtc(2).getx()<<", "<<vtr[i].getvtc(2).gety()<<", "<<vtr[i].getvtc(2).getz()<<")"<<endl;
*/
  set<Triangle,clscmp> str;
  for (auto i=0; i<4*vtrhs; i++) { str.insert(vtr[i]); }; 
  cout<<"The number of faces of this mesh is: "<<str.size()<<endl;
  cout<<"The faces of this mesh are: "<<'\n';

  for (auto i:str) cout<<"("<<i.getvtc(0).getid()<<", "<<i.getvtc(0).getx()<<", "<<i.getvtc(0).gety()<<", "<<i.getvtc(0).getz()<<"), ("\
                       <<i.getvtc(1).getid()<<", "<<i.getvtc(1).getx()<<", "<<i.getvtc(1).gety()<<", "<<i.getvtc(1).getz()<<"), ("\
                       <<i.getvtc(2).getid()<<", "<<i.getvtc(2).getx()<<", "<<i.getvtc(2).gety()<<", "<<i.getvtc(2).getz()<<")"<<endl;

  multiset<Triangle,clscmp> mstr;
  for (auto i=0; i<4*vtrhs; ++i) { mstr.insert(vtr[i]); };

  vector<Triangle> myvec;
  myvec.reserve(mstr.size());
  for (auto i:mstr) myvec.push_back(i);
  set<Triangle,clscmp> sbtr;
 
  int mvs = myvec.size(); 
  int mvit = 0;
  while (mvit < (mvs-1)) {
    if (find_equal(myvec[mvit],myvec[mvit+1])) {
      mvit = mvit + 2;
    } else {
      sbtr.insert(myvec[mvit]);
      mvit++;
    };
  };
  if (!(find_equal(myvec[myvec.size()-2],myvec[myvec.size()-1]))) {sbtr.insert(myvec[myvec.size()-1]);};
  cout<<"The number of boundary faces of this mesh is: "<<sbtr.size()<<endl;
  cout<<"The boundary faces of this mesh are: "<<'\n';
  for (auto i:sbtr) cout<<"("<<i.getvtc(0).getid()<<", "<<i.getvtc(0).getx()<<", "<<i.getvtc(0).gety()<<", "<<i.getvtc(0).getz()<<"), ("\
                       <<i.getvtc(1).getid()<<", "<<i.getvtc(1).getx()<<", "<<i.getvtc(1).gety()<<", "<<i.getvtc(1).getz()<<"), ("\
                       <<i.getvtc(2).getid()<<", "<<i.getvtc(2).getx()<<", "<<i.getvtc(2).gety()<<", "<<i.getvtc(2).getz()<<")"<<endl;

}


