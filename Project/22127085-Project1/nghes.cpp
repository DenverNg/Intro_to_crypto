#pragma comment(linker, "/STACK:5000000")
#include <deque>
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <random>
#include <fstream>
#include <chrono>
using namespace std;
#define isNeg second
// 0 is positive, 1 is negative
#define value first
#define bigInt pair<vector<unsigned char>,bool>
#define pairvec pair<bigInt,bigInt>

void removeLeadingZeros(bigInt &binary)
{
    int lastNonZeroIndex = -1;
    for (size_t i = 0; i < binary.value.size(); ++i)
        if (binary.value[i] != 0){
            lastNonZeroIndex = i;
            break;
        }
    if (lastNonZeroIndex != -1)
        binary.value.erase(binary.value.begin(), binary.value.begin() + lastNonZeroIndex);
    else {
        binary.value.clear();
        binary.value.push_back(0);

    }
}
void removeLeadingZeros(vector<unsigned char> &binary)
{
    int lastNonZeroIndex = -1;
    for (size_t i = 0; i < binary.size(); ++i)
        if (binary[i] != 0){
            lastNonZeroIndex = i;
            break;
        }
    if (lastNonZeroIndex != -1)
        binary.erase(binary.begin(), binary.begin() + lastNonZeroIndex);
    else {
        binary.clear();
        binary.push_back(0);
    }
}
string binaryToHex(const vector<unsigned char> &bin) {
    const char hexDigits[] = "0123456789ABCDEF";
    string hex;
    int value = 0;
    int bits = 0;
    for (int i = bin.size() - 1; i >= 0; i--){
        int mul = 1;
        int num = 0;
        for (int j = i; j >= i - 3 && j >= 0; j--){
            num += mul * bin[j];
            mul <<= 1;
        }  
        i -= 3;
        hex = hexDigits[num] + hex;
    }  
    // If there are remaining bits, pad with zeros and convert
    return hex;
}
string toDecimalString(const bigInt &s){
    string decimal = "0"; // Start with decimal value 0 as a string
    
    for (int bit : s.value) 
    {
        // Multiply the current decimal value by 2
        int carry = 0;
        for (size_t i = 0; i < decimal.size(); ++i)
        {
            int num = (decimal[i] - '0') * 2 + carry;
            decimal[i] = (num % 10) + '0';
            carry = num / 10;
        }

        // If there's a carry left, append it to the result
        if (carry > 0)
        {
            decimal += (carry + '0');
        }

        // Add the current binary bit to the result
        carry = bit;
        for (size_t i = 0; i < decimal.size(); ++i)
        {
            int num = (decimal[i] - '0') + carry;
            decimal[i] = (num % 10) + '0';
            carry = num / 10;
        }

        // If there's a carry left, append it to the result
        if (carry > 0)
        {
            decimal += (carry + '0');
        }
    }

    // The result will be reversed because of the way we process from LSB to MSB
    std::reverse(decimal.begin(), decimal.end());
    return decimal;
}
long long toDecimal(const bigInt &binary_string){
    long long pw = 1;
    long long result = 0;
    if (binary_string.value.size() >= 30)
        throw std::invalid_argument("Number is too large to convert to decimal");
    for (int i = binary_string.value.size() - 1; i >= 0; --i)
    {
        result += binary_string.value[i] * pw;
        pw *= 2;
    }
    return result;
}
void printBigInt(const bigInt &a, bool newLine = true){
    if (a.isNeg)
        cout << "-";
    cout << toDecimalString(a);
    if (newLine)
        cout << endl;
}


