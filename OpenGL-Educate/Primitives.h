/*
 * Primitives.h
 *
 *  Created on: 11 апр. 2021 г.
 *      Author: Домашний
 */


#ifndef PRIMITIVES_H_
#define PRIMITIVES_H_

#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>

void cart2cyl(	double x, double y, double z,
				double &r, double &phi, double &cz );

void cyl2cart(	double r, double phi, double cz,
				double &x, double &y, double &z );

void cart2sph(	double x, double y, double z,
				double &r, double &phi, double &theta );

void sph2cart(	double r, double phi, double theta ,
				double &x, double &y, double &z);

void draw_prism(int sides);
void draw_cylindr(int sides);
void draw_pyramid(int sides);
void draw_cone(int sides);
void draw_sphere_smooth(int rows, int cols);
void draw_sphere_smooth_motion(int rows, int cols, double cdx, double cdy, double cdz, double cdr);



#endif /* PRIMITIVES_H_ */
