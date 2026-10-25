
#include "boardcheck/test_images.hpp"

#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include <vector>

namespace boardcheck
{
    namespace
    {
        constexpr int boardWidth = 640;
        constexpr int boardHeight = 480;

        const cv::Scalar backgroundColor{35, 35, 35};
        const cv::Scalar boardColor{45, 105, 45};
        const cv::Scalar copperColor{75, 155, 190};
        const cv::Scalar padColor{80, 175, 205};
        const cv::Scalar silkscreenColor{225, 230, 215};
        const cv::Scalar componentColor{35, 35, 40};

        void drawTrace(
            cv::Mat &image,
            const std::vector<cv::Point> &points,
            int thickness = 4)
        {
            cv::polylines(
                image,
                points,
                false,
                copperColor,
                thickness,
                cv::LINE_AA);
        }

        void drawPad(cv::Mat &image, cv::Point center, int radius = 6)
        {
            cv::circle(
                image, center, radius + 2,
                copperColor, -1, cv::LINE_AA);

            cv::circle(
                image, center, radius,
                padColor, -1, cv::LINE_AA);

            cv::circle(
                image, center, 2,
                copperColor, -1, cv::LINE_AA);
        }

        void drawMountingHole(cv::Mat &image, cv::Point center)
        {
            cv::circle(image, center, 17, copperColor, -1, cv::LINE_AA);
            cv::circle(image, center, 12, boardColor, -1, cv::LINE_AA);
            cv::circle(image, center, 6, backgroundColor, -1, cv::LINE_AA);
        }

        // Two-terminal horizontal resistor.
        // Pad centres: center.x +/- 25.
        void drawResistor(cv::Mat &image, cv::Point center)
        {
            cv::line(
                image,
                {center.x - 25, center.y},
                {center.x - 16, center.y},
                copperColor, 3, cv::LINE_AA);

            cv::line(
                image,
                {center.x + 16, center.y},
                {center.x + 25, center.y},
                copperColor, 3, cv::LINE_AA);

            cv::rectangle(
                image,
                {center.x - 16, center.y - 8},
                {center.x + 16, center.y + 8},
                componentColor, -1);

            cv::rectangle(
                image,
                {center.x - 16, center.y - 8},
                {center.x + 16, center.y + 8},
                silkscreenColor, 1);

            cv::line(
                image,
                {center.x - 5, center.y - 5},
                {center.x - 5, center.y + 5},
                silkscreenColor, 1);
        }

        // Two-terminal horizontal capacitor.
        // Pad centres: center.x +/- 20.
        void drawCapacitor(cv::Mat &image, cv::Point center)
        {
            cv::line(
                image,
                {center.x - 20, center.y},
                {center.x - 9, center.y},
                copperColor, 3, cv::LINE_AA);

            cv::line(
                image,
                {center.x + 9, center.y},
                {center.x + 20, center.y},
                copperColor, 3, cv::LINE_AA);

            cv::rectangle(
                image,
                {center.x - 9, center.y - 11},
                {center.x + 9, center.y + 11},
                componentColor, -1);

            cv::rectangle(
                image,
                {center.x - 9, center.y - 11},
                {center.x + 9, center.y + 11},
                silkscreenColor, 1);
        }

        // Simplified IC. Body: x=362..438, y=175..225.
        // Pin tips extend to x=354 on the left and x=446 on the right.
        void drawIntegratedCircuit(cv::Mat &image, cv::Point center)
        {
            const cv::Rect body{
                center.x - 38,
                center.y - 25,
                76,
                50};

            for (int i = -2; i <= 2; ++i)
            {
                const int y = center.y + i * 10;

                cv::line(
                    image,
                    {body.x - 8, y},
                    {body.x, y},
                    copperColor, 3, cv::LINE_AA);

                cv::line(
                    image,
                    {body.x + body.width, y},
                    {body.x + body.width + 8, y},
                    copperColor, 3, cv::LINE_AA);
            }

            cv::rectangle(image, body, componentColor, -1);
            cv::rectangle(image, body, silkscreenColor, 1);

            cv::circle(
                image,
                {body.x + 9, body.y + 9},
                3, silkscreenColor, -1, cv::LINE_AA);

            cv::putText(
                image,
                "U1",
                {center.x - 12, center.y + 5},
                cv::FONT_HERSHEY_SIMPLEX,
                0.5,
                silkscreenColor,
                1,
                cv::LINE_AA);
        }

