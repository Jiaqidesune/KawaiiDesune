#pragma once
#include "..//GraphicsMgr.h"
#include "../../Core/Math/KawaiiMath.h"

namespace Excalibur{
	
	class GraphicsMgrGL : public GraphicsManager
	{

	public:
		virtual	int	Initialize();
		virtual	void Finalize();
		virtual	void Tick();

		virtual	void Present();
		virtual	void ClearRenderTarget(float r, float g, float b, float a) ;

		virtual	std::shared_ptr<VertexBuffer> CreateVertexBuffer(void* data, int count, VertexFormat vf);

		virtual	std::shared_ptr<IndexBuffer> CreateIndexBuffer(void* data, int count, IndexFormat iformat);

		virtual	std::shared_ptr<RenderMesh>	CreateRenderMesh(aiMesh* mesh, const aiScene* world);
		virtual	std::shared_ptr<RenderMesh>	CreateRenderMeshDebug(void* data, int count, VertexFormat vf);

		virtual	std::shared_ptr<Texture> CreateTexture2D(const std::string& path)  ;
		virtual	std::shared_ptr<SamplerState> CreateSamplerState()  ;

		virtual	void LoadShaders() ;
		virtual	void UseShader(std::shared_ptr<Shader>);
		virtual	std::shared_ptr<Shader> GetShader(const std::string& shaderName);

		virtual	void	Draw(unsigned int vcount, unsigned int start);
		virtual	void	DrawIndexed(unsigned int icount, unsigned int start, int baseLoc);
	};
}