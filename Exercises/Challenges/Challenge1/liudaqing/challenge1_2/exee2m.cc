#include<iostream>
#include<vector>
#include<set>
#include<array>
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

struct clscmp{
  bool operator()(Edge const & e1, Edge const & e2) {
    auto e1id1 = min(e1.getvtc(0).getid(), e1.getvtc(1).getid());
    auto e1id2 = max(e1.getvtc(0).getid(), e1.getvtc(1).getid());
    auto e2id1 = min(e2.getvtc(0).getid(), e2.getvtc(1).getid());
    auto e2id2 = max(e2.getvtc(0).getid(), e2.getvtc(1).getid());
    if (e1id1 == e2id1) return e1id2 < e2id2;
    return e1id1 < e2id1;
  };
};


bool find_equal(Edge e1, Edge e2) {
  auto e1_id1 = min(e1.getvtc(0).getid(), e1.getvtc(1).getid());
  auto e1_id2 = max(e1.getvtc(0).getid(), e1.getvtc(1).getid());
  auto e2_id1 = min(e2.getvtc(0).getid(), e2.getvtc(1).getid());
  auto e2_id2 = max(e2.getvtc(0).getid(), e2.getvtc(1).getid());
  return ((e1_id1==e2_id1) && (e1_id2==e2_id2));
};

