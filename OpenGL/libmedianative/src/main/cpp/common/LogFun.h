//
// Created by 孙全 on 2022/5/13.
//
#pragma once

#ifndef OPENGL_LOGFUN_H
#define OPENGL_LOGFUN_H

#include <android/log.h>
#include <string>
#include <jni.h>

#endif //OPENGL_LOGFUN_H

#define TAG_EGL_RENDER "EGLRender"
#define TAG_ASSET "Asset"
#define TAG_GLUTILS "GLUtils"
#define TAG_RENDER_JNI "NativeRenderJni"
#define TAG_ABS_RENDER "GLAbsRender"
#define TAG_RENDER_TRIANGLE "RenderTriangle"
#define TAG_ASSIGN_FACTORY "AssignFactory"
#define TAG_RENDER_TRIANGLE_VBO "RenderTriangleVBO"
#define TAG_RENDER_TRIANGLE_VAO "RenderTriangleVAO"
#define TAG_RENDER_RECT "RenderRect"
#define TAG_RENDER_TWO_FRAGMENT_SHADER "RenderTwoFragmentShader"
#define TAG_RENDER_RECT_EBO "RenderRectEBO"



#define LOGV(tag,format, ...) __android_log_print(ANDROID_LOG_VERBOSE, tag, format, ##__VA_ARGS__)
#define LOGD(tag,format, ...)  __android_log_print(ANDROID_LOG_DEBUG,  tag, format, ##__VA_ARGS__)
#define LOGI(tag,format, ...)  __android_log_print(ANDROID_LOG_INFO,  tag, format, ##__VA_ARGS__)
#define LOGW(tag,format, ...)  __android_log_print(ANDROID_LOG_WARN,  tag, format, ##__VA_ARGS__)
#define LOGE(tag,format, ...)  __android_log_print(ANDROID_LOG_ERROR,  tag, format, ##__VA_ARGS__)

#define GL_RESULT_ERROR 0;