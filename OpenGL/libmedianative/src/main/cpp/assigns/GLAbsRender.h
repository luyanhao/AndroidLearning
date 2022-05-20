//
// Created by 孙全 on 2022/5/19.
//

#ifndef OPENGL_GLABSRENDER_H
#define OPENGL_GLABSRENDER_H
#pragma once

#include <string>
#include "common/TypeUtil.h"
#include "common/LogFun.h"
#include "common/AssetFun.h"
#include <GLES3/gl3.h>
#include "common/GLUtils.h"
static GLuint DEFAULT_POS_LOCATION = 0;
class GLAbsRender {
public:
    GLAbsRender() {
        VERTEX_SHADER = GL_NONE;
        FRAGMENT_SHADER = GL_NONE;
        m_ProgramObj = 0;
        m_Width = 0;
        m_Height = 0;
    }
    virtual ~GLAbsRender() {}
    virtual void onInit(JNIEnv *env,jobject asset_manager,const string &vertexShaderAssetName,const string &fragmentShaderAssetName) {
        GLUtils::printGLInfo();
        glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
        LOGI(TAG_RENDER_TRIANGLE,"vertexShaderAssetName = %s, fragmentShaderAssetName = %s",vertexShaderAssetName.c_str(),fragmentShaderAssetName.c_str());
        AAssetManager *pManager = AAssetManager_fromJava(env, asset_manager);
        this->VERTEX_SHADER = AssetFun::readAssetFile(vertexShaderAssetName.c_str(), pManager);
        this->FRAGMENT_SHADER = AssetFun::readAssetFile(fragmentShaderAssetName.c_str(), pManager);
        LOGI(TAG_RENDER_TRIANGLE,"vertexShaderContent = %s",this->VERTEX_SHADER);
        LOGI(TAG_RENDER_TRIANGLE,"fragmentShaderContent = %s",this->FRAGMENT_SHADER);
    }
    virtual void onDraw() = 0;
    virtual void onSurfaceCreated() = 0;
    virtual void onSurfaceChange(int width,int height){
        LOGI(TAG_ABS_RENDER,"onSurfaceChange, width = %d, height = %d",width,height);
        this->m_Width = width;
        this->m_Height = height;
        glViewport(0,0,width,height);
    }
    virtual void onDestroy(){
        LOGI(TAG_ABS_RENDER,"onDestroy");
        if (m_ProgramObj) {
            glDeleteProgram(m_ProgramObj);
            m_ProgramObj = GL_NONE;
        }
        if(VERTEX_SHADER != nullptr){
            delete[] VERTEX_SHADER;
            VERTEX_SHADER = nullptr;
        }
        if(FRAGMENT_SHADER!= nullptr){
            delete[] FRAGMENT_SHADER;
            FRAGMENT_SHADER = nullptr;
        }
    }

protected:

    /**
     * 程序对象
     */
    GLuint m_ProgramObj;

    /**
     * 顶点着色器
     */
    const char *VERTEX_SHADER;
    /**
     * 片段着色器脚本
     */
    const char *FRAGMENT_SHADER;
    /**
     * 屏幕宽度
     */
    int m_Width;
    /**
     * 屏幕高度
     */
    int m_Height;

    /**
   * assginType
   */
    int m_AssignType;
};


#endif //OPENGL_GLABSRENDER_H
