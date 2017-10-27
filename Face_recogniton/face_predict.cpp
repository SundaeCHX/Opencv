#include "opencv2/core.hpp"
#include "opencv2/face.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;
using namespace cv::face;

int main()
{
    VideoCapture capture;
    capture.open(0);
    if(!capture.isOpened())
    {
        return -1;
    }

    Mat frame;
    Mat edges;
    Mat gray;

    CascadeClassifier cascade;
    bool stop = false;

    cascade.load("/opencv-3.3.0/data/haarcascades_cuda/haarcascade_frontalface_alt.xml");

    Ptr<EigenFaceRecognizer> modelPCA = Algorithm::load<EigenFaceRecognizer>("<Model Path>/MyFacePCAModel.xml");

    while(!stop)
    {
        capture >> frame;
        vector<Rect> faces(0);
        cvtColor(frame, gray, CV_BGR2GRAY);
        equalizeHist(gray, gray);

        cascade.detectMultiScale(gray, faces,
                                 1.1, 3, 0
                                 //|CV_HAAR_FIND_BIGGEST_OBJECT
                                 //|CV_HAAR_DO_ROUGH_SEARCH
                                 | CV_HAAR_SCALE_IMAGE,
                                 Size(30, 30));

        Mat face;
        Point text_lb;

        for(size_t i = 0; i < faces.size(); i++)
        {
            if(faces[i].height > 0 && faces[i].width > 0)
            {
                face = gray(faces[i]);
                text_lb = Point(faces[i].x, faces[i].y);

                rectangle(frame, faces[i], Scalar(255, 0, 0), 1, 8, 0);
            }
        }

        Mat face_test;

        int predictPCA = 0;
        if(face.rows >= 120)
        {
            resize(face, face_test, Size(92, 112));
        }
        if(!face_test.empty())
        {
            predictPCA = modelPCA->predict(face_test);
        }

        cout << predictPCA << endl;
        if (predictPCA == 40)
        {
            string name = "Your name";
            putText(frame, name, text_lb, FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255));
        }
        imshow("face", frame);
        if(waitKey(50) >= 0)
        {
            stop = true;
        }
    }
    return 0;
}
