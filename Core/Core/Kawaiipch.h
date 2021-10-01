#pragma once

// STL
#include <algorithm>
#include <array>
#include <atomic>
#include <execution>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <map>
#include <stdexcept>
#include <string>
#include <thread>
#include <type_traits>
#include <unordered_map>
#include <vector>

// DirectX
#include <d3d12.h>
#include <d3dcompiler.h>
#include <dxgi1_6.h>
#include <dxgidebug.h>
#include <pix3.h>

// Windows
#define NOMINMAX
#define NODRAWTEXT
#define NOGDI
#define NOMCX
#define NOSERVICE
#define NOHELP
#include <windows.h>
#include <WindowsX.h>
#include <wrl.h>
#include <pathcch.h>
#include <shellapi.h>
#include <intrin.h>
#include <xmmintrin.h>

#include "Common/Config.h"
#include "Common/ProjectHelper.h"