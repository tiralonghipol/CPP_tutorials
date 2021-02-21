include_directories(
    include 
)
add_executable(conditional_compiling src/conditional_compiling.cpp)

string(ASCII 27 Esc)
option(USE_OCTOMAP "Use OCTOMAP") #accept -DUSE_OCTOMAP=ON/OFF from command line
option(USE_VDB_EDT "Use VDB_EDT") #accept -DUSE_VDB_EDT=ON/OFF from command line
option(USE_VOXBLOX "Use VOXBLOX") #accept -DUSE_VOXBLOX=ON/OFF from command line

if(USE_OCTOMAP)
    message("${Esc}[1;33m Building with USE_OCTOMAP ${Esc}[m")
    add_definitions(-DUSE_OCTOMAP=${USE_OCTOMAP}) # 0
elseif(USE_VDB_EDT)
    message("${Esc}[1;33m Building with USE_VDB_EDT ${Esc}[m")
    add_definitions(-DUSE_VDB_EDT=${USE_VDB_EDT}) # 1
elseif(USE_VOXBLOX)
    message("${Esc}[1;33m Building with USE_VOXBLOX ${Esc}[m")
    add_definitions(-DUSE_VOXBLOX=${USE_VOXBLOX}) # 1
endif()


