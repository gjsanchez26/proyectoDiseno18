#include "DepthImage.h"


rdf::DepthImage::DepthImage() {
}

rdf::DepthImage::DepthImage(const DepthImage& orig) {
}

rdf::DepthImage::~DepthImage() {
}
/**
 * Funtion to read depth image
 * @param direction
 * @param imageLabel
 */
void rdf::DepthImage::readImage(int height, int width, std::string direction, cv::Mat& image) {
    cv::Mat imegeDepth;
    imegeDepth = cv::Mat(height, width, CV_16UC1, cv::Scalar(0));
    std::string rute = direction;
    imegeDepth = cv::imread(rute.c_str(),CV_16UC1);
    image = imegeDepth;
}
