workspace "Game-o-mat"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Distribution"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Game-o-mat/vendor/GLFW/include"

include "Game-o-mat/vendor/GLFW"

project "Game-o-mat"
	location "Game-o-mat"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "gompch.h"
	pchsource "Game-o-mat/src/gompch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links 
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows" 
		cppdialect "C++17"	
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GOM_PLATFORM_WINDOWS",
			"GOM_BUILD_DLL"
		}
		
		postbuildcommands 
		{
			("{MKDIR} ../bin/" .. outputdir .. "/Sandbox"),
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "GOM_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "GOM_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Distribution"
		defines "GOM_DISTRIBUTION"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Game-o-mat/vendor/spdlog/include",
		"Game-o-mat/src"
	}

	links 
	{
		"Game-o-mat"
	}

	filter "system:windows" 
		cppdialect "C++17"	
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"GOM_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "GOM_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "GOM_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Distribution"
		defines "GOM_DISTRIBUTION"
		buildoptions "/MD"
		optimize "On"