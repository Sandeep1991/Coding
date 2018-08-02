#include <bits/stdc++.h>

/*
 * SPOJ MST
 * We have to use ll instead of int to score 100 on this task
 * */
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

// Union-Find Disjoll Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<ll>
  ll numSets;
public:
  UnionFind(ll N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (ll i = 0; i < N; i++) p[i] = i; }
  ll findSet(ll i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(ll i, ll j) { return findSet(i) == findSet(j); }
  void unionSet(ll i, ll j) { 
    if (!isSameSet(i, j)) { numSets--; 
    ll x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  ll numDisjollSets() { return numSets; }
  ll sizeOfSet(ll i) { return setSize[findSet(i)]; }
};

vector<vii> AdjList;
vi taken;                                  // global boolean flag to avoid cycle
priority_queue<ii> pq;            // priority queue to help choose shorter edges

int main() {
  ll V, E, u, v, w;

  /*
  // Graph in Figure 4.10 left, format: list of weighted edges
  // This example shows another form of reading graph input
  5 7
  0 1 4
  0 2 4
  0 3 6
  0 4 6
  1 2 2
  2 3 8
  3 4 9
  */

  scanf("%lld %lld", &V, &E);
  // Kruskal's algorithm
  AdjList.assign(V, vii());
  vector< pair<ll, ii> > EdgeList;   // (weight, two vertices) of the edge
  for (ll i = 0; i < E; i++) {
    scanf("%lld %lld %lld", &u, &v, &w);            // read the triple: (u, v, w)
    u = u - 1; v = v - 1;
    EdgeList.push_back(make_pair(w, ii(u, v)));                // (w, u, v)
    AdjList[u].push_back(ii(v, w));
    AdjList[v].push_back(ii(u, w));
  }
  sort(EdgeList.begin(), EdgeList.end()); // sort by edge weight O(E log E)
                      // note: pair object has built-in comparison function

  ll mst_cost = 0;
  UnionFind UF(V);                     // all V are disjoll sets initially
  for (ll i = 0; i < E; i++) {                      // for each edge, O(E)
    pair<ll, ii> front = EdgeList[i];
    if (!UF.isSameSet(front.second.first, front.second.second)) {  // check
      mst_cost += front.first;                // add the weight of e to MST
      UF.unionSet(front.second.first, front.second.second);    // link them
  } }                       // note: the runtime cost of UFDS is very light

  // note: the number of disjoll sets must eventually be 1 for a valid MST
  printf("%lld\n",mst_cost);
  return 0;
}
