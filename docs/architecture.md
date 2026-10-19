
# BoardCheck Architecture

## 1. Purpose

BoardCheck aims to detect and localize visual differences between
a reference PCB image and a test image.

The architecture will evolve alongside experiments and evaluation.
Components should be introduced when they provide a clear
responsibility or improve testability.

## 2. Initial Pipeline

The intended high-level pipeline is:

1. Load the reference image.
2. Load the test image.
3. Validate the input images.
4. Align the images when necessary.
5. Compare the images.
6. Localize candidate differences.
7. Save inspection results.

This is a conceptual pipeline. Its implementation order and
individual algorithms have not yet been finalized.

## 3. Image Registration

The reference and test images may differ in position, rotation,
scale, or perspective.

Image registration will be investigated to reduce false detections
caused by geometric misalignment.

Registration methods will be evaluated using suitable test images.
The project will not assume that every image pair can be aligned
reliably.

## 4. Difference Analysis

The comparison stage will investigate methods for identifying
candidate visual differences between aligned images.

Possible approaches include pixel-wise comparison, thresholding,
morphological operations, and feature-based methods where appropriate.

The selected method must be evaluated against labeled examples
rather than judged only by visual appearance.

## 5. Output

The intended output may include:

- An image highlighting candidate differences.
- A summary of detected regions.
- Quantitative evaluation results.
- A machine-readable report in a later development stage.

The exact output format and command-line interface remain open
design decisions.

## 6. Testing and Evaluation

Testing will cover both individual processing components and
the complete inspection pipeline.

Evaluation should consider:

- False positives.
- False negatives.
- Localization quality.
- Sensitivity to image misalignment.
- Runtime and reproducibility.

Test images and reference annotations must have clear provenance
and usage permissions.

## 7. Constraints

BoardCheck performs visual analysis only.

A detected image difference is not proof of an electrical defect.
Likewise, a visually similar image does not establish electrical
correctness.

The system's limitations must be documented alongside its results.

## 8. Current Implementation

The project currently contains a minimal C++17 executable,
CMake configuration, and OpenCV integration.

The image processing pipeline, command-line interface,
and automated tests have not yet been implemented.
