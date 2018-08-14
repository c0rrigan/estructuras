#include <iostream>
#include <fstream>
#include <string>

int main(int argc,char* argv[]){
    unsigned int char_count = 0;
    char c;
    std::streampos str_pos = 0;
    unsigned int n = 3;
    std::string seed = "0\n1\n";
    std::string filename = "alph";
    if(argc == 1){
        std::cout << "sigma: 3\n,file out: alph" << std::endl;
    }
    if(argc > 1){
        n = std::stoi(argv[1]);
        std::cout << "sigma:" << argv[1] << std::endl;
    }
    if(argc > 2){
        filename = argv[2];
        std::cout << "file out:" << argv[2] << std::endl;
    }
    //create seed file
    std::ofstream seed_file (filename,std::ios::trunc);
    seed_file << seed.c_str();
    seed_file.close();
    //reopen file as fstream
    std::fstream file (filename,std::fstream::in | std::fstream::out | std::fstream::app);
    while(true){
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
    //add 'e' at the beggining of the file
    std::fstream final_file (filename,std::fstream::out|std::fstream::in);
    final_file << 'e';
    final_file.close();
    return 0;
}

