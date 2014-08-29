#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	//check if all input parameters are present
	if(argc != 4)
	{
		cout<<"Blad: Za malo danych wejsciowych!\n";
		return -1;
	}


	//variable definition
	Mat inputImage, outputImage;
	stringstream s;
	int divideWith;


	//reading divider
	s << argv[3];
	s >> divideWith;


	//loading input image
	inputImage = imread(argv[1], CV_LOAD_IMAGE_COLOR);
	if(!inputImage.data)
	{
		cout<<"Blad: Nie udalo sie odczytac obrazu!\n";
	}


	//creating lookUpTable
	unsigned char table[256];
	Mat lookUpTable(1, 256, CV_8U);
	unsigned char *p = lookUpTable.data;

	for(int i = 0; i < 256; i ++)
	{
		table[i] = (unsigned char)(divideWith * (table[i] / divideWith));
	}
	for(int i = 0; i < 256; ++ i)
	{
		p[i] = table[i];
	}


	//image transformation
	LUT(inputImage, lookUpTable, outputImage);


	//window definitions
	namedWindow("Obraz wejsciowy", CV_WINDOW_AUTOSIZE);
	namedWindow("Obraz wyjsciowy", CV_WINDOW_AUTOSIZE);


	//displaying images
	imshow("Obraz wejsciowy", inputImage);
	imshow("Obraz wyjsciowy", outputImage);


	//saving transformed image
	imwrite(argv[2], outputImage);


	//waitning for user reaction
	waitKey(0);

	return 0;
}