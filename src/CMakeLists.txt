SET(Python_ADDITIONAL_VERSIONS 3.6)
FIND_PACKAGE(PythonLibs 3 REQUIRED)

FILE(GLOB SRC
    *
    NVIM/*
    ) 

ADD_EXECUTABLE(${PROJECT_NAME} ${SRC})
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/plog/include
    ${CMAKE_INSTALL_PREFIX}/include
    ${PYTHON_INCLUDE_DIRS}
    #${CMAKE_INSTALL_PREFIX}/include/python3.6
    )

TARGET_LINK_LIBRARIES(${PROJECT_NAME} PRIVATE 
    general
    OPENGL32
    ${PYTHON_LIBRARIES}
    debug
    #${CMAKE_INSTALL_PREFIX}/debug/lib/python36_d.lib
    ${CMAKE_INSTALL_PREFIX}/debug/lib/sfml-system-d.lib
    ${CMAKE_INSTALL_PREFIX}/debug/lib/sfml-graphics-d.lib
    ${CMAKE_INSTALL_PREFIX}/debug/lib/sfml-window-d.lib
    optimized
    #${CMAKE_INSTALL_PREFIX}/lib/python36.lib
    ${CMAKE_INSTALL_PREFIX}/lib/sfml-system.lib
    ${CMAKE_INSTALL_PREFIX}/lib/sfml-graphics.lib
    ${CMAKE_INSTALL_PREFIX}/lib/sfml-window.lib
    )

