#include <iostream>
#include <numeric>
#include <stdexcept> 
#include <cassert>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>

#include "switch.h"

int cmp(int size, int* arr1, int* arr2){
    assert(size >= 0 && "Size cannot be negative.");

    int sum1 = std::accumulate(arr1, arr1 + size, 0);
    int sum2 = std::accumulate(arr2, arr2 + size, 0);

    if(sum1 < sum2){
        return -1;
    }
    else if(sum1 > sum2){
        return 1;
    }
    else{
        return 0;
    }
}

void test_cmp() {
    int arr1[] = {1, 2, 3};
    int arr2[] = {1, 2, 3};
    int sizeArr1 = sizeof(arr1) / sizeof(arr1[0]);
    assert(cmp(sizeArr1, arr1, arr2) == 0);

    int arr3[] = {4, 5, 6};
    assert(cmp(sizeArr1, arr3, arr1) == 1);
    assert(cmp(sizeArr1, arr1, arr3) == -1);

    int arr4[] = {-1, -2, -3};
    int arr5[] = {-1, -2, -3};
    int sizeArr4 = sizeof(arr4) / sizeof(arr4[0]);
    assert(cmp(sizeArr4, arr4, arr5) == 0);

    int arr6[] = {-4, -5, -6};
    assert(cmp(sizeArr4, arr6, arr4) == -1);
    assert(cmp(sizeArr4, arr4, arr6) == 1);
    assert(cmp(sizeArr4, arr1, arr4) == 1);


    int arrEmpty1[] = {};
    int arrEmpty2[] = {};
    assert(cmp(0,arrEmpty1,arrEmpty2) == 0);

    std::cout << "Tests for the  cmp  function passed successfully" << '\n';
}


int count(const char* str1,const char* str2) {
    if (str1 == nullptr || str2 == nullptr || strlen(str2) == 0) {
        return 0;
    }

    int cnt = 0;
    const char* temp = str1;
    size_t len2 = strlen(str2);

    while ((temp = strstr(temp, str2)) != nullptr) {
        cnt++;            
        temp += len2 - 1;         
    }

    return cnt;
}


void test_count() {
    const char* str1 = "abababab";
    const char* str2 = "ab";
    assert(count(str1, str2) == 4);

    const char* str3 = "hello";
    const char* str4 = "hello";
    assert(count(str3, str4) == 1);

    const char* str5 = "abcd";
    const char* str6 = "ef";
    assert(count(str5, str6) == 0);

    const char* str7 = "any string";
    const char* str8 = "";
    assert(count(str7, str8) == 0);

    const char* str9 = "";
    const char* str10 = "any";
    assert(count(str9, str10) == 0);

    const char* str11 = "short";
    const char* str12 = "longsubstring";
    assert(count(str11, str12) == 0);

    const char* str13 = "ababab";
    const char* str14 = "aba";
    assert(count(str13, str14) == 2);

    std::cout << "Tests for the  count  function passed successfully" << '\n';
}


void test_Switch() {
    CiscoSwitch cisco("sw1", 48);
    HuaweiSwitch huawei("sw2", 24);
    JuniperSwitch juniper("sw3", 16);

    assert(cisco.getFullName() == "Cisco:sw1");
    assert(cisco.getNumPort() == 48);

    assert(huawei.getFullName() == "Huawei:sw2");
    assert(huawei.getNumPort() == 24);

    assert(juniper.getFullName() == "Juniper:sw3");
    assert(juniper.getNumPort() == 16);

    std::ostringstream oss;
    std::streambuf* original_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    
    cisco.initialize();
    std::cout.rdbuf(original_cout_streambuf);
    assert(oss.str() == "Cisco:sw1: Up 48 ports\n");

    oss.str(""); 
    oss.clear(); 

    std::cout.rdbuf(oss.rdbuf());
    huawei.initialize();
    std::cout.rdbuf(original_cout_streambuf);
    assert(oss.str() == "Huawei:sw2: Up 24 ports\n");

    oss.str("");
    oss.clear();

    std::cout.rdbuf(oss.rdbuf());
    juniper.initialize();
    std::cout.rdbuf(original_cout_streambuf);
    assert(oss.str() == "Juniper:sw3: Up 16 ports\n");

    std::cout << "Tests for the  Switch  class passed successfully" << '\n';
}


int main() {
    test_count();
    test_cmp();
    test_Switch();
}