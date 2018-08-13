#include <iostream>
#include <fstream>
#include <string>

int main(int argc,char* argv[]){
    unsigned int n = 3;
    if(argc == 2){
        n = std::stoi(argv[1]);
    }
    unsigned int char_count = 0;
    char c;
    std::streampos str_pos = 0;
    //create seed file
    std::string seed = "00\n01\n10\n11\n";
    std::ofstream seed_file ("alph",std::ios::trunc);
    seed_file << seed.c_str();
    seed_file.close();
    //reopen file as fstream
    std::fstream file ("alph",std::fstream::in | std::fstream::out | std::fstream::app);
    while(char_count < n){
        char_count = 0;
        std::string buffer;
        file.seekg(str_pos);
        while((c = file.get()) != '\n'){
            buffer.push_back(c);
            char_count++;
        }
        if(char_count >= n)
            break;
        str_pos = file.tellg();
        buffer.append("0\n");
        file << buffer.c_str();
        buffer[buffer.length()-2] = '1';
        file << buffer.c_str();
    }
    file.close();
    return 0;
}

