//
// Created by Sanqian on 16/7/25.
//

#ifndef SIFTGPU_SIFTCONSOLE_H
#define SIFTGPU_SIFTCONSOLE_H

class SiftParam;
class SiftGPUEX;

class SiftConsole {
public:
    SiftConsole(int argc, char** argv);
    ~SiftConsole();
    void RunSiftGPU();
private:

    void ParseSiftParam(int argc, char** argv);


    SiftGPUEX* _sift;
};


#endif //SIFTGPU_SIFTCONSOLE_H
