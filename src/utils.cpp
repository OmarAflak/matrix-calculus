#include "../include/utils.h"

bool hasFlag(const std::string& arg, const int& argc, char const *argv[]){
    for(int i=0 ; i<argc ; i++){
        if(argv[i]==arg){
            return true;
        }
    }
    return false;
}

bool hasArg(const std::string& arg, const int& argc, char const *argv[]){
    for(int i=0 ; i<argc ; i++){
        if(argv[i]==arg){
            if(i<argc-1){
                return true;
            }
        }
    }
    return false;
}

std::string getArg(const std::string& arg, const int& argc, char const *argv[]){
    for(int i=0 ; i<argc ; i++){
        if(argv[i]==arg){
            return argv[i+1];
        }
    }
    return "";
}
