cmake_minimum_required(VERSION 3.0)
project(Natrix)
set(CMAKE_CXX_STANDARD 20)
add_executable(Natrix src/main.cpp

        src/ANSI.hpp

        src/Engine/Base/PositionRepresentation/Bitboard.hpp
        src/Engine/Base/PositionRepresentation/Pieces.hpp src/Engine/Base/PositionRepresentation/Pieces.cpp
        src/Engine/Base/PositionRepresentation/ZobristHashConstants.hpp
        src/Engine/Base/PositionRepresentation/ZobristHash.hpp src/Engine/Base/PositionRepresentation/ZobristHash.cpp
        src/Engine/Base/PositionRepresentation/RepetitionHistory.hpp src/Engine/Base/PositionRepresentation/RepetitionHistory.cpp
        src/Engine/Base/PositionRepresentation/Move.hpp src/Engine/Base/PositionRepresentation/Move.cpp
        src/Engine/Base/PositionRepresentation/Position.hpp src/Engine/Base/PositionRepresentation/Position.cpp

        src/Engine/Base/MoveGeneration/KnightMasks.hpp
        src/Engine/Base/MoveGeneration/KingMasks.hpp
        src/Engine/Base/MoveGeneration/SlidersMasks.hpp
        src/Engine/Base/MoveGeneration/PsLegalMoveMaskGen.hpp src/Engine/Base/MoveGeneration/PsLegalMoveMaskGen.cpp
        src/Engine/Base/MoveGeneration/MoveList.hpp src/Engine/Base/MoveGeneration/MoveList.cpp
        src/Engine/Base/MoveGeneration/LegalMoveGen.hpp src/Engine/Base/MoveGeneration/LegalMoveGen.cpp
        src/Engine/Base/MoveGeneration/LegalMoveGenTester.hpp src/Engine/Base/MoveGeneration/LegalMoveGenTester.cpp

        src/Engine/AI/PassedPawnMasks.hpp
        src/Engine/AI/PawnShieldMasks.hpp
        src/Engine/AI/StaticEvaluator.hpp src/Engine/AI/StaticEvaluator.cpp
        src/Engine/AI/MoveSorter.hpp src/Engine/AI/MoveSorter.cpp
        src/Engine/AI/Entry.hpp src/Engine/AI/Entry.cpp
        src/Engine/AI/TranspositionTable.hpp src/Engine/AI/TranspositionTable.cpp
        src/Engine/AI/OpeningBook.hpp src/Engine/AI/OpeningBook.cpp
        src/Engine/AI/AI.hpp src/Engine/AI/AI.cpp
        src/opening_book.txt
)
include(FindPkgConfig)
add_definitions(-Werror)
add_definitions(-O3)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libstdc++ -static-libgcc")
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)


# Подключение потоков.
find_package(Threads REQUIRED)
target_link_libraries(Natrix Threads::Threads)
