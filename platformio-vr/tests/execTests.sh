cxxtestgen --error-printer -o runner.cpp *.h
g++ -o runner -I/opt/cxxtest -I/home/devastator/development/vr-project/platformio-vr/src -I/home/devastator/development/lib-arduino runner.cpp ../src/*.cpp
./runner
