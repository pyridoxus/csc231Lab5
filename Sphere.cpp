//This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
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
