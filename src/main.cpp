/*
 * BoardCheck - PCB visual inspection using computer vision.
 * Copyright (C) 2026 Codenaut
 *
 * This file is part of BoardCheck.
 *
 * BoardCheck is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * BoardCheck is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BoardCheck. If not, see <https://www.gnu.org/licenses/>.
 */

#include "boardcheck/test_images.hpp"
 
#include <CLI/CLI.hpp>
#include <cstdio>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <string>
#include <filesystem>

int main(int argc, char *argv[])
{
    CLI::App cli{"PCB visual inspection using computer vision"};
    cli.get_formatter()->column_width(60);
    argv = cli.ensure_utf8(argv);

    std::string referencePath;
    std::string testPath;

    auto *demoCommand = cli.add_subcommand("demo", "Generate synthetic PCB demo images");

    auto *referenceOption = cli.add_option("--reference, --ref", referencePath, "Path to reference image");

    auto *testOption = cli.add_option("--test", testPath, "Path to test image");

    try
    {
        cli.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return cli.exit(e);
    }

    if (demoCommand->parsed())
    {
        if (!referenceOption->empty() || !testOption->empty())
        {
            std::fprintf(stderr, "Error: --reference and --test cannot be used with demo.\n");
            return 2;
        }

        const std::filesystem::path demoDirectory = "build/demo-data";

        const auto referencePath = demoDirectory / "reference.png";
        const auto testPath = demoDirectory / "test.png";
        const auto higherResolutionPath = demoDirectory / "test_higher_resolution.png";

        const bool filesExist = 
            std::filesystem::exists(referencePath) ||
            std::filesystem::exists(testPath) ||
            std::filesystem::exists(higherResolutionPath);

        bool overwrite = false;

        if(filesExist)
        {
            char answer[32];

            while(true)
            {
                std::printf(
                    "Demo images already exist in \"%s\".\n"
                    "Overwrite existing files? [y/N]: ",
                    demoDirectory.string().c_str());

                if(std::fgets(answer, sizeof(answer), stdin) == nullptr)
                {
                    std::printf("\nDemo cancelled.\n");
                    return 0;
                }

                if(answer[0] == 'y' || answer[0] == 'Y')
                {
                    overwrite = true;
                    break;
                }

                if(answer[0] == '\n' ||
                   answer[0] == 'n' ||
                   answer[0] == 'N')
                {
                    std:;printf("Demo cancelled\n");
                    return 0;
                }

                std::printf("Please answer y or n.\n");
            }
        }

        try
        {
            const boardcheck::TestImages images = 
                boardcheck::generateTestImages();

            if (!boardcheck::saveTestImages(images, demoDirectory, overwrite))
            {
                std::fprintf(stderr, "Error: failed to save demo images.\n");
                return 5;
            }
        }
        catch(const std::filesystem::filesystem_error &e)
        {
            std::fprintf(stderr, "Error: filesystem operation failed: %s\n", e.what());
            return 5;
        }
        catch(const cv::Exception &e)
        {
            std::fprintf(stderr, "Error: OpenCV operation failed: %s\n", e.what());
            return 5;
        }

        std::printf("Demo images saved to \"%s\".\n",
            demoDirectory.string().c_str());
        
        return 0;
    }

    if (referenceOption->empty() || testOption->empty())
    {
        std::fprintf(stderr, "Error: both --reference and --test are required.\n");
        return 2;
    }

    cv::Mat reference, test;

    reference = cv::imread(referencePath);
    if (reference.empty())
    {
        std::fprintf(stderr, "Error: failed to load reference image: %s\n", referencePath.c_str());
        return 3;
    }

    test = cv::imread(testPath);
    if (test.empty())
    {
        std::fprintf(stderr, "Error: failed to load test image: %s\n", testPath.c_str());
        return 3;
    }

    std::printf("Size of reference image: %d x %d\n", reference.cols, reference.rows);
    std::printf("Size of test image: %d x %d\n", test.cols, test.rows);

    if (reference.size() != test.size())
    {
        std::fprintf(stderr, "Error: Images are not equal in size\n");
        return 4;
    }

    return 0;
}
