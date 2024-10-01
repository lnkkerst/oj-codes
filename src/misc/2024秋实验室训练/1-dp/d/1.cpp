#include <iostream>
#include <ranges>
#include <vector>

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // 组合多个操作：过滤奇数，平方后取前 5 个结果
  auto result = v | std::views::filter([](int n) {
                  return n % 2 != 0;
                })
                | std::views::transform([](int n) {
                    return n * n;
                  })
                | std::views::take(5);

  for (int n : result) {
    std::cout << n << " ";
  }

  return 0;
}
