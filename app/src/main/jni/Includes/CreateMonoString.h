// Thanks to https://platinmods.com/threads/how-to-modify-unitys-il2cpp-string-methods.123414/ for this header

#include "Utils.h"
#include "Substrate/SubstrateHook.h"

typedef struct _monoString {
    void *klass;
    void *monitor;
    int length;
    char chars[1];

    int getLength() {
        return length;
    }

    char *getChars() {
        return chars;
    }
} monoString;

#if defined(__aarch64__)
	monoString *CreateMonoString(const char *str) {
    monoString *(*String_CreateString)(void *instance, const char *str) = (monoString *(*)(void *, const char *))getAbsoluteAddress("libil2cpp.so", 0xCA9A88);
	return String_CreateString(NULL, str); }
#else
	monoString *CreateMonoString(const char *str) {
    monoString *(*String_CreateString)(void *instance, const char *str) = (monoString *(*)(void *, const char *))getAbsoluteAddress("libil2cpp.so", 0xA3BCEC);
	return String_CreateString(NULL, str); }
#endif