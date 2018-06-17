#include "LabelImage.h"
using namespace rdf;

rdf::LabelImage::LabelImage() {
}

rdf::LabelImage::LabelImage(const LabelImage& orig) {
}

rdf::LabelImage::~LabelImage() {
}

/**
 * Funcion para la lectura de la imagen de etiquetas.
 * @param direction
 * @param imageLabel
 */
void rdf::LabelImage::readImage(int height, int width, std::string direction, cv::Mat& image) {
    cv::Mat imageLbl(height, width, CV_8UC3);
    std::string rute = direction;
    imageLbl = cv::imread(rute.c_str());

    image = imageLbl;
    
}
