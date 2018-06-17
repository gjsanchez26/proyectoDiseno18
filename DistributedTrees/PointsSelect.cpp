#include "PointsSelect.h"

using namespace rdf;

PointsSelect::PointsSelect() {
}

PointsSelect::PointsSelect(const PointsSelect& orig) {
}

PointsSelect::~PointsSelect() {
}

/**
 * This funtion generate to points to each algorithms 
 * @param type_Algorithm
 * @param points
 * @param NumPoints
 * @param height
 * @param width
 * @param NumTree
 */
void rdf::PointsSelect::generatedPoints(std::string type_Algorithm, std::vector<Estructura::Pixel>& points, int NumPoints, int height, int width, int NumTree){
    
    std::vector<Estructura::Pixel> temporal;
    if(type_Algorithm.compare(0,7,"shotton") == 0){
        generatShoton(temporal, NumPoints, height, width, NumTree);
        
    }
    points = temporal;
}

/**
 * This funtion generate to points to the algorithm of shotton
 * @param points
 * @param NumPoints
 * @param height
 * @param width
 * @param NumTree
 */
void rdf::PointsSelect::generatShoton(std::vector<Estructura::Pixel>& points, int NumPoints, int height, int width, int NumTree){
    
    
    std::vector<int> start (NumTree,0);
    Estructura::Pixel pixelTemp;
    
    for (int i = 0; i < NumPoints; i++) {
        pixelTemp.point = cv::Point((rand() % (height - 0)),((rand() % (width - 0))));
        pixelTemp.ubicacion = start;
        points.push_back(pixelTemp);
    }
}

