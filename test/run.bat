set filename=1
g++ -finput-charset=UTF-8 -fexec-charset=UTF-8 ^
    "%filename%.cpp" -o "%filename%.exe"
"%filename%.exe"