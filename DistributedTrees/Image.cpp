#include "Image.h"
#include "ImageGetter.h"
#include "Collection.h"
#include "PointsSelect.h"

using namespace rdf;

rdf::Image::Image() {
}

rdf::Image::Image(const Image& orig) {
}

rdf::Image::~Image() {
}

/**
 * Funtion get to structure of diferents algorithms
 * @param structure
 * @param dataMaster
 */
void rdf::Image::getStructura(std::vector<Estructura::Node>& structure, Estructura::DataMaster dataMaster) {
    std::string PathDepthImage = "/home/RDF/code/DistributedTrees/Database/pathDepth.txt";
    std::string PathLabelImage = "/home/RDF/code/DistributedTrees/Database/pathDepth.txt";


    std::vector<Estructura::Node> structureTemp;
    
    //load structure of the shotton algorithm
    if (dataMaster.type_Algorithm.compare(0, 7, "shotton") == 0) {
        generatedStructureShotton(structureTemp, dataMaster.type_Algorithm, dataMaster.NumPoints, dataMaster.height, dataMaster.width,
                dataMaster.NumTree, PathDepthImage, PathLabelImage, dataMaster.startRead, dataMaster.endRead, dataMaster.tree, dataMaster.node);
    }
    structure = structureTemp;
}

/**
 * Funtion make the structure of shotton algorithm
 * @param structure
 * @param type_Algorithm
 * @param NumPoints
 * @param height
 * @param width
 * @param NumTree
 * @param pathDepth
 * @param pathlabel
 * @param startRead
 * @param endRead
 * @param tree
 * @param node
 */
void rdf::Image::generatedStructureShotton(std::vector<Estructura::Node>& structure,
        std::string type_Algorithm, int NumPoints, int height, int width,
        int NumTree, std::string pathDepth, std::string pathlabel,
        int startRead, int endRead, int tree, int node) {

    ImageGetter imageGetter;
    LabelImage lblImage;
    DepthImage depthImage;
    Collection collection;
    cv::Mat imageDepth, imageLabel;

    //lee las direciones del path
    std::vector<std::string> directionesDepth;
    std::vector<std::string> directionesLabel;
    int NumLines = 0;

    imageGetter.readPath(directionesDepth, NumLines, pathDepth, startRead, endRead);
    imageGetter.readPath(directionesLabel, NumLines, pathlabel, startRead, endRead);
    
    //carga las imagenes cona las direcciones
    for (unsigned int k = 0; k < directionesDepth.size(); k++) {

        Estructura::Node dataAll;
        std::vector<Estructura::Pixel> puntos;
        
        Estructura es;

        PointsSelect pointSelect;
        
        
        //leer la imagen de profundidad
        collection.setImage(&depthImage);
        collection.readImage(height, width, directionesDepth[k], imageDepth);

        //leer la image de etiquetas
        collection.setImage(&lblImage);
        collection.readImage(height, width, directionesLabel[k], imageLabel);

        //std::cout << imageLabel << "\n";
        //para visualizar las imagenes que se estan cargando
        //es.seeImageDepth(height,width,imageDepth);
        //es.seeImageLabel(imageLabel);

        

        pointSelect.generatedPoints(type_Algorithm, puntos, NumPoints, height, width, NumTree);

        //llena los campos y carga al vector

        dataAll.imageDepth = imageDepth;
        dataAll.imageLabel = imageLabel;
        dataAll.points = puntos;
        dataAll.node = node;
        dataAll.tree = tree;

        structure.push_back(dataAll);
    }


}

