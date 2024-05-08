project(MachineLib)

set(SOURCE_FILES
        pch.h
        IMachineSystem.h
        MachineSystemFactory.cpp MachineSystemFactory.h
        MachineStandin.cpp MachineStandin.h
        Polygon.cpp Polygon.h
        MachineDialog.cpp MachineDialog.h include/machine-api.h
        MachineSystemStandin.cpp
        MachineSystemStandin.h
        Const.cpp
        Const.h
        MachineSystem.cpp
        MachineSystem.h
        Machine.cpp
        Machine.h
        Machine1Factory.cpp
        Machine1Factory.h
        Machine2Factory.cpp
        Machine2Factory.h
        Component.cpp
        Component.h
        Shape.cpp
        Shape.h
        Motor.cpp
        Motor.h
        MotionSource.cpp
        MotionSource.h
        IMotionSink.h
        Pulley.cpp
        Pulley.h
        SnowBlowerBody.cpp
        SnowBlowerBody.h
        Snow.cpp
        Snow.h
)

# Removed:
# Motor.cpp Motor.h Pulley.cpp Pulley.h

find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)
include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
