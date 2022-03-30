#pragma once

// here we include our precompiled static headers that we use in our (mostly cpp) implementation

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "GameOMat/Log.h"

// windows specific import, later on we can implement more platform dependecies

#ifdef GOM_PLATFORM_WINDOWS
	#include <Windows.h>
#endif // GOM_
