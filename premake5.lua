

workspace "text_editor"
    architecture "x64"
    startproject "prj_test"


    configurations 
    {
        "Debug",
        "Release"
    }

    flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
IncludeDir = {}
IncludeDir["GLFW"] = "deps/glfw/include"
IncludeDir["Glad"] =  "deps/glad/include"
IncludeDir["glm"] =  "deps/glm"
IncludeDir["LibLogLaugh"] = "deps/LibLogLaugh/include"
IncludeDir["freetype"] =  "deps/freetype/include"


group "Dependencies"
    include "deps/Glfw"
    include "deps/Glad"
    include "deps/LibLogLaugh"
group ""
       
project "text_editor"
    location "text_editor"
    kind "ConsoleApp"
    language "c++"
    cppdialect "C++17"
    staticruntime "on"
    

    targetdir ("bin/" .. "/%{prj.name}")
	objdir ("bin/int/" ..  "/%{prj.name}")
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{IncludeDir.glm}/glm/**.hpp",
        "%{IncludeDir.glm}/glm/**.inl"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS",
        "WIN32",
        "NDEBUG",
        "_CRT_SECURE_NO_WARNINGS"        
    }

    includedirs
    {
        "%{prj.name}/src/",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.freetype}",
        "%{IncludeDir.LibLogLaugh}"

    }
    libdirs 
    { 
        "deps/freetype/Lib"
    }
    links
    {
        "GLFW",
		"Glad",
        "opengl32",
        "freetype",
        "LibLogLaugh"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        defines "TEXT_D"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "TEXT_R"
        runtime "Release"
        symbols "on"