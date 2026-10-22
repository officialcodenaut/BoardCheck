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

#include <CLI/CLI.hpp>
#include <cstdio>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <string>

int main(int argc, char *argv[])
{
    CLI::App cli;
    cli.get_formatter()->column_width(45);
    argv = cli.ensure_utf8(argv);
    std::string referencePath;
    std::string testPath;

    cli.add_option("--reference", referencePath, "Path to reference image")->required();
    cli.add_option("--test", testPath, "Path to test image")->required();

    try
    {
        cli.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return cli.exit(e);
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
