class Solution {
public:
    double Power(double base, int exponent) {
        //base为0 或 指数为0
        if (std::equal(base, 0.0) || exponent == 0)
            return 1.0;
        int isPositive = true;
        if (exponent < 0)
        {
            exponent = -exponent;
            isPositive = false;
        }
    	double result = 1;
        while (exponent > 0)
        {
            result = result * base;
            exponent--;
        }
        return isPositive ? result : 1/result;
    }
};