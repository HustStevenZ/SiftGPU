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

    sift->RunSiftGPU();
    delete sift;
    return 0;
}

SiftConsole::SiftConsole(int argc, char **argv) {

    _sift = new SiftGPUEX();

    ParseSiftParam(argc,argv);

}
SiftConsole::~SiftConsole() {
    delete _sift;
}

void SiftConsole::ParseSiftParam(int argc, char **argv) {
    _sift->ParseParam(argc, argv);
    _sift->SetVerbose(5);
}

void SiftConsole::RunSiftGPU() {
    if(_sift->RunSIFT())
    {
        _sift->SetVerbose(2);

    }else
    {
        exit(0);
    }
}
