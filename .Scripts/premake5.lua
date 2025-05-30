workspace "Frosty515"
    architecture "x64"
    startproject "Compiler"

    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "StandardFileIO"
    location "StandardFileIO"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir)
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "StandardLogger/src"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "F515_PLATFORM_WINDOWS",
            "F515_BUILD_DLL"
        }

    filter "system:linux"
        cppdialect "C++2a"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "F515_PLATFORM_LINUX",
            "F515_BUILD_SO"
        }

    filter { "system:linux", "action:gmake" }
        linkoptions { "`wx-config --libs`", "-pthread" }

    filter "configurations:Debug"
        defines "F515_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "F515_RELEASE"
        optimize "On"

project "StandardLogger"
    location "StandardLogger"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir)
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "StandardFileIO/src"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "F515_PLATFORM_WINDOWS",
            "F515_BUILD_DLL"
        }

    filter "system:linux"
        cppdialect "C++2a"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "F515_PLATFORM_LINUX",
            "F515_BUILD_SO"
        }

    filter { "system:linux", "action:gmake" }
        linkoptions { "`wx-config --libs`", "-pthread" }

    filter "configurations:Debug"
        defines "F515_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "F515_RELEASE"
        optimize "On"

project "Compiler"
    location "Compiler"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir)
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "StandardFileIO/src",
        "StandardLogger/src"
    }

    links
    {
        "StandardFileIO",
        "StandardLogger"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "F515_PLATFORM_WINDOWS"
        }

    filter "system:linux"
        cppdialect "C++2a"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "F515_PLATFORM_LINUX"
        }

    filter { "system:linux", "action:gmake" }
        linkoptions { "`wx-config --libs`", "-pthread" }

    filter "configurations:Debug"
        defines "F515_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "F515_RELEASE"
        optimize "On"
