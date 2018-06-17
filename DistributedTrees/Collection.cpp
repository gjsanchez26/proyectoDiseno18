#include "Collection.h"

rdf::Collection::Collection() {
}

rdf::Collection::Collection(const Collection& orig) {
}

rdf::Collection::~Collection() {
}


/**
 * This method works to change image, by load in the structure
 * @param TypeImage
 */
void rdf::Collection::setImage(StrategyImage* TypeImage){
    rdf::Collection::stImage = TypeImage;
}

/**
 * This method works to read image of the database
 * @param height
 * @param width
 * @param direction
 * @param image
 */
void rdf::Collection::readImage(int height, int width, std::string direction, cv::Mat& image){
    cv::Mat imageTem;
    rdf::Collection::stImage->readImage(height,width,direction,imageTem);
    image = imageTem;
    
}
