#pragma comment(linker, "/STACK:5000000")
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <stdexcept>
#include <fstream>

using namespace std;

// Struct để đại diện số lớn
struct BigInt
{
    vector<int> bin; // Dạng nhị phân
    int sign;        // Dấu: 0 = dương, 1 = âm
};

#define pairBigInt pair<BigInt,BigInt>

// Chuyển chuỗi hex sang vector nhị phânb
vector<int> convertHexToBinary(string &strHex)
{
    vector<int> arrBit;
    for (char c : strHex)
    {
        switch (c)
        {
        case '0':
            arrBit.insert(arrBit.end(), {0, 0, 0, 0});
            break;
        case '1':
            arrBit.insert(arrBit.end(), {0, 0, 0, 1});
            break;
        case '2':
            arrBit.insert(arrBit.end(), {0, 0, 1, 0});
            break;
        case '3':
            arrBit.insert(arrBit.end(), {0, 0, 1, 1});
            break;
        case '4':
            arrBit.insert(arrBit.end(), {0, 1, 0, 0});
            break;
        case '5':
            arrBit.insert(arrBit.end(), {0, 1, 0, 1});
            break;
        case '6':
            arrBit.insert(arrBit.end(), {0, 1, 1, 0});
            break;
        case '7':
            arrBit.insert(arrBit.end(), {0, 1, 1, 1});
            break;
        case '8':
            arrBit.insert(arrBit.end(), {1, 0, 0, 0});
            break;
        case '9':
            arrBit.insert(arrBit.end(), {1, 0, 0, 1});
            break;
        case 'A':
            arrBit.insert(arrBit.end(), {1, 0, 1, 0});
            break;
        case 'B':
            arrBit.insert(arrBit.end(), {1, 0, 1, 1});
            break;
        case 'C':
            arrBit.insert(arrBit.end(), {1, 1, 0, 0});
            break;
        case 'D':
            arrBit.insert(arrBit.end(), {1, 1, 0, 1});
            break;
        case 'E':
            arrBit.insert(arrBit.end(), {1, 1, 1, 0});
            break;
        case 'F':
            arrBit.insert(arrBit.end(), {1, 1, 1, 1});
            break;
        default:
            throw invalid_argument("Invalid hex character");
        }
    }
    // Loại bỏ các bit 0 thừa phía trước
    while (arrBit.size() > 1 && arrBit[0] == 0)
    {
        arrBit.erase(arrBit.begin());
    }
    return arrBit;
}

// Hàm in BigInt
void printBigInt(const BigInt &num)
{
    if (num.sign == 1)
        cout << "-";
    for (int bit : num.bin)
        cout << bit;
    cout << " = " ;
    if (num.sign == 1)
        cout << "-";
    // num.bin convert binary to decimal
    int dec = 0;
    for (int i = 0; i < num.bin.size(); i++)
    {
        dec += num.bin[i] * (1 << (num.bin.size() - i - 1));
    }
    cout << dec << endl;
}

// binary to hex
string binaryToHex(const vector<int> &bin)
{
    const char hexDigits[] = "0123456789ABCDEF";
    string hex;
    int value = 0;
    int bits = 0;
    for (int i = bin.size() - 1; i >= 0; i--)
    {
        value += bin[i] << bits;
        bits++;
        if (bits == 4)
        {
            hex = hexDigits[value] + hex;
            value = 0;
            bits = 0;
        }
    }
    if (bits > 0)
    {
        hex = hexDigits[value] + hex;
    }
    return hex;
}

// So sánh hai số nhị phân: 1 nếu a > b, -1 nếu a < b, 0 nếu a = b
int compare(const vector<int> &a, const vector<int> &b)
{
    if (a.size() != b.size())
        return (a.size() > b.size()) ? 1 : -1;
    for (size_t i = 0; i < a.size(); ++i)
    {
        if (a[i] != b[i])
            return (a[i] > b[i]) ? 1 : -1;
    }
    return 0;
}