vector<unsigned char> hexDigitToBinary(char hexChar)
{
    vector<unsigned char> binary;
    switch (hexChar)
    {
    case '0':
        binary = {0, 0, 0, 0};
        break;
    case '1':
        binary = {0, 0, 0, 1};
        break;
    case '2':
        binary = {0, 0, 1, 0};
        break;
    case '3':
        binary = {0, 0, 1, 1};
        break;
    case '4':
        binary = {0, 1, 0, 0};
        break;
    case '5':
        binary = {0, 1, 0, 1};
        break;
    case '6':
        binary = {0, 1, 1, 0};
        break;
    case '7':
        binary = {0, 1, 1, 1};
        break;
    case '8':
        binary = {1, 0, 0, 0};
        break;
    case '9':
        binary = {1, 0, 0, 1};
        break;
    case 'A':
        binary = {1, 0, 1, 0};
        break;
    case 'B':
        binary = {1, 0, 1, 1};
        break;
    case 'C':

        binary = {1, 1, 0, 0};
        break;
    case 'D':
        binary = {1, 1, 0, 1};
        break;
    case 'E':
        binary = {1, 1, 1, 0};
        break;
    case 'F':
        binary = {1, 1, 1, 1};
        break;
    default:
        throw std::invalid_argument("Invalid hex digit");
    }
    return binary;
}

bigInt hexStringToBinary(const string &hexString)
{

    bigInt binary = {{}, false};
    for (char hexChar : hexString)
    {
        vector<unsigned char> binaryDigit = hexDigitToBinary(hexChar);
        binary.value.insert(binary.value.end(), binaryDigit.begin(), binaryDigit.end());
    }
    removeLeadingZeros(binary);
    return binary;
}
int compare(const bigInt &a,const bigInt &b){
    // be aware of the isNeg 0 is positive, 1 is negative
    if (a.isNeg > b.isNeg)
        return -1;
    if (a.isNeg < b.isNeg)
        return 1;
    // if a and b is positive
    if (a.isNeg == 0){
        if (a.value.size() > b.value.size())
            return -1;
        if (a.value.size() < b.value.size())
            return 1;
        for (size_t i = 0; i < a.value.size(); ++i)
        {
            if (a.value[i] > b.value[i])
                return -1;
            if (a.value[i] < b.value[i])
                return 1;
        }
        return 0;
    } else {
        if (a.value.size() > b.value.size())
            return 1;
        if (a.value.size() < b.value.size())
            return -1;
        for (size_t i = 0; i < a.value.size(); ++i)
        {
            if (a.value[i] > b.value[i])
                return 1;
            if (a.value[i] < b.value[i])
                return -1;
        }
        return 0;
    }
 

}
int compare(const vector<unsigned char> &a,const vector<unsigned char> &b){
    if (a.size() > b.size())
        return 1;
    if (a.size() < b.size())
        return -1;
    for (size_t i = 0; i < a.size(); ++i)
    {
        if (a[i] > b[i])
            return 1;
        if (a[i] < b[i])
            return -1;
    }
    return 0;
}
//code add and subtract for bigInt with sign
vector<unsigned char> add(const vector<unsigned char> &a,const vector<unsigned char> &b){
    vector<unsigned char> result(max(a.size(), b.size()) + 1, 0);
    int carry = 0;
    for (int i = 0; i < result.size(); ++i)
    {
        int sum = carry;
        if (i < a.size())
            sum += a[a.size() - i - 1];
        if (i < b.size())
            sum += b[b.size() - i - 1];
        result[result.size() - i - 1] = sum & 1;
        carry = sum >> 1;
    }
    if (carry != 0)
        result.insert(result.begin(), carry);
    removeLeadingZeros(result);
    return result;
}
vector<unsigned char> sub(const vector<unsigned char> &a,const vector<unsigned char> &b){
    vector<unsigned char> result(max(a.size(), b.size()), 0);
    int borrow = 0;
    for (int i = 0; i < result.size(); ++i)
    {
        int diff = borrow;
        if (i < a.size())
            diff += a[a.size() - i - 1];
        if (i < b.size())
            diff -= b[b.size() - i - 1];
        if (diff < 0)
        {
            diff += 2;
            borrow = -1;
        }
        else
            borrow = 0;
        result[result.size() - i - 1] = diff;
    }
    removeLeadingZeros(result);
    return result;
}
vector<unsigned char> multiply(const vector<unsigned char> &base,const vector<unsigned char> &b){
    vector<unsigned char> result;
    vector<unsigned char> a = base;  
    if (compare({0},a) == 0 || compare({0},b) == 0)
        return {0};
    for (int i = b.size()-1; i >= 0; --i){
        if (b[i] & 1)
            result = add(result, a);
        a.push_back(0);
    }
    removeLeadingZeros(result);
    return result;
}

