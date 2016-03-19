#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;


int main(int argc, char** argv )
{
 Mat frame;

 Mat MaskMOG2;
 Mat MaskMOG2WithBlur;
 Mat MaskMOG2WithGBlur;
 Mat MaskMOG2WithMBlur;
 Mat MaskMOG2WithBFilter;

 Mat RoiFrame;
 Mat RoiFrame2;
 Mat RoiFrame3;
 Mat RoiFrame4;

 Ptr<BackgroundSubtractor> MOG2;

 namedWindow("Frame");
 namedWindow("Mask Frame");
 namedWindow("Mask Frame with Blur");
 //namedWindow("Mask Frame with GaussianBlur");
 //namedWindow("Mask Frame with medianBlur");
 //namedWindow("Mask Frame with bilateralFilter");

 MOG2 = createBackgroundSubtractorMOG2();
 VideoCapture capture(argv[1]);

 while(1){
  capture >> frame;
  //Smoothing by method of blur
  blur(frame, RoiFrame, Size(3, 3));
  //GaussianBlur(frame,RoiFrame2,Size(3, 3),0,0);
  //medianBlur (frame, RoiFrame3,15);
  //bilateralFilter(frame,RoiFrame4,15,80,80);
  //Background Subtractor 
  MOG2->apply(frame, MaskMOG2);
  MOG2->apply(RoiFrame, MaskMOG2WithBlur);
  //MOG2->apply(RoiFrame2, MaskMOG2WithGBlur);
 // MOG2->apply(RoiFrame3, MaskMOG2WithMBlur);
  //MOG2->apply(RoiFrame4, MaskMOG2WithBFilter);

  imshow("Frame", frame); 
  imshow("Mask Frame", MaskMOG2); 
  imshow("Mask Frame with Blur", MaskMOG2WithBlur); 
  //imshow("Mask Frame with GaussianBlur", MaskMOG2WithGBlur);
  //imshow("Mask Frame with medianBlur", MaskMOG2WithMBlur);
  //imshow("Mask Frame with bilateralFilter", MaskMOG2WithBFilter);
 if (waitKey(1) >= 0)  
   break;  
 }
 return 0;
}