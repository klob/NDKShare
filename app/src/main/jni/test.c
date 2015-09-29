//
// Created by klob on 2015/9/29.
//

#include "test.h"
#include "util.h"
#include "common.h"

JNIEXPORT void JNICALL Java_com_diandi_klob_ndkshare_Engine_callJNIInt
        (JNIEnv * env, jobject obj, jint i)
{

    //找到java中的类
    jclass cls = (*env)->FindClass(env, "com/diandi/klob/ndkshare/Engine");
    //再找类中的方法
    jmethodID mid = (*env)->GetMethodID(env, cls, "callbackInt", "(I)V");
    if (mid == NULL) {
        LOGI("int error");
        return;
    }
    //打印接收到的数据
    LOGI("from java int: %d", i);
    //回调java中的方法
    (*env)->CallVoidMethod(env, obj, mid, i);
};


/*
 * Class:     com_diandi_klob_ndkshare_Engine
 * Method:    callJNIString
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_diandi_klob_ndkshare_Engine_callJNIString
        (JNIEnv * env, jobject jobject1, jstring s){
    //找到java中的类
    jclass cls = (*env)->FindClass(env, "com/diandi/klob/ndkshare/Engine");
    //再找类中的方法
    jmethodID mid = (*env)->GetMethodID(env, cls, "callbackString", "(Ljava/lang/String;)V");
    if (mid == NULL) {
        LOGI("string error");
        return;
    }
    const char *ch;
    //获取由java传过来的字符串

    ch = (*env)->GetStringUTFChars(env, s, NULL);
    (*env)->ReleaseStringUTFChars(env, s, ch);
    //回调java中的方法
    (*env)->CallVoidMethod(env, jobject1, mid, (*env)->NewStringUTF(env, "你好haha"));

};

/*
 * Class:     com_diandi_klob_ndkshare_Engine
 * Method:    md5
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_diandi_klob_ndkshare_Engine_md5
        (JNIEnv * env, jobject jobject1, jstring strText){
    jstring md5 = invoke_static_str(env, "com/diandi/klob/ndkshare/MD5", "MD5",
                                    "(Ljava/lang/String;)"
                                            "Ljava/lang/String;", strText);
    return md5;

};

/*
 * Class:     com_diandi_klob_ndkshare_Engine
 * Method:    test3
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_diandi_klob_ndkshare_Engine_test3
        (JNIEnv * env, jobject jobject1){

};

/*
 * Class:     com_diandi_klob_ndkshare_Engine
 * Method:    test4
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_diandi_klob_ndkshare_Engine_test4
        (JNIEnv * env, jobject jobject1){

};
