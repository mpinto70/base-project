#include "dir/file.h"

#include <gtest/gtest.h>

namespace dir {

TEST(fileTest, square) {
    EXPECT_EQ(square(2), 4);
    EXPECT_EQ(square(3), 9);;
}

}
