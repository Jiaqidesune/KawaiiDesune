#pragma once

#include "../Image.h"
#include "../../Core/Buffer.h"

namespace Kawaii::Asset
{
	enum class ImageFormat : unsigned
	{
		PNG,
		JPEG,
		TGA,
		BMP,
		NUM_SUPPORT
	};

	class ImageParser
	{
	public:
		virtual Image Parse(const Core::Buffer& buf) = 0;
		virtual ~ImageParser() = default;
	};
}