SET(prj_name stl2bmp)

PROJECT(${prj_name})

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

#USB;WIN32;_WINDOWS;_DEBUG;_USRDLL;_CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES=1;%(PreprocessorDefinitions)_VISUALC_;NeedFunctionPrototypes;_LIB;_MAGICKLIB_

ADD_DEFINITIONS(-DWIN32)
ADD_DEFINITIONS(-Dstl2bmp_EXPORTS)
#ADD_DEFINITIONS(-D_DEBUG)
ADD_DEFINITIONS(-DNDEBUG)

add_definitions(-D_CONSOLE)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../include/qt/include)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../include/qt/include/QtCore)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../include/qt/include/QtGui)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../include/qt/include/QtOpenGL)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../include/qt/include/QtSvg)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../include/qt/include/QtGui)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../include/qt/include/QtWidgets)


INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/b9layout)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/b9edit)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/b9slice)

set(SRC ${PROJECT_SOURCE_DIR}/b9edit/b9edit.cpp
${PROJECT_SOURCE_DIR}/b9layout/b9layout.cpp
${PROJECT_SOURCE_DIR}/b9layout/b9layoutprojectdata.cpp
${PROJECT_SOURCE_DIR}/b9layout/b9modelinstance.cpp
${PROJECT_SOURCE_DIR}/b9modelloader.cpp
${PROJECT_SOURCE_DIR}/b9modelwriter.cpp
${PROJECT_SOURCE_DIR}/b9supportstructure.cpp
${PROJECT_SOURCE_DIR}/b9layout/b9tesselator.cpp
${PROJECT_SOURCE_DIR}/b9layout/b9verticaltricontainer.cpp
${PROJECT_SOURCE_DIR}/convert.cpp
${PROJECT_SOURCE_DIR}/crushbitmap.cpp
${PROJECT_SOURCE_DIR}/b9edit/DrawingContext.cpp
${PROJECT_SOURCE_DIR}/b9edit/floodfill.cpp
${PROJECT_SOURCE_DIR}/b9layout/geometricfunctions.cpp
${PROJECT_SOURCE_DIR}/loadingbar.cpp
${PROJECT_SOURCE_DIR}/b9layout/loop.cpp
${PROJECT_SOURCE_DIR}/b9layout/modeldata.cpp
${PROJECT_SOURCE_DIR}/OS_Wrapper_Functions.cpp
${PROJECT_SOURCE_DIR}/b9layout/segment.cpp
${PROJECT_SOURCE_DIR}/b9layout/SlcExporter.cpp
${PROJECT_SOURCE_DIR}/b9layout/slice.cpp
${PROJECT_SOURCE_DIR}/b9layout/slicecontext.cpp
${PROJECT_SOURCE_DIR}/b9edit/SliceEditView.cpp
${PROJECT_SOURCE_DIR}/b9layout/sliceset.cpp
${PROJECT_SOURCE_DIR}/stl2bmp.cpp
${PROJECT_SOURCE_DIR}/b9layout/triangle3d.cpp
${PROJECT_SOURCE_DIR}/b9layout/worldview.cpp

)

set(HDR ${PROJECT_SOURCE_DIR}/b9edit/b9edit.h
${PROJECT_SOURCE_DIR}/b9layout/b9layout.h
${PROJECT_SOURCE_DIR}/b9layout/b9layoutprojectdata.h
${PROJECT_SOURCE_DIR}/b9layout/b9modelinstance.h
${PROJECT_SOURCE_DIR}/b9modelloader.h
${PROJECT_SOURCE_DIR}/b9modelwriter.h
${PROJECT_SOURCE_DIR}/b9supportstructure.h
${PROJECT_SOURCE_DIR}/b9layout/b9tesselator.h
${PROJECT_SOURCE_DIR}/b9layout/b9verticaltricontainer.h
${PROJECT_SOURCE_DIR}/convert.h
${PROJECT_SOURCE_DIR}/crushbitmap.h
${PROJECT_SOURCE_DIR}/b9edit/DrawingContext.h
${PROJECT_SOURCE_DIR}/b9edit/floodfill.h
${PROJECT_SOURCE_DIR}/b9layout/geometricfunctions.h
${PROJECT_SOURCE_DIR}/loadingbar.h
${PROJECT_SOURCE_DIR}/b9layout/loop.h
${PROJECT_SOURCE_DIR}/b9layout/modeldata.h
${PROJECT_SOURCE_DIR}/OS_Wrapper_Functions.h
${PROJECT_SOURCE_DIR}/b9layout/segment.h
${PROJECT_SOURCE_DIR}/b9layout/SlcExporter.h
${PROJECT_SOURCE_DIR}/b9layout/slice.h
${PROJECT_SOURCE_DIR}/b9layout/slicecontext.h
${PROJECT_SOURCE_DIR}/b9edit/SliceEditView.h
${PROJECT_SOURCE_DIR}/b9layout/sliceset.h
${PROJECT_SOURCE_DIR}/stl2bmp.h
${PROJECT_SOURCE_DIR}/b9layout/triangle3d.h
${PROJECT_SOURCE_DIR}/b9layout/worldview.h
${PROJECT_SOURCE_DIR}/OS_GL_Wrapper.h
)

#file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}  ../inc/image_convert.h  )
source_group("header" FILES ${HDR})

#file(GLOB SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)
source_group("src" FILES ${SRC})

#file(GLOB RC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}  cbs.rc)
#source_group("resource" FILES ${RC})

#file(GLOB DEF RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} cbs.def)
#source_group("" FILES ${DEF})

#INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../../3rdparty/opencv/build/include)



#LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/../../3rdparty/FreeImage/build/${CMAKE_PLATFORM}/vc9/lib)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/../lib)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/../include/qt/lib)


SET(CMAKE_C_FLAGS "/DWIN32 /D_WINDOWS /W3 /Zm1000")

#ADD_LIBRARY(${prj_name} SHARED ${HDR} ${SRC} ${RC} ${DEF})
ADD_LIBRARY(${prj_name} SHARED ${HDR} ${SRC}  )

# ugly, need change find_package
#
if(CMAKE_BUILD_TYPE MATCHES "Debug")
  set(QT_LIB qtmaind.lib Qt5Cored.lib Qt5Guid.lib Qt5OpenGLd.lib Qt5Svgd.lib Opengl32.lib Glu32.lib Qt5Widgetsd.lib Ws2_32.lib)
  
else()
  set(QT_LIB qtmain.lib Qt5Core.lib Qt5Gui.lib Qt5OpenGL.lib Qt5Svg.lib Opengl32.lib Glu32.lib Qt5Widgets.lib Ws2_32.lib)
  
endif()



TARGET_LINK_LIBRARIES(${prj_name}  ${QT_LIB} )

set(CompilerFlags
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
        )
foreach(CompilerFlag ${CompilerFlags})
  string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
  string(REPLACE "/Ob0" "" ${CompilerFlag} "${${CompilerFlag}}")
  string(REPLACE "/TC" "" ${CompilerFlag} "${${CompilerFlag}}")
  string(REPLACE "/TC" "" ${CompilerFlag} "${${CompilerFlag}}")
endforeach()



MESSAGE(STATUS " stl2bmp dll  ok : " ${CMAKE_CURRENT_SOURCE_DIR})


INSTALL(TARGETS ${prj_name}
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)
