#ifndef SOUNDEX_H
#define SOUNDEX_H

#include <string>

char getSoundexCode(char c);
std::string initializeSoundex(const std::string& name);
bool shouldAddCode(char code, char prevCode);
void processCharacter(char code, std::string& soundex, char& prevCode);
void updateSoundex(std::string& soundex, const std::string& name);
void padSoundex(std::string& soundex);
std::string generateSoundex(const std::string& name);

#endif // SOUNDEX_H
