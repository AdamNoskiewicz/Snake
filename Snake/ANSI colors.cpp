#include <iostream>
#include <string>
#include <chrono>
#include <thread>
int main(int argc, char ** argv){
    system("");
    std::string a;
    a = "\033[1;30;42m \033[0m";
    for(int i=0;i<6;i++) std::cout<<a;
//    std::cout << "Hello I'm waiting...." << std::endl;
//    std::this_thread::sleep_for(std::chrono::milliseconds(2000) );
//    std::cout << "Waited 2000 ms\n";
    return 0;
}
