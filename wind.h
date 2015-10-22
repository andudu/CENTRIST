
#ifndef __Wind_H__
#define __Wind_H__



 #include <iostream>
 #include <sstream>
 #include <stdio.h>
 #include <ml.h>




 #include "opencv2/core/core.hpp"
 #include "opencv2/core/opengl_interop.hpp"
 #include "opencv2/highgui/highgui.hpp"
 #include "opencv2/imgproc/imgproc.hpp"
 #include "opencv2/calib3d/calib3d.hpp"
 #include "opencv2/contrib/contrib.hpp"




using namespace std;
using namespace cv;




int  wind(float X,int F,Mat &h,Mat &space,Rect &roi,std::vector<Rect> &vecList,std::vector<Rect> &vecList1,std::vector<Rect> &vecList2,std::vector<Rect> &vecList3,std::vector<Rect> &vecList4,std::vector<Rect> &vecList5,std::vector<Rect> &vecList6,std::vector<Rect> &vecList7,std::vector<Rect> &vecList8,std::vector<Rect> &vecList9,std::vector<Rect> &vecList10,std::vector<Rect> &vecList11,std::vector<Rect> &vecList12,std::vector<Rect> &vecList13,std::vector<Rect> &vecList14,std::vector<Rect> &vecList15,std::vector<Rect> &vecList16,std::vector<Rect> &vecList17,std::vector<Rect> &vecList18,std::vector<Rect> &vecList19,std::vector<Rect> &vecList20)
{

int z;
int xx=0;
int R=0;
int yy=0;
int iii,jjj;
Mat k = h;
float T=0;
float U = 0;
int CT = 0;
Mat A1 = Mat::zeros(16,16, CV_32F);//24 and 32
Mat dst1(16,16,CV_8UC1);//24 and 32
float restCold = 1.5;//(640/(k.cols))*0.6;//1.5
float restRowd = 1.5;//(480/(k.rows))*0.6;//1.5
Rect brect1;
namedWindow( "Detectado", WINDOW_AUTOSIZE);





std::vector<Rect> vecTotal;
std::vector<Rect> vecFinal;
std::vector<Rect> vecFinal1;


 if ((vecList.size()!= 0) && (F == 1)){

                       //for(int z=0;z<vecList.size();z++){
                       //int p=vecList[z].x;
                       //if ((vecList[z].y == vecList[z+1].y) && (vecList[z].height > vecList[z+1].height)){vecList.erase(vecList.begin()+z+1);}
                            //else if ((vecList[z].y == vecList[z+1].y) && (vecList[z].height < vecList[z+1].height)){vecList.erase(vecList.begin()+z);}

                       //}
                        groupRectangles( vecList,2,0.6);//2,0.2
                        int p ,q ;
                        int FF=F;
                        CT++;
                        //#pragma omp parallel for
                        for(int z=0;z<vecList.size();z++){
                        p=vecList[z].x;
                        q=vecList[z].y;
                       int w=vecList[z].width;
                       int h=(vecList[z].height);
                       //int h = 72;
                        //cv::Rect rectT(p,q,(160*X)/restCold,(120*X)/restRowd);
                        //vecTotal.push_back(rectT);
                        RotatedRect rRect1 = RotatedRect(Point2f(p+(80/restCold)/2,q+(80/restRowd)/2),Size2f(w*X,h*X), 0);//Size2f((160)/restCold,(120)/restRowd), 0);
                        // 160 and 120  e  160 and 120

                        brect1 = rRect1.boundingRect();
                        //cv::rectangle(space, brect1, Scalar(255,255,0),0.25);//into the space I put my rectangle into center point (x,y) .
                        //t = ((double)getTickCount() - t)/getTickFrequency();
                        //cout << "Times passed in seconds: " << t << endl;
                        //imshow("Detectado",space);
                        //waitKey(1);
                        }}


     else if ((vecList1.size()!= 0) && (F == 2)){
                       //for(int z=0;z<vecList1.size();z++){
                       //int p=vecList1[z].x;
                       //if ((vecList1[z].y == vecList1[z+1].y) && (vecList1[z].height > vecList1[z+1].height)){vecList1.erase(vecList1.begin()+z+1);}
                            //else if ((vecList1[z].y == vecList1[z+1].y) && (vecList1[z].height < vecList1[z+1].height)){vecList1.erase(vecList1.begin()+z);}

                       //}
                        groupRectangles( vecList1,2,0.4);
                        int p1 ,q1 ;
                        int FF=F;
                        CT++;
                        //#pragma omp parallel for
                        for(int z=0;z<vecList1.size();z++){
                        p1=vecList1[z].x;
                        q1=vecList1[z].y;
                        int w1=vecList1[z].width;
                        int h1=vecList1[z].height;
                        //int h1 = 80;
                        //cv::Rect rectT(p,q,(160*X)/restCold,(120*X)/restRowd);
                        //vecTotal.push_back(rectT);
                        RotatedRect rRect1 = RotatedRect(Point2f(p1+(80/restCold)/2,q1+(80/restRowd)/2), Size2f(w1,h1), 0);
                        brect1 = rRect1.boundingRect();
                        //cv::rectangle(space, brect1, Scalar(255,0,0),0.25);
                        //t = ((double)getTickCount() - t)/getTickFrequency();
                        //cout << "Times passed in seconds: " << t << endl;
                        //imshow("Detectado",space);
                        //waitKey(1);
                        }}

   else if ((vecList2.size()!= 0) && (F == 3)){
                       //for(int z=0;z<vecList2.size();z++){
                       //int p=vecList2[z].x;
                       //if ((vecList2[z].y == vecList2[z+1].y) && (vecList2[z].height > vecList2[z+1].height)){vecList2.erase(vecList2.begin()+z+1);}
                            //else if ((vecList2[z].y == vecList2[z+1].y) && (vecList2[z].height < vecList2[z+1].height)){vecList2.erase(vecList2.begin()+z);}

                       //}
                        groupRectangles( vecList2,2,0.4);
                        int p2 ,q2 ;
                        int FF=F;
                        CT++;
                        //#pragma omp parallel for
                        for(int z=0;z<vecList2.size();z++){
                        p2=vecList2[z].x;
                        q2=vecList2[z].y;
                        int w2=vecList2[z].width;
                        int h2=vecList2[z].height;
                        //int h2 = 88;

                        //cv::Rect rectT(p,q,(160*X)/restCold,(120*X)/restRowd);
                        //vecTotal.push_back(rectT);
                        RotatedRect rRect1 = RotatedRect(Point2f(p2+(80/restCold)/2,q2+(80/restRowd)/2), Size2f(w2,h2), 0);
                        brect1 = rRect1.boundingRect();
                        //cv::rectangle(space, brect1, Scalar(255,0,255),0.25);
                        //t = ((double)getTickCount() - t)/getTickFrequency();
                        //cout << "Times passed in seconds: " << t << endl;
                        //imshow("Detectado",space);
                        //waitKey(1);
                        }}

    else if ((vecList3.size()!= 0) && ( F == 4)){
                       //for(int z=0;z<vecList3.size();z++){
                       //int p=vecList3[z].x;
                       //if ((vecList3[z].y == vecList3[z+1].y) && (vecList3[z].height > vecList3[z+1].height)){vecList3.erase(vecList3.begin()+z+1);}
                            //else if ((vecList3[z].y == vecList3[z+1].y) && (vecList3[z].height < vecList3[z+1].height)){vecList3.erase(vecList3.begin()+z);}

                       //}
                        groupRectangles( vecList3,2,0.4);
                        int p3 ,q3 ;
                        int FF=F;
                        CT++;
                        //#pragma omp parallel for
                        for(int z=0;z<vecList3.size();z++){
                        p3=vecList3[z].x;
                        q3=vecList3[z].y;
                        int w3=vecList3[z].width;
                        int h3=vecList3[z].height;
                        //int h3 = 96;
                        //cv::Rect rectT(p,q,(160*X)/restCold,(120*X)/restRowd);
                        //vecTotal.push_back(rectT);
                        RotatedRect rRect1 = RotatedRect(Point2f(p3+(80/restCold)/2,q3+(80/restRowd)/2), Size2f(w3,h3), 0);
                        brect1 = rRect1.boundingRect();
                        //cv::rectangle(space, brect1, Scalar(0,255,0),0.25);
                        //t = ((double)getTickCount() - t)/getTickFrequency();
                        //cout << "Times passed in seconds: " << t << endl;

                        //imshow("Detectado",space);
                        //waitKey(1);
                        }}


    else if ((vecList4.size()!= 0) && (F == 5)){
                       //for(int z=0;z<vecList4.size();z++){
                       //int p=vecList4[z].x;
                       //if ((vecList4[z].y == vecList4[z+1].y) && (vecList4[z].height > vecList4[z+1].height)){vecList4.erase(vecList4.begin()+z+1);}
                            //else if ((vecList4[z].y == vecList4[z+1].y) && (vecList4[z].height < vecList4[z+1].height)){vecList4.erase(vecList4.begin()+z);}

                       //}
                        groupRectangles( vecList4,2,0.4);
                        int p4 ,q4 ;
                        int FF=F;
                        CT++;
                        //#pragma omp parallel for
                        for(int z=0;z<vecList4.size();z++){
                        p4=vecList4[z].x;
                        q4=vecList4[z].y;
                        int w4=vecList4[z].width;
                        int h4=vecList4[z].height;
                        //int h4= 104;
                        //cv::Rect rectT(p,q,(160*X)/restCold,(120*X)/restRowd);
                        //vecTotal.push_back(rectT);
                        RotatedRect rRect1 = RotatedRect(Point2f(p4+(80/restCold)/2,q4+(80/restRowd)/2), Size2f(w4,h4), 0);
                        brect1 = rRect1.boundingRect();
                        //cv::rectangle(space, brect1, Scalar(0,0,255),0.25);
                        //t = ((double)getTickCount() - t)/getTickFrequency();
                        //cout << "Times passed in seconds: " << t << endl;

                        //imshow("Detectado",space);
                        //waitKey(1);
                        }}



    else if ((vecList5.size()!= 0) && (F == 6)){
                       //for(int z=0;z<vecList5.size();z++){
                       //int p=vecList5[z].x;
                       //if ((vecList5[z].y == vecList5[z+1].y) && (vecList5[z].height > vecList5[z+1].height)){vecList5.erase(vecList5.begin()+z+1);}
                            //else if ((vecList5[z].y == vecList5[z+1].y) && (vecList5[z].height < vecList5[z+1].height)){vecList5.erase(vecList5.begin()+z);}

                       //}
                        groupRectangles( vecList5,2,0.4);
                        int p5 ,q5 ;
                        int FF=F;
                        CT++;
                        //#pragma omp parallel for
                        for(int z=0;z<vecList5.size();z++){
                        p5=vecList5[z].x;
                        q5=vecList5[z].y;
                        int w5=vecList5[z].width;
                        int h5=vecList5[z].height;
                        //int h5=112;
                        //cv::Rect rectT(p,q,(160*X)/restCold,(120*X)/restRowd);
                        //vecTotal.push_back(rectT);
                        RotatedRect rRect1 = RotatedRect(Point2f(p5+(80/restCold)/2,q5+(80/restRowd)/2), Size2f(w5,h5), 0);
                        brect1 = rRect1.boundingRect();
                        //cv::rectangle(space, brect1, Scalar(0,255,255),0.25);

                        //imshow("Detectado",space);
                        //waitKey(1);
                        }}

    else if ((vecList6.size()!= 0) && (F == 7)){ groupRectangles( vecList6,2,0.4);
                        int p6 ,q6 ;
                        int FF=F;
                        CT++;
                        //#pragma omp parallel for
                        for(int z=0;z<vecList6.size();z++){
                        p6=vecList6[z].x;
                        q6=vecList6[z].y;
                        int w6=vecList6[z].width;
                        int h6=vecList6[z].height;
                        //cv::Rect rectT(p,q,(160*X)/restCold,(120*X)/restRowd);
                        //vecTotal.push_back(rectT);
                        RotatedRect rRect1 = RotatedRect(Point2f(p6+(80/restCold)/2,q6+(80/restRowd)/2), Size2f(w6,h6), 0);
                        brect1 = rRect1.boundingRect();
                        //cv::rectangle(space, brect1, Scalar(0,255,255),0.25);

                        //imshow("Detectado",space);
                        //waitKey(1);
                        }}

    else if ((vecList7.size()!= 0) && (F == 8)){ groupRectangles( vecList7,2,0.4);
                        int p7 ,q7 ;
                        int FF=F;
                        CT++;
                        //#pragma omp parallel for
                        for(int z=0;z<vecList7.size();z++){
                        p7=vecList7[z].x;
                        q7=vecList7[z].y;
                        int w7=vecList7[z].width;
                        int h7=vecList7[z].height;
                        //cv::Rect rectT(p,q,(160*X)/restCold,(120*X)/restRowd);
                        //vecTotal.push_back(rectT);
                        RotatedRect rRect1 = RotatedRect(Point2f(p7+(80/restCold)/2,q7+(80/restRowd)/2), Size2f(w7,h7), 0);
                        brect1 = rRect1.boundingRect();
                        //cv::rectangle(space, brect1, Scalar(0,255,255),0.25);

                        //imshow("Detectado",space);
                        //waitKey(1);
                        }}

    else if ((vecList8.size()!= 0) && (F == 9)){ groupRectangles( vecList8,2,0.4);
                        int p8 ,q8 ;
                        int FF=F;
                        CT++;
                        //#pragma omp parallel for
                        for(int z=0;z<vecList8.size();z++){
                        p8=vecList8[z].x;
                        q8=vecList8[z].y;
                        int w8=vecList8[z].width;
                        int h8=vecList8[z].height;
                        //cv::Rect rectT(p,q,(160*X)/restCold,(120*X)/restRowd);
                        //vecTotal.push_back(rectT);
                        RotatedRect rRect1 = RotatedRect(Point2f(p8+(80/restCold)/2,q8+(80/restRowd)/2), Size2f(w8,h8), 0);
                        brect1 = rRect1.boundingRect();
                        //cv::rectangle(space, brect1, Scalar(0,255,255),0.25);

                        //imshow("Detectado",space);
                        //waitKey(1);
                        }}

    else if ((vecList9.size()!= 0) && (F == 10)){ groupRectangles( vecList9,2,0.4);
                        int p9 ,q9 ;
                        int FF=F;
                        CT++;
                        //#pragma omp parallel for
                        for(int z=0;z<vecList9.size();z++){
                        p9=vecList9[z].x;
                        q9=vecList9[z].y;
                        int w9=vecList9[z].width;
                        int h9=vecList9[z].height;
                        //cv::Rect rectT(p,q,(160*X)/restCold,(120*X)/restRowd);
                        //vecTotal.push_back(rectT);
                        RotatedRect rRect1 = RotatedRect(Point2f(p9+(80/restCold)/2,q9+(80/restRowd)/2), Size2f(w9,h9), 0);
                        brect1 = rRect1.boundingRect();
                        //cv::rectangle(space, brect1, Scalar(0,255,255),0.25);

                        //imshow("Detectado",space);
                        //waitKey(1);
                        }}

    else if ((vecList10.size()!= 0) && (F == 11)){ groupRectangles( vecList10,2,0.4);
                        int p10 ,q10 ;
                        int FF=F;
                        CT++;
                        //#pragma omp parallel for
                        for(int z=0;z<vecList10.size();z++){
                        p10=vecList10[z].x;
                        q10=vecList10[z].y;
                        int w10=vecList10[z].width;
                        int h10=vecList10[z].height;
                        //cv::Rect rectT(p,q,(160*X)/restCold,(120*X)/restRowd);
                        //vecTotal.push_back(rectT);
                        RotatedRect rRect1 = RotatedRect(Point2f(p10+(80/restCold)/2,q10+(80/restRowd)/2), Size2f(w10,h10), 0);
                        brect1 = rRect1.boundingRect();
                        //cv::rectangle(space, brect1, Scalar(0,255,255),0.25);

                        //imshow("Detectado",space);
                        //waitKey(1);
                        }}

    else if ((vecList11.size()!= 0) && (F == 12)){ groupRectangles( vecList11,2,0.4);
                        int p11 ,q11 ;
                        int FF=F;
                        CT++;
                        //#pragma omp parallel for
                        for(int z=0;z<vecList11.size();z++){
                        p11=vecList11[z].x;
                        q11=vecList11[z].y;
                        int w11=vecList11[z].width;
                        int h11=vecList11[z].height;
                        //cv::Rect rectT(p,q,(160*X)/restCold,(120*X)/restRowd);
                        //vecTotal.push_back(rectT);
                        RotatedRect rRect1 = RotatedRect(Point2f(p11+(80/restCold)/2,q11+(80/restRowd)/2), Size2f(w11,h11), 0);
                        brect1 = rRect1.boundingRect();
                        //cv::rectangle(space, brect1, Scalar(0,255,255),0.25);

                        //imshow("Detectado",space);
                        //waitKey(1);
                        }}

    else if ((vecList12.size()!= 0) && (F == 13)){ groupRectangles( vecList12,2,0.4);
                        int p12 ,q12 ;
                        int FF=F;
                        CT++;
                        //#pragma omp parallel for
                        for(int z=0;z<vecList12.size();z++){
                        p12=vecList12[z].x;
                        q12=vecList12[z].y;
                        int w12=vecList12[z].width;
                        int h12=vecList12[z].height;
                        //cv::Rect rectT(p,q,(160*X)/restCold,(120*X)/restRowd);
                        //vecTotal.push_back(rectT);
                        RotatedRect rRect1 = RotatedRect(Point2f(p12+(80/restCold)/2,q12+(80/restRowd)/2), Size2f(w12,h12), 0);
                        brect1 = rRect1.boundingRect();
                        //cv::rectangle(space, brect1, Scalar(0,255,255),0.25);

                        //imshow("Detectado",space);
                        //waitKey(1);
                        }}

    else if ((vecList13.size()!= 0) && (F == 14)){ groupRectangles( vecList13,2,0.4);
                        int p13 ,q13 ;
                        int FF=F;
                        CT++;
                        //#pragma omp parallel for
                        for(int z=0;z<vecList13.size();z++){
                        p13=vecList13[z].x;
                        q13=vecList13[z].y;
                        int w13=vecList13[z].width;
                        int h13=vecList13[z].height;
                        //cv::Rect rectT(p,q,(160*X)/restCold,(120*X)/restRowd);
                        //vecTotal.push_back(rectT);
                        RotatedRect rRect1 = RotatedRect(Point2f(p13+(80/restCold)/2,q13+(80/restRowd)/2), Size2f(w13,h13), 0);
                        brect1 = rRect1.boundingRect();
                        //cv::rectangle(space, brect1, Scalar(0,255,255),0.25);

                        //imshow("Detectado",space);
                        //waitKey(1);
                        }}

    else if ((vecList14.size()!= 0) && (F == 15)){ groupRectangles( vecList14,2,0.4);
                        int p14 ,q14 ;
                        int FF=F;
                        CT++;
                        //#pragma omp parallel for
                        for(int z=0;z<vecList14.size();z++){
                        p14=vecList14[z].x;
                        q14=vecList14[z].y;
                        int w14=vecList14[z].width;
                        int h14=vecList14[z].height;
                        //cv::Rect rectT(p,q,(160*X)/restCold,(120*X)/restRowd);
                        //vecTotal.push_back(rectT);
                        RotatedRect rRect1 = RotatedRect(Point2f(p14+(80/restCold)/2,q14+(80/restRowd)/2), Size2f(w14,h14), 0);
                        brect1 = rRect1.boundingRect();
                        //cv::rectangle(space, brect1, Scalar(0,255,255),0.25);

                        //imshow("Detectado",space);
                        //waitKey(1);
                        }}

    else if ((vecList15.size()!= 0) && (F == 16)){ groupRectangles( vecList15,2,0.4);
                        int p15 ,q15 ;
                        int FF=F;
                        CT++;
                        //#pragma omp parallel for
                        for(int z=0;z<vecList15.size();z++){
                        p15=vecList15[z].x;
                        q15=vecList15[z].y;
                        int w15=vecList15[z].width;
                        int h15=vecList15[z].height;
                        //cv::Rect rectT(p,q,(160*X)/restCold,(120*X)/restRowd);
                        //vecTotal.push_back(rectT);
                        RotatedRect rRect1 = RotatedRect(Point2f(p15+(80/restCold)/2,q15+(80/restRowd)/2), Size2f(w15,h15), 0);
                        brect1 = rRect1.boundingRect();
                        //cv::rectangle(space, brect1, Scalar(0,255,255),0.25);

                        //imshow("Detectado",space);
                        //waitKey(1);
                        }}

    else if ((vecList16.size()!= 0) && (F == 17)){ groupRectangles( vecList16,2,0.4);
                        int p16 ,q16 ;
                        int FF=F;
                        CT++;
                        //#pragma omp parallel for
                        for(int z=0;z<vecList16.size();z++){
                        p16=vecList16[z].x;
                        q16=vecList16[z].y;
                        int w16=vecList16[z].width;
                        int h16=vecList16[z].height;
                        //cv::Rect rectT(p,q,(160*X)/restCold,(120*X)/restRowd);
                        //vecTotal.push_back(rectT);
                        RotatedRect rRect1 = RotatedRect(Point2f(p16+(80/restCold)/2,q16+(80/restRowd)/2), Size2f(w16,h16), 0);
                        brect1 = rRect1.boundingRect();
                        //cv::rectangle(space, brect1, Scalar(0,255,255),0.25);

                        //imshow("Detectado",space);
                        //waitKey(1);
                        }}


    else if ((vecList17.size()!= 0) && (F == 18)){ groupRectangles( vecList17,2,0.4);
                        int p17 ,q17 ;
                        int FF=F;
                        CT++;
                        //#pragma omp parallel for
                        for(int z=0;z<vecList17.size();z++){
                        p17=vecList17[z].x;
                        q17=vecList17[z].y;
                        int w17=vecList17[z].width;
                        int h17=vecList17[z].height;
                        //cv::Rect rectT(p,q,(160*X)/restCold,(120*X)/restRowd);
                        //vecTotal.push_back(rectT);
                        RotatedRect rRect1 = RotatedRect(Point2f(p17+(80/restCold)/2,q17+(80/restRowd)/2), Size2f(w17,h17), 0);
                        brect1 = rRect1.boundingRect();
                        //cv::rectangle(space, brect1, Scalar(0,255,255),0.25);

                        //imshow("Detectado",space);
                        //waitKey(1);
                        }}

    else if ((vecList18.size()!= 0) && (F == 19)){ groupRectangles( vecList18,2,0.4);
                        int p18 ,q18 ;
                        int FF=F;
                        CT++;
                        //#pragma omp parallel for
                        for(int z=0;z<vecList18.size();z++){
                        p18=vecList18[z].x;
                        q18=vecList18[z].y;
                        int w18=vecList18[z].width;
                        int h18=vecList18[z].height;
                        //cv::Rect rectT(p,q,(160*X)/restCold,(120*X)/restRowd);
                        //vecTotal.push_back(rectT);
                        RotatedRect rRect1 = RotatedRect(Point2f(p18+(80/restCold)/2,q18+(80/restRowd)/2), Size2f(w18,h18), 0);
                        brect1 = rRect1.boundingRect();
                        //cv::rectangle(space, brect1, Scalar(0,255,255),0.25);

                        //imshow("Detectado",space);
                        //waitKey(1);
                        }}

    else if ((vecList19.size()!= 0) && (F == 20)){ groupRectangles( vecList19,2,0.4);
                        int p19 ,q19 ;
                        int FF=F;
                        CT++;
                        //#pragma omp parallel for
                        for(int z=0;z<vecList19.size();z++){
                        p19=vecList19[z].x;
                        q19=vecList19[z].y;
                        int w19=vecList19[z].width;
                        int h19=vecList19[z].height;
                        //cv::Rect rectT(p,q,(160*X)/restCold,(120*X)/restRowd);
                        //vecTotal.push_back(rectT);
                        RotatedRect rRect1 = RotatedRect(Point2f(p19+(80/restCold)/2,q19+(80/restRowd)/2), Size2f(w19,h19), 0);
                        brect1 = rRect1.boundingRect();
                        //cv::rectangle(space, brect1, Scalar(0,255,255),0.25);

                        //imshow("Detectado",space);
                        //waitKey(1);
                        }}

    else if ((vecList20.size()!= 0) && (F == 21)){ groupRectangles( vecList20,2,0.4);
                        int p20 ,q20 ;
                        int FF=F;
                        CT++;
                        //#pragma omp parallel for
                        for(int z=0;z<vecList20.size();z++){
                        p20=vecList20[z].x;
                        q20=vecList20[z].y;
                        int w20=vecList20[z].width;
                        int h20=vecList20[z].height;
                        //cv::Rect rectT(p,q,(160*X)/restCold,(120*X)/restRowd);
                        //vecTotal.push_back(rectT);
                        RotatedRect rRect1 = RotatedRect(Point2f(p20+(80/restCold)/2,q20+(80/restRowd)/2), Size2f(w20,h20), 0);
                        brect1 = rRect1.boundingRect();
                        //cv::rectangle(space, brect1, Scalar(0,255,255),0.25);

                        //imshow("Detectado",space);
                        //waitKey(1);
                        }}

     if ((h.rows<=80 || h.cols<=80)){//120 and 160
                        int p ,q,p1,q1,p2,q2 ;
                        int w,h,w1,h1,w2,h2;


                         for(int z2=0;z2<vecList.size();z2++){
                                p1=vecList[z2].x;
                                q1=vecList[z2].y;
                                w1=vecList[z2].width;
                                h1=vecList[z2].height;
                                cv::Rect rectT(p1,q1,w1,h1);// 160 and 120
                                vecTotal.push_back(rectT);}

                         for(int z2=0;z2<vecList1.size();z2++){
                                p1=vecList1[z2].x;
                                q1=vecList1[z2].y;
                                w1=vecList1[z2].width;
                                h1=vecList1[z2].height;
                                cv::Rect rectT(p1,q1,w1,h1);//160 and 120
                                vecTotal.push_back(rectT);}

                            for(int z2=0;z2<vecList2.size();z2++){
                                p1=vecList2[z2].x;
                                q1=vecList2[z2].y;
                                w1=vecList2[z2].width;
                                h1=vecList2[z2].height;
                                cv::Rect rectT(p1,q1,w1,h1);//160 and 120
                                vecTotal.push_back(rectT);}

                            for(int z2=0;z2<vecList3.size();z2++){
                                p1=vecList3[z2].x;
                                q1=vecList3[z2].y;
                                w1=vecList3[z2].width;
                                h1=vecList3[z2].height;
                                cv::Rect rectT(p1,q1,w1,h1);// 160 and 120
                                vecTotal.push_back(rectT);}

                            for(int z2=0;z2<vecList4.size();z2++){
                                p1=vecList4[z2].x;
                                q1=vecList4[z2].y;
                                w1=vecList4[z2].width;
                                h1=vecList4[z2].height;
                                cv::Rect rectT(p1,q1,w1,h1);//160 and 120
                                vecTotal.push_back(rectT);}

                            for(int z2=0;z2<vecList5.size();z2++){
                                p1=vecList5[z2].x;
                                q1=vecList5[z2].y;
                                w1=vecList5[z2].width;
                                h1=vecList5[z2].height;
                                cv::Rect rectT(p1,q1,w1,h1);//160 and 120
                                vecTotal.push_back(rectT);}

                             for(int z2=0;z2<vecList6.size();z2++){
                                p1=vecList6[z2].x;
                                q1=vecList6[z2].y;
                                w1=vecList6[z2].width;
                                h1=vecList6[z2].height;
                                cv::Rect rectT(p1,q1,w1,h1);//160 and 120
                                vecTotal.push_back(rectT);}

                             for(int z2=0;z2<vecList7.size();z2++){
                                p1=vecList7[z2].x;
                                q1=vecList7[z2].y;
                                w1=vecList7[z2].width;
                                h1=vecList7[z2].height;
                                cv::Rect rectT(p1,q1,w1,h1);//160 and 120
                                vecTotal.push_back(rectT);}

                             for(int z2=0;z2<vecList8.size();z2++){
                                p1=vecList8[z2].x;
                                q1=vecList8[z2].y;
                                w1=vecList8[z2].width;
                                h1=vecList8[z2].height;
                                cv::Rect rectT(p1,q1,w1,h1);//160 and 120
                                vecTotal.push_back(rectT);}

                             for(int z2=0;z2<vecList9.size();z2++){
                                p1=vecList9[z2].x;
                                q1=vecList9[z2].y;
                                w1=vecList9[z2].width;
                                h1=vecList9[z2].height;
                                cv::Rect rectT(p1,q1,w1,h1);//160 and 120
                                vecTotal.push_back(rectT);}

                             for(int z2=0;z2<vecList10.size();z2++){
                                p1=vecList10[z2].x;
                                q1=vecList10[z2].y;
                                w1=vecList10[z2].width;
                                h1=vecList10[z2].height;
                                cv::Rect rectT(p1,q1,w1,h1);//160 and 120
                                vecTotal.push_back(rectT);}

                             for(int z2=0;z2<vecList11.size();z2++){
                                p1=vecList11[z2].x;
                                q1=vecList11[z2].y;
                                w1=vecList11[z2].width;
                                h1=vecList11[z2].height;
                                cv::Rect rectT(p1,q1,w1,h1);//160 and 120
                                vecTotal.push_back(rectT);}

                             for(int z2=0;z2<vecList12.size();z2++){
                                p1=vecList12[z2].x;
                                q1=vecList12[z2].y;
                                w1=vecList12[z2].width;
                                h1=vecList12[z2].height;
                                cv::Rect rectT(p1,q1,w1,h1);//160 and 120
                                vecTotal.push_back(rectT);}

                             for(int z2=0;z2<vecList13.size();z2++){
                                p1=vecList13[z2].x;
                                q1=vecList13[z2].y;
                                w1=vecList13[z2].width;
                                h1=vecList13[z2].height;
                                cv::Rect rectT(p1,q1,w1,h1);//160 and 120
                                vecTotal.push_back(rectT);}

                             for(int z2=0;z2<vecList14.size();z2++){
                                p1=vecList14[z2].x;
                                q1=vecList14[z2].y;
                                w1=vecList14[z2].width;
                                h1=vecList14[z2].height;
                                cv::Rect rectT(p1,q1,w1,h1);//160 and 120
                                vecTotal.push_back(rectT);}

                             for(int z2=0;z2<vecList15.size();z2++){
                                p1=vecList15[z2].x;
                                q1=vecList15[z2].y;
                                w1=vecList15[z2].width;
                                h1=vecList15[z2].height;
                                cv::Rect rectT(p1,q1,w1,h1);//160 and 120
                                vecTotal.push_back(rectT);}

                              for(int z2=0;z2<vecList16.size();z2++){
                                p1=vecList16[z2].x;
                                q1=vecList16[z2].y;
                                w1=vecList16[z2].width;
                                h1=vecList16[z2].height;
                                cv::Rect rectT(p1,q1,w1,h1);//160 and 120
                                vecTotal.push_back(rectT);}

                             for(int z2=0;z2<vecList17.size();z2++){
                                p1=vecList17[z2].x;
                                q1=vecList17[z2].y;
                                w1=vecList17[z2].width;
                                h1=vecList17[z2].height;
                                cv::Rect rectT(p1,q1,w1,h1);//160 and 120
                                vecTotal.push_back(rectT);}

                             for(int z2=0;z2<vecList18.size();z2++){
                                p1=vecList18[z2].x;
                                q1=vecList18[z2].y;
                                w1=vecList18[z2].width;
                                h1=vecList18[z2].height;
                                cv::Rect rectT(p1,q1,w1,h1);//160 and 120
                                vecTotal.push_back(rectT);}

                             for(int z2=0;z2<vecList19.size();z2++){
                                p1=vecList19[z2].x;
                                q1=vecList19[z2].y;
                                w1=vecList19[z2].width;
                                h1=vecList19[z2].height;
                                cv::Rect rectT(p1,q1,w1,h1);//160 and 120
                                vecTotal.push_back(rectT);}

                             for(int z2=0;z2<vecList20.size();z2++){
                                p1=vecList20[z2].x;
                                q1=vecList20[z2].y;
                                w1=vecList20[z2].width;
                                h1=vecList20[z2].height;
                                cv::Rect rectT(p1,q1,w1,h1);//160 and 120
                                vecTotal.push_back(rectT);}
                                groupRectangles( vecTotal,1,0.6);
                        //p ,q ;
                        //int FF=F;
                        //CT++;
                        //while(0 < vecTotal.size()){
                        //int Xmaximo = 0;
                        //int Ymaximo = 0;
                        //int Xminimo = 640;
                        //int Yminimo = 480;
                        //int P =0;
                        //while(P< vecTotal.size()){
                        //if ((vecTotal[P].x) > Xmaximo ){
                        //Xmaximo = vecTotal[P].x;
                        //Ymaximo = vecTotal[P].y;
                        //int wm=vecTotal[P].width;
                        //int hm=vecTotal[P].height;}
                        //if ((vecTotal[P].x) < Xminimo) {
                        //Xminimo = vecTotal[P].x;}
                        //P++;
                        //}

                        //#pragma omp parallel for
                        //for(int z=0;z<vecTotal.size();z++){
                        //p=vecTotal[z].x;
                        //q=vecTotal[z].y;
                        //int w7=vecTotal[z].width;
                        //int h7=vecTotal[z].height;

                        //if( (abs((Xmaximo - p) < F*1 ) && (abs(Ymaximo - q) < F*1) ) &&  (((Xmaximo - p) != 0 ) && ((Ymaximo - q) != 0) ) ){
                        //vecTotal.erase(vecTotal.begin()+z);}
                        //if(((Xmaximo - p) == 0 ) && ((Ymaximo - q) == 0) ){
                        //vecTotal.erase(vecTotal.begin()+z);
                        //cv::Rect rectT(Xmaximo,Ymaximo,w7,h7);//160 and 120
                        //vecFinal.push_back(rectT);
                        //z=0;}
                        //}
                        //if ((vecTotal.size()==0) && (vecFinal.size() !=0)){
                       //for(int z=0;z<vecTotal.size();z++){
                       //int p=vecTotal[z].x;
                       //if ((vecTotal[z].y == vecTotal[z+1].y) && (vecTotal[z].height > vecTotal[z+1].height)){vecTotal.erase(vecTotal.begin()+z+1);}
                            //else if ((vecTotal[z].y == vecTotal[z+1].y) && (vecTotal[z].height < vecTotal[z+1].height)){vecTotal.erase(vecTotal.begin()+z);}

                       //}


                        for(int z=0;z<vecTotal.size();z++){
                        p=vecTotal[z].x;
                        q=vecTotal[z].y;
                        w=vecTotal[z].width;
                        h=vecTotal[z].height;
                        RotatedRect rRect1 = RotatedRect(Point2f(p+(80/restCold)/2,q+(80/restRowd)/2), Size2f(w*X,h*X), 0);
                        //160 and 120  e 160 and 120
                        brect1 = rRect1.boundingRect();
                        cv::rectangle(space, brect1, Scalar(0,0,255),0.25);

                        imshow("Detectado",space);
                        imwrite("/home/fabiano/My_Project/Centrist/Fotos_Rec/Humano.jpg",space);
                        waitKey(1);
                        }

                        if ((vecTotal.size()!=0)){return 1;}
                        else{return 0;}
                        //}

                      //}

                               }


return 0;

}



#endif //__Adaboost_H__
