#include "Sphere.h"

Sphere::Sphere(float *diffuse, float *specular,
								float *shininess, float *translate)
{
	this->data.diffuse = (float *)malloc(sizeof(float));
	this->data.specular = (float *)malloc(sizeof(float));
	this->data.shininess = (float *)malloc(sizeof(float));
	this->data.translate = (float *)malloc(sizeof(float));
	*this->data.diffuse = *diffuse;
	*this->data.specular = *specular;
	*this->data.shininess = *shininess;
	*this->data.translate = *translate;
	return;
}

Sphere::~Sphere()
{
	free(this->data.diffuse);
	free(this->data.specular);
	free(this->data.shininess);
	free(this->data.translate);
	return;
}

void Sphere::draw(void)
{
	return;
}
