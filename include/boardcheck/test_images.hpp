#pragma once

#include <opencv2/core.hpp>
#include <filesystem>

namespace boardcheck
{
    struct TestImages
    {
        cv::Mat reference;
        cv::Mat test;
        cv::Mat testHigherResolution;
    };

    TestImages generateTestImages();

    bool saveTestImages(
        const TestImages &images,
        const std::filesystem::path &directory,
        bool overwrite
    );
}
