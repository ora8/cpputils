#pragma once

#include <cstring>
#include <algorithm>
#include <type_traits>

// Für trivially copyable Typen
template <typename T, size_t N>
void safe_memcpy(T (&destination)[N], const T (&source)[N]) {
    static_assert(std::is_trivially_copyable<T>::value,
                 "Type must trivially copyable");
    std::memcpy(destination, source, N * sizeof(T));
}

// Für nicht-trivial kopierbare Typen (z. B. std::string)
template <typename T, size_t N>
void safe_copy(T (&destination)[N], const T (&source)[N]) {
    std::copy(std::begin(source), std::end(source), std::begin(destination));
}

template<typename T, size_t N, size_t M>
void safe_memcpy(T (&destination)[N], const T (&source)[M]) {
        static_assert(std::is_trivially_copyable<T>::value,
                 "Type must trivially copyable");
    if (M <= N) {
        std::memcpy(destination, source, M * sizeof(T));
    }
    else {
        std::memcpy(destination, source, N *  sizeof(T));
    }
}

template<typename T, size_t N, size_t M>
void safe_copy(T (&destination)[N], const T (&source)[M]) {
    if (M <= N) {
        std::copy(std::begin(source), std::end(source), std::begin(destination));
    }
    else {
        std::copy(std::begin(source), std::begin(source) + N, std::begin(destination));
   }
}