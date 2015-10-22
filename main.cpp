
#include <omp.h>
#include "tbb/blocked_range.h"
#include "tbb/parallel_for.h"
#include "tbb/task_scheduler_init.h"



 #include <iostream>
 #include <sstream>
 #include <stdio.h>
 #include <cmath>

 #include <fstream>
 #include <string>
 #include <sstream>
 #include <cassert>
 #include <vector>
 #include <ml.h>


#include <boost/foreach.hpp>
#include <boost/tokenizer.hpp>


 #include "opencv2/core/core.hpp"
 #include "opencv2/core/opengl_interop.hpp"
 #include "opencv2/highgui/highgui.hpp"
 #include "opencv2/imgproc/imgproc.hpp"
 #include "opencv2/calib3d/calib3d.hpp"
 #include "opencv2/contrib/contrib.hpp"
 #include "Image_input.h"


 #include  "ClassifierHIK.h"
 #include "Ampl.h"
 #include "Adaboost.h"
 #include "Leg.h"
 #include "head.h"
 #include "arm.h"
 #include "Wind.h"
 #include "plot.h"
 #include "plot1.h"
 #define NUMBER_OF_CLASSES 2
 //#define USE_OPENCV_GRID_SEARCH_AUTOTRAIN 1  // set to 0 to set SVM parameters manually




using namespace std;
using namespace cv;
using namespace boost;
//float U = 0;
//float *result[255];


