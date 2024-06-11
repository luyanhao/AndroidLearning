//
// Created by 孙全 on 2022/5/19.
//
#pragma once
#ifndef OPENGL_RENDERTRIANGLEFAN_H
#define OPENGL_RENDERTRIANGLEFAN_H
#include "learnopengl_assigns/GLAbsRender.h"


class RenderTriangleFAN : public GLAbsRender{
public:
    virtual void onDraw();
    virtual void onSurfaceCreated();
};


#endif //OPENGL_RENDERTRIANGLEFAN_H
