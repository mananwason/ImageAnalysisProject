extern "C"{
#include <vl/generic.h>
#include <vl/stringop.h>
#include <vl/pgm.h>
#include <vl/sift.h>
#include <vl/getopt_long.h>
};

#include <dirent.h>

#include <stdio.h>
//#include <tchar.h>
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//#pragma comment(lib, "opencv_core230d.lib")
//#pragma comment(lib, "opencv_imgproc230d.lib")
//#pragma comment(lib, "opencv_highgui230d.lib")
//#pragma comment(lib, "opencv_objdetect230d.lib")
using namespace cv;
using namespace std;


extern "C"{
#include <vl/dsift.h>
#include <vl/generic.h>
#include <vl/stringop.h>
#include <vl/pgm.h>
#include <vl/sift.h>
#include <vl/getopt_long.h>
};

void medianfilter(Mat mat){
    int min=0;
    int filtersize=3;

//    for (int i=0;i<Image->height;i++)
//    {
//        for (int j=0;j<Image->width;j++)
    int drawfilter;
    for(int i=0;i<mat.rows;i++){
        for(int j=0;j<mat.cols;j++){
            filtersize=min*filtersize+filtersize;
        }
    }
//        {
//            Pixel=(unsigned char*)(Image->imageData+i*Image->width+j);
//            ImageData[i*Image->width+j]=*(Pixel);
//        }
//    }
//    VlSiftFilt *SiftFilt=NULL;
//    VlDsiftFilter *dsiftFilter=NULL;
//    SiftFilt=vl_sift_new(Image->width,Image->height,noctaves,nlevels,o_min);
//    dsiftFilter=vl_dsift_new(Image->width,Image->height);
    return ;
}
//
//int _main(int argc, char * argv[])
//{
//    VL_PRINT ("Hello world!\n") ;
//    char *ImagePath= (char *) "/Users/tgz/Desktop/Wrinkles.jpg";
//    IplImage *Image=cvLoadImage(ImagePath,0);
//    // int min=0;
//    // min=Image->width>Image->height?Image->height:Image->width;
//    int noctaves=4,nlevels=2,o_min=0;
//    // noctaves=(int)(log(min)/log(2));
//    float *ImageData=new float[Image->height*Image->width];
//    unsigned char *Pixel;
//    for (int i=0;i<Image->height;i++)
//    {
//        for (int j=0;j<Image->width;j++)
//        {
//            Pixel=(unsigned char*)(Image->imageData+i*Image->width+j);
//            ImageData[i*Image->width+j]=*(Pixel);
//        }
//    }
//    VlSiftFilt *SiftFilt=NULL;
//    VlDsiftFilter *dsiftFilter=NULL;
//    SiftFilt=vl_sift_new(Image->width,Image->height,noctaves,nlevels,o_min);
//    dsiftFilter=vl_dsift_new(Image->width,Image->height);
//    int KeyPoint=0;
//    int idx=0;
//    vl_dsift_process(dsiftFilter,ImageData);
//    int num=vl_dsift_get_keypoint_num(dsiftFilter);
//    cout<<num<<" ";
//    const VlDsiftKeypoint *keypoints = vl_dsift_get_keypoints(dsiftFilter);
//    for(int i=0; i<num; i++){
//        const VlDsiftKeypoint TemptKeyPoint = keypoints[i];
//        cvDrawCircle(Image,cvPoint(TemptKeyPoint.x,TemptKeyPoint.y),TemptKeyPoint.norm/2,CV_RGB(255,0,0));
//    }
//
////    if (vl_sift_process_first_octave(SiftFilt,ImageData)!=VL_ERR_EOF)
////    {
////        while (true)
////        {
////
////            vl_sift_detect(SiftFilt);
////            KeyPoint+=SiftFilt->nkeys;
//            VlSiftKeypoint *pKeyPoint=SiftFilt->keys;
////            for (int i=0;i<SiftFilt->nkeys;i++)
////            {
////                VlSiftKeypoint TemptKeyPoint=*pKeyPoint;
////                pKeyPoint++;
////                cvDrawCircle(Image,cvPoint(TemptKeyPoint.x,TemptKeyPoint.y),TemptKeyPoint.sigma/2,CV_RGB(255,0,0));
////                idx++;
////
////                double angles[4];
////                int angleCount=vl_sift_calc_keypoint_orientations(SiftFilt,angles,&TemptKeyPoint);
////                for (int j=0;j<angleCount;j++)
////                {
////                    double TemptAngle=angles[j];
////                    printf("%d: %f\n",j,TemptAngle);
////                    float *Descriptors=new float[128];
////                    vl_sift_calc_keypoint_descriptor(SiftFilt,Descriptors,&TemptKeyPoint,TemptAngle);
////                    int k=0;
////                    while (k<128)
////                    {
////                        printf("%d: %f",k,Descriptors[k]);
////                        printf("; ");
////                        k++;
////                    }
////                    printf("\n");
////                    delete []Descriptors;
////                    Descriptors=NULL;
////                }
////            }
////            if (vl_sift_process_next_octave(SiftFilt)==VL_ERR_EOF)
////            {
////                break;
////            }
//////free(pKeyPoint);
////            KeyPoint=NULL;
////        }
////    }
//
//    float const * descp = vl_dsift_get_descriptors(dsiftFilter);
//    int siz = vl_dsift_get_descriptor_size(dsiftFilter);
//    VlDsiftDescriptorGeometry const* geo = vl_dsift_get_geometry(dsiftFilter);
//    cout<<siz<<" "<<geo->numBinX<<" "<<geo->numBinY<<"\n";
//    cv::Mat a(geo->numBinY,geo->numBinX,CV_8UC1);
//    for(int i=0; i<128*num; i++){
//        //cout<<descp[i]<<"\n";
//    }
//    vl_sift_delete(SiftFilt);
//    vl_dsift_delete(dsiftFilter);
//    delete []ImageData;
//    ImageData=NULL;
//    cvNamedWindow("Source Image",1);
//    cvShowImage("Source Image",Image);
//    cvWaitKey(0);
//    cvReleaseImage(&Image);
//    cvDestroyAllWindows();
//    return 0;
//}

