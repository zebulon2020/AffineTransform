#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

/*读取文件，转换成string*/
string read_file(char* file_name){
    ifstream in(file_name);
    std::ostringstream tmp;
    tmp << in.rdbuf();
    string str = tmp.str();
    return str;
}

/*写入文件*/
void write_file(string text){
    ofstream out;  // 创建一个文件输出流对象
    out.open("result.txt");  // 将对象与文件关联
    out<<text;
    out.close();
}
