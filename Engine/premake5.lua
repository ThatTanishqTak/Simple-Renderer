project "Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputDir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputDir .. "/%{prj.name}")

    files
	{
		"src/**.h",
		"src/**.cpp"
	}

    defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

    includedirs
	{
		"src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.glad}"
    }

    links
	{
		"GLFW",
		"glad",
        "opengl32.lib"
    }

    filter "system:windows"
		systemversion "latest"

		defines
		{
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"