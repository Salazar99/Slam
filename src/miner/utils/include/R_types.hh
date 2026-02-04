#pragma once

#include "colors.hh"
#include <iostream>
#include <array>


/** @enum R_types
 *  @brief Used to choose the type of robustness to compute
 */
enum class R_types { STANDARD, CUMULATIVEPOS, CUMULATIVENEG, TROPICALPOS, TROPICALNEG };

// This struct is used to store robustness evaluation results
// Robustness type 
// Robustness mean value
// List of robustness data points
struct robustnessStruct {
    R_types type;
    float mean;
    std::vector<float>* values;
};

// Using std::array for a fixed-size 3x2-style structure
using RobustnessMatrix = std::array<robustnessStruct, 5>;