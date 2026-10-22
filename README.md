# BoardCheck

**PCB Visual Inspection | C++17 · OpenCV · CMake**

BoardCheck is an experimental computer vision project focused on detecting and localizing visual differences between a reference printed circuit board (PCB) image and a test image.

The goal is to build a practical image inspection pipeline while exploring image registration, image processing, feature matching, and quantitative evaluation in modern C++.

> **Project status:** Early development. The application currently loads two images and validates their dimensions. The image comparison and defect localization pipeline has not been implemented yet.

## Goals

- Compare a reference PCB image with a test image.
- Investigate image alignment and registration.
- Detect and localize visual differences.
- Evaluate detection quality using labeled test data.
- Produce clear, reproducible inspection results.
- Maintain a modular codebase with automated tests.

## Scope

BoardCheck focuses on **visual inspection**, not electrical verification.

A visual difference does not necessarily indicate an electrical defect, and the absence of detected visual differences does not guarantee that a PCB is electrically correct.

The project is experimental and is not intended to replace professional PCB inspection or electrical testing systems.

## Technology Stack

- C++17
- OpenCV
- CMake
- CLI11
- Git and GitHub

## Current Features

- Command-line argument parsing using CLI11.
- Loading reference and test images using OpenCV.
- Validation of image loading failures.
- Image dimension validation.
- A standalone utility for generating synthetic test images.

**Current limitation:** BoardCheck does not compare image content or detect PCB defects yet. Matching image dimensions only establishes that the inputs have compatible sizes.

## Building

The project is developed with CMake and a C++17-compatible compiler.

OpenCV must be installed and discoverable by CMake. CLI11 is configured as a CMake dependency.

Configure the project:

```powershell
cmake -S . -B build
```

Build all targets:

```powershell
cmake --build build
```

For a clean rebuild:

```powershell
cmake --build build --clean-first
```

## Usage

Run BoardCheck with paths to a reference image and a test image:

```powershell
.\build\BoardCheck.exe --reference data\reference.png --test data\test.png
```

Both arguments are required.

The application attempts to load both images and prints their dimensions. If either image cannot be loaded, or their dimensions differ, the application reports an error and exits with a non-zero status.

### Exit Codes

| Code | Meaning |
|---:|---|
| `0` | Both images loaded successfully and have matching dimensions. |
| `3` | Failed to load the reference or test image. |
| `4` | The images have different dimensions. |

CLI argument parsing errors are handled by CLI11.

## Test Image Generation

BoardCheck includes a standalone utility for generating synthetic images used during development.

Build the project first, then run:

```powershell
.\build\GenerateTestImages.exe
```

The utility generates three images in the `data/` directory:

- `reference.png` — reference image.
- `test.png` — test image with the same dimensions as the reference.
- `test_higher_resolution.png` — test image with different dimensions.

The generated images contain simple geometric shapes and are intended for testing input handling and validation. They are **synthetic development fixtures, not real PCB images or a labeled defect dataset**.

The utility expects the `data/` directory to exist.

## Planned Development

The following stages describe the intended direction, not necessarily implemented features.

- [x] Initial project structure
- [x] CMake configuration and OpenCV integration
- [x] Command-line argument parsing
- [x] Image loading and dimension validation
- [x] Synthetic test image generation
- [ ] Establish image comparison and output conventions
- [ ] Implement basic image comparison
- [ ] Explore and evaluate image registration
- [ ] Localize differences in the output image
- [ ] Add automated tests
- [ ] Evaluate the pipeline on labeled PCB images
- [ ] Introduce structured inspection reports

The implementation order may change as experiments reveal technical limitations or better approaches.

## Repository Structure

```text
BoardCheck/
├── docs/                       # Project documentation
├── include/boardcheck/         # Public project headers
├── src/                        # Application source code
├── tests/                      # Automated tests
├── tools/
│   └── generate_test_images.cpp
├── data/                       # Local datasets and generated test images
├── .clang-format
├── .gitignore
├── CMakeLists.txt
├── LICENSE
└── README.md
```

## Development

The project uses a branch-based Git workflow:

- `main` contains stable, reviewed changes.
- `dev` integrates completed features.
- `feature/*` branches isolate individual tasks.

Changes are intended to be reviewed through pull requests, with issues used to track planned work and defects.

## License

BoardCheck is licensed under the GNU General Public License v3.0. See [LICENSE](LICENSE) for details.
