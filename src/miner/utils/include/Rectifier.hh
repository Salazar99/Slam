#pragma once

#include <iostream>
#include <algorithm> // for std::max and std::min

enum class RectifierType {
    Positive,
    Negative
};

class Rectifier {
public:
    // Static ensures it can be called as Rectifier::process(...)
    static float process(RectifierType type, float value) {
        if (type == RectifierType::Positive) {
            return std::max(0.0f, value);
        } else {
            return std::min(0.0f, value);
        }
    }
};