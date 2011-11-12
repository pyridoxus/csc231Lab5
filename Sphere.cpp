#include "Sphere.h"

Sphere::Sphere(float *diffuse, float *specular,
								float *shininess, float *translate, float *ambient)
{
	int i;
	this->data.diffuse = (float *)malloc(4 * sizeof(float));
	this->data.specular = (float *)malloc(4 * sizeof(float));
	// Only 1 float is used for shininess, but we'll allocate full size to
	// fit the array from the lab5.cpp file.
	this->data.shininess = (float *)malloc(4 * sizeof(float));
	this->data.translate = (float *)malloc(4 * sizeof(float));
	this->data.ambient = (float *)malloc(4 * sizeof(float));
	for(i = 0; i < 5; i++)
	{
		this->data.diffuse[i] = diffuse[i];
		this->data.specular[i] = specular[i];
		this->data.shininess[i] = shininess[i];
		this->data.translate[i] = translate[i];
		this->data.ambient[i] = ambient[i];
	}
	return;
}

Sphere::~Sphere()
{
	free(this->data.diffuse);
	free(this->data.specular);
	free(this->data.shininess);
	free(this->data.translate);
	free(this->data.ambient);
	return;
}

void Sphere::draw(void)
{
  glPushMatrix();
  glTranslatef( this->data.translate[0], this->data.translate[1],
  							this->data.translate[2] );
  glMaterialfv(GL_FRONT, GL_DIFFUSE, this->data.diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, this->data.specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, this->data.shininess);
  glLightModelfv( GL_LIGHT_MODEL_AMBIENT, this->data.ambient );
  glutSolidSphere( 1.0, 40, 40 );
  glPopMatrix();
	return;
}
