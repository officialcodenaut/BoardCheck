#include "boardcheck/test_images.hpp"

#include <cstdio>
#include <opencv2/imgcodecs.hpp>

int main()
{
    const boardcheck::TestImages images = boardcheck::generateTestImages();

    if (!cv::imwrite("data/reference.png", images.reference))
    {
        std::fprintf(stderr, "Error: failed to save reference.png image\n");
        return 4;
    }

    if (!cv::imwrite("data/test.png", images.test))
    {
        std::fprintf(stderr, "Error: failed to save test.png image\n");
        return 4;
    }

    if (!cv::imwrite("data/test_higher_resolution.png", images.testHigherResolution))
    {
        std::fprintf(stderr, "Error: failed to save test_higher_resolution.png image\n");
        return 4;
    }

    return 0;
}
