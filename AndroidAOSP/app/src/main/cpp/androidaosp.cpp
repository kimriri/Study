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
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_androidaosp_JNICallBackMethod_PrinttoString(JNIEnv *env, jobject obj) {
    jclass cls = env ->GetObjectClass(obj);

    jmethodID mid = env ->GetMethodID(cls,"toString","()Ljava/lang/String;");

    jstring s = (jstring) env ->CallObjectMethod(obj,mid);

    const char *buf = env ->GetStringUTFChars(s,0);

    __android_log_print(ANDROID_LOG_INFO,"JNICallBackMethod_PrinttoString","%s",buf);

    env ->ReleaseStringUTFChars(s,buf);
    return s;
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_example_androidaosp_SignaturnActivity_fun_1signaturn__(JNIEnv *env, jobject clazz) {
    const char *buf = "시그네이처";
    return env->NewStringUTF(buf);
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_androidaosp_SignaturnActivity_fun_1signaturn__Ljava_lang_String_2(JNIEnv *env,jobject clazz,jstring s) {

    const char *str = env->GetStringUTFChars(s, NULL);
    if(str == NULL)
        return NULL;
    env ->ReleaseStringUTFChars(s,str);
    return env -> NewStringUTF(str);

}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_androidaosp_SignaturnActivity_fun_1signaturn__II(JNIEnv *env, jobject thiz, jint i,
                                                                  jint j) {
    std::string result = "JNU에서 연산한 값 : " + std::to_string(i + j);
    return env->NewStringUTF( result.c_str());
}