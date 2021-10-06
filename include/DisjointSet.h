#ifndef ALGORITHMS_DISJOINTSET_H
#define ALGORITHMS_DISJOINTSET_H

#include <vector>
#include <utility>

using namespace std;

class DisjointSet {
public:
  DisjointSet(int N) : roots_(N), ranks_(N, 0) {
    for (int i = 0; i < N; i++) {
      roots_[i] = i;
    }
  }

  void unite(int x, int y) {
    if (same(x, y)) return;

    if (rank(x) > rank(y)) {
      swap(x, y);
    }

    if (rank(y) == rank(x)) {
      ranks_[findRoot(y)] += 1;
    }

    roots_[findRoot(x)] = findRoot(y);
  }

  bool same(int x, int y) {
    return findRoot(x) == findRoot(y);
  }

private:
  vector<int> roots_;
  vector<int> ranks_;

  int findRoot(int n) {
    if (roots_[n] == n) return n;
    roots_[n] = findRoot(roots_[n]);
    return roots_[n];
  }

  int rank(int n) {
    return ranks_[findRoot(n)];
  }
};

#endif //ALGORITHMS_DISJOINTSET_H
