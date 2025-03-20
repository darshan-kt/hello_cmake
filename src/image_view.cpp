#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    std::string imagePath = "sample.jpg"; // Change this to your image path
    cv::Mat image = cv::imread(imagePath); // Load image

    if (image.empty()) {
        std::cerr << "Error: Could not open image!" << std::endl;
        return -1;
    }

    cv::imshow("Image Viewer", image); // Show image
    cv::waitKey(0); // Wait for key press
    return 0;
}
