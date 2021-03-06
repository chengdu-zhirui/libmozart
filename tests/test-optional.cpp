/**
 * Mozart++ Template Library
 * Licensed under Apache 2.0
 * Copyright (C) 2020-2021 Chengdu Covariant Technologies Co., LTD.
 * Website: https://covariant.cn/
 * Github:  https://github.com/chengdu-zhirui/
 */

#include <mozart++/optional>
#include <string>
#include <vector>
#include <cstdio>

void sayHi(mpp::optional<std::string> name) {
    if (name) {
        printf("hi: %s\n", name.get().c_str());
    } else {
        printf("you didn't tell me who you are\n");
    }
}

int sum(const mpp::optional<std::vector<int>> &nums) {
    return nums.apply_or<int>(0, [](auto &&v) -> int {
        int s = 0;
        for (auto &&e : v) {
            s += e;
        }
        return s;
    });
}

int main(int argc, const char **argv) {
    sayHi(mpp::none);
    sayHi(mpp::optional<std::string>("hello"));
    sayHi(mpp::some<std::string>("world"));
    sayHi(std::string("optional"));

    std::vector<int> v{1, 2, 3, 4};
    printf("sum1 = %d\n", sum(mpp::some<decltype(v)>(v)));
    printf("sum2 = %d\n", sum(mpp::none));
    printf("sum3 = %d\n", sum(mpp::some<decltype(v)>(1, 2, 3, 4, 5)));
}
