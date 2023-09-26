

workspace "Hazel"
	
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

-- Debug-Windows-64 an example of outputdir
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Hazel"
	location "Hazel"
	kind "SharedLib"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-Int/" .. outputdir .. "/%{prj.name}")
	--pre-compiled header set on project hazel
	pchheader "hzpch.h"
	pchsource "Hazel/src/hzpch.cpp"
	
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
	--system specific defines and commands to be execute from cmd
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22000.0"

		defines 
		{
			"HZ_PLATFORM_WINDOWS" ,
			"HZ_BUILD_DLL"
		}

		postbuildcommands
		{
			"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox"
		}

	--configuration Debug specific defines 
	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"
	--configuration Release specific defines 
	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"
	--configuration Dist specific defines 
	filter "configurations:Dist"
		defines "HZ_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-Int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Hazel/vendor/spdlog/include" , 
		"Hazel/src"
	}

	links 
	{
		"Hazel"
	}


	--system specific defines and commands to be execute from cmd
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22000.0"

		defines 
		{
			"HZ_PLATFORM_WINDOWS" 
		}

	--configuration Debug specific defines 
	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"
	--configuration Release specific defines 
	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"
	--configuration Dist specific defines 
	filter "configurations:Dist"
		defines "HZ_DIST"
		optimize "On"