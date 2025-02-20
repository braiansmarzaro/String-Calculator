#include <iostream>
#include <string>
#include <sstream>
#include <numeric>
#include <vector>
//https://codingdojo.org/kata/StringCalculator/?ref=blog.ippon.fr

/*
unordered_map -> dicionário
std::function -> passa função como parâmetro
*/

using namespace std;

string add(string number){
    if (number == ""){
        return 0;
    }
    char delimiter {','};

    /* Sum 2 numbers
    char delimiter {','};

    double token1 = stod(number.substr(0, number.find(delimiter)));
    double token2 = stod(number.substr(number.find(delimiter) + 1));

    return to_string(token1+token2);
    */
    string word;
    stringstream ss(number);

    double numbers[5]; //len should be the quantity of numbers input

    int i = 0;

    while (getline(ss, word, delimiter)){
        numbers[i++] = stod(word);
    }

    double total = accumulate(begin(numbers), end(numbers), 0, plus<double>()); //sum(numbers)
    cout<<total;

    return to_string(total);

}

int main() {
    
    string input {};
    cout<< "Insert some numbers separated by ',': "<<endl;
    cin >> input;
    string result {add(input)};

    cout<<"The result is: " << result<<endl;


    return 0;

}
