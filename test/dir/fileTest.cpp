#include "dir/file.h"

#include <gtest/gtest.h>

#include <boost/filesystem.hpp>

namespace dir {

TEST(fileTest, square) {
    EXPECT_EQ(square(2), 4);
    EXPECT_EQ(square(3), 9);;
}

TEST(fileTest, filesystem) {
    EXPECT_TRUE(boost::filesystem::is_regular_file(PROJECT_DIR "/CMakeLists.txt"));
}

}
