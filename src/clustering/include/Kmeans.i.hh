
#include "dkm.hpp"
#include "globals.hh"
#include "utils.hh"
#include <algorithm>
#include <cfloat>
#include <chrono>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

template <typename T>
std::vector<std::pair<T, T>> kmeans(std::vector<std::pair<T, T>> elements,
                                    size_t k) {
  // store data in the correct format
  std::vector<std::array<T, 2>> data;
  for (size_t i = 0; i < elements.size(); i++) {
    data.push_back(
        std::array<T, 2>({(T)(elements[i].first), (T)(elements[i].second)}));
  }

  std::vector<std::pair<T, T>> ranges;
  double prevSD = DBL_MAX;

  // generate the clusters
  auto cluster_data = dkm::kmeans_lloyd(data, k);

  // group the clusters by label
  std::unordered_map<size_t, std::vector<T>> labelToValues;
  for (size_t j = 0; j < std::get<1>(cluster_data).size(); j++) {
    auto label = std::get<1>(cluster_data)[j];
    labelToValues[label].push_back(data[j]);
  }

  // translate the customers into ranges [min, max]
  auto rr = toRanges<T>(labelToValues);
  // add the ranges to the final list
  ranges.insert(ranges.end(), rr.begin(), rr.end());

  return ranges;
}

