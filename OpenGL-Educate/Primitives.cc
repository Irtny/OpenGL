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

void sph2cart(
		double r, double phi, double theta,
		double &x, double &y, double &z)
{
	x = r * sin(theta) * cos(phi) ;
	y = r * sin(theta) * sin(phi) ;
	z = r * cos(theta);
}

void sph2cartm(
		double r, double phi, double theta,
		double &x, double &y, double &z,
		double cdx, double cdy, double cdz)
{
	x = r * sin(theta) * cos(phi) + cdx;
	y = r * sin(theta) * sin(phi) + cdy;
	z = r * cos(theta) + cdz;
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
			glVertex3d(0., 0., 2.);
			glVertex3d(x1, y1, 2.);
			glVertex3d(x2, y2, 2.);
			glNormal3d(0., 0., -1.);
			glVertex3d(0., 0., 0.);
			glVertex3d(x2, y2, 0.);
			glVertex3d(x1, y1, 0.);
			}
			glEnd();
			glBegin(GL_QUADS);
			{

				glNormal3d(x1, y1, 0);
				glVertex3d(x1, y1, 2.);
				glVertex3d(x1, y1, 0.);
				glNormal3d(x2, y2, 0);
				glVertex3d(x2, y2, 0.);
				glVertex3d(x2, y2, 2.);
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
				sph2cart(1., phin, Pi/4, xn, yn, zn);
				glBegin(GL_TRIANGLES);
				{

					glNormal3d(xn, yn, zn);
					glVertex3d(0., 0., 2.);
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

void draw_sphere_smooth(int rows, int cols)
{
	double  phi_step = 2. * Pi / cols,
			theta_step = Pi / rows;
	glBegin(GL_QUADS);
	for (int row = 0; row < rows; ++row){
		for (int col = 0; col < cols; ++col){
			double  phi1 = phi_step * col,
					phi2 = phi_step * (col + 1),
					theta1 = theta_step * row,
					theta2 = theta_step * (row + 1),
					phin = (phi1 + phi2) / 2.,
					thetan = (theta1 + theta2) / 2.;

			double  x11, x12, x21, x22,
					y11, y12, y21, y22,
					z11, z12, z21, z22,
					nx, ny, nz;

			sph2cart(1., phi1, theta1, x11, y11, z11);
			sph2cart(1., phi1, theta2, x12, y12, z12);
			sph2cart(1., phi2, theta1, x21, y21, z21);
			sph2cart(1., phi2, theta2, x22, y22, z22);
			sph2cart(1., phin, thetan, nx, ny, nz);

			glNormal3d(x11, y11, z11);
			glVertex3d(x11, y11, z11);
			glNormal3d(x12, y12, z12);
			glVertex3d(x12, y12, z12);
			glNormal3d(x22, y22, z22);
			glVertex3d(x22, y22, z22);
			glNormal3d(x21, y21, z21);
			glVertex3d(x21, y21, z21);
		}
	}
	glEnd();
}

void draw_sphere_smooth_motion(int rows, int cols, double cdx, double cdy, double cdz, double cdr)
{
	double  phi_step = 2. * Pi / cols,
			theta_step = Pi / rows;
	glBegin(GL_QUADS);
	for (int row = 0; row < rows; ++row){
		for (int col = 0; col < cols; ++col){
			double  phi1 = phi_step * col,
					phi2 = phi_step * (col + 1),
					theta1 = theta_step * row,
					theta2 = theta_step * (row + 1),
					phin = (phi1 + phi2) / 2.,
					thetan = (theta1 + theta2) / 2.;

			double  x11, x12, x21, x22,
					y11, y12, y21, y22,
					z11, z12, z21, z22,
					nx, ny, nz;

			sph2cartm(cdr, phi1, theta1, x11, y11, z11, cdx, cdy, cdz);
			sph2cartm(cdr, phi1, theta2, x12, y12, z12, cdx, cdy, cdz);
			sph2cartm(cdr, phi2, theta1, x21, y21, z21, cdx, cdy, cdz);
			sph2cartm(cdr, phi2, theta2, x22, y22, z22, cdx, cdy, cdz);
			sph2cartm(cdr, phin, thetan, nx, ny, nz, cdx, cdy, cdz);

			glNormal3d(x11, y11, z11);
			glVertex3d(x11, y11, z11);
			glNormal3d(x12, y12, z12);
			glVertex3d(x12, y12, z12);
			glNormal3d(x22, y22, z22);
			glVertex3d(x22, y22, z22);
			glNormal3d(x21, y21, z21);
			glVertex3d(x21, y21, z21);
		}
	}
	glEnd();
}
