# CMakeList.txt: проект CMake для Test; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Test")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Sem2 "sem2/2 Семинар.cpp" "sem2/Array.cpp")
add_executable (Sem3 "sem3/3 Семинар.cpp" "sem3/Solve.cpp")
add_executable (Sem4 "sem4/4 Семинар.cpp" "sem4/Functions.cpp")
add_executable (Sem5 "sem5/Семинар 5.cpp" "sem5/Nature.cpp")
add_executable (Sem6 "sem6/Семинар 6.cpp" "sem6/Shapes.cpp")
add_executable (Sem7 "sem7/Семинар 7.cpp")
add_executable (Sem10 "sem10/Семинар 10.cpp")
//add_executable (Extra_Task "Extra/Extra task.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