int main() {
  int n = 4; // number of rows of nodes on y
  int m = 6; // number of columns of nodes on x

  Pt2d p0(1,0,0);
  vector<Pt2d> vpt(n*m,p0);
//  vpt.reserve(n*m);

//  cout<<"the size of vtr = "<< vtr.size() <<endl;

  cout<<"The points are: "<<endl;
  for (auto i=0; i<n; ++i) {
    for (auto j=0; j<m; ++j) {    
      vpt[i*m+j].change(i*m+j+1,j*(1./(m-1)),i*(1./(n-1)));
//      vpt.push_back(p0);
      cout<<"("<<vpt[i*m+j].getid()<<", "<<vpt[i*m+j].getx()<<", "<<vpt[i*m+j].gety()<<") ";
    };
    cout<<endl;
  };

  cout<<"number of points = "<<vpt.size()<<endl;

  Triangle tri(1,vpt[0],vpt[1],vpt[m]);
  vector<Triangle> vtr(2*(n-1)*(m-1), tri);
//  vtr.reserve(2*(n-1)*(m-1));

  cout<<endl;
  cout<<"The triangles are: "<<endl;
  for (auto i=0; i<n-1; ++i) {
    for (auto j=0; j<2*(m-1); ++j) {
//      cout<<"I am changing the triangles vertices to "<<vpt[i*m+(j+1)/2].getx()<<","<<vpt[(i+j%2)*m+(j+2)/2].getx()<<","<<vpt[(i+1)*m+(j)/2].getx()<<endl;
      vtr[i*2*(m-1)+j].change(i*2*(m-1)+j+1,vpt[i*m+(j+1)/2],vpt[(i+j%2)*m+(j+2)/2],vpt[(i+1)*m+(j)/2]);
      cout<<"{"<<vtr[i*2*(m-1)+j].getid()<<", ("<<vtr[i*2*(m-1)+j].getvtc(0).getid()<<", "<<vtr[i*2*(m-1)+j].getvtc(0).getx()<<", "<<vtr[i*2*(m-1)+j].getvtc(0).gety()<<") "\
          <<"("<<vtr[i*2*(m-1)+j].getvtc(1).getid()<<", "<<vtr[i*2*(m-1)+j].getvtc(1).getx()<<", "<<vtr[i*2*(m-1)+j].getvtc(1).gety()<<") "\
          <<"("<<vtr[i*2*(m-1)+j].getvtc(2).getid()<<", "<<vtr[i*2*(m-1)+j].getvtc(2).getx()<<", "<<vtr[i*2*(m-1)+j].getvtc(2).gety()<<")} "<<endl;
/*
      if (j>0)  {
      cout<<"The previous one was "<<endl;
      cout<<"{"<<vtr[i*2*(m-1)+j-1].getid()<<", ("<<vtr[i*2*(m-1)+j-1].getvtc(0).getid()<<", "<<vtr[i*2*(m-1)+j-1].getvtc(0).getx()<<", "<<vtr[i*2*(m-1)+j-1].getvtc(0).gety()<<") "\
          <<"("<<vtr[i*2*(m-1)+j-1].getvtc(1).getid()<<", "<<vtr[i*2*(m-1)+j-1].getvtc(1).getx()<<", "<<vtr[i*2*(m-1)+j-1].getvtc(1).gety()<<") "\
          <<"("<<vtr[i*2*(m-1)+j-1].getvtc(2).getid()<<", "<<vtr[i*2*(m-1)+j-1].getvtc(2).getx()<<", "<<vtr[i*2*(m-1)+j-1].getvtc(2).gety()<<")} "<<endl;
	};
*/
//      vtr.push_back(tri);
/*      cout<<"{"<<tri.getid()<<", ("<<tri.getvtc(0).getid()<<", "<<tri.getvtc(0).getx()<<", "<<tri.getvtc(0).gety()<<") "\
          <<"("<<tri.getvtc(1).getid()<<", "<<tri.getvtc(1).getx()<<", "<<tri.getvtc(1).gety()<<") "\
          <<"("<<tri.getvtc(2).getid()<<", "<<tri.getvtc(2).getx()<<", "<<tri.getvtc(2).gety()<<")} ";
*/
    };
    cout<<endl;
  };

  cout<<"number of triangles = "<<vtr.size()<<endl;

  int vs = vtr.size();
  Edge edg1(vtr[0].getvtc(0), vtr[0].getvtc(1)); 
  vector<Edge> vedg(3*vs, edg1);
//  vedg.reserve(3*vs);
//  Edge edg2(vtr[0].getvtc(1), vtr[0].getvtc(2));
//  Edge edg3(vtr[0].getvtc(2), vtr[0].getvtc(0));

  cout<<endl;
//  cout<<"The edges of thses triangles are: "<<vedg.size()<<endl;
  for (auto i=0; i<vs; ++i){
/*
      cout<<"{"<<vtr[i].getid()<<", ("<<vtr[i].getvtc(0).getid()<<", "<<vtr[i].getvtc(0).getx()<<", "<<vtr[i].getvtc(0).gety()<<") "\
          <<"("<<vtr[i].getvtc(1).getid()<<", "<<vtr[i].getvtc(1).getx()<<", "<<vtr[i].getvtc(1).gety()<<") "\
          <<"("<<vtr[i].getvtc(2).getid()<<", "<<vtr[i].getvtc(2).getx()<<", "<<vtr[i].getvtc(2).gety()<<")} ";
*/

     vedg[3*i].change(vtr[i].getvtc(0), vtr[i].getvtc(1)); 

//     vedg.push_back(edg1);
/*     cout<<"("<<vedg[3*i].getvtc(0).getid()<<", "<<vedg[3*i].getvtc(0).getx()<<", "<<vedg[3*i].getvtc(0).gety()<<"), ("<<\
              vedg[3*i].getvtc(1).getid()<<", "<<vedg[3*i].getvtc(1).getx()<<", "<<vedg[3*i].getvtc(1).gety()<<")"<<endl;
*/
     vedg[3*i+1].change(vtr[i].getvtc(1), vtr[i].getvtc(2));
//     vedg.push_back(edg2);
/*     cout<<"("<<vedg[3*i+1].getvtc(0).getid()<<", "<<vedg[3*i+1].getvtc(0).getx()<<", "<<vedg[3*i+1].getvtc(0).gety()<<"), ("<<\
              vedg[3*i+1].getvtc(1).getid()<<", "<<vedg[3*i+1].getvtc(1).getx()<<", "<<vedg[3*i+1].getvtc(1).gety()<<")"<<endl;
*/
     vedg[3*i+2].change(vtr[i].getvtc(2), vtr[i].getvtc(0));
//     vedg.push_back(edg3);
/*     cout<<"("<<vedg[3*i+2].getvtc(0).getid()<<", "<<vedg[3*i+2].getvtc(0).getx()<<", "<<vedg[3*i+2].getvtc(0).gety()<<"), ("<<\
              vedg[3*i+2].getvtc(1).getid()<<", "<<vedg[3*i+2].getvtc(1).getx()<<", "<<vedg[3*i+2].getvtc(1).gety()<<")"<<endl;
*/
  };

  multiset<Edge,clscmp> msed; 
  for (int i=0; i<3*vs; i++) { msed.insert(vedg[i]); };

  vector<Edge> myvec;
  myvec.reserve(msed.size());
  for (auto i:msed) myvec.push_back(i);

  set<Edge,clscmp> sed;

  int mvs = myvec.size();
  int mvit=0;
  while (mvit < (mvs-1)) {
    if (find_equal(myvec[mvit],myvec[mvit+1])) {
      mvit = mvit + 2;
    } else {
        sed.insert(myvec[mvit]);
        mvit++;
    }
  };

  if (!(find_equal(myvec[myvec.size()-2],myvec[myvec.size()-1]))) {sed.insert(myvec[myvec.size()-1]);};
  cout<<"number of boundary edges = "<<sed.size()<<endl;
  cout<<"The boundary edges of the mesh are: "<<endl;
  for (auto i:sed) cout<<"("<<i.getvtc(0).getid()<<", "<<i.getvtc(0).getx()<<", "<<i.getvtc(0).gety()<<"), ("<<i.getvtc(1).getid()\
                       <<", "<<i.getvtc(1).getx()<<", "<<i.getvtc(1).gety()<<")"<<endl;

}



 

