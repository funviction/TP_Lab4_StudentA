add_library(NumericalIntegration SHARED
    src/NumericalIntegration.cpp
)
target_include_directories(NumericalIntegration PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
target_compile_definitions(NumericalIntegration PRIVATE NUMERICALINTEGRATION_EXPORTS)
