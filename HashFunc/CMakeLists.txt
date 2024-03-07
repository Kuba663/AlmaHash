# CMakeList.txt: projekt CMake dla elementu HashFunc, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#

# Dodaj źródło do pliku wykonywalnego tego projektu.

if (MSVC)
	add_compile_options("/O2 /Oi /Arch:AVX2")
endif()

add_library (HashFunc SHARED "HashFunc.c" "HashFunc.h" "Cipher.h" "Cipher.c")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET HashFunc PROPERTY CXX_STANDARD 20)
endif()

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
