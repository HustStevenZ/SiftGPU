//
// Created by Sanqian on 16/7/26.
//

#include "MatchConsole.h"
#include <SiftFileLoader.h>
int main(int argc,char** argv)
{
    if(argc>1)
    {
        std::vector<float> keypoint;
        std::vector<float> description;
        int descip_per_point;
        SiftFileLoader::loadFile(argv[1],keypoint,description,descip_per_point);
    }
}