template <typename T>
std::vector<std::pair<T, T>> kmeansElbow(std::vector<T> elements, size_t max,
                                         double SDmin_red, bool keepOnlyBest) {
  // store data in the correct format
  std::vector<std::array<T, 1>> data;
  for (size_t i = 0; i < elements.size(); i++) {
    data.push_back(std::array<T, 1>({(T)(elements[i])}));
  }

  std::vector<std::pair<T, T>> ranges;
  double prevSD = DBL_MAX;
  for (size_t i = 1; i <= max && i <= elements.size(); i++) {
    // generate the clusters
    auto cluster_data = dkm::kmeans_lloyd(data, i, 100);

    // group the clusters by label
    std::unordered_map<size_t, std::vector<T>> labelToValues;
    for (size_t j = 0; j < std::get<1>(cluster_data).size(); j++) {
      auto label = std::get<1>(cluster_data)[j];
      labelToValues[label].push_back(data[j][0]);
    }

    // compute the standard deviation
    double totSD = 0.f;
    auto means = std::get<0>(cluster_data);
    for (size_t k = 0; k < means.size(); k++) {
      double mean = means[k][0];
      double currSD = 0.f;
      for (auto &v : labelToValues[k]) {
        currSD += std::pow(mean - (double)v, 2);
      }
      currSD = std::sqrt(currSD / (double)elements.size());
      totSD += currSD;
    }

    // continue only if the standard deviation reduction is above the
    // defined threshold
    if (std::abs((double)prevSD - (double)totSD) / (double)prevSD < SDmin_red) {
      break;
    }
    // translate the clusters into ranges [min, max]
    auto rr = toRanges<T>(labelToValues);
    // add the ranges to the final list
    if (keepOnlyBest) {
      ranges.clear();
    }
    ranges.insert(ranges.end(), rr.begin(), rr.end());
    prevSD = totSD;

  }

  // remove redundant ranges
  std::set<std::pair<T, T>> uniqueRanges;
  for (auto &lr : ranges) {
    uniqueRanges.insert(lr);
  }

  std::vector<std::pair<T, T>> ret;

  //translate the ranges into the output format
  for (auto &lr : uniqueRanges) {
    ret.push_back(lr);
  }
  std::sort(ret.begin(), ret.end(),
            [](const std::pair<T, T> &e1, const std::pair<T, T> &e2) {
              return e1.second <= e2.first;
            });

  return ret;
}
// Function to plot scatter points and rectangles using Gnuplot
template <typename T>
void plotPointsAndRectangles(
    const std::vector<std::pair<T, T>> &points,
    const std::vector<std::tuple<double, double, double, double>> &rectangles,
    const std::string &title) {
  //  const char *colors[] = {
  //      "red",  "green",   "orange", "purple", "brown",
  //      "cyan", "magenta", "yellow", "gray",   "white",
  //      // Add more colors here as needed
  //  };
  const char *colors[] = {"dark-grey",
                          "red",
                          "web-green",
                          "web-blue",
                          "dark-magenta",
                          "dark-cyan",
                          "dark-orange",
                          "dark-yellow",
                          "royalblue",
                          "goldenrod",
                          "dark-spring-green",
                          "purple",
                          "steelblue",
                          "dark-red",
                          "dark-chartreuse",
                          "orchid",
                          "aquamarine",
                          "brown",
                          "yellow",
                          "turquoise",
                          "grey0",
                          "grey10",
                          "grey20",
                          "grey30",
                          "grey40",
                          "grey50",
                          "grey60",
                          "grey70",
                          "grey",
                          "grey80",
                          "grey90",
                          "grey100",
                          "light-red",
                          "light-green",
                          "light-blue",
                          "light-magenta",
                          "light-cyan",
                          "light-goldenrod",
                          "light-pink",
                          "light-turquoise",
                          "gold",
                          "green",
                          "dark-green",
                          "spring-green",
                          "forest-green",
                          "sea-green",
                          "blue",
                          "dark-blue",
                          "midnight-blue",
                          "navy",
                          "medium-blue",
                          "skyblue",
                          "cyan",
                          "magenta",
                          "dark-turquoise",
                          "dark-pink",
                          "coral",
                          "light-coral",
                          "orange-red",
                          "salmon",
                          "dark-salmon",
                          "khaki",
                          "dark-khaki",
                          "dark-goldenrod",
                          "beige",
                          "olive",
                          "orange",
                          "violet",
                          "dark-violet",
                          "plum",
                          "dark-plum",
                          "dark-olivegreen",
                          "orangered4",
                          "brown4",
                          "sienna4",
                          "orchid4",
                          "mediumpurple3",
                          "slateblue1",
                          "yellow4",
                          "sienna1",
                          "tan1",
                          "sandybrown",
                          "light-salmon",
                          "pink",
                          "khaki1",
                          "lemonchiffon",
                          "bisque",
                          "honeydew",
                          "slategrey",
                          "seagreen",
                          "antiquewhite",
                          "chartreuse",
                          "greenyellow",
                          "gray",
                          "light-gray",
                          "light-grey",
                          "dark-gray",
                          "slategray",
                          "gray0",
                          "gray10",
                          "gray20",
                          "gray30",
                          "gray40",
                          "gray50",
                          "gray60",
                          "gray70",
                          "gray80",
                          "gray90",
                          "gray100"};

  const size_t numColors = sizeof(colors) / sizeof(colors[0]);
  size_t colorIndex = 0;

  FILE *gnuplotPipe = popen("gnuplot -persist", "w");
  if (gnuplotPipe == nullptr) {
    std::cerr << "Error: Failed to open Gnuplot pipe." << std::endl;
    return;
  }

  auto xMinMax = std::minmax_element(
      points.begin(), points.end(),
      [](const auto &p1, const auto &p2) { return p1.first < p2.first; });
  auto yMinMax = std::minmax_element(
      points.begin(), points.end(),
      [](const auto &p1, const auto &p2) { return p1.second < p2.second; });

  double xMin = xMinMax.first->first;
  double xMax = xMinMax.second->first;
  double yMin = yMinMax.first->second;
  double yMax = yMinMax.second->second;

  xMin *= xMin > 0 ? 0.9 : 1.1;
  xMax *= xMax > 0 ? 1.1 : 0.9;
  yMin *= yMin > 0 ? 0.9 : 1.1;
  yMax *= yMax > 0 ? 1.1 : 0.9;

  fprintf(gnuplotPipe, "set xrange [%f:%f]\n", xMin, xMax);
  fprintf(gnuplotPipe, "set yrange [%f:%f]\n", yMin, yMax);

  // Send scatter plot commands for points

  // Send scatter plot commands for points
  fprintf(gnuplotPipe, "set title '%s'\n", title.c_str());

  // Set x and y labels
  fprintf(gnuplotPipe, "set xlabel 'Value'\n");
  fprintf(gnuplotPipe, "set ylabel 'Distance'\n");

  fprintf(gnuplotPipe,
          "plot '-' with points pt 7 ps 0.3 lc rgb 'black' notitle\n");

  // Send points data to the pipe
  for (const auto &point : points) {
    fprintf(gnuplotPipe, "%f %f\n", (double)point.first, (double)point.second);
  }
  fprintf(gnuplotPipe, "e\n");

  // Draw rectangles using set object rect
  size_t rectangleIndex = 1;
  for (const auto &rectangle : rectangles) {

    double x1, y1, x2, y2;
    std::tie(x1, x2, y1, y2) = rectangle;

    const char *color = colors[colorIndex % numColors];
    ++colorIndex;

    fprintf(gnuplotPipe,
            "set object %ld rect from %f,%f to %f,%f fc rgb '%s' fillstyle "
            "transparent solid 0.5\n",
            rectangleIndex, x1, y1, x2, y2, color);
    //    printf("set object %ld rect from %f,%f to %f,%f fc rgb '%s'\n",
    //           rectangleIndex, x1, y1, x2, y2, color);

    ++rectangleIndex;
  }

  // Replot to include rectangles
  fprintf(gnuplotPipe, "replot\n");

  // Close the pipe
  pclose(gnuplotPipe);
}

