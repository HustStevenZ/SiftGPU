//
// Created by Sanqian on 16/7/25.
//

#include "stdlib.h"
#include <iostream>
using std::iostream;
#include "SiftConsole.h"
#include <SiftGPU.h>
int main(int argc,char** argv)
{

    SiftConsole* sift = new SiftConsole(argc,argv);

    sift->RunSiftGPU(argc,argv);
    delete sift;
    return 0;
}

SiftConsole::SiftConsole(int argc, char **argv) {

    _sift = new SiftGPUEX();



}
SiftConsole::~SiftConsole() {
    delete _sift;
}
//
//void SiftConsole::ParseSiftParam(int argc, char **argv) {
//    _sift->ParseParam(argc, argv);
//    _sift->SetVerbose(5);
//}

void SiftConsole::RunSiftGPU(int argc, char **argv) {

    _sift->ParseParam(argc, argv);
//    _sift->CreateContextGL();
    if(_sift->RunSIFT())
    {
        _sift->SaveSIFT("test");
        _sift->SetVerbose(2);

    }else
    {
        exit(0);
    }
}
