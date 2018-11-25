#include "dir/file.h"

#include "../mck/dir/fileMock.h"

#include <gtest/gtest.h>

#include <boost/filesystem.hpp>

namespace dir {

TEST(fileTest, square) {
    EXPECT_EQ(square(2), 4);
    EXPECT_EQ(square(3), 9);
    ;
}

TEST(fileTest, filesystem) {
    EXPECT_TRUE(boost::filesystem::is_regular_file(PROJECT_DIR "/CMakeLists.txt"));
}

using ::testing::Return;
TEST(fileTest, mocking) {
    const ::dir::mck::InterfaceMock interface;
    EXPECT_CALL(interface, function(3)).WillOnce(Return("some 3"));
    EXPECT_EQ(interface.function(3), "some 3");
}
}
