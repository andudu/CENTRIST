
#ifndef __ClassifierHIK_H__
#define __ClassifierHIK_H__



 #include <iostream>
 #include <sstream>
 #include <stdio.h>




 #include "opencv2/core/core.hpp"
 #include "opencv2/core/opengl_interop.hpp"
 #include "opencv2/highgui/highgui.hpp"
 #include "opencv2/imgproc/imgproc.hpp"
 #include "opencv2/calib3d/calib3d.hpp"
 #include "opencv2/contrib/contrib.hpp"




using namespace std;
using namespace cv;




int  ClassifierHIK(Mat &E)
{
int c=0;
int xx=0;
int R=0;
int yy=0;
int iii,jjj;
Mat k;
float T=0;
float U = 0;
Mat A1 = Mat::zeros(16,16, CV_32F);//24 and 32
Mat dst1(16,16,CV_8UC1);//24 and 32



//namedWindow("Integral",WINDOW_NORMAL);


Size size(80,80);// 160 and 120
k = E;

 //integral(ImageClone1,isum,CV_32F);
              //resize(isum,k,size);
              //Scalar FT = sum(k);
              //float IimagT=(FT.val[0])/pow(10,19);
              //T = IimagT;
              //R =25;
              //imshow("Integral",isum);
            //waitKey(10);



             for (iii=1;iii<= 5;iii++)
{
    for (jjj=1;jjj<= 5 ;jjj++)//6#@

    {
        if(jjj > 1 && jjj< 6)
        xx = xx + 16;//32#@

    //R++;
    Mat subMat = k(Rect(xx,yy,16,16));//32 and 24#@
    //Size size1(32,24);
    //resize(subMat,IT,size1);
    //compare(subMat,A1,dst1, CMP_NE);
      //if (dst1.at<uchar>(1,1) == 255)
      //{


//if ( ! k.isContinuous() )
    //{k = k.clone();}

    //imshow("Integral",isum);


//float* pixel = NULL;#@
        //#pragma omp parallel for
        for(int p = 0; p < subMat.rows; p++){
            //float* pixel = subMat.ptr<float>(p);  // point to first color in row

        //#pragma omp parallel for
        for(int q = 0; q < subMat.cols; q++){
        float D = (subMat.at<float>(p,q));
            //float D = *pixel++;
            if (D!=0.0){
        //U+= ((*pixel++));}
        U+=D;}

            }
        }


        //delete pixel;
        R++;
        T+=  U;
        //printf("%d :%f :%f\n",R,U,(T/10000));//U*0.00000438799,R);
        //waitKey(1000);
        if (R==25){//30
        if ((T/10)>= 50){//50.0
        //cout << T/10 <<"\n";
        return(c=1);}}//48

      //}
    //cc.push_back(subMat.reshape(0,1)); //0 makes channel unchanged and 1 makes single row

     if(jjj == 5 && iii == 1)//6#@
     xx = yy = 0;
     if(jjj == 5 && iii > 1)//6#@
     xx = 0;

    }
    yy = yy + 16;//24#@

}




}



#endif //__IMAGE_INPUT_H__
