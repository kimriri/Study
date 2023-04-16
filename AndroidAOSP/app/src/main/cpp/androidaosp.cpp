#include <jni.h>
#include <string>
#include <android/log.h>

// Write C++ code here.
//
// Do not forget to dynamically load the C++ library into your application.
//
// For instance,
//
// In MainActivity.java:
//    static {
//       System.loadLibrary("androidaosp");
//    }
//
// Or, in MainActivity.kt:
//    companion object {
//      init {
//         System.loadLibrary("androidaosp")
//      }
//    }
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_androidaosp_aospnative_getLine(JNIEnv *env, jobject thiz, jstring prompt,
                                                  jint value) {
    const char *str = env->GetStringUTFChars(prompt, NULL);
    if(str == NULL)
        return NULL;

    __android_log_print(ANDROID_LOG_INFO,"App Debug", "%s(default %d) :" ,str,value);

    env->ReleaseStringUTFChars(prompt,str);

    const char *buf = "안녕하세요";
    return env -> NewStringUTF(buf);


}