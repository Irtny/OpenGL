/*
 * SimpleModel.h
 *
 *  Created on: 9 апр. 2021 г.
 *      Author: fomin
 */

#ifndef SIMPLEMODEL_H_
#define SIMPLEMODEL_H_

#include <vector>
#include <GL/gl.h>

class SimpleModel {
public:
	using Vertex = std::vector<GLdouble>;
	using Normal = std::vector<GLdouble>;
	using Color = std::vector<GLfloat>;
	using Face = std::vector<int>; // [0] - количество вершин, остальные - индексы

protected:
	std::vector<Vertex> _vertices;
	std::vector<Face> _faces;
	std::vector<Normal> _normals;
	std::vector<Color> _colors;
	std::vector<std::vector<Vertex>> _tex_coords;
public:
	SimpleModel(
		const std::vector<Vertex> &vertices,
		const std::vector<Face> &faces,
		const std::vector<Color> &colors,
		const std::vector<Normal> &normals,
		const std::vector<std::vector<Vertex>> & tex_coords);
	virtual ~SimpleModel() = default;

	void draw();

	static SimpleModel create_cube();
	static SimpleModel create_roof();
	static SimpleModel create_pipe();
};

#endif /* SIMPLEMODEL_H_ */
