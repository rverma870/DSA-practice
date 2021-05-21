#include <iostream>
#include<bits/stdc++.h>
using namespace std;

std::tuple<int,int> partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
    swap(a[l], a[j]);
    int p=j;
  for(int i=j-1;i>=0;i--)
  {
    if(a[i]>=x)
    {
      p--;
      swap(a[i],a[p]);
    }
  }
  return make_tuple(j,p);
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int j,p;
  tie(j,p)=partition2(a,l,r);

  randomized_quick_sort(a, l, p - 1);
  randomized_quick_sort(a, j + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
