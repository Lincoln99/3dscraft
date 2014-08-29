#ifndef GS_H
#define GS_H

#include <3ds/types.h>

#define GS_MATRIXSTACK_SIZE (8)

typedef enum
{
	GS_PROJECTION = 0,
	GS_MODELVIEW = 1,
	GS_MATRIXTYPES
}GS_MATRIX;

typedef struct
{
	u8* data;
	u32 currentSize; // in bytes
	u32 maxSize; // in bytes
}gsVbo_s;


void gsInit(void);
void gsExit(void);

float* gsGetMatrix(GS_MATRIX m);
int gsLoadMatrix(GS_MATRIX m, float* data);
int gsPushMatrix();
int gsPopMatrix();
int gsMatrixMode(GS_MATRIX m);

void gsLoadIdentity();
void gsProjectionMatrix(float fovy, float aspect, float near, float far);
void gsRotateX(float x);
void gsRotateY(float y);
void gsRotateZ(float z);
void gsScale(float x, float y, float z);
void gsTranslate(float x, float y, float z);
int gsMultMatrix(float* data);

int gsVboInit(gsVbo_s* vbo);
int gsVboCreate(gsVbo_s* vbo, u32 size);
int gsVboDestroy(gsVbo_s* vbo);
int gsVboDraw(gsVbo_s* vbo);
void* gsVboGetOffset(gsVbo_s* vbo);
int gsVboAddData(gsVbo_s* vbo, void* data, u32 size);

#endif