bigInt addBigInt(const bigInt &a, const bigInt &b){
    bigInt result;
    result.value.push_back(0);

    if (a.isNeg == b.isNeg){
        result.value = add(a.value,b.value);
        result.isNeg = a.isNeg;
    }
    else {
        int comp = compare(a.value, b.value);
        if (!comp)
            return result;
        if (comp > 0){
            result.value = sub(a.value, b.value);
            result.isNeg = a.isNeg;
        }else {
            result.value = sub(b.value, a.value);
            result.isNeg = b.isNeg;
        }
    }
    removeLeadingZeros(result);
    return result;
}
bigInt subBigInt(const bigInt &a, const bigInt &b){
    bigInt result;
    result.value.push_back(0);
    if (a.isNeg != b.isNeg){
        result.value = add(a.value, b.value);
        result.isNeg = a.isNeg;
    }else{
        int cmp = compare(a.value, b.value);
        if (cmp == 0)
            return result;
        if (cmp > 0){
            result.value = sub(a.value,b.value);
            result.isNeg = a.isNeg;
        }else{
            result.value = sub(b.value,a.value);
            result.isNeg = !a.isNeg;
        }
    }
    removeLeadingZeros(result);
    return result;
}
bigInt multiplyBigInt(const bigInt &a, const bigInt &b){
    bigInt result;
    result.value.push_back(0);
    if (compare(a.value,{0}) == 0 || compare(b.value,{0}) == 0)
        return result;
    result.value = multiply(a.value, b.value);
    result.isNeg = (a.isNeg != b.isNeg);
    removeLeadingZeros(result);
    return result;
}
//__________________________________________________________    
vector<unsigned char> mulMod(const vector<unsigned char> &base,const vector<unsigned char> &b,const vector<unsigned char> &m){
    vector<unsigned char> result;
    vector<unsigned char> a = base;  
    for (int i = b.size()-1; i >= 0; --i){
        if (b[i] & 1){
            result = add(result, a);
            if (compare(result, m) >= 0)
                result = sub(result, m);
        }
        a.push_back(0);
        if (compare(a, m) >= 0)
            a = sub(a, m);
    }
    removeLeadingZeros(result);
    return result;
}
vector<unsigned char> powMod(const vector<unsigned char> &a,const vector<unsigned char> &b,const vector<unsigned char> &m){
    vector<unsigned char> result = {1};
    for (int i = 0; i < b.size(); ++i){
        result = mulMod(result, result, m);
        if (b[i] & 1)
            result = mulMod(result, a, m);
    }
    removeLeadingZeros(result);
    return result;
}

pairvec getDivideAndModulo(const vector<unsigned char> &dividend, const vector<unsigned char> &divisor)
{
    // Khởi tạo giá trị ban đầu
    vector<unsigned char> remainder;
    vector<unsigned char> quotient(dividend.size(), 0);
    // Lặp qua từng bit của dividend
    for (size_t i = 0; i < dividend.size(); ++i)
    {
        remainder.push_back(dividend[i]);
        removeLeadingZeros(remainder);
        // cout << "remainder:" << binaryToHex(remainder) << " ";
        // cout << "divisor:" << binaryToHex(divisor) << " ";
        // Kiểm tra nếu remainder >= divisor
        if (compare(remainder, divisor) >= 0)
        {

            remainder = sub(remainder, divisor); 
            quotient[i] = 1;                    
        }
        // cout << "remainder result:" << binaryToHex(remainder) << endl;
    }

    // Xóa các bit 0 thừa ở đầu quotient
    removeLeadingZeros(quotient);

    pairvec result;
    result.first.value = quotient;
    result.second.value = remainder;
    return result;
}
pairvec subPair(const pairvec &A,const pairvec &B){
    pairvec result;
    // cout << "subpair:-------------";
    // cout << "a:";printBigInt(A.first,0);
    // cout << "b:";printBigInt(B.first,0);
    result.first = subBigInt(A.first,B.first);
    // cout << binaryToHex(result.first.value) << endl;
    result.second = subBigInt(A.second, B.second);
    return result;
}
pairvec scalarMul(const pairvec &A,const vector<unsigned char> &k){
    pairvec result;
    result.first = multiplyBigInt(A.first, {k,0});
    result.second = multiplyBigInt(A.second, {k,0});
    return result;
}

