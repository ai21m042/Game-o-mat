workspace "Game-o-mat"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Distribution"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Game-o-mat"
	location "Game-o-mat"
	kind "SharedLib"
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
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
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
		symbols "On"

	filter "configurations:Release"
		defines "GOM_RELEASE"
		optimize "On"

	filter "configurations:Distribution"
		defines "GOM_DISTRIBUTION"
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
		symbols "On"

	filter "configurations:Release"
		defines "GOM_RELEASE"
		optimize "On"

	filter "configurations:Distribution"
		defines "GOM_DISTRIBUTION"
		optimize "On"