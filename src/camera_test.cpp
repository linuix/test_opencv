#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "log_util.h"

#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char const *argv[])
{

    Mat img;
    int k;
    string img_name = "camera1.png";
    //开启默认摄像头创建相机类
    VideoCapture video_capture;
    video_capture.open(-1);
    if (!video_capture.isOpened())
    {
        LOGD("open camera faied !!!");
        return -1;
    }
    while (1)
    {
        video_capture >> img;
        GaussianBlur(img, img, Size(5, 5), 0);
        imshow("camera", img);
        k = waitKey(30);
        if (k == 's')
        {
            imwrite(img_name, img);
            img_name.at(6)++;
            img.release();
            LOGD("svae success !!!");
        }
        else if (k == 27)
        {
            break;
        }
    }

    return 0;
}
