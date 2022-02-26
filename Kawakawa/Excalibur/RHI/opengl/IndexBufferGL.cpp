#include "IndexBufferGL.h"

namespace Excalibur
{
	IndexBufferGL::IndexBufferGL(void* data, unsigned int count, IndexFormat iformat)
	{
		Initialize(data, count, iformat);
	}

	IndexBufferGL::~IndexBufferGL()
	{
		Finialize();
	}

	void IndexBufferGL::Initialize(void* data, unsigned int count, IndexFormat iformat)
	{
		IndexBuffer::Initialize(data, count, iformat);
		glGenBuffers(1, &mVEO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mVEO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * 4, data, GL_STATIC_DRAW);	// count * 4 == datasize

	}

	void IndexBufferGL::Finialize()
	{
		glDeleteBuffers(1, &mVEO);
	}

}