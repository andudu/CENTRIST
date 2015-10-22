
#ifndef __IMAGE_INPUT_H__
#define __IMAGE_INPUT_H__



 #include <iostream>
 #include <sstream>

 #include "opencv2/core/core.hpp"
 #include "opencv2/core/opengl_interop.hpp"
 #include "opencv2/highgui/highgui.hpp"
 #include "opencv2/imgproc/imgproc.hpp"
 #include "opencv2/calib3d/calib3d.hpp"
 #include "opencv2/contrib/contrib.hpp"
 #include "SobeGrad.h"
 #include "Intimage.h"


 using namespace std;
 using namespace cv;

Mat Image_input(Mat &E, float ip)
 {

 //char* window_name = "CENSU_TRANSFORM";
 //namedWindow( window_name, WINDOW_AUTOSIZE);
//namedWindow("Integral",WINDOW_AUTOSIZE);
 const char* imgName = "e.bmp";
 Mat I = E;
 //Mat a = imread(imgName);
 //Size size(216,72);//the dst image size,e.g.100x100
 //Size size(640,480);
 //resize(a,I,size);//resize image




 //imshow("INPUT", I);
 Mat imgIn = SobeGrad(I,ip);
 Size imgSize = imgIn.size();
 Mat imgTemp = Mat::zeros(imgSize, CV_8U);

 //If (CurrentPixelIntensity<CentrePixelIntensity) boolean bit=0
 //else boolean bit=1
 //450jx375i

 unsigned int census = 0;
 unsigned int bit = 0;
 int m = 3;
 int n = 3;//window size
 int i,j,x,y;
 int shiftCount = 0;
 for (x = m/2; x < imgSize.height - m/2; x++)
 {
   for(y = n/2; y < imgSize.width - n/2; y++)
   {
     census = 0;
     shiftCount = 0;
     for (i = x - m/2; i <= x + m/2; i++)
     {
       for (j = y - n/2; j <= y + n/2; j++)
       {

         if( shiftCount != m*n/2 )//skip the center pixel
         {
         census <<= 1;
         if( imgIn.at<uchar>(i,j) < imgIn.at<uchar>(x,y) )//compare pixel values in the neighborhood
         bit = 1;
         else
         bit = 0;
         census = census + bit;
         //cout<<census<<" ";*/

         }
         shiftCount ++;
       }
     }
    //cout<<endl;

    imgTemp.ptr<uchar>(x)[y] = census;
   }
 }

 //waitKey(1);
 return(imgTemp) ;

}
#endif //__IMAGE_INPUT_H__
