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

monoString *CreateMonoString(const char *str) {
    monoString *(*String_CreateString)(void *instance, const char *str) = (monoString *(*)(void *, const char *))getAbsoluteAddress("libil2cpp.so", Offsets::Methods.String_CreateString);
    return String_CreateString(NULL, str);
}