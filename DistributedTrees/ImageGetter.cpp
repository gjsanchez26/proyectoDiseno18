#include "ImageGetter.h"


using namespace rdf;

rdf::ImageGetter::ImageGetter() {
}

rdf::ImageGetter::ImageGetter(const ImageGetter& orig) {
}

rdf::ImageGetter::~ImageGetter() {
}

/**
 * Funcion para leer el archivo que contiene la direccion de todas las imagenes en la base de datos 
 * @param directiones
 * @param cont
 */
void rdf::ImageGetter::readPath(std::vector<std::string>& directiones, int& cont, std::string path, int startRead, int endRead) {
    std::ifstream file;
    std::string line;
    int numeroLinea = 0;
    //int cont = 0;
    file.open(path.c_str(), std::ifstream::in);
    
    //Leer el archivo hasta que termine.
    while (!file.eof()) {
        
        if(numeroLinea >= startRead && numeroLinea<endRead){
            getline(file, line); //Lee la linea
            directiones.push_back(line); //agrega la linea al vector
        }else{
            getline(file, line); //Lee la linea
        }
        if(numeroLinea == endRead){
            break;
        }
        numeroLinea++;
    }
    
}
