#pragma comment(linker, "/STACK:5000000")
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

const vector<int> Bit0 = {0};
const vector<int> Bit1 = {1};
const vector<int> Bit2 = {0, 1};

/*
Chuyen chuoi Hex sang chuoi Binary
Input:	1 string ( chuoi Hex ) ( strHex ).
Output: 1 vector ( chuoi Binary ).
*/
vector<int> convertHexToBinary(string strHex)
{
    vector<int> arrBit;
    for (int i = 0; i < strHex.length(); i++)
    {
        switch (strHex[i])
        {
        case '0':
        {
            arrBit.push_back(0);
            arrBit.push_back(0);
            arrBit.push_back(0);
            arrBit.push_back(0);
            break;
        }
        case '1':
        {
            arrBit.push_back(0);
            arrBit.push_back(0);
            arrBit.push_back(0);
            arrBit.push_back(1);
            break;
        }
        case '2':
        {
            arrBit.push_back(0);
            arrBit.push_back(0);
            arrBit.push_back(1);
            arrBit.push_back(0);
            break;
        }
        case '3':
        {
            arrBit.push_back(0);
            arrBit.push_back(0);
            arrBit.push_back(1);
            arrBit.push_back(1);
            break;
        }
        case '4':
        {
            arrBit.push_back(0);
            arrBit.push_back(1);
            arrBit.push_back(0);
            arrBit.push_back(0);
            break;
        }
        case '5':
        {
            arrBit.push_back(0);
            arrBit.push_back(1);
            arrBit.push_back(0);
            arrBit.push_back(1);
            break;
        }
        case '6':
        {
            arrBit.push_back(0);
            arrBit.push_back(1);
            arrBit.push_back(1);
            arrBit.push_back(0);
            break;
        }
        case '7':
        {
            arrBit.push_back(0);
            arrBit.push_back(1);
            arrBit.push_back(1);
            arrBit.push_back(1);
            break;
        }
        case '8':
        {
            arrBit.push_back(1);
            arrBit.push_back(0);
            arrBit.push_back(0);
            arrBit.push_back(0);
            break;
        }
        case '9':
        {
            arrBit.push_back(1);
            arrBit.push_back(0);
            arrBit.push_back(0);
            arrBit.push_back(1);
            break;
        }
        case 'A':
        {
            arrBit.push_back(1);
            arrBit.push_back(0);
            arrBit.push_back(1);
            arrBit.push_back(0);
            break;
        }
        case 'B':
        {
            arrBit.push_back(1);
            arrBit.push_back(0);
            arrBit.push_back(1);
            arrBit.push_back(1);
            break;
        }
        case 'C':
        {
            arrBit.push_back(1);
            arrBit.push_back(1);
            arrBit.push_back(0);
            arrBit.push_back(0);
            break;
        }
        case 'D':
        {
            arrBit.push_back(1);
            arrBit.push_back(1);
            arrBit.push_back(0);
            arrBit.push_back(1);
            break;
        }
        case 'E':
        {
            arrBit.push_back(1);
            arrBit.push_back(1);
            arrBit.push_back(1);
            arrBit.push_back(0);
            break;
        }
        case 'F':
        {
            arrBit.push_back(1);
            arrBit.push_back(1);
            arrBit.push_back(1);
            arrBit.push_back(0);
            break;
        }
        }
    }
    while (arrBit.size()>1 && arrBit[0]==0)
    {
        arrBit.erase(arrBit.begin());
    }
    return arrBit;
}

// Hàm cộng hai số nhị phân
vector<int> addTwoBinaryNumbers(const vector<int> &a, const vector<int> &b)
{
    vector<int> result(max(a.size(), b.size()) + 1, 0); // Thêm 1 để dự phòng carry
    int carry = 0;

    int i = a.size() - 1;      // Con trỏ bit cuối của a
    int j = b.size() - 1;      // Con trỏ bit cuối của b
    int k = result.size() - 1; // Con trỏ bit cuối của result

    // Bắt đầu cộng từ bit cuối lên đầu
    while (i >= 0 || j >= 0 || carry)
    {
        int bitA = (i >= 0) ? a[i--] : 0; // Lấy bit của a, nếu hết thì bằng 0
        int bitB = (j >= 0) ? b[j--] : 0; // Lấy bit của b, nếu hết thì bằng 0
        int sum = bitA + bitB + carry;    // Tính tổng 2 bit và carry
        cout << bitA << " " << bitB << " " << carry << " " << sum%2 << endl;
        result[k--] = sum % 2;            // Lấy bit kết quả
        carry = sum / 2;                  // Tính carry mới
    }

    // Loại bỏ các bit 0 thừa phía trước nếu cần
    while (result.size() > 1 && result[0] == 0)
    {
        result.erase(result.begin());
    }

    return result;
}

