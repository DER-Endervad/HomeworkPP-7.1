#include <iostream>
#include <map>
#include <algorithm>

int main()
{
    std::string in = "Hello world!!";
    std::cout << "[IN]: " << in << std::endl;
    std::map<char, int> my_map;
    std::multimap<int, char> sort_map;
    for (const char& input : in) {
        my_map[input] += 1;
        /*bool true_false = true;
        for (auto& elem : my_map) {
            if (elem.first == input) {
                elem.second = elem.second + 1;
                true_false = false;
            }
        }
        if (true_false) {
            my_map[input] = 1;
        }*/
    }
    typedef std::pair <int, char> Int_Pair;
    for (const auto& elem : my_map) {
        sort_map.insert(Int_Pair (elem.second, elem.first));
    }
    auto output = [](const auto& elem) {
        std::cout << elem.second << ": " << elem.first << std::endl;
    };
    std::cout << "[OUT]: " << std::endl;
    std::for_each(sort_map.rbegin(), sort_map.rend(), output);
}
