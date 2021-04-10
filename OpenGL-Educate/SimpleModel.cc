/*
 * SimpleModel.cc
 *
 *  Created on: 9 ���. 2021 �.
 *      Author: fomin
 */

#include "SimpleModel.h"

static const std::vector<SimpleModel::Vertex> s_cube_vertices {
	{  1.0,  1.0,  1.0 },
	{  1.0, -1.0,  1.0 },
	{ -1.0, -1.0,  1.0 },
	{ -1.0,  1.0,  1.0 },
	{  1.0,  1.0, -1.0 },
	{  1.0, -1.0, -1.0 },
	{ -1.0, -1.0, -1.0 },
	{ -1.0,  1.0, -1.0 },
};

static const std::vector<SimpleModel::Face> s_cube_faces {
	{ 4, 1, 0, 4, 5 },
	{ 4, 3, 2, 6, 7 },
	{ 4, 2, 3, 0, 1 },
	{ 4, 7, 6, 5, 4 },
	{ 4, 0, 3, 7, 4 },
	{ 4, 2, 1, 5, 6 },
};

static const std::vector<SimpleModel::Color> s_cube_colors {
	{ 0.8f, 1.0f, 1.0f  },
	{ 1.0f, 0.8f, 0.8f  },
	{ 1.0f, 1.0f, 0.8f  },
	{ 0.8f, 0.8f, 1.0f  },
	{ 1.0f, 0.8f, 1.0f  },
	{ 0.8f, 1.0f, 0.8f  },

};

static const std::vector<SimpleModel::Normal> s_cube_normals {
	{  1.0,  0.0,  0.0  },
	{ -1.0,  0.0,  0.0  },
	{  0.0,  0.0,  1.0  },
	{  0.0,  0.0, -1.0  },
	{  0.0,  1.0,  0.0  },
	{  0.0, -1.0,  0.0  },
};

static const std::vector<std::vector<SimpleModel::Vertex>> s_cube_tex_coords {
	{ { 0.00, 0.00}, { 0.25, 0.00}, { 0.25, 0.50}, { 0.00, 0.50} },
	{ { 0.25, 0.00}, { 0.50, 0.00}, { 0.50, 0.50}, { 0.25, 0.50} },
	{ { 0.50, 0.00}, { 0.75, 0.00}, { 0.75, 0.50}, { 0.50, 0.50} },
	{ { 0.00, 0.50}, { 0.25, 0.50}, { 0.25, 1.00}, { 0.00, 1.00} },
	{ { 0.25, 0.50}, { 0.50, 0.50}, { 0.50, 1.00}, { 0.25, 1.00} },
	{ { 0.50, 0.50}, { 0.75, 0.50}, { 0.75, 1.00}, { 0.50, 1.00} },
};


SimpleModel::SimpleModel(
		const std::vector<Vertex> &vertices,
		const std::vector<Face> &faces,
		const std::vector<Color> &colors,
		const std::vector<Normal> &normals,
		const std::vector<std::vector<Vertex> > &tex_coords)
: _vertices(vertices),
  _faces(faces),
  _colors(colors),
  _normals(normals),
  _tex_coords(tex_coords)
{
}

void SimpleModel::draw()
{
	for (unsigned face_idx = 0; face_idx < _faces.size(); ++face_idx){
		int vertices = _faces[face_idx][0];
		if(vertices == 3) glBegin(GL_TRIANGLES);
		else if (vertices == 4) glBegin(GL_QUADS);
		else glBegin(GL_POLYGON);

		glColor3fv(&_colors[face_idx][0]);
		glNormal3dv(&_normals[face_idx][0]);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, &_colors[face_idx][0]);

		for (int i = 0; i < vertices; ++i) {
			glTexCoord2dv(&_tex_coords[face_idx][i][0]);
			glVertex3dv(&_vertices[_faces[face_idx][i+1]][0]);
		}

		glEnd();
	}
}

SimpleModel SimpleModel::create_cube() {
	return SimpleModel(
			s_cube_vertices,
			s_cube_faces,
			s_cube_colors,
			s_cube_normals,
			s_cube_tex_coords);
}