template <typename T>
void printClusters(
    const std::vector<std::pair<T, T>> &elements,
    const std::vector<std::pair<std::pair<T, T>, std::pair<size_t, size_t>>>
        &ret,
    const std::string &expName) {

  //prepare data
  std::vector<std::tuple<double, double, double, double>> rectangles;
  for (auto &[n, t] : ret) {
    rectangles.emplace_back((double)n.first, (double)n.second, t.first,
                            t.second);
  }
  int avgShift = 5;
  for (auto &[f, s, t, fo] : rectangles) {
    if (f > 0) {
      f *= ((100 - rand() % avgShift) / 100.f);

    } else {
      f /= ((100 - rand() % avgShift) / 100.f);
    }
    if (s > 0) {
      s *= ((rand() % avgShift + 100) / 100.f);
    } else {
      s /= ((rand() % avgShift + 100) / 100.f);
    }
    if (t > 0) {
      t *= ((100 - rand() % avgShift) / 100.f);
    } else {
      t /= ((100 - rand() % avgShift) / 100.f);
    }
    if (fo > 0) {
      fo *= ((rand() % avgShift + 100) / 100.f);
    } else {
      fo /= ((rand() % avgShift + 100) / 100.f);
    }
    if ((s - f) * (fo - t) == 0) {
      f -= 1.f;
      s += 1.f;
      t -= 1.f;
      fo += 1.f;
    }
  }

  //  std::vector<std::pair<double, double>> points = {
  //      {1.0, 1.0}, {2.0, 2.0}, {3.0, 3.0}, {4.0, 4.0}, {5.0, 5.0}};
  //  std::vector<std::tuple<double, double, double, double>> rects = {
  //      {1, 3, 2, 4}};
  //sort rectangles
  std::sort(rectangles.begin(), rectangles.end(),
            [](const std::tuple<double, double, double, double> &e1,
               const std::tuple<double, double, double, double> &e2) {
              return ((std::get<1>(e1) - std::get<0>(e1)) *
                      (std::get<3>(e1) + std::get<2>(e1))) >
                     ((std::get<1>(e2) - std::get<0>(e2)) *
                      (std::get<3>(e2) + std::get<2>(e2)));
            });

  plotPointsAndRectangles(elements, rectangles, expName);
  //  plotPointsAndRectangles(points, rects);
  char c;
  std::cin >> c;
}
template <typename T>
std::string toHash(const std::pair<std::pair<T, T>, std::pair<size_t, size_t>> &range){
    return std::to_string(range.first.first) + "_" + std::to_string(range.first.second) + "_" + std::to_string(range.second.first) + "_" + std::to_string(range.second.second);
}
template <typename T>
std::vector<std::pair<std::pair<T, T>, std::pair<size_t, size_t>>>
kmeansElbowStl(std::vector<std::pair<T, T>> elements, size_t max,
               double SDmin_red, bool keepOnlyBest,
               const std::string &expName) {

  // store data in the correct format
  std::vector<std::array<T, 2>> data;
  for (size_t i = 0; i < elements.size(); i++) {
    data.push_back(
        std::array<T, 2>({elements[i].first, elements[i].second}));
  }

  std::vector<std::pair<std::pair<T, T>, std::pair<size_t, size_t>>> ranges;
  std::unordered_set<std::string> rangesHash;
  double prevSD = DBL_MAX;
  for (size_t i = 1; i <= max && i <= elements.size(); i++) {
    // generate the clusters
    std::tuple<std::vector<std::array<T, 2>>, std::vector<uint32_t>>
        cluster_data = dkm::kmeans_lloyd(data, i, 100);

    auto means = std::get<0>(cluster_data);
    auto labels = std::get<1>(cluster_data);

//    // print the clusters
//    for (size_t j = 0; j < data.size(); j++) {
//      std::cout << "("<<data[j][0]<<","<<data[j][0]<<") "<< " " << labels[j] << std::endl;
//    }
//
//    std::cout << "means:" << "\n";
//    for (size_t k = 0; k < means.size(); k++) {
//    std::cout << k<<"----->"<< means[k][0]<<","<<means[k][1]<< "\n";
//    }
    

    // group data by label
    std::unordered_map<size_t, std::vector<std::array<T, 2>>> labelToValues;
    for (size_t j = 0; j < labels.size(); j++) {
      labelToValues[labels[j]].push_back(data[j]);
    }

    if (labelToValues.size()!=i) {
        //kmeans failed for unknown reason
        break;
    }


    // compute the standard deviation
    double totSD = 0.f;
    for (size_t k = 0; k < i; k++) {
      double meanValues = means[k][0];
      double meanDistances = means[k][1];
      double currSD = 0.f;
      for (auto &v : labelToValues[k]) {
        currSD += std::pow(((double)(std::abs(meanValues - v[0]) + std::abs(meanDistances - v[1])))/2.f , 2);
      }
      currSD = std::sqrt(currSD / (double)elements.size());
      totSD += currSD;
    }

    // continue only if the standard deviation reduction is above the
    // defined threshold
    if (std::abs((double)prevSD - (double)totSD) / (double)prevSD < SDmin_red) {
      break;
    }

    // translate the clusters into ranges [min, max]
    auto rr = toRanges2D<T>(labelToValues);

    // add the ranges to the final list
    if (keepOnlyBest) {
      ranges.clear();
    }
    for (auto &newRange : rr) {
        std::string newRangeHash = toHash(newRange);
        if (!rangesHash.count(newRangeHash)) {
            ranges.push_back(newRange);
            rangesHash.insert(newRangeHash);
        }
    }

    prevSD = totSD;

    //print sd
    //std::cout << totSD << "\n";
    //std::cout << "-----------------------" << "\n";
  }


  if (clc::debugCls) {
    printClusters(elements, ranges, expName);
  }

  //sort to simplify debug
  sort(ranges.begin(),ranges.end(),[](const std::pair<std::pair<T, T>,std::pair<size_t,size_t>> &a,const std::pair<std::pair<T, T>,std::pair<size_t,size_t>> &b){return a.second.second<b.second.second ;} );

  return ranges;
}

