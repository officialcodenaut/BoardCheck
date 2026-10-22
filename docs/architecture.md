# BoardCheck Architecture

## 1. Purpose

BoardCheck aims to detect and localize visual differences between a reference PCB image and a test image.

The architecture will evolve alongside experiments and evaluation. Components should be introduced when they provide a clear responsibility, improve testability, or help isolate algorithmic decisions.

The implementation should remain practical and avoid unnecessary abstraction during early development.

## 2. Current Input Pipeline

The current application performs the following steps:

1. Parse command-line arguments.
2. Load the reference image.
3. Load the test image.
4. Validate that both images were loaded successfully.
5. Validate that both images have matching dimensions.
6. Exit with an appropriate status code.

The application currently uses CLI11 for argument parsing and OpenCV for image loading and basic image operations.

The current pipeline does not compare image content, perform image registration, or detect defects.

## 3. Intended Inspection Pipeline

The intended high-level pipeline is:

1. Load and validate the input images.
2. Align the images when necessary.
3. Compare the images.
4. Localize candidate differences.
5. Evaluate the results.
6. Save inspection results.

This is a conceptual pipeline. Its implementation order, individual algorithms, and output formats have not yet been finalized.

## 4. Image Registration

The reference and test images may differ in position, rotation, scale, or perspective.

Image registration will be investigated to reduce false detections caused by geometric misalignment.

Registration methods will be evaluated using suitable test images. The project will not assume that every image pair can be aligned reliably.

The implementation should distinguish registration failures from actual candidate differences wherever practical.

## 5. Difference Analysis

The comparison stage will investigate methods for identifying candidate visual differences between aligned images.

Possible approaches include pixel-wise comparison, thresholding, morphological operations, and feature-based methods where appropriate.

The selected method must be evaluated against labeled examples rather than judged only by visual appearance.

Algorithm selection should be guided by measured results and the limitations of the available dataset.

## 6. Output

The intended output may include:

- An image highlighting candidate differences.
- A summary of detected regions.
- Quantitative evaluation results.
- A machine-readable inspection report in a later development stage.

The exact output format and command-line interface remain open design decisions.

## 7. Testing and Evaluation

Testing will cover individual processing components and, as the pipeline develops, the complete inspection workflow.

Evaluation should consider:

- False positives.
- False negatives.
- Localization quality.
- Sensitivity to image misalignment.
- Runtime and reproducibility.

Synthetic images can support early development and validation of basic behavior. They are not a substitute for representative PCB images and labeled evaluation data.

Test images and reference annotations must have clear provenance and appropriate usage permissions.

## 8. Constraints

BoardCheck performs visual analysis only.

A detected image difference is not proof of an electrical defect. Likewise, a visually similar image does not establish electrical correctness.

The system's limitations must be documented alongside its results. Inspection output should be treated as evidence for further review, not as a guarantee of electrical or manufacturing quality.

## 9. Current Implementation

The project currently includes:

- A C++17 application built with CMake.
- CLI11-based parsing of the required `--reference` and `--test` arguments.
- OpenCV-based image loading.
- Validation of image loading failures.
- Validation that the input images have matching dimensions.
- A standalone utility for generating synthetic test images.

The application reports input dimensions and returns non-zero exit codes for image loading failures and dimension mismatches.

Image registration, image comparison, difference localization, inspection reports, and automated tests have not yet been implemented.
