//
// Created by Talha Rehman on 4/21/17.
//

#include "helper.h"

#include "matplotlib-cpp/matplotlibcpp.h"
namespace plt = matplotlibcpp;

void helper::plotRect(cv::Mat &image,vector<cv::Rect> boxes){

    for(int i=0; i<boxes.size(); i++){
        rectangle(image,boxes[i],Scalar(255,0,0),2, LINE_8);
    }
}

void helper::drawFilledRect(cv::Mat &image, vector<cv::Rect> boxes) {

    for(int i=0; i<boxes.size(); i++){
        rectangle(image,boxes[i],Scalar(0,0,0),2, CV_FILLED);
    }

}

void helper::verticalProjectionProfiles(cv::Mat imgBin, vector<int> &verticalProfiles) {

    Point pt;
    for (int i=0; i<imgBin.cols; i++){

        verticalProfiles.push_back(0);
        for(int j=0; j<imgBin.cols; j++){
            if(imgBin.at<uchar>(j, i)==0){
                verticalProfiles[i]++;
            }

        }
    }

}

void helper::binarizeShafait(Mat &gray, Mat &binary, int w, double k) {
    Mat sum, sumsq;
    gray.copyTo(binary);
    int half_width = w >> 1;
    integral(gray, sum, sumsq, CV_64F);
    for (int i = 0; i < gray.rows; i++) {
        for (int j = 0; j < gray.cols; j++) {
            int x_0 = (i > half_width) ? i - half_width : 0;
            int y_0 = (j > half_width) ? j - half_width : 0;
            int x_1 = (i + half_width >= gray.rows) ? gray.rows - 1 : i + half_width;
            int y_1 = (j + half_width >= gray.cols) ? gray.cols - 1 : j + half_width;
            double area = (x_1 - x_0) * (y_1 - y_0);
            double mean = (sum.at<double>(x_0, y_0) + sum.at<double>(x_1, y_1) - sum.at<double>(x_0, y_1) -
                           sum.at<double>(x_1, y_0)) / area;
            double sq_mean = (sumsq.at<double>(x_0, y_0) + sumsq.at<double>(x_1, y_1) - sumsq.at<double>(x_0, y_1) -
                              sumsq.at<double>(x_1, y_0)) / area;
            double stdev = sqrt(sq_mean - (mean * mean));
            double threshold = mean * (1 + k * ((stdev / 128) - 1));
            if (gray.at<uchar>(i, j) > threshold)
                binary.at<uchar>(i, j) = 255;
            else
                binary.at<uchar>(i, j) = 0;
        }
    }
}

void helper::drawHistogram(vector<int> input) {
    //TODO: complete this
}

void helper::plot() {
    plt::plot({1,2,3,4});
    plt::show();
}