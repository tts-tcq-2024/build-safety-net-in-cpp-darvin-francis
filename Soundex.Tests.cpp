#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTest, GenerateSoundex) {
    EXPECT_EQ(generateSoundex("example"), "E251");
    EXPECT_EQ(generateSoundex("name"), "N000");
    EXPECT_EQ(generateSoundex(""), "");
    EXPECT_EQ(generateSoundex("A"), "A000");
}

