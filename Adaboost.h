
#ifndef __Adaboost_H__
#define __Adaboost_H__



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




int  Adaboost(Mat &c,CvBoost &boost)
{

int z;
int xx=0;
int R=0;
int yy=0;
int iii,jjj;
Mat k;
float T=0;
float U = 0;
Mat A1 = Mat::zeros(16,16, CV_32F);
Mat dst1(16,16,CV_8UC1);



//CvBoost boost;


//boost.load("trained_boost2.xml");

Mat testing_data = Mat(1,1102, CV_32FC1);


float value;
Mat imgTemp1;
float maximo = 0;
float minimo = 255;
int P =0;
int attribute =0;




 imgTemp1.push_back(c.reshape(0,1));

while(P<= imgTemp1.cols){
 if ((imgTemp1.at<uchar>(0,P)) > maximo ){
        maximo = imgTemp1.at<uchar>(0,P);}
 if (((imgTemp1.at<uchar>(0,P)) < minimo) && (imgTemp1.at<uchar>(0,P) > 0)) {
        minimo = imgTemp1.at<uchar>(0,P);}
P++;
}





                for (iii=1;iii<= 5;iii++)
                {
                    for (jjj=1;jjj<= 5 ;jjj++)

                    {
                        if(jjj > 1 && jjj< 6)
                        xx = xx + 16;

                        //Size size(160,120);
                        //resize(IT,k,size);//training_mat
                        Mat subMat = c(Rect(xx,yy,16,16));
                        //imshow("subMat",c);
                        //waitKey(10);

                        if ( ! subMat.isContinuous() )
                        {subMat = subMat.clone();}
                        // first 64 elements (0-63) in each line are the attributes

                        for(int p = 0; p < subMat.rows; p++){


                        //#pragma omp parallel for
                        for(int q = 0; q < subMat.cols; q++){


                        if ((subMat.at<uchar>(p,q)>0)) {
                        value = ((((subMat.at<uchar>(p,q))-minimo)/(maximo-minimo))*255);
                        if (attribute<1101){
                            if ((iii<= 5)&&(jjj<=6)&&(attribute<1101)){
                                for(int x=attribute;x<1102;x++){
                                 testing_data.at<float>(0,x) = 0.0;} }
                        testing_data.at<float>(0, attribute) = value;
                        //printf("Linha=%d Valor=%f\n",attribute,testing_data.at<float>(0, attribute));
                        attribute++;
                        if (attribute==1101){
                        testing_data.at<float>(0, 1101) = 0.0;
                        //printf("Linha=%d Valor=%f\n",attribute,testing_data.at<float>(0, 2119));
                        }}}
                            }

                        }


        if(jjj == 5 && iii == 1)
        xx = yy = 0;
        if(jjj == 5 && iii > 1)
        xx = 0;

        }
        yy = yy + 16;

    }



        float x7 = boost.predict(testing_data,Mat(),Range::all(),false,false);
        //cout<<"Sample = "<< line << "  Resultado = "<< x <<"\n";
        if (x7==0) { return(z=1);}








}



#endif //__Adaboost_H__
