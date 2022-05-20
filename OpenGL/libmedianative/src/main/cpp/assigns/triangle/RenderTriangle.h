//
// Created by 孙全 on 2022/5/19.
//
#pragma once
#ifndef OPENGL_RENDERTRIANGLE_H
#define OPENGL_RENDERTRIANGLE_H
#include "assigns/GLAbsRender.h"


class RenderTriangle : public GLAbsRender{
public:
    RenderTriangle() = default;

    virtual ~RenderTriangle() = default;
    virtual void onDraw();
    virtual void onSurfaceCreated();
    virtual void onDestroy();
};


#endif //OPENGL_RENDERTRIANGLE_H
