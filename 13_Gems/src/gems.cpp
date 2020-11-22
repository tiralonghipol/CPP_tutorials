#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cctype>

template <class Container>
void write_to_cout(const Container &container, const char *delimiter = " ")
{
    std::copy(container.begin(), container.end(),
              std::ostream_iterator<typename Container::value_type>(std::cout, delimiter));
}
void print_menu()
{
    std::cout << "Options: " << std::endl;
    std::cout << "1) copy" << std::endl;
    std::cout << "2) copy_n" << std::endl;
    std::cout << "3) copy_backward" << std::endl;
    std::cout << "4) copy_if" << std::endl;
    std::cout << "5) move" << std::endl;
    std::cout << "Select: ";
}
int main()
{
    // containers
    std::vector<std::string> a = {"zero", "one", "two",
                                  "three", "four", "five",
                                  "six", "seven", "eight",
                                  "nine", "ten"};
    std::vector<std::string> b = {"0", "1", "2",
                                  "3", "4", "5",
                                  "6", "7", "8",
                                  "9", "10"};
    std::vector<int> c = {25, 15, 5, -5, -15};

    int menu_choice;
    // print original vectors
    std::cout << "Original vectors: " << std::endl;
    write_to_cout(a);
    std::cout << std::endl;
    write_to_cout(b);
    std::cout << std::endl;
    write_to_cout(c);
    std::cout << std::endl;
    std::cout << std::endl;
    // print choices
    print_menu();
    // choose a menu entry
    std::cin >> menu_choice;

    switch (menu_choice)
    {
    case 1:
    {
        // copy using iterators
        std::copy(a.begin() + 3, a.begin() + 7, b.begin() + 6);
        std::cout << "New b vector: " << std::endl;
        write_to_cout(b);
        std::cout << std::endl;
        break;
    }
    case 2:
    {
        // copy n elements using start iterator
        std::copy_n(a.begin() + 3, 4, b.begin() + 6);
        std::cout << "New b vector: " << std::endl;
        write_to_cout(b);
        std::cout << std::endl;
        break;
    }
    case 3:
    {
        // copy in reverse order
        std::copy_backward(a.begin() + 3, a.begin() + 7, b.begin() + 6);
        std::cout << "New b vector: " << std::endl;
        write_to_cout(b);
        std::cout << std::endl;
        break;
    }
    case 4:
    {
        // filter values < 0
        std::vector<int> positives;
        std::copy_if(c.begin(), c.end(), std::back_inserter(positives), [](int i) { return i >= 0; });
        std::cout << "New b vector: " << std::endl;
        write_to_cout(positives);
        std::cout << std::endl;
        break;
    }
    case 5:
    {
        // copy in reverse order
        std::move(a.begin() + 3, a.begin() + 7, b.begin() + 6);
        std::cout << "a vector: " << std::endl;
        write_to_cout(a, " | ");
        std::cout << std::endl;
        std::cout << "New b vector: " << std::endl;
        write_to_cout(b);
        std::cout << std::endl;
        break;
    }
    default:
    {
        std::cout << "Choice not available" << std::endl;
        break;
    }
    }

    return 0;
}