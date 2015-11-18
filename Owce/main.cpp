#include "mainwindow.h"
#include <QApplication>
using namespace std;
int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    cv::Mat inputImage = cv::imread("/home/murnko/Documents/projekt_UP/usg_cut1.jpg");
    if (inputImage.empty()) return -1;

    cv::Mat grayscale;
    cv::cvtColor(inputImage,grayscale,CV_BGR2GRAY);
    //cv::imshow("gray", grayscale);

    cv::Mat binary;
    cv::Mat smallImage;
    cv::Canny(grayscale,binary,0,50,5);
    cv::Size size(9,9);
    cv::GaussianBlur(grayscale,grayscale,size,2);

    cv::adaptiveThreshold(grayscale,binary,255,CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY,151,0);
    cv::imshow("bin", binary);
    cvWaitKey(0);
    vector<vector<cv::Point> >contours;
    cv::findContours(binary.clone(),contours,CV_RETR_EXTERNAL,CV_CHAIN_APPROX_NONE);
    std::vector<cv::Point> approx;
    int max_contour = 0;
    for (vector<cv::Point> contour : contours)
    {
        cv::approxPolyDP(
            cv::Mat(contour),
            approx,
            cv::arcLength(cv::Mat(contour), true) * 0.02,
            true
        );

        if (std::fabs(cv::contourArea(contour)) < 10000 )
            continue;
          cout << cv::contourArea(contour) <<endl;
          cv::Rect r = cv::boundingRect(contour);
          float position = sqrt(pow(r.x + (r.width/2),2) * pow(r.y+ (r.height/2),2));
          smallImage = cv::Mat(inputImage, r).clone();
          cv::imshow("najwieksze", smallImage);
          cvWaitKey(0);
    }
    //return a.exec();
    return 42;
}
