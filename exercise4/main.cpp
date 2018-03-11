#include <iostream>
#include <unordered_map>

using namespace std;

class Point
{
private:
    int x, y;
public:
  Point(int x, int y) :x(x), y(y) {};
  bool operator == (const Point& p) const { return (x== p.x && y == p.y);}
  int getx() const {return x;}
  int gety() const {return y;}

};

int main()
{
  std::unordered_map<int, int> umap;
  for(int i = 0; i < 100; i++)
  {
    umap.insert({i, i + 1});
    cout<<"bucket load factor"<<i<<" has "<<umap.load_factor()<<" elements"<<endl;
  }
  for(auto& x : umap)
  {
    cout<< x.first << ": " << x.second <<endl;
  }

  cout<<endl;

  cout<<"Bucket_count: "<<umap.bucket_count()<<endl;
  cout<<"Load_factor: "<<umap.load_factor()<<endl;

  unsigned nbuckets = umap.bucket_count();
  cout<<"umap has: "<<nbuckets<<" buckets"<<endl;
  for(unsigned i = 0; i<nbuckets; ++i)
  {
    cout<<"bucket #"<<i<<" has "<<umap.bucket_size(i)<<" elements"<<endl;
    // cout<<"bucket load factor"<<i<<" has "<<umap.load_factor()<<" elements"<<endl;
  }

}
