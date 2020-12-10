//
// Created by linuix on 2020/12/6.
//
#include <stdlib.h>
#include "log_util.h"
#include <string.h>
#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/cvconfig.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/types_c.h>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/videoio/videoio_c.h>
#include <opencv2/core/core_c.h>
#include <vector>

using namespace cv;

using namespace std;

#define __cplusplus 201704L;

int main(int argc, char const *argv[])
{
    LOGD("%s start -----------", argv[0]);
    Mat mat = imread("../img_file/camera3.png");
//    namedWindow("img");
    cvtColor(mat,mat,COLOR_BGR2GRAY);

    blur(mat,mat,Size(3,3));
    //处理边缘显示
    Canny(mat,mat,0,25,3);
    imshow("img",mat);
    waitKey(-1);

    return 1;
}
