#pragma once

#include <stdint.h>

typedef struct {
    float a, b;
} Data;

class Serializer {
    private:
        Serializer(void);
        ~Serializer(void);
        Serializer(const Serializer& copy);
        Serializer &operator=(const Serializer& copy);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};