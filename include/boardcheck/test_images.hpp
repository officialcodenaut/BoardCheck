#pragma once

#include <opencv2/core.hpp>

namespace boardcheck
{
    struct TestImages
    {
        cv::Mat reference;
        cv::Mat test;
        cv::Mat testHigherResolution;
    };

    TestImages generateTestImages();
}