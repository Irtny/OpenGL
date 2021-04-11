#include "Primitives.h"
#include <cmath>
#include <GL/gl.h>

static constexpr double Pi = acos(-1.);


void cart2cyl(	double x, double y, double z,
				double &r, double &phi, double &cz )
{
	r = hypot(y, x);
	phi = atan2(y, x);
	cz = z;

}
void cyl2cart(	double r, double phi, double cz,
				double &x, double &y, double &z )
{
	x = r * cos(phi);
	y = r * sin(phi);
	z = cz;
}

void cart2sph(	double x, double y, double z,
				double &r, double &phi, double &theta)
{
	r = sqrt(x*x + y*y +z*z);
	phi = atan2(y, x);
	theta = atan2(hypot(x,y), z);
}

void sph2cart(	double r, double phi, double theta,
				double &x, double &y, double &z)
{
	x = r * sin(theta) * cos(phi);
	y = r * sin(theta) * sin(phi);
	z = r * cos(theta);
}

void draw_prism(int sides)
{
	double phi_step = 2. * Pi / sides;
	for (int side = 0; side < sides; side++) {
		double  phi1 = phi_step * side,
				phi2 = phi_step * (side+1),
				phin = (phi1 + phi2) / 2.;

		double x1, x2, y1, y2, z1, z2, xn, yn ,zn;
		cyl2cart(1., phi1, 0., x1, y1, z1);
		cyl2cart(1., phi2, 1., x2, y2, z2);
		cyl2cart(1., phin, 0., xn, yn, zn);
		glBegin(GL_TRIANGLES);
		{
		glNormal3d(0., 0., 1.);
		glVertex3d(0., 0., 1.);
		glVertex3d(x1, y1, 1.);
		glVertex3d(x2, y2, 1.);
		glNormal3d(0., 0., -1.);
		glVertex3d(0., 0., 0.);
		glVertex3d(x2, y2, 0.);
		glVertex3d(x1, y1, 0.);
		}
		glEnd();
		glBegin(GL_QUADS);
		{
			glNormal3d(xn, yn, zn);
			glVertex3d(x2, y2, 1.);
			glVertex3d(x1, y1, 1.);
			glVertex3d(x1, y1, 0.);
			glVertex3d(x2, y2, 0.);
		}
		glEnd();
	}
}

void draw_cylindr(int sides)
{
	double phi_step = 2. * Pi / sides;
		for (int side = 0; side < sides; side++) {
			double  phi1 = phi_step * side,
					phi2 = phi_step * (side+1);


			double x1, x2, y1, y2, z1, z2;
			cyl2cart(1., phi1, 0., x1, y1, z1);
			cyl2cart(1., phi2, 1., x2, y2, z2);
			glBegin(GL_TRIANGLES);
			{
			glNormal3d(0., 0., 1.);
			glVertex3d(0., 0., 1.);
			glVertex3d(x1, y1, 1.);
			glVertex3d(x2, y2, 1.);
			glNormal3d(0., 0., -1.);
			glVertex3d(0., 0., 0.);
			glVertex3d(x2, y2, 0.);
			glVertex3d(x1, y1, 0.);
			}
			glEnd();
			glBegin(GL_QUADS);
			{
				glNormal3d(x1, y1, 0);
				glVertex3d(x1, y1, 1.);
				glVertex3d(x1, y1, 0.);
				glNormal3d(x2, y2, 0);
				glVertex3d(x2, y2, 0.);
				glVertex3d(x2, y2, 1.);
			}
			glEnd();
		}

}

void draw_pyramid(int sides)
{
	double phi_step = 2. * Pi / sides;
		for (int side = 0; side < sides; side++) {
			double  phi1 = phi_step * side,
					phi2 = phi_step * (side+1),
					phin = (phi1 + phi2) / 2.;

			double x1, x2, y1, y2, z1, z2, xn, yn, zn;
			cyl2cart(1., phi1, 0., x1, y1, z1);
			cyl2cart(1., phi2, 1., x2, y2, z2);
			sph2cart(1., phin, Pi/4, xn, yn, zn);
			glBegin(GL_TRIANGLES);
			{
			glNormal3d(xn, yn, zn);
			glVertex3d(0., 0., 1.);
			glVertex3d(x1, y1, 0.);
			glVertex3d(x2, y2, 0.);
			glNormal3d(0., 0., -1.);
			glVertex3d(0., 0., 0.);
			glVertex3d(x2, y2, 0.);
			glVertex3d(x1, y1, 0.);
			}
			glEnd();

			glEnd();
		}
}



void draw_cone(int sides)
{
	double phi_step = 2. * Pi / sides;
			for (int side = 0; side < sides; side++) {
				double  phi1 = phi_step * side,
						phi2 = phi_step * (side+1),
						phin = (phi1 + phi2) / 2.;

				double x1, x2, y1, y2, z1, z2, xn, yn, zn;
				cyl2cart(1., phi1, 0., x1, y1, z1);
				cyl2cart(1., phi2, 1., x2, y2, z2);
				sph2cart(1., phin, Pi/4, xn, yn, zn);				glBegin(GL_TRIANGLES);
				{

					glNormal3d(xn, yn, zn);
					glVertex3d(0., 0., 1.);
					glVertex3d(x1, y1, 0.);
					glVertex3d(x2, y2, 0.);
					glNormal3d(0., 0., -1.);
					glVertex3d(0., 0., 0.);
					glVertex3d(x2, y2, 0.);
					glVertex3d(x1, y1, 0.);

				}
				glEnd();
			}
}

void draw_sphere(int sides) {
}

void draw_sphere_smooth(int sides) {
}
