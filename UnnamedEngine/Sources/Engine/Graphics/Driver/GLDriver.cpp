#include "GLDriver.h"

#include <GLFW/glfw3.h>

#include "Engine/Graphics/Driver/GLMesh.h"
#include "Engine/Graphics/Driver/GLProgram.h"
#include "Engine/Graphics/Driver/GLShader.h"
#include "Engine/Graphics/Driver/GLAttributes.h"


void GLDriver::ClearResources()
{
	for(auto& mesh : mMeshes)
	{
		mesh.Free();
	}
	for(auto& program: mPrograms)
	{
		program.Free();
	}
	for(auto& attribute : mAttributes)
	{
		attribute.Free();
	}

	mMeshes.clear();
	mPrograms.clear();
	mAttributes.clear();
}

Ptr<GLMesh> GLDriver::CreateMesh(const std::weak_ptr<MeshResource>& meshResource)
{
	mMeshes.push_back(GLMesh(meshResource));
	return(&mMeshes.back());
}

Ptr<GLProgram> GLDriver::CreateProgram(
	const std::weak_ptr<ShaderResource>& vertShader,
	const std::weak_ptr<ShaderResource>& fragShader
)
{
	// need to use emplace_back here since program is noncopyable
	GLProgram program;
	GLShader vert(vertShader);
	GLShader frag(fragShader);
	program.RegisterShader(vert);
	program.RegisterShader(frag);
	program.Link();
	vert.Free();
	frag.Free();

	mPrograms.emplace_back(std::move(program));

	return(&mPrograms.back());
}

Ptr<GLAttributes> GLDriver::CreateAttributes()
{
	GLAttributes attributes;
	mAttributes.push_back(std::move(attributes));
	return(&mAttributes.back());
}

void GLDriver::SwapBuffers(GLFWwindow* window)
{
	glfwSwapBuffers(window);
}