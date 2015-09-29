//
// Created by klob on 2015/9/12.
//

#ifndef ENCRYPTION_EXECUTOR_H
#define ENCRYPTION_EXECUTOR_H


#include <jni.h>

void invoke_int(JNIEnv *env, jobject obj, char * class_name,char *method, char * signature,int i );
jobject invoke_str(JNIEnv *env, jobject obj , char *method, char *signature,const char *str,...) ;
jobject invoke_static_str(JNIEnv *env, char *class_name , char *method, char *signature,const char *str,...) ;

char * get_class_name (JNIEnv  *env,jobject clz);

#endif //ENCRYPTION_EXECUTOR_H
