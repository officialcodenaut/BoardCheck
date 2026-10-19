
# BoardCheck

**PCB Visual Inspection | C++17 · OpenCV · CMake**

BoardCheck is an experimental computer vision project focused on
detecting and localizing visual differences between a reference
printed circuit board (PCB) image and a test image.

The goal is to build a practical image inspection pipeline while
exploring image registration, image processing, feature matching,
and quantitative evaluation in modern C++.

> **Project status:** Initial setup. The build configuration is
> working; the inspection pipeline has not been implemented yet.

## Goals

- Compare a reference PCB image with a test image.
- Investigate image alignment and registration.
- Detect and localize visual differences.
- Evaluate detection quality using labeled test data.
- Produce clear, reproducible inspection results.
- Maintain a modular codebase with automated tests.

## Scope

BoardCheck focuses on **visual inspection**, not electrical
verification.

A visual difference does not necessarily indicate an electrical
defect, and the absence of detected visual differences does not
guarantee that a PCB is electrically correct.

The project is experimental and is not intended to replace
professional PCB inspection or electrical testing systems.

## Technology Stack

- C++17
- OpenCV
- CMake
- Git and GitHub

## Building

The project is developed with CMake and a C++17-compatible compiler.

Configure the project:

```powershell
cmake -S . -B build
```

Build:

```powershell
cmake --build build
```

For a clean rebuild:

```powershell
cmake --build build --clean-first
```

Run the current executable on Windows:

```powershell
.\build\BoardCheck.exe
```

OpenCV must be installed and discoverable by CMake.

## Planned Development

The following stages describe the intended direction, not
implemented features.

- [x] Initial project structure
- [x] CMake configuration and OpenCV integration
- [ ] Define image input and output conventions
- [ ] Implement basic image comparison
- [ ] Explore and evaluate image registration
- [ ] Localize differences in the output image
- [ ] Add automated tests
- [ ] Evaluate the pipeline on labeled PCB images
- [ ] Introduce structured reports and command-line options

The implementation order may change as experiments reveal
technical limitations or better approaches.

## Repository Structure

```text
BoardCheck/
├── docs/                 # Project documentation
├── include/boardcheck/   # Public project headers
├── src/                  # Application source code
├── tests/                # Automated tests
├── data/                 # Local datasets and test images
├── CMakeLists.txt
├── LICENSE
└── README.md
```

## Development

The project uses a branch-based Git workflow:

- `main` contains stable, reviewed changes.
- `dev` integrates completed features.
- `feature/*` branches isolate individual tasks.

Changes are intended to be reviewed through pull requests,
with issues used to track planned work and defects.

## License

The project license will be selected before the first public release.