int main(int argc, char** argv)
{


Mat b,bb;
Mat Image;
Mat I,II;
Mat IC;
CvPoint aux1,aux2;
int i,j;
int y = 0;
float x= 0;
int S;
int R = 0;
int cl;
int C = 0;
int cmp_op;
Mat Sum;
Mat h,c;
Mat SOB;
int z;
Mat isum,isum2,isumT;
Mat IT,IT1;
Mat ImageCloneT;
Mat ImageCloneT2;
Rect brect1;
int CT = 0;
int F = 1;
float X ;
double Total=0.0;
int classe;
int NUMBER_OF_TESTING_SAMPLES = 0;
int false_[NUMBER_OF_CLASSES] = {0,0};
int true_positives[NUMBER_OF_CLASSES] = {0,0};

//int best_class = 0;
int correct_class = 0;
int wrong_class = 0;
int Lens = 0;
int W=0;
int V =0;
int count = 0;
double ACC;
//int count1 =0;
int Res = 1;
//float* FP_Value= new float[16];
double FP_Value[100];
double TP_Value[100];
double Precision[100];
double Recall[100];





std::vector<Rect> vecList;
std::vector<Rect> vecList1;
std::vector<Rect> vecList2;
std::vector<Rect> vecList3;
std::vector<Rect> vecList4;
std::vector<Rect> vecList5;
std::vector<Rect> vecList6;
std::vector<Rect> vecList7;
std::vector<Rect> vecList8;
std::vector<Rect> vecList9;
std::vector<Rect> vecList10;
std::vector<Rect> vecList11;
std::vector<Rect> vecList12;
std::vector<Rect> vecList13;
std::vector<Rect> vecList14;
std::vector<Rect> vecList15;
std::vector<Rect> vecList16;
std::vector<Rect> vecList17;
std::vector<Rect> vecList18;
std::vector<Rect> vecList19;
std::vector<Rect> vecList20;

std::vector<Rect> vecTotal;
std::vector<Rect> vecFinal;
std::vector<Rect> vecFinal1;

vecList.clear();
vecList1.clear();
vecList2.clear();
vecList3.clear();
vecList4.clear();
vecList5.clear();
vecList6.clear();
vecList7.clear();
vecList8.clear();
vecList9.clear();
vecList10.clear();
vecList11.clear();
vecList12.clear();
vecList13.clear();
vecList14.clear();
vecList15.clear();
vecList16.clear();
vecList17.clear();
vecList18.clear();
vecList19.clear();
vecList20.clear();

vecTotal.clear();
vecFinal.clear();
vecFinal1.clear();


CvBoost boost;
boost.load("CORPO_70%_boost.xml");

CvANN_MLP nnetworkC,nnetworkB,nnetworkL;
nnetworkC.load("NNT_CABEÇAS70%.xml");
nnetworkB.load("NNT_BRAÇOS70%.xml");
nnetworkL.load("NNT_PERNAS70%.xml");

CvDTree dtreeC;
CvDTree dtreeB;
CvDTree dtreeL;
dtreeC.load("Dtree_CABEÇAS70%.xml");
dtreeB.load("Dtree_BRAÇOS70%.xml");
dtreeL.load("Dtree_PERNAS70%.xml");

CvSVM svmC,svmB,svmL;
svmC.load("SVM_CABEÇAS70%A.xml");
svmB.load("SVM_BRAÇOS70%A.xml");
svmL.load("SVM_PERNAS70%.xml");





const char* modelfile ("/home/fabiano/My_Project/Centrist/Novos_modelos/merge_33%N_70%G.int.model");//("/home/fabiano/My_Project/Centrist/Novos_modelos/merge_S21.int.model");//


std::ifstream in(modelfile);
	if(in.good()==false)
	{
		std::cout<<"SVM model "<<modelfile<<" can not be loaded."<<std::endl;
        exit(-1);
	}
	std::string buffer;
	std::getline(in,buffer); // first line
	std::getline(in,buffer); // second line
	std::getline(in,buffer); // third line
	in>>buffer; assert(buffer=="nr_feature");
	int num_dim;
	in>>num_dim; //assert(num_dim>0 && num_dim==m);
	std::getline(in,buffer); // end of line 4
	in>>buffer; assert(buffer=="bias");
	int bias;
	in>>bias;
	std::getline(in,buffer); //end of line 5;
	in>>buffer; assert(buffer=="w");
	std::getline(in,buffer); //end of line 6
	//float valor;
	float *buff;
	buff = new float[num_dim];


//#pragma omp parallel for
	//vector<float> result;
	for(int i=0;i<num_dim;i++){
	    in >> buff[i];
	    //in >> *buff;
	    //*buff++;
	    //printf("buff= %f\n",buff[i]);
	}

	//in>>valor;
	//result.push_back(valor);}
	double rho = 0;
	//if(bias>=0) in>>rho;
	in>>rho;
	in.close();
	//return rho;



int R1=0;


// Load SVM models -- Histogram Intersectin Kernel SVM trained by libHIK

const char* modelfile1("/home/fabiano/My_Project/Centrist/Novos_modelos/mergeHIK_33%N_70%H.int.model");//("/home/fabiano/My_Project/Centrist/Novos_modelos/mergeHIK_S22.int.model");//

	std::ifstream inn(modelfile1);

	if(inn.good()==false)
	{
		std::cout<<"SVM model "<<modelfile1<<" can not be loaded."<<std::endl;
        exit(-1);
	}
	std::string buffer1;
	std::getline(inn,buffer1); // first line
	std::getline(inn,buffer1); // second line
	std::getline(inn,buffer1); // third linepass a dynamic array into a function by reference?
	inn>>buffer1; assert(buffer1=="nr_feature");
	int num_dim1;
	inn>>num_dim1; //assert(num_dim1>0 && num_dim1==m1);
	std::getline(inn,buffer1); // end of line 4
	inn>>buffer1; assert(buffer1=="bias");
	int bias1;
	inn>>bias1;
	std::getline(inn,buffer1); //end of line 5;
	inn>>buffer1; assert(buffer1=="w");
	std::getline(inn,buffer1); //end of line 6#pragma omp parallel for private(n_e

	int upper_bound = 255;
	float (*result)[upper_bound];



     result = (float (*)[upper_bound]) malloc(sizeof(float) * num_dim1 * upper_bound);
    if (result == NULL)
    {
    printf("Not enough memory!\n");
    }

	for(int i=0;i<num_dim1;i++){

		for(int j=0;j<upper_bound;j++){
		    //inn >> **result;
		    //*result++;
			inn>>result[i][j];
			float H = result[i][j];
			//printf("result %f\n",H);
            }}//R1++;
	double rho1 = 0;
	if(bias1>0)
	{
		inn>>rho1;
		inn>>rho1;
	}
	inn.close();
	std::cout<<"Rho = "<<"Carregando os classificadores....."<<std::endl;


        //double t = (double)getTickCount();
        // do something ...
        //t = ((double)getTickCount() - t)/getTickFrequency();
        //cout << "Times passed in seconds: " << t << endl;


//namedWindow( "Input", WINDOW_NORMAL);
//namedWindow("c",WINDOW_NORMAL);
//namedWindow("Integral",WINDOW_NORMAL);
//namedWindow("subMat",WINDOW_NORMAL);
//namedWindow("Detectdo",WINDOW_NORMAL);
//namedWindow("Montagem",WINDOW_NORMAL);



//double t = (double)getTickCount();

//There were the size of features from (120x160) to (80x80)
Mat A = Mat::zeros(80,80, CV_32F);
Mat A1= Mat::zeros(80,80, CV_32F);
Mat dst(80,80,CV_8UC1);
Mat dst1(80,80,CV_8UC1);


Mat ImageClone(80,80,CV_32F);
Mat ImageClone1(80,80,CV_32F);
Mat training_mat(80,80,CV_32F);//There were the size of features from (24x32) to (16x16)#@16x16
Mat training_HIK(80,80,CV_32F);//#@16x16



const char* listname =("Cenas_DE_Desastres.txt");//("fotos_b.txt");//("Fotos_Drone.txt");//(("Cenas_DE_Desastres.txt");////("Fotos_TEST2.txt");//("T_Test_Final.txt");/
string filename;
ifstream inp(listname);
inp >> filename;
int numfile = 0;
char * cstr = new char [filename.length()+1];
Mat*p=(NULL);
IplImage *img = NULL;



while (inp.good()) {

numfile++;
NUMBER_OF_TESTING_SAMPLES = numfile;

double t = (double)getTickCount();
strcpy (cstr, filename.c_str());
int v;

cout << filename;

string text = cstr;

char_separator<char> sep("I");
//char_separator<char> sep1(".jpg");// Deve-se mudar o tipo de formato da foto (.jpg , jpeg ou bmp)
char_separator<char> sep1(".jpg");
//char_separator<char> sep1(".bmp");

tokenizer< char_separator<char> > tokens(text, sep);
BOOST_FOREACH (const string& t, tokens) {
tokenizer< char_separator<char> > tokens(t, sep1);
BOOST_FOREACH (const string& t1, tokens){
v = atoi(t1.c_str());}}

float Valor = (float(v)/2);
if (int(Valor)==Valor){
    classe =1;}
 //cout << v << " é par" <<"classe ="<<classe<<endl;}
else {classe = 0;}
    //cout << v << " é impar" <<"classe="<<classe<<endl;}






//Carregar a imagem
IplImage *img ;
img = cvLoadImage(cstr , CV_LOAD_IMAGE_COLOR);
Mat b1 = img;

//imshow("B1",b1);
//waitKey(1);


int CT = 0;
int F = 1;
float X ;
//Rotina para achar o máximo e o minimo feature.
Mat imgTemp1;
float maximo = 0;
float minimo = 255;
int P =0;



//Mat b1 = imread("/home/fabiano/My_Project/Centrist/CT_FOTOS/d5.jpeg");//Fotos para teste final
//II = imread("/home/fabiano/My_Project/Centrist/FOTOS_CORPO/I1.jpg");
//II = imread("/home/fabiano/My_Project/Centrist/negative_images/0013.jpg");
//II= imread("/home/fabiano/My_Project/Centrist/b.bmp");



Size sizeF(300,200);
Size sizeG(200,300);
//resize(b1,II,sizeF);

float B2 = b1.cols;
float B3 = b1.rows;
float B4 = B2/B3;


//Redimensionamento da imagem de entrada.
if (B2>640){//320
if ((B4)>1){resize(b1,II,sizeF);}

 else if((B4)<1){resize(b1,II,sizeG);}}

 else {II =b1;}




b = Image_input(II,1);//II
//imshow("b",b);
//waitKey(1);


float Colb = (b.cols);
float Rowb = (b.rows);




int restColb = Colb/80;//ceil(Colb/80);
int restRowb = Rowb/80;//ceil(Rowb/80);



Size size(80,80);//There were the size of features from (160x120) to (80x80)
Mat space(restRowb*80,restColb*80, CV_8UC3, Scalar(0));//There were the size of features from (120x160) to (80x80)
Size size1(restColb*80,restRowb*80);
resize(II,Image,size1);
Rect roi( Point( 0, 0 ), Image.size() );//Rect
//Rect1 roi( Point( 0, 0 ), Image.size() );                                        //x – x-coordinate of the top-left corner.
                                        //y – y-coordinate of the top-left corner (sometimes bottom-left corner).
                                        //width – width of the rectangle.
                                        //height – height of the rectangle.

Image.copyTo(space( roi ) );



float Col = b.cols;
float Row = b.rows;
float val = float(Col/213);






float Cold = II.cols;//II
float Rowd = II.rows;//II
Mat E1,E_gray,Image1,imgTemp2,imgTemp3;
int ii,jj;

int restCold = Cold/80;//160
int restRowd = Rowd/80;//120
Size size3(80*restColb,80*restRowb);//160 and 120
resize(II,E1,size3);
cvtColor( E1, E_gray, CV_RGB2GRAY );
ImageCloneT = E_gray;
ImageCloneT2 = E_gray;



for (jj=0;jj+80 <= (restRowb*80);jj+=80)//120

{

   for (ii=0;ii+80 <= (restColb*80);ii+=80)//160

    {

        Image1 = E1(Rect(ii,jj,80,80));// 160 and 120
        imgTemp2 = Image_input(Image1,1);
        //imgTemp3 = Image_input(Image1,2);
        Rect roi( Point(ii,jj), imgTemp2.size() );
        //Rect roi1(Point(ii,jj), imgTemp3.size() );
        imgTemp2.copyTo(ImageCloneT( roi ) );
        //imgTemp3.copyTo(ImageCloneT2(roi1 ) );
        //imshow("Montagem",ImageCloneT);
        //waitKey(1);

    }

}

 //double t = (double)getTickCount();


//t = ((double)getTickCount() - t)/getTickFrequency();
    //cout << "Times passed in seconds: " << t << endl;
//Image total após a montagem.
//imwrite("/home/fabiano/My_Project/Centrist/Fotos_Rec/Centrist.jpg",ImageCloneT);
bb=ImageCloneT;
h=bb;


//if ((((h1.cols)>320)) && ((h1.rows)>240)){
    //Size sizeF((h1.cols)/2,(h1.rows)/2);
    //resize(h1,h,sizeF);
//}

//else {h=h1;}

//imshow("H",h);
//waitKey(10);

while(h.rows>=80 && h.cols>=80){// 120 and 160

   if (F==1){X=1;}
    else if(F>1){X=0.8;}//X= valor de redimencionamento das janelas de detecção


Row=Row*X;
Col=Col*X;


Size size9(Col,Row);
resize(bb,h,size9);


    for(j=2;(j+80) < (Row);j+=5)// j = passo de escaneamento da janela de detecção.
    {

        for(i=2;(i+80) < (Col);i+=5)// i= passo de escaneamento da janela  de detecção

        {



      c = h(Rect(i,j,80,80));//i and j are top and down left////There were the size of features from (160x120) to (80x80)


      integral(c,isum,CV_32F);
      Size size(80,80);//160 and 120
      resize(isum,IT,size);
      compare(IT,A,dst, CMP_NE);
      if (dst.at<uchar>(1,1) == 255)
      {


if ( ! c.isContinuous() )
    {c = c.clone();

//Imagem no formato 120x160 na região de interesse
//imshow("Input",c);
//waitKey(1);
//Rotina para achar o máximo e o minimo feature.
//Mat imgTemp1;
//float maximo = 0;
//float minimo = 255;
//int P =0;



//waitKey(1);

imgTemp1.push_back(c.reshape(0,1));

while(P<= num_dim){
 if ((imgTemp1.at<uchar>(0,P)) > maximo ){
        maximo = imgTemp1.at<uchar>(0,P);}
 if (((imgTemp1.at<uchar>(0,P)) < minimo) && (imgTemp1.at<uchar>(0,P) > 0)) {
        minimo = imgTemp1.at<uchar>(0,P);}
P++;
}

    }
//t = ((double)getTickCount() - t)/getTickFrequency();
    //cout << "Times passed in seconds: " << t << endl;

//Rotina para achar os valores dos coeficiente Lineares e HIk da imagem em análise

//double t = (double)getTickCount();


             int xx=0;
             int yy=0;
             int iii,jjj;
             Mat k;
             int m = 0;
             int BB = 0;
             float B = 0.0;
             uchar D =0;
             int R = 0;
             int O = 0;



        //for (iii=1;iii<= 5;iii++)#@
//{#@
    //for (jjj=1;jjj<= 5 ;jjj++)//6//#@

    //{#@
        //if(jjj > 1 && jjj< 6)#@
        //xx = xx + 16;//32#@

    //Size size(160,120);
    //resize(IT,k,size);//training_mat
    //Mat subMat = c(Rect(xx,yy,16,16));//32 and 24#@
    //imshow("subMat",subMat);
    //waitKey(10);

//f ( ! subMat.isContinuous() )#@
    //{subMat = subMat.clone();}#@


//uchar* pixel = NULL;
//float* pixel1 = NULL;
//float* pixel_H = NULL;

//#pragma omp parallel for
        for(int p = 0; p < c.rows; p++){//subMat

            //uchar* pixel = subMat.ptr<uchar>(p);  // point to first color in row
            //float* pixel1 = training_mat.ptr<float>(p);
            //float* pixel_H = training_HIK.ptr<float>(p);

//#pragma omp parallel for
        for(int q = 0; q < c.cols; q++){//subMat

             //D = *pixel++;
            // R = D;

            m++;
            D = (c.at<uchar>(p,q));
            R=D;

            if (R>=0){//R>=0 is necessary to ensure this matrice is complete.

          if ((m<num_dim) && (maximo > minimo)){
                 O++;
                //float B = (subMat.at<uchar>(p,q));
                 B = ((( (D)-minimo)/(maximo-minimo))*255);
                 //B = ((( (D)-minimo)/(maximo-minimo))*255);
                 BB = int(B);
                float L = buff[m];
                training_mat.at<float>(p,q) = B*L;
                //*pixel1 = B*L;
                float G = result[m][BB];
                training_HIK.at<float>(p,q) = G;
                //*pixel_H = G;
                //printf("m=%d: pixel1=%f: pixel_H=%f\n",m,*pixel1,pixel_H);
                //printf("O=%d:%f,%f\n",O,training_mat.at<float>(p,q),training_HIK.at<float>(p,q));
                //waitKey(10000);



        //printf("%d :%f \n",m*255,training_HIK.at<float>(p,q));
        }
        //*pixel++;
        //*pixel1++;
        //*pixel_H++;
            }

            }
        }



//t = ((double)getTickCount() - t)/getTickFrequency();
    //cout << "Times passed in seconds: " << t << endl;


//delete pixel;
//delete pixel1;
//delete pixel_H;


         ImageClone=training_mat;
         ImageClone1=training_HIK;

        //Rect roi( Point( xx, yy ), training_mat.size() );#@
        //training_mat.copyTo(ImageClone( roi ) );#@

        if ( ! ImageClone.isContinuous() )
            {
              ImageClone = ImageClone.clone();
             }




        //Rect roi1( Point( xx, yy ), training_HIK.size() );#@
        //training_HIK.copyTo(ImageClone1( roi1 ) );#@


        if ( ! ImageClone1.isContinuous() )
            {
              ImageClone1= ImageClone1.clone();
            }



     //if(jjj == 5 && iii == 1)//6#@
     //xx = yy = 0;#@
     //if(jjj == 5 && iii > 1)//6#@
     //xx = 0;#@

    //}#@
    //yy = yy + 16;//24#@

//}#@



              integral(ImageClone,isum,CV_32F);
              resize(isum,IT,size);
              Scalar FT = sum(IT);
              float IimagT=(FT.val[0])/1000;




              //imshow("Integral",IT);
              //char* window_name = "ImageClone";
              //namedWindow( window_name, WINDOW_NORMAL);
              //imshow("ImageClone",ImageClone);


              xx=0;
              yy=0;
              iii,jjj;
              k;
              float T=0;
              float U=0;
              int p, q;
               R=25;
               T= IimagT;

               //printf("%e\n",T);//U*0.00000438799,R);
               //waitKey(100);

             //for (iii=1;iii<= 5;iii++)#@
//{#@

    //for (jjj=1;jjj<= 5 ;jjj++)//6#@

    //{#@
        //if(jjj > 1 && jjj< 6)#@
        //xx = xx + 16;//32#@

    //Size size(80,80);//160 and 120#@
    //resize(ImageClone,k,size);#@
   //Mat subMat = k(Rect(xx,yy,16,16));// 32 and 24#@



    //if ( ! subMat.isContinuous() )#@
    //{subMat = subMat.clone();}#@




//Scalar s = cv::sum(k).val[0];

    //imshow("PATH",subMat);
    //waitKey(10);

//float* pixel = NULL;


  //cv::MatConstIterator_<uchar> p;
  //cv::MatConstIterator_<float> q;
  //float q,U;

//for(p=subMat.begin<uchar>();p!=subMat.end<uchar>();p++){
//q = *p;
//U += q;}

//#pragma omp parallel for

        //for( p = 0; p < subMat.rows; p++){#@
            //float* pixel = subMat.ptr<float>(p);  // point to first color in row

            //float* pixel1 = training_mat.ptr<float>(p);
            //float* pixel_H = training_HIK.ptr<float>(p);

//#pragma omp parallel for

        //for( q = 0; q < subMat.cols; q++){#@

           //float D = (subMat.at<float>(p,q));#@
            //if (D!=0.0){
            //float D = *pixel++;

            //if (D!=0.0){#@

        //U+= (*pixel++);}
        //U+=D;}#@
            //}#@
        //}#@




        //delete pixel;


        //R++;#@
        //T+= U;#@
         //Printf para acompanhar os valores em todas as escalas.
        //printf("%f :%d :%f :%f :%e :%e\n",X,R,U,T,D,IimagT);//U*0.00000438799,R);
        //waitKey(100);
        if (R==25){//30

        //if (T>=3.0){ z = Adaboost(c,boost);//to use with Adaboost classifier
        if (T>=3.0){ z = ClassifierHIK(ImageClone1);//to use with SVM-HIK classifier//48//threshold = 11 com sobel =0.018 e hik =35
        if (z == 1){
            float R,C;
            if (Cold>Rowd){C=1,R=0.9;}
            else {R=1,C=0.9;}
            int FF=F;
            cv::Rect rect(i/pow(X,FF-1),j/pow(X,FF-1),C*(80/pow(X,FF-1)),R*(80/pow(X,FF-1))+0);//160 and 120
            int w = 1;//1
            switch (w)
        {
            case 1:vecList.push_back(rect);
                break;
            case 2:vecList1.push_back(rect);
                break;
            case 3:vecList2.push_back(rect);
                break;
            case 4:vecList3.push_back(rect);
                break;
            case 5:vecList4.push_back(rect);
                break;
            case 6:vecList5.push_back(rect);
                break;
            case 7:vecList6.push_back(rect);
                break;
            case 8:vecList7.push_back(rect);
                break;
            case 9:vecList8.push_back(rect);
                break;
            case 10:vecList9.push_back(rect);
                break;
            case 11:vecList10.push_back(rect);
                break;
            case 12:vecList11.push_back(rect);
                break;
            case 13:vecList12.push_back(rect);
                break;
            case 14:vecList13.push_back(rect);
                break;
            case 15:vecList14.push_back(rect);
                break;
            case 16:vecList15.push_back(rect);
                break;
            case 17:vecList16.push_back(rect);
                break;
            case 18:vecList17.push_back(rect);
                break;
            case 19:vecList18.push_back(rect);
                break;
            case 20:vecList19.push_back(rect);
                break;
            case 21:vecList20.push_back(rect);
                break;
            default: cout << "qwerty";
            break;
        }


        }
        else {W=0;}}
        else {W =2;}}


    //cc.push_back(subMat.reshape(0,1)); //0 makes channel unchanged and 1 makes single row

     //if(jjj == 5 && iii == 1)//6#@
     //xx = yy = 0;#@
     //if(jjj == 5 && iii > 1)//6#@
     //xx = 0;#@

    //}#@
    //yy = yy + 16;//24#@


    //}#@

}

}


 }

int FFF=1;
      W = wind(X,F,h,space,roi,vecList,vecList1,vecList2,vecList3,vecList4,vecList5,vecList6,vecList7,vecList8,vecList9,vecList10,vecList11,vecList12,vecList13,vecList14,vecList15,vecList16,vecList17,vecList18,vecList19,vecList20);


F++;


    //waitKey(100);
      //}
}
    //}



    for (jj=0;jj+80 <= (restRowb*80);jj+=80)//120

{

   for (ii=0;ii+80 <= (restColb*80);ii+=80)//160

    {

        Image1 = E1(Rect(ii,jj,80,80));// 160 and 120
        //imgTemp2 = Image_input(Image1,1);
        imgTemp3 = Image_input(Image1,1.0);
        //Rect roi( Point(ii,jj), imgTemp2.size() );
        Rect roi1(Point(ii,jj), imgTemp3.size() );
        //imgTemp2.copyTo(ImageCloneT( roi ) );
        imgTemp3.copyTo(ImageCloneT2(roi1 ) );
        //imshow("Montagem2",ImageCloneT2);
        //waitKey(1);

    }

}


 Mat b7 = ImageCloneT2;

  //if ((h.rows<=80 || h.cols<=80) && (vecList.size()== 0) && (vecList1.size()==0) && (vecList2.size()== 0) && (vecList3.size() == 0) && (vecList4.size() == 0) && (vecList5.size() == 0) && (W==0) )
  if ((h.rows<=80 || h.cols<=80) && (W==0) )
  { Lens = Ampl(II,b7,h,nnetworkC,nnetworkB,nnetworkL,dtreeC,dtreeB,dtreeL,svmC,svmB,svmL);}


 if (((W == 0) && (Lens == 1)||(W == 1))){ Res =1;}
   else {Res=0;}

int Resultado = classe-Res;
//cout << "W ="<<W<<"Lens = "<<Lens<<"Classe ="<<classe<<"Res ="<<Res<<"Resultado"<<Resultado<<" ";

 count ++;
 if ((classe - Res)!=0)
            {
                // if they differ more than floating point error => wrong class

                cout<<"Wrong Classification"<<" ";
                wrong_class++;
                false_[classe]++;
                //false_negative -> false_positives[0] é equivalente a dizer que não há pessoas na imagem, porém há.
            }

            else
            {
                // otherwise correct
                correct_class++;
                cout<<"Correct Classification"<<" ";
                //true_negative -> true_positive [0] é equivalente a dizer que não há pessoas na imagem e realmente não há.
                true_positives[classe]++;


            }

                if (count == 10){

             for (int i = 0; i < NUMBER_OF_CLASSES; i++)
                {
                     FP_Value[V]=(double) false_[1]/(false_[1]+true_positives[0]);

                     //cout<<"FP="<<(double) false_positives[classe]/NUMBER_OF_TESTING_SAMPLES;
                     TP_Value[V]=(double) true_positives[1]/(true_positives[1]+false_[0]);

                     //Precision & Recall calculado para a detecção positiva de pessoas.
                     Recall[V]=(double) true_positives[1]/(true_positives[1]+false_[1]);
                     Precision[V]=(double) true_positives[1]/(true_positives[1]+false_[0]);
                     //ACC=(double) (true_positives[1]+true_positives[0])/(true_positives[1]+true_positives[0])+(false_positives[1]+false_positives[0]);
                     //cout<<"TP="<<(double) true_positives[classe]/NUMBER_OF_TESTING_SAMPLES;
                     //cout<<"Calculo de FP = "<<FP_Value[V]<<"\n"<<"Calculo de TP = "<<TP_Value[V]<<"\n"<<"Precision = "<<Precision[V]<<"\n"<<"Recall = "<<Recall[V];
                     V++;
                     count = 0;
                }
                                }
      //t = (double)getTickCount();
        // do something ...
    t = ((double)getTickCount() - t)/getTickFrequency();
    Total = Total + t;
    cout << "Time passed: " << t << " seg"<<endl;


vecList.clear();
vecList1.clear();
vecList2.clear();
vecList3.clear();
vecList4.clear();
vecList5.clear();
vecList6.clear();
vecList7.clear();
vecList8.clear();
vecList9.clear();
vecList10.clear();
vecList11.clear();
vecList12.clear();
vecList13.clear();
vecList14.clear();
vecList15.clear();
vecList16.clear();
vecList17.clear();
vecList18.clear();
vecList19.clear();
vecList20.clear();

vecTotal.clear();
vecFinal.clear();
vecFinal1.clear();



            inp >> filename;


        }

    in.close();

    int P = plot(FP_Value,TP_Value,Precision,Recall);
    int PP = plot1(Precision,Recall);

    printf( "\nResults on the testing database: %s\n"
                "\tCorrect classification: %d (%g%%)\n"
                "\tWrong classifications: %d (%g%%)\n"
                 "\tTotal de imagens analisadas: %d\n"
                  "\tTempo total decorrido:(%g) seg \n"
                  "\t Média (Tempo Total/Imagens):(%g) seg \n",

                "RESULTADOS:",
                correct_class, (double) correct_class*100/NUMBER_OF_TESTING_SAMPLES,
                wrong_class, (double) wrong_class*100/NUMBER_OF_TESTING_SAMPLES,
                numfile,Total,(double)Total/numfile);

        for (int i = 0; i < NUMBER_OF_CLASSES; i++)
        {
            printf( "\tClass (digit %d) false postives 	%d (%g%%)\n", i,
                    false_[i],
                    (double) false_[i]*100/NUMBER_OF_TESTING_SAMPLES);
            printf( "\tClass (digit %d) true postives 	%d (%g%%)\n", i,
                    true_positives[i],
                    (double) true_positives[i]*100/NUMBER_OF_TESTING_SAMPLES);
        }

            printf( "\tClass (digit %d) Recall  (%g%%)\n", 1,
                     Recall[V]=(double) true_positives[1]*100/(true_positives[1]+false_[1]));

            printf( "\tClass (digit %d) Precision  (%g%%)\n", 1,
                  Precision[V]=(double) true_positives[1]*100/(true_positives[1]+false_[0]));



    //cout << "TEMPO TOTAL = "<<Total<<" COM  "<<numfile<<"  IMAGENS";
    delete[]buff;
    buff = NULL;
    delete[]result;
    result = NULL;


}
