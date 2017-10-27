#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    cout << "Built with OpenCV " << CV_VERSION << endl;
    Mat image;
    VideoCapture capture;
    capture.open(0);
    int i = 0;
    int m = 1;
    if(capture.isOpened())
    {
        cout << "Capture is opened" << endl;
        for(;;)
        {
            capture >> image;
            if(image.empty())
                break;
            imshow("Sample", image);
            char key = waitKey(100);
            string filename = format("pic%d.jpg", i);
            switch(key)
            {
            case'p':
                i++;
                imwrite(filename, image);
                imshow("photo", image);
                waitKey(500);
                destroyWindow("photo");
                break;
            default:
                break;
            }
        }
    }
    else
    {
        cout << "No capture" << endl;
        image = Mat::zeros(480, 640, CV_8UC1);
        imshow("Sample", image);
        waitKey(0);
    }
    return 0;
}
