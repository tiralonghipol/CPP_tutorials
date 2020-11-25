#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <cctype>
#include <random>
#include <chrono>
#include <stack>
#include <queue>

class Timer
{
public:
    Timer()
    {
        m_start_time_point = std::chrono::high_resolution_clock::now();
    }
    void stop()
    {
        auto end_time_point = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_start_time_point).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_time_point).time_since_epoch().count();
        auto duration = end - start;
        double ms = duration * 0.001;

        std::cout << duration << " us | " << ms << " ms " << std::endl;
    }
    ~Timer()
    {
        stop();
    };

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start_time_point;
};

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
    std::cout << "6) remove" << std::endl;
    std::cout << "7) transform" << std::endl;
    std::cout << "8) generate_n" << std::endl;
    std::cout << "9) lamda" << std::endl;
    std::cout << "10) sort/search/timing" << std::endl;
    std::cout << "11) heap" << std::endl;
    std::cout << "12) stack" << std::endl;
    std::cout << "13) priority_queue" << std::endl;
    std::cout << "Select: ";
}

struct Action
{
    int time_stamp;
    std::string description;
    bool operator>(const Action &rhs) const
    {
        return time_stamp > rhs.time_stamp;
    }
};

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
    std::vector<int> rands_v;
    std::stack<int> stack_of_ints;
    std::priority_queue<Action, std::vector<Action>, std::greater<Action>> pq;
    // shuffle random generator
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> d(-10, 10);

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
        // move form one vector to the other
        std::move(a.begin() + 3, a.begin() + 7, b.begin() + 6);
        std::cout << "a vector: " << std::endl;
        write_to_cout(a, " | ");
        std::cout << std::endl;
        std::cout << "New b vector: " << std::endl;
        write_to_cout(b);
        std::cout << std::endl;

        break;
    }
    case 6:
    {
        // remove all items not containing an 'e'
        const auto new_end = std::remove_if(
            a.begin(),
            a.end(),
            [](const std::string &s) {
                return std::count(s.begin(), s.end(), 'e') == 0;
            });
        a.erase(new_end, a.end());

        std::cout << "New a vector: " << std::endl;
        write_to_cout(a);
        std::cout << std::endl;

        break;
    }
    case 7:
    {
        // transform all input to upper case
        for (int id = 0; id < a.size(); id++)
        {
            std::transform(a.at(id).begin(), a.at(id).end(), a.at(id).begin(), ::toupper);
        }
        std::cout << "New a vector: " << std::endl;
        write_to_cout(a);
        std::cout << std::endl;

        break;
    }
    case 8:
    {
        // generate n radonm values
        // std::generate_n(std::back_inserter(rands_v), 5, rng);
        std::generate_n(std::back_inserter(rands_v), 6, [&]() { return d(rng); });
        write_to_cout(rands_v);
        std::cout << std::endl;

        break;
    }
    case 9:
    {
        // test a lamda function
        int a = 3, b = 2;
        auto add_ints = [&a, &b]() {
            a -= 1;
            return a + b;
        };
        std::cout << add_ints() << std::endl;

        break;
    }
    case 10:
    {
        // generate n radonm values and time the operation
        // std::generate_n(std::back_inserter(rands_v), 5, rng);
        std::cout << "t1: ";
        {
            Timer t1;
            std::generate_n(std::back_inserter(rands_v), 1e6, [&]() { return d(rng); });
        }
        // sort the vector and time the operation
        std::cout << "t2: ";
        {
            Timer t2;
            std::sort(rands_v.begin(), rands_v.end());
        }

        std::cout << std::endl;
        break;
    }
    case 11:
    {
        // generate 100 radonm values
        std::generate_n(std::back_inserter(rands_v), 10, [&]() { return d(rng); });
        write_to_cout(rands_v);
        std::cout << std::endl;
        {
            Timer t1;
            // max heap
            // std::make_heap(rands_v.begin(), rands_v.end());
            // min heap
            std::make_heap(rands_v.begin(), rands_v.end(), std::greater<int>{});
        }
        write_to_cout(rands_v);
        std::cout << std::endl;
        break;
    }
    case 12:
    {
        // push a value into the empty stack
        stack_of_ints.push(10);
        std::cout << stack_of_ints.top() << std::endl;
        break;
    }
    case 13:
    {
        // push some timestamps/action into the priority queue
        pq.push({20, "Eat"});
        pq.push({10, "Sleep"});
        pq.push({40, "Work"});
        pq.push({-10, "Study"});

        while (!pq.empty())
        {
            const auto &a = pq.top();
            std::cout << "Time: " << a.time_stamp << " - executing: " << a.description << std::endl;
            pq.pop();
        }

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