// Hàm cộng hai số nhị phân
vector<int> addTwoBinaryNumbers(const vector<int> &a, const vector<int> &b)
{
    // Tạo bản sao của các vector để không ảnh hưởng đến tham số gốc
    vector<int> num1 = a;
    vector<int> num2 = b;

    // Bổ sung các bit 0 vào cuối để hai số có độ dài bằng nhau
    while (num1.size() < num2.size())
    {
        num1.insert(num1.begin(), 0); // Chèn bit 0 vào đầu num1
    }
    while (num2.size() < num1.size())
    {
        num2.insert(num2.begin(), 0); // Chèn bit 0 vào đầu num2
    }

    vector<int> result(num1.size() + 1, 0); // Thêm 1 để dự phòng carry
    int carry = 0;                          // Biến lưu giá trị nhớ

    // Cộng từ đáy lên
    for (int i = num1.size() - 1; i >= 0; --i)
    {
        int sum = num1[i] + num2[i] + carry; // Tổng hai bit và carry
        result[i + 1] = sum % 2;             // Lấy bit kết quả (0 hoặc 1)
        carry = sum / 2;                     // Tính carry mới
    }

    // Xử lý carry ở bit cao nhất
    result[0] = carry;

    // Loại bỏ các bit 0 thừa phía trước nếu cần
    while (result.size() > 1 && result[0] == 0)
    {
        result.erase(result.begin());
    }

    return result;
}
// Hàm trừ hai số nhị phân (a >= b)
vector<int> subTwoBinaryNumbers(const vector<int> &a, const vector<int> &b)
{
    vector<int> result(a.size(), 0); // Kết quả có cùng kích thước với `a`
    int borrow = 0;

    int i = a.size() - 1; // Con trỏ bit cuối của `a`
    int j = b.size() - 1; // Con trỏ bit cuối của `b`

    // Thực hiện trừ từng bit
    while (i >= 0)
    {
        int bitA = a[i];                // Bit từ `a`
        int bitB = (j >= 0) ? b[j] : 0; // Bit từ `b` (nếu vượt ngoài chỉ số thì xem như 0)

        // Tính bit kết quả và cập nhật borrow
        int diff = bitA - bitB - borrow;
        if (diff < 0)
        {
            diff += 2;  // Mượn từ bit cao hơn
            borrow = 1; // Đánh dấu mượn
        }
        else
        {
            borrow = 0;
        }

        result[i] = diff; // Lưu bit kết quả
        i--;
        j--;
    }

    // Loại bỏ các bit 0 thừa phía trước nếu cần
    while (result.size() > 1 && result[0] == 0)
    {
        result.erase(result.begin());
    }

    return result;
}

vector<int> multiplyTwoBinaryNumbers(const vector<int> &base, const vector<int> &b)
{
    vector<int> result = {0}; // Khởi tạo kết quả bằng 0
    vector<int> a = base;     // Sao chép số base để xử lý

    // Nếu một trong hai số là 0, trả về kết quả 0
    if (compare(base, {0}) ==0 || compare(b, {0}) == 0)
        return {0};

    // Lặp qua từng bit của số b (từ bit thấp nhất đến cao nhất)
    for (int i = b.size() - 1; i >= 0; --i)
    {
        if (b[i] & 1)
            result = addTwoBinaryNumbers(result, a); // Nếu bit là 1, cộng giá trị hiện tại của a vào result
        a.push_back(0);                              // Dịch trái số a (nhân đôi)
    }

    // Loại bỏ các số 0 thừa ở đầu kết quả
    while (result.size() > 1 && result[0] == 0)
    {
        result.erase(result.begin());
    }
    return result;
}

void divideBinaryNumbers(const vector<int> &dividend, const vector<int> &divisor,
                         vector<int> &quotient, vector<int> &remainder)
{
    // Khởi tạo giá trị ban đầu
    remainder.clear();
    quotient.clear();

    // Lặp qua từng bit của dividend
    for (size_t i = 0; i < dividend.size(); ++i)
    {
        // Đưa bit tiếp theo vào remainder
        remainder.push_back(dividend[i]);
        // Xóa các bit 0 thừa ở đầu remainder
        while (remainder.size() > 1 && remainder[0] == 0)
        {
            remainder.erase(remainder.begin());
        }

        // Kiểm tra nếu remainder >= divisor
        if (compare(remainder, divisor) >= 0)
        {
            remainder = subTwoBinaryNumbers(remainder, divisor); // remainder -= divisor
            quotient.push_back(1);                               // Thêm 1 vào quotient
        }
        else
        {
            quotient.push_back(0); // Thêm 0 vào quotient
        }
    }

    // Xóa các bit 0 thừa ở đầu quotient
    while (quotient.size() > 1 && quotient[0] == 0)
    {
        quotient.erase(quotient.begin());
    }
}

