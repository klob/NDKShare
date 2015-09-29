//
// Created by klob on 2015/9/12.
//
#include "util.h"
#include "common.h"

void invoke_int(JNIEnv *env, jobject obj, char *class_name, char *method, char *signature, int i) {
    jclass obj_class = (*env)->FindClass(env, class_name);
    //再找类中的方法
    jmethodID mid = (*env)->GetMethodID(env, obj_class, method, signature);
    if (mid == NULL) {
        LOGE("int error");
        return;
    }
    //打印接收到的数据
    LOGI("invoke_int  param %d ", i);

    LOGI("call method %s/%s", class_name, method);

    (*env)->DeleteLocalRef(env,obj_class);
    //回调java中的方法
    (*env)->CallVoidMethod(env, obj, mid, i);

};

jobject invoke_str(JNIEnv *env, jobject obj , char *method, char *signature,const char *str,...) {
    jclass obj_class = (*env)->GetObjectClass(env, obj);
    //再找类中的方法
    jmethodID mid = (*env)->GetMethodID(env, obj_class, method, signature);
    if (mid == NULL) {
        LOGE("int error");
        return "";
    }

    //打印接收到的数据
 /*   va_list ap;

    char buf[BUF_SIZE];
    va_start(ap, str);
    vsnprintf(buf, BUF_SIZE, str, ap);

    va_end(ap);*/


    LOGI("call method %s/%s", get_class_name(env,obj), method);
    (*env)->DeleteLocalRef(env,obj_class);
    //回调java中的方法
    return    (*env)->CallObjectMethod(env, obj, mid,str);


};


jobject invoke_static_str(JNIEnv *env, char *class_name , char *method, char *signature,const char *str,...)
 {
    jclass obj_class = (*env)->FindClass(env, class_name);
    //再找类中的方法
    jmethodID mid = (*env)->GetStaticMethodID(env, obj_class, method, signature);
    if (mid == NULL) {
        LOGE("int error");
        return "";
    }

    //打印接收到的数据
    /*   va_list ap;

       char buf[BUF_SIZE];
       va_start(ap, str);
       vsnprintf(buf, BUF_SIZE, str, ap);

       va_end(ap);*/


   // LOGI("call method %s/%s", get_class_name(env,obj), method);
    //回调java中的方法
    return    (*env)->CallStaticObjectMethod(env, obj_class, mid,str);


};

char * get_class_name (JNIEnv  *env,jobject clz)
{
    jclass obj_class = (*env)->GetObjectClass(env, clz);
    //再找类中的方法
    jmethodID mid = (*env)->GetMethodID(env, obj_class, "toString", "()Ljava/lang/String;");
    if (mid == NULL) {
        LOGI("int error");
        return "";
    }
    (*env)->DeleteLocalRef(env,obj_class);
    return jstrToChar(env, (*env)->CallObjectMethod(env, clz, mid));
}

