/*
*	Instituto Tecnológico de Costa Rica
*	Authors:
*		Willberth Varela 
*		Jonatan Chaverri
*	Task 4
*	Procesamiento y análisis de imágenes digitales
*	Semester I, 2018
*/
#include <opencv2/opencv.hpp>
#include <string>
#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>


int loadImage (cv::Mat& image, int num){
	std::string folder ("Images/");
	std::string name = std::to_string(num);
	std::string end(".jpg");
	image = cv::imread(folder+name+end, 1);
	if(!image.data){
		std::cout <<  "Could not open or find the image" << std::endl ;
		return -1;
	}
	cv::Mat imageGray;
	cv::cvtColor(image, imageGray, cv::COLOR_RGB2GRAY);
	image = imageGray;
	return 0;
}


void showImage(cv::Mat& image){
	 cv::namedWindow("Imagen" , cv::WINDOW_AUTOSIZE);
  	 cv::imshow("Image", image);
	//wait for 5 seconds
  	cv::waitKey(5000);
}

int main(){
	int numberOfTestEntries = 100;
	cv::Mat imageSrc;
	if (loadImage(imageSrc, 5)==-1)
		return 0;
	showImage(imageSrc);
	return 0;
}	
