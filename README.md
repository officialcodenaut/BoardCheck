# BoardCheck

**PCB Visual Inspection | C++17 · OpenCV · CMake**

BoardCheck is an open-source computer vision project focused on detecting and localizing visual differences between a reference printed circuit board (PCB) image and a test image.

The goal is to develop a practical image inspection pipeline while exploring image registration, image processing, feature matching, and quantitative evaluation in modern C++.

> **Project status:** Early development — currently on hold while work continues on other projects. BoardCheck is not abandoned and development is expected to resume.
>
> The `main` branch contains the stable project baseline. More recent development work is available on [`dev`](../../tree/dev) and dedicated feature branches.

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
- CLI11 (development branches)
- Git and GitHub

## Current Development Progress

The project has progressed beyond its initial setup. Work completed across development branches includes:

- [x] Initial project structure and CMake configuration
- [x] OpenCV integration
- [x] Command-line interface using CLI11
- [x] Image loading and input validation
- [x] Synthetic PCB test image generator
- [x] Basic pixel-wise image comparison module
- [x] Initial automated tests for image comparison

The comparison module and its tests are currently implemented on `feature/image-comparison` and are not yet integrated into the `main` branch.

The full inspection pipeline is not yet operational.

## Building

The project uses CMake and requires a C++17-compatible compiler.

Configure:

```powershell
cmake -S . -B build
```

Build:

```powershell
cmake --build build
```

Clean rebuild:

```powershell
cmake --build build --clean-first
```

OpenCV must be installed and discoverable by CMake.

**Note:** The available executable targets and command-line options depend on the branch being built. Refer to the README on the corresponding development branch for its usage instructions.

## Planned Development

The following stages describe the intended direction of the project:

- [ ] Integrate image comparison into the application workflow
- [ ] Generate binary difference masks
- [ ] Explore and evaluate image registration
- [ ] Localize and visualize detected differences
- [ ] Evaluate detection quality using labeled PCB images
- [ ] Introduce structured inspection reports
- [ ] Expand automated tests and regression coverage

The implementation order may change as experiments reveal technical limitations or better approaches.

## Repository Structure

The baseline project structure is:

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

Additional tools and modules are being developed on other branches.

## Development Workflow

BoardCheck uses a branch-based Git workflow:

- `main` — stable, reviewed project baseline.
- `dev` — integration branch for completed development work.
- `feature/*` — isolated development of individual features.

For the latest integrated development progress, see the [`dev` branch](../../tree/dev).

Changes are intended to be reviewed through pull requests, with issues used to track planned work and defects.

## License

BoardCheck is licensed under the **GNU General Public License v3.0**. See [LICENSE](LICENSE) for details.