#include <cctype>
#include <string>

// Function to get the Soundex code for a given character
char getSoundexCode(char c) {
    static const std::string soundexCodes[] = {
        "", "BFPV", "CGJKQSXZ", "DT", "L", "MN", "R"
    };

    c = toupper(c);
    for (int i = 1; i < 7; i++) {
        if (soundexCodes[i].find(c) != std::string::npos) {
            return '0' + i;
        }
    }
    return '0'; // For A, E, I, O, U, H, W, Y
}

// Function to initialize the Soundex code
std::string initializeSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0]));
    return soundex;
}

// Function to update the Soundex code based on the name
void updateSoundex(std::string& soundex, const std::string& name) {
    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
            soundex += code;
            prevCode = code;
        }
    }
}

// Function to pad the Soundex code to ensure it is 4 characters long
void padSoundex(std::string& soundex) {
    while (soundex.length() < 4) {
        soundex += '0';
    }
}

// Main function to generate the Soundex code
std::string generateSoundex(const std::string& name) {
    std::string soundex = initializeSoundex(name);
    if (soundex.empty()) return "";

    updateSoundex(soundex, name);
    padSoundex(soundex);

    return soundex;
}
