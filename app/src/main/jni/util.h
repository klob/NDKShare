//
// Created by klob on 2015/9/12.
//

#ifndef ENCRYPTION_UTIL_H
#define ENCRYPTION_UTIL_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <stddef.h>
#include <unistd.h>

#include <fcntl.h>


#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <termios.h>


#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include "jni.h"
#include "log.h"


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
 char * jstrToChar(JNIEnv *env, jstring jstring1);
jstring charToJstr(JNIEnv *env , char * c);
jstring getSignChar(JNIEnv *env);
char *str2md5(const char *str, int length);
void releaseStringUTFChars(JNIEnv *env, jstring jstr, char *temp);

#endif //ENCRYPTION_UTIL_H
