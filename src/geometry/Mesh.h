#if not defined(ANUT_MESH_H)
#define ANUT_MESH_H
#include <vector>

namespace anut
{
class Vec4;

class Mesh
{
public:
	Mesh();
	
//	void rotate();
//	void scale();
//	void translate();
	
	void addPosition(const anut::Vec4& pos);
	void addColor(const anut::Vec4& normalizedRgba);
	void addNormal(const anut::Vec4& n);
//	void addTexCoord(const glm::vec2& texCoord);
	
//	void computeNormals();
	
	int getVertexCount();
	int getIndexCount();

	std::vector<unsigned> indices;
	std::vector<anut::Vec4> positions;
	std::vector<anut::Vec4> colors;
	std::vector<anut::Vec4> normals;
};

inline void Mesh::addPosition(const anut::Vec4& pos)
{
	positions.push_back(pos);
}

inline void Mesh::addColor(const anut::Vec4& normalizedRgba)
{
	colors.push_back(normalizedRgba);
}

inline void Mesh::addNormal(const anut::Vec4& n)
{
	normals.push_back(n);
}

inline int Mesh::getVertexCount()
{
	return positions.size();
}

inline int Mesh::getIndexCount()
{
	return indices.size();
}

} // anut namespace

#endif
