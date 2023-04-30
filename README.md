# floating-point-scheme

To implement 16-bit floating-point arithmetic, we can define a struct with three fields: a 1-bit field for the sign, a 5-bit field for the exponent, and a 10-bit field for the fraction. We can then define functions to perform arithmetic operations on these structs, including addition, subtraction, multiplication, and division.

To test the library, we can generate a signal by mixing sinusoids of three different frequencies - f1, f2, and f3, such that f1 < f2 < f3. We can then design an FIR filter to filter out frequency f3. We can compare the FFTs of the filtered signal generated using both 32-bit and 16-bit floating-point arithmetic.

float_point.cpp is the desired library.