// Hàm trừ hai số nhị phân
vector<int> subTwoBinaryNumbers(const vector<int> &a, const vector<int> &b)
{
    vector<int> result = a;
    vector<int> borrow(b.size(), 0);
    for (size_t i = 0; i < b.size(); ++i)
    {
        if (result[i] < b[i])
        {
            result[i] += 2 - b[i];
            result[i + 1] -= 1; // Borrow
        }
        else
        {
            result[i] -= b[i];
        }
    }
    while (!result.empty() && result.back() == 0)
    {
        result.pop_back();
    }
    return result;
}

// So sánh hai số nhị phân
int compareTwoBinaryNumbers(const vector<int> &a, const vector<int> &b)
{
    if (a.size() != b.size())
    {
        return a.size() > b.size() ? 1 : -1;
    }
    for (int i = a.size() - 1; i >= 0; --i)
    {
        if (a[i] != b[i])
        {
            return a[i] > b[i] ? 1 : -1;
        }
    }
    return 0;
}

// Hàm nhân hai số nhị phân với modulo
vector<int> modMultiply(const vector<int> &num1, const vector<int> &num2, const vector<int> &mod)
{
    vector<int> res = {0};
    vector<int> tempA = num1;
    vector<int> tempB = num2;

    while (!tempB.empty())
    {
        if (tempB.back() == 1)
        {
            res = addTwoBinaryNumbers(res, tempA);
            if (compareTwoBinaryNumbers(res, mod) >= 0)
            {
                res = subTwoBinaryNumbers(res, mod);
            }
        }
        tempA.push_back(0);
        if (compareTwoBinaryNumbers(tempA, mod) >= 0)
        {
            tempA = subTwoBinaryNumbers(tempA, mod);
        }
        tempB.pop_back();
    }
    return res;
}

// Hàm tính lũy thừa modulo
vector<int> modExponentiate(const vector<int> &base, const vector<int> &exp, const vector<int> &mod)
{
    vector<int> result = {1}; // Đại diện nhị phân cho số 1
    for (size_t i = 0; i < exp.size(); ++i)
    {
        result = modMultiply(result, result, mod);
        if (exp[i] == 1)
        {
            result = modMultiply(result, base, mod);
        }
    }
    return result;
}

// Kiểm tra Miller-Rabin
bool millerRabinTest(const vector<int> &num, const vector<int> &base)
{
    vector<int> d = subTwoBinaryNumbers(num, {1}); // d = num - 1
    int s = 0;

    while (!d.empty() && d.back() == 0)
    {
        d.pop_back();
        ++s;
    }

    vector<int> x = modExponentiate(base, d, num);
    if (compareTwoBinaryNumbers(x, {1}) == 0 || compareTwoBinaryNumbers(x, subTwoBinaryNumbers(num, {1})) == 0)
    {
        return true;
    }

    for (int i = 1; i < s; ++i)
    {
        x = modMultiply(x, x, num);
        if (compareTwoBinaryNumbers(x, subTwoBinaryNumbers(num, {1})) == 0)
        {
            return true;
        }
    }
    return false;
}

// Kiểm tra số nguyên tố
bool isPrime(const vector<int> &num, int iterations)
{
    if (compareTwoBinaryNumbers(num, {2}) < 0)
    {
        return false;
    }
    vector<vector<int>> baseCandidates = {{1, 0}, {1, 1}, {1, 0, 1}, {1, 1, 1}}; // 2, 3, 5, 7
    for (int i = 0; i < iterations; ++i)
    {
        vector<int> base = baseCandidates[i % baseCandidates.size()];
        if (!millerRabinTest(num, base))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string hexString = "D119";
    vector<int> binaryVector = convertHexToBinary(hexString);
    for (int i = 0; i < binaryVector.size(); i++)
    {
        cout << binaryVector[i];
    }
    cout << endl;
    vector<int> testVector = convertHexToBinary("DE95");
    for (int i = 0; i < testVector.size(); i++)
    {
        cout << testVector[i];
    }
    cout << endl;
    vector<int> result = addTwoBinaryNumbers(binaryVector, testVector);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
}

// int main()
// {
//     string hexString;
//     vector<int> binaryVector;

//     string nameFile = "test";

//     ifstream in;
//     in.open(nameFile + ".inp");
//     ofstream out;
//     out.open(nameFile + ".out");

//     in >> hexString;
//     binaryVector = convertHexToBinary(hexString);
//     if (isPrime(binaryVector, 3))
//     {
//         out << "1";
//     }
//     else
//     {
//         out << "0";
//     }

//     return 0;
// }