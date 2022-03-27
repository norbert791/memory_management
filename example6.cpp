#include <cstdio>
#include <memory>
#include <string>

using ShoppingList = std::shared_ptr<std::FILE>;

ShoppingList makeFile(const char* filename, const char* flags)
{
    return {fopen(filename, flags),[] (FILE* file) {fclose(file);}};
}

class Partner
{
public:
    void addToFile(const std::string& element)
    {
        fprintf(shoppingList.get(), "%s\n", element.c_str());
    }
    ShoppingList shoppingList;
};

int main()
{
    Partner boy{};
    boy.shoppingList = makeFile("ShoppingList", "wb");

    Partner girl{};
    girl.shoppingList = boy.shoppingList;
    girl.addToFile("Butter");
    girl.addToFile("Milk");
}
