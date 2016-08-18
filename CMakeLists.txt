set(GIT_IS_NOT_NEEDED_I_WILL_DOWNLOAD_EVERYTHING_MANUALLY FALSE CACHE BOOL "Do not clone git repos for shims, I'll do it manually")
if(NOT GIT_IS_NOT_NEEDED_I_WILL_DOWNLOAD_EVERYTHING_MANUALLY)
	FIND_PACKAGE(Git REQUIRED)
endif()
if(GIT_FOUND)
	execute_process(
		COMMAND ${GIT_EXECUTABLE} submodule update --recursive
		RESULT_VARIABLE GIT_RESULT
		ERROR_QUIET
	)
	if(NOT GIT_RESULT EQUAL 0)
		message(WARNING "git failed to update submodules")
	endif()
else(GIT_FOUND)
	message(WARNING "git NOT found, so failed to update submodules")
endif(GIT_FOUND)

file(GLOB shimIncludeDirs "${nixShims4Windows_DIR}/include" "${nixShims4Windows_DIR}/sources/dirent/include" "${nixShims4Windows_DIR}/sources/wingetopt/src")


file(GLOB shimDefs "${nixShims4Windows_DIR}/lib/*.def")
file(GLOB shimLibs "${nixShims4Windows_DIR}/lib/*.lib")
file(GLOB shimSources "${nixShims4Windows_DIR}/src/*.c" "${nixShims4Windows_DIR}/sources/wingetopt/src/*.c")
file(GLOB shimHeaders
	"${nixShims4Windows_DIR}/include/*.h"
	"${nixShims4Windows_DIR}/sources/dirent/include/*.h"
	"${nixShims4Windows_DIR}/sources/wingetopt/src/*.h"
)
#message(STATUS "${shimDefs} ${shimLibs} ${shimSources} ${shimHeaders} ${shimIncludeDirs}")