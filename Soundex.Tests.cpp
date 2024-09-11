#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoundexTest, GetSoundexCode) {
    EXPECT_EQ(getSoundexCode('a'), '0');
    EXPECT_EQ(getSoundexCode('b'), '1');
    EXPECT_EQ(getSoundexCode('c'), '2');
    EXPECT_EQ(getSoundexCode('d'), '3');
    EXPECT_EQ(getSoundexCode('l'), '4');
    EXPECT_EQ(getSoundexCode('m'), '5');
    EXPECT_EQ(getSoundexCode('r'), '6');
    EXPECT_EQ(getSoundexCode('z'), '2');
    EXPECT_EQ(getSoundexCode('w'), '0'); // Letters not assigned a code
}

TEST(SoundexTest, InitializeSoundex) {
    EXPECT_EQ(initializeSoundex("example"), "E");
    EXPECT_EQ(initializeSoundex(""), "");
    EXPECT_EQ(initializeSoundex("a"), "A");
    EXPECT_EQ(initializeSoundex("B"), "B");
}

TEST(SoundexTest, ShouldAddCode) {
    EXPECT_TRUE(shouldAddCode('1', '0'));
    EXPECT_FALSE(shouldAddCode('0', '0'));
    EXPECT_FALSE(shouldAddCode('1', '1'));
    EXPECT_TRUE(shouldAddCode('2', '1'));
}

TEST(SoundexTest, ProcessCharacter) {
    std::string soundex = "A";
    char prevCode = '0';
    
    processCharacter('1', soundex, prevCode);
    EXPECT_EQ(soundex, "A1");
    EXPECT_EQ(prevCode, '1');

    processCharacter('1', soundex, prevCode);
    EXPECT_EQ(soundex, "A1"); // No change because '1' is the same as prevCode

    processCharacter('2', soundex, prevCode);
    EXPECT_EQ(soundex, "A12");
    EXPECT_EQ(prevCode, '2');
}

TEST(SoundexTest, UpdateSoundex) {
    std::string soundex = initializeSoundex("example");
    updateSoundex(soundex, "example");
    EXPECT_EQ(soundex, "E251");

    soundex = initializeSoundex("name");
    updateSoundex(soundex, "name");
    EXPECT_EQ(soundex, "N550");
}

TEST(SoundexTest, PadSoundex) {
    std::string soundex = "A1";
    padSoundex(soundex);
    EXPECT_EQ(soundex, "A100");

    soundex = "A123";
    padSoundex(soundex);
    EXPECT_EQ(soundex, "A123"); // No change needed

    soundex = "A";
    padSoundex(soundex);
    EXPECT_EQ(soundex, "A000");
}

TEST(SoundexTest, GenerateSoundex) {
    EXPECT_EQ(generateSoundex("example"), "E251");
    EXPECT_EQ(generateSoundex("name"), "N550");
    EXPECT_EQ(generateSoundex(""), "");
    EXPECT_EQ(generateSoundex("A"), "A000");
}

