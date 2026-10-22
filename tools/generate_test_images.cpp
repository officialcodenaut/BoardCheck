#include <cstdio>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

int main()
{
    cv::Mat ref(480, 640, CV_8UC3, cv::Scalar(255, 255, 255));
    cv::Mat test(480, 640, CV_8UC3, cv::Scalar(255, 255, 255));
    cv::Mat test_h_r(600, 800, CV_8UC3, cv::Scalar(255, 255, 255));

    // reference.png
    cv::rectangle(ref, cv::Point(50, 50), cv::Point(200, 150), cv::Scalar(255, 0, 0), 3);

    cv::line(ref, cv::Point(20, 200), cv::Point(300, 200), cv::Scalar(0, 0, 0), 2);

    cv::circle(ref, cv::Point(400, 250), 40, cv::Scalar(0, 0, 255), -1);

    // test.png
    cv::rectangle(test, cv::Point(50, 50), cv::Point(150, 200), cv::Scalar(255, 0, 0), 3);

    cv::line(test, cv::Point(200, 20), cv::Point(200, 300), cv::Scalar(0, 0, 0), 2);

    cv::circle(test, cv::Point(250, 400), 40, cv::Scalar(0, 0, 255), -1);

    // test_higher_resolution.png
    cv::rectangle(test_h_r, cv::Point(70, 70), cv::Point(170, 220), cv::Scalar(255, 0, 0), 3);

    cv::line(test_h_r, cv::Point(220, 40), cv::Point(220, 320), cv::Scalar(0, 0, 0), 2);

    cv::circle(test_h_r, cv::Point(270, 420), 40, cv::Scalar(0, 0, 255), -1);

    if (!cv::imwrite("data/reference.png", ref))
    {
        std::fprintf(stderr, "Error: failed to save reference.png image\n");
        return 4;
    }

    if (!cv::imwrite("data/test.png", test))
    {
        std::fprintf(stderr, "Error: failed to save test.png image\n");
        return 4;
    }

    if (!cv::imwrite("data/test_higher_resolution.png", test_h_r))
    {
        std::fprintf(stderr, "Error: failed to save test_higher_resolution.png image\n");
        return 4;
    }

    return 0;
}
