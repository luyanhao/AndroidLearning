#include <jni.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iosfwd>
#include "learnopengl_assigns/AssignFactory.h"

#ifdef __cplusplus
extern "C" {
#endif
JNIEXPORT void JNICALL
Java_com_scott_nativecode_NativeRenderJni_onSurfaceCreated(JNIEnv *env, jobject thiz) {
    AssignFactory::getInstance()->onSurfaceCreated();
}

JNIEXPORT void JNICALL
Java_com_scott_nativecode_NativeRenderJni_onSurfaceChanged(JNIEnv *env, jobject thiz, jint width,
                                                           jint height) {
    AssignFactory::getInstance()->onSurfaceChange(width,height);
}
JNIEXPORT void JNICALL
Java_com_scott_nativecode_NativeRenderJni_onDrawFrame(JNIEnv *env, jobject thiz) {
    AssignFactory::getInstance()->onDraw();
}

JNIEXPORT void JNICALL
Java_com_scott_nativecode_NativeRenderJni_init(JNIEnv *env, jobject thiz, jobject asset_manager,
                                               jint assignType,
                                               jstring vertex_shader_asset_name,
                                               jstring fragment_shader_asset_name) {
    AssignFactory::getInstance()->createAssignDemo(assignType);
    AssignFactory::getInstance()->onInit(env,asset_manager,JNI_GetString(env,vertex_shader_asset_name),JNI_GetString(env,fragment_shader_asset_name));
}

JNIEXPORT void JNICALL
Java_com_scott_nativecode_NativeRenderJni_initV2(JNIEnv *env, jobject thiz, jobject asset_manager,
                                                 jint assign_type) {
    // TODO: implement initV2()
    AssignFactory::getInstance()->createAssignDemoV2(env,asset_manager,assign_type);
}

JNIEXPORT void JNICALL
Java_com_scott_nativecode_NativeRenderJni_onDestroy(JNIEnv *env, jobject thiz) {
    AssignFactory::onDestroyInstance();
}

#ifdef __cplusplus
}
#endif

