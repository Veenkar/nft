cmake_minimum_required(VERSION 2.8)

project(nft)

# NFT LIB
set(NFT_HEADERS nft.h)
set(NFT_SOURCES nft.c)
add_library(nft_lib ${NFT_SOURCES} ${NFT_HEADERS})
target_link_libraries(nft_lib m)

# MAIN
set(SOURCES "main.c")
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} nft_lib)
target_link_libraries(${PROJECT_NAME} m)
