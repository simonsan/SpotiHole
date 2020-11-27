#pragma once

#define DEBUG

//Base
#include <Windows.h>
#include <iostream>
#include <thread>
#include <d3d9.h>
#include <fstream>

//Utils
#include "..\Utils\Utils.hpp"
#include "..\Utils\Hooking.hpp"

//Patches
#include "..\Modules\Initialization.hpp"
#include "..\Modules\AutoUpdates.hpp"
#include "..\Modules\AdBlock.hpp"
#include "..\Modules\Functions.hpp"
#include "..\Modules\QuickPatch.hpp"

