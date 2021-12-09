#pragma once

#include "../GraphicsMgr.h"

namespace Excalibur
{
	class GraphicsMgrGL : public GraphicsManager
	{
	public:
		virtual	int	Initialize() noexcept;
		virtual	void Finalize() noexcept;
		virtual	void Tick() noexcept;

		virtual	void Present();
		virtual	void ClearRenderTarget(float r, float g, float b, float a);


		virtual std::shared_ptr<VertexBufferBase> CreateVertexBuffer(void* data, int count, VertexFormat vf);
		virtual std::shared_ptr<IndexBufferBase> CreateIndexBuffer(void* data, int count);
		virtual std::shared_ptr<TextureBase> CreateTexture2D(const std::string& path);

		virtual	std::shared_ptr<MeshBase> CreateRenderMesh(aiMesh* mesh, const aiScene* world);

		virtual void LoadShader();
		virtual void UseShader(std::shared_ptr<ShaderBase> shader);
		virtual std::shared_ptr<ShaderBase> GetShader(const std::string& name);
	};
}