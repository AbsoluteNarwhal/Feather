workspace "Feather"
	architecture "x64"
	startproject "ExampleApp"
	configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "FeatherEngine/vendor/glfw/include"

include "FeatherEngine/vendor/glfw"

project "FeatherEngine"
	location "FeatherEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir)
	objdir ("bin/int/" .. outputdir .. "/%{prj.name}")

	pchheader "ftpch.h"
	pchsource "FeatherEngine/src/ftpch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"FeatherEngine/src",
		"FeatherEngine/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"FT_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines "FT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FT_RELEASE"
		optimize "On"
		symbols "On"

	filter "configurations:Dist"
		defines "FT_DIST"
		optimize "On"
		symbols "Off"

project "ExampleApp"
	location "%{prj.name}"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir)
	objdir ("bin/int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"FeatherEngine/vendor/spdlog/include",
		"FeatherEngine/src"
	}

	links 
	{
		"FeatherEngine"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		defines "FT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FT_RELEASE"
		optimize "On"
		symbols "On"

	filter "configurations:Dist"
		defines "FT_DIST"
		optimize "On"
		symbols "Off"