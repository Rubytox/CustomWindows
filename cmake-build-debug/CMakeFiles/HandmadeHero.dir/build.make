# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\cFAG\Documents\CustomWindows

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\cFAG\Documents\CustomWindows\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\HandmadeHero.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\HandmadeHero.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\HandmadeHero.dir\flags.make

CMakeFiles\HandmadeHero.dir\main.cpp.obj: CMakeFiles\HandmadeHero.dir\flags.make
CMakeFiles\HandmadeHero.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\cFAG\Documents\CustomWindows\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HandmadeHero.dir/main.cpp.obj"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1413~1.261\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\HandmadeHero.dir\main.cpp.obj /FdCMakeFiles\HandmadeHero.dir\ /FS -c C:\Users\cFAG\Documents\CustomWindows\main.cpp
<<

CMakeFiles\HandmadeHero.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HandmadeHero.dir/main.cpp.i"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1413~1.261\bin\Hostx86\x86\cl.exe > CMakeFiles\HandmadeHero.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\cFAG\Documents\CustomWindows\main.cpp
<<

CMakeFiles\HandmadeHero.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HandmadeHero.dir/main.cpp.s"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1413~1.261\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\HandmadeHero.dir\main.cpp.s /c C:\Users\cFAG\Documents\CustomWindows\main.cpp
<<

CMakeFiles\HandmadeHero.dir\Logger.cpp.obj: CMakeFiles\HandmadeHero.dir\flags.make
CMakeFiles\HandmadeHero.dir\Logger.cpp.obj: ..\Logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\cFAG\Documents\CustomWindows\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/HandmadeHero.dir/Logger.cpp.obj"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1413~1.261\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\HandmadeHero.dir\Logger.cpp.obj /FdCMakeFiles\HandmadeHero.dir\ /FS -c C:\Users\cFAG\Documents\CustomWindows\Logger.cpp
<<

CMakeFiles\HandmadeHero.dir\Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HandmadeHero.dir/Logger.cpp.i"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1413~1.261\bin\Hostx86\x86\cl.exe > CMakeFiles\HandmadeHero.dir\Logger.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\cFAG\Documents\CustomWindows\Logger.cpp
<<

CMakeFiles\HandmadeHero.dir\Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HandmadeHero.dir/Logger.cpp.s"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1413~1.261\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\HandmadeHero.dir\Logger.cpp.s /c C:\Users\cFAG\Documents\CustomWindows\Logger.cpp
<<

CMakeFiles\HandmadeHero.dir\OffscreenBuffer.cpp.obj: CMakeFiles\HandmadeHero.dir\flags.make
CMakeFiles\HandmadeHero.dir\OffscreenBuffer.cpp.obj: ..\OffscreenBuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\cFAG\Documents\CustomWindows\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/HandmadeHero.dir/OffscreenBuffer.cpp.obj"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1413~1.261\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\HandmadeHero.dir\OffscreenBuffer.cpp.obj /FdCMakeFiles\HandmadeHero.dir\ /FS -c C:\Users\cFAG\Documents\CustomWindows\OffscreenBuffer.cpp
<<

CMakeFiles\HandmadeHero.dir\OffscreenBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HandmadeHero.dir/OffscreenBuffer.cpp.i"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1413~1.261\bin\Hostx86\x86\cl.exe > CMakeFiles\HandmadeHero.dir\OffscreenBuffer.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\cFAG\Documents\CustomWindows\OffscreenBuffer.cpp
<<

CMakeFiles\HandmadeHero.dir\OffscreenBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HandmadeHero.dir/OffscreenBuffer.cpp.s"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1413~1.261\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\HandmadeHero.dir\OffscreenBuffer.cpp.s /c C:\Users\cFAG\Documents\CustomWindows\OffscreenBuffer.cpp
<<

# Object files for target HandmadeHero
HandmadeHero_OBJECTS = \
"CMakeFiles\HandmadeHero.dir\main.cpp.obj" \
"CMakeFiles\HandmadeHero.dir\Logger.cpp.obj" \
"CMakeFiles\HandmadeHero.dir\OffscreenBuffer.cpp.obj"

# External object files for target HandmadeHero
HandmadeHero_EXTERNAL_OBJECTS =

HandmadeHero.exe: CMakeFiles\HandmadeHero.dir\main.cpp.obj
HandmadeHero.exe: CMakeFiles\HandmadeHero.dir\Logger.cpp.obj
HandmadeHero.exe: CMakeFiles\HandmadeHero.dir\OffscreenBuffer.cpp.obj
HandmadeHero.exe: CMakeFiles\HandmadeHero.dir\build.make
HandmadeHero.exe: CMakeFiles\HandmadeHero.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\cFAG\Documents\CustomWindows\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable HandmadeHero.exe"
	"C:\Program Files\JetBrains\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\HandmadeHero.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100162~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100162~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1413~1.261\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\HandmadeHero.dir\objects1.rsp @<<
 /out:HandmadeHero.exe /implib:HandmadeHero.lib /pdb:C:\Users\cFAG\Documents\CustomWindows\cmake-build-debug\HandmadeHero.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:windows  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\HandmadeHero.dir\build: HandmadeHero.exe

.PHONY : CMakeFiles\HandmadeHero.dir\build

CMakeFiles\HandmadeHero.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\HandmadeHero.dir\cmake_clean.cmake
.PHONY : CMakeFiles\HandmadeHero.dir\clean

CMakeFiles\HandmadeHero.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\cFAG\Documents\CustomWindows C:\Users\cFAG\Documents\CustomWindows C:\Users\cFAG\Documents\CustomWindows\cmake-build-debug C:\Users\cFAG\Documents\CustomWindows\cmake-build-debug C:\Users\cFAG\Documents\CustomWindows\cmake-build-debug\CMakeFiles\HandmadeHero.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\HandmadeHero.dir\depend

