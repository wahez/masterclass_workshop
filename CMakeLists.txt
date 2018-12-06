cmake_minimum_required(VERSION 2.8)

project(workshop)
set(CMAKE_CXX_STANDARD 14)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
	add_definitions("-Wall -Wextra -Werror -fno-omit-frame-pointer")
endif()

set(sources
	card.h
	card.cc
	cards.h
	cards.cc
	card_collection.h
	card_generator.h
	card_generator.cc
	main.cc
)

add_executable(workshop ${sources})

find_package(Threads)

option(BENCHMARK_ENABLE_TESTING "Enable testing of the benchmark library." OFF)
add_subdirectory(benchmark)
target_link_libraries(workshop
	benchmark
	${CMAKE_THREAD_LIBS_INIT})

