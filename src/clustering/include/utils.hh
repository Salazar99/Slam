
#pragma once
#include <algorithm>
#include <unordered_map>
#include <vector>

template <typename T>
std::vector<std::pair<T, T>>
toRanges(std::unordered_map<size_t, std::vector<T>> &labelToValues);

template <typename T>
std::vector<std::pair<std::pair<T, T>,std::pair<size_t,size_t>>>
toRanges2D(std::unordered_map<size_t, std::vector<T>> &labelToValues);

template <typename T>
std::vector<std::pair<T, T>>
toRanges(std::unordered_map<size_t, std::vector<T>> &labelToValues) {
  std::vector<std::pair<T, T>> ranges;

  for (auto &l_vv : labelToValues) {
    std::vector<T> values;
    for (auto &v : l_vv.second) {
      values.push_back(v);
    }
    if (values.empty())
      continue;

    std::sort(values.begin(), values.end());
    if (values.size() > 1) {
      ranges.emplace_back(std::make_pair(values.front(), values.back()));
    } else {
      ranges.emplace_back(std::make_pair(values.back(), values.back()));
    }
  }
  return ranges;
}

template <typename T>
std::vector<std::pair<std::pair<T, T>,std::pair<size_t,size_t>>>
toRanges2D(std::unordered_map<size_t, std::vector<std::array<T,2>>> &labelToValues) {
  std::vector<std::pair<std::pair<T, T>,std::pair<size_t,size_t>>> ranges;

  //for each point of the map {label,(value,time)}
  for (auto &l_vv : labelToValues) {
    std::vector<T> values;
    std::vector<size_t> times;
    //for each array of the label
    for (auto &v : l_vv.second) {
      values.push_back(v[0]);
      times.push_back((size_t)v[1]);
    }
    if (values.empty() || times.empty())
      continue;

    //sort values
    std::sort(values.begin(), values.end());
    //sort times
    std::sort(times.begin(),times.end());
    if (values.size() > 1 && times.size() > 1) {
      ranges.emplace_back(std::make_pair(std::make_pair(values.front(), values.back()),std::make_pair(times.front(),times.back())));
    } else {
      ranges.emplace_back(std::make_pair(std::make_pair(values.back(), values.back()),std::make_pair(times.back(),times.back())));
    }
  }
  return ranges;
}