#include "geometry/Quad.h"
#include "math/vec4.h"
#include <arm_neon.h>

namespace anut
{
Mesh Quad::_cubeMesh{};

Quad::Quad(float w, float h, float d)
{
	if (_cubeMesh.getVertexCount() == 0)
	{
		loadCubeMesh();
	}
	
	positions.resize(VERTEX_COUNT);
	indices.resize(INDEX_COUNT);
	
	for (int i = 0; i < INDEX_COUNT; i++)
	{
		indices[i] = _cubeMesh.indices[i];
	}
	
	resize(w, h, d);
}

void Quad::resize(float w, float h, float d)
{
	_width = w;
	_height = h;
	_depth = d;
	
	float s[4] = {w, h, d, 1.f};
	float32x4_t scalarVec = vld1q_f32(s);
	for (int i = 0; i < VERTEX_COUNT; i++)
	{
		float32x4_t vertex = vld1q_f32(&_cubeMesh.positions[i].v[0]);
		vertex = vmulq_f32(vertex, scalarVec);
		vst1q_f32(&positions[i].v[0], vertex);
	}
}

void Quad::loadCubeMesh()
{
	const anut::Vec4 cubeVertices[] =
	{
		// front
		{-0.5f, +0.5f, +0.5f, 1.f}, // top-left 0
		{+0.5f, +0.5f, +0.5f, 1.f}, // top-right 1
		{-0.5f, -0.5f, +0.5f, 1.f}, // bottom-left 2
		{+0.5f, -0.5f, +0.5f, 1.f}, // bottom-right 3
		
		// back
		{-0.5f, +0.5f, -0.5f, 1.f}, // top-left 4
		{+0.5f, +0.5f, -0.5f, 1.f}, // top-right 5
		{-0.5f, -0.5f, -0.5f, 1.f}, // bottom-left 6
		{+0.5f, -0.5f, -0.5f, 1.f}  // bottom-right 7
	};
	
	const unsigned cubeIndices[] =
	{
		// Front face
		0,	2,	1,
		1,	2,	3,
		
		// Back face
		4,	5,	6,
		5,	7,	6,
		
		// Left face
		4,	6,	0,
		0,	6,	2,
		
		// Right face
		1,	3,	5,
		5,	3,	7,
		
		// Top face
		0,	1,	4,
		1,	5,	4,
		
		// Bottom face
		2,	6,	3,
		3,	6,	7
	};
	
	_cubeMesh.positions.resize(VERTEX_COUNT);
	_cubeMesh.indices.resize(INDEX_COUNT);
	for (int i = 0; i < VERTEX_COUNT; i++)
	{
		_cubeMesh.positions[i] = cubeVertices[i];
	}
	
	for (int i = 0; i < INDEX_COUNT; i++)
	{
		_cubeMesh.indices[i] = cubeIndices[i];
	}
}
} // anut namespace 
