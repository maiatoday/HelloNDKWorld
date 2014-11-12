#include <jni.h>
#include <string.h>
#include <android/log.h>
#define DEBUG_TAG "NDK_AndroidNDK1SampleActivity"
void Java_com_example_hellondkworld_MainActivity_helloLog(JNIEnv * env, jobject this, jstring logThis)
{
    jboolean isCopy;
    const char * szLogThis = (*env)->GetStringUTFChars(env, logThis, &isCopy);
    __android_log_print(ANDROID_LOG_DEBUG, DEBUG_TAG, "NDK:LC: [%s]", szLogThis);
    (*env)->ReleaseStringUTFChars(env, logThis, szLogThis);
}

jstring
Java_com_example_hellondkworld_MainActivity_stringFromJNI( JNIEnv* env,
                                                  jobject thiz )
{
#if defined(__arm__)
  #if defined(__ARM_ARCH_7A__)
    #if defined(__ARM_NEON__)
      #define ABI "armeabi-v7a/NEON"
    #else
      #define ABI "armeabi-v7a"
    #endif
  #else
   #define ABI "armeabi"
  #endif
#elif defined(__i386__)
   #define ABI "x86"
#elif defined(__mips__)
   #define ABI "mips"
#else
   #define ABI "unknown"
#endif

    return (*env)->NewStringUTF(env, "Hello from JNI !  Compiled with ABI " ABI ".");
}
