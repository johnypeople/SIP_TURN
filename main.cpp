#include "Server.h"

int main() {
    Server server("http://localhost:8080");
    server.start();

    std::cout << "Server is running at http://localhost:8080" << std::endl;
    std::string line;
    std::getline(std::cin, line);

    return 0;
}