        void drawConnector(cv::Mat &image)
        {
            // The connector body is to the left of its two pads.
            cv::rectangle(
                image,
                {76, 130, 24, 40},
                componentColor, -1);

            cv::rectangle(
                image,
                {76, 130, 24, 40},
                silkscreenColor, 1);

            cv::putText(
                image, "J1", {78, 125},
                cv::FONT_HERSHEY_SIMPLEX, 0.45,
                silkscreenColor, 1, cv::LINE_AA);

            cv::putText(
                image, "+", {80, 145},
                cv::FONT_HERSHEY_SIMPLEX, 0.4,
                silkscreenColor, 1, cv::LINE_AA);

            cv::putText(
                image, "-", {80, 160},
                cv::FONT_HERSHEY_SIMPLEX, 0.4,
                silkscreenColor, 1, cv::LINE_AA);
        }

        void drawReferenceBoard(cv::Mat &image)
        {
            image = cv::Mat(
                boardHeight,
                boardWidth,
                CV_8UC3,
                backgroundColor);

            const cv::Rect board{40, 35, 560, 410};

            cv::rectangle(image, board, boardColor, -1);
            cv::rectangle(image, board, silkscreenColor, 2);

            // Mounting holes.
            drawMountingHole(image, {65, 60});
            drawMountingHole(image, {575, 60});
            drawMountingHole(image, {65, 420});
            drawMountingHole(image, {575, 420});

            // ---------------------------------------------------------
            // VCC net
            // J1 pin 1 -> R1 pin 1, C1 pin 1 and U1 VCC pin.
            // The upper track is the VCC trunk.
            // ---------------------------------------------------------

            drawTrace(image, {
                {100, 140},
                {120, 140},
                {120, 90},
                {470, 90},
                {470, 330},
                {480, 330}
            });

            // VCC to R1.
            drawTrace(image, {
                {120, 140},
                {205, 140}
            });

            // VCC to C1.
            drawTrace(image, {
                {120, 140},
                {120, 330},
                {130, 330}
            });

            // VCC to U1.
            drawTrace(image, {
                {350, 90},
                {350, 180},
                {354, 180}
            });

            // ---------------------------------------------------------
            // Divider midpoint
            // R1 pin 2 -> R2 pin 1.
            // U1 signal input is connected to the midpoint.
            // ---------------------------------------------------------

            drawTrace(image, {
                {255, 140},
                {300, 140},
                {300, 200},
                {354, 200}
            });

            drawTrace(image, {
                {300, 200},
                {300, 220},
                {205, 220}
            });

            // ---------------------------------------------------------
            // GND net
            // J1 pin 2 -> R2 pin 2, C1 pin 2,
            // U1 GND pin and C2 GND pad.
            //
            // Route GND around the left edge to avoid crossing VCC.
            // ---------------------------------------------------------

            drawTrace(image, {
                {100, 160},
                {105, 160},
                {105, 390},
                {340, 390},
                {340, 242},
                {354, 220}
            });

            // GND branch to R2.
            drawTrace(image, {
                {180, 390},
                {180, 250},
                {280, 250},
                {280, 220},
                {255, 220}
            });

            // GND branch to C1.
            drawTrace(image, {
                {180, 330},
                {170, 330}
            });

            // GND branch to C2.
            drawTrace(image, {
                {340, 390},
                {530, 390},
                {530, 330},
                {520, 330}
            });

            // Draw components over the ends of their traces.
            drawConnector(image);
            drawResistor(image, {230, 140}); // R1
            drawResistor(image, {230, 220}); // R2
            drawIntegratedCircuit(image, {400, 200}); // U1
            drawCapacitor(image, {150, 330}); // C1
            drawCapacitor(image, {500, 330}); // C2

            // Draw pads last, centred on their corresponding trace ends.
            drawPad(image, {100, 140}, 7); // J1 VCC
            drawPad(image, {100, 160}, 7); // J1 GND

            drawPad(image, {205, 140}); // R1 pin 1
            drawPad(image, {255, 140}); // R1 pin 2
            drawPad(image, {205, 220}); // R2 pin 1
            drawPad(image, {255, 220}); // R2 pin 2

            drawPad(image, {354, 180}); // U1 VCC
            drawPad(image, {354, 200}); // U1 signal input
            drawPad(image, {354, 220}); // U1 GND

            drawPad(image, {130, 330}); // C1 VCC
            drawPad(image, {170, 330}); // C1 GND
            drawPad(image, {480, 330}); // C2 VCC
            drawPad(image, {520, 330}); // C2 GND

            // Component reference designators.
            cv::putText(
                image, "BOARDCHECK", {145, 75},
                cv::FONT_HERSHEY_SIMPLEX, 0.7,
                silkscreenColor, 2, cv::LINE_AA);

            cv::putText(
                image, "R1", {215, 125},
                cv::FONT_HERSHEY_SIMPLEX, 0.4,
                silkscreenColor, 1, cv::LINE_AA);

            cv::putText(
                image, "R2", {215, 205},
                cv::FONT_HERSHEY_SIMPLEX, 0.4,
                silkscreenColor, 1, cv::LINE_AA);

            cv::putText(
                image, "C1", {140, 305},
                cv::FONT_HERSHEY_SIMPLEX, 0.4,
                silkscreenColor, 1, cv::LINE_AA);

            cv::putText(
                image, "C2", {490, 305},
                cv::FONT_HERSHEY_SIMPLEX, 0.4,
                silkscreenColor, 1, cv::LINE_AA);
        }
    }

