#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

struct Float16 {
    bool sign;
    unsigned int exponent : 5;
    unsigned int fraction : 10;
};

Float16 fromFloat32(float f) {
    bitset<32> bits(*reinterpret_cast<unsigned int*>(&f));
    bool sign = bits[31];
    unsigned int exponent = (bits >> 23 & 0xff) - 127;
    unsigned int fraction = (bits & 0x7fffff).to_ulong() >> 13;
    fraction &= 0x3ff;
    Float16 f16;
    f16.sign = sign;
    f16.exponent = exponent;
    f16.fraction = fraction;
    return f16;
}

float toFloat32(Float16 f16) {
    int exponent = f16.exponent + 15;
    int fraction = f16.fraction << 13;
    bitset<32> bits;
    bits[31] = f16.sign;
    bits |= (exponent << 23);
    bits |= fraction;
    return *reinterpret_cast<float*>(&bits);
}

Float16 add(Float16 a, Float16 b) {
    float a_f = toFloat32(a);
    float b_f = toFloat32(b);
    float result_f = a_f + b_f;
    return fromFloat32(result_f);
}

Float16 subtract(Float16 a, Float16 b) {
    float a_f = toFloat32(a);
    float b_f = toFloat32(b);
    float result_f = a_f - b_f;
    return fromFloat32(result_f);
}

Float16 multiply(Float16 a, Float16 b) {
    float a_f = toFloat32(a);
    float b_f = toFloat32(b);
    float result_f = a_f * b_f;
    return fromFloat32(result_f);
}

Float16 divide(Float16 a, Float16 b) {
    float a_f = toFloat32(a);
    float b_f = toFloat32(b);
    float result_f = a_f / b_f;
    return fromFloat32(result_f);
}

int main() {
    Float16 a = fromFloat32(2.0);
    Float16 b = fromFloat32(0.5);
    Float16 sum = add(a, b);
    Float16 difference = subtract(a, b);
    Float16 product = multiply(a, b);
    Float16 quotient = divide(a, b);
    cout << "a = " << toFloat32(a) << endl;
    cout << "b = " << toFloat32(b) << endl;
    cout << "a + b = " << toFloat32(sum) << endl;
    cout << "a - b = " << toFloat32(difference) << endl;
    cout << "a * b = " << toFloat32(product) << endl;
    cout << "a / b = " << toFloat32(quotient) << endl;
    return 0;
}