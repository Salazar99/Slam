#pragma once

#include <algorithm>
#include <string>
#include <vector>

#include "DTUtils.hh"

namespace slam {
  /** \brief returns a vector of combinations, k permutations of n elements 
   */
inline void comb(int N, int K, std::vector<std::vector<size_t>> &ret) {
  std::string bitmask(K, 1); // K leading 1's
  bitmask.resize(N, 0);      // N-K trailing 0's

  do {
    std::vector<size_t> tmp;
    for (int i = 0; i < N; ++i) // [0..N-1] integers
    {
      if (bitmask[i])
        tmp.push_back(i);
    }
    ret.push_back(tmp);
  } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
}
} // namespace slam
