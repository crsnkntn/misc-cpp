#include <vector>
#include <algorithm>
#include <cmath>

namespace STATS {
    double mean (std::vector<double>& data) {
        double sum = 0.0;
        for (double d : data)
            sum += d;
        return sum / double(data.size());
    }

    double standard_deviation (std::vector<double>& data, double m) {
        double summation = 0.0;
        for (double d : data)
            summation += (d - m) * (d - m);
        return sqrt(summation / (data.size() - 1));
    }

    double variance (std::vector<double>& data, double m) {
        double summation = 0.0;
        for (double d : data)
            summation += (d - m) * (d - m);
        return summation / (data.size() - 1);
    }

    double median (std::vector<double>& data) {
        std::sort(data.begin(), data.end());
        return median_sorted(data);
    }

    double median_sorted (std::vector<double>& data) {
        std::size_t sz = data.size();
        if (sz % 2 == 0)
            return data[int(sz / 2)] + data[int(sz / 2) - 1];
        else
            return data[int(sz / 2)];
    }
    
    // P(A) = p, P(B) = q
    double AorB (double p, double q) {
        return p + q - p * q;
    }

    double notA (double p) {
        return 1 - p;
    }

    double AandB (double p, double q) {
        return p * q;
    }

    double AgivenB (double p, double q) {
        return p;
    }
};