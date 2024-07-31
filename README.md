# Rational
A rational number is represented by two mutually simple integers - a numerator and a positive denominator. This invariant must be maintained when performing any operations on objects of the Rational class. The public interface of the class includes:
1) A default constructor that initializes the number with zero;
2) An implicit transform constructor from integers;
3) A constructor from two integers (numerator and denominator);
4) GetNumerator() and GetDenominator() methods that return the numerator and denominator respectively;
5) SetNumerator(int) and SetDenominator(int) methods that set the numerator and denominator to the desired values;
6) Binary arithmetic operations (+, -, /, *) and their assignment versions (+=, -=, /=, *=);
7) Unary operations (+, -), as well as prefix and postfix increments and decrements (++, --);
8) Comparison operations;
9) Operations of input from a stream and output to a stream (>>, <<);
