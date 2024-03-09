# CMakeList.txt: projekt CMake dla elementu HashFunc, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#

# Dodaj źródło do pliku wykonywalnego tego projektu.
if(CMAKE_BUILD_TYPE MATCHES DEBUG)
	message("Optymalizacje wyłączona podczas debugowania")
else()
	if (MSVC)
		# add_compile_options("/Od /Arch:AVX2")
	endif()
endif(CMAKE_BUILD_TYPE MATCHES DEBUG)



add_compile_definitions(ALMA_EXPORTS)

add_library (HashFunc SHARED "HashFunc.c" "HashFunc.h")


target_link_libraries(HashFunc "CipherFunc")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET HashFunc PROPERTY CXX_STANDARD 20)
endif()

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