pairvec gcd(bigInt a,bigInt b){
    pairvec A_coefficient;
    A_coefficient.first.value = {1};
    A_coefficient.second.value = {0};
    pairvec B_coefficient;
    B_coefficient.first.value = {0};
    B_coefficient.second.value = {1};
    int count = 0;
    while (compare(b.value,{0})){
        pairvec d = getDivideAndModulo(a.value, b.value);
        bigInt &q = d.first;
        bigInt &r = d.second;
        cout << "a:";printBigInt(a,0);
        cout << "b:";printBigInt(b,0);
        cout << "----------------" << endl;
        a = b;
        b = r;
        pairvec R_coefficient = subPair(A_coefficient, scalarMul(B_coefficient,q.value));
        A_coefficient = B_coefficient;
        B_coefficient = R_coefficient;
        
        // cout << "q:";printBigInt(q,0);
        // cout << "r:";printBigInt(r,1);
        // cout << "A:";printBigInt(A_coefficient.first,0); cout << " ";printBigInt(A_coefficient.second,1);
        // cout << "B:";printBigInt(B_coefficient.first,0); cout << " ";printBigInt(B_coefficient.second,1);

    }

    return A_coefficient;
}
bigInt getNormalizeD(const bigInt &phi, const pairvec &ex_gcd){
    bigInt result = ex_gcd.second;
    if (result.isNeg){
        pairvec d = getDivideAndModulo(result.value, phi.value);
        bigInt q = d.first;
        result = addBigInt(result,multiplyBigInt(phi, addBigInt(q, bigInt({1},0))));
    }else {
        // check if ex_gcd.second >= phi
        pairvec d = getDivideAndModulo(ex_gcd.second.value, phi.value);
        result = d.second;
    }
    return result;
}
int main(int argc,char *argv[]){
    if (argc != 3)
        return cout << "Invalid arguments" << endl, 1;
    
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    ifstream file(argv[1]);
    ofstream out(argv[2]);
    string p_hex, q_hex, e_hex;
    getline(file, p_hex);
    getline(file, q_hex);
    getline(file, e_hex);
    bigInt phi;
    bigInt p = hexStringToBinary(p_hex);
    bigInt q = hexStringToBinary(q_hex);
    bigInt e = hexStringToBinary(e_hex);
    
    phi.value = multiply(sub(p.value,{1}), sub(q.value,{1}));
    // cout << "phi:" << binaryToHex(phi.value) << endl;
    pairvec ex_gcd = gcd(phi, e);
    
    
    bigInt gcd = addBigInt(multiplyBigInt(ex_gcd.first, phi), multiplyBigInt(ex_gcd.second, e));
    printBigInt(ex_gcd.second, 1);
    if (compare(gcd,bigInt({1},0)) == 0){
        bigInt result = getNormalizeD(phi, ex_gcd);
        out << binaryToHex(result.value);
        cout << binaryToHex(result.value) << endl;;
        // cout << binaryToHex(phi.value) << endl;
    }
    else {
        out << -1 << "\n";
        
    }
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(end - start);
    cout << "Time: " << time_span.count() << " seconds" << endl;
    out.close();
    file.close();

}