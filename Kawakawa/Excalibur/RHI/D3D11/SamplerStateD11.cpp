#include "SamplerStateD11.h"
#include "GraphicsMgrD11.h"
#include "../../Platform/Application.h"


Excalibur::SamplerStateD11::SamplerStateD11()
{
	Initialize();
}

Excalibur::SamplerStateD11::~SamplerStateD11()
{
	Finialize();
}

void Excalibur::SamplerStateD11::Initialize()
{
	D3D11_SAMPLER_DESC samplerDesc;
	auto mgrd11 = (GraphicsMgrD11*)GApp->mGraphicsManager;
	samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.MipLODBias = 0.0f;
	samplerDesc.MaxAnisotropy = 1;
	samplerDesc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
	samplerDesc.BorderColor[0] = 0;
	samplerDesc.BorderColor[1] = 0;
	samplerDesc.BorderColor[2] = 0;
	samplerDesc.BorderColor[3] = 0;
	samplerDesc.MinLOD = 0;
	samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;
	auto result = mgrd11->m_device->CreateSamplerState(&samplerDesc, &m_sampleState);

	if (FAILED(result)) {
		assert(false);
	}
}

void Excalibur::SamplerStateD11::Finialize()
{
	if (m_sampleState) {
		m_sampleState->Release();
	}
}