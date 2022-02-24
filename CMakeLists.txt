cmake_minimum_required(VERSION 3.10)

project(libmime VERSION 0.9.9 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(LIBMIME_SOURCES
    libmime/Base64.cpp
    libmime/Base64.hpp
    libmime/body.cpp
    libmime/body.hpp
    libmime/body_shadow.cpp
    libmime/body_shadow.hpp
    libmime/codec.cpp
    libmime/codec.hpp
    libmime/contentid_body.cpp
    libmime/contentid_body.hpp
    libmime/contenttype_body.cpp
    libmime/contenttype_body.hpp
    libmime/field.cpp
    libmime/field.hpp
    libmime/field_body.cpp
    libmime/field_body.hpp
    libmime/field_name.cpp
    libmime/field_name.hpp
    libmime/header.cpp
    libmime/header.hpp
    libmime/mime.hpp
    libmime/mime_entity.cpp
    libmime/mime_entity.hpp
    libmime/mime_header.cpp
    libmime/mime_header.hpp
    libmime/mime_message.cpp
    libmime/mime_message.hpp
    libmime/mult_entity.cpp
    libmime/mult_entity.hpp
    libmime/param.cpp
    libmime/param.hpp
    libmime/string_body.cpp
    libmime/string_body.hpp
    libmime/text_entity.cpp
    libmime/text_entity.hpp
    libmime/token.cpp
    libmime/token.hpp
    libmime/util.cpp
    libmime/util.hpp
    libmime/version_body.cpp
    libmime/version_body.hpp
)
add_library(libmime ${LIBMIME_SOURCES} )
target_compile_features(libmime PRIVATE cxx_std_17)

target_include_directories(libmime PUBLIC .)
target_include_directories(libmime PRIVATE libmime/)
