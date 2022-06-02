#include <iostream>
#include <memory>
#include <utility>

class Resource
{
public:
    Resource()
    {
        std::cout << "Resource aquired\n";
    }
    ~Resource()
    {
        std::cout << "Resource destroyed\n";
    }
};

int main()
{
    std::unique_ptr<Resource> res1{new Resource{}};
    std::unique_ptr<Resource> res2{};

    std::cout << "Res1 is "
        << (static_cast<bool>(res1) ? "not null\n" : "null\n");
    std::cout << "Res2 is "
        << (static_cast<bool>(res2) ? "not null\n" : "null\n");

    res2 = std::move(res1);

    std::cout << "Ownership transfered!\n";

    std::cout << "Res1 is "
        << (static_cast<bool>(res1) ? "not null\n" : "null\n");
    std::cout << "Res2 is "
        << (static_cast<bool>(res2) ? "not null\n" : "null\n");

    return 0;
}
