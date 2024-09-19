#include <cctype>
#include <string>

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

std::string initializeSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0]));
    return soundex;
}

bool shouldAddCode(char code, char prevCode) {
    return code != '0' && code != prevCode;
}

void processCharacter(char code, std::string& soundex, char& prevCode) {
    if (shouldAddCode(code, prevCode)) {
        soundex += code;
        prevCode = code;
    }
}

void updateSoundex(std::string& soundex, const std::string& name) {
    char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(name[i]);
        processCharacter(code, soundex, prevCode);
    }
}

void padSoundex(std::string& soundex) {
    while (soundex.length() < 4) {
        soundex += '0';
    }
}

std::string generateSoundex(const std::string& name) {
    std::string soundex = initializeSoundex(name);
    if (soundex.empty()) return "";

    updateSoundex(soundex, name);
    padSoundex(soundex);

    return soundex;
}
