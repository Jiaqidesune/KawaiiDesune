#pragma once

#define D3D12MA_D3D12_HEADERS_ALREADY_INCLUDED
#include "D3D12MemAlloc.h"

using namespace Microsoft::WRL;

namespace RHI
{
	class GraphicCore
	{
		static constexpr UINT CMD_LIST_COUNT = 8;
		static constexpr UINT BACKBUFFER_COUNT = 3;

		struct FrameResources
		{
			ComPtr<ID3D12Resource> m_backBuffer;
			
			ComPtr<ID3D12CommandAllocator> m_default_cmd_Allocator;
			ComPtr<ID3D12GraphicsCommandList4> m_default_cmd_List;

			ComPtr<ID3D12CommandAllocator>      m_cmd_allocators[CMD_LIST_COUNT] = {};
			ComPtr<ID3D12GraphicsCommandList4>  m_cmd_lists[CMD_LIST_COUNT] = {};
			UINT cmd_list_index = 0;

			ComPtr<ID3D12CommandAllocator>		m_compute_cmd_llocators[CMD_LIST_COUNT] = {};
			ComPtr<ID3D12GraphicsCommandList4>  m_compute_cmd_lists[CMD_LIST_COUNT] = {};
			UINT compute_cmd_list_index = 0;
		};

	public:
		GraphicCore(void* window_handle);
		GraphicCore(GraphicCore const&) = delete;
		GraphicCore(GraphicCore&&) = default;
		~GraphicCore();

		ID3D12Device5* GetDevice() const { return m_device.Get(); }

		void ResetDefaultCommandList();
		void ExecuteDefaultCommandList();

	private:
		FrameResources& GetFrameResources();
		const FrameResources& GetFrameResources() const;

		void ExecuteGraphicsCommandLists();
		void ExecuteComputeCommandLists();
	private:

		UINT width, height;
		UINT m_backBufferIndex;
		UINT m_Last_backBufferIndex;

		ComPtr<ID3D12Device5> m_device;
		ComPtr<IDXGISwapChain3> m_swapChain;

		// Frame Resources
		FrameResources frames[BACKBUFFER_COUNT];

		// Commands Queue
		ComPtr<ID3D12CommandQueue> m_graphicQueue;
		ComPtr<ID3D12CommandQueue> m_computeQueue;

		// Sync
		Microsoft::WRL::ComPtr<ID3D12Fence> m_frameFence[BACKBUFFER_COUNT];
		HANDLE m_frameFenceEvent[BACKBUFFER_COUNT];
		UINT64 m_frameFenceValues[BACKBUFFER_COUNT];
		UINT64 m_frameFenceValue;

		Microsoft::WRL::ComPtr<ID3D12Fence> m_waitFence = nullptr;
		HANDLE m_waitEvent = nullptr;
		UINT64 m_waitFenceValue = 0;
	};
}