workspace "FLORA"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "FLORA"
	location "FLORA"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	postbuildcommands {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/%{cfg.buildcfg}-windows-x86_64/SandBox/")
    }

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions { "/utf-8" }

	defines
	{
		"FL_PLATFORM_WINDOWS",
		"FL_BUILD_DLL"
	}

	

	filter "configurations:Debug"
		defines "FL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FL_DIST"
		optimize "On"

project "SandBox"
	location "SandBox"
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
		"FLORA/vendor/spdlog/include",
		"FLORA/src"
	}

	

	links
	{
		"FLORA"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		buildoptions { "/utf-8" }

	defines
	{
		"FL_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "FL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FL_DIST"
		optimize "On"