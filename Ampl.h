
#ifndef __Ampl_H__
#define __Ampl_H__

#include <omp.h>
#include "tbb/blocked_range.h"
#include "tbb/parallel_for.h"
#include "tbb/task_scheduler_init.h"



 #include <iostream>
 #include <sstream>
 #include <stdio.h>
 #include <cmath>

 #include <ml.h>
 #include <fstream>
 #include <string>
 #include <sstream>
 #include <cassert>
 #include <vector>
 #include "Leg.h"
 #include "arm.h"
 #include "head.h"
 #include "Analysis.h"
 #include "Wind.h"




 #include "opencv2/core/core.hpp"
 #include "opencv2/core/opengl_interop.hpp"
 #include "opencv2/highgui/highgui.hpp"
 #include "opencv2/imgproc/imgproc.hpp"
 #include "opencv2/calib3d/calib3d.hpp"
 #include "opencv2/contrib/contrib.hpp"


using namespace std;
using namespace cv;

int  Ampl(Mat &II,Mat &b7,Mat &h,CvANN_MLP &nnetworkC,CvANN_MLP &nnetworkB,CvANN_MLP &nnetworkL,CvDTree &dtreeC,CvDTree &dtreeB,CvDTree &dtreeL,CvSVM &svmC,CvSVM &svmB,CvSVM &svmL)
{


std::vector<Rect> vecLista;
std::vector<Rect> vecListb;
std::vector<Rect> vecListc;
std::vector<Rect> vecListd;
std::vector<Rect> vecListe;
std::vector<Rect> vecListf;
std::vector<Rect> vecListg;
std::vector<Rect> vecListh;


vecLista.clear();
vecListb.clear();
vecListc.clear();
vecListd.clear();
vecListe.clear();
vecListf.clear();
vecListg.clear();
vecListh.clear();

Rect brect1;


namedWindow( "Membro Humano Detectado", WINDOW_AUTOSIZE);
Mat I, Isum,hh;
float Col = b7.cols;
float Row = b7.rows;
Mat AA = Mat::zeros(80,80, CV_32F);
Mat Dst(80,80,CV_8UC1);
Mat Image;
float ST;
int FF=1;




float Colb = (b7.cols);
float Rowb = (b7.rows);

int restColb = Colb/80;//ceil(Colb/80);
int restRowb = Rowb/80;//ceil(Rowb/80);


Size size(80,80);//There were the size of features from (160x120) to (80x80)
//Mat space((restRowb*80)/0.5,(restColb*80)/0.5, CV_8UC3, Scalar(0));//There were the size of features from (120x160) to (80x80)
Mat space(restRowb*80,restColb*80, CV_8UC3, Scalar(0));
//Size size1((restColb*80)/0.5,(restRowb*80)/0.5);
Size size1(80*restColb,80*restRowb);
resize(II,Image,size1);
Rect roi( Point( 0, 0 ), Image.size() );//Rect
Image.copyTo(space( roi ) );
//imshow("Image B",b7);
//waitKey(1);


Cabecas Sh;
Bracos Sa;
Pernas Sl;



for (float X=1.0;X  < 3;X+=1){

Size size(Col/X,Row/X);
resize(b7,hh,size);


    for(int j=2;(j+80) < (Row/X);j+=3)
    {

        for(int i=2;(i+80) < (Col/X);i+=3)

        {


     Mat p = hh(Rect(i,j,80,80));
        //imshow("Centrist",p);
        //cout<<"valor X= "<<X;
       //waitKey(1);


      integral(p,Isum,CV_32F);
      Size size(80,80);
      resize(Isum,I,size);
      Scalar FT = sum(I);
      float IimagT=(FT.val[0])/1000000;
      compare(I,AA,Dst, CMP_NE);
      if ((Dst.at<uchar>(1,1) == 255) && (IimagT > 60))
      {


if ( ! p.isContinuous() )
    {p = p.clone();}





     //imshow("Centrist",p);
     //waitKey(100);
     Sl= Leg(p,nnetworkL,dtreeL,svmL);
     Sa= arm(p,nnetworkB,dtreeB,svmB);
     Sh= head(p,nnetworkC,dtreeC,svmC);
     //float Z =(((Sl.SL1+Sl.SL2+Sl.SL3)*1.0)+((Sa.SA1+Sa.SA2+Sa.SA3)*1.0) + ((Sh.SH1+Sh.SH2+Sh.SH3)*2.0));
     int Z,z1,z2,z3;
     if ((Sl.SL1+Sl.SL2+Sl.SL3)>=2.0){z1=1;}
     else {z1=0;}
     if ((Sa.SA1+Sa.SA2+Sa.SA3)>=2.0){z2=1;}
     else {z2=0;}
     if((Sh.SH1+Sh.SH2+Sh.SH3)>=2.0){z3=1;}
     else {z3=0;}
     //if (((Sl.SL1+Sl.SL2+Sl.SL3)>=2) || ((Sa.SA1+Sa.SA2+Sa.SA3)>=2) || ((Sh.SH1+Sh.SH2+Sh.SH3)>=2));{
     if (Z=z1+z2+z3 >= 1.0){
     ST = Analysis(Sl,Sa,Sh);
      if (ST >= 0.992){//0.992
            //int FF=1;
            cout << "Propabilidade de haver Corpo_Human0 ="<<ST*100<<"%"<<endl;
            cv::Rect rect(i/pow(X,FF-1),j/pow(X,FF-1),1*(80/pow(X,FF-1)),1*(80/pow(X,FF-1)));//160 and 120

            int w = 1;
            switch (w)
        {
           case 1:vecLista.push_back(rect);
                break;
            case 2:vecListb.push_back(rect);
                break;
            default: cout << "qwerty";
            break;}



            }


     }

    }
        }

    }
     int F = FF;
     //int W = wind(X,F,h,space,roi,vecList,vecList1,vecList2,vecList3,vecList4,vecList5,vecList6,vecList7,vecList8,vecList9,vecList10,vecList11,vecList12,vecList13,vecList14,vecList15,vecList16,vecList17,vecList18,vecList19,vecList20);


}

 if ((vecLista.size()!= 0) && (1 == 1)){//FF
     if(vecLista.size()>1){
                        groupRectangles( vecLista,2,0.2);}
                        int p ,q ;
                        int FF=1;
                        //CT++;
                        //#pragma omp parallel for
                        for(int z=0;z<vecLista.size();z++){
                        p=vecLista[z].x;
                        q=vecLista[z].y;
                       int w=vecLista[z].width;
                       int h=vecLista[z].height;
                        //cv::Rect rectT(p,q,(160*X)/restCold,(120*X)/restRowd);
                        //vecTotal.push_back(rectT);
                        //RotatedRect rRect1 = RotatedRect(Point2f(p+(80/0.5)/2,q+(80/0.5)/2),Size2f(w,h), 0);//Size2f((160)/restCold,(120)/restRowd), 0);#@
                        RotatedRect rRect1 = RotatedRect(Point2f(p+(80/restColb)/2,q+(80/restRowb)/2), Size2f(w,h), 0);
                        // 160 and 120  e  160 and 120

                        brect1 = rRect1.boundingRect();
                        cv::rectangle(space, brect1, Scalar(0,255,0),1.0);//into the space I put my rectangle into center point (x,y) .
                        //t = ((double)getTickCount() - t)/getTickFrequency();
                        //cout << "Times passed in seconds: " << t << endl;
                        imshow("Membro Humano Detectado",space);
                        //imwrite("/home/fabiano/My_Project/Centrist/Fotos_Rec/Membro_Humano.jpg",space);
                        //waitKey(1);

                        }}
                        if ((vecLista.size()!=0)){return 1;}


return 0;
}



#endif //__IMAGE_INPUT_H__
