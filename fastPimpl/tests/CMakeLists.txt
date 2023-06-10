include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG 58d77fa8070e8cec2dc1ed015d66b454c8d78850 #release-1.12.1
)
FetchContent_MakeAvailable(googletest)

add_executable(unit_tests test.cpp)
target_link_libraries(unit_tests PRIVATE gtest_main FastPimpl)
include(GoogleTest)
gtest_discover_tests(unit_tests)