#include <iostream>
#include <vector>

using namespace std;

struct disjoint_sets {
  vector<int> roots;
  vector<int> heights;

  disjoint_sets(int in_size) {
    for (int i = 0; i < in_size; i++) roots.push_back(i);
    heights.assign(in_size, 0);
  }

  int find(int idx) {
    return (idx == roots[idx]) ? idx : (roots[idx] = find(roots[idx]));
  }

  void join(int idx1, int idx2) {
    int r1 = find(idx1);
    int r2 = find(idx2);

    if (r1 == r2) return;
    if (heights[r1] >= heights[r2])
      roots[r2] = r1;
    else
      roots[r1] = r2;

    if (heights[r1] == heights[r2]) heights[r1]++;
  }
};


int main() {
  disjoint_sets my_sets(6);

  // cout << my_sets.roots.size() << endl;
  // cout << my_sets.heights.size() << endl;

  // my_sets.join(2, 5);

  my_sets.join(2, 0);
  my_sets.join(2, 5);

  for (int i = 0; i < my_sets.roots.size(); i++)
    cout << my_sets.roots[i] << endl;

  if (my_sets.find(0) == my_sets.find(5)) cout << "OK" << endl;
}