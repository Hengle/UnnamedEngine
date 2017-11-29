#pragma once
#include "Engine/Base/Common/Common.h"

#include <memory>
#include <glad/glad.h>

class MeshResource;

class GLMesh
{
public:
	GLMesh(const std::weak_ptr<MeshResource>& resource);
	void Free();
	size_t GetSize() const;

private:
	size_t mSize;
	GLuint mVertices;
	GLuint mIndices;
};