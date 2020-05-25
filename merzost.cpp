#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <ctime>

using namespace std;
int times, razrad1, razrad2, razrad3;
vector <bool> nul;

void pairOperation(int pair, int razrad, int operation) {
    cout << "Pair " << pair << "  " << razrad << "."<<operation<< "operation" << endl;
}
vector <bool> toBinaryStraight(int num)
{
    vector <bool> res;
    size_t size;
    int num_;
    num_ = abs(num);
    while (num_)
    {
        res.emplace(res.begin(), num_ % 2);
        num_ /= 2;
    }
    size = res.size();
    for (size_t i = 0; i < 6 - size; i++)
    {
        res.emplace(res.begin(), 0);
    }
    if (num < 0)
    {
        res[0] = 1;
    }
    return res;
}
vector <bool> addition(vector <bool> a, vector <bool> b)
{
    vector <bool> res;
    bool trans = false;
    for (size_t i = 0; i = a.size() - b.size(); i++)
    {
        b.push_back(0);
    }
    for (size_t i = a.size(); i > 0; i--)
    {
        if (a[i - 1] == 0 && b[i - 1] == 0 && trans == false)
        {
            res.emplace(res.begin(), 0);
            trans = false;
        }
        else if (a[i - 1] == 0 && b[i - 1] == 0 && trans == true)
        {
            res.emplace(res.begin(), 1);
            trans = false;
        }
        else if (a[i - 1] == 1 && b[i - 1] == 0 && trans == false)
        {
            res.emplace(res.begin(), 1);
            trans = false;
        }
        else if (a[i - 1] == 1 && b[i - 1] == 0 && trans == true)
        {
            res.emplace(res.begin(), 0);
            trans = true;
        }
        else if (a[i - 1] == 0 && b[i - 1] == 1 && trans == false)
        {
            res.emplace(res.begin(), 1);
            trans = false;
        }
        else if (a[i - 1] == 0 && b[i - 1] == 1 && trans == true)
        {
            res.emplace(res.begin(), 0);
            trans = true;
        }
        else if (a[i - 1] == 1 && b[i - 1] == 1 && trans == false)
        {
            res.emplace(res.begin(), 0);
            trans = true;
        }
        else if (a[i - 1] == 1 && b[i - 1] == 1 && trans == true)
        {
            res.emplace(res.begin(), 1);
            trans = true;
        }
    }
    return res;
} 
vector <int> enterNumbersInVector(vector<int> v, int pairs){
    for (int i = 0; i < pairs; i++)
    {
        int n1;
        cin >> n1;
        v.push_back(n1);
    }
    return v;
}
void vectorToBinary(int pairs, vector <int> v) {
    for (int i = 0; i < pairs; i++)
    {
        vector <bool> res;
        res = toBinaryStraight(v[i]);
        cout << v[i] << "  -  ";
        for (int i = 0; i < res.size(); i++)
        {
            if (i == 4)
            {
                cout << ".";
            }
            cout << res[i];
        }
        cout << endl;
    }
   
}
int whatStage() {
    int n, stage;
    bool s = false;
    while (s == false) {
        cout << "How many stages do you want?  (1/2/3/6/18)" << endl;
        cin >> n;
        if (n == 1 || n == 2 || n == 3 || n == 6 || n == 18)
        {
            stage = n;
            s = true;
        }
    };
    cout << endl;
    return stage;
}
void time()
{
    times++;
    times++;
    times++;
    cout << endl<<times<<endl;

}
int razradChange(int razrad) {
   return razrad++;
}
void crop(int j) {
    if (j == 4||j==8)
    {
        cout << ".";
    }
}
void printBoolVectorWithCrop(vector<bool>v){
    for (int j = 0; j < v.size(); j++)
    {
        if (j == 4)
        {
            cout << ".";
        }
        cout << v[j];
    }
}
void straightLine(){
    for (int i = 0; i < 20; i++)
    {
        printf("%c", 254);
    }
}
void beforeCalculation(vector<bool>v1, vector<bool>v2, int pair) {
   
    cout << "Pair "<< pair<<":" << endl;
    printBoolVectorWithCrop(v1);
    cout << endl;
    printBoolVectorWithCrop(v2);
    cout << endl;
    straightLine();
    cout << endl;
}
vector <bool> stage1understage1(vector<bool>v1, vector<bool>v2, int razrad, int pair) {
    pairOperation(pair, razrad, 1);
    vector<bool> first;
    if (v2[v2.size() - razrad] == 0)
    {


        for (int j = 0; j < v2.size(); j++)
        {
            first.push_back(0);
        }
        for (int j = 0; j < first.size(); j++)
        {
            crop(j);
            cout << first[j];
        }

    }
    else
    {

        for (int j = 0; j < v2.size(); j++)
        {
            first.push_back(v1[j]);
        }
        for (int j = 0; j < first.size(); j++)
        {
            crop(j);
            cout << first[j];
        }

    }
    cout << endl;
    straightLine();
    cout << endl;
    return first;
}
void nulVector() {
    for (int i = 0; i < 6; i++)
    {
        nul.push_back(0);
    }
}
vector<bool> stage1UnderStage2(vector<bool>first, vector<bool>secondb_before, int razrad, int pair) {
    pairOperation(pair, razrad,2);
    vector<bool> sum = addition(secondb_before, first);
    for (int j = 0; j < sum.size(); j++)
    {
        crop(j);
        cout << sum[j];
    }
    cout << endl;
    straightLine();
    cout << endl;
    return sum;
}
vector<bool> stage1UnderStage3(vector<bool>sum, int razrad, int pair) {
    pairOperation(pair, razrad, 3);
    vector <bool> second(sum.size() + 1);

    for (int i = 1; i < sum.size() + 1; i++)
    {
        second[i] = sum[i - 1];
    }
    for (int j = 0; j < second.size(); j++)
    {
        crop(j);
        cout << second[j];
    }
    cout << endl;
    straightLine();
    cout << endl;
    return second;
}
vector<bool> stage3Operations(vector<bool>num1,vector<bool>num2, vector<bool> second_before,int razrad,int pair) {
      vector<bool> vector1 = stage1understage1(num1, num2, razrad, pair);
      vector<bool> sum = stage1UnderStage2(vector1, second_before, razrad, pair);
      vector<bool> vector2 = stage1UnderStage3(sum, razrad, pair);

      return vector2;
}
int main()
{
 
    razrad1 = 1;
    razrad2 = 1;
    razrad3 = 1;

    nulVector();

   
    int pairs;
    cout << "Pairs of number" << endl;
    pairs = 3;
    cout << 3 << endl;
    


    cout << "enter " << pairs << " the first vector" << endl;
    vector<int>v1 = enterNumbersInVector(v1, pairs);

    cout << "enter " << pairs << " the second vector" << endl;
    vector<int>v2 = enterNumbersInVector(v2, pairs);


    
    cout << "first vector" << endl;
    vectorToBinary(pairs, v1);

    cout << "second vector" << endl;
    vectorToBinary(pairs, v2);


   
    int stage = whatStage();
    int operations_in_stage = 18 / stage;   

    
    vector<bool> pair1num1 = toBinaryStraight(v1[0]);
    vector<bool> pair1num2 = toBinaryStraight(v2[0]);
    vector<bool> pair2num1 = toBinaryStraight(v1[1]);
    vector<bool> pair2num2 = toBinaryStraight(v2[1]);
    vector<bool> pair3num1 = toBinaryStraight(v1[2]);
    vector<bool> pair3num2 = toBinaryStraight(v2[2]);


    
    beforeCalculation(pair1num1, pair1num2, 1);
    beforeCalculation(pair2num1, pair2num2, 2);
    beforeCalculation(pair3num1, pair3num2, 3);

    switch (stage)
    {
    case 1:
    {

        vector<bool> vector11 = stage3Operations(pair1num1, pair1num2, nul, razrad1, 1); razrad1++; time();
        vector<bool> vector12 = stage3Operations(pair1num1, pair1num2, vector11, razrad1, 1); razrad1++; time();
        vector<bool> vector13 = stage3Operations(pair1num1, pair1num2, vector12, razrad1, 1); razrad1++; time();
        vector<bool> vector14 = stage3Operations(pair1num1, pair1num2, vector13, razrad1, 1); razrad1++; time();
        vector<bool> vector15 = stage3Operations(pair1num1, pair1num2, vector14, razrad1, 1); razrad1++; time();
        vector<bool> vector16 = stage3Operations(pair1num1, pair1num2, vector15, razrad1, 1); time();

        vector<bool> vector21 = stage3Operations(pair2num1, pair2num2, nul, razrad2, 2); razrad2++; time();
        vector<bool> vector22 = stage3Operations(pair2num1, pair2num2, vector21, razrad2, 2); razrad2++; time();
        vector<bool> vector23 = stage3Operations(pair2num1, pair2num2, vector22, razrad2, 2); razrad2++; time();
        vector<bool> vector24 = stage3Operations(pair2num1, pair2num2, vector23, razrad2, 2); razrad2++; time();
        vector<bool> vector25 = stage3Operations(pair2num1, pair2num2, vector24, razrad2, 2); razrad2++; time();
        vector<bool> vector26 = stage3Operations(pair2num1, pair2num2, vector25, razrad2, 2); time();

        vector<bool> vector31 = stage3Operations(pair3num1, pair3num2, nul, razrad3, 3); razrad3++; time();
        vector<bool> vector32 = stage3Operations(pair3num1, pair3num2, vector31, razrad3, 3); razrad3++; time();
        vector<bool> vector33 = stage3Operations(pair3num1, pair3num2, vector32, razrad3, 3); razrad3++; time();
        vector<bool> vector34 = stage3Operations(pair3num1, pair3num2, vector33, razrad3, 3); razrad3++; time();
        vector<bool> vector35 = stage3Operations(pair3num1, pair3num2, vector34, razrad3, 3); razrad3++; time();
        vector<bool> vector36 = stage3Operations(pair3num1, pair3num2, vector35, razrad3, 3); time();
        break;
    }
    
    case 2:
    {
        vector<bool> vector11 = stage3Operations(pair1num1, pair1num2, nul, razrad1, 1); razrad1++; time();
        vector<bool> vector12 = stage3Operations(pair1num1, pair1num2, vector11, razrad1, 1); razrad1++; time();
        vector<bool> vector13 = stage3Operations(pair1num1, pair1num2, vector12, razrad1, 1); razrad1++; time();

        vector<bool> vector21 = stage3Operations(pair2num1, pair2num2, nul, razrad2, 2); razrad2++;
        vector<bool> vector14 = stage3Operations(pair1num1, pair1num2, vector13, razrad1, 1); razrad1++; time();
        vector<bool> vector22 = stage3Operations(pair2num1, pair2num2, vector21, razrad2, 2); razrad2++;
        vector<bool> vector15 = stage3Operations(pair1num1, pair1num2, vector14, razrad1, 1); razrad1++; time();
        vector<bool> vector23 = stage3Operations(pair2num1, pair2num2, vector22, razrad2, 2); razrad2++;
        vector<bool> vector16 = stage3Operations(pair1num1, pair1num2, vector15, razrad1, 1); time();

        vector<bool> vector31 = stage3Operations(pair3num1, pair3num2, nul, razrad3, 3); razrad3++;
        vector<bool> vector24 = stage3Operations(pair2num1, pair2num2, vector23, razrad2, 2); razrad2++; time();
        vector<bool> vector32 = stage3Operations(pair3num1, pair3num2, vector31, razrad3, 3); razrad3++;
        vector<bool> vector25 = stage3Operations(pair2num1, pair2num2, vector24, razrad2, 2); razrad2++; time();
        vector<bool> vector33 = stage3Operations(pair3num1, pair3num2, vector32, razrad3, 3); razrad3++;
        vector<bool> vector26 = stage3Operations(pair2num1, pair2num2, vector25, razrad2, 2); time();

        vector<bool> vector34 = stage3Operations(pair3num1, pair3num2, vector33, razrad3, 3); razrad3++; time();
        vector<bool> vector35 = stage3Operations(pair3num1, pair3num2, vector34, razrad3, 3); razrad3++; time();
        vector<bool> vector36 = stage3Operations(pair3num1, pair3num2, vector35, razrad3, 3); time();
        break;
    }
    case 3:
    {
        vector<bool> vector11 = stage3Operations(pair1num1, pair1num2, nul, razrad1, 1); razrad1++; time();
        vector<bool> vector12 = stage3Operations(pair1num1, pair1num2, vector11, razrad1, 1); razrad1++; time();

        vector<bool> vector21 = stage3Operations(pair2num1, pair2num2, nul, razrad2, 2); razrad2++;
        vector<bool> vector13 = stage3Operations(pair1num1, pair1num2, vector12, razrad1, 1); razrad1++; time();
        vector<bool> vector22 = stage3Operations(pair2num1, pair2num2, vector21, razrad2, 2); razrad2++;
        vector<bool> vector14 = stage3Operations(pair1num1, pair1num2, vector13, razrad1, 1); razrad1++; time();

        vector<bool> vector31 = stage3Operations(pair3num1, pair3num2, nul, razrad3, 3); razrad3++;
        vector<bool> vector23 = stage3Operations(pair2num1, pair2num2, vector22, razrad2, 2); razrad2++;
        vector<bool> vector15 = stage3Operations(pair1num1, pair1num2, vector14, razrad1, 1); razrad1++; time();
        vector<bool> vector32 = stage3Operations(pair3num1, pair3num2, vector31, razrad3, 3); razrad3++;
        vector<bool> vector24 = stage3Operations(pair2num1, pair2num2, vector23, razrad2, 2); razrad2++;
        vector<bool> vector16 = stage3Operations(pair1num1, pair1num2, vector15, razrad1, 1); time();

        vector<bool> vector33 = stage3Operations(pair3num1, pair3num2, vector32, razrad3, 3); razrad3++;
        vector<bool> vector25 = stage3Operations(pair2num1, pair2num2, vector24, razrad2, 2); razrad2++; time();
        vector<bool> vector34 = stage3Operations(pair3num1, pair3num2, vector33, razrad3, 3); razrad3++;
        vector<bool> vector26 = stage3Operations(pair2num1, pair2num2, vector25, razrad2, 2); time();

        vector<bool> vector35 = stage3Operations(pair3num1, pair3num2, vector34, razrad3, 3); razrad3++; time();
        vector<bool> vector36 = stage3Operations(pair3num1, pair3num2, vector35, razrad3, 3); time();

        break;

    }
    case 6:
    {
        vector<bool> vector11 = stage3Operations(pair1num1, pair1num2, nul, razrad1, 1); razrad1++; time();

        vector<bool> vector21 = stage3Operations(pair2num1, pair2num2, nul, razrad2, 2); razrad2++;
        vector<bool> vector12 = stage3Operations(pair1num1, pair1num2, vector11, razrad1, 1); razrad1++; time();

        vector<bool> vector31 = stage3Operations(pair3num1, pair3num2, nul, razrad3, 3); razrad3++;
        vector<bool> vector22 = stage3Operations(pair2num1, pair2num2, vector21, razrad2, 2); razrad2++;
        vector<bool> vector13 = stage3Operations(pair1num1, pair1num2, vector12, razrad1, 1); razrad1++; time();

        vector<bool> vector32 = stage3Operations(pair3num1, pair3num2, vector31, razrad3, 3); razrad3++;
        vector<bool> vector23 = stage3Operations(pair2num1, pair2num2, vector22, razrad2, 2); razrad2++;
        vector<bool> vector14 = stage3Operations(pair1num1, pair1num2, vector13, razrad1, 1); razrad1++; time();

        vector<bool> vector33 = stage3Operations(pair3num1, pair3num2, vector32, razrad3, 3); razrad3++;
        vector<bool> vector24 = stage3Operations(pair2num1, pair2num2, vector23, razrad2, 2); razrad2++;
        vector<bool> vector15 = stage3Operations(pair1num1, pair1num2, vector14, razrad1, 1); razrad1++; time();


        vector<bool> vector34 = stage3Operations(pair3num1, pair3num2, vector33, razrad3, 3); razrad3++;
        vector<bool> vector25 = stage3Operations(pair2num1, pair2num2, vector24, razrad2, 2); razrad2++;
        vector<bool> vector16 = stage3Operations(pair1num1, pair1num2, vector15, razrad1, 1); time();


        vector<bool> vector35 = stage3Operations(pair3num1, pair3num2, vector34, razrad3, 3); razrad3++;
        vector<bool> vector26 = stage3Operations(pair2num1, pair2num2, vector25, razrad2, 2); time();

        vector<bool> vector36 = stage3Operations(pair3num1, pair3num2, vector35, razrad3, 3); time();

        break;
    }
   
    case 18:
    {


        vector<bool> vector111 = stage1understage1(pair1num1, pair1num2, razrad1, 1); 

        vector<bool> vector121 = stage1understage1(pair2num1, pair2num2, razrad2, 2);
        vector<bool> sum11 = stage1UnderStage2(vector111, nul, razrad1, 1); 
       
        vector<bool> vector131 = stage1understage1(pair3num1, pair3num2, razrad3, 3);
        vector<bool> sum21 = stage1UnderStage2(vector121, nul, razrad2, 2);
        vector<bool> vector211 = stage1UnderStage3(sum11, razrad1, 1); razrad1++; time();

        vector<bool> sum31 = stage1UnderStage2(vector131, nul, razrad3, 3);
        vector<bool> vector221 = stage1UnderStage3(sum21, razrad2, 2); razrad2++;
        vector<bool> vector112 = stage1understage1(pair1num1, pair1num2, razrad1, 1); 

        vector<bool> vector231 = stage1UnderStage3(sum31, razrad3, 3); razrad3++;
        vector<bool> vector122 = stage1understage1(pair2num1, pair2num2, razrad2, 2);
        vector<bool> sum12 = stage1UnderStage2(vector112, vector211, razrad1, 1); 

        vector<bool> vector132 = stage1understage1(pair3num1, pair3num2, razrad3, 3);
        vector<bool> sum22 = stage1UnderStage2(vector122, vector221, razrad2, 2);
        vector<bool> vector212 = stage1UnderStage3(sum12, razrad1, 1); razrad1++; time();

        vector<bool> sum32 = stage1UnderStage2(vector132, vector231, razrad3, 3);
        vector<bool> vector222 = stage1UnderStage3(sum22, razrad2, 2); razrad2++;
        vector<bool> vector113 = stage1understage1(pair1num1, pair1num2, razrad1, 1); 

        vector<bool> vector232 = stage1UnderStage3(sum32, razrad3, 3); razrad3++;
        vector<bool> vector123 = stage1understage1(pair2num1, pair2num2, razrad2, 2);
        vector<bool> sum13 = stage1UnderStage2(vector113, vector212, razrad1, 1); 

        vector<bool> vector133 = stage1understage1(pair3num1, pair3num2, razrad3, 3);
        vector<bool> sum23 = stage1UnderStage2(vector123, vector222, razrad2, 2);
        vector<bool> vector213 = stage1UnderStage3(sum13, razrad1, 1); razrad1++; time();

        vector<bool> sum33 = stage1UnderStage2(vector133, vector232, razrad3, 3);
        vector<bool> vector223 = stage1UnderStage3(sum23, razrad2, 2); razrad2++;
        vector<bool> vector114 = stage1understage1(pair1num1, pair1num2, razrad1, 1); 

        vector<bool> vector233 = stage1UnderStage3(sum33, razrad3, 3); razrad3++;
        vector<bool> vector124 = stage1understage1(pair2num1, pair2num2, razrad2, 2);
        vector<bool> sum14 = stage1UnderStage2(vector114, vector213, razrad1, 1); 

        vector<bool> vector134 = stage1understage1(pair3num1, pair3num2, razrad3, 3);
        vector<bool> sum24 = stage1UnderStage2(vector124, vector223, razrad2, 2);
        vector<bool> vector214 = stage1UnderStage3(sum14, razrad1, 1); razrad1++; time();

        vector<bool> sum34 = stage1UnderStage2(vector134, vector233, razrad3, 3);
        vector<bool> vector224 = stage1UnderStage3(sum24, razrad2, 2); razrad2++;
        vector<bool> vector115 = stage1understage1(pair1num1, pair1num2, razrad1, 1); 

        vector<bool> vector234 = stage1UnderStage3(sum34, razrad3, 3); razrad3++;
        vector<bool> vector125 = stage1understage1(pair2num1, pair2num2, razrad2, 2);
        vector<bool> sum15 = stage1UnderStage2(vector115, vector214, razrad1, 1); 

        vector<bool> vector135 = stage1understage1(pair3num1, pair3num2, razrad3, 3);
        vector<bool> sum25 = stage1UnderStage2(vector125, vector224, razrad2, 2);
        vector<bool> vector215 = stage1UnderStage3(sum15, razrad1, 1); razrad1++; time();

        vector<bool> sum35 = stage1UnderStage2(vector135, vector234, razrad3, 3);
        vector<bool> vector225 = stage1UnderStage3(sum25, razrad2, 2); razrad2++;
        vector<bool> vector116 = stage1understage1(pair1num1, pair1num2, razrad1, 1); 

        vector<bool> vector235 = stage1UnderStage3(sum35, razrad3, 3); razrad3++;
        vector<bool> vector126 = stage1understage1(pair2num1, pair2num2, razrad2, 2);
        vector<bool> sum16 = stage1UnderStage2(vector116, vector215, razrad1, 1); 

        vector<bool> vector136 = stage1understage1(pair3num1, pair3num2, razrad3, 3);
        vector<bool> sum26 = stage1UnderStage2(vector126, vector225, razrad2, 2);
        vector<bool> vector216 = stage1UnderStage3(sum16, razrad1, 1); razrad1++; time();

        vector<bool> sum36 = stage1UnderStage2(vector136, vector235, razrad3, 3);
        vector<bool> vector226 = stage1UnderStage3(sum26, razrad2, 2); razrad2++; 

        vector<bool> vector236 = stage1UnderStage3(sum36, razrad3, 3); razrad3++; 

        times++;
        times++;
        cout << endl << times << endl;

        break;
    }
    }
}


