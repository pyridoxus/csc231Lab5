#ifndef SPHERE_H_
#define SPHERE_H_

class Sphere
{
	public:
		Sphere(GLdouble radius, GLint slices, GLint stacks);
		virtual ~Sphere();
		void setDiffuse(float *data);
		void setSpecular(float *data);
		void setShininess(float *data);
		void translate(float x, float y, float z);
};

#endif
