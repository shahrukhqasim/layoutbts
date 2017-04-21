#include <iostream>
#include "opencv2/core/core_c.h"
#include "opencv2/ml.hpp"
#include "opencv2/highgui/highgui_c.h"
#include "helper.h"

using namespace std;
using namespace cv;

int main( int argc, char** argv ) {

    helper test;
    Mat imgRgb=imread(argv[1]);
    Mat imgBin;
    Mat imgGray;
    cvtColor(imgRgb,imgGray,CV_BGR2GRAY);
    test.binarizeShafait(imgGray,imgBin,50,0.3);

    vector<int> temp;
    test.verticalProjectionProfiles(imgBin,temp);

    for(int i=0; i<temp.size(); i++){
        cout<<temp[i]<<" ";
    }

    test.plot();
}