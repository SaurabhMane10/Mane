#include <iostream>
#include <algorithm>
#include <vector>

void no_permute(std::vector<int>& elements) {
    
    do {
        for (int num : elements) {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    } while (std::next_permutation(elements.begin(), elements.end()));
}

int main() {
    int n;


    std::cin >> n;

    
    std::vector<int> elements(n);
    
    for (int i = 0; i < n; ++i) {
        std::cin >> elements[i];
    }

  
    
    no_permute(elements);

    return 0;
}
