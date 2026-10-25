#include "boardcheck/test_images.hpp"

#include <opencv2/imgproc.hpp>

namespace boardcheck
{
    TestImages generateTestImages()
    {
        TestImages images{cv::Mat(480, 640, CV_8UC3, cv::Scalar(255, 255, 255)), cv::Mat(480, 640, CV_8UC3, cv::Scalar(255, 255, 255)),
                          cv::Mat(600, 800, CV_8UC3, cv::Scalar(255, 255, 255))};

        // Reference image
        cv::rectangle(images.reference, cv::Point(50, 50), cv::Point(200, 150), cv::Scalar(255, 0, 0), 3);
        cv::line(images.reference, cv::Point(20, 200), cv::Point(300, 200), cv::Scalar(0, 0, 0), 2);
        cv::circle(images.reference, cv::Point(400, 250), 40, cv::Scalar(0, 0, 255), -1);

        // Test image
        cv::rectangle(images.test, cv::Point(50, 50), cv::Point(150, 200), cv::Scalar(255, 0, 0), 3);
        cv::line(images.test, cv::Point(200, 20), cv::Point(200, 300), cv::Scalar(0, 0, 0), 2);
        cv::circle(images.test, cv::Point(250, 400), 40, cv::Scalar(0, 0, 255), -1);

        // Higher-resolution test image
        cv::rectangle(images.testHigherResolution, cv::Point(70, 70), cv::Point(170, 220), cv::Scalar(255, 0, 0), 3);
        cv::line(images.testHigherResolution, cv::Point(220, 40), cv::Point(220, 320), cv::Scalar(0, 0, 0), 2);
        cv::circle(images.testHigherResolution, cv::Point(270, 420), 40, cv::Scalar(0, 0, 255), -1);

        return images;
    }
}