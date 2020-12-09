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
    IplImage *pFrame = NULL;
    cvNamedWindow("img", 1);
    VideoCapture video_cp;
    video_cp.open(-1);
    if (video_cp.isOpened())
    {
        LOGD("ok");
    }

    Mat cap;          //定义一个Mat变量，用于存储每一帧的图像
    video_cp >> cap;  //读取当前帧
    if (!cap.empty()) //判断当前帧是否捕捉成功 **这步很重要
    {
        imshow("img", cap); //若当前帧捕捉成功，显示

        vector<int> compression_params;

        compression_params.push_back(IMWRITE_PNG_COMPRESSION);
        compression_params.push_back(9);
        imwrite("img.png", cap, compression_params);
    }
    else
        LOGD("error");
    waitKey(5000); //延时10毫秒
    // CvCapture *pCapture = cvCaptureFromCAM(0);
    // cvSetCaptureProperty(pCapture, CV_CAP_PROP_FRAME_WIDTH, 320);
    // cvSetCaptureProperty(pCapture, CV_CAP_PROP_FRAME_HEIGHT, 240);

    // while (true)
    // {
    //     pFrame = cvQueryFrame(pCapture);
    //     if (!pFrame)
    //         break;

    //     char c = cvWaitKey(33);
    //     if (c == 32)
    //         break;
    //     cvShowImage("result", pFrame);
    // }

    return 1;
}
