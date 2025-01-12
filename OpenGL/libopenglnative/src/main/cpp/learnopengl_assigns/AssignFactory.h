//
// Created by 孙全 on 2022/5/20.
//

#pragma once

#include "learnopengl_assigns/GLAbsRender.h"
#include "common/LogFun.h"
#include "common/AssignType.h"

//triangle
#include "learnopengl_assigns/triangle/RenderTriangle.h"
#include "learnopengl_assigns/triangle/RenderTriangleFAN.h"
#include "learnopengl_assigns/triangle/RenderTriangleVBO.h"
#include "learnopengl_assigns/triangle/RenderTriangleVAO.h"
#include "learnopengl_assigns/triangle/RenderRect.h"
#include "learnopengl_assigns/triangle/RenderRectTwoFragmentShader.h"
#include "learnopengl_assigns/triangle/RenderRectEBO.h"

//shaders
#include "learnopengl_assigns/shaders/SimpleShader.h"
#include "learnopengl_assigns/shaders/UniformShader.h"
#include "learnopengl_assigns/shaders/StrideShader.h"
#include "learnopengl_assigns/textures/TextureDemo.h"
#include "learnopengl_assigns/transform/TransformDemo.h"
#include "learnopengl_assigns/transform/PerspactiveTransformDemo.h"
#include "learnopengl_assigns/transform/TextureTransformDemo.h"
#include "learnopengl_assigns/lighting/SimpleColorDemo.h"
#include "learnopengl_assigns/lighting/BasicColorDemo.h"

class AssignFactory {
public:
    void createAssignDemo(int type);
    void createAssignDemoV2(JNIEnv *env,jobject asset_manager,int type);
    void onInit(JNIEnv *env,jobject asset_manager,const string &vertexShaderAssetName,const string &fragmentShaderAssetName){
        if(!p_AssignDemo){
            LOGE(TAG_ASSIGN_FACTORY,"p_AssignDemo is null");
            return;
        }
        p_AssignDemo->onInit(env,asset_manager,vertexShaderAssetName,fragmentShaderAssetName);
    }
    void onDraw(){
        if(!p_AssignDemo){
            LOGE(TAG_ASSIGN_FACTORY,"p_AssignDemo is null");
            return;
        }
        p_AssignDemo->onDraw();
    }
    void onSurfaceCreated(){
        if(!p_AssignDemo){
            LOGE(TAG_ASSIGN_FACTORY,"p_AssignDemo is null");
            return;
        }
        p_AssignDemo->onSurfaceCreated();
    }
    void onSurfaceChange(int width,int height){
        if(!p_AssignDemo){
            LOGE(TAG_ASSIGN_FACTORY,"p_AssignDemo is null");
            return;
        }
        p_AssignDemo->onSurfaceChange(width,height);
    }
    void onOptClick(int opt_type){
        if(!p_AssignDemo){
            LOGE(TAG_ASSIGN_FACTORY,"p_AssignDemo is null");
            return;
        }
        p_AssignDemo->onOptClick(opt_type);
    }
    void onDestroy(){
        if(!p_AssignDemo){
            LOGE(TAG_ASSIGN_FACTORY,"p_AssignDemo is null");
            return;
        }
        p_AssignDemo->onDestroy();
        delete p_AssignDemo;
        p_AssignDemo = nullptr;
    }

    static AssignFactory *getInstance();
    static void onDestroyDemoResources();



private:
    static AssignFactory *m_Instance;
    GLAbsRender* p_AssignDemo;
};


