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

#include <cstdio>
#include <opencv2/core.hpp>
#include <CLI/CLI.hpp>
#include <string>

int main(int argc, char* argv[])
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
    catch(const CLI::ParseError& e) 
    {
        return cli.exit(e);
    }
    
    std::printf("BoardCheck v0.1.0\n");
    std::printf("OpenCV version: %s\n", CV_VERSION);
    return 0;
}