#include <jni.h>
#include <string>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

extern "C" {

//入力されたMatのタイプを返している
JNIEXPORT jstring JNICALL
Java_com_wrongwrong_opencv4androidsample_MainActivity_MatTest1(
        JNIEnv *env,
        jobject instance,
        jlong inputAddr
) {
    Mat &input = *(Mat *) inputAddr;

    stringstream ss;
    ss << input.type();

    return env->NewStringUTF(ss.str().c_str());
}

//自分の環境で試したところ、入ってくるMatのタイプは24(CV8U4C)だった
//ここではそのrgbaのうちrを0にしている
//アドレスでやり取りしているため、voidで何も返却せずにMatの内容を操作できる
JNIEXPORT void JNICALL
Java_com_wrongwrong_opencv4androidsample_MainActivity_MatTest2(
        JNIEnv *env,
        jobject instance,
        jlong inputAddr
) {
    Mat &input = *(Mat *) inputAddr;

    input.forEach<Vec4b>([](Vec4b &p, const int *position) -> void {
        p[0] = 0;
    });
}

}