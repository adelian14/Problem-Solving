class Mint {
    static int mod;

public:
    static vector<Mint> fact;
    long long val;
    Mint(int x = 0) { val = x; }
    Mint operator+(Mint b) { return Mint((val + b.val) % mod); }
    Mint operator+(int b) { return Mint((val + b) % mod); }
    Mint operator-(Mint b) { return Mint((val - b.val + mod) % mod); }
    Mint operator-(int b) { return Mint((val - b + mod) % mod); }
    Mint operator*(Mint b) { return Mint((val * b.val) % mod); }
    Mint operator*(int b) { return Mint((val * b) % mod); }
    Mint operator/(int b) { return *this * Mint(b).inv(); }
    Mint operator/(Mint b) { return *this * b.inv(); }
    Mint operator+=(int b) {
        val = (val + b) % mod;
        return *this;
    }
    Mint operator+=(Mint b) {
        val = (val + b.val) % mod;
        return *this;
    }
    Mint operator-=(int b) {
        val = (val - b + mod) % mod;
        return *this;
    }
    Mint operator-=(Mint b) {
        val = (val - b.val + mod) % mod;
        return *this;
    }
    Mint operator*=(int b) {
        val = (val * b) % mod;
        return *this;
    }
    Mint operator*=(Mint b) {
        val = (val * b.val) % mod;
        return *this;
    }
    Mint operator/=(int b) {
        val = (val * Mint(b).inv().val) % mod;
        return *this;
    }
    Mint operator/=(Mint b) {
        val = (val * b.inv().val) % mod;
        return *this;
    }
    static Mint pow(int a, int p) { return pow(Mint(a), p); }
    static Mint pow(Mint n, int p) {
        Mint ans(1);
        while (p) {
            if (p & 1)
                ans *= n;
            n *= n;
            p /= 2;
        }
        return ans;
    }
    Mint inv() { return Mint::pow(val, mod - 2); }
    static void setMod(int m){
        mod = m;
    }
    static void calFact(int n) {
        fact = vector<Mint>(n);
        fact[0] = Mint(1);
        for (int i = 1; i < fact.size(); i++) {
            fact[i] = fact[i - 1] * i;
        }
    }
    static Mint npr(int n, int r) {
        if (r > n)
            return Mint(0);
        return fact[n] / fact[n - r];
    }
    static Mint ncr(int n, int r) {
        if (r > n)
            return Mint(0);
        return npr(n, r) / fact[r];
    }
};
int Mint::mod = 0;
vector<Mint> Mint::fact = vector<Mint>();
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        Mint::setMod(1e9+7);
        Mint::calFact(1e5+10);
        Mint ans;
        for (int x = 0; x * one <= high; x++) {
            int d1 = low-x*one, d2 = high-x*one;
            int y = (d1+zero-1)/zero;
            int z = d2/zero;
            if (z < y)
                continue;
            ans += Mint::ncr(x + z + 1, x + 1) - Mint::ncr(x + y, x + 1);
        }
        return ans.val;
    }
};
