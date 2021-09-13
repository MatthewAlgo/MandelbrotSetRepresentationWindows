cmake_minimum_required(VERSION 3.0.0)
project(MandelbrotSetRepresentationWindows VERSION 0.1.0)

if(WIN32) # IF WE ARE ON WINDOWS

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_TOOLCHAIN_FILE "E:/_WINDOWS_DATA_/VCPKG_PACKAGE_MANAGER/scripts/buildsystems/vcpkg.cmake")

INCLUDE_DIRECTORIES(
    E:/_WINDOWS_DATA_/VCPKG_PACKAGE_MANAGER/installed/x86-windows/include
)

LINK_DIRECTORIES(
    E:/_WINDOWS_DATA_/VCPKG_PACKAGE_MANAGER/installed/x86-windows/lib
)


add_executable(MandelbrotSetRepresentationWindows 
# SOURCES

WinBGIFilesDIR/WORKING_SOURCE_FILE.cpp # MAIN SOURCE FILE
WinBGIFilesDIR/bgiout.cxx
WinBGIFilesDIR/dibutil.cxx
WinBGIFilesDIR/drawing.cxx
WinBGIFilesDIR/file.cxx
WinBGIFilesDIR/main.cxx
WinBGIFilesDIR/misc.cxx
WinBGIFilesDIR/mouse.cxx
WinBGIFilesDIR/palette.cxx
WinBGIFilesDIR/text.cxx
WinBGIFilesDIR/winbgi.cxx
WinBGIFilesDIR/winthread.cxx

# HEADERS
WinBGIFilesDIR/dibapi.h
WinBGIFilesDIR/dibutil.h
WinBGIFilesDIR/graphics.h
WinBGIFilesDIR/winbgi.h
WinBGIFilesDIR/winbgim.h
WinBGIFilesDIR/winbgitypes.h

)

# For SFML
# find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED) # REQUIRED FOR DLL's

TARGET_LINK_LIBRARIES( MandelbrotSetRepresentationWindows  PRIVATE
    # sfml-graphics
    # sfml-system
    # sfml-audio
    # sfml-window
)

ADD_TEST(NAME MandelbrotSetRepresentationWindows  COMMAND MandelbrotSetRepresentationWindows )

INSTALL(TARGETS MandelbrotSetRepresentationWindows  DESTINATION "Binaries")

endif()