#include <map>
map<int, string> labelMap;

vector<float> getDescriptor(Mat img, string msg);

void enhance(Mat mat);

vector<int> labels;
vector< vector<float> > data;
Mat *labelsMat;
Mat *trainingMat;
int main(int argc, char * argv[]){
    string trainDir, testDir;

    cv::Size sz(250, 100);
    if(argc != 3){
        cerr<<"Please specify training directory and test directory\n";
        cout << argv[2]<<"\n";
        perror("");
        return EXIT_FAILURE;
    }else{
        trainDir = argv[1];
        testDir = argv[2];

        DIR* mainDir;
        DIR* curDir;

        struct dirent* ent;
        struct dirent* trainImg;


        data.clear();
        labels.clear();
        if((mainDir = opendir(trainDir.c_str())) != NULL){
            int labelNum = 1;

            while((ent = readdir(mainDir)) != NULL){
                Mat image;
                if(ent->d_name[0] != '.'){
                    string cur = trainDir;
                    cur.append("/").append(ent->d_name);
                    int curLabel = labelNum++;
                    labelMap[curLabel] = (string)ent->d_name;
                    if((curDir = opendir(cur.c_str())) != NULL){
                        while((trainImg = readdir(curDir)) != NULL){
                            cout<<trainImg->d_name<<" "<<cur.c_str()<<" reading dir!!!\n";
                            if(trainImg->d_name[0] != '.'){
                                string imgPath = cur;
                                imgPath.append("/").append(trainImg->d_name);
                                cout<<imgPath<<" reading image!!!\n";
                                Mat img = imread(imgPath, CV_LOAD_IMAGE_GRAYSCALE);
                                enhance(img);
                                resize(img, img, sz);
                                data.push_back(getDescriptor(img, imgPath.append(" getting descriptor.\n")));
                                labels.push_back(curLabel);
                            }
                        }
                    }
                }
            }
        }
        int n = data.size();
        assert(n != 1);

        int descSize = data[0].size();

        assert(labels.size() == n);
        float* trainingData = new float[n*descSize];
//        int* labelData = new int[n];
//
//        for(int i=0; i < n; ++i){labelData[i] = labels[i];}
        // for(int i=0; i < n; ++i){trainingData[i] = new float[descSize];}
        int p=0;
        for(int i=0; i < n; ++i){
            assert(data[i].size() == descSize);
            for(int j=0; j < data[i].size(); ++j){
                trainingData[p++] = data[i][j];
            }
        }
        cout<<"training starting "<<n<<" "<<n * descSize<<"\n";
        labelsMat = new Mat(n, 1, CV_32S, &labels[0]);
        trainingMat= new Mat(n, descSize, CV_32FC1, trainingData);
        cout<<"training starting";
        Ptr<ml::SVM> svm = ml::SVM::create();
        svm->setType(ml::SVM::C_SVC);
        svm->setKernel(ml::SVM::LINEAR);
        svm->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 100, 1e-6));

        svm->train(*trainingMat, ml::ROW_SAMPLE, *labelsMat);
        cout<<"Training Done!!!";

        delete labelsMat;
        delete trainingMat;
        delete trainingData;
