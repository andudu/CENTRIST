
#ifndef __SOBEGRAD_H__
#define __SOBEGRAD_H__


 #include <iostream>
 #include <sstream>

 #include "opencv2/core/core.hpp"
 #include "opencv2/core/opengl_interop.hpp"
 #include "opencv2/highgui/highgui.hpp"
 #include "opencv2/imgproc/imgproc.hpp"
 #include "opencv2/calib3d/calib3d.hpp"
 #include "opencv2/contrib/contrib.hpp"



 using namespace std;
 using namespace cv;

Mat SobeGrad(Mat &I, float ip)
 {




  Mat src_gray, src;
  src = I;
  Mat grad,imgIn;
  char* window_name = "SOBEL";
  int scale = 1;
  int delta = 0;
  int ddepth = CV_16S;
  int kernel_size = 3;
  int c;


  //if( !src.data )
 // { return -1; }

  GaussianBlur( src, src, Size(3,3), 4, 4, BORDER_DEFAULT);


  /// Convert it to gray
  cvtColor( src, src_gray, CV_RGB2GRAY );


  /// Create window
  //namedWindow( "SOBEL", WINDOW_AUTOSIZE );

  /// Generate grad_x and grad_y
  Mat grad_x, grad_y;
  Mat abs_grad_x, abs_grad_y;

  /// Gradient X
  //Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
  Sobel( src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT );
  convertScaleAbs( grad_x, abs_grad_x );

  /// Gradient Y
  //Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
  Sobel( src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT );
  convertScaleAbs( grad_y, abs_grad_y );

  /// Total Gradient (approximate)
  addWeighted( abs_grad_x, 0.00129*ip, abs_grad_y, 0.00129*ip, 0, grad );//HIK > 0.00142 desastre //drone 0.0046

  //imshow( "SOBEL", grad );
  //waitKey();


  return(grad);



}
#endif //__SOBEGRAD_H__