    TestImages generateTestImages()
    {
        TestImages images;

        // Create the valid reference board first.
        drawReferenceBoard(images.reference);

        // Start with an exact copy so every change is intentional.
        images.test = images.reference.clone();

        // Defect 1: remove R1's body while keeping both copper pads.
        cv::rectangle(
            images.test,
            {214, 132},
            {246, 148},
            boardColor,
            -1);

        drawPad(images.test, {205, 140});
        drawPad(images.test, {255, 140});

        // Defect 2: break the divider trace between R1 and its midpoint.
        cv::line(
            images.test,
            {300, 155},
            {300, 169},
            boardColor,
            9,
            cv::LINE_AA);

        // Defect 3: displace C2 upward and to the right.
        // The original copper pads remain where the board expects them.
        cv::rectangle(
            images.test,
            {491, 319},
            {509, 341},
            boardColor,
            -1);

        drawCapacitor(images.test, {512, 310});
        drawPad(images.test, {492, 310});
        drawPad(images.test, {532, 310});

        // Keep the higher-resolution image for dimension validation.
        cv::resize(
            images.reference,
            images.testHigherResolution,
            {800, 600},
            0,
            0,
            cv::INTER_LINEAR);

        return images;
    }

    bool saveTestImages(
        const TestImages &images,
        const std::filesystem::path &directory,
        bool overwrite)
    {
        const auto referencePath = directory / "reference.png";
        const auto testPath = directory / "test.png";
        const auto higherResolutionPath =
            directory / "test_higher_resolution.png";

        if (!overwrite &&
            (std::filesystem::exists(referencePath) ||
             std::filesystem::exists(testPath) ||
             std::filesystem::exists(higherResolutionPath)))
        {
            return false;
        }

        std::filesystem::create_directories(directory);

        return cv::imwrite(referencePath.string(), images.reference) &&
               cv::imwrite(testPath.string(), images.test) &&
               cv::imwrite(
                   higherResolutionPath.string(),
                   images.testHigherResolution);
    }
}