vector<int> modBinary(const vector<int> &binaryNum, const vector<int> &mod)
{
    vector<int> remainder, quotient;
    divideBinaryNumbers(binaryNum, mod, quotient, remainder); // Chia lấy dư
    return remainder;
}

vector<int> modMultiply(const vector<int> &num1, const vector<int> &num2, const vector<int> &mod)
{
    vector<int> product = {0};                        // Kết quả ban đầu bằng 0
    vector<int> moddedBinNum1 = modBinary(num1, mod); // num1 % mod
                                                      // vector<int> moddedBinNum1 = num1;
    vector<int> currentMultiplier = num2;             // Sao chép num2 để xử lý

    // Lặp qua từng bit của num2
    while (!currentMultiplier.empty())
    {
        // Nếu bit cuối cùng của currentMultiplier bằng 1
        if (currentMultiplier.back() == 1)
        {
            product = addTwoBinaryNumbers(product, moddedBinNum1); // product += moddedBinNum1

            // Nếu product >= mod, thực hiện modulo
            if (compare(product, mod) >= 0)
            {
                product = subTwoBinaryNumbers(product, mod);
            }
        }

        // Dịch trái moddedBinNum1 (tương đương nhân 2)
        moddedBinNum1.push_back(0);

        // Nếu moddedBinNum1 >= mod, thực hiện modulo
        if (compare(moddedBinNum1, mod) >= 0)
        {
            moddedBinNum1 = subTwoBinaryNumbers(moddedBinNum1, mod);
        }

        // Loại bỏ bit cuối cùng của currentMultiplier
        currentMultiplier.pop_back();
    }

    return product;
}

// Hàm tính lũy thừa modulo
vector<int> modExponentiate(const vector<int> &base, const vector<int> &exp, const vector<int> &mod)
{
    vector<int> result = {1}; // Đại diện nhị phân cho số 1
    vector<int> temp = mod;
    for (size_t i = 0; i < exp.size(); i++)
    {
        result = modMultiply(result, result, mod);
        if (exp[i] == 1)
        {
            result = modMultiply(result, base, mod);
        }
    }
    return result;
}

// ==============================BIG INT==============================
int compare(const BigInt &a, const BigInt &b)
{
    if (a.sign > b.sign)
    {
        return -1;
    }
    else if (a.sign < b.sign)
    {
        return 1;
    }

    if (a.sign)
    {
        return compare(b.bin, a.bin);
    }
    return compare(a.bin, b.bin);
}

// Hàm cộng hai BigInt
BigInt addBigInt(const BigInt &a, const BigInt &b)
{
    if (a.sign == b.sign)
    {
        return {addTwoBinaryNumbers(a.bin, b.bin), a.sign};
    }
    int cmp = compare(a.bin, b.bin);
    if (cmp >= 0)
    {
        return {subTwoBinaryNumbers(a.bin, b.bin), a.sign};
    }
    else
    {
        return {subTwoBinaryNumbers(b.bin, a.bin), b.sign};
    }
}

// Hàm trừ hai BigInt
BigInt subtractBigInt(const BigInt &a, const BigInt &b)
{
    BigInt negB = b;
    negB.sign = 1 - b.sign;
    return addBigInt(a, negB);
}

// Hàm nhân hai số BigInt
BigInt multiplyBigInt(const BigInt &a, const BigInt &b)
{
    BigInt result;
    result.sign = a.sign ^ b.sign;
    result.bin = multiplyTwoBinaryNumbers(a.bin, b.bin);
    return result;
}

// Hàm chia lấy dư BigInt
BigInt modBigInt(const BigInt &num, const BigInt &mod)
{
    BigInt remainder;
    vector<int> remBin = modBinary(num.bin, mod.bin);
    remainder.bin = remBin;
    remainder.sign = false;
    return remainder;
}

// // Hàm nhân modulo BigInt
// BigInt modMultiplyBigInt(const BigInt &a, const BigInt &b, const BigInt &mod)
// {
//     BigInt product = multiplyBigInt(a, b);
//     return modBigInt(product, mod);
// }

