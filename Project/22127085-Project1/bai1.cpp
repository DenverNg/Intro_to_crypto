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
vector<int> convertHexToBinary(string &strHex)
{
    vector<int> arrBit = {};
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
        default:
            throw "Invalid hex string";
        }
    }
    cout << endl;
    while (arrBit.size() > 1 && arrBit[0] == 0)
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

// So sánh hai số nhị phân
// Trả về 1 nếu a > b, -1 nếu a < b, 0 nếu a = b
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

// Kiểm tra Miller-Rabin và xác định số nguyên tố
bool millerRabin(const vector<int> &num, int iterations)
{
    // Nếu num < 2 thì không phải số nguyên tố
    if (compareTwoBinaryNumbers(num, {2}) < 0)
    {
        return false;
    }

    // Nếu num là 2 thì là số nguyên tố
    if (compareTwoBinaryNumbers(num, {2}) == 0)
    {
        return true;
    }

    // Nếu num chẵn thì không phải số nguyên tố
    if (num.back() == 0)
    {
        return false;
    }

    // Chuẩn bị cho kiểm tra Miller-Rabin
    vector<int> d = subTwoBinaryNumbers(num, {1}); // d = num - 1
    int s = 0;

    // Tách d thành dạng d * 2^s
    while (!d.empty() && d.back() == 0)
    {
        d.pop_back();
        ++s;
    }

    vector<vector<int>> baseCandidates = {{1, 0}, {1, 1}, {1, 0, 1}, {1, 1, 1}}; // 2, 3, 5, 7

    // Lặp lại kiểm tra theo số lần `iterations`
    vector<int> base;
    for (int i = 0; i < iterations; ++i)
    {
        // Chọn cơ số (base) từ danh sách các số nguyên tố nhỏ
        switch (i%baseCandidates.size())
        {
        case 0:
            base = baseCandidates[0];
            break;
        case 1:
            base = baseCandidates[1];
            break;
        case 2:
            base = baseCandidates[2];
            break;
        case 3:
            base = baseCandidates[3];
            break;
        default:
            break;
        }
        cout << "Iteration " << i + 1 << ": Base = ";
        // Tính x = base^d mod num
        vector<int> x = modExponentiate(base, d, num);
        for (int i = 0; i < x.size(); i++)
        {
            cout << x[i];
        }
        // Nếu x == 1 hoặc x == num - 1, tiếp tục kiểm tra
        if (compareTwoBinaryNumbers(x, {1}) == 0 || compareTwoBinaryNumbers(x, subTwoBinaryNumbers(num, {1})) == 0)
        {
            continue;
        }

        // Lặp qua s-1 bước để kiểm tra
        bool found = false;
        for (int j = 1; j < s; ++j)
        {
            x = modMultiply(x, x, num);
            if (compareTwoBinaryNumbers(x, subTwoBinaryNumbers(num, {1})) == 0)
            {
                found = true;
                break;
            }
        }

        // Nếu không thỏa điều kiện, chắc chắn không phải số nguyên tố
        if (!found)
        {
            return false;
        }
    }

    // Nếu qua tất cả kiểm tra, là số nguyên tố
    return true;
}

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
    string hexString;
    in >> hexString;
    cout << "Hex: " << hexString << endl;

    vector<int> num = convertHexToBinary(hexString);
    cout << endl;
    cout << "Binary: ";
    for (int i = 0; i < num.size(); i++)
    {
        cout << num[i];
    }
    cout << endl;
    int time = 1;
    if (num.size() <= 256)
    {
        time = 10;
    }
    else if (num.size() <= 348)
    {
        time = 3;
    }
    else
    {
        time = 2;
    }
    cout << "Checking..." << endl;
    if (millerRabin(num, time))
    {
        out << 1;
        cout << "Prime" << endl;
    }
    else
    {
        out << 0;
        cout << "Composite" << endl;
    }
    in.close();
    out.close();
    return 0;
}