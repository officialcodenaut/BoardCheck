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

int main()
{
    std::printf("BoardCheck v0.1.0\n");
    std::printf("OpenCV version: %s\n", CV_VERSION);
    return 0;
}