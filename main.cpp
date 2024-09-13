#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll n, l, d;
bool music, bell;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> l >> d;
  ll mcount = l;
  ll off_count = 0;
  ll bcount = 1;
  ll next_bell = 0;
  music = true;
  bell = true;
  ll now = 0;
  while (true) {
    if (now == next_bell) {
      bell = true;
      bcount = 1;
    }

    // cout << now << ' ' << music << ' ' << bell << '\n';

    if (!music && bell) {
      cout << now;
      return 0;
    }

    if (0 < mcount) {
      --mcount;
      if (0 == mcount) {
        off_count = 5;
        music = false;
        --n;
      }
    } else {
      --off_count;
      if (0 == off_count) {
        if (0 < n) {
          mcount = l;
          music = true;
        }
      }
    }

    if (0 < bcount) {
      --bcount;
      next_bell = now + d;
      bell = false;
    }

    ++now;
  }

  return 0;
}