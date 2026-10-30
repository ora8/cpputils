#include <print>

#include "utils.hpp"

struct int_array6 {
    int elements[5];
    int_array6() {
    }
    int_array6(int (&elements_)[6]) {
        safe_memcpy<int, 5, 6>(elements, elements_);
    }
};

int main() {
    // Beispiel für primitive Typen
    int source1[5] = {1, 2, 3, 4, 5};
    int destination1[5];
    safe_memcpy(destination1, source1);

    // Beispiel für std::string (nicht trivial kopierbar)
    std::string source2[3] = {"Hallo", "Welt", "!"};
    std::string destination2[3];
    safe_copy(destination2, source2);

    int int_arr[6] = {1, 2, 3, 4, 5, 6};
    int_array6 arr{int_arr};
    int_array6 arr1 = arr;
    for (auto it = std::begin(arr1.elements); it != std::end(arr1.elements); ++it) {
        std::println("{}, ", *it);
    }
    return 0;
}