//        delete labelData;

        // trainDir = argv[1];
        // testDir = argv[2];

        // DIR* mainDir;
        // DIR* curDir;

        // struct dirent* ent;
        // struct dirent* trainImg;


        data.clear();
        labels.clear();
        if((mainDir = opendir(testDir.c_str())) != NULL){
            int labelNum = 1;

            while((ent = readdir(mainDir)) != NULL){
                Mat image;
                if(ent->d_name[0] != '.'){
                    string cur = testDir;
                    cur.append("/").append(ent->d_name);
                    int curLabel = labelNum++;
                    //labelMap[curLabel] = cur;
                    int cD = atoi(ent->d_name);
                    float tot = 0;
                    float cnt = 0;
                    if((curDir = opendir(cur.c_str())) != NULL){
                        cout<<cur<<"----\n";
                        while((trainImg = readdir(curDir)) != NULL){
                            if(trainImg->d_name[0] != '.'){
                                string imgPath = cur;
                                imgPath.append("/").append(trainImg->d_name);
                                //cout<<imgPath<<"\n";
                                Mat img = imread(imgPath, CV_LOAD_IMAGE_GRAYSCALE);
                                resize(img, img, sz);
                                //cout<<imgPath;
                                int lbl = svm->predict(getDescriptor(img, imgPath));
                                //string a=testDir;
                              //  cerr<<imgPath<<" "<<labelMap[lbl]<<" "<<lbl<<"\n";
                                if(cD == atoi(labelMap[lbl].c_str()))cnt+=1;
                                tot += 1;
                                //cout<<imgPath<<" - "<<labelMap[lbl]<<"\n";
//                                if(lbl == 1){
//                                    a.append("REJECTED!_!");
//                                }else if(lbl == 2){
//                                    a.append("../").append(ent->d_name);
//                                    a.append(trainImg->d_name);
//                                    imwrite(a.c_str(), img);
//                                }
//                                cout<<a<<"\n";
                                //a.append(trainImg->d_name);
                                //imwrite(a.c_str(), img);
                            }
                        }
                        if(cnt/tot > 0.5)puts("Yes"); else puts("No");
//                        cerr<<cnt<<" "<<tot<<" "<<cD<<"\n";
                    }
                }
            }
        }
    }
    cout<<"label = 1 > "<<labelMap[1];
    cout<<"label = 2 > "<<labelMap[2];
    return 0;
}

void enhance(Mat mat) {
    medianfilter(mat);
}


vector<float> getDescriptor(Mat img, string msg){
    //VL_PRINT(msg.c_str());
    float* imgData = new float[img.rows*img.cols];
    uchar *p = img.data;
    for(int i=0; i < img.rows * img.cols; ++i){
        imgData[i] = (float)p[i];
    }
    //TODO implemenet for3 channel
    //for(int r=0; r<img.rows; r++){
    //  for(int c=0; c<img.cols; c++){



    VlDsiftFilter* dsiftFilter = NULL;
    dsiftFilter = vl_dsift_new(img.cols, img.rows);
    // process the dsift
    vl_dsift_process(dsiftFilter, imgData);

    const VlDsiftKeypoint *keypoints = vl_dsift_get_keypoints(dsiftFilter);
    float const * descp = vl_dsift_get_descriptors(dsiftFilter);

    int dsize = vl_dsift_get_descriptor_size(dsiftFilter);
    int numPoints = vl_dsift_get_keypoint_num(dsiftFilter);

    vector<float> output;
    output.clear();

    for(int i=0; i < numPoints * dsize; ++i){
        output.push_back(descp[i]);
    }

    //delete heap memory!!
    vl_dsift_delete(dsiftFilter);
    delete []imgData;

    //VL_PRINT("ended!\n");
    return output;
}


