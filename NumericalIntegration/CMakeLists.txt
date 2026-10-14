add_library(NumericalIntegration STATIC
    src/NumericalIntegration.cpp
)
target_include_directories(NumericalIntegration PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
