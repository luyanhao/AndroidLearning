//
// Created by 孙全 on 2022/5/19.
//

#include "RenderTriangleFAN.h"
static GLfloat vertices[] = {
        -0.5f, 0.5f, 0.0f, // 左上（x, y, z）
        -0.5f, -0.5f, 0.0f, // 左下（x, y, z）
        0.5f, -0.5f, 0.0f, // 右下（x, y, z）
        0.5, 0.5, 0.0f // 右上（x，y，z）
};

void RenderTriangleFAN::onSurfaceCreated() {
    glClearColor(1.0f, 0.5f, 0.0f, 1.0f);
    this->m_ProgramObj = GLUtils::createProgram(&this->VERTEX_SHADER, &this->FRAGMENT_SHADER);
    // 设置清除颜色
    if (!this->m_ProgramObj) {
        LOGD(TAG_RENDER_TRIANGLE,"Could not Create program");
        return;
    }
    glUseProgram(this->m_ProgramObj);
    //index代表pos_location
    glVertexAttribPointer(DEFAULT_POS_LOCATION,3,GL_FLOAT,GL_FALSE,0,vertices);
    glEnableVertexAttribArray(DEFAULT_POS_LOCATION);

}

void RenderTriangleFAN::onDraw() {
    LOGI(TAG_RENDER_TRIANGLE,"onDraw");
    glClear(GL_COLOR_BUFFER_BIT);
    // GL_TRIANGLE_FAN: 前面三角形的第1和3个顶点，为后面三角形的第1和2个顶点
    // GL_TRIANGLE_STRIP: 三角形的最后2个顶点为下一个三角形的前面2个顶点
    glDrawArrays(GL_TRIANGLE_FAN,0,4);
}