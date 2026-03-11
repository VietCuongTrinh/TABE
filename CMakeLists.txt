cmake_minimum_required(VERSION 3.16)
project(MTBE LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --------- Homebrew prefix ----------
# Apple Silicon: /opt/homebrew
# Intel Mac:     /usr/local
if (EXISTS "/opt/homebrew")
    set(HOMEBREW_PREFIX "/opt/homebrew")
else()
    set(HOMEBREW_PREFIX "/usr/local")
endif()

# --------- Include directories ----------
include_directories(
        ${HOMEBREW_PREFIX}/include
)

# --------- Library directories ----------
link_directories(
        ${HOMEBREW_PREFIX}/lib
)

# --------- Executable ----------
add_executable(MTBE
        main.cpp
        setup.cpp
        keygen.cpp
        encrypt.cpp
        decrypt.cpp
)

# --------- Link libraries ----------
target_link_libraries(MTBE
        pbc
        gmp
)
