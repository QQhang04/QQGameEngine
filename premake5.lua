workspace "QQGameEngine"
    architecture "x64"
    startproject "DemoGame"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "QQGameEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "QQGameEngine/vendor/glad/include"
IncludeDir["ImGui"] = "QQGameEngine/vendor/imgui"
IncludeDir["glm"] = "QQGameEngine/vendor/glm"

group "Dependencies"
    include "QQGameEngine/vendor/GLFW"
    include "QQGameEngine/vendor/glad"
    include "QQGameEngine/vendor/imgui"

group ""

project "QQGameEngine"
    location "QQGameEngine"
    kind "SharedLib"
    language "C++"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "pch.h"
    pchsource "QQGameEngine/src/pch.cpp"

    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"

        buildoptions { "/utf-8" }

        defines 
        {
            "QQH_PLATFORM_WINDOWS",
            "QQH_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            "{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/DemoGame/\""
        }

    filter "configurations:Debug"
        defines "QQH_DEBUG"
        runtime "Debug"
        symbols "On"
    
    filter "configurations:Release"
        defines "QQH_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "QQH_DIST"
        runtime "Release"
        optimize "On"

project "DemoGame"
    location "DemoGame"
    kind "ConsoleApp"

    language "C++"
    staticruntime "off"

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
        "QQGameEngine/src",
        "QQGameEngine/vendor",
        "%{IncludeDir.glm}"
    }

    links
    {
        "QQGameEngine"
    }

    filter "system:windows"
        cppdialect "C++17"

        buildoptions { "/utf-8" }

        defines 
        {
            "QQH_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "QQH_DEBUG"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines "QQH_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "QQH_DIST"
        runtime "Release"
        optimize "On"
