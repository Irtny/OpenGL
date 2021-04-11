/*
 * Primitives.h
 *
 *  Created on: 11 ���. 2021 �.
 *      Author: ��������
 */

#ifndef PRIMITIVES_H_
#define PRIMITIVES_H_
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
void draw_sphere(int sides);
void draw_sphere_smooth(int sides);



#endif /* PRIMITIVES_H_ */
