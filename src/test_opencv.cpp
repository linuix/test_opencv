#include <stdlib.h>
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char **argv)
{
    printf("test opencv start!!!\n");
    if (argc != 2)
    {
        printf("usage: DisplayImage.out <Image_Path>\n");
        return -1;
    }
    Mat image = imread(argv[1]);

    namedWindow("Image Loader");
    imshow("Image Loader",image);
    waitKey();
        
    return 0;
}