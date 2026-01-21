workspace "QQGameEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "QQGameEngine/vendor/GLFW/include"

include "QQGameEngine/vendor/GLFW"

project "QQGameEngine"
    location "QQGameEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "pch.h"
    pchsource "%{prj.name}/src/pch.cpp"

    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "off"

        buildoptions { "/utf-8" }

        defines 
        {
            "QQH_PLATFORM_WINDOWS",
            "QQH_BUILD_DLL"
        }

        postbuildcommands
        {
            "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/DemoGame"
        }

    filter "configurations:Debug"
        defines "QQH_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "QQH_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "QQH_DIST"
        optimize "On"

project "DemoGame"
    location "DemoGame"
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
        "QQGameEngine/vendor/spdlog/include",
        "QQGameEngine/src"
    }

    links
    {
        "QQGameEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"

        buildoptions { "/utf-8" }

        defines 
        {
            "QQH_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "QQH_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "QQH_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "QQH_DIST"
        optimize "On"
