
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

  messageErrorIf(labelToValues.empty(),"Empty map of values");

  for (auto &[l,vv] : labelToValues) {
      assert(!vv.empty());
  }

  //for each point of the map {label,(value,time)}
  for (auto &[l,vv] : labelToValues) {

      //find max and min values in vv

      T minValue =(*std::min_element(vv.begin(),vv.end(),[](const std::array<T,2> &a,const std::array<T,2> &b){return a[0]<b[0];}))[0];
      
      T maxValue =(*std::max_element(vv.begin(),vv.end(),[](const std::array<T,2> &a,const std::array<T,2> &b){return a[0]<b[0];}))[0];

      size_t minDistance = (*std::min_element(vv.begin(),vv.end(),[](const std::array<T,2> &a,const std::array<T,2> &b){return a[1]<b[1];}))[1];
      size_t maxDistance = (*std::max_element(vv.begin(),vv.end(),[](const std::array<T,2> &a,const std::array<T,2> &b){return a[1]<b[1];}))[1];
     
      ranges.push_back(std::make_pair(std::make_pair(minValue, maxValue),std::make_pair(minDistance,maxDistance)));

  }
  return ranges;
}
