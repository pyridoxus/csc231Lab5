#ifndef SPHERE_H_
#define SPHERE_H_
#include "MaterialData.h"
#include <stdlib.h>
#include <GL/glut.h>

class Sphere
{
	public:
		Sphere(float *diffuse, float *specular, float *shininess,
					 float *translate, float *ambient);
		virtual ~Sphere();
		void draw(void);
	private:
		MaterialData data;
};

#endif
