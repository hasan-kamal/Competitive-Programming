#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

vii PrefixOps(int n) {
  vii ops;
  for (int i = 1; i < n; i++) {
    ops.push_back(make_pair(i + 1, i));
  }
  return ops;
}

vii SuffixOps(int n) {
  vii ops;
  for (int i = n - 2; i >= 0; i--) {
    ops.push_back(make_pair(i + 1, i + 2));
  }
  return ops;
}

// Assumes a has a large positive element which when added to any negative elem
// makes it non-negative. Similarly, assumes a has a large negative element
// which when added to any positive elem makes it non-positive.
pair<vii, vii> GetBothSolutions(const vi& a) {
  const int n = a.size();

  // Try making everything non-negative.
  int large_max = std::max_element(a.begin(), a.end()) - a.begin();
  vii positive_ops;
  for (int i = 0; i < n; i++) {
    if (a[i] < 0) {
      positive_ops.push_back(make_pair(i + 1, large_max + 1));
    }
  }
  const vii prefix_ops = PrefixOps(n);
  positive_ops.insert(positive_ops.end(), prefix_ops.begin(), prefix_ops.end());

  // Try making everything non-positive.
  int large_min = std::min_element(a.begin(), a.end()) - a.begin();
  vii negative_ops;
  for (int i = 0; i < n; i++) {
    if (a[i] > 0) {
      negative_ops.push_back(make_pair(i + 1, large_min + 1));
    }
  }
  const vii suffix_ops = SuffixOps(n);
  negative_ops.insert(negative_ops.end(), suffix_ops.begin(), suffix_ops.end());

  return make_pair(positive_ops, negative_ops);
}

void PrintOps(const vii& ops) {
  cout << ops.size() << endl;
  for (const auto& op : ops) {
    cout << op.first << " " << op.second << endl;
  }
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    if (*std::min_element(a.begin(), a.end()) >= 0) {
      // All non-negative.
      PrintOps(PrefixOps(n));
      continue;
    } else if (*std::max_element(a.begin(), a.end()) <= 0) {
      // All non-positive.
      PrintOps(SuffixOps(n));
      continue;
    }

    int max_abs_index = std::max_element(a.begin(), a.end(),
                                         [](const int l, const int r) {
                                           return abs(l) < abs(r);
                                         }) -
                        a.begin();
    vii positive_ops, negative_ops;
    if (a[max_abs_index] > 0) {
      int min_idx = std::min_element(a.begin(), a.end()) - a.begin();
      while (a[min_idx] >= -20) {
        a[min_idx] *= 2;
        negative_ops.push_back(make_pair(min_idx + 1, min_idx + 1));
      }
    } else if (a[max_abs_index] < 0) {
      int max_idx = std::max_element(a.begin(), a.end()) - a.begin();
      while (a[max_idx] <= 20) {
        a[max_idx] *= 2;
        positive_ops.push_back(make_pair(max_idx + 1, max_idx + 1));
      }
    }

    const pair<vii, vii> solutions = GetBothSolutions(a);
    positive_ops.insert(positive_ops.end(), solutions.first.begin(),
                        solutions.first.end());
    negative_ops.insert(negative_ops.end(), solutions.second.begin(),
                        solutions.second.end());
    PrintOps(positive_ops.size() < negative_ops.size() ? positive_ops
                                                       : negative_ops);
  }

  return 0;
}