// // Hàm lũy thừa modulo BigInt
// BigInt modExponentiateBigInt(const BigInt &base, const BigInt &exp, const BigInt &mod)
// {
//     BigInt result = {{1}, false}; // BigInt = 1
//     BigInt modBase = modBigInt(base, mod);
//     vector<int> exponent = exp.bin;

//     for (size_t i = 0; i < exponent.size(); ++i)
//     {
//         result = modMultiplyBigInt(result, result, mod);
//         if (exponent[i] == 1)
//         {
//             result = modMultiplyBigInt(result, modBase, mod);
//         }
//     }
//     return result;
// }

// ===========================PAIR BIG INT==============================
pairBigInt addPairBigInt(const pairBigInt &a, const pairBigInt &b)
{
    return {addBigInt(a.first, b.first), addBigInt(a.second, b.second)};
}

pairBigInt subtractPairBigInt(const pairBigInt &a, const pairBigInt &b)
{
    return {subtractBigInt(a.first, b.first), subtractBigInt(a.second, b.second)};
}

pairBigInt multiplyNum(const pairBigInt &a, vector<int> &num)
{
    return {multiplyBigInt(a.first, {num, 0}), multiplyBigInt(a.second, {num, 0})};
}

pairBigInt getQuotientAndRemainder(const vector<int> &dividend, const vector<int> &divisor)
{
    vector<int> quotient, remainder;
    divideBinaryNumbers(dividend, divisor, quotient, remainder);
    return {{quotient, 0}, {remainder, 0}};
}

pairBigInt extendedEuclide(BigInt a, BigInt b)
{
    pairBigInt A_coefficient = {{{1},0}, {{0},0}};
    pairBigInt B_coefficient = {{{0},0}, {{1},0}};
    while (compare(b.bin, {0}))
    {
        
        pairBigInt d = getQuotientAndRemainder(a.bin, b.bin);
        BigInt &q = d.first;
        BigInt &r = d.second;
        a = b;
        b = r;
        pairBigInt R_coefficient = subtractPairBigInt(A_coefficient, multiplyNum(B_coefficient, q.bin));
        A_coefficient = B_coefficient;
        B_coefficient = R_coefficient;
    }
    return A_coefficient;
}

BigInt getMinimumPositiveD(const BigInt &phi, const pairBigInt &oldGCD)
{
    BigInt result = oldGCD.second;
    if (result.sign)
    {
        pairBigInt d = getQuotientAndRemainder(result.bin, phi.bin);
        BigInt temp = {{1},0};
        result = addBigInt(result, multiplyBigInt(phi, addBigInt(d.first, temp)));
    }
    else
    {
        // check if oldGCD.second >= phi
        pairBigInt d = getQuotientAndRemainder(oldGCD.second.bin, phi.bin);
        result = d.second;
    }
    return result;
}

// Chương trình chính
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
        return 1;
    }

    string inputFile = argv[1];
    string outputFile = argv[2];

    if (inputFile.empty() || outputFile.empty())
    {
        cout << "Invalid input/output file" << endl;
        return 1;
    }

    ifstream in(inputFile);
    ofstream out(outputFile);

    if (!in.is_open() || !out.is_open())
    {
        cout << "Error opening file(s)" << endl;
        return 1;
    }

    string p, q, e;
    getline(in, p);
    getline(in, q);
    getline(in, e);

    BigInt phi;
    BigInt pBin = {convertHexToBinary(p), 0}; // 24263
    BigInt qBin = {convertHexToBinary(q), 0}; // 2003
    BigInt eBin = {convertHexToBinary(e), 0}; // 2449

    phi.bin = multiplyTwoBinaryNumbers(subTwoBinaryNumbers(pBin.bin, {1}), subTwoBinaryNumbers(qBin.bin, {1}));
    phi.sign = 0;

    pairBigInt oldGCD = extendedEuclide(phi, eBin);

    BigInt gcd = addBigInt(multiplyBigInt(oldGCD.first, phi), multiplyBigInt(oldGCD.second, eBin));
    if (compare(gcd, {{1},0}) == 0)
    {
        BigInt d = getMinimumPositiveD(phi, oldGCD);
        out << binaryToHex(d.bin) << endl;
    }
    else
    {
        cout << -1 <<endl;
    }
    cout << "Result is written to " << outputFile << endl;
    in.close();
    out.close();
    return 0;
}
